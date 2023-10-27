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

namespace harmcut_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

using xfader_c0 = parameter::from0To1<core::gain, 
                                      0, 
                                      xfader_c0Range>;

using xfader_c1 = xfader_c0;

using xfader_multimod = parameter::list<xfader_c0, xfader_c1>;

using xfader_t = control::xfader<xfader_multimod, faders::linear>;

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<fx::sampleandhold<NV>, 0>, 
                               control::tempo_sync<NV>>;
using stereo_cable = cable::block<2>;

using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

DECLARE_PARAMETER_RANGE_SKEW(pma_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma_mod = parameter::from0To1<filters::svf<NV>, 
                                    0, 
                                    pma_modRange>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, peak_t<NV>>, 
                                  math::clear<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain7_t>, 
                                  chain8_t<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, tempo_sync_t<NV>>, 
                                  routing::receive<stereo_cable>, 
                                  fx::sampleandhold<NV>, 
                                  split2_t<NV>, 
                                  routing::send<stereo_cable>, 
                                  core::gain>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain2_t>, 
                                 chain3_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader_t>, 
                                  split_t<NV>>;

using xfader1_c0 = xfader_c0;

using xfader1_c1 = xfader_c0;

using xfader1_multimod = parameter::list<xfader1_c0, xfader1_c1>;

using xfader1_t = control::xfader<xfader1_multimod, faders::linear>;

using chain5_t = chain2_t;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, pma_t<NV>>, 
                                  filters::svf<NV>, 
                                  core::gain>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain5_t>, 
                                  chain6_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader1_t>, 
                                  split1_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, chain1_t<NV>>, 
                                 chain4_t<NV>>;

namespace harmcut_t_parameters
{
// Parameter list for harmcut_impl::harmcut_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(shrate_InputRange, 
                             0., 
                             18., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(shrate_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using shrate_0 = parameter::from0To1<harmcut_impl::tempo_sync_t<NV>, 
                                     0, 
                                     shrate_0Range>;

DECLARE_PARAMETER_RANGE_STEP(shrate_1Range, 
                             1., 
                             64., 
                             0.1);

template <int NV>
using shrate_1 = parameter::from0To1<harmcut_impl::tempo_sync_t<NV>, 
                                     3, 
                                     shrate_1Range>;

template <int NV>
using shrate = parameter::chain<shrate_InputRange, 
                                shrate_0<NV>, 
                                shrate_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ftype_InputRange, 
                             0., 
                             4., 
                             0.1);
DECLARE_PARAMETER_RANGE_SKEW(ftype_0Range, 
                             0., 
                             3., 
                             0.878126);

template <int NV>
using ftype_0 = parameter::from0To1<filters::svf<NV>, 
                                    4, 
                                    ftype_0Range>;

template <int NV>
using ftype = parameter::chain<ftype_InputRange, ftype_0<NV>>;

using shmix = parameter::plain<harmcut_impl::xfader_t, 0>;
template <int NV>
using shdiv = parameter::plain<harmcut_impl::tempo_sync_t<NV>, 
                               1>;
template <int NV>
using shsync = parameter::plain<harmcut_impl::tempo_sync_t<NV>, 
                                2>;
template <int NV>
using cut = parameter::plain<harmcut_impl::pma_t<NV>, 
                             2>;
template <int NV>
using cutshmod = parameter::plain<harmcut_impl::pma_t<NV>, 
                                  1>;
template <int NV>
using res = parameter::plain<filters::svf<NV>, 1>;
using cutmix = parameter::plain<harmcut_impl::xfader1_t, 
                                0>;
template <int NV>
using harmcut_t_plist = parameter::list<shmix, 
                                        shrate<NV>, 
                                        shdiv<NV>, 
                                        shsync<NV>, 
                                        cut<NV>, 
                                        cutshmod<NV>, 
                                        res<NV>, 
                                        cutmix, 
                                        ftype<NV>>;
}

template <int NV>
using harmcut_t_ = container::chain<harmcut_t_parameters::harmcut_t_plist<NV>, 
                                    wrap::fix<2, chain_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public harmcut_impl::harmcut_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(harmcut);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(142)
		{
			0x005B, 0x0000, 0x7300, 0x6D68, 0x7869, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6873, 0x6172, 0x6574, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0002, 0x0000, 0x6873, 0x6964, 0x0076, 0x0000, 0x3F80, 0x0000, 
            0x4180, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 
            0x0000, 0x7300, 0x7368, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x045B, 
            0x0000, 0x6300, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 
            0x7563, 0x7374, 0x6D68, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x963F, 0x57C3, 0x00BF, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 
            0x0000, 0x6572, 0x0073, 0x999A, 0x3E99, 0x6666, 0x411E, 0x9A2B, 
            0x3ED7, 0x8918, 0x3E87, 0x0000, 0x0000, 0x075B, 0x0000, 0x6300, 
            0x7475, 0x696D, 0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 0x6600, 
            0x7974, 0x6570, 0x0000, 0x0000, 0x0000, 0x8000, 0x0040, 0x0000, 
            0x0000, 0x8000, 0xCD3F, 0xCCCC, 0x003D, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain = this->getT(0);                                                 // harmcut_impl::chain_t<NV>
		auto& chain1 = this->getT(0).getT(0);                                        // harmcut_impl::chain1_t<NV>
		auto& xfader = this->getT(0).getT(0).getT(0);                                // harmcut_impl::xfader_t
		auto& split = this->getT(0).getT(0).getT(1);                                 // harmcut_impl::split_t<NV>
		auto& chain2 = this->getT(0).getT(0).getT(1).getT(0);                        // harmcut_impl::chain2_t
		auto& gain = this->getT(0).getT(0).getT(1).getT(0).getT(0);                  // core::gain
		auto& chain3 = this->getT(0).getT(0).getT(1).getT(1);                        // harmcut_impl::chain3_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(1).getT(1).getT(0);            // harmcut_impl::tempo_sync_t<NV>
		auto& receive = this->getT(0).getT(0).getT(1).getT(1).getT(1);               // routing::receive<stereo_cable>
		auto& sampleandhold = this->getT(0).getT(0).getT(1).getT(1).getT(2);         // fx::sampleandhold<NV>
		auto& split2 = this->getT(0).getT(0).getT(1).getT(1).getT(3);                // harmcut_impl::split2_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(0);        // harmcut_impl::chain7_t
		auto& chain8 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(1);        // harmcut_impl::chain8_t<NV>
		auto& peak = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(1).getT(0);  // harmcut_impl::peak_t<NV>
		auto& clear = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(1).getT(1); // math::clear<NV>
		auto& send = this->getT(0).getT(0).getT(1).getT(1).getT(4);                  // routing::send<stereo_cable>
		auto& gain1 = this->getT(0).getT(0).getT(1).getT(1).getT(5);                 // core::gain
		auto& chain4 = this->getT(0).getT(1);                                        // harmcut_impl::chain4_t<NV>
		auto& xfader1 = this->getT(0).getT(1).getT(0);                               // harmcut_impl::xfader1_t
		auto& split1 = this->getT(0).getT(1).getT(1);                                // harmcut_impl::split1_t<NV>
		auto& chain5 = this->getT(0).getT(1).getT(1).getT(0);                        // harmcut_impl::chain5_t
		auto& gain2 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                 // core::gain
		auto& chain6 = this->getT(0).getT(1).getT(1).getT(1);                        // harmcut_impl::chain6_t<NV>
		auto& pma = this->getT(0).getT(1).getT(1).getT(1).getT(0);                   // harmcut_impl::pma_t<NV>
		auto& svf = this->getT(0).getT(1).getT(1).getT(1).getT(1);                   // filters::svf<NV>
		auto& gain3 = this->getT(0).getT(1).getT(1).getT(1).getT(2);                 // core::gain
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader); // shmix -> xfader::Value
		
		auto& shrate_p = this->getParameterT(1);
		shrate_p.connectT(0, tempo_sync); // shrate -> tempo_sync::Tempo
		shrate_p.connectT(1, tempo_sync); // shrate -> tempo_sync::UnsyncedTime
		
		this->getParameterT(2).connectT(0, tempo_sync); // shdiv -> tempo_sync::Multiplier
		
		this->getParameterT(3).connectT(0, tempo_sync); // shsync -> tempo_sync::Enabled
		
		this->getParameterT(4).connectT(0, pma); // cut -> pma::Add
		
		this->getParameterT(5).connectT(0, pma); // cutshmod -> pma::Multiply
		
		this->getParameterT(6).connectT(0, svf); // res -> svf::Q
		
		this->getParameterT(7).connectT(0, xfader1); // cutmix -> xfader1::Value
		
		this->getParameterT(8).connectT(0, svf); // ftype -> svf::Mode
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);            // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);           // xfader -> gain1::Gain
		tempo_sync.getParameter().connectT(0, sampleandhold);   // tempo_sync -> sampleandhold::Counter
		pma.getWrappedObject().getParameter().connectT(0, svf); // pma -> svf::Frequency
		peak.getParameter().connectT(0, pma);                   // peak -> pma::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain2); // xfader1 -> gain2::Gain
		xfader1_p.getParameterT(1).connectT(0, gain3); // xfader1 -> gain3::Gain
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values --------------------------------------------------------------------------
		
		; // xfader::Value is automated
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 20.);   // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		receive.setParameterT(0, 0.); // routing::receive::Feedback
		
		; // sampleandhold::Counter is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 20.);   // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader1::Value is automated
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 20.);   // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                           // svf::Mode is automated
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 20.);   // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 4.);
		this->setParameterT(2, 4.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, -0.842828);
		this->setParameterT(6, 0.421098);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(1).getT(0).setExternalData(b, index); // harmcut_impl::peak_t<NV>
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
using harmcut = wrap::node<harmcut_impl::instance<NV>>;
}


