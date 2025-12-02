#pragma once

#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
#include "xnode.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace ArrangeNew_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_mod_t_index = runtime_target::indexers::fix_hash<1>;
using global_mod_t_config = modulation::config::dynamic;
template <int NV>
using global_mod_t = wrap::no_data<core::global_mod<NV, global_mod_t_index, global_mod_t_config>>;

template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<math::add<NV>, 0>>;
template <int NV>
using midi1_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi1_t<NV>>, 
                                  pma1_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma2_t = pma1_t<NV>;
template <int NV>
using midi2_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi2_t<NV>>, 
                                  pma2_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma3_t = pma1_t<NV>;
template <int NV>
using midi3_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                          control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi3_t<NV>>, 
                                  pma3_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma4_t = pma1_t<NV>;
template <int NV>
using midi_cc_t = control::midi_cc<parameter::plain<pma4_t<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc_t<NV>>, 
                                  pma4_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma5_t = pma1_t<NV>;
template <int NV>
using midi_cc1_t = control::midi_cc<parameter::plain<pma5_t<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc1_t<NV>>, 
                                  pma5_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma6_t = pma1_t<NV>;
template <int NV>
using midi_cc2_t = control::midi_cc<parameter::plain<pma6_t<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc2_t<NV>>, 
                                  pma6_t<NV>, 
                                  math::add<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain3_t<NV>>, 
                                    chain4_t<NV>, 
                                    chain5_t<NV>, 
                                    chain6_t<NV>, 
                                    chain7_t<NV>, 
                                    chain8_t<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, global_mod_t<NV>>, 
                                  branch1_t<NV>>;

struct xnode1_t_matrix
{
	static const int NumTables = 0;
	static const int NumSliderPacks = 0;
	static const int NumAudioFiles = 3;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 3;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][3] =
	{
		{ -1, -1, -1 }, // 
		{ -1, -1, -1 }, // 
		{ 0, 1, 1000 }  //  | 0->0 | 1->1 | 2->e[0]
	};
	
private:
	
public:
	
const span<dyn<float> };
};

template <int NV>
using xnode1_t = wrap::data<project::xnode<NV>, 
                            data::matrix<xnode1_t_matrix>>;
template <int NV>
using clone_pack_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<xnode1_t<NV>, 0>>>, 
                                data::external::sliderpack<0>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<clone_pack_t<NV>, 1>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, split1_t<NV>>, 
                                  peak_t<NV>, 
                                  math::clear<NV>>;
using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<0>>;

template <int NV>
using clone_forward_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 1>>>;

template <int NV>
using clone_forward2_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 2>>>;

template <int NV>
using clone_forward1_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 3>>>;

template <int NV>
using clone_forward6_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 4>>>;

template <int NV>
using clone_forward7_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 18>>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, clone_pack_t<NV>>, 
                                  clone_forward_t<NV>, 
                                  clone_forward2_t<NV>, 
                                  clone_forward1_t<NV>, 
                                  clone_forward6_t<NV>, 
                                  clone_forward7_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, chain9_t<NV>>, 
                                  pack_resizer_t, 
                                  split2_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, chain1_t<NV>>>;
using global_mod1_t_index = global_mod_t_index;
using global_mod1_t_config = global_mod_t_config;
template <int NV>
using global_mod1_t = wrap::no_data<core::global_mod<NV, global_mod1_t_index, global_mod1_t_config>>;

template <int NV> using pma7_t = pma1_t<NV>;
template <int NV>
using midi5_t = wrap::mod<parameter::plain<pma7_t<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi5_t<NV>>, 
                                   pma7_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma8_t = pma1_t<NV>;
template <int NV>
using midi6_t = wrap::mod<parameter::plain<pma8_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi6_t<NV>>, 
                                   pma8_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma9_t = pma1_t<NV>;
template <int NV>
using midi7_t = wrap::mod<parameter::plain<pma9_t<NV>, 0>, 
                          control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi7_t<NV>>, 
                                   pma9_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma10_t = pma1_t<NV>;
template <int NV>
using midi_cc3_t = control::midi_cc<parameter::plain<pma10_t<NV>, 0>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc3_t<NV>>, 
                                   pma10_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma11_t = pma1_t<NV>;
template <int NV>
using midi_cc4_t = control::midi_cc<parameter::plain<pma11_t<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc4_t<NV>>, 
                                   pma11_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma12_t = pma1_t<NV>;
template <int NV>
using midi_cc5_t = control::midi_cc<parameter::plain<pma12_t<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc5_t<NV>>, 
                                   pma12_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain13_t<NV>>, 
                                    chain14_t<NV>, 
                                    chain15_t<NV>, 
                                    chain16_t<NV>, 
                                    chain17_t<NV>, 
                                    chain18_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, global_mod1_t<NV>>, 
                                  branch2_t<NV>>;

DECLARE_PARAMETER_RANGE(clone_cable_modRange, 
                        0., 
                        2.);

template <int NV>
using clone_cable_mod = parameter::from0To1<xnode1_t<NV>, 
                                            15, 
                                            clone_cable_modRange>;

template <int NV>
using clone_cable_t = control::clone_cable<parameter::cloned<clone_cable_mod<NV>>, 
                                           duplilogic::spread>;
DECLARE_PARAMETER_RANGE(peak1_modRange, 
                        -1., 
                        1.);

template <int NV>
using peak1_mod = parameter::from0To1<clone_cable_t<NV>, 
                                      1, 
                                      peak1_modRange>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split3_t<NV>>, 
                                   peak1_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain12_t<NV>>, 
                                   clone_cable_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain11_t<NV>>>;
using global_mod3_t_index = global_mod_t_index;
using global_mod3_t_config = global_mod_t_config;
template <int NV>
using global_mod3_t = wrap::no_data<core::global_mod<NV, global_mod3_t_index, global_mod3_t_config>>;

template <int NV> using pma19_t = pma1_t<NV>;
template <int NV>
using midi11_t = wrap::mod<parameter::plain<pma19_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi11_t<NV>>, 
                                   pma19_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma20_t = pma1_t<NV>;
template <int NV>
using midi12_t = wrap::mod<parameter::plain<pma20_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi12_t<NV>>, 
                                   pma20_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma21_t = pma1_t<NV>;
template <int NV>
using midi13_t = wrap::mod<parameter::plain<pma21_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi13_t<NV>>, 
                                   pma21_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma22_t = pma1_t<NV>;
template <int NV>
using midi_cc9_t = control::midi_cc<parameter::plain<pma22_t<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc9_t<NV>>, 
                                   pma22_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma23_t = pma1_t<NV>;
template <int NV>
using midi_cc10_t = control::midi_cc<parameter::plain<pma23_t<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc10_t<NV>>, 
                                   pma23_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma24_t = pma1_t<NV>;
template <int NV>
using midi_cc11_t = control::midi_cc<parameter::plain<pma24_t<NV>, 0>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc11_t<NV>>, 
                                   pma24_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain30_t<NV>>, 
                                    chain31_t<NV>, 
                                    chain32_t<NV>, 
                                    chain33_t<NV>, 
                                    chain34_t<NV>, 
                                    chain35_t<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, global_mod3_t<NV>>, 
                                  branch4_t<NV>>;

template <int NV>
using clone_cable2_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 17>>, 
                                            duplilogic::fixed>;
template <int NV>
using peak3_t = wrap::mod<parameter::plain<clone_cable2_t<NV>, 1>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split6_t<NV>>, 
                                   peak3_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain29_t<NV>>, 
                                   clone_cable2_t<NV>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain28_t<NV>>>;
using global_mod4_t_index = global_mod_t_index;
using global_mod4_t_config = global_mod_t_config;
template <int NV>
using global_mod4_t = wrap::no_data<core::global_mod<NV, global_mod4_t_index, global_mod4_t_config>>;

template <int NV> using pma25_t = pma1_t<NV>;
template <int NV>
using midi14_t = wrap::mod<parameter::plain<pma25_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi14_t<NV>>, 
                                   pma25_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma26_t = pma1_t<NV>;
template <int NV>
using midi15_t = wrap::mod<parameter::plain<pma26_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi15_t<NV>>, 
                                   pma26_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma27_t = pma1_t<NV>;
template <int NV>
using midi16_t = wrap::mod<parameter::plain<pma27_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi16_t<NV>>, 
                                   pma27_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma28_t = pma1_t<NV>;
template <int NV>
using midi_cc12_t = control::midi_cc<parameter::plain<pma28_t<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc12_t<NV>>, 
                                   pma28_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma29_t = pma1_t<NV>;
template <int NV>
using midi_cc13_t = control::midi_cc<parameter::plain<pma29_t<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc13_t<NV>>, 
                                   pma29_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma30_t = pma1_t<NV>;
template <int NV>
using midi_cc14_t = control::midi_cc<parameter::plain<pma30_t<NV>, 0>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc14_t<NV>>, 
                                   pma30_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain39_t<NV>>, 
                                    chain40_t<NV>, 
                                    chain41_t<NV>, 
                                    chain42_t<NV>, 
                                    chain43_t<NV>, 
                                    chain44_t<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, global_mod4_t<NV>>, 
                                  branch5_t<NV>>;

template <int NV>
using clone_cable3_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 20>>, 
                                            duplilogic::fixed>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<clone_cable3_t<NV>, 1>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split7_t<NV>>, 
                                   peak4_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain38_t<NV>>, 
                                   clone_cable3_t<NV>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain37_t<NV>>>;
using global_mod5_t_index = global_mod_t_index;
using global_mod5_t_config = global_mod_t_config;
template <int NV>
using global_mod5_t = wrap::no_data<core::global_mod<NV, global_mod5_t_index, global_mod5_t_config>>;

template <int NV> using pma31_t = pma1_t<NV>;
template <int NV>
using midi17_t = wrap::mod<parameter::plain<pma31_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi17_t<NV>>, 
                                   pma31_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma32_t = pma1_t<NV>;
template <int NV>
using midi18_t = wrap::mod<parameter::plain<pma32_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi18_t<NV>>, 
                                   pma32_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma33_t = pma1_t<NV>;
template <int NV>
using midi19_t = wrap::mod<parameter::plain<pma33_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi19_t<NV>>, 
                                   pma33_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma34_t = pma1_t<NV>;
template <int NV>
using midi_cc15_t = control::midi_cc<parameter::plain<pma34_t<NV>, 0>>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc15_t<NV>>, 
                                   pma34_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma35_t = pma1_t<NV>;
template <int NV>
using midi_cc16_t = control::midi_cc<parameter::plain<pma35_t<NV>, 0>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc16_t<NV>>, 
                                   pma35_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma36_t = pma1_t<NV>;
template <int NV>
using midi_cc17_t = control::midi_cc<parameter::plain<pma36_t<NV>, 0>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc17_t<NV>>, 
                                   pma36_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain48_t<NV>>, 
                                    chain49_t<NV>, 
                                    chain50_t<NV>, 
                                    chain51_t<NV>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, global_mod5_t<NV>>, 
                                  branch6_t<NV>>;

template <int NV>
using clone_cable4_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 21>>, 
                                            duplilogic::fixed>;
template <int NV>
using peak5_t = wrap::mod<parameter::plain<clone_cable4_t<NV>, 1>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split8_t<NV>>, 
                                   peak5_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain47_t<NV>>, 
                                   clone_cable4_t<NV>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain46_t<NV>>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain_t<NV>>, 
                                 chain10_t<NV>, 
                                 chain27_t<NV>, 
                                 chain36_t<NV>, 
                                 chain45_t<NV>>;
using global_mod6_t_index = global_mod_t_index;
using global_mod6_t_config = global_mod_t_config;
template <int NV>
using global_mod6_t = wrap::no_data<core::global_mod<NV, global_mod6_t_index, global_mod6_t_config>>;

template <int NV> using pma37_t = pma1_t<NV>;
template <int NV>
using midi20_t = wrap::mod<parameter::plain<pma37_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi20_t<NV>>, 
                                   pma37_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma38_t = pma1_t<NV>;
template <int NV>
using midi21_t = wrap::mod<parameter::plain<pma38_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi21_t<NV>>, 
                                   pma38_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma39_t = pma1_t<NV>;
template <int NV>
using midi22_t = wrap::mod<parameter::plain<pma39_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi22_t<NV>>, 
                                   pma39_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma40_t = pma1_t<NV>;
template <int NV>
using midi_cc18_t = control::midi_cc<parameter::plain<pma40_t<NV>, 0>>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc18_t<NV>>, 
                                   pma40_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma41_t = pma1_t<NV>;
template <int NV>
using midi_cc19_t = control::midi_cc<parameter::plain<pma41_t<NV>, 0>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc19_t<NV>>, 
                                   pma41_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma42_t = pma1_t<NV>;
template <int NV>
using midi_cc20_t = control::midi_cc<parameter::plain<pma42_t<NV>, 0>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc20_t<NV>>, 
                                   pma42_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain57_t<NV>>, 
                                    chain58_t<NV>, 
                                    chain59_t<NV>, 
                                    chain60_t<NV>, 
                                    chain61_t<NV>, 
                                    chain62_t<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, global_mod6_t<NV>>, 
                                   branch7_t<NV>>;

template <int NV>
using clone_pack2_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<xnode1_t<NV>, 6>>>, 
                                 data::external::sliderpack<1>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<clone_pack2_t<NV>, 1>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split10_t<NV>>, 
                                   peak6_t<NV>, 
                                   math::clear<NV>>;
using pack_resizer2_t = wrap::data<control::pack_resizer, 
                                   data::external::sliderpack<1>>;

template <int NV>
using clone_forward10_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 5>>>;

template <int NV>
using clone_forward9_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 7>>>;

template <int NV>
using clone_forward11_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 8>>>;

template <int NV>
using clone_forward15_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 19>>>;

template <int NV>
using clone_forward12_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 9>>>;

template <int NV>
using clone_forward13_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 14>>>;

template <int NV>
using clone_forward14_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 16>>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_pack2_t<NV>>, 
                                   clone_forward10_t<NV>, 
                                   clone_forward9_t<NV>, 
                                   clone_forward11_t<NV>, 
                                   clone_forward15_t<NV>, 
                                   clone_forward12_t<NV>, 
                                   clone_forward13_t<NV>, 
                                   clone_forward14_t<NV>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain56_t<NV>>, 
                                   pack_resizer2_t, 
                                   split11_t<NV>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain55_t<NV>>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain54_t<NV>>>;
using global_mod11_t_index = global_mod_t_index;
using global_mod11_t_config = global_mod_t_config;
template <int NV>
using global_mod11_t = wrap::no_data<core::global_mod<NV, global_mod11_t_index, global_mod11_t_config>>;

template <int NV> using pma67_t = pma1_t<NV>;
template <int NV>
using midi35_t = wrap::mod<parameter::plain<pma67_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain102_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi35_t<NV>>, 
                                    pma67_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma68_t = pma1_t<NV>;
template <int NV>
using midi36_t = wrap::mod<parameter::plain<pma68_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain103_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi36_t<NV>>, 
                                    pma68_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma69_t = pma1_t<NV>;
template <int NV>
using midi37_t = wrap::mod<parameter::plain<pma69_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain104_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi37_t<NV>>, 
                                    pma69_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma70_t = pma1_t<NV>;
template <int NV>
using midi_cc33_t = control::midi_cc<parameter::plain<pma70_t<NV>, 0>>;

template <int NV>
using chain105_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc33_t<NV>>, 
                                    pma70_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma71_t = pma1_t<NV>;
template <int NV>
using midi_cc34_t = control::midi_cc<parameter::plain<pma71_t<NV>, 0>>;

template <int NV>
using chain106_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc34_t<NV>>, 
                                    pma71_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma72_t = pma1_t<NV>;
template <int NV>
using midi_cc35_t = control::midi_cc<parameter::plain<pma72_t<NV>, 0>>;

template <int NV>
using chain107_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc35_t<NV>>, 
                                    pma72_t<NV>, 
                                    math::add<NV>>;
template <int NV>
using branch12_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain102_t<NV>>, 
                                     chain103_t<NV>, 
                                     chain104_t<NV>, 
                                     chain105_t<NV>, 
                                     chain106_t<NV>, 
                                     chain107_t<NV>>;

template <int NV>
using split17_t = container::split<parameter::empty, 
                                   wrap::fix<1, global_mod11_t<NV>>, 
                                   branch12_t<NV>>;

DECLARE_PARAMETER_RANGE(clone_pack3_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using clone_pack3_mod = parameter::from0To1<xnode1_t<NV>, 
                                            13, 
                                            clone_pack3_modRange>;

template <int NV>
using clone_pack3_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack3_mod<NV>>>, 
                                 data::external::sliderpack<2>>;
template <int NV>
using peak11_t = wrap::mod<parameter::plain<clone_pack3_t<NV>, 1>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain101_t = container::chain<parameter::empty, 
                                    wrap::fix<1, split17_t<NV>>, 
                                    peak11_t<NV>, 
                                    math::clear<NV>>;
using pack_resizer3_t = wrap::data<control::pack_resizer, 
                                   data::external::sliderpack<2>>;

DECLARE_PARAMETER_RANGE_STEP(clone_cable14_modRange, 
                             0., 
                             3., 
                             1.);

template <int NV>
using clone_cable14_mod = parameter::from0To1<xnode1_t<NV>, 
                                              11, 
                                              clone_cable14_modRange>;

template <int NV>
using clone_cable14_t = control::clone_cable<parameter::cloned<clone_cable14_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using clone_forward21_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 22>>>;

template <int NV>
using clone_cable13_mod = parameter::from0To1<jdsp::jpanner<NV>, 
                                              0, 
                                              peak1_modRange>;

template <int NV>
using clone_cable13_t = control::clone_cable<parameter::cloned<clone_cable13_mod<NV>>, 
                                             duplilogic::spread>;

template <int NV>
using split18_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_pack3_t<NV>>, 
                                   clone_cable14_t<NV>, 
                                   clone_forward21_t<NV>, 
                                   clone_cable13_t<NV>>;

template <int NV>
using chain100_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain101_t<NV>>, 
                                    pack_resizer3_t, 
                                    split18_t<NV>>;

template <int NV>
using chain99_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain100_t<NV>>>;
using global_mod13_t_index = global_mod_t_index;
using global_mod13_t_config = global_mod_t_config;
template <int NV>
using global_mod13_t = wrap::no_data<core::global_mod<NV, global_mod13_t_index, global_mod13_t_config>>;

template <int NV> using pma79_t = pma1_t<NV>;
template <int NV>
using midi41_t = wrap::mod<parameter::plain<pma79_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain120_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi41_t<NV>>, 
                                    pma79_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma80_t = pma1_t<NV>;
template <int NV>
using midi42_t = wrap::mod<parameter::plain<pma80_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain121_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi42_t<NV>>, 
                                    pma80_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma81_t = pma1_t<NV>;
template <int NV>
using midi43_t = wrap::mod<parameter::plain<pma81_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain122_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi43_t<NV>>, 
                                    pma81_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma82_t = pma1_t<NV>;
template <int NV>
using midi_cc39_t = control::midi_cc<parameter::plain<pma82_t<NV>, 0>>;

template <int NV>
using chain123_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc39_t<NV>>, 
                                    pma82_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma83_t = pma1_t<NV>;
template <int NV>
using midi_cc40_t = control::midi_cc<parameter::plain<pma83_t<NV>, 0>>;

template <int NV>
using chain124_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc40_t<NV>>, 
                                    pma83_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma84_t = pma1_t<NV>;
template <int NV>
using midi_cc41_t = control::midi_cc<parameter::plain<pma84_t<NV>, 0>>;

template <int NV>
using chain125_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc41_t<NV>>, 
                                    pma84_t<NV>, 
                                    math::add<NV>>;
template <int NV>
using branch14_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain120_t<NV>>, 
                                     chain121_t<NV>, 
                                     chain122_t<NV>, 
                                     chain123_t<NV>, 
                                     chain124_t<NV>, 
                                     chain125_t<NV>>;

template <int NV>
using split20_t = container::split<parameter::empty, 
                                   wrap::fix<1, global_mod13_t<NV>>, 
                                   branch14_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_cable10_modRange, 
                             0.3, 
                             1., 
                             0.264718);

template <int NV>
using clone_cable10_mod = parameter::from0To1<xnode1_t<NV>, 
                                              12, 
                                              clone_cable10_modRange>;

template <int NV>
using clone_cable10_t = control::clone_cable<parameter::cloned<clone_cable10_mod<NV>>, 
                                             duplilogic::fixed>;
template <int NV>
using peak13_t = wrap::mod<parameter::plain<clone_cable10_t<NV>, 1>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain119_t = container::chain<parameter::empty, 
                                    wrap::fix<1, split20_t<NV>>, 
                                    peak13_t<NV>, 
                                    math::clear<NV>>;

template <int NV>
using chain118_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain119_t<NV>>, 
                                    clone_cable10_t<NV>>;

template <int NV>
using chain117_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain118_t<NV>>>;
using global_mod14_t_index = global_mod_t_index;
using global_mod14_t_config = global_mod_t_config;
template <int NV>
using global_mod14_t = wrap::no_data<core::global_mod<NV, global_mod14_t_index, global_mod14_t_config>>;

template <int NV> using pma85_t = pma1_t<NV>;
template <int NV>
using midi44_t = wrap::mod<parameter::plain<pma85_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain129_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi44_t<NV>>, 
                                    pma85_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma86_t = pma1_t<NV>;
template <int NV>
using midi45_t = wrap::mod<parameter::plain<pma86_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain130_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi45_t<NV>>, 
                                    pma86_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma87_t = pma1_t<NV>;
template <int NV>
using midi46_t = wrap::mod<parameter::plain<pma87_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain131_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi46_t<NV>>, 
                                    pma87_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma88_t = pma1_t<NV>;
template <int NV>
using midi_cc42_t = control::midi_cc<parameter::plain<pma88_t<NV>, 0>>;

template <int NV>
using chain132_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc42_t<NV>>, 
                                    pma88_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma89_t = pma1_t<NV>;
template <int NV>
using midi_cc43_t = control::midi_cc<parameter::plain<pma89_t<NV>, 0>>;

template <int NV>
using chain133_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc43_t<NV>>, 
                                    pma89_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma90_t = pma1_t<NV>;
template <int NV>
using midi_cc44_t = control::midi_cc<parameter::plain<pma90_t<NV>, 0>>;

template <int NV>
using chain134_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc44_t<NV>>, 
                                    pma90_t<NV>, 
                                    math::add<NV>>;
template <int NV>
using branch15_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain129_t<NV>>, 
                                     chain130_t<NV>, 
                                     chain131_t<NV>, 
                                     chain132_t<NV>, 
                                     chain133_t<NV>, 
                                     chain134_t<NV>>;

template <int NV>
using split21_t = container::split<parameter::empty, 
                                   wrap::fix<1, global_mod14_t<NV>>, 
                                   branch15_t<NV>>;

template <int NV>
using clone_cable11_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 10>>, 
                                             duplilogic::fixed>;
template <int NV>
using peak14_t = wrap::mod<parameter::plain<clone_cable11_t<NV>, 1>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain128_t = container::chain<parameter::empty, 
                                    wrap::fix<1, split21_t<NV>>, 
                                    peak14_t<NV>, 
                                    math::clear<NV>>;

template <int NV>
using chain127_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain128_t<NV>>, 
                                    clone_cable11_t<NV>>;

template <int NV>
using chain126_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain127_t<NV>>>;

template <int NV>
using split16_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain99_t<NV>>, 
                                   chain117_t<NV>, 
                                   chain126_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split_t<NV>>, 
                                     split9_t<NV>, 
                                     split16_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, xnode1_t<NV>>, 
                                       jdsp::jpanner<NV>>;
template <int NV>
using clone_t = wrap::clonecopy<clone_child_t<NV>, 32>;

namespace ArrangeNew_t_parameters
{
// Parameter list for ArrangeNew_impl::ArrangeNew_t ------------------------------------------------

template <int NV>
using Stages = parameter::chain<ranges::Identity, 
                                parameter::plain<ArrangeNew_impl::clone_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::pack_resizer_t, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_pack_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward2_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward1_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_cable_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward6_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward7_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_cable3_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_cable2_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_cable4_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::pack_resizer2_t, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_pack2_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward10_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward9_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward11_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward15_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward12_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward13_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward14_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::pack_resizer3_t, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_pack3_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_cable13_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_cable10_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_forward21_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_cable11_t<NV>, 0>, 
                                parameter::plain<ArrangeNew_impl::clone_cable14_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(HarmSrc_InputRange, 
                             1., 
                             17., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(HarmSrc_0Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using HarmSrc_0 = parameter::from0To1<ArrangeNew_impl::global_mod_t<NV>, 
                                      0, 
                                      HarmSrc_0Range>;

template <int NV>
using HarmSrc = parameter::chain<HarmSrc_InputRange, HarmSrc_0<NV>>;

template <int NV>
using HarmAux = parameter::chain<ranges::Identity, 
                                 parameter::plain<ArrangeNew_impl::pma1_t<NV>, 1>, 
                                 parameter::plain<ArrangeNew_impl::pma2_t<NV>, 1>, 
                                 parameter::plain<ArrangeNew_impl::pma3_t<NV>, 1>, 
                                 parameter::plain<ArrangeNew_impl::pma4_t<NV>, 1>, 
                                 parameter::plain<ArrangeNew_impl::pma5_t<NV>, 1>, 
                                 parameter::plain<ArrangeNew_impl::pma6_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(HarmAuxSrc_InputRange, 
                             1., 
                             6., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(HarmAuxSrc_0Range, 
                             0., 
                             5., 
                             1.);

template <int NV>
using HarmAuxSrc_0 = parameter::from0To1<ArrangeNew_impl::branch1_t<NV>, 
                                         0, 
                                         HarmAuxSrc_0Range>;

template <int NV>
using HarmAuxSrc = parameter::chain<HarmAuxSrc_InputRange, HarmAuxSrc_0<NV>>;

DECLARE_PARAMETER_RANGE(Detune_InputRange, 
                        -1., 
                        1.);

template <int NV>
using Detune = parameter::chain<Detune_InputRange, 
                                parameter::plain<ArrangeNew_impl::global_mod1_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(DetuneSrc_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using DetuneSrc_0 = parameter::from0To1<ArrangeNew_impl::global_mod1_t<NV>, 
                                        0, 
                                        HarmSrc_0Range>;

template <int NV>
using DetuneSrc = parameter::chain<DetuneSrc_InputRange, DetuneSrc_0<NV>>;

template <int NV>
using DetuneAux = parameter::chain<ranges::Identity, 
                                   parameter::plain<ArrangeNew_impl::pma7_t<NV>, 1>, 
                                   parameter::plain<ArrangeNew_impl::pma8_t<NV>, 1>, 
                                   parameter::plain<ArrangeNew_impl::pma9_t<NV>, 1>, 
                                   parameter::plain<ArrangeNew_impl::pma10_t<NV>, 1>, 
                                   parameter::plain<ArrangeNew_impl::pma11_t<NV>, 1>, 
                                   parameter::plain<ArrangeNew_impl::pma12_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(DetuneAuxSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using DetuneAuxSrc_0 = parameter::from0To1<ArrangeNew_impl::branch2_t<NV>, 
                                           0, 
                                           HarmAuxSrc_0Range>;

template <int NV>
using DetuneAuxSrc = parameter::chain<DetuneAuxSrc_InputRange, 
                                      DetuneAuxSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ShapeSrc_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using ShapeSrc_0 = parameter::from0To1<ArrangeNew_impl::global_mod3_t<NV>, 
                                       0, 
                                       HarmSrc_0Range>;

template <int NV>
using ShapeSrc = parameter::chain<ShapeSrc_InputRange, ShapeSrc_0<NV>>;

template <int NV>
using ShapeAux = parameter::chain<ranges::Identity, 
                                  parameter::plain<ArrangeNew_impl::pma19_t<NV>, 1>, 
                                  parameter::plain<ArrangeNew_impl::pma20_t<NV>, 1>, 
                                  parameter::plain<ArrangeNew_impl::pma21_t<NV>, 1>, 
                                  parameter::plain<ArrangeNew_impl::pma22_t<NV>, 1>, 
                                  parameter::plain<ArrangeNew_impl::pma23_t<NV>, 1>, 
                                  parameter::plain<ArrangeNew_impl::pma24_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(ShapeAuxSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using ShapeAuxSrc_0 = parameter::from0To1<ArrangeNew_impl::branch4_t<NV>, 
                                          0, 
                                          HarmAuxSrc_0Range>;

template <int NV>
using ShapeAuxSrc = parameter::chain<ShapeAuxSrc_InputRange, ShapeAuxSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(CyclePosSrc_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using CyclePosSrc_0 = parameter::from0To1<ArrangeNew_impl::global_mod4_t<NV>, 
                                          0, 
                                          HarmSrc_0Range>;

template <int NV>
using CyclePosSrc = parameter::chain<CyclePosSrc_InputRange, CyclePosSrc_0<NV>>;

template <int NV>
using CyclePosAux = parameter::chain<ranges::Identity, 
                                     parameter::plain<ArrangeNew_impl::pma25_t<NV>, 1>, 
                                     parameter::plain<ArrangeNew_impl::pma26_t<NV>, 1>, 
                                     parameter::plain<ArrangeNew_impl::pma27_t<NV>, 1>, 
                                     parameter::plain<ArrangeNew_impl::pma28_t<NV>, 1>, 
                                     parameter::plain<ArrangeNew_impl::pma29_t<NV>, 1>, 
                                     parameter::plain<ArrangeNew_impl::pma30_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(CyclePosAuxSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using CyclePosAuxSrc_0 = parameter::from0To1<ArrangeNew_impl::branch5_t<NV>, 
                                             0, 
                                             HarmAuxSrc_0Range>;

template <int NV>
using CyclePosAuxSrc = parameter::chain<CyclePosAuxSrc_InputRange, 
                                        CyclePosAuxSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(CycleShapeSrc_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using CycleShapeSrc_0 = parameter::from0To1<ArrangeNew_impl::global_mod5_t<NV>, 
                                            0, 
                                            HarmSrc_0Range>;

template <int NV>
using CycleShapeSrc = parameter::chain<CycleShapeSrc_InputRange, 
                                       CycleShapeSrc_0<NV>>;

template <int NV>
using CycleShapeAux = parameter::chain<ranges::Identity, 
                                       parameter::plain<ArrangeNew_impl::pma31_t<NV>, 1>, 
                                       parameter::plain<ArrangeNew_impl::pma32_t<NV>, 1>, 
                                       parameter::plain<ArrangeNew_impl::pma33_t<NV>, 1>, 
                                       parameter::plain<ArrangeNew_impl::pma34_t<NV>, 1>, 
                                       parameter::plain<ArrangeNew_impl::pma35_t<NV>, 1>, 
                                       parameter::plain<ArrangeNew_impl::pma36_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(CycleShapeAuxSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using CycleShapeAuxSrc_0 = parameter::from0To1<ArrangeNew_impl::branch6_t<NV>, 
                                               0, 
                                               HarmAuxSrc_0Range>;

template <int NV>
using CycleShapeAuxSrc = parameter::chain<CycleShapeAuxSrc_InputRange, 
                                          CycleShapeAuxSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FxValueSrc_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using FxValueSrc_0 = parameter::from0To1<ArrangeNew_impl::global_mod6_t<NV>, 
                                         0, 
                                         HarmSrc_0Range>;

template <int NV>
using FxValueSrc = parameter::chain<FxValueSrc_InputRange, FxValueSrc_0<NV>>;

template <int NV>
using FxValueAux = parameter::chain<ranges::Identity, 
                                    parameter::plain<ArrangeNew_impl::pma37_t<NV>, 1>, 
                                    parameter::plain<ArrangeNew_impl::pma38_t<NV>, 1>, 
                                    parameter::plain<ArrangeNew_impl::pma39_t<NV>, 1>, 
                                    parameter::plain<ArrangeNew_impl::pma40_t<NV>, 1>, 
                                    parameter::plain<ArrangeNew_impl::pma41_t<NV>, 1>, 
                                    parameter::plain<ArrangeNew_impl::pma42_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(FxValueAuxSrvc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using FxValueAuxSrvc_0 = parameter::from0To1<ArrangeNew_impl::branch7_t<NV>, 
                                             0, 
                                             HarmAuxSrc_0Range>;

template <int NV>
using FxValueAuxSrvc = parameter::chain<FxValueAuxSrvc_InputRange, 
                                        FxValueAuxSrvc_0<NV>>;

DECLARE_PARAMETER_RANGE(CutSrc_InputRange, 
                        1., 
                        17.);
template <int NV>
using CutSrc_0 = parameter::from0To1<ArrangeNew_impl::global_mod11_t<NV>, 
                                     0, 
                                     HarmSrc_0Range>;

template <int NV>
using CutSrc = parameter::chain<CutSrc_InputRange, CutSrc_0<NV>>;

template <int NV>
using CutAux = parameter::chain<ranges::Identity, 
                                parameter::plain<ArrangeNew_impl::pma67_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma68_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma69_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma70_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma71_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma72_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(CutAuxSrc_InputRange, 
                        1., 
                        6.);
template <int NV>
using CutAuxSrc_0 = parameter::from0To1<ArrangeNew_impl::branch12_t<NV>, 
                                        0, 
                                        HarmAuxSrc_0Range>;

template <int NV>
using CutAuxSrc = parameter::chain<CutAuxSrc_InputRange, CutAuxSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterMode_InputRange, 
                             1., 
                             4., 
                             1.);

template <int NV>
using FilterMode = parameter::chain<FilterMode_InputRange, 
                                    parameter::plain<ArrangeNew_impl::clone_cable14_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(ResSrc_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using ResSrc_0 = parameter::from0To1<ArrangeNew_impl::global_mod13_t<NV>, 
                                     0, 
                                     HarmSrc_0Range>;

template <int NV>
using ResSrc = parameter::chain<ResSrc_InputRange, ResSrc_0<NV>>;

template <int NV>
using ResAux = parameter::chain<ranges::Identity, 
                                parameter::plain<ArrangeNew_impl::pma79_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma80_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma81_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma82_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma83_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma84_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(ResAuxSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using ResAuxSrc_0 = parameter::from0To1<ArrangeNew_impl::branch14_t<NV>, 
                                        0, 
                                        HarmAuxSrc_0Range>;

template <int NV>
using ResAuxSrc = parameter::chain<ResAuxSrc_InputRange, ResAuxSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterMixSrc_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using FilterMixSrc_0 = parameter::from0To1<ArrangeNew_impl::global_mod14_t<NV>, 
                                           0, 
                                           HarmSrc_0Range>;

template <int NV>
using FilterMixSrc = parameter::chain<FilterMixSrc_InputRange, 
                                      FilterMixSrc_0<NV>>;

template <int NV>
using FilterMixAux = parameter::chain<ranges::Identity, 
                                      parameter::plain<ArrangeNew_impl::pma85_t<NV>, 1>, 
                                      parameter::plain<ArrangeNew_impl::pma86_t<NV>, 1>, 
                                      parameter::plain<ArrangeNew_impl::pma87_t<NV>, 1>, 
                                      parameter::plain<ArrangeNew_impl::pma88_t<NV>, 1>, 
                                      parameter::plain<ArrangeNew_impl::pma89_t<NV>, 1>, 
                                      parameter::plain<ArrangeNew_impl::pma90_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(FilterMixAuxSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using FilterMixAuxSrc_0 = parameter::from0To1<ArrangeNew_impl::branch15_t<NV>, 
                                              0, 
                                              HarmAuxSrc_0Range>;

template <int NV>
using FilterMixAuxSrc = parameter::chain<FilterMixAuxSrc_InputRange, 
                                         FilterMixAuxSrc_0<NV>>;

template <int NV>
using Harm = parameter::plain<ArrangeNew_impl::global_mod_t<NV>, 
                              1>;
template <int NV>
using HarmMod = parameter::plain<ArrangeNew_impl::global_mod_t<NV>, 
                                 4>;
template <int NV>
using Min = parameter::plain<ArrangeNew_impl::clone_forward_t<NV>, 
                             1>;
template <int NV>
using Max = parameter::plain<ArrangeNew_impl::clone_forward2_t<NV>, 
                             1>;
template <int NV>
using Step = parameter::plain<ArrangeNew_impl::clone_forward1_t<NV>, 
                              1>;
template <int NV>
using DetuneMod = parameter::plain<ArrangeNew_impl::global_mod1_t<NV>, 
                                   4>;
template <int NV>
using OscType = parameter::plain<ArrangeNew_impl::clone_forward6_t<NV>, 
                                 1>;
template <int NV>
using Shape = parameter::plain<ArrangeNew_impl::global_mod3_t<NV>, 
                               1>;
template <int NV>
using ShapeMod = parameter::plain<ArrangeNew_impl::global_mod3_t<NV>, 
                                  4>;
template <int NV>
using VoiceMode = parameter::plain<ArrangeNew_impl::clone_forward7_t<NV>, 
                                   1>;
template <int NV>
using CyclePos = parameter::plain<ArrangeNew_impl::global_mod4_t<NV>, 
                                  1>;
template <int NV>
using CyclePosMod = parameter::plain<ArrangeNew_impl::global_mod4_t<NV>, 
                                     4>;
template <int NV>
using CycleShape = parameter::plain<ArrangeNew_impl::global_mod5_t<NV>, 
                                    1>;
template <int NV>
using CycleShapeMod = parameter::plain<ArrangeNew_impl::global_mod5_t<NV>, 
                                       4>;
template <int NV>
using FxValue = parameter::plain<ArrangeNew_impl::global_mod6_t<NV>, 
                                 1>;
template <int NV>
using FxValueMod = parameter::plain<ArrangeNew_impl::global_mod6_t<NV>, 
                                    4>;
template <int NV>
using FxMix = parameter::plain<ArrangeNew_impl::clone_forward10_t<NV>, 
                               1>;
template <int NV>
using FxDiv = parameter::plain<ArrangeNew_impl::clone_forward9_t<NV>, 
                               1>;
template <int NV>
using FxSync = parameter::plain<ArrangeNew_impl::clone_forward11_t<NV>, 
                                1>;
template <int NV>
using FxSinSh = parameter::plain<ArrangeNew_impl::clone_forward15_t<NV>, 
                                 1>;
template <int NV>
using FxSmooth = parameter::plain<ArrangeNew_impl::clone_forward14_t<NV>, 
                                  1>;
template <int NV>
using FxtoPitch = parameter::plain<ArrangeNew_impl::clone_forward12_t<NV>, 
                                   1>;
template <int NV>
using FxtoCut = parameter::plain<ArrangeNew_impl::clone_forward13_t<NV>, 
                                 1>;
template <int NV>
using Cut = parameter::plain<ArrangeNew_impl::global_mod11_t<NV>, 
                             1>;
template <int NV>
using CutMod = parameter::plain<ArrangeNew_impl::global_mod11_t<NV>, 
                                4>;
template <int NV>
using Res = parameter::plain<ArrangeNew_impl::global_mod13_t<NV>, 
                             1>;
template <int NV>
using ResMod = parameter::plain<ArrangeNew_impl::global_mod13_t<NV>, 
                                4>;
template <int NV>
using FilterMix = parameter::plain<ArrangeNew_impl::global_mod14_t<NV>, 
                                   1>;
template <int NV>
using FilterMixMod = parameter::plain<ArrangeNew_impl::global_mod14_t<NV>, 
                                      4>;
template <int NV>
using Spread = parameter::plain<ArrangeNew_impl::clone_cable13_t<NV>, 
                                1>;
template <int NV>
using Snap = parameter::plain<ArrangeNew_impl::clone_forward21_t<NV>, 
                              1>;
template <int NV>
using ArrangeNew_t_plist = parameter::list<Stages<NV>, 
                                           Harm<NV>, 
                                           HarmMod<NV>, 
                                           HarmSrc<NV>, 
                                           HarmAux<NV>, 
                                           HarmAuxSrc<NV>, 
                                           Min<NV>, 
                                           Max<NV>, 
                                           Step<NV>, 
                                           Detune<NV>, 
                                           DetuneMod<NV>, 
                                           DetuneSrc<NV>, 
                                           DetuneAux<NV>, 
                                           DetuneAuxSrc<NV>, 
                                           OscType<NV>, 
                                           Shape<NV>, 
                                           ShapeMod<NV>, 
                                           ShapeSrc<NV>, 
                                           ShapeAux<NV>, 
                                           ShapeAuxSrc<NV>, 
                                           VoiceMode<NV>, 
                                           CyclePos<NV>, 
                                           CyclePosMod<NV>, 
                                           CyclePosSrc<NV>, 
                                           CyclePosAux<NV>, 
                                           CyclePosAuxSrc<NV>, 
                                           CycleShape<NV>, 
                                           CycleShapeMod<NV>, 
                                           CycleShapeSrc<NV>, 
                                           CycleShapeAux<NV>, 
                                           CycleShapeAuxSrc<NV>, 
                                           FxValue<NV>, 
                                           FxValueMod<NV>, 
                                           FxValueSrc<NV>, 
                                           FxValueAux<NV>, 
                                           FxValueAuxSrvc<NV>, 
                                           FxMix<NV>, 
                                           FxDiv<NV>, 
                                           FxSync<NV>, 
                                           FxSinSh<NV>, 
                                           FxSmooth<NV>, 
                                           FxtoPitch<NV>, 
                                           FxtoCut<NV>, 
                                           Cut<NV>, 
                                           CutMod<NV>, 
                                           CutSrc<NV>, 
                                           CutAux<NV>, 
                                           CutAuxSrc<NV>, 
                                           FilterMode<NV>, 
                                           Res<NV>, 
                                           ResMod<NV>, 
                                           ResSrc<NV>, 
                                           ResAux<NV>, 
                                           ResAuxSrc<NV>, 
                                           FilterMix<NV>, 
                                           FilterMixMod<NV>, 
                                           FilterMixSrc<NV>, 
                                           FilterMixAux<NV>, 
                                           FilterMixAuxSrc<NV>, 
                                           Spread<NV>, 
                                           Snap<NV>>;
}

template <int NV>
using ArrangeNew_t_ = container::chain<ArrangeNew_t_parameters::ArrangeNew_t_plist<NV>, 
                                       wrap::fix<2, modchain_t<NV>>, 
                                       clone_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public ArrangeNew_impl::ArrangeNew_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 3;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(ArrangeNew);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(1110)
		{
			0x005C, 0x0000, 0x0000, 0x7453, 0x6761, 0x7365, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x4200, 0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0001, 0x0000, 0x6148, 0x6D72, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0002, 0x0000, 0x6148, 0x6D72, 0x6F4D, 0x0064, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x0300, 0x0000, 0x4800, 0x7261, 0x536D, 
            0x6372, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4188, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0004, 0x0000, 0x6148, 
            0x6D72, 0x7541, 0x0078, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0500, 0x0000, 
            0x4800, 0x7261, 0x416D, 0x7875, 0x7253, 0x0063, 0x0000, 0x8000, 
            0x003F, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x0600, 0x0000, 0x4D00, 0x6E69, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0007, 0x0000, 0x614D, 0x0078, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0041, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x0800, 0x0000, 0x5300, 0x6574, 0x0070, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0900, 0x0000, 0x4400, 0x7465, 0x6E75, 0x0065, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x8F3F, 0xF5C2, 0x003C, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x0A00, 0x0000, 0x4400, 0x7465, 0x6E75, 0x4D65, 0x646F, 
            0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x000B, 0x0000, 0x6544, 0x7574, 
            0x656E, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0x8800, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0C00, 0x0000, 
            0x4400, 0x7465, 0x6E75, 0x4165, 0x7875, 0x0000, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x45A2, 0x3AAA, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x000D, 0x0000, 0x6544, 0x7574, 0x656E, 0x7541, 0x5378, 
            0x6372, 0x0000, 0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x000E, 0x0000, 0x734F, 
            0x5463, 0x7079, 0x0065, 0x0000, 0x8000, 0x003F, 0xC000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0F00, 0x0000, 
            0x5300, 0x6168, 0x6570, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0xEE86, 0x3F0C, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0010, 
            0x0000, 0x6853, 0x7061, 0x4D65, 0x646F, 0x0000, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0011, 0x0000, 0x6853, 0x7061, 0x5365, 0x6372, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x4188, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x0012, 0x0000, 0x6853, 0x7061, 0x4165, 
            0x7875, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0013, 0x0000, 0x6853, 
            0x7061, 0x4165, 0x7875, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 
            0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x1400, 0x0000, 0x5600, 0x696F, 0x6563, 0x6F4D, 0x6564, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x4040, 0x0000, 0x4000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0015, 0x0000, 0x7943, 0x6C63, 0x5065, 
            0x736F, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x999A, 0x3E19, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0016, 0x0000, 0x7943, 
            0x6C63, 0x5065, 0x736F, 0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x1700, 0x0000, 0x4300, 0x6379, 0x656C, 0x6F50, 0x5373, 0x6372, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x4188, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x005C, 0x0018, 0x0000, 0x7943, 0x6C63, 
            0x5065, 0x736F, 0x7541, 0x0078, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1900, 
            0x0000, 0x4300, 0x6379, 0x656C, 0x6F50, 0x4173, 0x7875, 0x7253, 
            0x0063, 0x0000, 0x8000, 0x003F, 0xC000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x1A00, 0x0000, 0x4300, 0x6379, 
            0x656C, 0x6853, 0x7061, 0x0065, 0x0000, 0x0000, 0x0000, 0x8000, 
            0xCD3F, 0xCCCC, 0x003E, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1B00, 
            0x0000, 0x4300, 0x6379, 0x656C, 0x6853, 0x7061, 0x4D65, 0x646F, 
            0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x001C, 0x0000, 0x7943, 0x6C63, 
            0x5365, 0x6168, 0x6570, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 
            0x8800, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x1D00, 0x0000, 0x4300, 0x6379, 0x656C, 0x6853, 0x7061, 0x4165, 
            0x7875, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x5C29, 0xBE8F, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x001E, 0x0000, 0x7943, 
            0x6C63, 0x5365, 0x6168, 0x6570, 0x7541, 0x5378, 0x6372, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x4040, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x001F, 0x0000, 0x7846, 0x6156, 0x756C, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x2000, 0x0000, 0x4600, 0x5678, 
            0x6C61, 0x6575, 0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x2100, 
            0x0000, 0x4600, 0x5678, 0x6C61, 0x6575, 0x7253, 0x0063, 0x0000, 
            0x8000, 0x003F, 0x8800, 0x0041, 0x4000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x2200, 0x0000, 0x4600, 0x5678, 0x6C61, 0x6575, 
            0x7541, 0x0078, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x2300, 0x0000, 0x4600, 
            0x5678, 0x6C61, 0x6575, 0x7541, 0x5378, 0x7672, 0x0063, 0x0000, 
            0x8000, 0x003F, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x2400, 0x0000, 0x4600, 0x4D78, 0x7869, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0025, 0x0000, 0x7846, 0x6944, 0x0076, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x0000, 0x0042, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x2600, 0x0000, 0x4600, 0x5378, 0x6E79, 
            0x0063, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x2700, 0x0000, 0x4600, 0x5378, 
            0x6E69, 0x6853, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0028, 0x0000, 
            0x7846, 0x6D53, 0x6F6F, 0x6874, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x44FA, 0xC000, 0x40A8, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0029, 0x0000, 0x7846, 0x6F74, 0x6950, 0x6374, 0x0068, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x0A3F, 0xA3D7, 0x003D, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x2A00, 0x0000, 0x4600, 0x7478, 0x436F, 0x7475, 
            0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x47AE, 0x3DE1, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x002B, 0x0000, 0x7543, 0x0074, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x2C00, 0x0000, 0x4300, 0x7475, 0x6F4D, 
            0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x2D00, 0x0000, 0x4300, 0x7475, 
            0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0x8800, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x2E00, 0x0000, 0x4300, 
            0x7475, 0x7541, 0x0078, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x2F00, 0x0000, 
            0x4300, 0x7475, 0x7541, 0x5378, 0x6372, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0030, 0x0000, 0x6946, 0x746C, 0x7265, 0x6F4D, 0x6564, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x005C, 0x0031, 0x0000, 0x6552, 0x0073, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x3200, 0x0000, 0x5200, 0x7365, 0x6F4D, 
            0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x3300, 0x0000, 0x5200, 0x7365, 
            0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0x8800, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x3400, 0x0000, 0x5200, 
            0x7365, 0x7541, 0x0078, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x3500, 0x0000, 
            0x5200, 0x7365, 0x7541, 0x5378, 0x6372, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0036, 0x0000, 0x6946, 0x746C, 0x7265, 0x694D, 0x0078, 
            0x0000, 0x0000, 0x0000, 0x8000, 0xEC3F, 0x7851, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x3700, 0x0000, 0x4600, 0x6C69, 0x6574, 
            0x4D72, 0x7869, 0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x3800, 
            0x0000, 0x4600, 0x6C69, 0x6574, 0x4D72, 0x7869, 0x7253, 0x0063, 
            0x0000, 0x8000, 0x003F, 0x8800, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x3900, 0x0000, 0x4600, 0x6C69, 0x6574, 
            0x4D72, 0x7869, 0x7541, 0x0078, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x3A00, 
            0x0000, 0x4600, 0x6C69, 0x6574, 0x4D72, 0x7869, 0x7541, 0x5378, 
            0x6372, 0x0000, 0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x003B, 0x0000, 0x7053, 
            0x6572, 0x6461, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0xCF7B, 
            0x3EB1, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x003C, 0x0000, 
            0x6E53, 0x7061, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(25)
		{
			0x003A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                     // ArrangeNew_impl::modchain_t<NV>
		auto& split = this->getT(0).getT(0);                                                // ArrangeNew_impl::split_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0);                                        // ArrangeNew_impl::chain_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(0);                               // ArrangeNew_impl::chain1_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                       // ArrangeNew_impl::chain9_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);               // ArrangeNew_impl::split1_t<NV>
		auto& global_mod = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);   // ArrangeNew_impl::global_mod_t<NV>
		auto& branch1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);      // ArrangeNew_impl::branch1_t<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(0).                               // ArrangeNew_impl::chain3_t<NV>
                       getT(0).getT(0).getT(1).getT(0);
		auto& midi1 = this->getT(0).getT(0).getT(0).getT(0).                                // ArrangeNew_impl::midi1_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(0);
		auto& pma1 = this->getT(0).getT(0).getT(0).getT(0).                                 // ArrangeNew_impl::pma1_t<NV>
                     getT(0).getT(0).getT(1).getT(0).
                     getT(1);
		auto& add1 = this->getT(0).getT(0).getT(0).getT(0).                                 // math::add<NV>
                     getT(0).getT(0).getT(1).getT(0).
                     getT(2);
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(0).                               // ArrangeNew_impl::chain4_t<NV>
                       getT(0).getT(0).getT(1).getT(1);
		auto& midi2 = this->getT(0).getT(0).getT(0).getT(0).                                // ArrangeNew_impl::midi2_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(0);
		auto& pma2 = this->getT(0).getT(0).getT(0).getT(0).                                 // ArrangeNew_impl::pma2_t<NV>
                     getT(0).getT(0).getT(1).getT(1).
                     getT(1);
		auto& add2 = this->getT(0).getT(0).getT(0).getT(0).                                 // math::add<NV>
                     getT(0).getT(0).getT(1).getT(1).
                     getT(2);
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(0).                               // ArrangeNew_impl::chain5_t<NV>
                       getT(0).getT(0).getT(1).getT(2);
		auto& midi3 = this->getT(0).getT(0).getT(0).getT(0).                                // ArrangeNew_impl::midi3_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(0);
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(0).                                 // ArrangeNew_impl::pma3_t<NV>
                     getT(0).getT(0).getT(1).getT(2).
                     getT(1);
		auto& add3 = this->getT(0).getT(0).getT(0).getT(0).                                 // math::add<NV>
                     getT(0).getT(0).getT(1).getT(2).
                     getT(2);
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(0).                               // ArrangeNew_impl::chain6_t<NV>
                       getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc = this->getT(0).getT(0).getT(0).getT(0).                              // ArrangeNew_impl::midi_cc_t<NV>
                        getT(0).getT(0).getT(1).getT(3).
                        getT(0);
		auto& pma4 = this->getT(0).getT(0).getT(0).getT(0).                                 // ArrangeNew_impl::pma4_t<NV>
                     getT(0).getT(0).getT(1).getT(3).
                     getT(1);
		auto& add4 = this->getT(0).getT(0).getT(0).getT(0).                                 // math::add<NV>
                     getT(0).getT(0).getT(1).getT(3).
                     getT(2);
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(0).                               // ArrangeNew_impl::chain7_t<NV>
                       getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc1 = this->getT(0).getT(0).getT(0).getT(0).                             // ArrangeNew_impl::midi_cc1_t<NV>
                         getT(0).getT(0).getT(1).getT(4).
                         getT(0);
		auto& pma5 = this->getT(0).getT(0).getT(0).getT(0).                                 // ArrangeNew_impl::pma5_t<NV>
                     getT(0).getT(0).getT(1).getT(4).
                     getT(1);
		auto& add5 = this->getT(0).getT(0).getT(0).getT(0).                                 // math::add<NV>
                     getT(0).getT(0).getT(1).getT(4).
                     getT(2);
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(0).                               // ArrangeNew_impl::chain8_t<NV>
                       getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc2 = this->getT(0).getT(0).getT(0).getT(0).                             // ArrangeNew_impl::midi_cc2_t<NV>
                         getT(0).getT(0).getT(1).getT(5).
                         getT(0);
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(0).                                 // ArrangeNew_impl::pma6_t<NV>
                     getT(0).getT(0).getT(1).getT(5).
                     getT(1);
		auto& add6 = this->getT(0).getT(0).getT(0).getT(0).                                 // math::add<NV>
                     getT(0).getT(0).getT(1).getT(5).
                     getT(2);
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);                 // ArrangeNew_impl::peak_t<NV>
		auto& clear = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);                // math::clear<NV>
		auto& pack_resizer = this->getT(0).getT(0).getT(0).getT(0).getT(1);                 // ArrangeNew_impl::pack_resizer_t
		auto& split2 = this->getT(0).getT(0).getT(0).getT(0).getT(2);                       // ArrangeNew_impl::split2_t<NV>
		auto& clone_pack = this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(0);           // ArrangeNew_impl::clone_pack_t<NV>
		auto& clone_forward = this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(1);        // ArrangeNew_impl::clone_forward_t<NV>
		auto& clone_forward2 = this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(2);       // ArrangeNew_impl::clone_forward2_t<NV>
		auto& clone_forward1 = this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(3);       // ArrangeNew_impl::clone_forward1_t<NV>
		auto& clone_forward6 = this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(4);       // ArrangeNew_impl::clone_forward6_t<NV>
		auto& clone_forward7 = this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(5);       // ArrangeNew_impl::clone_forward7_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(1);                                      // ArrangeNew_impl::chain10_t<NV>
		auto& chain11 = this->getT(0).getT(0).getT(1).getT(0);                              // ArrangeNew_impl::chain11_t<NV>
		auto& chain12 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                      // ArrangeNew_impl::chain12_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);               // ArrangeNew_impl::split3_t<NV>
		auto& global_mod1 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).getT(0);  // ArrangeNew_impl::global_mod1_t<NV>
		auto& branch2 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).getT(1);      // ArrangeNew_impl::branch2_t<NV>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(0).                              // ArrangeNew_impl::chain13_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& midi5 = this->getT(0).getT(0).getT(1).getT(0).                                // ArrangeNew_impl::midi5_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(0);
		auto& pma7 = this->getT(0).getT(0).getT(1).getT(0).                                 // ArrangeNew_impl::pma7_t<NV>
                     getT(0).getT(0).getT(1).getT(0).
                     getT(1);
		auto& add7 = this->getT(0).getT(0).getT(1).getT(0).                                 // math::add<NV>
                     getT(0).getT(0).getT(1).getT(0).
                     getT(2);
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(0).                              // ArrangeNew_impl::chain14_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& midi6 = this->getT(0).getT(0).getT(1).getT(0).                                // ArrangeNew_impl::midi6_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(0);
		auto& pma8 = this->getT(0).getT(0).getT(1).getT(0).                                 // ArrangeNew_impl::pma8_t<NV>
                     getT(0).getT(0).getT(1).getT(1).
                     getT(1);
		auto& add8 = this->getT(0).getT(0).getT(1).getT(0).                                 // math::add<NV>
                     getT(0).getT(0).getT(1).getT(1).
                     getT(2);
		auto& chain15 = this->getT(0).getT(0).getT(1).getT(0).                              // ArrangeNew_impl::chain15_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& midi7 = this->getT(0).getT(0).getT(1).getT(0).                                // ArrangeNew_impl::midi7_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(0);
		auto& pma9 = this->getT(0).getT(0).getT(1).getT(0).                                 // ArrangeNew_impl::pma9_t<NV>
                     getT(0).getT(0).getT(1).getT(2).
                     getT(1);
		auto& add9 = this->getT(0).getT(0).getT(1).getT(0).                                 // math::add<NV>
                     getT(0).getT(0).getT(1).getT(2).
                     getT(2);
		auto& chain16 = this->getT(0).getT(0).getT(1).getT(0).                              // ArrangeNew_impl::chain16_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc3 = this->getT(0).getT(0).getT(1).getT(0).                             // ArrangeNew_impl::midi_cc3_t<NV>
                         getT(0).getT(0).getT(1).getT(3).
                         getT(0);
		auto& pma10 = this->getT(0).getT(0).getT(1).getT(0).                                // ArrangeNew_impl::pma10_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add10 = this->getT(0).getT(0).getT(1).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain17 = this->getT(0).getT(0).getT(1).getT(0).                              // ArrangeNew_impl::chain17_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc4 = this->getT(0).getT(0).getT(1).getT(0).                             // ArrangeNew_impl::midi_cc4_t<NV>
                         getT(0).getT(0).getT(1).getT(4).
                         getT(0);
		auto& pma11 = this->getT(0).getT(0).getT(1).getT(0).                                // ArrangeNew_impl::pma11_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add11 = this->getT(0).getT(0).getT(1).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain18 = this->getT(0).getT(0).getT(1).getT(0).                              // ArrangeNew_impl::chain18_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc5 = this->getT(0).getT(0).getT(1).getT(0).                             // ArrangeNew_impl::midi_cc5_t<NV>
                         getT(0).getT(0).getT(1).getT(5).
                         getT(0);
		auto& pma12 = this->getT(0).getT(0).getT(1).getT(0).                                // ArrangeNew_impl::pma12_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add12 = this->getT(0).getT(0).getT(1).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak1 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);                // ArrangeNew_impl::peak1_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(2);               // math::clear<NV>
		auto& clone_cable = this->getT(0).getT(0).getT(1).getT(0).getT(1);                  // ArrangeNew_impl::clone_cable_t<NV>
		auto& chain27 = this->getT(0).getT(0).getT(2);                                      // ArrangeNew_impl::chain27_t<NV>
		auto& chain28 = this->getT(0).getT(0).getT(2).getT(0);                              // ArrangeNew_impl::chain28_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(2).getT(0).getT(0);                      // ArrangeNew_impl::chain29_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0);               // ArrangeNew_impl::split6_t<NV>
		auto& global_mod3 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).getT(0);  // ArrangeNew_impl::global_mod3_t<NV>
		auto& branch4 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).getT(1);      // ArrangeNew_impl::branch4_t<NV>
		auto& chain30 = this->getT(0).getT(0).getT(2).getT(0).                              // ArrangeNew_impl::chain30_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& midi11 = this->getT(0).getT(0).getT(2).getT(0).                               // ArrangeNew_impl::midi11_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma19 = this->getT(0).getT(0).getT(2).getT(0).                                // ArrangeNew_impl::pma19_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add19 = this->getT(0).getT(0).getT(2).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain31 = this->getT(0).getT(0).getT(2).getT(0).                              // ArrangeNew_impl::chain31_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& midi12 = this->getT(0).getT(0).getT(2).getT(0).                               // ArrangeNew_impl::midi12_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma20 = this->getT(0).getT(0).getT(2).getT(0).                                // ArrangeNew_impl::pma20_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add20 = this->getT(0).getT(0).getT(2).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain32 = this->getT(0).getT(0).getT(2).getT(0).                              // ArrangeNew_impl::chain32_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& midi13 = this->getT(0).getT(0).getT(2).getT(0).                               // ArrangeNew_impl::midi13_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma21 = this->getT(0).getT(0).getT(2).getT(0).                                // ArrangeNew_impl::pma21_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add21 = this->getT(0).getT(0).getT(2).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain33 = this->getT(0).getT(0).getT(2).getT(0).                              // ArrangeNew_impl::chain33_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc9 = this->getT(0).getT(0).getT(2).getT(0).                             // ArrangeNew_impl::midi_cc9_t<NV>
                         getT(0).getT(0).getT(1).getT(3).
                         getT(0);
		auto& pma22 = this->getT(0).getT(0).getT(2).getT(0).                                // ArrangeNew_impl::pma22_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add22 = this->getT(0).getT(0).getT(2).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain34 = this->getT(0).getT(0).getT(2).getT(0).                              // ArrangeNew_impl::chain34_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc10 = this->getT(0).getT(0).getT(2).getT(0).                            // ArrangeNew_impl::midi_cc10_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma23 = this->getT(0).getT(0).getT(2).getT(0).                                // ArrangeNew_impl::pma23_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add23 = this->getT(0).getT(0).getT(2).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain35 = this->getT(0).getT(0).getT(2).getT(0).                              // ArrangeNew_impl::chain35_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc11 = this->getT(0).getT(0).getT(2).getT(0).                            // ArrangeNew_impl::midi_cc11_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma24 = this->getT(0).getT(0).getT(2).getT(0).                                // ArrangeNew_impl::pma24_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add24 = this->getT(0).getT(0).getT(2).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak3 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1);                // ArrangeNew_impl::peak3_t<NV>
		auto& clear3 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(2);               // math::clear<NV>
		auto& clone_cable2 = this->getT(0).getT(0).getT(2).getT(0).getT(1);                 // ArrangeNew_impl::clone_cable2_t<NV>
		auto& chain36 = this->getT(0).getT(0).getT(3);                                      // ArrangeNew_impl::chain36_t<NV>
		auto& chain37 = this->getT(0).getT(0).getT(3).getT(0);                              // ArrangeNew_impl::chain37_t<NV>
		auto& chain38 = this->getT(0).getT(0).getT(3).getT(0).getT(0);                      // ArrangeNew_impl::chain38_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(0);               // ArrangeNew_impl::split7_t<NV>
		auto& global_mod4 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(0).getT(0);  // ArrangeNew_impl::global_mod4_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(0).getT(1);      // ArrangeNew_impl::branch5_t<NV>
		auto& chain39 = this->getT(0).getT(0).getT(3).getT(0).                              // ArrangeNew_impl::chain39_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& midi14 = this->getT(0).getT(0).getT(3).getT(0).                               // ArrangeNew_impl::midi14_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma25 = this->getT(0).getT(0).getT(3).getT(0).                                // ArrangeNew_impl::pma25_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add25 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain40 = this->getT(0).getT(0).getT(3).getT(0).                              // ArrangeNew_impl::chain40_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& midi15 = this->getT(0).getT(0).getT(3).getT(0).                               // ArrangeNew_impl::midi15_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma26 = this->getT(0).getT(0).getT(3).getT(0).                                // ArrangeNew_impl::pma26_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add26 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain41 = this->getT(0).getT(0).getT(3).getT(0).                              // ArrangeNew_impl::chain41_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& midi16 = this->getT(0).getT(0).getT(3).getT(0).                               // ArrangeNew_impl::midi16_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma27 = this->getT(0).getT(0).getT(3).getT(0).                                // ArrangeNew_impl::pma27_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add27 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain42 = this->getT(0).getT(0).getT(3).getT(0).                              // ArrangeNew_impl::chain42_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc12 = this->getT(0).getT(0).getT(3).getT(0).                            // ArrangeNew_impl::midi_cc12_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma28 = this->getT(0).getT(0).getT(3).getT(0).                                // ArrangeNew_impl::pma28_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add28 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain43 = this->getT(0).getT(0).getT(3).getT(0).                              // ArrangeNew_impl::chain43_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc13 = this->getT(0).getT(0).getT(3).getT(0).                            // ArrangeNew_impl::midi_cc13_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma29 = this->getT(0).getT(0).getT(3).getT(0).                                // ArrangeNew_impl::pma29_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add29 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain44 = this->getT(0).getT(0).getT(3).getT(0).                              // ArrangeNew_impl::chain44_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc14 = this->getT(0).getT(0).getT(3).getT(0).                            // ArrangeNew_impl::midi_cc14_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma30 = this->getT(0).getT(0).getT(3).getT(0).                                // ArrangeNew_impl::pma30_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add30 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak4 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1);                // ArrangeNew_impl::peak4_t<NV>
		auto& clear4 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(2);               // math::clear<NV>
		auto& clone_cable3 = this->getT(0).getT(0).getT(3).getT(0).getT(1);                 // ArrangeNew_impl::clone_cable3_t<NV>
		auto& chain45 = this->getT(0).getT(0).getT(4);                                      // ArrangeNew_impl::chain45_t<NV>
		auto& chain46 = this->getT(0).getT(0).getT(4).getT(0);                              // ArrangeNew_impl::chain46_t<NV>
		auto& chain47 = this->getT(0).getT(0).getT(4).getT(0).getT(0);                      // ArrangeNew_impl::chain47_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0);               // ArrangeNew_impl::split8_t<NV>
		auto& global_mod5 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0).getT(0);  // ArrangeNew_impl::global_mod5_t<NV>
		auto& branch6 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0).getT(1);      // ArrangeNew_impl::branch6_t<NV>
		auto& chain48 = this->getT(0).getT(0).getT(4).getT(0).                              // ArrangeNew_impl::chain48_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& midi17 = this->getT(0).getT(0).getT(4).getT(0).                               // ArrangeNew_impl::midi17_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma31 = this->getT(0).getT(0).getT(4).getT(0).                                // ArrangeNew_impl::pma31_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add31 = this->getT(0).getT(0).getT(4).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain49 = this->getT(0).getT(0).getT(4).getT(0).                              // ArrangeNew_impl::chain49_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& midi18 = this->getT(0).getT(0).getT(4).getT(0).                               // ArrangeNew_impl::midi18_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma32 = this->getT(0).getT(0).getT(4).getT(0).                                // ArrangeNew_impl::pma32_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add32 = this->getT(0).getT(0).getT(4).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain50 = this->getT(0).getT(0).getT(4).getT(0).                              // ArrangeNew_impl::chain50_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& midi19 = this->getT(0).getT(0).getT(4).getT(0).                               // ArrangeNew_impl::midi19_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma33 = this->getT(0).getT(0).getT(4).getT(0).                                // ArrangeNew_impl::pma33_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add33 = this->getT(0).getT(0).getT(4).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain51 = this->getT(0).getT(0).getT(4).getT(0).                              // ArrangeNew_impl::chain51_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc15 = this->getT(0).getT(0).getT(4).getT(0).                            // ArrangeNew_impl::midi_cc15_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma34 = this->getT(0).getT(0).getT(4).getT(0).                                // ArrangeNew_impl::pma34_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add34 = this->getT(0).getT(0).getT(4).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain52 = this->getT(0).getT(0).getT(4).getT(0).                              // ArrangeNew_impl::chain52_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc16 = this->getT(0).getT(0).getT(4).getT(0).                            // ArrangeNew_impl::midi_cc16_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma35 = this->getT(0).getT(0).getT(4).getT(0).                                // ArrangeNew_impl::pma35_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add35 = this->getT(0).getT(0).getT(4).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain53 = this->getT(0).getT(0).getT(4).getT(0).                              // ArrangeNew_impl::chain53_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc17 = this->getT(0).getT(0).getT(4).getT(0).                            // ArrangeNew_impl::midi_cc17_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma36 = this->getT(0).getT(0).getT(4).getT(0).                                // ArrangeNew_impl::pma36_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add36 = this->getT(0).getT(0).getT(4).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak5 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(1);                // ArrangeNew_impl::peak5_t<NV>
		auto& clear5 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(2);               // math::clear<NV>
		auto& clone_cable4 = this->getT(0).getT(0).getT(4).getT(0).getT(1);                 // ArrangeNew_impl::clone_cable4_t<NV>
		auto& split9 = this->getT(0).getT(1);                                               // ArrangeNew_impl::split9_t<NV>
		auto& chain54 = this->getT(0).getT(1).getT(0);                                      // ArrangeNew_impl::chain54_t<NV>
		auto& chain55 = this->getT(0).getT(1).getT(0).getT(0);                              // ArrangeNew_impl::chain55_t<NV>
		auto& chain56 = this->getT(0).getT(1).getT(0).getT(0).getT(0);                      // ArrangeNew_impl::chain56_t<NV>
		auto& split10 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0);              // ArrangeNew_impl::split10_t<NV>
		auto& global_mod6 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);  // ArrangeNew_impl::global_mod6_t<NV>
		auto& branch7 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(1);      // ArrangeNew_impl::branch7_t<NV>
		auto& chain57 = this->getT(0).getT(1).getT(0).getT(0).                              // ArrangeNew_impl::chain57_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& midi20 = this->getT(0).getT(1).getT(0).getT(0).                               // ArrangeNew_impl::midi20_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma37 = this->getT(0).getT(1).getT(0).getT(0).                                // ArrangeNew_impl::pma37_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add37 = this->getT(0).getT(1).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain58 = this->getT(0).getT(1).getT(0).getT(0).                              // ArrangeNew_impl::chain58_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& midi21 = this->getT(0).getT(1).getT(0).getT(0).                               // ArrangeNew_impl::midi21_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma38 = this->getT(0).getT(1).getT(0).getT(0).                                // ArrangeNew_impl::pma38_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add38 = this->getT(0).getT(1).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain59 = this->getT(0).getT(1).getT(0).getT(0).                              // ArrangeNew_impl::chain59_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& midi22 = this->getT(0).getT(1).getT(0).getT(0).                               // ArrangeNew_impl::midi22_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma39 = this->getT(0).getT(1).getT(0).getT(0).                                // ArrangeNew_impl::pma39_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add39 = this->getT(0).getT(1).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain60 = this->getT(0).getT(1).getT(0).getT(0).                              // ArrangeNew_impl::chain60_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc18 = this->getT(0).getT(1).getT(0).getT(0).                            // ArrangeNew_impl::midi_cc18_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma40 = this->getT(0).getT(1).getT(0).getT(0).                                // ArrangeNew_impl::pma40_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add40 = this->getT(0).getT(1).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain61 = this->getT(0).getT(1).getT(0).getT(0).                              // ArrangeNew_impl::chain61_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc19 = this->getT(0).getT(1).getT(0).getT(0).                            // ArrangeNew_impl::midi_cc19_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma41 = this->getT(0).getT(1).getT(0).getT(0).                                // ArrangeNew_impl::pma41_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add41 = this->getT(0).getT(1).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain62 = this->getT(0).getT(1).getT(0).getT(0).                              // ArrangeNew_impl::chain62_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc20 = this->getT(0).getT(1).getT(0).getT(0).                            // ArrangeNew_impl::midi_cc20_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma42 = this->getT(0).getT(1).getT(0).getT(0).                                // ArrangeNew_impl::pma42_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add42 = this->getT(0).getT(1).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak6 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(1);                // ArrangeNew_impl::peak6_t<NV>
		auto& clear6 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(2);               // math::clear<NV>
		auto& pack_resizer2 = this->getT(0).getT(1).getT(0).getT(0).getT(1);                // ArrangeNew_impl::pack_resizer2_t
		auto& split11 = this->getT(0).getT(1).getT(0).getT(0).getT(2);                      // ArrangeNew_impl::split11_t<NV>
		auto& clone_pack2 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);          // ArrangeNew_impl::clone_pack2_t<NV>
		auto& clone_forward10 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(1);      // ArrangeNew_impl::clone_forward10_t<NV>
		auto& clone_forward9 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(2);       // ArrangeNew_impl::clone_forward9_t<NV>
		auto& clone_forward11 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(3);      // ArrangeNew_impl::clone_forward11_t<NV>
		auto& clone_forward15 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(4);      // ArrangeNew_impl::clone_forward15_t<NV>
		auto& clone_forward12 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(5);      // ArrangeNew_impl::clone_forward12_t<NV>
		auto& clone_forward13 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(6);      // ArrangeNew_impl::clone_forward13_t<NV>
		auto& clone_forward14 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(7);      // ArrangeNew_impl::clone_forward14_t<NV>
		auto& split16 = this->getT(0).getT(2);                                              // ArrangeNew_impl::split16_t<NV>
		auto& chain99 = this->getT(0).getT(2).getT(0);                                      // ArrangeNew_impl::chain99_t<NV>
		auto& chain100 = this->getT(0).getT(2).getT(0).getT(0);                             // ArrangeNew_impl::chain100_t<NV>
		auto& chain101 = this->getT(0).getT(2).getT(0).getT(0).getT(0);                     // ArrangeNew_impl::chain101_t<NV>
		auto& split17 = this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(0);              // ArrangeNew_impl::split17_t<NV>
		auto& global_mod11 = this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(0).getT(0); // ArrangeNew_impl::global_mod11_t<NV>
		auto& branch12 = this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(0).getT(1);     // ArrangeNew_impl::branch12_t<NV>
		auto& chain102 = this->getT(0).getT(2).getT(0).getT(0).                             // ArrangeNew_impl::chain102_t<NV>
                         getT(0).getT(0).getT(1).getT(0);
		auto& midi35 = this->getT(0).getT(2).getT(0).getT(0).                               // ArrangeNew_impl::midi35_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma67 = this->getT(0).getT(2).getT(0).getT(0).                                // ArrangeNew_impl::pma67_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add67 = this->getT(0).getT(2).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain103 = this->getT(0).getT(2).getT(0).getT(0).                             // ArrangeNew_impl::chain103_t<NV>
                         getT(0).getT(0).getT(1).getT(1);
		auto& midi36 = this->getT(0).getT(2).getT(0).getT(0).                               // ArrangeNew_impl::midi36_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma68 = this->getT(0).getT(2).getT(0).getT(0).                                // ArrangeNew_impl::pma68_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add68 = this->getT(0).getT(2).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain104 = this->getT(0).getT(2).getT(0).getT(0).                             // ArrangeNew_impl::chain104_t<NV>
                         getT(0).getT(0).getT(1).getT(2);
		auto& midi37 = this->getT(0).getT(2).getT(0).getT(0).                               // ArrangeNew_impl::midi37_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma69 = this->getT(0).getT(2).getT(0).getT(0).                                // ArrangeNew_impl::pma69_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add69 = this->getT(0).getT(2).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain105 = this->getT(0).getT(2).getT(0).getT(0).                             // ArrangeNew_impl::chain105_t<NV>
                         getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc33 = this->getT(0).getT(2).getT(0).getT(0).                            // ArrangeNew_impl::midi_cc33_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma70 = this->getT(0).getT(2).getT(0).getT(0).                                // ArrangeNew_impl::pma70_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add70 = this->getT(0).getT(2).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain106 = this->getT(0).getT(2).getT(0).getT(0).                             // ArrangeNew_impl::chain106_t<NV>
                         getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc34 = this->getT(0).getT(2).getT(0).getT(0).                            // ArrangeNew_impl::midi_cc34_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma71 = this->getT(0).getT(2).getT(0).getT(0).                                // ArrangeNew_impl::pma71_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add71 = this->getT(0).getT(2).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain107 = this->getT(0).getT(2).getT(0).getT(0).                             // ArrangeNew_impl::chain107_t<NV>
                         getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc35 = this->getT(0).getT(2).getT(0).getT(0).                            // ArrangeNew_impl::midi_cc35_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma72 = this->getT(0).getT(2).getT(0).getT(0).                                // ArrangeNew_impl::pma72_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add72 = this->getT(0).getT(2).getT(0).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak11 = this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(1);               // ArrangeNew_impl::peak11_t<NV>
		auto& clear11 = this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(2);              // math::clear<NV>
		auto& pack_resizer3 = this->getT(0).getT(2).getT(0).getT(0).getT(1);                // ArrangeNew_impl::pack_resizer3_t
		auto& split18 = this->getT(0).getT(2).getT(0).getT(0).getT(2);                      // ArrangeNew_impl::split18_t<NV>
		auto& clone_pack3 = this->getT(0).getT(2).getT(0).getT(0).getT(2).getT(0);          // ArrangeNew_impl::clone_pack3_t<NV>
		auto& clone_cable14 = this->getT(0).getT(2).getT(0).getT(0).getT(2).getT(1);        // ArrangeNew_impl::clone_cable14_t<NV>
		auto& clone_forward21 = this->getT(0).getT(2).getT(0).getT(0).getT(2).getT(2);      // ArrangeNew_impl::clone_forward21_t<NV>
		auto& clone_cable13 = this->getT(0).getT(2).getT(0).getT(0).getT(2).getT(3);        // ArrangeNew_impl::clone_cable13_t<NV>
		auto& chain117 = this->getT(0).getT(2).getT(1);                                     // ArrangeNew_impl::chain117_t<NV>
		auto& chain118 = this->getT(0).getT(2).getT(1).getT(0);                             // ArrangeNew_impl::chain118_t<NV>
		auto& chain119 = this->getT(0).getT(2).getT(1).getT(0).getT(0);                     // ArrangeNew_impl::chain119_t<NV>
		auto& split20 = this->getT(0).getT(2).getT(1).getT(0).getT(0).getT(0);              // ArrangeNew_impl::split20_t<NV>
		auto& global_mod13 = this->getT(0).getT(2).getT(1).getT(0).getT(0).getT(0).getT(0); // ArrangeNew_impl::global_mod13_t<NV>
		auto& branch14 = this->getT(0).getT(2).getT(1).getT(0).getT(0).getT(0).getT(1);     // ArrangeNew_impl::branch14_t<NV>
		auto& chain120 = this->getT(0).getT(2).getT(1).getT(0).                             // ArrangeNew_impl::chain120_t<NV>
                         getT(0).getT(0).getT(1).getT(0);
		auto& midi41 = this->getT(0).getT(2).getT(1).getT(0).                               // ArrangeNew_impl::midi41_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma79 = this->getT(0).getT(2).getT(1).getT(0).                                // ArrangeNew_impl::pma79_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add79 = this->getT(0).getT(2).getT(1).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain121 = this->getT(0).getT(2).getT(1).getT(0).                             // ArrangeNew_impl::chain121_t<NV>
                         getT(0).getT(0).getT(1).getT(1);
		auto& midi42 = this->getT(0).getT(2).getT(1).getT(0).                               // ArrangeNew_impl::midi42_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma80 = this->getT(0).getT(2).getT(1).getT(0).                                // ArrangeNew_impl::pma80_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add80 = this->getT(0).getT(2).getT(1).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain122 = this->getT(0).getT(2).getT(1).getT(0).                             // ArrangeNew_impl::chain122_t<NV>
                         getT(0).getT(0).getT(1).getT(2);
		auto& midi43 = this->getT(0).getT(2).getT(1).getT(0).                               // ArrangeNew_impl::midi43_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma81 = this->getT(0).getT(2).getT(1).getT(0).                                // ArrangeNew_impl::pma81_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add81 = this->getT(0).getT(2).getT(1).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain123 = this->getT(0).getT(2).getT(1).getT(0).                             // ArrangeNew_impl::chain123_t<NV>
                         getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc39 = this->getT(0).getT(2).getT(1).getT(0).                            // ArrangeNew_impl::midi_cc39_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma82 = this->getT(0).getT(2).getT(1).getT(0).                                // ArrangeNew_impl::pma82_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add82 = this->getT(0).getT(2).getT(1).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain124 = this->getT(0).getT(2).getT(1).getT(0).                             // ArrangeNew_impl::chain124_t<NV>
                         getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc40 = this->getT(0).getT(2).getT(1).getT(0).                            // ArrangeNew_impl::midi_cc40_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma83 = this->getT(0).getT(2).getT(1).getT(0).                                // ArrangeNew_impl::pma83_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add83 = this->getT(0).getT(2).getT(1).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain125 = this->getT(0).getT(2).getT(1).getT(0).                             // ArrangeNew_impl::chain125_t<NV>
                         getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc41 = this->getT(0).getT(2).getT(1).getT(0).                            // ArrangeNew_impl::midi_cc41_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma84 = this->getT(0).getT(2).getT(1).getT(0).                                // ArrangeNew_impl::pma84_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add84 = this->getT(0).getT(2).getT(1).getT(0).                                // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak13 = this->getT(0).getT(2).getT(1).getT(0).getT(0).getT(1);               // ArrangeNew_impl::peak13_t<NV>
		auto& clear13 = this->getT(0).getT(2).getT(1).getT(0).getT(0).getT(2);              // math::clear<NV>
		auto& clone_cable10 = this->getT(0).getT(2).getT(1).getT(0).getT(1);                // ArrangeNew_impl::clone_cable10_t<NV>
		auto& chain126 = this->getT(0).getT(2).getT(2);                                     // ArrangeNew_impl::chain126_t<NV>
		auto& chain127 = this->getT(0).getT(2).getT(2).getT(0);                             // ArrangeNew_impl::chain127_t<NV>
		auto& chain128 = this->getT(0).getT(2).getT(2).getT(0).getT(0);                     // ArrangeNew_impl::chain128_t<NV>
		auto& split21 = this->getT(0).getT(2).getT(2).getT(0).getT(0).getT(0);              // ArrangeNew_impl::split21_t<NV>
		auto& global_mod14 = this->getT(0).getT(2).getT(2).getT(0).getT(0).getT(0).getT(0); // ArrangeNew_impl::global_mod14_t<NV>
		auto& branch15 = this->getT(0).getT(2).getT(2).getT(0).getT(0).getT(0).getT(1);     // ArrangeNew_impl::branch15_t<NV>
		auto& chain129 = this->getT(0).getT(2).getT(2).getT(0).                             // ArrangeNew_impl::chain129_t<NV>
                         getT(0).getT(0).getT(1).getT(0);
		auto& midi44 = this->getT(0).getT(2).getT(2).getT(0).                  // ArrangeNew_impl::midi44_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma85 = this->getT(0).getT(2).getT(2).getT(0).                   // ArrangeNew_impl::pma85_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add85 = this->getT(0).getT(2).getT(2).getT(0).                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain130 = this->getT(0).getT(2).getT(2).getT(0).                // ArrangeNew_impl::chain130_t<NV>
                         getT(0).getT(0).getT(1).getT(1);
		auto& midi45 = this->getT(0).getT(2).getT(2).getT(0).                  // ArrangeNew_impl::midi45_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma86 = this->getT(0).getT(2).getT(2).getT(0).                   // ArrangeNew_impl::pma86_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add86 = this->getT(0).getT(2).getT(2).getT(0).                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain131 = this->getT(0).getT(2).getT(2).getT(0).                // ArrangeNew_impl::chain131_t<NV>
                         getT(0).getT(0).getT(1).getT(2);
		auto& midi46 = this->getT(0).getT(2).getT(2).getT(0).                  // ArrangeNew_impl::midi46_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma87 = this->getT(0).getT(2).getT(2).getT(0).                   // ArrangeNew_impl::pma87_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add87 = this->getT(0).getT(2).getT(2).getT(0).                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain132 = this->getT(0).getT(2).getT(2).getT(0).                // ArrangeNew_impl::chain132_t<NV>
                         getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc42 = this->getT(0).getT(2).getT(2).getT(0).               // ArrangeNew_impl::midi_cc42_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma88 = this->getT(0).getT(2).getT(2).getT(0).                   // ArrangeNew_impl::pma88_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add88 = this->getT(0).getT(2).getT(2).getT(0).                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain133 = this->getT(0).getT(2).getT(2).getT(0).                // ArrangeNew_impl::chain133_t<NV>
                         getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc43 = this->getT(0).getT(2).getT(2).getT(0).               // ArrangeNew_impl::midi_cc43_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma89 = this->getT(0).getT(2).getT(2).getT(0).                   // ArrangeNew_impl::pma89_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add89 = this->getT(0).getT(2).getT(2).getT(0).                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain134 = this->getT(0).getT(2).getT(2).getT(0).                // ArrangeNew_impl::chain134_t<NV>
                         getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc44 = this->getT(0).getT(2).getT(2).getT(0).               // ArrangeNew_impl::midi_cc44_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma90 = this->getT(0).getT(2).getT(2).getT(0).                   // ArrangeNew_impl::pma90_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add90 = this->getT(0).getT(2).getT(2).getT(0).                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak14 = this->getT(0).getT(2).getT(2).getT(0).getT(0).getT(1);  // ArrangeNew_impl::peak14_t<NV>
		auto& clear14 = this->getT(0).getT(2).getT(2).getT(0).getT(0).getT(2); // math::clear<NV>
		auto& clone_cable11 = this->getT(0).getT(2).getT(2).getT(0).getT(1);   // ArrangeNew_impl::clone_cable11_t<NV>
		auto& clone = this->getT(1);                                           // ArrangeNew_impl::clone_t<NV>                                           // ArrangeNew_impl::clone_child_t<NV>
		auto xnode1 = this->getT(1).getT(0);                                   // ArrangeNew_impl::xnode1_t<NV>
		auto jpanner = this->getT(1).getT(1);                                  // jdsp::jpanner<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& Stages_p = this->getParameterT(0);
		Stages_p.connectT(0, clone);            // Stages -> clone::NumClones
		Stages_p.connectT(1, pack_resizer);     // Stages -> pack_resizer::NumSliders
		Stages_p.connectT(2, clone_pack);       // Stages -> clone_pack::NumClones
		Stages_p.connectT(3, clone_forward);    // Stages -> clone_forward::NumClones
		Stages_p.connectT(4, clone_forward2);   // Stages -> clone_forward2::NumClones
		Stages_p.connectT(5, clone_forward1);   // Stages -> clone_forward1::NumClones
		Stages_p.connectT(6, clone_cable);      // Stages -> clone_cable::NumClones
		Stages_p.connectT(7, clone_forward6);   // Stages -> clone_forward6::NumClones
		Stages_p.connectT(8, clone_forward7);   // Stages -> clone_forward7::NumClones
		Stages_p.connectT(9, clone_cable3);     // Stages -> clone_cable3::NumClones
		Stages_p.connectT(10, clone_cable2);    // Stages -> clone_cable2::NumClones
		Stages_p.connectT(11, clone_cable4);    // Stages -> clone_cable4::NumClones
		Stages_p.connectT(12, pack_resizer2);   // Stages -> pack_resizer2::NumSliders
		Stages_p.connectT(13, clone_pack2);     // Stages -> clone_pack2::NumClones
		Stages_p.connectT(14, clone_forward10); // Stages -> clone_forward10::NumClones
		Stages_p.connectT(15, clone_forward9);  // Stages -> clone_forward9::NumClones
		Stages_p.connectT(16, clone_forward11); // Stages -> clone_forward11::NumClones
		Stages_p.connectT(17, clone_forward15); // Stages -> clone_forward15::NumClones
		Stages_p.connectT(18, clone_forward12); // Stages -> clone_forward12::NumClones
		Stages_p.connectT(19, clone_forward13); // Stages -> clone_forward13::NumClones
		Stages_p.connectT(20, clone_forward14); // Stages -> clone_forward14::NumClones
		Stages_p.connectT(21, pack_resizer3);   // Stages -> pack_resizer3::NumSliders
		Stages_p.connectT(22, clone_pack3);     // Stages -> clone_pack3::NumClones
		Stages_p.connectT(23, clone_cable13);   // Stages -> clone_cable13::NumClones
		Stages_p.connectT(24, clone_cable10);   // Stages -> clone_cable10::NumClones
		Stages_p.connectT(25, clone_forward21); // Stages -> clone_forward21::NumClones
		Stages_p.connectT(26, clone_cable11);   // Stages -> clone_cable11::NumClones
		Stages_p.connectT(27, clone_cable14);   // Stages -> clone_cable14::NumClones
		
		this->getParameterT(1).connectT(0, global_mod); // Harm -> global_mod::Value
		
		this->getParameterT(2).connectT(0, global_mod); // HarmMod -> global_mod::Intensity
		
		this->getParameterT(3).connectT(0, global_mod); // HarmSrc -> global_mod::Index
		
		auto& HarmAux_p = this->getParameterT(4);
		HarmAux_p.connectT(0, pma1); // HarmAux -> pma1::Multiply
		HarmAux_p.connectT(1, pma2); // HarmAux -> pma2::Multiply
		HarmAux_p.connectT(2, pma3); // HarmAux -> pma3::Multiply
		HarmAux_p.connectT(3, pma4); // HarmAux -> pma4::Multiply
		HarmAux_p.connectT(4, pma5); // HarmAux -> pma5::Multiply
		HarmAux_p.connectT(5, pma6); // HarmAux -> pma6::Multiply
		
		this->getParameterT(5).connectT(0, branch1); // HarmAuxSrc -> branch1::Index
		
		this->getParameterT(6).connectT(0, clone_forward); // Min -> clone_forward::Value
		
		this->getParameterT(7).connectT(0, clone_forward2); // Max -> clone_forward2::Value
		
		this->getParameterT(8).connectT(0, clone_forward1); // Step -> clone_forward1::Value
		
		this->getParameterT(9).connectT(0, global_mod1); // Detune -> global_mod1::Value
		
		this->getParameterT(10).connectT(0, global_mod1); // DetuneMod -> global_mod1::Intensity
		
		this->getParameterT(11).connectT(0, global_mod1); // DetuneSrc -> global_mod1::Index
		
		auto& DetuneAux_p = this->getParameterT(12);
		DetuneAux_p.connectT(0, pma7);  // DetuneAux -> pma7::Multiply
		DetuneAux_p.connectT(1, pma8);  // DetuneAux -> pma8::Multiply
		DetuneAux_p.connectT(2, pma9);  // DetuneAux -> pma9::Multiply
		DetuneAux_p.connectT(3, pma10); // DetuneAux -> pma10::Multiply
		DetuneAux_p.connectT(4, pma11); // DetuneAux -> pma11::Multiply
		DetuneAux_p.connectT(5, pma12); // DetuneAux -> pma12::Multiply
		
		this->getParameterT(13).connectT(0, branch2); // DetuneAuxSrc -> branch2::Index
		
		this->getParameterT(14).connectT(0, clone_forward6); // OscType -> clone_forward6::Value
		
		this->getParameterT(15).connectT(0, global_mod3); // Shape -> global_mod3::Value
		
		this->getParameterT(16).connectT(0, global_mod3); // ShapeMod -> global_mod3::Intensity
		
		this->getParameterT(17).connectT(0, global_mod3); // ShapeSrc -> global_mod3::Index
		
		auto& ShapeAux_p = this->getParameterT(18);
		ShapeAux_p.connectT(0, pma19); // ShapeAux -> pma19::Multiply
		ShapeAux_p.connectT(1, pma20); // ShapeAux -> pma20::Multiply
		ShapeAux_p.connectT(2, pma21); // ShapeAux -> pma21::Multiply
		ShapeAux_p.connectT(3, pma22); // ShapeAux -> pma22::Multiply
		ShapeAux_p.connectT(4, pma23); // ShapeAux -> pma23::Multiply
		ShapeAux_p.connectT(5, pma24); // ShapeAux -> pma24::Multiply
		
		this->getParameterT(19).connectT(0, branch4); // ShapeAuxSrc -> branch4::Index
		
		this->getParameterT(20).connectT(0, clone_forward7); // VoiceMode -> clone_forward7::Value
		
		this->getParameterT(21).connectT(0, global_mod4); // CyclePos -> global_mod4::Value
		
		this->getParameterT(22).connectT(0, global_mod4); // CyclePosMod -> global_mod4::Intensity
		
		this->getParameterT(23).connectT(0, global_mod4); // CyclePosSrc -> global_mod4::Index
		
		auto& CyclePosAux_p = this->getParameterT(24);
		CyclePosAux_p.connectT(0, pma25); // CyclePosAux -> pma25::Multiply
		CyclePosAux_p.connectT(1, pma26); // CyclePosAux -> pma26::Multiply
		CyclePosAux_p.connectT(2, pma27); // CyclePosAux -> pma27::Multiply
		CyclePosAux_p.connectT(3, pma28); // CyclePosAux -> pma28::Multiply
		CyclePosAux_p.connectT(4, pma29); // CyclePosAux -> pma29::Multiply
		CyclePosAux_p.connectT(5, pma30); // CyclePosAux -> pma30::Multiply
		
		this->getParameterT(25).connectT(0, branch5); // CyclePosAuxSrc -> branch5::Index
		
		this->getParameterT(26).connectT(0, global_mod5); // CycleShape -> global_mod5::Value
		
		this->getParameterT(27).connectT(0, global_mod5); // CycleShapeMod -> global_mod5::Intensity
		
		this->getParameterT(28).connectT(0, global_mod5); // CycleShapeSrc -> global_mod5::Index
		
		auto& CycleShapeAux_p = this->getParameterT(29);
		CycleShapeAux_p.connectT(0, pma31); // CycleShapeAux -> pma31::Multiply
		CycleShapeAux_p.connectT(1, pma32); // CycleShapeAux -> pma32::Multiply
		CycleShapeAux_p.connectT(2, pma33); // CycleShapeAux -> pma33::Multiply
		CycleShapeAux_p.connectT(3, pma34); // CycleShapeAux -> pma34::Multiply
		CycleShapeAux_p.connectT(4, pma35); // CycleShapeAux -> pma35::Multiply
		CycleShapeAux_p.connectT(5, pma36); // CycleShapeAux -> pma36::Multiply
		
		this->getParameterT(30).connectT(0, branch6); // CycleShapeAuxSrc -> branch6::Index
		
		this->getParameterT(31).connectT(0, global_mod6); // FxValue -> global_mod6::Value
		
		this->getParameterT(32).connectT(0, global_mod6); // FxValueMod -> global_mod6::Intensity
		
		this->getParameterT(33).connectT(0, global_mod6); // FxValueSrc -> global_mod6::Index
		
		auto& FxValueAux_p = this->getParameterT(34);
		FxValueAux_p.connectT(0, pma37); // FxValueAux -> pma37::Multiply
		FxValueAux_p.connectT(1, pma38); // FxValueAux -> pma38::Multiply
		FxValueAux_p.connectT(2, pma39); // FxValueAux -> pma39::Multiply
		FxValueAux_p.connectT(3, pma40); // FxValueAux -> pma40::Multiply
		FxValueAux_p.connectT(4, pma41); // FxValueAux -> pma41::Multiply
		FxValueAux_p.connectT(5, pma42); // FxValueAux -> pma42::Multiply
		
		this->getParameterT(35).connectT(0, branch7); // FxValueAuxSrvc -> branch7::Index
		
		this->getParameterT(36).connectT(0, clone_forward10); // FxMix -> clone_forward10::Value
		
		this->getParameterT(37).connectT(0, clone_forward9); // FxDiv -> clone_forward9::Value
		
		this->getParameterT(38).connectT(0, clone_forward11); // FxSync -> clone_forward11::Value
		
		this->getParameterT(39).connectT(0, clone_forward15); // FxSinSh -> clone_forward15::Value
		
		this->getParameterT(40).connectT(0, clone_forward14); // FxSmooth -> clone_forward14::Value
		
		this->getParameterT(41).connectT(0, clone_forward12); // FxtoPitch -> clone_forward12::Value
		
		this->getParameterT(42).connectT(0, clone_forward13); // FxtoCut -> clone_forward13::Value
		
		this->getParameterT(43).connectT(0, global_mod11); // Cut -> global_mod11::Value
		
		this->getParameterT(44).connectT(0, global_mod11); // CutMod -> global_mod11::Intensity
		
		this->getParameterT(45).connectT(0, global_mod11); // CutSrc -> global_mod11::Index
		
		auto& CutAux_p = this->getParameterT(46);
		CutAux_p.connectT(0, pma67); // CutAux -> pma67::Multiply
		CutAux_p.connectT(1, pma68); // CutAux -> pma68::Multiply
		CutAux_p.connectT(2, pma69); // CutAux -> pma69::Multiply
		CutAux_p.connectT(3, pma70); // CutAux -> pma70::Multiply
		CutAux_p.connectT(4, pma71); // CutAux -> pma71::Multiply
		CutAux_p.connectT(5, pma72); // CutAux -> pma72::Multiply
		
		this->getParameterT(47).connectT(0, branch12); // CutAuxSrc -> branch12::Index
		
		this->getParameterT(48).connectT(0, clone_cable14); // FilterMode -> clone_cable14::Value
		
		this->getParameterT(49).connectT(0, global_mod13); // Res -> global_mod13::Value
		
		this->getParameterT(50).connectT(0, global_mod13); // ResMod -> global_mod13::Intensity
		
		this->getParameterT(51).connectT(0, global_mod13); // ResSrc -> global_mod13::Index
		
		auto& ResAux_p = this->getParameterT(52);
		ResAux_p.connectT(0, pma79); // ResAux -> pma79::Multiply
		ResAux_p.connectT(1, pma80); // ResAux -> pma80::Multiply
		ResAux_p.connectT(2, pma81); // ResAux -> pma81::Multiply
		ResAux_p.connectT(3, pma82); // ResAux -> pma82::Multiply
		ResAux_p.connectT(4, pma83); // ResAux -> pma83::Multiply
		ResAux_p.connectT(5, pma84); // ResAux -> pma84::Multiply
		
		this->getParameterT(53).connectT(0, branch14); // ResAuxSrc -> branch14::Index
		
		this->getParameterT(54).connectT(0, global_mod14); // FilterMix -> global_mod14::Value
		
		this->getParameterT(55).connectT(0, global_mod14); // FilterMixMod -> global_mod14::Intensity
		
		this->getParameterT(56).connectT(0, global_mod14); // FilterMixSrc -> global_mod14::Index
		
		auto& FilterMixAux_p = this->getParameterT(57);
		FilterMixAux_p.connectT(0, pma85); // FilterMixAux -> pma85::Multiply
		FilterMixAux_p.connectT(1, pma86); // FilterMixAux -> pma86::Multiply
		FilterMixAux_p.connectT(2, pma87); // FilterMixAux -> pma87::Multiply
		FilterMixAux_p.connectT(3, pma88); // FilterMixAux -> pma88::Multiply
		FilterMixAux_p.connectT(4, pma89); // FilterMixAux -> pma89::Multiply
		FilterMixAux_p.connectT(5, pma90); // FilterMixAux -> pma90::Multiply
		
		this->getParameterT(58).connectT(0, branch15); // FilterMixAuxSrc -> branch15::Index
		
		this->getParameterT(59).connectT(0, clone_cable13); // Spread -> clone_cable13::Value
		
		this->getParameterT(60).connectT(0, clone_forward21); // Snap -> clone_forward21::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma1.getWrappedObject().getParameter().connectT(0, add1);              // pma1 -> add1::Value
		midi1.getParameter().connectT(0, pma1);                                // midi1 -> pma1::Value
		pma2.getWrappedObject().getParameter().connectT(0, add2);              // pma2 -> add2::Value
		midi2.getParameter().connectT(0, pma2);                                // midi2 -> pma2::Value
		pma3.getWrappedObject().getParameter().connectT(0, add3);              // pma3 -> add3::Value
		midi3.getParameter().connectT(0, pma3);                                // midi3 -> pma3::Value
		pma4.getWrappedObject().getParameter().connectT(0, add4);              // pma4 -> add4::Value
		midi_cc.getWrappedObject().getParameter().connectT(0, pma4);           // midi_cc -> pma4::Value
		pma5.getWrappedObject().getParameter().connectT(0, add5);              // pma5 -> add5::Value
		midi_cc1.getWrappedObject().getParameter().connectT(0, pma5);          // midi_cc1 -> pma5::Value
		pma6.getWrappedObject().getParameter().connectT(0, add6);              // pma6 -> add6::Value
		midi_cc2.getWrappedObject().getParameter().connectT(0, pma6);          // midi_cc2 -> pma6::Value
		clone_pack.getWrappedObject().getParameter().connectT(0, xnode1);      // clone_pack -> xnode1::Harm
		peak.getParameter().connectT(0, clone_pack);                           // peak -> clone_pack::Value
		clone_forward.getWrappedObject().getParameter().connectT(0, xnode1);   // clone_forward -> xnode1::min
		clone_forward2.getWrappedObject().getParameter().connectT(0, xnode1);  // clone_forward2 -> xnode1::max
		clone_forward1.getWrappedObject().getParameter().connectT(0, xnode1);  // clone_forward1 -> xnode1::step
		clone_forward6.getWrappedObject().getParameter().connectT(0, xnode1);  // clone_forward6 -> xnode1::Mode
		clone_forward7.getWrappedObject().getParameter().connectT(0, xnode1);  // clone_forward7 -> xnode1::TYPE
		pma7.getWrappedObject().getParameter().connectT(0, add7);              // pma7 -> add7::Value
		midi5.getParameter().connectT(0, pma7);                                // midi5 -> pma7::Value
		pma8.getWrappedObject().getParameter().connectT(0, add8);              // pma8 -> add8::Value
		midi6.getParameter().connectT(0, pma8);                                // midi6 -> pma8::Value
		pma9.getWrappedObject().getParameter().connectT(0, add9);              // pma9 -> add9::Value
		midi7.getParameter().connectT(0, pma9);                                // midi7 -> pma9::Value
		pma10.getWrappedObject().getParameter().connectT(0, add10);            // pma10 -> add10::Value
		midi_cc3.getWrappedObject().getParameter().connectT(0, pma10);         // midi_cc3 -> pma10::Value
		pma11.getWrappedObject().getParameter().connectT(0, add11);            // pma11 -> add11::Value
		midi_cc4.getWrappedObject().getParameter().connectT(0, pma11);         // midi_cc4 -> pma11::Value
		pma12.getWrappedObject().getParameter().connectT(0, add12);            // pma12 -> add12::Value
		midi_cc5.getWrappedObject().getParameter().connectT(0, pma12);         // midi_cc5 -> pma12::Value
		clone_cable.getWrappedObject().getParameter().connectT(0, xnode1);     // clone_cable -> xnode1::DET
		peak1.getParameter().connectT(0, clone_cable);                         // peak1 -> clone_cable::Value
		pma19.getWrappedObject().getParameter().connectT(0, add19);            // pma19 -> add19::Value
		midi11.getParameter().connectT(0, pma19);                              // midi11 -> pma19::Value
		pma20.getWrappedObject().getParameter().connectT(0, add20);            // pma20 -> add20::Value
		midi12.getParameter().connectT(0, pma20);                              // midi12 -> pma20::Value
		pma21.getWrappedObject().getParameter().connectT(0, add21);            // pma21 -> add21::Value
		midi13.getParameter().connectT(0, pma21);                              // midi13 -> pma21::Value
		pma22.getWrappedObject().getParameter().connectT(0, add22);            // pma22 -> add22::Value
		midi_cc9.getWrappedObject().getParameter().connectT(0, pma22);         // midi_cc9 -> pma22::Value
		pma23.getWrappedObject().getParameter().connectT(0, add23);            // pma23 -> add23::Value
		midi_cc10.getWrappedObject().getParameter().connectT(0, pma23);        // midi_cc10 -> pma23::Value
		pma24.getWrappedObject().getParameter().connectT(0, add24);            // pma24 -> add24::Value
		midi_cc11.getWrappedObject().getParameter().connectT(0, pma24);        // midi_cc11 -> pma24::Value
		clone_cable2.getWrappedObject().getParameter().connectT(0, xnode1);    // clone_cable2 -> xnode1::OscShapes
		peak3.getParameter().connectT(0, clone_cable2);                        // peak3 -> clone_cable2::Value
		pma25.getWrappedObject().getParameter().connectT(0, add25);            // pma25 -> add25::Value
		midi14.getParameter().connectT(0, pma25);                              // midi14 -> pma25::Value
		pma26.getWrappedObject().getParameter().connectT(0, add26);            // pma26 -> add26::Value
		midi15.getParameter().connectT(0, pma26);                              // midi15 -> pma26::Value
		pma27.getWrappedObject().getParameter().connectT(0, add27);            // pma27 -> add27::Value
		midi16.getParameter().connectT(0, pma27);                              // midi16 -> pma27::Value
		pma28.getWrappedObject().getParameter().connectT(0, add28);            // pma28 -> add28::Value
		midi_cc12.getWrappedObject().getParameter().connectT(0, pma28);        // midi_cc12 -> pma28::Value
		pma29.getWrappedObject().getParameter().connectT(0, add29);            // pma29 -> add29::Value
		midi_cc13.getWrappedObject().getParameter().connectT(0, pma29);        // midi_cc13 -> pma29::Value
		pma30.getWrappedObject().getParameter().connectT(0, add30);            // pma30 -> add30::Value
		midi_cc14.getWrappedObject().getParameter().connectT(0, pma30);        // midi_cc14 -> pma30::Value
		clone_cable3.getWrappedObject().getParameter().connectT(0, xnode1);    // clone_cable3 -> xnode1::UserPs
		peak4.getParameter().connectT(0, clone_cable3);                        // peak4 -> clone_cable3::Value
		pma31.getWrappedObject().getParameter().connectT(0, add31);            // pma31 -> add31::Value
		midi17.getParameter().connectT(0, pma31);                              // midi17 -> pma31::Value
		pma32.getWrappedObject().getParameter().connectT(0, add32);            // pma32 -> add32::Value
		midi18.getParameter().connectT(0, pma32);                              // midi18 -> pma32::Value
		pma33.getWrappedObject().getParameter().connectT(0, add33);            // pma33 -> add33::Value
		midi19.getParameter().connectT(0, pma33);                              // midi19 -> pma33::Value
		pma34.getWrappedObject().getParameter().connectT(0, add34);            // pma34 -> add34::Value
		midi_cc15.getWrappedObject().getParameter().connectT(0, pma34);        // midi_cc15 -> pma34::Value
		pma35.getWrappedObject().getParameter().connectT(0, add35);            // pma35 -> add35::Value
		midi_cc16.getWrappedObject().getParameter().connectT(0, pma35);        // midi_cc16 -> pma35::Value
		pma36.getWrappedObject().getParameter().connectT(0, add36);            // pma36 -> add36::Value
		midi_cc17.getWrappedObject().getParameter().connectT(0, pma36);        // midi_cc17 -> pma36::Value
		clone_cable4.getWrappedObject().getParameter().connectT(0, xnode1);    // clone_cable4 -> xnode1::UserInput
		peak5.getParameter().connectT(0, clone_cable4);                        // peak5 -> clone_cable4::Value
		pma37.getWrappedObject().getParameter().connectT(0, add37);            // pma37 -> add37::Value
		midi20.getParameter().connectT(0, pma37);                              // midi20 -> pma37::Value
		pma38.getWrappedObject().getParameter().connectT(0, add38);            // pma38 -> add38::Value
		midi21.getParameter().connectT(0, pma38);                              // midi21 -> pma38::Value
		pma39.getWrappedObject().getParameter().connectT(0, add39);            // pma39 -> add39::Value
		midi22.getParameter().connectT(0, pma39);                              // midi22 -> pma39::Value
		pma40.getWrappedObject().getParameter().connectT(0, add40);            // pma40 -> add40::Value
		midi_cc18.getWrappedObject().getParameter().connectT(0, pma40);        // midi_cc18 -> pma40::Value
		pma41.getWrappedObject().getParameter().connectT(0, add41);            // pma41 -> add41::Value
		midi_cc19.getWrappedObject().getParameter().connectT(0, pma41);        // midi_cc19 -> pma41::Value
		pma42.getWrappedObject().getParameter().connectT(0, add42);            // pma42 -> add42::Value
		midi_cc20.getWrappedObject().getParameter().connectT(0, pma42);        // midi_cc20 -> pma42::Value
		clone_pack2.getWrappedObject().getParameter().connectT(0, xnode1);     // clone_pack2 -> xnode1::FxValue
		peak6.getParameter().connectT(0, clone_pack2);                         // peak6 -> clone_pack2::Value
		clone_forward10.getWrappedObject().getParameter().connectT(0, xnode1); // clone_forward10 -> xnode1::FxMix
		clone_forward9.getWrappedObject().getParameter().connectT(0, xnode1);  // clone_forward9 -> xnode1::FxShDiv
		clone_forward11.getWrappedObject().getParameter().connectT(0, xnode1); // clone_forward11 -> xnode1::FxShSync
		clone_forward15.getWrappedObject().getParameter().connectT(0, xnode1); // clone_forward15 -> xnode1::ShSinMix
		clone_forward12.getWrappedObject().getParameter().connectT(0, xnode1); // clone_forward12 -> xnode1::shPitch
		clone_forward13.getWrappedObject().getParameter().connectT(0, xnode1); // clone_forward13 -> xnode1::FilterFxMod
		clone_forward14.getWrappedObject().getParameter().connectT(0, xnode1); // clone_forward14 -> xnode1::ShSmooth
		pma67.getWrappedObject().getParameter().connectT(0, add67);            // pma67 -> add67::Value
		midi35.getParameter().connectT(0, pma67);                              // midi35 -> pma67::Value
		pma68.getWrappedObject().getParameter().connectT(0, add68);            // pma68 -> add68::Value
		midi36.getParameter().connectT(0, pma68);                              // midi36 -> pma68::Value
		pma69.getWrappedObject().getParameter().connectT(0, add69);            // pma69 -> add69::Value
		midi37.getParameter().connectT(0, pma69);                              // midi37 -> pma69::Value
		pma70.getWrappedObject().getParameter().connectT(0, add70);            // pma70 -> add70::Value
		midi_cc33.getWrappedObject().getParameter().connectT(0, pma70);        // midi_cc33 -> pma70::Value
		pma71.getWrappedObject().getParameter().connectT(0, add71);            // pma71 -> add71::Value
		midi_cc34.getWrappedObject().getParameter().connectT(0, pma71);        // midi_cc34 -> pma71::Value
		pma72.getWrappedObject().getParameter().connectT(0, add72);            // pma72 -> add72::Value
		midi_cc35.getWrappedObject().getParameter().connectT(0, pma72);        // midi_cc35 -> pma72::Value
		clone_pack3.getWrappedObject().getParameter().connectT(0, xnode1);     // clone_pack3 -> xnode1::FilterCut
		peak11.getParameter().connectT(0, clone_pack3);                        // peak11 -> clone_pack3::Value
		clone_cable14.getWrappedObject().getParameter().connectT(0, xnode1);   // clone_cable14 -> xnode1::FilterType
		clone_forward21.getWrappedObject().getParameter().connectT(0, xnode1); // clone_forward21 -> xnode1::snap
		clone_cable13.getWrappedObject().getParameter().connectT(0, jpanner);  // clone_cable13 -> jpanner::Pan
		pma79.getWrappedObject().getParameter().connectT(0, add79);            // pma79 -> add79::Value
		midi41.getParameter().connectT(0, pma79);                              // midi41 -> pma79::Value
		pma80.getWrappedObject().getParameter().connectT(0, add80);            // pma80 -> add80::Value
		midi42.getParameter().connectT(0, pma80);                              // midi42 -> pma80::Value
		pma81.getWrappedObject().getParameter().connectT(0, add81);            // pma81 -> add81::Value
		midi43.getParameter().connectT(0, pma81);                              // midi43 -> pma81::Value
		pma82.getWrappedObject().getParameter().connectT(0, add82);            // pma82 -> add82::Value
		midi_cc39.getWrappedObject().getParameter().connectT(0, pma82);        // midi_cc39 -> pma82::Value
		pma83.getWrappedObject().getParameter().connectT(0, add83);            // pma83 -> add83::Value
		midi_cc40.getWrappedObject().getParameter().connectT(0, pma83);        // midi_cc40 -> pma83::Value
		pma84.getWrappedObject().getParameter().connectT(0, add84);            // pma84 -> add84::Value
		midi_cc41.getWrappedObject().getParameter().connectT(0, pma84);        // midi_cc41 -> pma84::Value
		clone_cable10.getWrappedObject().getParameter().connectT(0, xnode1);   // clone_cable10 -> xnode1::FilterRes
		peak13.getParameter().connectT(0, clone_cable10);                      // peak13 -> clone_cable10::Value
		pma85.getWrappedObject().getParameter().connectT(0, add85);            // pma85 -> add85::Value
		midi44.getParameter().connectT(0, pma85);                              // midi44 -> pma85::Value
		pma86.getWrappedObject().getParameter().connectT(0, add86);            // pma86 -> add86::Value
		midi45.getParameter().connectT(0, pma86);                              // midi45 -> pma86::Value
		pma87.getWrappedObject().getParameter().connectT(0, add87);            // pma87 -> add87::Value
		midi46.getParameter().connectT(0, pma87);                              // midi46 -> pma87::Value
		pma88.getWrappedObject().getParameter().connectT(0, add88);            // pma88 -> add88::Value
		midi_cc42.getWrappedObject().getParameter().connectT(0, pma88);        // midi_cc42 -> pma88::Value
		pma89.getWrappedObject().getParameter().connectT(0, add89);            // pma89 -> add89::Value
		midi_cc43.getWrappedObject().getParameter().connectT(0, pma89);        // midi_cc43 -> pma89::Value
		pma90.getWrappedObject().getParameter().connectT(0, add90);            // pma90 -> add90::Value
		midi_cc44.getWrappedObject().getParameter().connectT(0, pma90);        // midi_cc44 -> pma90::Value
		clone_cable11.getWrappedObject().getParameter().connectT(0, xnode1);   // clone_cable11 -> xnode1::FilterMix
		peak14.getParameter().connectT(0, clone_cable11);                      // peak14 -> clone_cable11::Value
		
		// Default Values --------------------------------------------------------------------------
		
		;                                // global_mod::Index is automated
		;                                // global_mod::Value is automated
		global_mod.setParameterT(2, 1.); // core::global_mod::ProcessSignal
		global_mod.setParameterT(3, 1.); // core::global_mod::Mode
		;                                // global_mod::Intensity is automated
		
		; // branch1::Index is automated
		
		;                          // pma1::Value is automated
		;                          // pma1::Multiply is automated
		pma1.setParameterT(2, 0.); // control::pma::Add
		
		; // add1::Value is automated
		
		;                          // pma2::Value is automated
		;                          // pma2::Multiply is automated
		pma2.setParameterT(2, 0.); // control::pma::Add
		
		; // add2::Value is automated
		
		;                          // pma3::Value is automated
		;                          // pma3::Multiply is automated
		pma3.setParameterT(2, 0.); // control::pma::Add
		
		; // add3::Value is automated
		
		midi_cc.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		;                          // pma4::Value is automated
		;                          // pma4::Multiply is automated
		pma4.setParameterT(2, 0.); // control::pma::Add
		
		; // add4::Value is automated
		
		midi_cc1.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc1.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc1.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                          // pma5::Value is automated
		;                          // pma5::Multiply is automated
		pma5.setParameterT(2, 0.); // control::pma::Add
		
		; // add5::Value is automated
		
		midi_cc2.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc2.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc2.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                          // pma6::Value is automated
		;                          // pma6::Multiply is automated
		pma6.setParameterT(2, 0.); // control::pma::Add
		
		; // add6::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // pack_resizer::NumSliders is automated
		
		; // clone_pack::NumClones is automated
		; // clone_pack::Value is automated
		
		; // clone_forward::NumClones is automated
		; // clone_forward::Value is automated
		
		; // clone_forward2::NumClones is automated
		; // clone_forward2::Value is automated
		
		; // clone_forward1::NumClones is automated
		; // clone_forward1::Value is automated
		
		; // clone_forward6::NumClones is automated
		; // clone_forward6::Value is automated
		
		; // clone_forward7::NumClones is automated
		; // clone_forward7::Value is automated
		
		;                                 // global_mod1::Index is automated
		;                                 // global_mod1::Value is automated
		global_mod1.setParameterT(2, 1.); // core::global_mod::ProcessSignal
		global_mod1.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod1::Intensity is automated
		
		; // branch2::Index is automated
		
		;                          // pma7::Value is automated
		;                          // pma7::Multiply is automated
		pma7.setParameterT(2, 0.); // control::pma::Add
		
		; // add7::Value is automated
		
		;                          // pma8::Value is automated
		;                          // pma8::Multiply is automated
		pma8.setParameterT(2, 0.); // control::pma::Add
		
		; // add8::Value is automated
		
		;                          // pma9::Value is automated
		;                          // pma9::Multiply is automated
		pma9.setParameterT(2, 0.); // control::pma::Add
		
		; // add9::Value is automated
		
		midi_cc3.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc3.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc3.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		;                           // pma10::Value is automated
		;                           // pma10::Multiply is automated
		pma10.setParameterT(2, 0.); // control::pma::Add
		
		; // add10::Value is automated
		
		midi_cc4.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc4.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc4.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma11::Value is automated
		;                           // pma11::Multiply is automated
		pma11.setParameterT(2, 0.); // control::pma::Add
		
		; // add11::Value is automated
		
		midi_cc5.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc5.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc5.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma12::Value is automated
		;                           // pma12::Multiply is automated
		pma12.setParameterT(2, 0.); // control::pma::Add
		
		; // add12::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		;                                 // clone_cable::NumClones is automated
		;                                 // clone_cable::Value is automated
		clone_cable.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                 // global_mod3::Index is automated
		;                                 // global_mod3::Value is automated
		global_mod3.setParameterT(2, 1.); // core::global_mod::ProcessSignal
		global_mod3.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod3::Intensity is automated
		
		; // branch4::Index is automated
		
		;                           // pma19::Value is automated
		;                           // pma19::Multiply is automated
		pma19.setParameterT(2, 0.); // control::pma::Add
		
		; // add19::Value is automated
		
		;                           // pma20::Value is automated
		;                           // pma20::Multiply is automated
		pma20.setParameterT(2, 0.); // control::pma::Add
		
		; // add20::Value is automated
		
		;                           // pma21::Value is automated
		;                           // pma21::Multiply is automated
		pma21.setParameterT(2, 0.); // control::pma::Add
		
		; // add21::Value is automated
		
		midi_cc9.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc9.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc9.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		;                           // pma22::Value is automated
		;                           // pma22::Multiply is automated
		pma22.setParameterT(2, 0.); // control::pma::Add
		
		; // add22::Value is automated
		
		midi_cc10.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc10.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc10.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma23::Value is automated
		;                           // pma23::Multiply is automated
		pma23.setParameterT(2, 0.); // control::pma::Add
		
		; // add23::Value is automated
		
		midi_cc11.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc11.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc11.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma24::Value is automated
		;                           // pma24::Multiply is automated
		pma24.setParameterT(2, 0.); // control::pma::Add
		
		; // add24::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		;                                  // clone_cable2::NumClones is automated
		;                                  // clone_cable2::Value is automated
		clone_cable2.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                 // global_mod4::Index is automated
		;                                 // global_mod4::Value is automated
		global_mod4.setParameterT(2, 1.); // core::global_mod::ProcessSignal
		global_mod4.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod4::Intensity is automated
		
		; // branch5::Index is automated
		
		;                           // pma25::Value is automated
		;                           // pma25::Multiply is automated
		pma25.setParameterT(2, 0.); // control::pma::Add
		
		; // add25::Value is automated
		
		;                           // pma26::Value is automated
		;                           // pma26::Multiply is automated
		pma26.setParameterT(2, 0.); // control::pma::Add
		
		; // add26::Value is automated
		
		;                           // pma27::Value is automated
		;                           // pma27::Multiply is automated
		pma27.setParameterT(2, 0.); // control::pma::Add
		
		; // add27::Value is automated
		
		midi_cc12.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc12.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc12.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		;                           // pma28::Value is automated
		;                           // pma28::Multiply is automated
		pma28.setParameterT(2, 0.); // control::pma::Add
		
		; // add28::Value is automated
		
		midi_cc13.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc13.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc13.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma29::Value is automated
		;                           // pma29::Multiply is automated
		pma29.setParameterT(2, 0.); // control::pma::Add
		
		; // add29::Value is automated
		
		midi_cc14.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc14.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc14.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma30::Value is automated
		;                           // pma30::Multiply is automated
		pma30.setParameterT(2, 0.); // control::pma::Add
		
		; // add30::Value is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		;                                  // clone_cable3::NumClones is automated
		;                                  // clone_cable3::Value is automated
		clone_cable3.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                 // global_mod5::Index is automated
		;                                 // global_mod5::Value is automated
		global_mod5.setParameterT(2, 1.); // core::global_mod::ProcessSignal
		global_mod5.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod5::Intensity is automated
		
		; // branch6::Index is automated
		
		;                           // pma31::Value is automated
		;                           // pma31::Multiply is automated
		pma31.setParameterT(2, 0.); // control::pma::Add
		
		; // add31::Value is automated
		
		;                           // pma32::Value is automated
		;                           // pma32::Multiply is automated
		pma32.setParameterT(2, 0.); // control::pma::Add
		
		; // add32::Value is automated
		
		;                           // pma33::Value is automated
		;                           // pma33::Multiply is automated
		pma33.setParameterT(2, 0.); // control::pma::Add
		
		; // add33::Value is automated
		
		midi_cc15.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc15.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc15.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		;                           // pma34::Value is automated
		;                           // pma34::Multiply is automated
		pma34.setParameterT(2, 0.); // control::pma::Add
		
		; // add34::Value is automated
		
		midi_cc16.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc16.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc16.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma35::Value is automated
		;                           // pma35::Multiply is automated
		pma35.setParameterT(2, 0.); // control::pma::Add
		
		; // add35::Value is automated
		
		midi_cc17.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc17.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc17.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma36::Value is automated
		;                           // pma36::Multiply is automated
		pma36.setParameterT(2, 0.); // control::pma::Add
		
		; // add36::Value is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		;                                  // clone_cable4::NumClones is automated
		;                                  // clone_cable4::Value is automated
		clone_cable4.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                 // global_mod6::Index is automated
		;                                 // global_mod6::Value is automated
		global_mod6.setParameterT(2, 1.); // core::global_mod::ProcessSignal
		global_mod6.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod6::Intensity is automated
		
		; // branch7::Index is automated
		
		;                           // pma37::Value is automated
		;                           // pma37::Multiply is automated
		pma37.setParameterT(2, 0.); // control::pma::Add
		
		; // add37::Value is automated
		
		;                           // pma38::Value is automated
		;                           // pma38::Multiply is automated
		pma38.setParameterT(2, 0.); // control::pma::Add
		
		; // add38::Value is automated
		
		;                           // pma39::Value is automated
		;                           // pma39::Multiply is automated
		pma39.setParameterT(2, 0.); // control::pma::Add
		
		; // add39::Value is automated
		
		midi_cc18.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc18.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc18.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		;                           // pma40::Value is automated
		;                           // pma40::Multiply is automated
		pma40.setParameterT(2, 0.); // control::pma::Add
		
		; // add40::Value is automated
		
		midi_cc19.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc19.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc19.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma41::Value is automated
		;                           // pma41::Multiply is automated
		pma41.setParameterT(2, 0.); // control::pma::Add
		
		; // add41::Value is automated
		
		midi_cc20.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc20.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc20.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma42::Value is automated
		;                           // pma42::Multiply is automated
		pma42.setParameterT(2, 0.); // control::pma::Add
		
		; // add42::Value is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		; // pack_resizer2::NumSliders is automated
		
		; // clone_pack2::NumClones is automated
		; // clone_pack2::Value is automated
		
		; // clone_forward10::NumClones is automated
		; // clone_forward10::Value is automated
		
		; // clone_forward9::NumClones is automated
		; // clone_forward9::Value is automated
		
		; // clone_forward11::NumClones is automated
		; // clone_forward11::Value is automated
		
		; // clone_forward15::NumClones is automated
		; // clone_forward15::Value is automated
		
		; // clone_forward12::NumClones is automated
		; // clone_forward12::Value is automated
		
		; // clone_forward13::NumClones is automated
		; // clone_forward13::Value is automated
		
		; // clone_forward14::NumClones is automated
		; // clone_forward14::Value is automated
		
		;                                  // global_mod11::Index is automated
		;                                  // global_mod11::Value is automated
		global_mod11.setParameterT(2, 1.); // core::global_mod::ProcessSignal
		global_mod11.setParameterT(3, 1.); // core::global_mod::Mode
		;                                  // global_mod11::Intensity is automated
		
		; // branch12::Index is automated
		
		;                           // pma67::Value is automated
		;                           // pma67::Multiply is automated
		pma67.setParameterT(2, 0.); // control::pma::Add
		
		; // add67::Value is automated
		
		;                           // pma68::Value is automated
		;                           // pma68::Multiply is automated
		pma68.setParameterT(2, 0.); // control::pma::Add
		
		; // add68::Value is automated
		
		;                           // pma69::Value is automated
		;                           // pma69::Multiply is automated
		pma69.setParameterT(2, 0.); // control::pma::Add
		
		; // add69::Value is automated
		
		midi_cc33.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc33.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc33.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		;                           // pma70::Value is automated
		;                           // pma70::Multiply is automated
		pma70.setParameterT(2, 0.); // control::pma::Add
		
		; // add70::Value is automated
		
		midi_cc34.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc34.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc34.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma71::Value is automated
		;                           // pma71::Multiply is automated
		pma71.setParameterT(2, 0.); // control::pma::Add
		
		; // add71::Value is automated
		
		midi_cc35.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc35.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc35.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma72::Value is automated
		;                           // pma72::Multiply is automated
		pma72.setParameterT(2, 0.); // control::pma::Add
		
		; // add72::Value is automated
		
		clear11.setParameterT(0, 0.); // math::clear::Value
		
		; // pack_resizer3::NumSliders is automated
		
		; // clone_pack3::NumClones is automated
		; // clone_pack3::Value is automated
		
		;                                   // clone_cable14::NumClones is automated
		;                                   // clone_cable14::Value is automated
		clone_cable14.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // clone_forward21::NumClones is automated
		; // clone_forward21::Value is automated
		
		;                                   // clone_cable13::NumClones is automated
		;                                   // clone_cable13::Value is automated
		clone_cable13.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // global_mod13::Index is automated
		;                                  // global_mod13::Value is automated
		global_mod13.setParameterT(2, 1.); // core::global_mod::ProcessSignal
		global_mod13.setParameterT(3, 1.); // core::global_mod::Mode
		;                                  // global_mod13::Intensity is automated
		
		; // branch14::Index is automated
		
		;                           // pma79::Value is automated
		;                           // pma79::Multiply is automated
		pma79.setParameterT(2, 0.); // control::pma::Add
		
		; // add79::Value is automated
		
		;                           // pma80::Value is automated
		;                           // pma80::Multiply is automated
		pma80.setParameterT(2, 0.); // control::pma::Add
		
		; // add80::Value is automated
		
		;                           // pma81::Value is automated
		;                           // pma81::Multiply is automated
		pma81.setParameterT(2, 0.); // control::pma::Add
		
		; // add81::Value is automated
		
		midi_cc39.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc39.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc39.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		;                           // pma82::Value is automated
		;                           // pma82::Multiply is automated
		pma82.setParameterT(2, 0.); // control::pma::Add
		
		; // add82::Value is automated
		
		midi_cc40.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc40.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc40.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma83::Value is automated
		;                           // pma83::Multiply is automated
		pma83.setParameterT(2, 0.); // control::pma::Add
		
		; // add83::Value is automated
		
		midi_cc41.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc41.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc41.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma84::Value is automated
		;                           // pma84::Multiply is automated
		pma84.setParameterT(2, 0.); // control::pma::Add
		
		; // add84::Value is automated
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // clone_cable10::NumClones is automated
		;                                   // clone_cable10::Value is automated
		clone_cable10.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // global_mod14::Index is automated
		;                                  // global_mod14::Value is automated
		global_mod14.setParameterT(2, 1.); // core::global_mod::ProcessSignal
		global_mod14.setParameterT(3, 1.); // core::global_mod::Mode
		;                                  // global_mod14::Intensity is automated
		
		; // branch15::Index is automated
		
		;                           // pma85::Value is automated
		;                           // pma85::Multiply is automated
		pma85.setParameterT(2, 0.); // control::pma::Add
		
		; // add85::Value is automated
		
		;                           // pma86::Value is automated
		;                           // pma86::Multiply is automated
		pma86.setParameterT(2, 0.); // control::pma::Add
		
		; // add86::Value is automated
		
		;                           // pma87::Value is automated
		;                           // pma87::Multiply is automated
		pma87.setParameterT(2, 0.); // control::pma::Add
		
		; // add87::Value is automated
		
		midi_cc42.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc42.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc42.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		;                           // pma88::Value is automated
		;                           // pma88::Multiply is automated
		pma88.setParameterT(2, 0.); // control::pma::Add
		
		; // add88::Value is automated
		
		midi_cc43.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc43.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc43.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma89::Value is automated
		;                           // pma89::Multiply is automated
		pma89.setParameterT(2, 0.); // control::pma::Add
		
		; // add89::Value is automated
		
		midi_cc44.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc44.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc44.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                           // pma90::Value is automated
		;                           // pma90::Multiply is automated
		pma90.setParameterT(2, 0.); // control::pma::Add
		
		; // add90::Value is automated
		
		clear14.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // clone_cable11::NumClones is automated
		;                                   // clone_cable11::Value is automated
		clone_cable11.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                           // clone::NumClones is automated
		clone.setParameterT(1, 2.); // container::clone::SplitSignal
		
		; // xnode1::Harm is automated
		; // xnode1::min is automated
		; // xnode1::max is automated
		; // xnode1::step is automated
		; // xnode1::Mode is automated
		; // xnode1::FxMix is automated
		; // xnode1::FxValue is automated
		; // xnode1::FxShDiv is automated
		; // xnode1::FxShSync is automated
		; // xnode1::shPitch is automated
		; // xnode1::FilterMix is automated
		; // xnode1::FilterType is automated
		; // xnode1::FilterRes is automated
		; // xnode1::FilterCut is automated
		; // xnode1::FilterFxMod is automated
		; // xnode1::DET is automated
		; // xnode1::ShSmooth is automated
		; // xnode1::OscShapes is automated
		; // xnode1::TYPE is automated
		; // xnode1::ShSinMix is automated
		; // xnode1::UserPs is automated
		; // xnode1::UserInput is automated
		; // xnode1::snap is automated
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		this->setParameterT(0, 32.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 16.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 0.03);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 0.00129907);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 0.550515);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 0.);
		this->setParameterT(19, 1.);
		this->setParameterT(20, 2.);
		this->setParameterT(21, 0.15);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 1.);
		this->setParameterT(24, 0.);
		this->setParameterT(25, 1.);
		this->setParameterT(26, 0.4);
		this->setParameterT(27, 0.);
		this->setParameterT(28, 1.);
		this->setParameterT(29, -0.28);
		this->setParameterT(30, 3.);
		this->setParameterT(31, 1.);
		this->setParameterT(32, 0.);
		this->setParameterT(33, 3.);
		this->setParameterT(34, 0.);
		this->setParameterT(35, 1.);
		this->setParameterT(36, 0.);
		this->setParameterT(37, 32.);
		this->setParameterT(38, 1.);
		this->setParameterT(39, 0.);
		this->setParameterT(40, 5.27344);
		this->setParameterT(41, 0.08);
		this->setParameterT(42, 0.11);
		this->setParameterT(43, 1.);
		this->setParameterT(44, 0.);
		this->setParameterT(45, 1.);
		this->setParameterT(46, 0.);
		this->setParameterT(47, 1.);
		this->setParameterT(48, 1.);
		this->setParameterT(49, 1.);
		this->setParameterT(50, 0.);
		this->setParameterT(51, 1.);
		this->setParameterT(52, 0.);
		this->setParameterT(53, 1.);
		this->setParameterT(54, 0.97);
		this->setParameterT(55, 0.);
		this->setParameterT(56, 1.);
		this->setParameterT(57, 0.);
		this->setParameterT(58, 1.);
		this->setParameterT(59, 0.347286);
		this->setParameterT(60, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // ArrangeNew_impl::global_mod_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // ArrangeNew_impl::global_mod1_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // ArrangeNew_impl::global_mod3_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // ArrangeNew_impl::global_mod4_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // ArrangeNew_impl::global_mod5_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // ArrangeNew_impl::global_mod6_t<NV>
		this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // ArrangeNew_impl::global_mod11_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // ArrangeNew_impl::global_mod13_t<NV>
		this->getT(0).getT(2).getT(2).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // ArrangeNew_impl::global_mod14_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // ArrangeNew_impl::global_mod_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);                 // ArrangeNew_impl::pack_resizer_t
		this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);         // ArrangeNew_impl::clone_pack_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // ArrangeNew_impl::global_mod1_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // ArrangeNew_impl::global_mod3_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // ArrangeNew_impl::global_mod4_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak4_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // ArrangeNew_impl::global_mod5_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak5_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // ArrangeNew_impl::global_mod6_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak6_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);                 // ArrangeNew_impl::pack_resizer2_t
		this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);         // ArrangeNew_impl::clone_pack2_t<NV>
		this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // ArrangeNew_impl::global_mod11_t<NV>
		this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak11_t<NV>
		this->getT(0).getT(2).getT(0).getT(0).getT(1).setExternalData(b, index);                 // ArrangeNew_impl::pack_resizer3_t
		this->getT(0).getT(2).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);         // ArrangeNew_impl::clone_pack3_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // ArrangeNew_impl::global_mod13_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak13_t<NV>
		this->getT(0).getT(2).getT(2).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // ArrangeNew_impl::global_mod14_t<NV>
		this->getT(0).getT(2).getT(2).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak14_t<NV>
		this->getT(1).getT(0).setExternalData(b, index);                                         // ArrangeNew_impl::xnode1_t<NV>
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
using ArrangeNew = wrap::node<ArrangeNew_impl::instance<NV>>;
}


