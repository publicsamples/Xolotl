#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace Env2_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<0>>;
template <int NV>
using ramp_t = wrap::mod<parameter::plain<cable_table_t<NV>, 0>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::rect<NV>>>;

using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain3_t<NV>>, 
                                    chain4_t>;

template <int NV>
using ahdsr_c0 = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::add<NV>, 0>, 
                                  parameter::plain<routing::public_mod, 0>>;

template <int NV>
using ahdsr_multimod = parameter::list<ahdsr_c0<NV>, parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;
template <int NV>
using input_toggle_t = control::input_toggle<NV, 
                                             parameter::plain<ahdsr_t<NV>, 8>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 2>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, tempo_sync_t<NV>>, 
                                 ramp_t<NV>, 
                                 branch1_t<NV>, 
                                 peak_t<NV>, 
                                 input_toggle_t<NV>, 
                                 math::clear<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, ahdsr_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain1_t<NV>>, 
                                   chain2_t<NV>>;
using peak1_t = wrap::data<core::peak, 
                           data::external::displaybuffer<0>>;

namespace Env2_t_parameters
{
// Parameter list for Env2_impl::Env2_t ------------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(trig_InputRange, 
                             0., 
                             1., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(trig_0Range, 
                             0., 
                             1., 
                             1.);

template <int NV>
using trig_0 = parameter::from0To1<Env2_impl::input_toggle_t<NV>, 
                                   0, 
                                   trig_0Range>;

template <int NV>
using trig = parameter::chain<trig_InputRange, 
                              trig_0<NV>, 
                              parameter::plain<Env2_impl::ramp_t<NV>, 1>>;

template <int NV>
using mode = parameter::chain<ranges::Identity, 
                              parameter::plain<Env2_impl::branch_t<NV>, 0>, 
                              parameter::plain<Env2_impl::branch1_t<NV>, 0>>;

template <int NV>
using Tempo = parameter::plain<Env2_impl::tempo_sync_t<NV>, 
                               0>;
template <int NV>
using Multi = parameter::plain<Env2_impl::tempo_sync_t<NV>, 
                               1>;
template <int NV>
using Sync = parameter::plain<Env2_impl::tempo_sync_t<NV>, 
                              2>;
template <int NV>
using Unsynced = parameter::plain<Env2_impl::tempo_sync_t<NV>, 
                                  3>;
template <int NV>
using a = parameter::plain<Env2_impl::ahdsr_t<NV>, 0>;
template <int NV>
using d = parameter::plain<Env2_impl::ahdsr_t<NV>, 3>;
template <int NV>
using h = parameter::plain<Env2_impl::ahdsr_t<NV>, 2>;
template <int NV>
using s = parameter::plain<Env2_impl::ahdsr_t<NV>, 4>;
template <int NV>
using r = parameter::plain<Env2_impl::ahdsr_t<NV>, 5>;
template <int NV>
using Env2_t_plist = parameter::list<Tempo<NV>, 
                                     Multi<NV>, 
                                     Sync<NV>, 
                                     Unsynced<NV>, 
                                     a<NV>, 
                                     d<NV>, 
                                     h<NV>, 
                                     s<NV>, 
                                     r<NV>, 
                                     trig<NV>, 
                                     mode<NV>>;
}

template <int NV>
using Env2_t_ = container::chain<Env2_t_parameters::Env2_t_plist<NV>, 
                                 wrap::fix<1, chain_t<NV>>, 
                                 branch_t<NV>, 
                                 routing::public_mod, 
                                 peak1_t, 
                                 math::clear<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance:  public Env2_impl::Env2_t_<NV>,
                                    public routing::public_mod_target
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(Env2);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(172)
		{
			0x005C, 0x0000, 0x0000, 0x6554, 0x706D, 0x006F, 0x0000, 0x0000, 
            0x0000, 0x9000, 0x0041, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x0100, 0x0000, 0x4D00, 0x6C75, 0x6974, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0002, 0x0000, 0x7953, 0x636E, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0003, 0x0000, 0x6E55, 0x7973, 0x636E, 0x6465, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x447A, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0xCCCD, 0x3DCC, 0x005C, 0x0004, 0x0000, 0x0061, 0x0000, 
            0x0000, 0x0000, 0x1C40, 0x0046, 0x0000, 0x7200, 0x4A6A, 0xCD3E, 
            0xCCCC, 0x5C3D, 0x0500, 0x0000, 0x6400, 0x0000, 0x0000, 0x0000, 
            0x4000, 0x461C, 0xC000, 0x439D, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 
            0x005C, 0x0006, 0x0000, 0x0068, 0x0000, 0x0000, 0x0000, 0x1C40, 
            0x0046, 0x0000, 0x7200, 0x4A6A, 0xCD3E, 0xCCCC, 0x5C3D, 0x0700, 
            0x0000, 0x7300, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0008, 0x0000, 
            0x0072, 0x0000, 0x0000, 0x0000, 0x1C40, 0x0046, 0x8180, 0x7243, 
            0x4A6A, 0xCD3E, 0xCCCC, 0x5C3D, 0x0900, 0x0000, 0x7400, 0x6972, 
            0x0067, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x0A00, 0x0000, 0x6D00, 0x646F, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain = this->getT(0);                        // Env2_impl::chain_t<NV>
		auto& tempo_sync = this->getT(0).getT(0);           // Env2_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(0).getT(1);                 // Env2_impl::ramp_t<NV>
		auto& branch1 = this->getT(0).getT(2);              // Env2_impl::branch1_t<NV>
		auto& chain3 = this->getT(0).getT(2).getT(0);       // Env2_impl::chain3_t<NV>
		auto& rect = this->getT(0).getT(2).getT(0).getT(0); // math::rect<NV>
		auto& chain4 = this->getT(0).getT(2).getT(1);       // Env2_impl::chain4_t
		auto& peak = this->getT(0).getT(3);                 // Env2_impl::peak_t<NV>
		auto& input_toggle = this->getT(0).getT(4);         // Env2_impl::input_toggle_t<NV>
		auto& clear = this->getT(0).getT(5);                // math::clear<NV>
		auto& branch = this->getT(1);                       // Env2_impl::branch_t<NV>
		auto& chain1 = this->getT(1).getT(0);               // Env2_impl::chain1_t<NV>
		auto& ahdsr = this->getT(1).getT(0).getT(0);        // Env2_impl::ahdsr_t<NV>
		auto& add = this->getT(1).getT(0).getT(1);          // math::add<NV>
		auto& chain2 = this->getT(1).getT(1);               // Env2_impl::chain2_t<NV>
		auto& cable_table = this->getT(1).getT(1).getT(0);  // Env2_impl::cable_table_t<NV>
		auto& add1 = this->getT(1).getT(1).getT(1);         // math::add<NV>
		auto& public_mod = this->getT(2);                   // routing::public_mod
		auto& peak1 = this->getT(3);                        // Env2_impl::peak1_t
		auto& clear1 = this->getT(4);                       // math::clear<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // Tempo -> tempo_sync::Tempo
		
		this->getParameterT(1).connectT(0, tempo_sync); // Multi -> tempo_sync::Multiplier
		
		this->getParameterT(2).connectT(0, tempo_sync); // Sync -> tempo_sync::Enabled
		
		this->getParameterT(3).connectT(0, tempo_sync); // Unsynced -> tempo_sync::UnsyncedTime
		
		this->getParameterT(4).connectT(0, ahdsr); // a -> ahdsr::Attack
		
		this->getParameterT(5).connectT(0, ahdsr); // d -> ahdsr::Decay
		
		this->getParameterT(6).connectT(0, ahdsr); // h -> ahdsr::Hold
		
		this->getParameterT(7).connectT(0, ahdsr); // s -> ahdsr::Sustain
		
		this->getParameterT(8).connectT(0, ahdsr); // r -> ahdsr::Release
		
		auto& trig_p = this->getParameterT(9);
		trig_p.connectT(0, input_toggle); // trig -> input_toggle::Input
		trig_p.connectT(1, ramp);         // trig -> ramp::LoopStart
		
		auto& mode_p = this->getParameterT(10);
		mode_p.connectT(0, branch);  // mode -> branch::Index
		mode_p.connectT(1, branch1); // mode -> branch1::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		cable_table.getWrappedObject().getParameter().connectT(0, add1); // cable_table -> add1::Value
		ramp.getParameter().connectT(0, cable_table);                    // ramp -> cable_table::Value
		tempo_sync.getParameter().connectT(0, ramp);                     // tempo_sync -> ramp::PeriodTime
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, add);                         // ahdsr -> add::Value
		ahdsr_p.getParameterT(0).connectT(1, public_mod);                  // ahdsr -> public_mod::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, ahdsr); // input_toggle -> ahdsr::Gate
		peak.getParameter().connectT(0, input_toggle);                     // peak -> input_toggle::Value2
		
		// Public Mod Connection -------------------------------------------------------------------
		
		public_mod.connect(*this);
		
		// Default Values --------------------------------------------------------------------------
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch1::Index is automated
		
		rect.setParameterT(0, 1.); // math::rect::Value
		
		;                                  // input_toggle::Input is automated
		input_toggle.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                  // input_toggle::Value2 is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // branch::Index is automated
		
		;                            // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		;                            // ahdsr::Hold is automated
		;                            // ahdsr::Decay is automated
		;                            // ahdsr::Sustain is automated
		;                            // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		;                            // ahdsr::Gate is automated
		
		; // add::Value is automated
		
		; // cable_table::Value is automated
		
		; // add1::Value is automated
		
		; // public_mod::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		this->setParameterT(0, 3.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 315.5);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 259.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(1).setExternalData(b, index);         // Env2_impl::ramp_t<NV>
		this->getT(0).getT(3).setExternalData(b, index);         // Env2_impl::peak_t<NV>
		this->getT(1).getT(0).getT(0).setExternalData(b, index); // Env2_impl::ahdsr_t<NV>
		this->getT(1).getT(1).getT(0).setExternalData(b, index); // Env2_impl::cable_table_t<NV>
		this->getT(3).setExternalData(b, index);                 // Env2_impl::peak1_t
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using Env2 = wrap::node<Env2_impl::instance<NV>>;
}


