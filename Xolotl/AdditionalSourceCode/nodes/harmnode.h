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

namespace harmnode_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;
template <int NV>
using file_player1_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;
template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using pma_unscaled_mod = parameter::chain<ranges::Identity, 
                                          parameter::plain<file_player_t<NV>, 3>, 
                                          parameter::plain<file_player1_t<NV>, 3>, 
                                          parameter::plain<oscillator_t<NV>, 2>>;

template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, pma_unscaled_mod<NV>>;

template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, 
                                              parameter::plain<pma_unscaled_t<NV>, 2>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, pma_unscaled_t<NV>>, 
                                 pma_unscaled1_t<NV>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled1_t<NV>, 2>>;

template <int NV>
using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player_t<NV>>>;

template <int NV>
using sb1_t = bypass::smoothed<20, sb1_t_<NV>>;
template <int NV>
using switcher_c0 = parameter::bypass<sb1_t<NV>>;

template <int NV>
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player1_t<NV>>>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb2_t<NV>>;

template <int NV>
using sb3_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, oscillator_t<NV>>>;

template <int NV>
using sb3_t = bypass::smoothed<20, sb3_t_<NV>>;
template <int NV>
using switcher_c2 = parameter::bypass<sb3_t<NV>>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0<NV>, 
                                          switcher_c1<NV>, 
                                          switcher_c2<NV>>;

template <int NV>
using switcher_t = control::xfader<switcher_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container_t = container::chain<parameter::empty, 
                                        wrap::fix<2, sb1_t<NV>>, 
                                        sb2_t<NV>, 
                                        sb3_t<NV>>;

namespace softbypass_switch4_t_parameters
{
DECLARE_PARAMETER_RANGE(Switch_InputRange, 
                        0., 
                        2.);

template <int NV>
using Switch = parameter::chain<Switch_InputRange, 
                                parameter::plain<harmnode_impl::switcher_t<NV>, 0>>;

}

template <int NV>
using softbypass_switch4_t = container::chain<softbypass_switch4_t_parameters::Switch<NV>, 
                                              wrap::fix<2, switcher_t<NV>>, 
                                              sb_container_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, split_t<NV>>, 
                                 minmax_t<NV>, 
                                 softbypass_switch4_t<NV>>;

namespace harmnode_t_parameters
{
// Parameter list for harmnode_impl::harmnode_t ----------------------------------------------------

template <int NV>
using pitch = parameter::plain<harmnode_impl::pma_unscaled_t<NV>, 
                               0>;
template <int NV>
using mode = parameter::plain<harmnode_impl::softbypass_switch4_t<NV>, 
                              0>;
template <int NV>
using OscWave = parameter::plain<harmnode_impl::oscillator_t<NV>, 
                                 0>;
template <int NV>
using harm = parameter::plain<harmnode_impl::minmax_t<NV>, 
                              0>;
template <int NV>
using min = parameter::plain<harmnode_impl::minmax_t<NV>, 
                             1>;
template <int NV>
using max = parameter::plain<harmnode_impl::minmax_t<NV>, 
                             2>;
template <int NV>
using step = parameter::plain<harmnode_impl::minmax_t<NV>, 
                              4>;
template <int NV>
using wheel = parameter::plain<harmnode_impl::pma_unscaled1_t<NV>, 
                               0>;
template <int NV>
using harmnode_t_plist = parameter::list<pitch<NV>, 
                                         mode<NV>, 
                                         OscWave<NV>, 
                                         harm<NV>, 
                                         min<NV>, 
                                         max<NV>, 
                                         step<NV>, 
                                         wheel<NV>>;
}

template <int NV>
using harmnode_t_ = container::chain<harmnode_t_parameters::harmnode_t_plist<NV>, 
                                     wrap::fix<2, chain_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public harmnode_impl::harmnode_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(harmnode);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(122)
		{
			0x005B, 0x0000, 0x7000, 0x7469, 0x6863, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6F6D, 0x6564, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 
            0x0000, 0x734F, 0x5763, 0x7661, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x4080, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 
            0x0000, 0x6800, 0x7261, 0x006D, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 
            0x6D00, 0x6E69, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0005, 0x0000, 0x616D, 
            0x0078, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x065B, 0x0000, 0x7300, 0x6574, 0x0070, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x075B, 0x0000, 0x7700, 0x6568, 0x6C65, 0x0000, 
            0x0000, 0x0000, 0x0000, 0xAF40, 0x7EDE, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain = this->getT(0);                                        // harmnode_impl::chain_t<NV>
		auto& split = this->getT(0).getT(0);                                // harmnode_impl::split_t<NV>
		auto& pma_unscaled = this->getT(0).getT(0).getT(0);                 // harmnode_impl::pma_unscaled_t<NV>
		auto& pma_unscaled1 = this->getT(0).getT(0).getT(1);                // harmnode_impl::pma_unscaled1_t<NV>
		auto& minmax = this->getT(0).getT(1);                               // harmnode_impl::minmax_t<NV>
		auto& softbypass_switch4 = this->getT(0).getT(2);                   // harmnode_impl::softbypass_switch4_t<NV>
		auto& switcher = this->getT(0).getT(2).getT(0);                     // harmnode_impl::switcher_t<NV>
		auto& sb_container = this->getT(0).getT(2).getT(1);                 // harmnode_impl::sb_container_t<NV>
		auto& sb1 = this->getT(0).getT(2).getT(1).getT(0);                  // harmnode_impl::sb1_t<NV>
		auto& file_player = this->getT(0).getT(2).getT(1).getT(0).getT(0);  // harmnode_impl::file_player_t<NV>
		auto& sb2 = this->getT(0).getT(2).getT(1).getT(1);                  // harmnode_impl::sb2_t<NV>
		auto& file_player1 = this->getT(0).getT(2).getT(1).getT(1).getT(0); // harmnode_impl::file_player1_t<NV>
		auto& sb3 = this->getT(0).getT(2).getT(1).getT(2);                  // harmnode_impl::sb3_t<NV>
		auto& oscillator = this->getT(0).getT(2).getT(1).getT(2).getT(0);   // harmnode_impl::oscillator_t<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		softbypass_switch4.getParameterT(0).connectT(0, switcher); // Switch -> switcher::Value
		this->getParameterT(0).connectT(0, pma_unscaled);          // pitch -> pma_unscaled::Value
		
		this->getParameterT(1).connectT(0, softbypass_switch4); // mode -> softbypass_switch4::Switch
		
		this->getParameterT(2).connectT(0, oscillator); // OscWave -> oscillator::Mode
		
		this->getParameterT(3).connectT(0, minmax); // harm -> minmax::Value
		
		this->getParameterT(4).connectT(0, minmax); // min -> minmax::Minimum
		
		this->getParameterT(5).connectT(0, minmax); // max -> minmax::Maximum
		
		this->getParameterT(6).connectT(0, minmax); // step -> minmax::Step
		
		this->getParameterT(7).connectT(0, pma_unscaled1); // wheel -> pma_unscaled1::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma_unscaled.getWrappedObject().getParameter().connectT(0, file_player);   // pma_unscaled -> file_player::FreqRatio
		pma_unscaled.getWrappedObject().getParameter().connectT(1, file_player1);  // pma_unscaled -> file_player1::FreqRatio
		pma_unscaled.getWrappedObject().getParameter().connectT(2, oscillator);    // pma_unscaled -> oscillator::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(0, pma_unscaled); // pma_unscaled1 -> pma_unscaled::Add
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled1);       // minmax -> pma_unscaled1::Add
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1); // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2); // switcher -> sb2::Bypassed
		switcher_p.getParameterT(2).connectT(0, sb3); // switcher -> sb3::Bypassed
		
		// Default Values --------------------------------------------------------------------------
		
		;                                  // pma_unscaled::Value is automated
		pma_unscaled.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                  // pma_unscaled::Add is automated
		
		;                                   // pma_unscaled1::Value is automated
		pma_unscaled1.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled1::Add is automated
		
		;                            // minmax::Value is automated
		;                            // minmax::Minimum is automated
		;                            // minmax::Maximum is automated
		minmax.setParameterT(3, 1.); // control::minmax::Skew
		;                            // minmax::Step is automated
		minmax.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // softbypass_switch4::Switch is automated
		
		; // switcher::Value is automated
		
		file_player.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                   // file_player::FreqRatio is automated
		
		file_player1.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player1.setParameterT(1, 1.);   // core::file_player::Gate
		file_player1.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player1::FreqRatio is automated
		
		;                                      // oscillator::Mode is automated
		oscillator.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                      // oscillator::FreqRatio is automated
		oscillator.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);       // core::oscillator::Phase
		oscillator.setParameterT(5, 0.495563); // core::oscillator::Gain
		
		this->setParameterT(0, 2.);
		this->setParameterT(1, 2.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.995585);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index); // harmnode_impl::file_player_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index); // harmnode_impl::file_player1_t<NV>
		this->getT(0).getT(2).getT(1).getT(2).getT(0).setExternalData(b, index); // harmnode_impl::oscillator_t<NV>
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
using harmnode = wrap::node<harmnode_impl::instance<NV>>;
}


