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
using oscillator_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using pma_unscaled_mod = parameter::chain<ranges::Identity, 
                                          parameter::plain<file_player_t<NV>, 3>, 
                                          parameter::plain<oscillator_t<NV>, 2>>;

template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, pma_unscaled_mod<NV>>;

template <int NV>
using pma_unscaled2_t = control::pma_unscaled<NV, 
                                              parameter::plain<pma_unscaled_t<NV>, 2>>;

template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, 
                                              parameter::plain<pma_unscaled2_t<NV>, 2>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, pma_unscaled_t<NV>>, 
                                 pma_unscaled2_t<NV>, 
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
using sb3_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, oscillator_t<NV>>>;

template <int NV>
using sb3_t = bypass::smoothed<20, sb3_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb3_t<NV>>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0<NV>, switcher_c1<NV>>;

template <int NV>
using switcher_t = control::xfader<switcher_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container_t = container::chain<parameter::empty, 
                                        wrap::fix<2, sb1_t<NV>>, 
                                        sb3_t<NV>>;

namespace softbypass_switch4_t_parameters
{
}

template <int NV>
using softbypass_switch4_t = container::chain<parameter::plain<harmnode_impl::switcher_t<NV>, 0>, 
                                              wrap::fix<2, switcher_t<NV>>, 
                                              sb_container_t<NV>>;

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

using converter_t = control::converter<parameter::plain<core::fm, 0>, 
                                       conversion_logic::ms2freq>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<converter_t, 0>, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;
using stereo_cable = cable::block<2>;

using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::fm>, 
                                   core::mono2stereo>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, fx::sampleandhold<NV>>, 
                                   chain11_t>;

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
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<pma_t<NV>, 0>, 
                                  parameter::plain<pma_unscaled2_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
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
                                  converter_t, 
                                  routing::receive<stereo_cable>, 
                                  branch_t<NV>, 
                                  split2_t<NV>, 
                                  routing::send<stereo_cable>, 
                                  core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain2_t<NV>>, 
                                  chain3_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader_t<NV>>, 
                                  split1_t<NV>>;

template <int NV> using xfader1_c0 = xfader_c0<NV>;

template <int NV> using xfader1_c1 = xfader_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV> using chain5_t = chain2_t<NV>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, pma_t<NV>>, 
                                  filters::svf<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain5_t<NV>>, 
                                  chain6_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader1_t<NV>>, 
                                  split3_t<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain1_t<NV>>, 
                                  chain4_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, split_t<NV>>, 
                                 minmax_t<NV>, 
                                 softbypass_switch4_t<NV>, 
                                 chain9_t<NV>>;

namespace harmnode_t_parameters
{
// Parameter list for harmnode_impl::harmnode_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(FmMulti_InputRange, 
                             1., 
                             12., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(FmMulti_0Range, 
                             0., 
                             12., 
                             1.);

using FmMulti_0 = parameter::from0To1<core::fm, 
                                      2, 
                                      FmMulti_0Range>;

using FmMulti = parameter::chain<FmMulti_InputRange, FmMulti_0>;

DECLARE_PARAMETER_RANGE_STEP(ShRate_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using ShRate_0 = parameter::from0To1<harmnode_impl::tempo_sync_t<NV>, 
                                     0, 
                                     ShRate_0Range>;

DECLARE_PARAMETER_RANGE_STEP(ShRate_1Range, 
                             1., 
                             64., 
                             0.1);

template <int NV>
using ShRate_1 = parameter::from0To1<harmnode_impl::tempo_sync_t<NV>, 
                                     3, 
                                     ShRate_1Range>;

template <int NV>
using ShRate = parameter::chain<ranges::Identity, 
                                ShRate_0<NV>, 
                                ShRate_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(shDivRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using shDiv = parameter::from0To1<harmnode_impl::tempo_sync_t<NV>, 
                                  1, 
                                  shDivRange>;

DECLARE_PARAMETER_RANGE_SKEW(ResRange, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using Res = parameter::from0To1<filters::svf<NV>, 
                                1, 
                                ResRange>;

DECLARE_PARAMETER_RANGE(CutSHRange, 
                        -1., 
                        1.);

template <int NV>
using CutSH = parameter::from0To1<harmnode_impl::pma_t<NV>, 
                                  1, 
                                  CutSHRange>;

DECLARE_PARAMETER_RANGE_SKEW(FilterTypeRange, 
                             0., 
                             3., 
                             0.878126);

template <int NV>
using FilterType = parameter::from0To1<filters::svf<NV>, 
                                       4, 
                                       FilterTypeRange>;

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
using SH = parameter::plain<harmnode_impl::pma_unscaled2_t<NV>, 
                            1>;
using FmMod = parameter::plain<core::fm, 1>;
template <int NV>
using SHMx = parameter::plain<harmnode_impl::xfader_t<NV>, 
                              0>;
template <int NV>
using shSync = parameter::plain<harmnode_impl::tempo_sync_t<NV>, 
                                2>;
template <int NV>
using Cut = parameter::plain<harmnode_impl::pma_t<NV>, 
                             2>;
template <int NV>
using FMix = parameter::plain<harmnode_impl::xfader1_t<NV>, 
                              0>;
template <int NV>
using shFm = parameter::plain<harmnode_impl::branch_t<NV>, 
                              0>;
template <int NV>
using harmnode_t_plist = parameter::list<pitch<NV>, 
                                         mode<NV>, 
                                         OscWave<NV>, 
                                         harm<NV>, 
                                         min<NV>, 
                                         max<NV>, 
                                         step<NV>, 
                                         wheel<NV>, 
                                         SH<NV>, 
                                         FmMod, 
                                         FmMulti, 
                                         ShRate<NV>, 
                                         SHMx<NV>, 
                                         shDiv<NV>, 
                                         shSync<NV>, 
                                         Cut<NV>, 
                                         Res<NV>, 
                                         CutSH<NV>, 
                                         FilterType<NV>, 
                                         FMix<NV>, 
                                         shFm<NV>>;
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
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(harmnode);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(324)
		{
			0x005B, 0x0000, 0x7000, 0x7469, 0x6863, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6F6D, 0x6564, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 
            0x0000, 0x734F, 0x5763, 0x7661, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x4080, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 
            0x0000, 0x6800, 0x7261, 0x006D, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 
            0x6D00, 0x6E69, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0005, 0x0000, 0x616D, 
            0x0078, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x4180, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x065B, 0x0000, 0x7300, 0x6574, 0x0070, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x075B, 0x0000, 0x7700, 0x6568, 0x6C65, 0x0000, 
            0x0000, 0x0000, 0x0000, 0xAF40, 0x7EDE, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0008, 0x0000, 0x4853, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x6F3F, 0x0312, 0x00B9, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0009, 0x0000, 0x6D46, 0x6F4D, 0x0064, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xCA8F, 0x3ECD, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 
            0x0000, 0x4600, 0x4D6D, 0x6C75, 0x6974, 0x0000, 0x8000, 0x003F, 
            0x4000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x000B, 0x0000, 0x6853, 0x6152, 0x6574, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x000C, 0x0000, 0x4853, 0x784D, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000D, 
            0x0000, 0x6873, 0x6944, 0x0076, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0E5B, 0x0000, 
            0x7300, 0x5368, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0F5B, 0x0000, 
            0x4300, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0010, 0x0000, 0x6552, 
            0x0073, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x115B, 0x0000, 0x4300, 0x7475, 0x4853, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0012, 0x0000, 0x6946, 0x746C, 0x7265, 
            0x7954, 0x6570, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0013, 0x0000, 0x4D46, 
            0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x313F, 0x8708, 0x003E, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0014, 0x0000, 0x6873, 0x6D46, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain = this->getT(0);                                                         // harmnode_impl::chain_t<NV>
		auto& split = this->getT(0).getT(0);                                                 // harmnode_impl::split_t<NV>
		auto& pma_unscaled = this->getT(0).getT(0).getT(0);                                  // harmnode_impl::pma_unscaled_t<NV>
		auto& pma_unscaled2 = this->getT(0).getT(0).getT(1);                                 // harmnode_impl::pma_unscaled2_t<NV>
		auto& pma_unscaled1 = this->getT(0).getT(0).getT(2);                                 // harmnode_impl::pma_unscaled1_t<NV>
		auto& minmax = this->getT(0).getT(1);                                                // harmnode_impl::minmax_t<NV>
		auto& softbypass_switch4 = this->getT(0).getT(2);                                    // harmnode_impl::softbypass_switch4_t<NV>
		auto& switcher = this->getT(0).getT(2).getT(0);                                      // harmnode_impl::switcher_t<NV>
		auto& sb_container = this->getT(0).getT(2).getT(1);                                  // harmnode_impl::sb_container_t<NV>
		auto& sb1 = this->getT(0).getT(2).getT(1).getT(0);                                   // harmnode_impl::sb1_t<NV>
		auto& file_player = this->getT(0).getT(2).getT(1).getT(0).getT(0);                   // harmnode_impl::file_player_t<NV>
		auto& sb3 = this->getT(0).getT(2).getT(1).getT(1);                                   // harmnode_impl::sb3_t<NV>
		auto& oscillator = this->getT(0).getT(2).getT(1).getT(1).getT(0);                    // harmnode_impl::oscillator_t<NV>
		auto& chain9 = this->getT(0).getT(3);                                                // harmnode_impl::chain9_t<NV>
		auto& chain1 = this->getT(0).getT(3).getT(0);                                        // harmnode_impl::chain1_t<NV>
		auto& xfader = this->getT(0).getT(3).getT(0).getT(0);                                // harmnode_impl::xfader_t<NV>
		auto& split1 = this->getT(0).getT(3).getT(0).getT(1);                                // harmnode_impl::split1_t<NV>
		auto& chain2 = this->getT(0).getT(3).getT(0).getT(1).getT(0);                        // harmnode_impl::chain2_t<NV>
		auto& gain = this->getT(0).getT(3).getT(0).getT(1).getT(0).getT(0);                  // core::gain<NV>
		auto& chain3 = this->getT(0).getT(3).getT(0).getT(1).getT(1);                        // harmnode_impl::chain3_t<NV>
		auto& tempo_sync = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(0);            // harmnode_impl::tempo_sync_t<NV>
		auto& converter = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(1);             // harmnode_impl::converter_t
		auto& receive = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(2);               // routing::receive<stereo_cable>
		auto& branch = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(3);                // harmnode_impl::branch_t<NV>
		auto& sampleandhold = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(3).getT(0); // fx::sampleandhold<NV>
		auto& chain11 = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(3).getT(1);       // harmnode_impl::chain11_t
		auto& fm = this->getT(0).getT(3).getT(0).getT(1).                                    // core::fm
                   getT(1).getT(3).getT(1).getT(0);
		auto& mono2stereo2 = this->getT(0).getT(3).getT(0).getT(1).                   // core::mono2stereo
                             getT(1).getT(3).getT(1).getT(1);
		auto& split2 = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(4);         // harmnode_impl::split2_t<NV>
		auto& chain7 = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(4).getT(0); // harmnode_impl::chain7_t
		auto& chain8 = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(4).getT(1); // harmnode_impl::chain8_t<NV>
		auto& peak = this->getT(0).getT(3).getT(0).getT(1).                           // harmnode_impl::peak_t<NV>
                     getT(1).getT(4).getT(1).getT(0);
		auto& clear = this->getT(0).getT(3).getT(0).getT(1).                 // math::clear<NV>
                      getT(1).getT(4).getT(1).getT(1);
		auto& send = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(5);  // routing::send<stereo_cable>
		auto& gain1 = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(6); // core::gain<NV>
		auto& chain4 = this->getT(0).getT(3).getT(1);                        // harmnode_impl::chain4_t<NV>
		auto& xfader1 = this->getT(0).getT(3).getT(1).getT(0);               // harmnode_impl::xfader1_t<NV>
		auto& split3 = this->getT(0).getT(3).getT(1).getT(1);                // harmnode_impl::split3_t<NV>
		auto& chain5 = this->getT(0).getT(3).getT(1).getT(1).getT(0);        // harmnode_impl::chain5_t<NV>
		auto& gain2 = this->getT(0).getT(3).getT(1).getT(1).getT(0).getT(0); // core::gain<NV>
		auto& chain6 = this->getT(0).getT(3).getT(1).getT(1).getT(1);        // harmnode_impl::chain6_t<NV>
		auto& pma = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(0);   // harmnode_impl::pma_t<NV>
		auto& svf = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(1);   // filters::svf<NV>
		auto& gain3 = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(2); // core::gain<NV>
		
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
		
		this->getParameterT(8).connectT(0, pma_unscaled2); // SH -> pma_unscaled2::Multiply
		
		this->getParameterT(9).connectT(0, fm); // FmMod -> fm::Modulator
		
		this->getParameterT(10).connectT(0, fm); // FmMulti -> fm::FreqMultiplier
		
		auto& ShRate_p = this->getParameterT(11);
		ShRate_p.connectT(0, tempo_sync); // ShRate -> tempo_sync::Tempo
		ShRate_p.connectT(1, tempo_sync); // ShRate -> tempo_sync::UnsyncedTime
		
		this->getParameterT(12).connectT(0, xfader); // SHMx -> xfader::Value
		
		this->getParameterT(13).connectT(0, tempo_sync); // shDiv -> tempo_sync::Multiplier
		
		this->getParameterT(14).connectT(0, tempo_sync); // shSync -> tempo_sync::Enabled
		
		this->getParameterT(15).connectT(0, pma); // Cut -> pma::Add
		
		this->getParameterT(16).connectT(0, svf); // Res -> svf::Q
		
		this->getParameterT(17).connectT(0, pma); // CutSH -> pma::Multiply
		
		this->getParameterT(18).connectT(0, svf); // FilterType -> svf::Mode
		
		this->getParameterT(19).connectT(0, xfader1); // FMix -> xfader1::Value
		
		this->getParameterT(20).connectT(0, branch); // shFm -> branch::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma_unscaled.getWrappedObject().getParameter().connectT(0, file_player);    // pma_unscaled -> file_player::FreqRatio
		pma_unscaled.getWrappedObject().getParameter().connectT(1, oscillator);     // pma_unscaled -> oscillator::FreqRatio
		pma_unscaled2.getWrappedObject().getParameter().connectT(0, pma_unscaled);  // pma_unscaled2 -> pma_unscaled::Add
		pma_unscaled1.getWrappedObject().getParameter().connectT(0, pma_unscaled2); // pma_unscaled1 -> pma_unscaled2::Add
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled1);        // minmax -> pma_unscaled1::Add
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1); // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb3); // switcher -> sb3::Bypassed
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                 // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);                // xfader -> gain1::Gain
		converter.getWrappedObject().getParameter().connectT(0, fm); // converter -> fm::Frequency
		tempo_sync.getParameter().connectT(0, converter);            // tempo_sync -> converter::Value
		tempo_sync.getParameter().connectT(1, sampleandhold);        // tempo_sync -> sampleandhold::Counter
		pma.getWrappedObject().getParameter().connectT(0, svf);      // pma -> svf::Frequency
		peak.getParameter().connectT(0, pma);                        // peak -> pma::Value
		peak.getParameter().connectT(1, pma_unscaled2);              // peak -> pma_unscaled2::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain2); // xfader1 -> gain2::Gain
		xfader1_p.getParameterT(1).connectT(0, gain3); // xfader1 -> gain3::Gain
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values --------------------------------------------------------------------------
		
		;                                  // pma_unscaled::Value is automated
		pma_unscaled.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                  // pma_unscaled::Add is automated
		
		; // pma_unscaled2::Value is automated
		; // pma_unscaled2::Multiply is automated
		; // pma_unscaled2::Add is automated
		
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
		
		;                                  // oscillator::Mode is automated
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                  // oscillator::FreqRatio is automated
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		; // xfader::Value is automated
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 9.1);   // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		; // converter::Value is automated
		
		receive.setParameterT(0, 0.); // routing::receive::Feedback
		
		; // branch::Index is automated
		
		; // sampleandhold::Counter is automated
		
		;                        // fm::Frequency is automated
		;                        // fm::Modulator is automated
		;                        // fm::FreqMultiplier is automated
		fm.setParameterT(3, 1.); // core::fm::Gate
		
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
		
		this->setParameterT(0, 2.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 16.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.995585);
		this->setParameterT(8, -0.000125);
		this->setParameterT(9, 0.401936);
		this->setParameterT(10, 4.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 0.263734);
		this->setParameterT(20, 0.);
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
		
		this->getT(0).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index); // harmnode_impl::file_player_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index); // harmnode_impl::oscillator_t<NV>
		this->getT(0).getT(3).getT(0).getT(1).                                   // harmnode_impl::peak_t<NV>
        getT(1).getT(4).getT(1).getT(0).setExternalData(b, index);
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


