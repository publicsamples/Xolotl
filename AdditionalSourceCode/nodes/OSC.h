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

namespace OSC_impl
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
template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;

template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, 
                                             parameter::plain<file_player_t<NV>, 3>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled_t<NV>, 0>>;

using simple_ar_multimod = parameter::list<parameter::empty, parameter::empty>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player_t<NV>>, 
                                 pma_unscaled_t<NV>, 
                                 minmax_t<NV>, 
                                 simple_ar_t<NV>, 
                                 core::gain>;
template <int NV>
using file_player2_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;

template <int NV>
using pma_unscaled2_t = control::pma_unscaled<NV, 
                                              parameter::plain<file_player2_t<NV>, 3>>;

template <int NV>
using minmax2_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled2_t<NV>, 0>>;

using simple_ar2_multimod = simple_ar_multimod;

template <int NV>
using simple_ar2_t = wrap::no_data<envelope::simple_ar<NV, simple_ar2_multimod>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, file_player2_t<NV>>, 
                                  pma_unscaled2_t<NV>, 
                                  minmax2_t<NV>, 
                                  simple_ar2_t<NV>, 
                                  core::gain>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain2_t<NV>>;

namespace OSC_t_parameters
{
// Parameter list for OSC_impl::OSC_t --------------------------------------------------------------

template <int NV>
using min = parameter::chain<ranges::Identity, 
                             parameter::plain<OSC_impl::minmax_t<NV>, 1>, 
                             parameter::plain<OSC_impl::minmax2_t<NV>, 1>>;

template <int NV>
using mac = parameter::chain<ranges::Identity, 
                             parameter::plain<OSC_impl::minmax_t<NV>, 2>, 
                             parameter::plain<OSC_impl::minmax2_t<NV>, 2>>;

template <int NV>
using step = parameter::chain<ranges::Identity, 
                              parameter::plain<OSC_impl::minmax_t<NV>, 4>, 
                              parameter::plain<OSC_impl::minmax2_t<NV>, 4>>;

using mix = parameter::plain<OSC_impl::xfader_t, 0>;
template <int NV>
using detune1 = parameter::plain<OSC_impl::pma_unscaled_t<NV>, 
                                 2>;
template <int NV>
using detune2 = parameter::plain<OSC_impl::pma_unscaled2_t<NV>, 
                                 2>;
template <int NV>
using harm1 = parameter::plain<OSC_impl::minmax_t<NV>, 0>;
template <int NV>
using harm2 = parameter::plain<OSC_impl::minmax2_t<NV>, 
                               0>;
template <int NV>
using atk1 = parameter::plain<OSC_impl::simple_ar_t<NV>, 
                              0>;
template <int NV>
using atk2 = parameter::plain<OSC_impl::simple_ar2_t<NV>, 
                              0>;
template <int NV>
using rel1 = parameter::plain<OSC_impl::simple_ar_t<NV>, 
                              1>;
template <int NV>
using rel2 = parameter::plain<OSC_impl::simple_ar2_t<NV>, 
                              1>;
template <int NV>
using OSC_t_plist = parameter::list<mix, 
                                    detune1<NV>, 
                                    detune2<NV>, 
                                    harm1<NV>, 
                                    harm2<NV>, 
                                    atk1<NV>, 
                                    atk2<NV>, 
                                    rel1<NV>, 
                                    rel2<NV>, 
                                    min<NV>, 
                                    mac<NV>, 
                                    step<NV>>;
}

template <int NV>
using OSC_t_ = container::chain<OSC_t_parameters::OSC_t_plist<NV>, 
                                wrap::fix<2, xfader_t>, 
                                split_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public OSC_impl::OSC_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(OSC);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(184)
		{
			0x005B, 0x0000, 0x6D00, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 
            0xB63F, 0xF785, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x6564, 0x7574, 0x656E, 0x0031, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0xF604, 0xBCB0, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x6400, 0x7465, 0x6E75, 0x3265, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0003, 0x0000, 0x6168, 0x6D72, 0x0031, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 
            0x0000, 0x6800, 0x7261, 0x326D, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 
            0x0000, 0x7461, 0x316B, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0044, 
            0x8000, 0x9B3F, 0x9A20, 0xCD3E, 0xCCCC, 0x5B3D, 0x0006, 0x0000, 
            0x7461, 0x326B, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0044, 0x8000, 
            0x9B3F, 0x9A20, 0xCD3E, 0xCCCC, 0x5B3D, 0x0007, 0x0000, 0x6572, 
            0x316C, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0044, 0x8000, 0x9B3F, 
            0x9A20, 0xCD3E, 0xCCCC, 0x5B3D, 0x0008, 0x0000, 0x6572, 0x326C, 
            0x0000, 0x0000, 0x0000, 0x7A00, 0x0044, 0x8000, 0x9B3F, 0x9A20, 
            0xCD3E, 0xCCCC, 0x5B3D, 0x0009, 0x0000, 0x696D, 0x006E, 0x0000, 
            0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0A5B, 0x0000, 0x6D00, 0x6361, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x000B, 0x0000, 0x7473, 0x7065, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& xfader = this->getT(0);                        // OSC_impl::xfader_t
		auto& split = this->getT(1);                         // OSC_impl::split_t<NV>
		auto& chain = this->getT(1).getT(0);                 // OSC_impl::chain_t<NV>
		auto& file_player = this->getT(1).getT(0).getT(0);   // OSC_impl::file_player_t<NV>
		auto& pma_unscaled = this->getT(1).getT(0).getT(1);  // OSC_impl::pma_unscaled_t<NV>
		auto& minmax = this->getT(1).getT(0).getT(2);        // OSC_impl::minmax_t<NV>
		auto& simple_ar = this->getT(1).getT(0).getT(3);     // OSC_impl::simple_ar_t<NV>
		auto& gain1 = this->getT(1).getT(0).getT(4);         // core::gain
		auto& chain2 = this->getT(1).getT(1);                // OSC_impl::chain2_t<NV>
		auto& file_player2 = this->getT(1).getT(1).getT(0);  // OSC_impl::file_player2_t<NV>
		auto& pma_unscaled2 = this->getT(1).getT(1).getT(1); // OSC_impl::pma_unscaled2_t<NV>
		auto& minmax2 = this->getT(1).getT(1).getT(2);       // OSC_impl::minmax2_t<NV>
		auto& simple_ar2 = this->getT(1).getT(1).getT(3);    // OSC_impl::simple_ar2_t<NV>
		auto& gain = this->getT(1).getT(1).getT(4);          // core::gain
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader); // mix -> xfader::Value
		
		this->getParameterT(1).connectT(0, pma_unscaled); // detune1 -> pma_unscaled::Add
		
		this->getParameterT(2).connectT(0, pma_unscaled2); // detune2 -> pma_unscaled2::Add
		
		this->getParameterT(3).connectT(0, minmax); // harm1 -> minmax::Value
		
		this->getParameterT(4).connectT(0, minmax2); // harm2 -> minmax2::Value
		
		this->getParameterT(5).connectT(0, simple_ar); // atk1 -> simple_ar::Attack
		
		this->getParameterT(6).connectT(0, simple_ar2); // atk2 -> simple_ar2::Attack
		
		this->getParameterT(7).connectT(0, simple_ar); // rel1 -> simple_ar::Release
		
		this->getParameterT(8).connectT(0, simple_ar2); // rel2 -> simple_ar2::Release
		
		auto& min_p = this->getParameterT(9);
		min_p.connectT(0, minmax);  // min -> minmax::Minimum
		min_p.connectT(1, minmax2); // min -> minmax2::Minimum
		
		auto& mac_p = this->getParameterT(10);
		mac_p.connectT(0, minmax);  // mac -> minmax::Maximum
		mac_p.connectT(1, minmax2); // mac -> minmax2::Maximum
		
		auto& step_p = this->getParameterT(11);
		step_p.connectT(0, minmax);  // step -> minmax::Step
		step_p.connectT(1, minmax2); // step -> minmax2::Step
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                            // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain);                             // xfader -> gain::Gain
		pma_unscaled.getWrappedObject().getParameter().connectT(0, file_player); // pma_unscaled -> file_player::FreqRatio
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled);      // minmax -> pma_unscaled::Value
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		pma_unscaled2.getWrappedObject().getParameter().connectT(0, file_player2); // pma_unscaled2 -> file_player2::FreqRatio
		minmax2.getWrappedObject().getParameter().connectT(0, pma_unscaled2);      // minmax2 -> pma_unscaled2::Value
		auto& simple_ar2_p = simple_ar2.getWrappedObject().getParameter();
		
		// Default Values --------------------------------------------------------------------------
		
		; // xfader::Value is automated
		
		file_player.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                   // file_player::FreqRatio is automated
		
		;                                  // pma_unscaled::Value is automated
		pma_unscaled.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                  // pma_unscaled::Add is automated
		
		;                            // minmax::Value is automated
		;                            // minmax::Minimum is automated
		;                            // minmax::Maximum is automated
		minmax.setParameterT(3, 1.); // control::minmax::Skew
		;                            // minmax::Step is automated
		minmax.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                               // simple_ar::Attack is automated
		;                               // simple_ar::Release is automated
		simple_ar.setParameterT(2, 0.); // envelope::simple_ar::Gate
		simple_ar.setParameterT(3, 0.); // envelope::simple_ar::AttackCurve
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		file_player2.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player2.setParameterT(1, 1.);   // core::file_player::Gate
		file_player2.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player2::FreqRatio is automated
		
		;                                   // pma_unscaled2::Value is automated
		pma_unscaled2.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled2::Add is automated
		
		;                             // minmax2::Value is automated
		;                             // minmax2::Minimum is automated
		;                             // minmax2::Maximum is automated
		minmax2.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax2::Step is automated
		minmax2.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                // simple_ar2::Attack is automated
		;                                // simple_ar2::Release is automated
		simple_ar2.setParameterT(2, 0.); // envelope::simple_ar::Gate
		simple_ar2.setParameterT(3, 0.); // envelope::simple_ar::AttackCurve
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.483442);
		this->setParameterT(1, -0.0216017);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 1.);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(1).getT(0).getT(0).setExternalData(b, index); // OSC_impl::file_player_t<NV>
		this->getT(1).getT(0).getT(3).setExternalData(b, index); // OSC_impl::simple_ar_t<NV>
		this->getT(1).getT(1).getT(0).setExternalData(b, index); // OSC_impl::file_player2_t<NV>
		this->getT(1).getT(1).getT(3).setExternalData(b, index); // OSC_impl::simple_ar2_t<NV>
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
using OSC = wrap::node<OSC_impl::instance<NV>>;
}


