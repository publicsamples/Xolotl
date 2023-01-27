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

namespace harmonic_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;
template <int NV>
using ptoggle_t = control::input_toggle<parameter::plain<file_player_t<NV>, 3>>;
template <int NV>
using pintchalter1_t = control::minmax<NV, 
                                       parameter::plain<ptoggle_t<NV>, 1>>;

template <int NV>
using pitchalter2_t = control::minmax<NV, 
                                      parameter::plain<ptoggle_t<NV>, 2>>;

template <int NV>
using pitchin_mod = parameter::chain<ranges::Identity, 
                                     parameter::plain<pintchalter1_t<NV>, 0>, 
                                     parameter::plain<pitchalter2_t<NV>, 0>>;

template <int NV>
using pitchin_t = control::pma<NV, pitchin_mod<NV>>;
template <int NV>
using clone_cable_t = control::clone_cable<parameter::cloned<parameter::plain<pitchin_t<NV>, 0>>, 
                                           duplilogic::spread>;

template <int NV>
using clone_cable28_t = control::clone_cable<parameter::cloned<parameter::plain<pitchin_t<NV>, 0>>, 
                                             duplilogic::random>;

template <int NV>
using clone_cable29_t = control::clone_cable<parameter::cloned<parameter::plain<pitchin_t<NV>, 0>>, 
                                             duplilogic::harmonics>;

template <int NV>
using clone_cable30_t = control::clone_cable<parameter::cloned<parameter::plain<pitchin_t<NV>, 0>>, 
                                             duplilogic::scale>;

template <int NV>
using clone_cable31_t = control::clone_cable<parameter::cloned<parameter::plain<pitchin_t<NV>, 0>>, 
                                             duplilogic::fixed>;

template <int NV>
using clone_pack1_cc = parameter::clonechain<parameter::cloned<parameter::plain<pitchin_t<NV>, 0>>, 
                                             parameter::cloned<parameter::plain<pintchalter1_t<NV>, 0>>>;
template <int NV>
using clone_pack1_t = wrap::data<control::clone_pack<clone_pack1_cc<NV>>, 
                                 data::external::sliderpack<0>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, clone_cable_t<NV>>, 
                                  clone_cable28_t<NV>, 
                                  clone_cable29_t<NV>, 
                                  clone_cable30_t<NV>, 
                                  clone_cable31_t<NV>, 
                                  clone_pack1_t<NV>>;

template <int NV>
using chain161_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split2_t<NV>>>;

template <int NV>
using clone_cable4_t = control::clone_cable<parameter::cloned<parameter::plain<ptoggle_t<NV>, 0>>, 
                                            duplilogic::fixed>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, clone_cable4_t<NV>>>;

template <int NV>
using split25_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain161_t<NV>>, 
                                   chain5_t<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, split25_t<NV>>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<2, chain6_t<NV>>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, file_player_t<NV>>, 
                                  core::gain>;

template <int NV>
using pitch_t = container::chain<parameter::empty, 
                                 wrap::fix<2, pitchin_t<NV>>, 
                                 pintchalter1_t<NV>, 
                                 pitchalter2_t<NV>, 
                                 ptoggle_t<NV>>;

template <int NV>
using chain148_t = container::chain<parameter::empty, 
                                    wrap::fix<2, control::pma<NV, parameter::empty>>>;

template <int NV>
using split52_t = container::split<parameter::empty, 
                                   wrap::fix<2, pitch_t<NV>>, 
                                   chain148_t<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, split52_t<NV>>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, chain4_t<NV>>, 
                                       chain3_t<NV>>;
template <int NV>
using clone_t = wrap::fix_clonesplit<clone_child_t<NV>, 16>;

namespace harmonic_t_parameters
{
// Parameter list for harmonic_impl::harmonic_t ----------------------------------------------------

template <int NV>
using pitchmode_toggle = parameter::plain<harmonic_impl::clone_cable4_t<NV>, 
                                          1>;
template <int NV>
using sprval1 = parameter::plain<harmonic_impl::clone_cable_t<NV>, 
                                 1>;
template <int NV>
using rand_val1 = parameter::plain<harmonic_impl::clone_cable28_t<NV>, 
                                   1>;
template <int NV>
using hrmval1 = parameter::plain<harmonic_impl::clone_cable29_t<NV>, 
                                 1>;
template <int NV>
using scalval1 = parameter::plain<harmonic_impl::clone_cable30_t<NV>, 
                                  1>;
template <int NV>
using fixedval = parameter::plain<harmonic_impl::clone_cable31_t<NV>, 
                                  1>;
using f1val = parameter::empty;
using f2val = f1val;
using f3val = f1val;
using f4val = f1val;
using f5val = f1val;
template <int NV>
using harmonic_t_plist = parameter::list<pitchmode_toggle<NV>, 
                                         sprval1<NV>, 
                                         rand_val1<NV>, 
                                         hrmval1<NV>, 
                                         scalval1<NV>, 
                                         fixedval<NV>, 
                                         f1val, 
                                         f2val, 
                                         f3val, 
                                         f4val, 
                                         f5val>;
}

template <int NV>
using harmonic_t_ = container::chain<harmonic_t_parameters::harmonic_t_plist<NV>, 
                                     wrap::fix<2, no_midi_t<NV>>, 
                                     clone_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public harmonic_impl::harmonic_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(harmonic);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(184)
		{
			0x005B, 0x0000, 0x7000, 0x7469, 0x6863, 0x6F6D, 0x6564, 0x745F, 
            0x676F, 0x6C67, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x015B, 0x0000, 0x7300, 
            0x7270, 0x6176, 0x316C, 0x0000, 0x8000, 0x00BF, 0x8000, 0x543F, 
            0x45D5, 0x00BF, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 0x0000, 
            0x6172, 0x646E, 0x765F, 0x6C61, 0x0031, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x035B, 
            0x0000, 0x6800, 0x6D72, 0x6176, 0x316C, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xA23F, 0x6F25, 0x003D, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0004, 0x0000, 0x6373, 0x6C61, 0x6176, 0x316C, 0x0000, 0x0000, 
            0x0000, 0x8000, 0xAA3F, 0x3A29, 0x003E, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0005, 0x0000, 0x6966, 0x6578, 0x7664, 0x6C61, 0x0000, 
            0x0000, 0x0000, 0x8000, 0xAC3F, 0xAB3C, 0x003C, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0006, 0x0000, 0x3166, 0x6176, 0x006C, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0xBB23, 0xBECF, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x075B, 0x0000, 0x6600, 0x7632, 0x6C61, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x633F, 0x0B55, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0008, 0x0000, 0x3366, 0x6176, 0x006C, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0xBAD9, 0x3E92, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x095B, 0x0000, 0x6600, 0x7634, 0x6C61, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x423F, 0x1028, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x000A, 0x0000, 0x3566, 0x6176, 0x006C, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xA927, 0x3F4D, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& no_midi = this->getT(0);                                               // harmonic_impl::no_midi_t<NV>
		auto& chain6 = this->getT(0).getT(0);                                        // harmonic_impl::chain6_t<NV>
		auto& split25 = this->getT(0).getT(0).getT(0);                               // harmonic_impl::split25_t<NV>
		auto& chain161 = this->getT(0).getT(0).getT(0).getT(0);                      // harmonic_impl::chain161_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                // harmonic_impl::split2_t<NV>
		auto& clone_cable = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);   // harmonic_impl::clone_cable_t<NV>
		auto& clone_cable28 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1); // harmonic_impl::clone_cable28_t<NV>
		auto& clone_cable29 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2); // harmonic_impl::clone_cable29_t<NV>
		auto& clone_cable30 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3); // harmonic_impl::clone_cable30_t<NV>
		auto& clone_cable31 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4); // harmonic_impl::clone_cable31_t<NV>
		auto& clone_pack1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5);   // harmonic_impl::clone_pack1_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(1);                        // harmonic_impl::chain5_t<NV>
		auto& clone_cable4 = this->getT(0).getT(0).getT(0).getT(1).getT(0);          // harmonic_impl::clone_cable4_t<NV>
		auto& clone = this->getT(1);                                                 // harmonic_impl::clone_t<NV>                                                 // harmonic_impl::clone_child_t<NV>
		auto chain4 = this->getT(1).getT(0);                                         // harmonic_impl::chain4_t<NV>
		auto file_player = this->getT(1).getT(0).getT(0);                            // harmonic_impl::file_player_t<NV>
		auto gain = this->getT(1).getT(0).getT(1);                                   // core::gain
		auto chain3 = this->getT(1).getT(1);                                         // harmonic_impl::chain3_t<NV>
		auto split52 = this->getT(1).getT(1).getT(0);                                // harmonic_impl::split52_t<NV>
		auto pitch = this->getT(1).getT(1).getT(0).getT(0);                          // harmonic_impl::pitch_t<NV>
		auto pitchin = this->getT(1).getT(1).getT(0).getT(0).getT(0);                // harmonic_impl::pitchin_t<NV>
		auto pintchalter1 = this->getT(1).getT(1).getT(0).getT(0).getT(1);           // harmonic_impl::pintchalter1_t<NV>
		auto pitchalter2 = this->getT(1).getT(1).getT(0).getT(0).getT(2);            // harmonic_impl::pitchalter2_t<NV>
		auto ptoggle = this->getT(1).getT(1).getT(0).getT(0).getT(3);                // harmonic_impl::ptoggle_t<NV>
		auto chain148 = this->getT(1).getT(1).getT(0).getT(1);                       // harmonic_impl::chain148_t<NV>
		auto pma34 = this->getT(1).getT(1).getT(0).getT(1).getT(0);                  // control::pma<NV, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, clone_cable4); // pitchmode_toggle -> clone_cable4::Value
		
		this->getParameterT(1).connectT(0, clone_cable); // sprval1 -> clone_cable::Value
		
		this->getParameterT(2).connectT(0, clone_cable28); // rand_val1 -> clone_cable28::Value
		
		this->getParameterT(3).connectT(0, clone_cable29); // hrmval1 -> clone_cable29::Value
		
		this->getParameterT(4).connectT(0, clone_cable30); // scalval1 -> clone_cable30::Value
		
		this->getParameterT(5).connectT(0, clone_cable31); // fixedval -> clone_cable31::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		ptoggle.getWrappedObject().getParameter().connectT(0, file_player);      // ptoggle -> file_player::FreqRatio
		pintchalter1.getWrappedObject().getParameter().connectT(0, ptoggle);     // pintchalter1 -> ptoggle::Value1
		pitchalter2.getWrappedObject().getParameter().connectT(0, ptoggle);      // pitchalter2 -> ptoggle::Value2
		pitchin.getWrappedObject().getParameter().connectT(0, pintchalter1);     // pitchin -> pintchalter1::Value
		pitchin.getWrappedObject().getParameter().connectT(1, pitchalter2);      // pitchin -> pitchalter2::Value
		clone_cable.getWrappedObject().getParameter().connectT(0, pitchin);      // clone_cable -> pitchin::Value
		clone_cable28.getWrappedObject().getParameter().connectT(0, pitchin);    // clone_cable28 -> pitchin::Value
		clone_cable29.getWrappedObject().getParameter().connectT(0, pitchin);    // clone_cable29 -> pitchin::Value
		clone_cable30.getWrappedObject().getParameter().connectT(0, pitchin);    // clone_cable30 -> pitchin::Value
		clone_cable31.getWrappedObject().getParameter().connectT(0, pitchin);    // clone_cable31 -> pitchin::Value
		clone_pack1.getWrappedObject().getParameter().connectT(0, pitchin);      // clone_pack1 -> pitchin::Value
		clone_pack1.getWrappedObject().getParameter().connectT(1, pintchalter1); // clone_pack1 -> pintchalter1::Value
		clone_cable4.getWrappedObject().getParameter().connectT(0, ptoggle);     // clone_cable4 -> ptoggle::Input
		
		// Default Values --------------------------------------------------------------------------
		
		;                                 // clone_cable::NumClones is deactivated
		;                                 // clone_cable::Value is automated
		clone_cable.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable28::NumClones is deactivated
		;                                   // clone_cable28::Value is automated
		clone_cable28.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable29::NumClones is deactivated
		;                                   // clone_cable29::Value is automated
		clone_cable29.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable30::NumClones is deactivated
		;                                   // clone_cable30::Value is automated
		clone_cable30.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                         // clone_cable31::NumClones is deactivated
		;                                         // clone_cable31::Value is automated
		clone_cable31.setParameterT(2, 0.522975); // control::clone_cable::Gamma
		
		;                                 // clone_pack1::NumClones is deactivated
		clone_pack1.setParameterT(1, 1.); // control::clone_pack::Value
		
		;                                  // clone_cable4::NumClones is deactivated
		;                                  // clone_cable4::Value is automated
		clone_cable4.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone.setParameterT(0, 16.); // container::clone::NumClones
		clone.setParameterT(1, 1.);  // container::clone::SplitSignal
		
		file_player.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                   // file_player::FreqRatio is automated
		
		gain.setParameterT(0, -22.);  // core::gain::Gain
		gain.setParameterT(1, 0.1);   // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                   // pitchin::Value is automated
		pitchin.setParameterT(1, 1.);       // control::pma::Multiply
		pitchin.setParameterT(2, 0.156436); // control::pma::Add
		
		;                                   // pintchalter1::Value is automated
		pintchalter1.setParameterT(1, 1.);  // control::minmax::Minimum
		pintchalter1.setParameterT(2, 16.); // control::minmax::Maximum
		pintchalter1.setParameterT(3, 1.);  // control::minmax::Skew
		pintchalter1.setParameterT(4, 1.);  // control::minmax::Step
		pintchalter1.setParameterT(5, 0.);  // control::minmax::Polarity
		
		;                                       // pitchalter2::Value is automated
		pitchalter2.setParameterT(1, 0.909091); // control::minmax::Minimum
		pitchalter2.setParameterT(2, 1.1);      // control::minmax::Maximum
		pitchalter2.setParameterT(3, 0.93424);  // control::minmax::Skew
		pitchalter2.setParameterT(4, 0.);       // control::minmax::Step
		pitchalter2.setParameterT(5, 0.);       // control::minmax::Polarity
		
		; // ptoggle::Input is automated
		; // ptoggle::Value1 is automated
		; // ptoggle::Value2 is automated
		
		pma34.setParameterT(0, 0.); // control::pma::Value
		pma34.setParameterT(1, 1.); // control::pma::Multiply
		pma34.setParameterT(2, 1.); // control::pma::Add
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, -0.772786);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.0583855);
		this->setParameterT(4, 0.1818);
		this->setParameterT(5, 0.020903);
		this->setParameterT(6, -0.405725);
		this->setParameterT(7, 0.544272);
		this->setParameterT(8, 0.286582);
		this->setParameterT(9, 0.140779);
		this->setParameterT(10, 0.803362);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).setExternalData(b, index); // harmonic_impl::clone_pack1_t<NV>
		this->getT(1).getT(0).getT(0).setExternalData(b, index);                         // harmonic_impl::file_player_t<NV>
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
using harmonic = wrap::node<harmonic_impl::instance<NV>>;
}


