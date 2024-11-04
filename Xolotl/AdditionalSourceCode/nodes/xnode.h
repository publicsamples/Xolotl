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

namespace xnode_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;
template <int NV>
using oscillator4_t = wrap::no_data<core::oscillator<NV>>;
template <int NV> using oscillator3_t = oscillator4_t<NV>;
template <int NV> using oscillator1_t = oscillator4_t<NV>;
template <int NV> using oscillator2_t = oscillator4_t<NV>;
template <int NV> using oscillator_t = oscillator4_t<NV>;

template <int NV>
using pma_unscaled1_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player_t<NV>, 3>, 
                                           parameter::plain<oscillator4_t<NV>, 2>, 
                                           parameter::plain<oscillator3_t<NV>, 2>, 
                                           parameter::plain<oscillator1_t<NV>, 2>, 
                                           parameter::plain<oscillator2_t<NV>, 2>, 
                                           parameter::plain<oscillator_t<NV>, 2>>;

template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, pma_unscaled1_mod<NV>>;
template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, 
                                             parameter::plain<pma_unscaled1_t<NV>, 2>>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled_t<NV>, 2>>;
<<<<<<< HEAD
using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<7>>;

template <int NV>
using input_toggle2_t = control::input_toggle<parameter::plain<oscillator_t<NV>, 3>>;

template <int NV>
using input_toggle3_t = control::input_toggle<parameter::plain<oscillator2_t<NV>, 3>>;

template <int NV>
using input_toggle9_t = control::input_toggle<parameter::plain<oscillator1_t<NV>, 3>>;

template <int NV>
using input_toggle1_t = control::input_toggle<parameter::plain<oscillator3_t<NV>, 4>>;

template <int NV>
using input_toggle6_t = control::input_toggle<parameter::plain<file_player_t<NV>, 1>>;

template <int NV>
using input_toggle7_t = control::input_toggle<parameter::plain<oscillator6_t<NV>, 3>>;

template <int NV>
using input_toggle8_t = control::input_toggle<parameter::plain<oscillator7_t<NV>, 3>>;

template <int NV>
using input_toggle4_t = control::input_toggle<parameter::plain<oscillator8_t<NV>, 3>>;
template <int NV> using oscillator5_t = oscillator6_t<NV>;

template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<core::gain<NV>, 0>>;

template <int NV>
using sliderbank1_c0 = parameter::chain<ranges::Identity, 
                                        parameter::plain<input_toggle2_t<NV>, 0>, 
                                        parameter::plain<input_toggle3_t<NV>, 0>, 
                                        parameter::plain<input_toggle9_t<NV>, 0>, 
                                        parameter::plain<input_toggle1_t<NV>, 0>, 
                                        parameter::plain<input_toggle5_t<NV>, 0>, 
                                        parameter::plain<input_toggle6_t<NV>, 0>, 
                                        parameter::plain<input_toggle7_t<NV>, 0>, 
                                        parameter::plain<input_toggle8_t<NV>, 1>, 
                                        parameter::plain<input_toggle8_t<NV>, 0>, 
                                        parameter::plain<input_toggle4_t<NV>, 0>, 
                                        parameter::plain<oscillator5_t<NV>, 5>, 
                                        parameter::plain<input_toggle_t<NV>, 0>>;

template <int NV>
using ahdsr_c1 = parameter::chain<ranges::Identity, 
                                  parameter::plain<input_toggle2_t<NV>, 2>, 
                                  parameter::plain<input_toggle3_t<NV>, 2>, 
                                  parameter::plain<input_toggle9_t<NV>, 2>, 
                                  parameter::plain<input_toggle1_t<NV>, 2>, 
                                  parameter::plain<input_toggle6_t<NV>, 2>, 
                                  parameter::plain<input_toggle7_t<NV>, 2>, 
                                  parameter::plain<input_toggle8_t<NV>, 2>, 
                                  parameter::plain<input_toggle4_t<NV>, 2>>;

template <int NV>
using ahdsr_multimod = parameter::list<parameter::plain<input_toggle_t<NV>, 2>, 
                                       ahdsr_c1<NV>>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;
DECLARE_PARAMETER_RANGE_SKEW(sliderbank1_c1Range, 
                             0., 
                             10000., 
                             0.197672);

template <int NV>
using sliderbank1_c1 = parameter::from0To1<ahdsr_t<NV>, 
                                           0, 
                                           sliderbank1_c1Range>;

template <int NV>
using sliderbank1_c2 = parameter::from0To1<ahdsr_t<NV>, 
                                           3, 
                                           sliderbank1_c1Range>;

template <int NV>
using sliderbank1_c3 = parameter::from0To1<ahdsr_t<NV>, 
                                           5, 
                                           sliderbank1_c1Range>;

template <int NV>
using sliderbank1_multimod = parameter::list<sliderbank1_c0<NV>, 
                                             sliderbank1_c1<NV>, 
                                             sliderbank1_c2<NV>, 
                                             sliderbank1_c3<NV>>;

template <int NV>
using sliderbank1_t = wrap::data<control::sliderbank<sliderbank1_multimod<NV>>, 
                                 data::external::sliderpack<7>>;
=======
>>>>>>> parent of 416899d (s&h gate)

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, minmax_t<NV>>, 
                                      pma_unscaled_t<NV>, 
                                      pma_unscaled1_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, oscillator_t<NV>>, 
                                   oscillator2_t<NV>, 
                                   oscillator1_t<NV>, 
                                   oscillator3_t<NV>, 
                                   oscillator4_t<NV>, 
                                   file_player_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<fx::sampleandhold<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, tempo_sync_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, wrap::no_process<math::clear<NV>>>, 
                                  fx::sampleandhold<NV>>;

using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

DECLARE_PARAMETER_RANGE_SKEW(pma_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma_mod_0 = parameter::from0To1<filters::allpass<NV>, 
                                      0, 
                                      pma_mod_0Range>;

template <int NV>
using pma_mod_1 = parameter::from0To1<filters::svf<NV>, 
                                      0, 
                                      pma_mod_0Range>;

template <int NV> using pma_mod_2 = pma_mod_1<NV>;

template <int NV> using pma_mod_3 = pma_mod_1<NV>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 pma_mod_0<NV>, 
                                 pma_mod_1<NV>, 
                                 pma_mod_2<NV>, 
                                 pma_mod_3<NV>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<pma_t<NV>, 0>, 
                                  parameter::plain<pma_unscaled1_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak_t<NV>>, 
                                   math::clear<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain11_t>, 
                                  chain12_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split2_t<NV>>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  chain7_t<NV>, 
                                  chain10_t<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain2_t<NV>>, 
                                 chain3_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader_t<NV>>, 
                                  split_t<NV>>;

template <int NV> using xfader1_c0 = xfader_c0<NV>;

template <int NV> using xfader1_c1 = xfader_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV> using chain5_t = chain2_t<NV>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, pma_t<NV>>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::allpass<NV>>, 
                                  core::gain<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, filters::svf<NV>>, 
                                    filters::svf<NV>, 
                                    filters::svf<NV>, 
                                    chain9_t<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, modchain2_t<NV>>, 
                                  branch2_t<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain5_t<NV>>, 
                                  chain6_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader1_t<NV>>, 
                                  split1_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, modchain1_t<NV>>, 
                                 branch_t<NV>, 
                                 chain1_t<NV>, 
<<<<<<< HEAD
                                 chain4_t<NV>, 
                                 input_toggle_t<NV>, 
                                 core::gain<NV>, 
                                 core::gain<NV>>;
=======
                                 chain4_t<NV>>;
>>>>>>> parent of 416899d (s&h gate)

template <int NV>
using frame2_block_t = container::chain<parameter::empty, 
                                        wrap::fix<2, chain_t<NV>>>;

template <int NV>
using fix8_block1_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, frame2_block_t<NV>>>;

template <int NV>
using fix8_block1_t = wrap::fix_block<8, fix8_block1_t_<NV>>;

namespace xnode_t_parameters
{
// Parameter list for xnode_impl::xnode_t ----------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(Mode_InputRange, 
                             0., 
                             11., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Mode_0Range, 
                             0., 
                             5., 
                             1.);

template <int NV>
using Mode_0 = parameter::from0To1<xnode_impl::branch_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode = parameter::chain<Mode_InputRange, Mode_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FxValue_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using FxValue_0 = parameter::from0To1<xnode_impl::tempo_sync_t<NV>, 
                                      0, 
                                      FxValue_0Range>;

DECLARE_PARAMETER_RANGE_STEP(FxValue_1Range, 
                             0., 
                             1000., 
                             0.1);

template <int NV>
using FxValue_1 = parameter::from0To1<xnode_impl::tempo_sync_t<NV>, 
                                      3, 
                                      FxValue_1Range>;

template <int NV>
using FxValue = parameter::chain<ranges::Identity, 
                                 FxValue_0<NV>, 
                                 FxValue_1<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(FilterRes_3Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using FilterRes_3 = parameter::from0To1<filters::allpass<NV>, 
                                        1, 
                                        FilterRes_3Range>;

template <int NV>
using FilterRes = parameter::chain<ranges::Identity, 
                                   parameter::plain<filters::svf<NV>, 1>, 
                                   parameter::plain<filters::svf<NV>, 1>, 
                                   parameter::plain<filters::svf<NV>, 1>, 
                                   FilterRes_3<NV>>;

template <int NV>
using Harm = parameter::plain<xnode_impl::minmax_t<NV>, 
                              0>;
template <int NV>
using min = parameter::plain<xnode_impl::minmax_t<NV>, 
                             1>;
template <int NV>
using max = parameter::plain<xnode_impl::minmax_t<NV>, 
                             2>;
template <int NV>
using step = parameter::plain<xnode_impl::minmax_t<NV>, 
                              4>;
template <int NV>
using FxMix = parameter::plain<xnode_impl::xfader_t<NV>, 
                               0>;
template <int NV>
using FxShDiv = parameter::plain<xnode_impl::tempo_sync_t<NV>, 
                                 1>;
template <int NV>
using FxShSync = parameter::plain<xnode_impl::tempo_sync_t<NV>, 
                                  2>;
template <int NV>
using shPitch = parameter::plain<xnode_impl::pma_unscaled1_t<NV>, 
                                 1>;
template <int NV>
using FilterMix = parameter::plain<xnode_impl::xfader1_t<NV>, 
                                   0>;
template <int NV>
using FilterType = parameter::plain<xnode_impl::branch2_t<NV>, 
                                    0>;
template <int NV>
using FilterCut = parameter::plain<xnode_impl::pma_t<NV>, 2>;
template <int NV>
using FilterFxMod = parameter::plain<xnode_impl::pma_t<NV>, 1>;
template <int NV>
using DET = parameter::plain<xnode_impl::pma_unscaled_t<NV>, 
                             0>;
template <int NV>
using xnode_t_plist = parameter::list<Harm<NV>, 
                                      min<NV>, 
                                      max<NV>, 
                                      step<NV>, 
                                      Mode<NV>, 
                                      FxMix<NV>, 
                                      FxValue<NV>, 
                                      FxShDiv<NV>, 
                                      FxShSync<NV>, 
                                      shPitch<NV>, 
                                      FilterMix<NV>, 
                                      FilterType<NV>, 
                                      FilterRes<NV>, 
                                      FilterCut<NV>, 
                                      FilterFxMod<NV>, 
                                      DET<NV>>;
}

template <int NV>
using xnode_t_ = container::chain<xnode_t_parameters::xnode_t_plist<NV>, 
                                  wrap::fix<2, fix8_block1_t<NV>>, 
                                  core::gain<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public xnode_impl::xnode_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(xnode);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(260)
		{
			0x005B, 0x0000, 0x4800, 0x7261, 0x006D, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xEF1D, 0x3F33, 0x0000, 0x3F80, 0x0000, 0x0000, 0x015B, 
            0x0000, 0x6D00, 0x6E69, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0002, 0x0000, 
            0x616D, 0x0078, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 0x0000, 0x7300, 0x6574, 
            0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 0xD70A, 0x3C86, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 0x4D00, 0x646F, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x4130, 0x0000, 0x40C0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x055B, 0x0000, 0x4600, 0x4D78, 0x7869, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0006, 0x0000, 0x7846, 0x6156, 0x756C, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0691, 0x3F0F, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x075B, 0x0000, 0x4600, 0x5378, 0x4468, 0x7669, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0008, 0x0000, 0x7846, 0x6853, 0x7953, 
            0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0009, 0x0000, 0x6873, 0x6950, 
            0x6374, 0x0068, 0x0000, 0xBF80, 0x0000, 0x3F80, 0xD604, 0xBCE3, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x4D72, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000B, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x7954, 0x6570, 0x0000, 0x0000, 0x0000, 
            0x4000, 0x0040, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x000C, 0x0000, 0x6946, 0x746C, 0x7265, 0x6552, 0x0073, 0x999A, 
            0x3E99, 0x6666, 0x411E, 0xA03F, 0x4117, 0x8918, 0x3E87, 0x0000, 
            0x0000, 0x0D5B, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4372, 0x7475, 
            0x0000, 0x8000, 0x0024, 0x8000, 0x273F, 0xACC3, 0x003E, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000E, 0x0000, 0x6946, 0x746C, 0x7265, 
            0x7846, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0F5B, 0x0000, 0x4400, 
            0x5445, 0x0000, 0x0000, 0x0000, 0x0000, 0xF040, 0x9736, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block1 = this->getT(0);                                               // xnode_impl::fix8_block1_t<NV>
		auto& frame2_block = this->getT(0).getT(0);                                      // xnode_impl::frame2_block_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0);                                     // xnode_impl::chain_t<NV>
		auto& modchain1 = this->getT(0).getT(0).getT(0).getT(0);                         // xnode_impl::modchain1_t<NV>
		auto& minmax = this->getT(0).getT(0).getT(0).getT(0).getT(0);                    // xnode_impl::minmax_t<NV>
		auto& pma_unscaled = this->getT(0).getT(0).getT(0).getT(0).getT(1);              // xnode_impl::pma_unscaled_t<NV>
		auto& pma_unscaled1 = this->getT(0).getT(0).getT(0).getT(0).getT(2);             // xnode_impl::pma_unscaled1_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0).getT(1);                            // xnode_impl::branch_t<NV>
		auto& oscillator = this->getT(0).getT(0).getT(0).getT(1).getT(0);                // xnode_impl::oscillator_t<NV>
		auto& oscillator2 = this->getT(0).getT(0).getT(0).getT(1).getT(1);               // xnode_impl::oscillator2_t<NV>
		auto& oscillator1 = this->getT(0).getT(0).getT(0).getT(1).getT(2);               // xnode_impl::oscillator1_t<NV>
		auto& oscillator3 = this->getT(0).getT(0).getT(0).getT(1).getT(3);               // xnode_impl::oscillator3_t<NV>
		auto& oscillator4 = this->getT(0).getT(0).getT(0).getT(1).getT(4);               // xnode_impl::oscillator4_t<NV>
		auto& file_player = this->getT(0).getT(0).getT(0).getT(1).getT(5);               // xnode_impl::file_player_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(2);                            // xnode_impl::chain1_t<NV>
		auto& xfader = this->getT(0).getT(0).getT(0).getT(2).getT(0);                    // xnode_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(0).getT(0).getT(2).getT(1);                     // xnode_impl::split_t<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0);            // xnode_impl::chain2_t<NV>
		auto& gain = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);      // core::gain<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1);            // xnode_impl::chain3_t<NV>
		auto& modchain = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(0);  // xnode_impl::modchain_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(0).getT(2).                        // xnode_impl::tempo_sync_t<NV>
                           getT(1).getT(1).getT(0).getT(0);
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(1);    // xnode_impl::chain7_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(0).getT(2).                            // wrap::no_process<math::clear<NV>>
                       getT(1).getT(1).getT(1).getT(0);
		auto& sampleandhold = this->getT(0).getT(0).getT(0).getT(2).                     // fx::sampleandhold<NV>
                              getT(1).getT(1).getT(1).getT(1);
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(2);   // xnode_impl::chain10_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(0).getT(2).                            // xnode_impl::split2_t<NV>
                       getT(1).getT(1).getT(2).getT(0);
		auto& chain11 = this->getT(0).getT(0).getT(0).getT(2).                           // xnode_impl::chain11_t
                        getT(1).getT(1).getT(2).getT(0).
                        getT(0);
		auto& chain12 = this->getT(0).getT(0).getT(0).getT(2).                           // xnode_impl::chain12_t<NV>
                        getT(1).getT(1).getT(2).getT(0).
                        getT(1);
		auto& peak = this->getT(0).getT(0).getT(0).getT(2).getT(1).                      // xnode_impl::peak_t<NV>
                     getT(1).getT(2).getT(0).getT(1).getT(0);
		auto& clear = this->getT(0).getT(0).getT(0).getT(2).getT(1).                     // math::clear<NV>
                      getT(1).getT(2).getT(0).getT(1).getT(1);
		auto& gain1 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(3);     // core::gain<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(3);                            // xnode_impl::chain4_t<NV>
		auto& xfader1 = this->getT(0).getT(0).getT(0).getT(3).getT(0);                   // xnode_impl::xfader1_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(0).getT(3).getT(1);                    // xnode_impl::split1_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0);            // xnode_impl::chain5_t<NV>
		auto& gain2 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0).getT(0);     // core::gain<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1);            // xnode_impl::chain6_t<NV>
		auto& modchain2 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1).getT(0); // xnode_impl::modchain2_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0).getT(3).                               // xnode_impl::pma_t<NV>
                    getT(1).getT(1).getT(0).getT(0);
		auto& branch2 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1).getT(1); // xnode_impl::branch2_t<NV>
		auto& svf1 = this->getT(0).getT(0).getT(0).getT(3).                            // filters::svf<NV>
                     getT(1).getT(1).getT(1).getT(0);
		auto& svf6 = this->getT(0).getT(0).getT(0).getT(3).                          // filters::svf<NV>
                     getT(1).getT(1).getT(1).getT(1);
		auto& svf5 = this->getT(0).getT(0).getT(0).getT(3).                          // filters::svf<NV>
                     getT(1).getT(1).getT(1).getT(2);
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(3).                        // xnode_impl::chain9_t<NV>
                       getT(1).getT(1).getT(1).getT(3);
<<<<<<< HEAD
		auto& gain3 = this->getT(0).getT(0).getT(0).getT(5).getT(1).getT(1).getT(2); // core::gain<NV>
		auto& input_toggle = this->getT(0).getT(0).getT(0).getT(6);                  // xnode_impl::input_toggle_t<NV>
		auto& gain4 = this->getT(0).getT(0).getT(0).getT(7);                         // core::gain<NV>
		auto& gain5 = this->getT(0).getT(0).getT(0).getT(8);                         // core::gain<NV>
=======
		auto& allpass = this->getT(0).getT(0).getT(0).getT(3).                       // filters::allpass<NV>
                        getT(1).getT(1).getT(1).getT(3).
                        getT(0);
		auto& gain6 = this->getT(0).getT(0).getT(0).getT(3).                         // core::gain<NV>
                      getT(1).getT(1).getT(1).getT(3).
                      getT(1);
		auto& gain3 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1).getT(2); // core::gain<NV>
		auto& gain5 = this->getT(1);                                                 // core::gain<NV>
>>>>>>> parent of 416899d (s&h gate)
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, minmax); // Harm -> minmax::Value
		
		this->getParameterT(1).connectT(0, minmax); // min -> minmax::Minimum
		
		this->getParameterT(2).connectT(0, minmax); // max -> minmax::Maximum
		
		this->getParameterT(3).connectT(0, minmax); // step -> minmax::Step
		
		this->getParameterT(4).connectT(0, branch); // Mode -> branch::Index
		
		this->getParameterT(5).connectT(0, xfader); // FxMix -> xfader::Value
		
		auto& FxValue_p = this->getParameterT(6);
		FxValue_p.connectT(0, tempo_sync); // FxValue -> tempo_sync::Tempo
		FxValue_p.connectT(1, tempo_sync); // FxValue -> tempo_sync::UnsyncedTime
		
		this->getParameterT(7).connectT(0, tempo_sync); // FxShDiv -> tempo_sync::Multiplier
		
		this->getParameterT(8).connectT(0, tempo_sync); // FxShSync -> tempo_sync::Enabled
		
		this->getParameterT(9).connectT(0, pma_unscaled1); // shPitch -> pma_unscaled1::Multiply
		
		this->getParameterT(10).connectT(0, xfader1); // FilterMix -> xfader1::Value
		
		this->getParameterT(11).connectT(0, branch2); // FilterType -> branch2::Index
		
		auto& FilterRes_p = this->getParameterT(12);
		FilterRes_p.connectT(0, svf1);    // FilterRes -> svf1::Q
		FilterRes_p.connectT(1, svf6);    // FilterRes -> svf6::Q
		FilterRes_p.connectT(2, svf5);    // FilterRes -> svf5::Q
		FilterRes_p.connectT(3, allpass); // FilterRes -> allpass::Q
		
		this->getParameterT(13).connectT(0, pma); // FilterCut -> pma::Add
		
		this->getParameterT(14).connectT(0, pma); // FilterFxMod -> pma::Multiply
		
		this->getParameterT(15).connectT(0, pma_unscaled); // DET -> pma_unscaled::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma_unscaled1.getWrappedObject().getParameter().connectT(0, file_player);  // pma_unscaled1 -> file_player::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(1, oscillator4);  // pma_unscaled1 -> oscillator4::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(2, oscillator3);  // pma_unscaled1 -> oscillator3::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(3, oscillator1);  // pma_unscaled1 -> oscillator1::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(4, oscillator2);  // pma_unscaled1 -> oscillator2::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(5, oscillator);   // pma_unscaled1 -> oscillator::FreqRatio
		pma_unscaled.getWrappedObject().getParameter().connectT(0, pma_unscaled1); // pma_unscaled -> pma_unscaled1::Add
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled);        // minmax -> pma_unscaled::Add
<<<<<<< HEAD
		input_toggle2.getWrappedObject().getParameter().connectT(0, oscillator);   // input_toggle2 -> oscillator::Gate
		input_toggle3.getWrappedObject().getParameter().connectT(0, oscillator2);  // input_toggle3 -> oscillator2::Gate
		input_toggle9.getWrappedObject().getParameter().connectT(0, oscillator1);  // input_toggle9 -> oscillator1::Gate
		input_toggle1.getWrappedObject().getParameter().connectT(0, oscillator3);  // input_toggle1 -> oscillator3::Phase
		input_toggle6.getWrappedObject().getParameter().connectT(0, file_player);  // input_toggle6 -> file_player::Gate
		input_toggle7.getWrappedObject().getParameter().connectT(0, oscillator6);  // input_toggle7 -> oscillator6::Gate
		input_toggle8.getWrappedObject().getParameter().connectT(0, oscillator7);  // input_toggle8 -> oscillator7::Gate
		input_toggle4.getWrappedObject().getParameter().connectT(0, oscillator8);  // input_toggle4 -> oscillator8::Gate
		input_toggle.getWrappedObject().getParameter().connectT(0, gain4);         // input_toggle -> gain4::Gain
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, input_toggle);  // ahdsr -> input_toggle::Value2
		ahdsr_p.getParameterT(1).connectT(0, input_toggle2); // ahdsr -> input_toggle2::Value2
		ahdsr_p.getParameterT(1).connectT(1, input_toggle3); // ahdsr -> input_toggle3::Value2
		ahdsr_p.getParameterT(1).connectT(2, input_toggle9); // ahdsr -> input_toggle9::Value2
		ahdsr_p.getParameterT(1).connectT(3, input_toggle1); // ahdsr -> input_toggle1::Value2
		ahdsr_p.getParameterT(1).connectT(4, input_toggle6); // ahdsr -> input_toggle6::Value2
		ahdsr_p.getParameterT(1).connectT(5, input_toggle7); // ahdsr -> input_toggle7::Value2
		ahdsr_p.getParameterT(1).connectT(6, input_toggle8); // ahdsr -> input_toggle8::Value2
		ahdsr_p.getParameterT(1).connectT(7, input_toggle4); // ahdsr -> input_toggle4::Value2
		auto& sliderbank1_p = sliderbank1.getWrappedObject().getParameter();
		sliderbank1_p.getParameterT(0).connectT(0, input_toggle2); // sliderbank1 -> input_toggle2::Input
		sliderbank1_p.getParameterT(0).connectT(1, input_toggle3); // sliderbank1 -> input_toggle3::Input
		sliderbank1_p.getParameterT(0).connectT(2, input_toggle9); // sliderbank1 -> input_toggle9::Input
		sliderbank1_p.getParameterT(0).connectT(3, input_toggle1); // sliderbank1 -> input_toggle1::Input
		sliderbank1_p.getParameterT(0).connectT(4, input_toggle5); // sliderbank1 -> input_toggle5::Input
		sliderbank1_p.getParameterT(0).connectT(5, input_toggle6); // sliderbank1 -> input_toggle6::Input
		sliderbank1_p.getParameterT(0).connectT(6, input_toggle7); // sliderbank1 -> input_toggle7::Input
		sliderbank1_p.getParameterT(0).connectT(7, input_toggle8); // sliderbank1 -> input_toggle8::Value1
		sliderbank1_p.getParameterT(0).connectT(8, input_toggle8); // sliderbank1 -> input_toggle8::Input
		sliderbank1_p.getParameterT(0).connectT(9, input_toggle4); // sliderbank1 -> input_toggle4::Input
		sliderbank1_p.getParameterT(0).connectT(10, oscillator5);  // sliderbank1 -> oscillator5::Gain
		sliderbank1_p.getParameterT(0).connectT(11, input_toggle); // sliderbank1 -> input_toggle::Input
		sliderbank1_p.getParameterT(1).connectT(0, ahdsr);         // sliderbank1 -> ahdsr::Attack
		sliderbank1_p.getParameterT(2).connectT(0, ahdsr);         // sliderbank1 -> ahdsr::Decay
		sliderbank1_p.getParameterT(3).connectT(0, ahdsr);         // sliderbank1 -> ahdsr::Release
		peak1.getParameter().connectT(0, pma1);                    // peak1 -> pma1::Value
=======
>>>>>>> parent of 416899d (s&h gate)
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);               // xfader -> gain1::Gain
		tempo_sync.getParameter().connectT(0, sampleandhold);       // tempo_sync -> sampleandhold::Counter
		pma.getWrappedObject().getParameter().connectT(0, allpass); // pma -> allpass::Frequency
		pma.getWrappedObject().getParameter().connectT(1, svf5);    // pma -> svf5::Frequency
		pma.getWrappedObject().getParameter().connectT(2, svf6);    // pma -> svf6::Frequency
		pma.getWrappedObject().getParameter().connectT(3, svf1);    // pma -> svf1::Frequency
		peak.getParameter().connectT(0, pma);                       // peak -> pma::Value
		peak.getParameter().connectT(1, pma_unscaled1);             // peak -> pma_unscaled1::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain2); // xfader1 -> gain2::Gain
		xfader1_p.getParameterT(1).connectT(0, gain3); // xfader1 -> gain3::Gain
		
		// Default Values --------------------------------------------------------------------------
		
		;                            // minmax::Value is automated
		;                            // minmax::Minimum is automated
		;                            // minmax::Maximum is automated
		minmax.setParameterT(3, 1.); // control::minmax::Skew
		;                            // minmax::Step is automated
		minmax.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                  // pma_unscaled::Value is automated
		pma_unscaled.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                  // pma_unscaled::Add is automated
		
		; // pma_unscaled1::Value is automated
		; // pma_unscaled1::Multiply is automated
		; // pma_unscaled1::Add is automated
		
		; // branch::Index is automated
		
		oscillator.setParameterT(0, 0.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 440.); // core::oscillator::Frequency
		;                                  // oscillator::FreqRatio is automated
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 1.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		oscillator2.setParameterT(0, 1.);   // core::oscillator::Mode
		oscillator2.setParameterT(1, 440.); // core::oscillator::Frequency
		;                                   // oscillator2::FreqRatio is automated
		oscillator2.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator2.setParameterT(4, 1.);   // core::oscillator::Phase
		oscillator2.setParameterT(5, 1.);   // core::oscillator::Gain
		
		oscillator1.setParameterT(0, 2.);   // core::oscillator::Mode
		oscillator1.setParameterT(1, 440.); // core::oscillator::Frequency
		;                                   // oscillator1::FreqRatio is automated
		oscillator1.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator1.setParameterT(4, 1.);   // core::oscillator::Phase
		oscillator1.setParameterT(5, 1.);   // core::oscillator::Gain
		
		oscillator3.setParameterT(0, 3.);   // core::oscillator::Mode
		oscillator3.setParameterT(1, 85.4); // core::oscillator::Frequency
		;                                   // oscillator3::FreqRatio is automated
		oscillator3.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator3.setParameterT(4, 1.);   // core::oscillator::Phase
		oscillator3.setParameterT(5, 1.);   // core::oscillator::Gain
		
		oscillator4.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator4.setParameterT(1, 85.4); // core::oscillator::Frequency
		;                                   // oscillator4::FreqRatio is automated
		oscillator4.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator4.setParameterT(4, 1.);   // core::oscillator::Phase
		oscillator4.setParameterT(5, 1.);   // core::oscillator::Gain
		
		file_player.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                   // file_player::FreqRatio is automated
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // sampleandhold::Counter is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader1::Value is automated
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // branch2::Index is automated
		
		;                          // svf1::Frequency is automated
		;                          // svf1::Q is automated
		svf1.setParameterT(2, 0.); // filters::svf::Gain
		svf1.setParameterT(3, 0.); // filters::svf::Smoothing
		svf1.setParameterT(4, 0.); // filters::svf::Mode
		svf1.setParameterT(5, 1.); // filters::svf::Enabled
		
		;                          // svf6::Frequency is automated
		;                          // svf6::Q is automated
		svf6.setParameterT(2, 0.); // filters::svf::Gain
		svf6.setParameterT(3, 0.); // filters::svf::Smoothing
		svf6.setParameterT(4, 1.); // filters::svf::Mode
		svf6.setParameterT(5, 1.); // filters::svf::Enabled
		
		;                          // svf5::Frequency is automated
		;                          // svf5::Q is automated
		svf5.setParameterT(2, 0.); // filters::svf::Gain
		svf5.setParameterT(3, 0.); // filters::svf::Smoothing
		svf5.setParameterT(4, 2.); // filters::svf::Mode
		svf5.setParameterT(5, 1.); // filters::svf::Enabled
		
		;                               // allpass::Frequency is automated
		;                               // allpass::Q is automated
		allpass.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		gain6.setParameterT(0, -9.8); // core::gain::Gain
		gain6.setParameterT(1, 20.);  // core::gain::Smoothing
		gain6.setParameterT(2, 0.);   // core::gain::ResetValue
		
<<<<<<< HEAD
		;                                  // input_toggle::Input is automated
		input_toggle.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                  // input_toggle::Value2 is automated
		
		;                              // gain4::Gain is automated
		gain4.setParameterT(1, 142.9); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);    // core::gain::ResetValue
=======
		;                            // gain3::Gain is automated
		gain3.setParameterT(1, 20.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.);  // core::gain::ResetValue
>>>>>>> parent of 416899d (s&h gate)
		
		gain5.setParameterT(0, -6.1);  // core::gain::Gain
		gain5.setParameterT(1, 167.6); // core::gain::Smoothing
		gain5.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.702867);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.01646);
		this->setParameterT(4, 6.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.558694);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, -0.027812);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 3.);
		this->setParameterT(12, 9.47662);
		this->setParameterT(13, 0.337426);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 1.18136);
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
		
		this->getT(0).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index); // xnode_impl::oscillator_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index); // xnode_impl::oscillator2_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index); // xnode_impl::oscillator1_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(3).setExternalData(b, index); // xnode_impl::oscillator3_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(4).setExternalData(b, index); // xnode_impl::oscillator4_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(5).setExternalData(b, index); // xnode_impl::file_player_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).                           // xnode_impl::peak_t<NV>
        getT(1).getT(2).getT(0).getT(1).getT(0).setExternalData(b, index);
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
using xnode = wrap::node<xnode_impl::instance<NV>>;
}


