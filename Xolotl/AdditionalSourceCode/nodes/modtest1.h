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

namespace modtest1_impl
{
// ==============================| Node & Parameter type declarations |==============================

using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<0>>;

DECLARE_PARAMETER_RANGE_SKEW(sliderbank_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using sliderbank_c0 = parameter::from0To1<core::gain<NV>, 
                                          0, 
                                          sliderbank_c0Range>;

template <int NV> using sliderbank_c1 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c2 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c3 = sliderbank_c0<NV>;

template <int NV>
using sliderbank_multimod = parameter::list<sliderbank_c0<NV>, 
                                            sliderbank_c1<NV>, 
                                            sliderbank_c2<NV>, 
                                            sliderbank_c3<NV>>;

template <int NV>
using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod<NV>>, 
                                data::external::sliderpack<0>>;

template <int NV>
using ramp1_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          wrap::no_data<core::ramp<NV, false>>>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>, 
                                        parameter::plain<ramp1_t<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, pack_resizer_t>, 
                                     sliderbank_t<NV>, 
                                     tempo_sync_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::pi<NV>>, 
                                   math::sin<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::rect<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::clear<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;
template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, oscillator_t<NV>>, 
                                   wrap::no_process<math::pi<NV>>, 
                                   fx::sampleandhold<NV>, 
                                   math::sig2mod<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain23_t<NV>>, 
                                  chain8_t<NV>, 
                                  chain5_t<NV>, 
                                  chain32_t<NV>>;
using peak_t = wrap::no_data<core::peak>;

namespace custom
{

struct expr3
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 24.0 * value * input) * (2 - Math.PI);;
	}
};
}

namespace custom
{

struct expr5
{
	static float op(float input, float value)
	{
		return input * Math.asin(Math.PI * 1.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr8
{
	static float op(float input, float value)
	{
		return input * Math.cos(Math.PI * 12.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr9
{
	static float op(float input, float value)
	{
		return input * Math.log(Math.PI * 1.0 * value * input) * (1 - Math.PI);;
	}
};
}

DECLARE_PARAMETER_RANGE(pma_mod_0Range, 
                        0.01, 
                        1.);

template <int NV>
using pma_mod_0 = parameter::from0To1<math::expr<NV, custom::expr3>, 
                                      0, 
                                      pma_mod_0Range>;

DECLARE_PARAMETER_RANGE(pma_mod_1Range, 
                        0.02, 
                        1.);

template <int NV>
using pma_mod_1 = parameter::from0To1<math::expr<NV, custom::expr5>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 pma_mod_0<NV>, 
                                 pma_mod_1<NV>, 
                                 parameter::plain<math::expr<NV, custom::expr8>, 0>, 
                                 parameter::plain<math::expr<NV, custom::expr9>, 0>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr3>>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr5>>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr8>>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr9>>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain1_t>, 
                                    chain29_t<NV>, 
                                    chain35_t<NV>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>>;
using peak2_t = wrap::data<core::peak, 
                           data::external::displaybuffer<0>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<3357039>;
using peak3_mod = parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 
                                   0>;
using peak3_t = wrap::mod<peak3_mod, 
                          wrap::no_data<core::peak>>;

using chain13_t = container::chain<parameter::empty, wrap::fix<1, peak3_t>>;

using global_cable39_t_index = runtime_target::indexers::fix_hash<3357040>;
using peak9_mod = parameter::plain<routing::global_cable<global_cable39_t_index, parameter::empty>, 
                                   0>;
using peak9_t = wrap::mod<peak9_mod, 
                          wrap::no_data<core::peak>>;

using chain16_t = container::chain<parameter::empty, wrap::fix<1, peak9_t>>;

using global_cable38_t_index = runtime_target::indexers::fix_hash<3357041>;
using peak8_mod = parameter::plain<routing::global_cable<global_cable38_t_index, parameter::empty>, 
                                   0>;
using peak8_t = wrap::mod<peak8_mod, 
                          wrap::no_data<core::peak>>;

using chain24_t = container::chain<parameter::empty, wrap::fix<1, peak8_t>>;

using global_cable37_t_index = runtime_target::indexers::fix_hash<3357042>;
using peak7_mod = parameter::plain<routing::global_cable<global_cable37_t_index, parameter::empty>, 
                                   0>;
using peak7_t = wrap::mod<peak7_mod, 
                          wrap::no_data<core::peak>>;

using chain50_t = container::chain<parameter::empty, wrap::fix<1, peak7_t>>;
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain13_t>, 
                                    chain16_t, 
                                    chain24_t, 
                                    chain50_t>;

using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, routing::global_cable<global_cable_t_index, parameter::empty>>, 
                                 routing::global_cable<global_cable39_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable38_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable37_t_index, parameter::empty>>;

namespace modtest1_t_parameters
{
// Parameter list for modtest1_impl::modtest1_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE(ModiAdjustRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using ModiAdjust = parameter::from0To1<modtest1_impl::pma_t<NV>, 
                                       2, 
                                       ModiAdjustRange>;

template <int NV>
using Tempo = parameter::plain<modtest1_impl::tempo_sync_t<NV>, 
                               0>;
template <int NV>
using Div = parameter::plain<modtest1_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using Modifiers = parameter::plain<modtest1_impl::branch1_t<NV>, 
                                   0>;
using OUTPUT = parameter::plain<modtest1_impl::branch2_t, 
                                0>;
template <int NV>
using Sync = parameter::plain<modtest1_impl::tempo_sync_t<NV>, 
                              2>;
template <int NV>
using Unsync = parameter::plain<modtest1_impl::tempo_sync_t<NV>, 
                                3>;
template <int NV>
using modtest1_t_plist = parameter::list<Tempo<NV>, 
                                         Div<NV>, 
                                         Modifiers<NV>, 
                                         OUTPUT, 
                                         Sync<NV>, 
                                         Unsync<NV>, 
                                         ModiAdjust<NV>>;
}

template <int NV>
using modtest1_t_ = container::chain<modtest1_t_parameters::modtest1_t_plist<NV>, 
                                     wrap::fix<1, math::clear<NV>>, 
                                     modchain_t<NV>, 
                                     ramp1_t<NV>, 
                                     split1_t<NV>, 
                                     peak_t, 
                                     pma_t<NV>, 
                                     branch1_t<NV>, 
                                     peak2_t, 
                                     wrap::no_process<math::clear<NV>>, 
                                     branch2_t, 
                                     split_t>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public modtest1_impl::modtest1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(modtest1);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(120)
		{
			0x005C, 0x0000, 0x0000, 0x6554, 0x706D, 0x006F, 0x0000, 0x0000, 
            0x0000, 0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x0100, 0x0000, 0x4400, 0x7669, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0002, 0x0000, 0x6F4D, 0x6964, 0x6966, 0x7265, 0x0073, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x0300, 0x0000, 0x4F00, 0x5455, 0x5550, 
            0x0054, 0x0000, 0x0000, 0x0000, 0x4000, 0x0040, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x0400, 0x0000, 0x5300, 0x6E79, 
            0x0063, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x0500, 0x0000, 0x5500, 0x736E, 
            0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0044, 0x8000, 
            0x003F, 0x8000, 0xCD3F, 0xCCCC, 0x5C3D, 0x0600, 0x0000, 0x4D00, 
            0x646F, 0x4169, 0x6A64, 0x7375, 0x0074, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xB93F, 0x87E0, 0x003E, 0x8000, 0x003F, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(17)
		{
			0x003A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& clear2 = this->getT(0);                         // math::clear<NV>
		auto& modchain = this->getT(1);                       // modtest1_impl::modchain_t<NV>
		auto& pack_resizer = this->getT(1).getT(0);           // modtest1_impl::pack_resizer_t
		auto& sliderbank = this->getT(1).getT(1);             // modtest1_impl::sliderbank_t<NV>
		auto& tempo_sync = this->getT(1).getT(2);             // modtest1_impl::tempo_sync_t<NV>
		auto& ramp1 = this->getT(2);                          // modtest1_impl::ramp1_t<NV>
		auto& split1 = this->getT(3);                         // modtest1_impl::split1_t<NV>
		auto& chain23 = this->getT(3).getT(0);                // modtest1_impl::chain23_t<NV>
		auto& pi5 = this->getT(3).getT(0).getT(0);            // math::pi<NV>
		auto& sin5 = this->getT(3).getT(0).getT(1);           // math::sin<NV>
		auto& gain1 = this->getT(3).getT(0).getT(2);          // core::gain<NV>
		auto& chain8 = this->getT(3).getT(1);                 // modtest1_impl::chain8_t<NV>
		auto& rect1 = this->getT(3).getT(1).getT(0);          // math::rect<NV>
		auto& gain = this->getT(3).getT(1).getT(1);           // core::gain<NV>
		auto& chain5 = this->getT(3).getT(2);                 // modtest1_impl::chain5_t<NV>
		auto& clear = this->getT(3).getT(2).getT(0);          // math::clear<NV>
		auto& add = this->getT(3).getT(2).getT(1);            // math::add<NV>
		auto& gain2 = this->getT(3).getT(2).getT(2);          // core::gain<NV>
		auto& chain32 = this->getT(3).getT(3);                // modtest1_impl::chain32_t<NV>
		auto& oscillator = this->getT(3).getT(3).getT(0);     // modtest1_impl::oscillator_t<NV>
		auto& pi = this->getT(3).getT(3).getT(1);             // wrap::no_process<math::pi<NV>>
		auto& sampleandhold1 = this->getT(3).getT(3).getT(2); // fx::sampleandhold<NV>
		auto& sig2mod7 = this->getT(3).getT(3).getT(3);       // math::sig2mod<NV>
		auto& gain4 = this->getT(3).getT(3).getT(4);          // core::gain<NV>
		auto& peak = this->getT(4);                           // modtest1_impl::peak_t
		auto& pma = this->getT(5);                            // modtest1_impl::pma_t<NV>
		auto& branch1 = this->getT(6);                        // modtest1_impl::branch1_t<NV>
		auto& chain1 = this->getT(6).getT(0);                 // modtest1_impl::chain1_t
		auto& chain29 = this->getT(6).getT(1);                // modtest1_impl::chain29_t<NV>
		auto& expr3 = this->getT(6).getT(1).getT(0);          // math::expr<NV, custom::expr3>
		auto& chain35 = this->getT(6).getT(2);                // modtest1_impl::chain35_t<NV>
		auto& expr5 = this->getT(6).getT(2).getT(0);          // math::expr<NV, custom::expr5>
		auto& chain44 = this->getT(6).getT(3);                // modtest1_impl::chain44_t<NV>
		auto& expr8 = this->getT(6).getT(3).getT(0);          // math::expr<NV, custom::expr8>
		auto& chain45 = this->getT(6).getT(4);                // modtest1_impl::chain45_t<NV>
		auto& expr9 = this->getT(6).getT(4).getT(0);          // math::expr<NV, custom::expr9>
		auto& peak2 = this->getT(7);                          // modtest1_impl::peak2_t
		auto& clear3 = this->getT(8);                         // wrap::no_process<math::clear<NV>>
		auto& branch2 = this->getT(9);                        // modtest1_impl::branch2_t
		auto& chain13 = this->getT(9).getT(0);                // modtest1_impl::chain13_t
		auto& peak3 = this->getT(9).getT(0).getT(0);          // modtest1_impl::peak3_t
		auto& chain16 = this->getT(9).getT(1);                // modtest1_impl::chain16_t
		auto& peak9 = this->getT(9).getT(1).getT(0);          // modtest1_impl::peak9_t
		auto& chain24 = this->getT(9).getT(2);                // modtest1_impl::chain24_t
		auto& peak8 = this->getT(9).getT(2).getT(0);          // modtest1_impl::peak8_t
		auto& chain50 = this->getT(9).getT(3);                // modtest1_impl::chain50_t
		auto& peak7 = this->getT(9).getT(3).getT(0);          // modtest1_impl::peak7_t
		auto& split = this->getT(10);                         // modtest1_impl::split_t
		auto& global_cable = this->getT(10).getT(0);          // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& global_cable39 = this->getT(10).getT(1);        // routing::global_cable<global_cable39_t_index, parameter::empty>
		auto& global_cable38 = this->getT(10).getT(2);        // routing::global_cable<global_cable38_t_index, parameter::empty>
		auto& global_cable37 = this->getT(10).getT(3);        // routing::global_cable<global_cable37_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // Tempo -> tempo_sync::Tempo
		
		this->getParameterT(1).connectT(0, tempo_sync); // Div -> tempo_sync::Multiplier
		
		this->getParameterT(2).connectT(0, branch1); // Modifiers -> branch1::Index
		
		this->getParameterT(3).connectT(0, branch2); // OUTPUT -> branch2::Index
		
		this->getParameterT(4).connectT(0, tempo_sync); // Sync -> tempo_sync::Enabled
		
		this->getParameterT(5).connectT(0, tempo_sync); // Unsync -> tempo_sync::UnsyncedTime
		
		this->getParameterT(6).connectT(0, pma); // ModiAdjust -> pma::Add
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, gain1);         // sliderbank -> gain1::Gain
		sliderbank_p.getParameterT(1).connectT(0, gain);          // sliderbank -> gain::Gain
		sliderbank_p.getParameterT(2).connectT(0, gain2);         // sliderbank -> gain2::Gain
		sliderbank_p.getParameterT(3).connectT(0, gain4);         // sliderbank -> gain4::Gain
		ramp1.getParameter().connectT(0, add);                    // ramp1 -> add::Value
		tempo_sync.getParameter().connectT(0, sampleandhold1);    // tempo_sync -> sampleandhold1::Counter
		tempo_sync.getParameter().connectT(1, ramp1);             // tempo_sync -> ramp1::PeriodTime
		pma.getWrappedObject().getParameter().connectT(0, expr3); // pma -> expr3::Value
		pma.getWrappedObject().getParameter().connectT(1, expr5); // pma -> expr5::Value
		pma.getWrappedObject().getParameter().connectT(2, expr8); // pma -> expr8::Value
		pma.getWrappedObject().getParameter().connectT(3, expr9); // pma -> expr9::Value
		peak3.getParameter().connectT(0, global_cable);           // peak3 -> global_cable::Value
		peak9.getParameter().connectT(0, global_cable39);         // peak9 -> global_cable39::Value
		peak8.getParameter().connectT(0, global_cable38);         // peak8 -> global_cable38::Value
		peak7.getParameter().connectT(0, global_cable37);         // peak7 -> global_cable37::Value
		
		// Default Values --------------------------------------------------------------------------
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		pack_resizer.setParameterT(0, 4.); // control::pack_resizer::NumSliders
		
		sliderbank.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		;                           // ramp1::PeriodTime is automated
		ramp1.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp1.setParameterT(2, 1.); // core::ramp::Gate
		
		pi5.setParameterT(0, 1.); // math::pi::Value
		
		sin5.setParameterT(0, 1.); // math::sin::Value
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		rect1.setParameterT(0, 0.166743); // math::rect::Value
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // add::Value is automated
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		oscillator.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		pi.setParameterT(0, 1.); // math::pi::Value
		
		; // sampleandhold1::Counter is automated
		
		sig2mod7.setParameterT(0, 0.); // math::sig2mod::Value
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		pma.setParameterT(0, 0.); // control::pma::Value
		pma.setParameterT(1, 0.); // control::pma::Multiply
		;                         // pma::Add is automated
		
		; // branch1::Index is automated
		
		; // expr3::Value is automated
		
		; // expr5::Value is automated
		
		; // expr8::Value is automated
		
		; // expr9::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // branch2::Index is automated
		
		; // global_cable::Value is automated
		
		; // global_cable39::Value is automated
		
		; // global_cable38::Value is automated
		
		; // global_cable37::Value is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1);
		this->setParameterT(6, 0.265386);
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
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(10).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable39_t_index, parameter::empty>
		this->getT(10).getT(2).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable38_t_index, parameter::empty>
		this->getT(10).getT(3).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable37_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(1).getT(0).setExternalData(b, index);         // modtest1_impl::pack_resizer_t
		this->getT(1).getT(1).setExternalData(b, index);         // modtest1_impl::sliderbank_t<NV>
		this->getT(2).setExternalData(b, index);                 // modtest1_impl::ramp1_t<NV>
		this->getT(3).getT(3).getT(0).setExternalData(b, index); // modtest1_impl::oscillator_t<NV>
		this->getT(4).setExternalData(b, index);                 // modtest1_impl::peak_t
		this->getT(7).setExternalData(b, index);                 // modtest1_impl::peak2_t
		this->getT(9).getT(0).getT(0).setExternalData(b, index); // modtest1_impl::peak3_t
		this->getT(9).getT(1).getT(0).setExternalData(b, index); // modtest1_impl::peak9_t
		this->getT(9).getT(2).getT(0).setExternalData(b, index); // modtest1_impl::peak8_t
		this->getT(9).getT(3).getT(0).setExternalData(b, index); // modtest1_impl::peak7_t
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
using modtest1 = wrap::node<modtest1_impl::instance<NV>>;
}


