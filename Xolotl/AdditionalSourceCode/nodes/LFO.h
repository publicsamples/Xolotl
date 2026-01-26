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

namespace LFO_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;
template <int NV>
using converter_t = control::converter<parameter::plain<tempo_sync_t<NV>, 3>, 
                                       conversion_logic::freq2ms>;
template <int NV>
using clock_ramp_t = wrap::no_data<core::clock_ramp<NV, false>>;
template <int NV>
using ramp_generator_t = container::branch<parameter::empty, 
                                           wrap::fix<1, ramp_t<NV>>, 
                                           clock_ramp_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::add<NV>>, 
                                  math::fmod<NV>>;

// The ramp generation nodes (either clock-synced or free running ramp) ----------------------------

template <int NV>
using generator_t = container::chain<parameter::empty, 
                                     wrap::fix<1, converter_t<NV>>, 
                                     tempo_sync_t<NV>, 
                                     ramp_generator_t<NV>, 
                                     chain2_t<NV>>;

template <int NV>
using sine_t = container::chain<parameter::empty, 
                                wrap::fix<1, math::pi<NV>>, 
                                math::sin<NV>, 
                                math::sig2mod<NV>>;

template <int NV>
using triangle_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::add<NV>>, 
                                    math::fmod<NV>, 
                                    math::sub<NV>, 
                                    math::abs<NV>, 
                                    math::mul<NV>>;

template <int NV>
using saw_t = container::chain<parameter::empty, 
                               wrap::fix<1, math::mul<NV>>>;

template <int NV>
using square_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::mod_inv<NV>>, 
                                  math::rect<NV>>;

// randomize the cable value -----------------------------------------------------------------------

template <int NV>
using random1_t = control::random<parameter::plain<math::add<NV>, 0>>;
// Filter out repeating values (so that the cable only fires when going from 0 to 1 or vice versa) -

template <int NV>
using change_t = control::change<NV, 
                                 parameter::plain<random1_t<NV>, 0>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<change_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using fix16_block_t_ = container::chain<parameter::empty, 
                                        wrap::fix<1, math::rect<NV>>, 
                                        peak_t<NV>, 
                                        change_t<NV>, 
                                        random1_t<NV>, 
                                        math::add<NV>>;

template <int NV>
using fix16_block_t = wrap::fix_block<16, fix16_block_t_<NV>>;

template <int NV>
using random_t = container::chain<parameter::empty, 
                                  wrap::fix<1, fix16_block_t<NV>>>;
using table_t = wrap::data<math::table, 
                           data::external::table<0>>;

using custom_t = container::chain<parameter::empty, wrap::fix<1, table_t>>;
using pack_t = wrap::data<math::pack, 
                          data::external::sliderpack<0>>;

using steps_t = container::chain<parameter::empty, wrap::fix<1, pack_t>>;
// The waveshaping functions based on the mode -----------------------------------------------------

template <int NV>
using wave_shapers_t = container::branch<parameter::empty, 
                                         wrap::fix<1, sine_t<NV>>, 
                                         triangle_t<NV>, 
                                         saw_t<NV>, 
                                         square_t<NV>, 
                                         random_t<NV>, 
                                         custom_t, 
                                         steps_t>;

using simple_ar_multimod = parameter::list<parameter::empty, parameter::empty>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod>>;

// The post processing chain will smooth the LFO signal and add a fade-in envelope -----------------

template <int NV>
using post_t = container::chain<parameter::empty, 
                                wrap::fix<1, core::smoother<NV>>, 
                                simple_ar_t<NV>, 
                                math::mod_inv<NV>>;

using peak1_t = wrap::mod<parameter::plain<routing::public_mod, 0>, 
                          wrap::no_data<core::peak>>;

// Detects the peak and sends it as output value ---------------------------------------------------

using output_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak1_t>, 
                                  routing::public_mod>;

namespace LFO_t_parameters
{
// Parameter list for LFO_impl::LFO_t --------------------------------------------------------------

template <int NV>
using Gate = parameter::chain<ranges::Identity, 
                              parameter::plain<LFO_impl::ramp_t<NV>, 2>, 
                              parameter::plain<LFO_impl::simple_ar_t<NV>, 2>>;

template <int NV>
using Tempo = parameter::chain<ranges::Identity, 
                               parameter::plain<LFO_impl::tempo_sync_t<NV>, 0>, 
                               parameter::plain<LFO_impl::clock_ramp_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_INV(LoopRange, 
                            0., 
                            1.);

template <int NV>
using Loop = parameter::from0To1_inv<LFO_impl::ramp_t<NV>, 
                                     1, 
                                     LoopRange>;

template <int NV>
using Type = parameter::plain<LFO_impl::wave_shapers_t<NV>, 
                              0>;
template <int NV>
using Sync = parameter::plain<LFO_impl::tempo_sync_t<NV>, 
                              2>;
template <int NV>
using Clock = parameter::plain<LFO_impl::ramp_generator_t<NV>, 
                               0>;
template <int NV>
using Frequency = parameter::plain<LFO_impl::converter_t<NV>, 
                                   0>;
template <int NV>
using Phase = parameter::plain<math::add<NV>, 0>;
template <int NV>
using Smoothing = parameter::plain<core::smoother<NV>, 0>;
template <int NV>
using Fadetime = parameter::plain<LFO_impl::simple_ar_t<NV>, 
                                  0>;
template <int NV>
using LFO_t_plist = parameter::list<Type<NV>, 
                                    Gate<NV>, 
                                    Sync<NV>, 
                                    Clock<NV>, 
                                    Frequency<NV>, 
                                    Tempo<NV>, 
                                    Phase<NV>, 
                                    Loop<NV>, 
                                    Smoothing<NV>, 
                                    Fadetime<NV>>;
}

template <int NV>
using LFO_t_ = container::chain<LFO_t_parameters::LFO_t_plist<NV>, 
                                wrap::fix<1, math::clear<NV>>, 
                                generator_t<NV>, 
                                wave_shapers_t<NV>, 
                                post_t<NV>, 
                                output_t>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance:  public LFO_impl::LFO_t_<NV>,
                                    public routing::public_mod_target
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(LFO);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(160)
		{
			0x005B, 0x0000, 0x5400, 0x7079, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x40C0, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x015B, 
            0x0000, 0x4700, 0x7461, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 0x0000, 
            0x5300, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 0x0000, 0x4300, 
            0x6F6C, 0x6B63, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0004, 0x0000, 0x7246, 
            0x7165, 0x6575, 0x636E, 0x0079, 0x0000, 0x0000, 0x0000, 0x4220, 
            0x0000, 0x4040, 0x0000, 0x3F00, 0x0000, 0x0000, 0x055B, 0x0000, 
            0x5400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0006, 0x0000, 
            0x6850, 0x7361, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x4C00, 
            0x6F6F, 0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x085B, 0x0000, 0x5300, 0x6F6D, 
            0x746F, 0x6968, 0x676E, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0044, 
            0xA000, 0x6940, 0x6CEE, 0xCD3E, 0xCCCC, 0x5B3D, 0x0009, 0x0000, 
            0x6146, 0x6564, 0x6974, 0x656D, 0x0000, 0x0000, 0x0000, 0x7A00, 
            0x0044, 0x7A00, 0x9B44, 0x9A20, 0xCD3E, 0xCCCC, 0x003D, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& clear = this->getT(0);                           // math::clear<NV>
		auto& generator = this->getT(1);                       // LFO_impl::generator_t<NV>
		auto& converter = this->getT(1).getT(0);               // LFO_impl::converter_t<NV>
		auto& tempo_sync = this->getT(1).getT(1);              // LFO_impl::tempo_sync_t<NV>
		auto& ramp_generator = this->getT(1).getT(2);          // LFO_impl::ramp_generator_t<NV>
		auto& ramp = this->getT(1).getT(2).getT(0);            // LFO_impl::ramp_t<NV>
		auto& clock_ramp = this->getT(1).getT(2).getT(1);      // LFO_impl::clock_ramp_t<NV>
		auto& chain2 = this->getT(1).getT(3);                  // LFO_impl::chain2_t<NV>
		auto& add = this->getT(1).getT(3).getT(0);             // math::add<NV>
		auto& fmod = this->getT(1).getT(3).getT(1);            // math::fmod<NV>
		auto& wave_shapers = this->getT(2);                    // LFO_impl::wave_shapers_t<NV>
		auto& sine = this->getT(2).getT(0);                    // LFO_impl::sine_t<NV>
		auto& pi = this->getT(2).getT(0).getT(0);              // math::pi<NV>
		auto& sin = this->getT(2).getT(0).getT(1);             // math::sin<NV>
		auto& sig2mod = this->getT(2).getT(0).getT(2);         // math::sig2mod<NV>
		auto& triangle = this->getT(2).getT(1);                // LFO_impl::triangle_t<NV>
		auto& add1 = this->getT(2).getT(1).getT(0);            // math::add<NV>
		auto& fmod1 = this->getT(2).getT(1).getT(1);           // math::fmod<NV>
		auto& sub = this->getT(2).getT(1).getT(2);             // math::sub<NV>
		auto& abs = this->getT(2).getT(1).getT(3);             // math::abs<NV>
		auto& mul1 = this->getT(2).getT(1).getT(4);            // math::mul<NV>
		auto& saw = this->getT(2).getT(2);                     // LFO_impl::saw_t<NV>
		auto& mul = this->getT(2).getT(2).getT(0);             // math::mul<NV>
		auto& square = this->getT(2).getT(3);                  // LFO_impl::square_t<NV>
		auto& mod_inv = this->getT(2).getT(3).getT(0);         // math::mod_inv<NV>
		auto& rect = this->getT(2).getT(3).getT(1);            // math::rect<NV>
		auto& random = this->getT(2).getT(4);                  // LFO_impl::random_t<NV>
		auto& fix16_block = this->getT(2).getT(4).getT(0);     // LFO_impl::fix16_block_t<NV>
		auto& rect1 = this->getT(2).getT(4).getT(0).getT(0);   // math::rect<NV>
		auto& peak = this->getT(2).getT(4).getT(0).getT(1);    // LFO_impl::peak_t<NV>
		auto& change = this->getT(2).getT(4).getT(0).getT(2);  // LFO_impl::change_t<NV>
		auto& random1 = this->getT(2).getT(4).getT(0).getT(3); // LFO_impl::random1_t<NV>
		auto& add3 = this->getT(2).getT(4).getT(0).getT(4);    // math::add<NV>
		auto& custom = this->getT(2).getT(5);                  // LFO_impl::custom_t
		auto& table = this->getT(2).getT(5).getT(0);           // LFO_impl::table_t
		auto& steps = this->getT(2).getT(6);                   // LFO_impl::steps_t
		auto& pack = this->getT(2).getT(6).getT(0);            // LFO_impl::pack_t
		auto& post = this->getT(3);                            // LFO_impl::post_t<NV>
		auto& smoother = this->getT(3).getT(0);                // core::smoother<NV>
		auto& simple_ar = this->getT(3).getT(1);               // LFO_impl::simple_ar_t<NV>
		auto& mod_inv2 = this->getT(3).getT(2);                // math::mod_inv<NV>
		auto& output = this->getT(4);                          // LFO_impl::output_t
		auto& peak1 = this->getT(4).getT(0);                   // LFO_impl::peak1_t
		auto& public_mod = this->getT(4).getT(1);              // routing::public_mod
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, wave_shapers); // Type -> wave_shapers::Index
		
		auto& Gate_p = this->getParameterT(1);
		Gate_p.connectT(0, ramp);      // Gate -> ramp::Gate
		Gate_p.connectT(1, simple_ar); // Gate -> simple_ar::Gate
		
		this->getParameterT(2).connectT(0, tempo_sync); // Sync -> tempo_sync::Enabled
		
		this->getParameterT(3).connectT(0, ramp_generator); // Clock -> ramp_generator::Index
		
		this->getParameterT(4).connectT(0, converter); // Frequency -> converter::Value
		
		auto& Tempo_p = this->getParameterT(5);
		Tempo_p.connectT(0, tempo_sync); // Tempo -> tempo_sync::Tempo
		Tempo_p.connectT(1, clock_ramp); // Tempo -> clock_ramp::Tempo
		
		this->getParameterT(6).connectT(0, add); // Phase -> add::Value
		
		this->getParameterT(7).connectT(0, ramp); // Loop -> ramp::LoopStart
		
		this->getParameterT(8).connectT(0, smoother); // Smoothing -> smoother::SmoothingTime
		
		this->getParameterT(9).connectT(0, simple_ar); // Fadetime -> simple_ar::Attack
		
		// Modulation Connections ------------------------------------------------------------------
		
		tempo_sync.getParameter().connectT(0, ramp);                         // tempo_sync -> ramp::PeriodTime
		converter.getWrappedObject().getParameter().connectT(0, tempo_sync); // converter -> tempo_sync::UnsyncedTime
		random1.getWrappedObject().getParameter().connectT(0, add3);         // random1 -> add3::Value
		change.getWrappedObject().getParameter().connectT(0, random1);       // change -> random1::Value
		peak.getParameter().connectT(0, change);                             // peak -> change::Value
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		peak1.getParameter().connectT(0, public_mod); // peak1 -> public_mod::Value
		
		// Public Mod Connection -------------------------------------------------------------------
		
		public_mod.connect(*this);
		
		// Default Values --------------------------------------------------------------------------
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // converter::Value is automated
		
		;                                // tempo_sync::Tempo is automated
		tempo_sync.setParameterT(1, 1.); // control::tempo_sync::Multiplier
		;                                // tempo_sync::Enabled is automated
		;                                // tempo_sync::UnsyncedTime is automated
		
		; // ramp_generator::Index is automated
		
		; // ramp::PeriodTime is automated
		; // ramp::LoopStart is automated
		; // ramp::Gate is automated
		
		;                                // clock_ramp::Tempo is automated
		clock_ramp.setParameterT(1, 1.); // core::clock_ramp::Multiplier
		clock_ramp.setParameterT(2, 1.); // core::clock_ramp::AddToSignal
		clock_ramp.setParameterT(3, 1.); // core::clock_ramp::UpdateMode
		clock_ramp.setParameterT(4, 0.); // core::clock_ramp::Inactive
		
		; // add::Value is automated
		
		fmod.setParameterT(0, 1.); // math::fmod::Value
		
		; // wave_shapers::Index is automated
		
		pi.setParameterT(0, 2.); // math::pi::Value
		
		sin.setParameterT(0, 1.); // math::sin::Value
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		add1.setParameterT(0, 0.748667); // math::add::Value
		
		fmod1.setParameterT(0, 1.); // math::fmod::Value
		
		sub.setParameterT(0, 0.496); // math::sub::Value
		
		abs.setParameterT(0, 0.); // math::abs::Value
		
		mul1.setParameterT(0, 2.); // math::mul::Value
		
		mul.setParameterT(0, 1.); // math::mul::Value
		
		mod_inv.setParameterT(0, 0.); // math::mod_inv::Value
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		rect1.setParameterT(0, 0.); // math::rect::Value
		
		; // change::Value is automated
		
		; // random1::Value is automated
		
		; // add3::Value is automated
		
		;                              // smoother::SmoothingTime is automated
		smoother.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		;                                 // simple_ar::Attack is automated
		simple_ar.setParameterT(1, 36.4); // envelope::simple_ar::Release
		;                                 // simple_ar::Gate is automated
		simple_ar.setParameterT(3, 0.5);  // envelope::simple_ar::AttackCurve
		
		mod_inv2.setParameterT(0, 0.); // math::mod_inv::Value
		
		; // public_mod::Value is automated
		
		this->setParameterT(0, 2.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 3.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 5);
		this->setParameterT(9, 1000.);
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
		
		this->getT(1).getT(2).getT(0).setExternalData(b, index);         // LFO_impl::ramp_t<NV>
		this->getT(1).getT(2).getT(1).setExternalData(b, index);         // LFO_impl::clock_ramp_t<NV>
		this->getT(2).getT(4).getT(0).getT(1).setExternalData(b, index); // LFO_impl::peak_t<NV>
		this->getT(2).getT(5).getT(0).setExternalData(b, index);         // LFO_impl::table_t
		this->getT(2).getT(6).getT(0).setExternalData(b, index);         // LFO_impl::pack_t
		this->getT(3).getT(1).setExternalData(b, index);                 // LFO_impl::simple_ar_t<NV>
		this->getT(4).getT(0).setExternalData(b, index);                 // LFO_impl::peak1_t
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
using LFO = wrap::node<LFO_impl::instance<NV>>;
}


