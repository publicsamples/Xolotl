#pragma once

#include "Env2.h"
#include "Env2.h"
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

struct Env3_t_matrix
{
	static const int NumTables = 1;
	static const int NumSliderPacks = 0;
	static const int NumAudioFiles = 0;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 0;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][1] =
	{
		{ 1 },  //  | 0->1
		{ -1 }, // 
		{ -1 }  // 
	};
	
	const span<dyn<float>, 0> embeddedData = { };
};

template <int NV>
using Env3_t = wrap::data<project::Env2<NV>, 
                          data::matrix<Env3_t_matrix>>;

template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<math::add<NV>, 0>>;

template <int NV> using pma14_t = pma_t<NV>;

template <int NV> using pma16_t = pma_t<NV>;

template <int NV> using pma18_t = pma_t<NV>;

template <int NV> using pma44_t = pma_t<NV>;

template <int NV> using pma46_t = pma_t<NV>;

template <int NV> using pma48_t = pma_t<NV>;

template <int NV> using pma50_t = pma_t<NV>;

template <int NV> using pma52_t = pma_t<NV>;

template <int NV>
using peak2_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma_t<NV>, 0>, 
                                   parameter::plain<pma14_t<NV>, 0>, 
                                   parameter::plain<pma16_t<NV>, 0>, 
                                   parameter::plain<pma18_t<NV>, 0>, 
                                   parameter::plain<pma44_t<NV>, 0>, 
                                   parameter::plain<pma46_t<NV>, 0>, 
                                   parameter::plain<pma48_t<NV>, 0>, 
                                   parameter::plain<pma50_t<NV>, 0>, 
                                   parameter::plain<pma52_t<NV>, 0>>;

template <int NV>
using peak2_t = wrap::mod<peak2_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, Env3_t<NV>>, 
                                  peak2_t<NV>, 
                                  math::clear<NV>>;

struct Env4_t_matrix
{
	static const int NumTables = 1;
	static const int NumSliderPacks = 0;
	static const int NumAudioFiles = 0;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 0;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][1] =
	{
		{ 2 },  //  | 0->2
		{ -1 }, // 
		{ -1 }  // 
	};
	
	const span<dyn<float>, 0> embeddedData = { };
};

template <int NV>
using Env4_t = wrap::data<project::Env2<NV>, 
                          data::matrix<Env4_t_matrix>>;

template <int NV> using pma13_t = pma_t<NV>;

template <int NV> using pma15_t = pma_t<NV>;

template <int NV> using pma17_t = pma_t<NV>;

template <int NV> using pma43_t = pma_t<NV>;

template <int NV> using pma45_t = pma_t<NV>;

template <int NV> using pma47_t = pma_t<NV>;

template <int NV> using pma49_t = pma_t<NV>;

template <int NV> using pma51_t = pma_t<NV>;

template <int NV> using pma53_t = pma_t<NV>;

template <int NV>
using peak7_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma13_t<NV>, 0>, 
                                   parameter::plain<pma15_t<NV>, 0>, 
                                   parameter::plain<pma17_t<NV>, 0>, 
                                   parameter::plain<pma43_t<NV>, 0>, 
                                   parameter::plain<pma45_t<NV>, 0>, 
                                   parameter::plain<pma47_t<NV>, 0>, 
                                   parameter::plain<pma49_t<NV>, 0>, 
                                   parameter::plain<pma51_t<NV>, 0>, 
                                   parameter::plain<pma53_t<NV>, 0>>;

template <int NV>
using peak7_t = wrap::mod<peak7_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, Env4_t<NV>>, 
                                   peak7_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain2_t<NV>>, 
                                  chain19_t<NV>>;
using global_cable_t_index = runtime_target::indexers::fix_hash<3318940>;

template <int NV> using pma54_t = pma_t<NV>;
template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<pma54_t<NV>, 0>>;

template <int NV>
using chain75_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable_t<NV>>, 
                                   pma54_t<NV>, 
                                   math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<3318941>;

template <int NV> using pma56_t = pma_t<NV>;
template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<pma56_t<NV>, 0>>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable2_t<NV>>, 
                                   pma56_t<NV>, 
                                   math::add<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<3318942>;

template <int NV> using pma55_t = pma_t<NV>;
template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<pma55_t<NV>, 0>>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable1_t<NV>>, 
                                   pma55_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma13_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain75_t<NV>>, 
                                   chain77_t<NV>, 
                                   chain76_t<NV>, 
                                   chain20_t<NV>, 
                                   chain21_t<NV>>;

template <int NV> using pma1_t = pma_t<NV>;
template <int NV>
using midi1_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi1_t<NV>>, 
                                  pma1_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma2_t = pma_t<NV>;
template <int NV>
using midi2_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi2_t<NV>>, 
                                  pma2_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma3_t = pma_t<NV>;
template <int NV>
using midi3_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                          control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi3_t<NV>>, 
                                  pma3_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma4_t = pma_t<NV>;
template <int NV>
using midi_cc_t = control::midi_cc<parameter::plain<pma4_t<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc_t<NV>>, 
                                  pma4_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma5_t = pma_t<NV>;
template <int NV>
using midi_cc1_t = control::midi_cc<parameter::plain<pma5_t<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc1_t<NV>>, 
                                  pma5_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma6_t = pma_t<NV>;
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
                                  wrap::fix<1, branch_t<NV>>, 
                                  branch1_t<NV>>;

struct xnode1_t_matrix
{
	static const int NumTables = 1;
	static const int NumSliderPacks = 1;
	static const int NumAudioFiles = 31;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 0;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][31] =
	{
		{ 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },  //  | 0->0
		{ 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, //  | 0->11
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }            //  | 0->0 | 1->1 | 2->2 | 3->3 | 4->4 | 5->5 | 6->6 | 7->7 | 8->8 | 9->9 | 10->10 | 11->11 | 12->12 | 13->13 | 14->14 | 15->15 | 16->16
	};
	
	const span<dyn<float>, 0> embeddedData = { };
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
using clone_forward8_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 27>>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, clone_pack_t<NV>>, 
                                  clone_forward_t<NV>, 
                                  clone_forward2_t<NV>, 
                                  clone_forward1_t<NV>, 
                                  clone_forward6_t<NV>, 
                                  clone_forward7_t<NV>, 
                                  clone_forward8_t<NV>>;

template <int NV>
using no_midi4_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, pack_resizer_t>, 
                                     split2_t<NV>>;

template <int NV>
using no_midi4_t = wrap::no_midi<no_midi4_t_<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, chain9_t<NV>>, 
                                  no_midi4_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, chain1_t<NV>>>;
using global_cable3_t_index = global_cable_t_index;

template <int NV> using pma57_t = pma_t<NV>;
template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<pma57_t<NV>, 0>>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   pma57_t<NV>, 
                                   math::add<NV>>;
using global_cable5_t_index = global_cable2_t_index;

template <int NV> using pma59_t = pma_t<NV>;
template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<pma59_t<NV>, 0>>;

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable5_t<NV>>, 
                                   pma59_t<NV>, 
                                   math::add<NV>>;
using global_cable4_t_index = global_cable1_t_index;

template <int NV> using pma58_t = pma_t<NV>;
template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<pma58_t<NV>, 0>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   pma58_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma14_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma15_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain78_t<NV>>, 
                                    chain80_t<NV>, 
                                    chain79_t<NV>, 
                                    chain22_t<NV>, 
                                    chain23_t<NV>>;

template <int NV> using pma7_t = pma_t<NV>;
template <int NV>
using midi5_t = wrap::mod<parameter::plain<pma7_t<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi5_t<NV>>, 
                                   pma7_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma8_t = pma_t<NV>;
template <int NV>
using midi6_t = wrap::mod<parameter::plain<pma8_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi6_t<NV>>, 
                                   pma8_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma9_t = pma_t<NV>;
template <int NV>
using midi7_t = wrap::mod<parameter::plain<pma9_t<NV>, 0>, 
                          control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi7_t<NV>>, 
                                   pma9_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma10_t = pma_t<NV>;
template <int NV>
using midi_cc3_t = control::midi_cc<parameter::plain<pma10_t<NV>, 0>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc3_t<NV>>, 
                                   pma10_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma11_t = pma_t<NV>;
template <int NV>
using midi_cc4_t = control::midi_cc<parameter::plain<pma11_t<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc4_t<NV>>, 
                                   pma11_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma12_t = pma_t<NV>;
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
                                  wrap::fix<1, branch3_t<NV>>, 
                                  branch2_t<NV>>;

template <int NV>
using input_toggle38_t = control::input_toggle<NV, 
                                               parameter::plain<xnode1_t<NV>, 15>>;
template <int NV>
using clone_cable_cable_mod = parameter::cloned<parameter::plain<input_toggle38_t<NV>, 1>>;
template <int NV>
using clone_cable_t = control::clone_cable<clone_cable_cable_mod<NV>, 
                                           duplilogic::fixed>;

template <int NV>
using clone_cable29_cable_mod = parameter::cloned<parameter::plain<input_toggle38_t<NV>, 2>>;
template <int NV>
using clone_cable29_t = control::clone_cable<clone_cable29_cable_mod<NV>, 
                                             duplilogic::spread>;
DECLARE_PARAMETER_RANGE(peak1_mod_0Range, 
                        -1., 
                        1.);

template <int NV>
using peak1_mod_0 = parameter::from0To1<clone_cable_t<NV>, 
                                        1, 
                                        peak1_mod_0Range>;

template <int NV>
using peak1_mod_1 = parameter::from0To1<clone_cable29_t<NV>, 
                                        1, 
                                        peak1_mod_0Range>;

template <int NV>
using peak1_mod = parameter::chain<ranges::Identity, 
                                   peak1_mod_0<NV>, 
                                   peak1_mod_1<NV>>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split3_t<NV>>, 
                                   peak1_t<NV>, 
                                   math::clear<NV>>;

DECLARE_PARAMETER_RANGE_STEP(clone_cable28_modRange, 
                             0., 
                             1., 
                             1.);

template <int NV>
using clone_cable28_mod = parameter::from0To1<input_toggle38_t<NV>, 
                                              0, 
                                              clone_cable28_modRange>;

template <int NV>
using clone_cable28_t = control::clone_cable<parameter::cloned<clone_cable28_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using clone_cable30_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 22>>, 
                                             duplilogic::scale>;

template <int NV>
using split23_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_cable_t<NV>>, 
                                   clone_cable29_t<NV>, 
                                   clone_cable28_t<NV>, 
                                   clone_cable30_t<NV>>;

template <int NV>
using no_midi5_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split23_t<NV>>>;

template <int NV>
using no_midi5_t = wrap::no_midi<no_midi5_t_<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain12_t<NV>>, 
                                   no_midi5_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain11_t<NV>>>;
using global_cable7_t_index = global_cable_t_index;

template <int NV> using pma61_t = pma_t<NV>;
template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<pma61_t<NV>, 0>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   pma61_t<NV>, 
                                   math::add<NV>>;
using global_cable9_t_index = global_cable2_t_index;

template <int NV> using pma63_t = pma_t<NV>;
template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<pma63_t<NV>, 0>>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable9_t<NV>>, 
                                   pma63_t<NV>, 
                                   math::add<NV>>;
using global_cable8_t_index = global_cable1_t_index;

template <int NV> using pma62_t = pma_t<NV>;
template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<pma62_t<NV>, 0>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   pma62_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma16_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma17_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch8_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain82_t<NV>>, 
                                    chain84_t<NV>, 
                                    chain83_t<NV>, 
                                    chain24_t<NV>, 
                                    chain25_t<NV>>;

template <int NV> using pma19_t = pma_t<NV>;
template <int NV>
using midi11_t = wrap::mod<parameter::plain<pma19_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi11_t<NV>>, 
                                   pma19_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma20_t = pma_t<NV>;
template <int NV>
using midi12_t = wrap::mod<parameter::plain<pma20_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi12_t<NV>>, 
                                   pma20_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma21_t = pma_t<NV>;
template <int NV>
using midi13_t = wrap::mod<parameter::plain<pma21_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi13_t<NV>>, 
                                   pma21_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma22_t = pma_t<NV>;
template <int NV>
using midi_cc9_t = control::midi_cc<parameter::plain<pma22_t<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc9_t<NV>>, 
                                   pma22_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma23_t = pma_t<NV>;
template <int NV>
using midi_cc10_t = control::midi_cc<parameter::plain<pma23_t<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc10_t<NV>>, 
                                   pma23_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma24_t = pma_t<NV>;
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
                                  wrap::fix<1, branch8_t<NV>>, 
                                  branch4_t<NV>>;

template <int NV>
using input_toggle36_t = control::input_toggle<NV, 
                                               parameter::plain<xnode1_t<NV>, 17>>;
template <int NV>
using clone_cable2_cable_mod = parameter::cloned<parameter::plain<input_toggle36_t<NV>, 1>>;
template <int NV>
using clone_cable2_t = control::clone_cable<clone_cable2_cable_mod<NV>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable23_cable_mod = parameter::cloned<parameter::plain<input_toggle36_t<NV>, 2>>;
template <int NV>
using clone_cable23_t = control::clone_cable<clone_cable23_cable_mod<NV>, 
                                             duplilogic::spread>;
DECLARE_PARAMETER_RANGE_SKEW(peak3_mod_0Range, 
                             0., 
                             1., 
                             0.229905);

template <int NV>
using peak3_mod_0 = parameter::from0To1<clone_cable2_t<NV>, 
                                        1, 
                                        peak3_mod_0Range>;

template <int NV>
using peak3_mod_1 = parameter::from0To1<clone_cable23_t<NV>, 
                                        1, 
                                        peak1_mod_0Range>;

template <int NV>
using peak3_mod = parameter::chain<ranges::Identity, 
                                   peak3_mod_0<NV>, 
                                   peak3_mod_1<NV>>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split6_t<NV>>, 
                                   peak3_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using clone_cable24_mod = parameter::from0To1<input_toggle36_t<NV>, 
                                              0, 
                                              clone_cable28_modRange>;

template <int NV>
using clone_cable24_t = control::clone_cable<parameter::cloned<clone_cable24_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using split19_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_cable2_t<NV>>, 
                                   clone_cable23_t<NV>, 
                                   clone_cable24_t<NV>>;

template <int NV>
using no_midi13_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split19_t<NV>>>;

template <int NV>
using no_midi13_t = wrap::no_midi<no_midi13_t_<NV>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain29_t<NV>>, 
                                   no_midi13_t<NV>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain28_t<NV>>>;
using global_cable10_t_index = global_cable_t_index;

template <int NV> using pma64_t = pma_t<NV>;
template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<pma64_t<NV>, 0>>;

template <int NV>
using chain85_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   pma64_t<NV>, 
                                   math::add<NV>>;
using global_cable12_t_index = global_cable2_t_index;

template <int NV> using pma66_t = pma_t<NV>;
template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<pma66_t<NV>, 0>>;

template <int NV>
using chain87_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   pma66_t<NV>, 
                                   math::add<NV>>;
using global_cable11_t_index = global_cable1_t_index;

template <int NV> using pma65_t = pma_t<NV>;
template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<pma65_t<NV>, 0>>;

template <int NV>
using chain86_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   pma65_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma18_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma43_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch9_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain85_t<NV>>, 
                                    chain87_t<NV>, 
                                    chain86_t<NV>, 
                                    chain26_t<NV>, 
                                    chain63_t<NV>>;

template <int NV> using pma25_t = pma_t<NV>;
template <int NV>
using midi14_t = wrap::mod<parameter::plain<pma25_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi14_t<NV>>, 
                                   pma25_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma26_t = pma_t<NV>;
template <int NV>
using midi15_t = wrap::mod<parameter::plain<pma26_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi15_t<NV>>, 
                                   pma26_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma27_t = pma_t<NV>;
template <int NV>
using midi16_t = wrap::mod<parameter::plain<pma27_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi16_t<NV>>, 
                                   pma27_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma28_t = pma_t<NV>;
template <int NV>
using midi_cc12_t = control::midi_cc<parameter::plain<pma28_t<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc12_t<NV>>, 
                                   pma28_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma29_t = pma_t<NV>;
template <int NV>
using midi_cc13_t = control::midi_cc<parameter::plain<pma29_t<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc13_t<NV>>, 
                                   pma29_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma30_t = pma_t<NV>;
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
                                  wrap::fix<1, branch9_t<NV>>, 
                                  branch5_t<NV>>;

template <int NV>
using input_toggle_t = control::input_toggle<NV, 
                                             parameter::plain<xnode1_t<NV>, 20>>;
template <int NV>
using clone_cable3_t = control::clone_cable<parameter::cloned<parameter::plain<input_toggle_t<NV>, 1>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable7_t = control::clone_cable<parameter::cloned<parameter::plain<input_toggle_t<NV>, 2>>, 
                                            duplilogic::spread>;
template <int NV>
using peak4_mod_1 = parameter::from0To1<clone_cable7_t<NV>, 
                                        1, 
                                        peak1_mod_0Range>;

template <int NV>
using peak4_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<clone_cable3_t<NV>, 1>, 
                                   peak4_mod_1<NV>>;

template <int NV>
using peak4_t = wrap::mod<peak4_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   split7_t<NV>, 
                                   core::smoother<NV>, 
                                   peak4_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using clone_cable8_mod = parameter::from0To1<input_toggle_t<NV>, 
                                             0, 
                                             clone_cable28_modRange>;

template <int NV>
using clone_cable8_t = control::clone_cable<parameter::cloned<clone_cable8_mod<NV>>, 
                                            duplilogic::fixed>;

DECLARE_PARAMETER_RANGE_STEP(clone_cable32_modRange, 
                             1., 
                             32., 
                             1.);

template <int NV>
using clone_cable32_mod = parameter::from0To1<xnode1_t<NV>, 
                                              25, 
                                              clone_cable32_modRange>;

template <int NV>
using clone_cable32_t = control::clone_cable<parameter::cloned<clone_cable32_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using clone_cable31_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 26>>, 
                                             duplilogic::fixed>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, clone_cable3_t<NV>>, 
                                  clone_cable7_t<NV>, 
                                  clone_cable8_t<NV>, 
                                  clone_cable32_t<NV>, 
                                  clone_cable31_t<NV>>;

template <int NV>
using no_midi7_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split5_t<NV>>>;

template <int NV>
using no_midi7_t = wrap::no_midi<no_midi7_t_<NV>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain38_t<NV>>, 
                                   no_midi7_t<NV>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain37_t<NV>>>;
using global_cable13_t_index = global_cable1_t_index;

template <int NV> using pma73_t = pma_t<NV>;
template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<pma73_t<NV>, 0>>;

template <int NV>
using chain88_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   pma73_t<NV>, 
                                   math::add<NV>>;
using global_cable15_t_index = global_cable1_t_index;

template <int NV> using pma75_t = pma_t<NV>;
template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<pma75_t<NV>, 0>>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   pma75_t<NV>, 
                                   math::add<NV>>;
using global_cable14_t_index = global_cable1_t_index;

template <int NV> using pma74_t = pma_t<NV>;
template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<pma74_t<NV>, 0>>;

template <int NV>
using chain89_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   pma74_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma44_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma45_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch10_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain88_t<NV>>, 
                                     chain90_t<NV>, 
                                     chain89_t<NV>, 
                                     chain64_t<NV>, 
                                     chain65_t<NV>>;

template <int NV> using pma31_t = pma_t<NV>;
template <int NV>
using midi17_t = wrap::mod<parameter::plain<pma31_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi17_t<NV>>, 
                                   pma31_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma32_t = pma_t<NV>;
template <int NV>
using midi18_t = wrap::mod<parameter::plain<pma32_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi18_t<NV>>, 
                                   pma32_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma33_t = pma_t<NV>;
template <int NV>
using midi19_t = wrap::mod<parameter::plain<pma33_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi19_t<NV>>, 
                                   pma33_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma34_t = pma_t<NV>;
template <int NV>
using midi_cc15_t = control::midi_cc<parameter::plain<pma34_t<NV>, 0>>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc15_t<NV>>, 
                                   pma34_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma35_t = pma_t<NV>;
template <int NV>
using midi_cc16_t = control::midi_cc<parameter::plain<pma35_t<NV>, 0>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc16_t<NV>>, 
                                   pma35_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma36_t = pma_t<NV>;
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
                                  wrap::fix<1, branch10_t<NV>>, 
                                  branch6_t<NV>>;

template <int NV>
using input_toggle37_t = control::input_toggle<NV, 
                                               parameter::plain<xnode1_t<NV>, 21>>;
template <int NV>
using clone_cable4_cable_mod = parameter::cloned<parameter::plain<input_toggle37_t<NV>, 1>>;
template <int NV>
using clone_cable4_t = control::clone_cable<clone_cable4_cable_mod<NV>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable26_cable_mod = parameter::cloned<parameter::plain<input_toggle37_t<NV>, 2>>;
template <int NV>
using clone_cable26_t = control::clone_cable<clone_cable26_cable_mod<NV>, 
                                             duplilogic::spread>;
template <int NV>
using peak5_mod_1 = parameter::from0To1<clone_cable26_t<NV>, 
                                        1, 
                                        peak1_mod_0Range>;

template <int NV>
using peak5_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<clone_cable4_t<NV>, 1>, 
                                   peak5_mod_1<NV>>;

template <int NV>
using peak5_t = wrap::mod<peak5_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split8_t<NV>>, 
                                   peak5_t<NV>, 
                                   math::clear<NV>>;

using no_midi8_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, core::empty>>;

using no_midi8_t = wrap::no_midi<no_midi8_t_>;

template <int NV>
using clone_cable27_mod = parameter::from0To1<input_toggle37_t<NV>, 
                                              0, 
                                              clone_cable28_modRange>;

template <int NV>
using clone_cable27_t = control::clone_cable<parameter::cloned<clone_cable27_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using split22_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_cable4_t<NV>>, 
                                   clone_cable26_t<NV>, 
                                   clone_cable27_t<NV>>;

template <int NV>
using no_midi14_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split22_t<NV>>>;

template <int NV>
using no_midi14_t = wrap::no_midi<no_midi14_t_<NV>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain47_t<NV>>, 
                                   no_midi8_t, 
                                   no_midi14_t<NV>>;

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
using global_cable16_t_index = global_cable_t_index;

template <int NV> using pma76_t = pma_t<NV>;
template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<pma76_t<NV>, 0>>;

template <int NV>
using chain91_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   pma76_t<NV>, 
                                   math::add<NV>>;
using global_cable18_t_index = global_cable2_t_index;

template <int NV> using pma78_t = pma_t<NV>;
template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<pma78_t<NV>, 0>>;

template <int NV>
using chain93_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   pma78_t<NV>, 
                                   math::add<NV>>;
using global_cable17_t_index = global_cable1_t_index;

template <int NV> using pma77_t = pma_t<NV>;
template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<pma77_t<NV>, 0>>;

template <int NV>
using chain92_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   pma77_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma46_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma47_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch11_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain91_t<NV>>, 
                                     chain93_t<NV>, 
                                     chain92_t<NV>, 
                                     chain66_t<NV>, 
                                     chain67_t<NV>>;

template <int NV> using pma37_t = pma_t<NV>;
template <int NV>
using midi20_t = wrap::mod<parameter::plain<pma37_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi20_t<NV>>, 
                                   pma37_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma38_t = pma_t<NV>;
template <int NV>
using midi21_t = wrap::mod<parameter::plain<pma38_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi21_t<NV>>, 
                                   pma38_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma39_t = pma_t<NV>;
template <int NV>
using midi22_t = wrap::mod<parameter::plain<pma39_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi22_t<NV>>, 
                                   pma39_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma40_t = pma_t<NV>;
template <int NV>
using midi_cc18_t = control::midi_cc<parameter::plain<pma40_t<NV>, 0>>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc18_t<NV>>, 
                                   pma40_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma41_t = pma_t<NV>;
template <int NV>
using midi_cc19_t = control::midi_cc<parameter::plain<pma41_t<NV>, 0>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc19_t<NV>>, 
                                   pma41_t<NV>, 
                                   math::add<NV>>;

template <int NV> using pma42_t = pma_t<NV>;
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
                                   wrap::fix<1, branch11_t<NV>>, 
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
using pack_resizer5_t = wrap::data<control::pack_resizer, 
                                   data::external::sliderpack<3>>;
using pack_resizer4_t = wrap::data<control::pack_resizer, 
                                   data::external::sliderpack<4>>;

template <int NV>
using clone_cable9_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 24>>, 
                                            duplilogic::spread>;

template <int NV>
using clone_forward11_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 8>>>;

template <int NV>
using clone_forward14_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 5>>>;

template <int NV>
using input_toggle32_t = control::input_toggle<NV, 
                                               parameter::plain<xnode1_t<NV>, 23>>;
template <int NV>
using clone_cable1_cable_mod = parameter::cloned<parameter::plain<input_toggle32_t<NV>, 1>>;
template <int NV>
using clone_cable1_t = control::clone_cable<clone_cable1_cable_mod<NV>, 
                                            duplilogic::fixed>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_cable1_t<NV>>>;

template <int NV>
using no_midi9_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split12_t<NV>>>;

template <int NV>
using no_midi9_t = wrap::no_midi<no_midi9_t_<NV>>;

template <int NV>
using clone_cable17_mod = parameter::from0To1<xnode1_t<NV>, 
                                              7, 
                                              clone_cable32_modRange>;

template <int NV>
using clone_cable17_t = control::clone_cable<parameter::cloned<clone_cable17_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_cable17_t<NV>>>;

template <int NV>
using no_midi10_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split13_t<NV>>>;

template <int NV>
using no_midi10_t = wrap::no_midi<no_midi10_t_<NV>>;

template <int NV>
using input_toggle35_t = control::input_toggle<NV, 
                                               parameter::plain<xnode1_t<NV>, 9>>;
template <int NV>
using clone_forward12_cable_mod = parameter::cloned<parameter::plain<input_toggle35_t<NV>, 1>>;
template <int NV>
using clone_forward12_t = control::clone_forward<clone_forward12_cable_mod<NV>>;

template <int NV>
using clone_cable19_cable_mod = parameter::cloned<parameter::plain<input_toggle35_t<NV>, 2>>;
template <int NV>
using clone_cable19_t = control::clone_cable<clone_cable19_cable_mod<NV>, 
                                             duplilogic::spread>;

template <int NV>
using clone_cable20_mod = parameter::from0To1<input_toggle35_t<NV>, 
                                              0, 
                                              clone_cable28_modRange>;

template <int NV>
using clone_cable20_t = control::clone_cable<parameter::cloned<clone_cable20_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_forward12_t<NV>>, 
                                   clone_cable19_t<NV>, 
                                   clone_cable20_t<NV>>;

template <int NV>
using no_midi11_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split14_t<NV>>>;

template <int NV>
using no_midi11_t = wrap::no_midi<no_midi11_t_<NV>>;

template <int NV>
using input_toggle34_t = control::input_toggle<NV, 
                                               parameter::plain<xnode1_t<NV>, 14>>;
template <int NV>
using clone_forward13_cable_mod = parameter::cloned<parameter::plain<input_toggle34_t<NV>, 1>>;
template <int NV>
using clone_forward13_t = control::clone_forward<clone_forward13_cable_mod<NV>>;

template <int NV>
using clone_cable21_cable_mod = parameter::cloned<parameter::plain<input_toggle34_t<NV>, 2>>;
template <int NV>
using clone_cable21_t = control::clone_cable<clone_cable21_cable_mod<NV>, 
                                             duplilogic::spread>;

template <int NV>
using clone_cable22_mod = parameter::from0To1<input_toggle34_t<NV>, 
                                              0, 
                                              clone_cable28_modRange>;

template <int NV>
using clone_cable22_t = control::clone_cable<parameter::cloned<clone_cable22_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_forward13_t<NV>>, 
                                   clone_cable21_t<NV>, 
                                   clone_cable22_t<NV>>;

template <int NV>
using no_midi12_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split15_t<NV>>>;

template <int NV>
using no_midi12_t = wrap::no_midi<no_midi12_t_<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_cable6_modRange, 
                             0., 
                             2000., 
                             0.231378);

template <int NV>
using clone_cable6_mod = parameter::from0To1<xnode1_t<NV>, 
                                             16, 
                                             clone_cable6_modRange>;

template <int NV>
using clone_cable6_t = control::clone_cable<parameter::cloned<clone_cable6_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable5_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 19>>, 
                                            duplilogic::fixed>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_pack2_t<NV>>, 
                                   clone_cable9_t<NV>, 
                                   clone_forward11_t<NV>, 
                                   clone_forward14_t<NV>, 
                                   no_midi9_t<NV>, 
                                   no_midi10_t<NV>, 
                                   no_midi11_t<NV>, 
                                   no_midi12_t<NV>, 
                                   clone_cable6_t<NV>, 
                                   clone_cable5_t<NV>>;

template <int NV>
using no_midi3_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, pack_resizer2_t>, 
                                     pack_resizer5_t, 
                                     pack_resizer4_t, 
                                     split11_t<NV>>;

template <int NV>
using no_midi3_t = wrap::no_midi<no_midi3_t_<NV>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain56_t<NV>>, 
                                   no_midi3_t<NV>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain55_t<NV>>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain54_t<NV>>>;
using global_cable19_t_index = global_cable_t_index;

template <int NV> using pma91_t = pma_t<NV>;
template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<pma91_t<NV>, 0>>;

template <int NV>
using chain94_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   pma91_t<NV>, 
                                   math::add<NV>>;
using global_cable20_t_index = global_cable2_t_index;

template <int NV> using pma92_t = pma_t<NV>;
template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<pma92_t<NV>, 0>>;

template <int NV>
using chain95_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   pma92_t<NV>, 
                                   math::add<NV>>;
using global_cable21_t_index = global_cable1_t_index;

template <int NV> using pma93_t = pma_t<NV>;
template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<pma93_t<NV>, 0>>;

template <int NV>
using chain96_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   pma93_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma48_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma49_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch13_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain94_t<NV>>, 
                                     chain95_t<NV>, 
                                     chain96_t<NV>, 
                                     chain68_t<NV>, 
                                     chain69_t<NV>>;

template <int NV> using pma67_t = pma_t<NV>;
template <int NV>
using midi35_t = wrap::mod<parameter::plain<pma67_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain102_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi35_t<NV>>, 
                                    pma67_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma68_t = pma_t<NV>;
template <int NV>
using midi36_t = wrap::mod<parameter::plain<pma68_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain103_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi36_t<NV>>, 
                                    pma68_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma69_t = pma_t<NV>;
template <int NV>
using midi37_t = wrap::mod<parameter::plain<pma69_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain104_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi37_t<NV>>, 
                                    pma69_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma70_t = pma_t<NV>;
template <int NV>
using midi_cc33_t = control::midi_cc<parameter::plain<pma70_t<NV>, 0>>;

template <int NV>
using chain105_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc33_t<NV>>, 
                                    pma70_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma71_t = pma_t<NV>;
template <int NV>
using midi_cc34_t = control::midi_cc<parameter::plain<pma71_t<NV>, 0>>;

template <int NV>
using chain106_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc34_t<NV>>, 
                                    pma71_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma72_t = pma_t<NV>;
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
                                   wrap::fix<1, branch13_t<NV>>, 
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
                             4., 
                             1.);

template <int NV>
using clone_cable14_mod = parameter::from0To1<xnode1_t<NV>, 
                                              11, 
                                              clone_cable14_modRange>;

template <int NV>
using clone_cable14_t = control::clone_cable<parameter::cloned<clone_cable14_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using clone_cable13_mod = parameter::from0To1<jdsp::jpanner<NV>, 
                                              0, 
                                              peak1_mod_0Range>;

template <int NV>
using clone_cable13_t = control::clone_cable<parameter::cloned<clone_cable13_mod<NV>>, 
                                             duplilogic::spread>;

template <int NV>
using split18_t = container::split<parameter::empty, 
                                   wrap::fix<1, clone_pack3_t<NV>>, 
                                   clone_cable14_t<NV>, 
                                   clone_cable13_t<NV>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, split18_t<NV>>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using chain100_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain101_t<NV>>, 
                                    pack_resizer3_t, 
                                    no_midi_t<NV>>;

template <int NV>
using chain99_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain100_t<NV>>>;
using global_cable22_t_index = global_cable_t_index;

template <int NV> using pma94_t = pma_t<NV>;
template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<pma94_t<NV>, 0>>;

template <int NV>
using chain97_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   pma94_t<NV>, 
                                   math::add<NV>>;
using global_cable24_t_index = global_cable2_t_index;

template <int NV> using pma96_t = pma_t<NV>;
template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<pma96_t<NV>, 0>>;

template <int NV>
using chain108_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable24_t<NV>>, 
                                    pma96_t<NV>, 
                                    math::add<NV>>;
using global_cable23_t_index = global_cable1_t_index;

template <int NV> using pma95_t = pma_t<NV>;
template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<pma95_t<NV>, 0>>;

template <int NV>
using chain98_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   pma95_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma50_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma51_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch16_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain97_t<NV>>, 
                                     chain108_t<NV>, 
                                     chain98_t<NV>, 
                                     chain70_t<NV>, 
                                     chain71_t<NV>>;

template <int NV> using pma79_t = pma_t<NV>;
template <int NV>
using midi41_t = wrap::mod<parameter::plain<pma79_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain120_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi41_t<NV>>, 
                                    pma79_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma80_t = pma_t<NV>;
template <int NV>
using midi42_t = wrap::mod<parameter::plain<pma80_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain121_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi42_t<NV>>, 
                                    pma80_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma81_t = pma_t<NV>;
template <int NV>
using midi43_t = wrap::mod<parameter::plain<pma81_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain122_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi43_t<NV>>, 
                                    pma81_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma82_t = pma_t<NV>;
template <int NV>
using midi_cc39_t = control::midi_cc<parameter::plain<pma82_t<NV>, 0>>;

template <int NV>
using chain123_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc39_t<NV>>, 
                                    pma82_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma83_t = pma_t<NV>;
template <int NV>
using midi_cc40_t = control::midi_cc<parameter::plain<pma83_t<NV>, 0>>;

template <int NV>
using chain124_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc40_t<NV>>, 
                                    pma83_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma84_t = pma_t<NV>;
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
                                   wrap::fix<1, branch16_t<NV>>, 
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
using no_midi1_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, clone_cable10_t<NV>>>;

template <int NV>
using no_midi1_t = wrap::no_midi<no_midi1_t_<NV>>;

template <int NV>
using chain118_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain119_t<NV>>, 
                                    no_midi1_t<NV>>;

template <int NV>
using chain117_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain118_t<NV>>>;
using global_cable25_t_index = global_cable_t_index;

template <int NV> using pma97_t = pma_t<NV>;
template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<pma97_t<NV>, 0>>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable25_t<NV>>, 
                                    pma97_t<NV>, 
                                    math::add<NV>>;
using global_cable27_t_index = global_cable2_t_index;

template <int NV> using pma99_t = pma_t<NV>;
template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<pma99_t<NV>, 0>>;

template <int NV>
using chain111_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable27_t<NV>>, 
                                    pma99_t<NV>, 
                                    math::add<NV>>;
using global_cable26_t_index = global_cable1_t_index;

template <int NV> using pma98_t = pma_t<NV>;
template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<pma98_t<NV>, 0>>;

template <int NV>
using chain110_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable26_t<NV>>, 
                                    pma98_t<NV>, 
                                    math::add<NV>>;

template <int NV>
using chain72_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma52_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma53_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch17_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain109_t<NV>>, 
                                     chain111_t<NV>, 
                                     chain110_t<NV>, 
                                     chain72_t<NV>, 
                                     chain73_t<NV>>;

template <int NV> using pma85_t = pma_t<NV>;
template <int NV>
using midi44_t = wrap::mod<parameter::plain<pma85_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain129_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi44_t<NV>>, 
                                    pma85_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma86_t = pma_t<NV>;
template <int NV>
using midi45_t = wrap::mod<parameter::plain<pma86_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain130_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi45_t<NV>>, 
                                    pma86_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma87_t = pma_t<NV>;
template <int NV>
using midi46_t = wrap::mod<parameter::plain<pma87_t<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain131_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi46_t<NV>>, 
                                    pma87_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma88_t = pma_t<NV>;
template <int NV>
using midi_cc42_t = control::midi_cc<parameter::plain<pma88_t<NV>, 0>>;

template <int NV>
using chain132_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc42_t<NV>>, 
                                    pma88_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma89_t = pma_t<NV>;
template <int NV>
using midi_cc43_t = control::midi_cc<parameter::plain<pma89_t<NV>, 0>>;

template <int NV>
using chain133_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc43_t<NV>>, 
                                    pma89_t<NV>, 
                                    math::add<NV>>;

template <int NV> using pma90_t = pma_t<NV>;
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
                                   wrap::fix<1, branch17_t<NV>>, 
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
using no_midi2_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, clone_cable11_t<NV>>>;

template <int NV>
using no_midi2_t = wrap::no_midi<no_midi2_t_<NV>>;

template <int NV>
using chain127_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain128_t<NV>>, 
                                    no_midi2_t<NV>>;

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
                                     wrap::fix<1, split4_t<NV>>, 
                                     split_t<NV>, 
                                     split9_t<NV>, 
                                     split16_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain74_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle_t<NV>>, 
                                   input_toggle32_t<NV>, 
                                   input_toggle35_t<NV>, 
                                   input_toggle34_t<NV>, 
                                   input_toggle36_t<NV>, 
                                   input_toggle37_t<NV>, 
                                   input_toggle38_t<NV>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, chain74_t<NV>>, 
                                       xnode1_t<NV>, 
                                       jdsp::jpanner<NV>>;
template <int NV>
using clone_t = wrap::clonesplit<clone_child_t<NV>, 33>;

namespace ArrangeNew_t_parameters
{
// Parameter list for ArrangeNew_impl::ArrangeNew_t ------------------------------------------------

template <int NV>
using Harm = parameter::chain<ranges::Identity, 
                              parameter::plain<ArrangeNew_impl::pma_t<NV>, 2>, 
                              parameter::plain<ArrangeNew_impl::pma13_t<NV>, 2>, 
                              parameter::plain<ArrangeNew_impl::pma56_t<NV>, 2>, 
                              parameter::plain<ArrangeNew_impl::pma55_t<NV>, 2>, 
                              parameter::plain<ArrangeNew_impl::pma54_t<NV>, 2>>;

template <int NV>
using HarmMod = parameter::chain<ranges::Identity, 
                                 parameter::plain<ArrangeNew_impl::pma_t<NV>, 1>, 
                                 parameter::plain<ArrangeNew_impl::pma13_t<NV>, 1>, 
                                 parameter::plain<ArrangeNew_impl::pma56_t<NV>, 1>, 
                                 parameter::plain<ArrangeNew_impl::pma54_t<NV>, 1>, 
                                 parameter::plain<ArrangeNew_impl::pma55_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(HarmSrc_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using HarmSrc_0 = parameter::from0To1<ArrangeNew_impl::branch_t<NV>, 
                                      0, 
                                      ArrangeNew_impl::clone_cable14_modRange>;

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
                                parameter::plain<ArrangeNew_impl::pma14_t<NV>, 2>, 
                                parameter::plain<ArrangeNew_impl::pma15_t<NV>, 2>, 
                                parameter::plain<ArrangeNew_impl::pma59_t<NV>, 2>, 
                                parameter::plain<ArrangeNew_impl::pma58_t<NV>, 2>, 
                                parameter::plain<ArrangeNew_impl::pma57_t<NV>, 2>>;

template <int NV>
using DetuneMod = parameter::chain<ranges::Identity, 
                                   parameter::plain<ArrangeNew_impl::pma14_t<NV>, 1>, 
                                   parameter::plain<ArrangeNew_impl::pma15_t<NV>, 1>, 
                                   parameter::plain<ArrangeNew_impl::pma57_t<NV>, 1>, 
                                   parameter::plain<ArrangeNew_impl::pma59_t<NV>, 1>, 
                                   parameter::plain<ArrangeNew_impl::pma58_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(DetuneSrc_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using DetuneSrc_0 = parameter::from0To1<ArrangeNew_impl::branch3_t<NV>, 
                                        0, 
                                        ArrangeNew_impl::clone_cable14_modRange>;

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

template <int NV>
using Shape = parameter::chain<ranges::Identity, 
                               parameter::plain<ArrangeNew_impl::pma16_t<NV>, 2>, 
                               parameter::plain<ArrangeNew_impl::pma17_t<NV>, 2>, 
                               parameter::plain<ArrangeNew_impl::pma62_t<NV>, 2>, 
                               parameter::plain<ArrangeNew_impl::pma63_t<NV>, 2>, 
                               parameter::plain<ArrangeNew_impl::pma61_t<NV>, 2>>;

template <int NV>
using ShapeMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<ArrangeNew_impl::pma16_t<NV>, 1>, 
                                  parameter::plain<ArrangeNew_impl::pma17_t<NV>, 1>, 
                                  parameter::plain<ArrangeNew_impl::pma61_t<NV>, 1>, 
                                  parameter::plain<ArrangeNew_impl::pma63_t<NV>, 1>, 
                                  parameter::plain<ArrangeNew_impl::pma62_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(ShapeSrc_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using ShapeSrc_0 = parameter::from0To1<ArrangeNew_impl::branch8_t<NV>, 
                                       0, 
                                       ArrangeNew_impl::clone_cable14_modRange>;

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

template <int NV>
using CyclePos = parameter::chain<ranges::Identity, 
                                  parameter::plain<ArrangeNew_impl::pma18_t<NV>, 2>, 
                                  parameter::plain<ArrangeNew_impl::pma43_t<NV>, 2>, 
                                  parameter::plain<ArrangeNew_impl::pma64_t<NV>, 2>, 
                                  parameter::plain<ArrangeNew_impl::pma66_t<NV>, 2>, 
                                  parameter::plain<ArrangeNew_impl::pma65_t<NV>, 2>>;

template <int NV>
using CyclePosMod = parameter::chain<ranges::Identity, 
                                     parameter::plain<ArrangeNew_impl::pma18_t<NV>, 1>, 
                                     parameter::plain<ArrangeNew_impl::pma43_t<NV>, 1>, 
                                     parameter::plain<ArrangeNew_impl::pma64_t<NV>, 1>, 
                                     parameter::plain<ArrangeNew_impl::pma66_t<NV>, 1>, 
                                     parameter::plain<ArrangeNew_impl::pma65_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(CyclePosSrc_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using CyclePosSrc_0 = parameter::from0To1<ArrangeNew_impl::branch9_t<NV>, 
                                          0, 
                                          ArrangeNew_impl::clone_cable14_modRange>;

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

template <int NV>
using CycleShape = parameter::chain<ranges::Identity, 
                                    parameter::plain<ArrangeNew_impl::pma44_t<NV>, 2>, 
                                    parameter::plain<ArrangeNew_impl::pma45_t<NV>, 2>, 
                                    parameter::plain<ArrangeNew_impl::pma73_t<NV>, 2>, 
                                    parameter::plain<ArrangeNew_impl::pma75_t<NV>, 2>, 
                                    parameter::plain<ArrangeNew_impl::pma74_t<NV>, 2>>;

template <int NV>
using CycleShapeMod = parameter::chain<ranges::Identity, 
                                       parameter::plain<ArrangeNew_impl::pma44_t<NV>, 1>, 
                                       parameter::plain<ArrangeNew_impl::pma45_t<NV>, 1>, 
                                       parameter::plain<ArrangeNew_impl::pma73_t<NV>, 1>, 
                                       parameter::plain<ArrangeNew_impl::pma75_t<NV>, 1>, 
                                       parameter::plain<ArrangeNew_impl::pma74_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(CycleShapeSrc_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using CycleShapeSrc_0 = parameter::from0To1<ArrangeNew_impl::branch10_t<NV>, 
                                            0, 
                                            ArrangeNew_impl::clone_cable14_modRange>;

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

DECLARE_PARAMETER_RANGE(FxValue_InputRange, 
                        0., 
                        18.);

template <int NV>
using FxValue = parameter::chain<FxValue_InputRange, 
                                 parameter::plain<ArrangeNew_impl::pma46_t<NV>, 2>, 
                                 parameter::plain<ArrangeNew_impl::pma47_t<NV>, 2>, 
                                 parameter::plain<ArrangeNew_impl::pma76_t<NV>, 2>, 
                                 parameter::plain<ArrangeNew_impl::pma78_t<NV>, 2>, 
                                 parameter::plain<ArrangeNew_impl::pma77_t<NV>, 2>>;

template <int NV>
using FxValueMod = parameter::chain<ranges::Identity, 
                                    parameter::plain<ArrangeNew_impl::pma46_t<NV>, 1>, 
                                    parameter::plain<ArrangeNew_impl::pma47_t<NV>, 1>, 
                                    parameter::plain<ArrangeNew_impl::pma76_t<NV>, 1>, 
                                    parameter::plain<ArrangeNew_impl::pma78_t<NV>, 1>, 
                                    parameter::plain<ArrangeNew_impl::pma77_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(FxValueSrc_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using FxValueSrc_0 = parameter::from0To1<ArrangeNew_impl::branch11_t<NV>, 
                                         0, 
                                         ArrangeNew_impl::clone_cable14_modRange>;

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

DECLARE_PARAMETER_RANGE_STEP(FxDiv_InputRange, 
                             1., 
                             32., 
                             1.);

template <int NV>
using FxDiv = parameter::chain<FxDiv_InputRange, 
                               parameter::plain<ArrangeNew_impl::clone_cable17_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(FxSinSh_InputRange, 
                             1., 
                             4., 
                             1.);

template <int NV>
using FxSinSh = parameter::chain<FxSinSh_InputRange, 
                                 parameter::plain<ArrangeNew_impl::clone_cable5_t<NV>, 1>>;

template <int NV>
using FxtoPitch = parameter::chain<ranges::Identity, 
                                   parameter::plain<ArrangeNew_impl::clone_forward12_t<NV>, 1>, 
                                   parameter::plain<ArrangeNew_impl::clone_cable19_t<NV>, 1>>;

template <int NV>
using FxtoCut = parameter::chain<ranges::Identity, 
                                 parameter::plain<ArrangeNew_impl::clone_forward13_t<NV>, 1>, 
                                 parameter::plain<ArrangeNew_impl::clone_cable21_t<NV>, 1>>;

template <int NV>
using Cut = parameter::chain<ranges::Identity, 
                             parameter::plain<ArrangeNew_impl::pma48_t<NV>, 2>, 
                             parameter::plain<ArrangeNew_impl::pma49_t<NV>, 2>, 
                             parameter::plain<ArrangeNew_impl::pma91_t<NV>, 2>, 
                             parameter::plain<ArrangeNew_impl::pma92_t<NV>, 2>, 
                             parameter::plain<ArrangeNew_impl::pma93_t<NV>, 2>>;

template <int NV>
using CutMod = parameter::chain<ranges::Identity, 
                                parameter::plain<ArrangeNew_impl::pma48_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma49_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma91_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma92_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma93_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(CutSrc_InputRange, 
                        1., 
                        5.);
template <int NV>
using CutSrc_0 = parameter::from0To1<ArrangeNew_impl::branch13_t<NV>, 
                                     0, 
                                     ArrangeNew_impl::clone_cable14_modRange>;

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

template <int NV>
using Res = parameter::chain<ranges::Identity, 
                             parameter::plain<ArrangeNew_impl::pma50_t<NV>, 2>, 
                             parameter::plain<ArrangeNew_impl::pma51_t<NV>, 2>, 
                             parameter::plain<ArrangeNew_impl::pma94_t<NV>, 2>, 
                             parameter::plain<ArrangeNew_impl::pma96_t<NV>, 2>, 
                             parameter::plain<ArrangeNew_impl::pma95_t<NV>, 2>>;

template <int NV>
using ResMod = parameter::chain<ranges::Identity, 
                                parameter::plain<ArrangeNew_impl::pma50_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma51_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma94_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma96_t<NV>, 1>, 
                                parameter::plain<ArrangeNew_impl::pma95_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(ResSrc_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using ResSrc_0 = parameter::from0To1<ArrangeNew_impl::branch16_t<NV>, 
                                     0, 
                                     ArrangeNew_impl::clone_cable14_modRange>;

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

template <int NV>
using FilterMix = parameter::chain<ranges::Identity, 
                                   parameter::plain<ArrangeNew_impl::pma52_t<NV>, 2>, 
                                   parameter::plain<ArrangeNew_impl::pma53_t<NV>, 2>, 
                                   parameter::plain<ArrangeNew_impl::pma97_t<NV>, 2>, 
                                   parameter::plain<ArrangeNew_impl::pma99_t<NV>, 2>, 
                                   parameter::plain<ArrangeNew_impl::pma98_t<NV>, 2>>;

template <int NV>
using FilterMixMod = parameter::chain<ranges::Identity, 
                                      parameter::plain<ArrangeNew_impl::pma52_t<NV>, 1>, 
                                      parameter::plain<ArrangeNew_impl::pma53_t<NV>, 1>, 
                                      parameter::plain<ArrangeNew_impl::pma97_t<NV>, 1>, 
                                      parameter::plain<ArrangeNew_impl::pma99_t<NV>, 1>, 
                                      parameter::plain<ArrangeNew_impl::pma98_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(FilterMixSrc_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using FilterMixSrc_0 = parameter::from0To1<ArrangeNew_impl::branch17_t<NV>, 
                                           0, 
                                           ArrangeNew_impl::clone_cable14_modRange>;

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

DECLARE_PARAMETER_RANGE(FxtoGain_InputRange, 
                        -1., 
                        1.);

template <int NV>
using FxtoGain = parameter::chain<FxtoGain_InputRange, 
                                  parameter::plain<ArrangeNew_impl::clone_cable1_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(posdiv_InputRange, 
                             1., 
                             32., 
                             1.);

template <int NV>
using posdiv = parameter::chain<posdiv_InputRange, 
                                parameter::plain<ArrangeNew_impl::clone_cable32_t<NV>, 1>>;

template <int NV>
using V1 = parameter::chain<ranges::Identity, 
                            parameter::plain<ArrangeNew_impl::pack_resizer_t, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_pack_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_forward_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_forward2_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_forward1_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_forward6_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_forward7_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable2_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable23_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable24_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable3_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable7_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable8_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable4_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable26_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable27_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable29_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable28_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable30_t<NV>, 0>>;

template <int NV>
using V2 = parameter::chain<ranges::Identity, 
                            parameter::plain<ArrangeNew_impl::clone_pack2_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_forward11_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable1_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable17_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_forward12_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable19_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_forward13_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable21_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable22_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable6_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable5_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_pack3_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::pack_resizer3_t, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable14_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable13_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable10_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable11_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::pack_resizer2_t, 0>, 
                            parameter::plain<ArrangeNew_impl::pack_resizer5_t, 0>, 
                            parameter::plain<ArrangeNew_impl::pack_resizer4_t, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_forward14_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable32_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable31_t<NV>, 0>>;

template <int NV>
using V3 = parameter::chain<ranges::Identity, 
                            parameter::plain<ArrangeNew_impl::clone_t<NV>, 0>, 
                            parameter::plain<ArrangeNew_impl::clone_cable20_t<NV>, 0>>;

template <int NV>
using EnvMode1 = parameter::from0To1<ArrangeNew_impl::Env3_t<NV>, 
                                     10, 
                                     ArrangeNew_impl::clone_cable28_modRange>;

template <int NV>
using EnvMode2 = parameter::from0To1<ArrangeNew_impl::Env4_t<NV>, 
                                     10, 
                                     ArrangeNew_impl::clone_cable28_modRange>;

template <int NV>
using DetSprd = parameter::from0To1<ArrangeNew_impl::clone_cable28_t<NV>, 
                                    1, 
                                    ArrangeNew_impl::peak1_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(PitchSmooth_InputRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using PitchSmooth = parameter::chain<PitchSmooth_InputRange, 
                                     parameter::plain<ArrangeNew_impl::clone_cable30_t<NV>, 1>>;

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
using OscType = parameter::plain<ArrangeNew_impl::clone_forward6_t<NV>, 
                                 1>;
template <int NV>
using VoiceMode = parameter::plain<ArrangeNew_impl::clone_forward7_t<NV>, 
                                   1>;
using FxMix = parameter::empty;
using FxSync = FxMix;
template <int NV>
using Spread = parameter::plain<ArrangeNew_impl::clone_cable13_t<NV>, 
                                1>;
using Snap = FxMix;
template <int NV>
using EnvTempo1 = parameter::plain<ArrangeNew_impl::Env3_t<NV>, 
                                   0>;
template <int NV>
using EnvDiv1 = parameter::plain<ArrangeNew_impl::Env3_t<NV>, 
                                 1>;
template <int NV>
using EnvA1 = parameter::plain<ArrangeNew_impl::Env3_t<NV>, 
                               4>;
template <int NV>
using EnvD1 = parameter::plain<ArrangeNew_impl::Env3_t<NV>, 
                               5>;
template <int NV>
using EnvH1 = parameter::plain<ArrangeNew_impl::Env3_t<NV>, 
                               6>;
template <int NV>
using EnvS1 = parameter::plain<ArrangeNew_impl::Env3_t<NV>, 
                               7>;
template <int NV>
using EnvR1 = parameter::plain<ArrangeNew_impl::Env3_t<NV>, 
                               8>;
template <int NV>
using EnvTrig1 = parameter::plain<ArrangeNew_impl::Env3_t<NV>, 
                                  9>;
template <int NV>
using EnvTempo2 = parameter::plain<ArrangeNew_impl::Env4_t<NV>, 
                                   0>;
template <int NV>
using EnvDiv2 = parameter::plain<ArrangeNew_impl::Env4_t<NV>, 
                                 1>;
template <int NV>
using EnvA2 = parameter::plain<ArrangeNew_impl::Env4_t<NV>, 
                               4>;
template <int NV>
using EnvD2 = parameter::plain<ArrangeNew_impl::Env4_t<NV>, 
                               5>;
template <int NV>
using EnvH2 = parameter::plain<ArrangeNew_impl::Env4_t<NV>, 
                               6>;
template <int NV>
using EnvS2 = parameter::plain<ArrangeNew_impl::Env4_t<NV>, 
                               7>;
template <int NV>
using EnvR2 = parameter::plain<ArrangeNew_impl::Env4_t<NV>, 
                               8>;
template <int NV>
using EnvTrig2 = parameter::plain<ArrangeNew_impl::Env4_t<NV>, 
                                  9>;
template <int NV>
using Stages2 = parameter::plain<ArrangeNew_impl::clone_forward8_t<NV>, 
                                 0>;
template <int NV>
using PosMode = parameter::plain<ArrangeNew_impl::clone_cable31_t<NV>, 
                                 1>;
template <int NV>
using Quant = parameter::plain<ArrangeNew_impl::clone_forward8_t<NV>, 
                               1>;
template <int NV>
using PosSpread = parameter::plain<ArrangeNew_impl::clone_cable8_t<NV>, 
                                   1>;
using FxToGainSpread = FxMix;
using FxDivSprd = FxMix;
using FxToPitchSprd = FxMix;
using FxFilterSprd = FxMix;
template <int NV>
using OscShapeSpread = parameter::plain<ArrangeNew_impl::clone_cable24_t<NV>, 
                                        1>;
template <int NV>
using OscShpSprd = parameter::plain<ArrangeNew_impl::clone_cable27_t<NV>, 
                                    1>;
template <int NV>
using ModPhase = parameter::plain<ArrangeNew_impl::clone_cable9_t<NV>, 
                                  1>;
template <int NV>
using V5 = parameter::plain<ArrangeNew_impl::clone_cable9_t<NV>, 
                            0>;
template <int NV>
using SMOOTH = parameter::plain<ArrangeNew_impl::clone_cable6_t<NV>, 
                                1>;
template <int NV>
using FileGainRest = parameter::plain<ArrangeNew_impl::clone_forward11_t<NV>, 
                                      1>;
template <int NV>
using FileGainSmooth = parameter::plain<ArrangeNew_impl::clone_forward14_t<NV>, 
                                        1>;
template <int NV>
using ArrangeNew_t_plist = parameter::list<Harm<NV>, 
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
                                           FxMix, 
                                           FxDiv<NV>, 
                                           FxSync, 
                                           FxSinSh<NV>, 
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
                                           Snap, 
                                           FxtoGain<NV>, 
                                           EnvTempo1<NV>, 
                                           EnvDiv1<NV>, 
                                           EnvA1<NV>, 
                                           EnvD1<NV>, 
                                           EnvH1<NV>, 
                                           EnvS1<NV>, 
                                           EnvR1<NV>, 
                                           EnvTrig1<NV>, 
                                           EnvTempo2<NV>, 
                                           EnvDiv2<NV>, 
                                           EnvA2<NV>, 
                                           EnvD2<NV>, 
                                           EnvH2<NV>, 
                                           EnvS2<NV>, 
                                           EnvR2<NV>, 
                                           EnvTrig2<NV>, 
                                           Stages2<NV>, 
                                           posdiv<NV>, 
                                           PosMode<NV>, 
                                           Quant<NV>, 
                                           PosSpread<NV>, 
                                           FxToGainSpread, 
                                           FxDivSprd, 
                                           FxToPitchSprd, 
                                           FxFilterSprd, 
                                           OscShapeSpread<NV>, 
                                           OscShpSprd<NV>, 
                                           V1<NV>, 
                                           V2<NV>, 
                                           V3<NV>, 
                                           ModPhase<NV>, 
                                           V5<NV>, 
                                           SMOOTH<NV>, 
                                           EnvMode1<NV>, 
                                           EnvMode2<NV>, 
                                           FileGainRest<NV>, 
                                           FileGainSmooth<NV>, 
                                           DetSprd<NV>, 
                                           PitchSmooth<NV>>;
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
		static const int NumTables = 3;
		static const int NumSliderPacks = 12;
		static const int NumAudioFiles = 17;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(ArrangeNew);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(1782)
		{
			0x005C, 0x0000, 0x0000, 0x6148, 0x6D72, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0001, 0x0000, 0x6148, 0x6D72, 0x6F4D, 0x0064, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x0200, 0x0000, 0x4800, 0x7261, 0x536D, 0x6372, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x40A0, 0x0000, 0x4040, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x005C, 0x0003, 0x0000, 0x6148, 0x6D72, 
            0x7541, 0x0078, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0400, 0x0000, 0x4800, 
            0x7261, 0x416D, 0x7875, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 
            0xC000, 0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x0500, 0x0000, 0x4D00, 0x6E69, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0006, 0x0000, 0x614D, 0x0078, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0041, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0700, 
            0x0000, 0x5300, 0x6574, 0x0070, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0800, 
            0x0000, 0x4400, 0x7465, 0x6E75, 0x0065, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0900, 0x0000, 0x4400, 0x7465, 0x6E75, 0x4D65, 0x646F, 0x0000, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x000A, 0x0000, 0x6544, 0x7574, 0x656E, 
            0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0xA000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0B00, 0x0000, 0x4400, 
            0x7465, 0x6E75, 0x4165, 0x7875, 0x0000, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x23C0, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x000C, 0x0000, 0x6544, 0x7574, 0x656E, 0x7541, 0x5378, 0x6372, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x005C, 0x000D, 0x0000, 0x734F, 0x5463, 
            0x7079, 0x0065, 0x0000, 0x8000, 0x003F, 0xC000, 0x0040, 0xC000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0E00, 0x0000, 0x5300, 
            0x6168, 0x6570, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000F, 0x0000, 
            0x6853, 0x7061, 0x4D65, 0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0010, 0x0000, 0x6853, 0x7061, 0x5365, 0x6372, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x40A0, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0011, 0x0000, 0x6853, 0x7061, 0x4165, 0x7875, 
            0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0012, 0x0000, 0x6853, 0x7061, 
            0x4165, 0x7875, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0xC000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x1300, 
            0x0000, 0x5600, 0x696F, 0x6563, 0x6F4D, 0x6564, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x4080, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0014, 0x0000, 0x7943, 0x6C63, 0x5065, 0x736F, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0015, 0x0000, 0x7943, 0x6C63, 
            0x5065, 0x736F, 0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1600, 
            0x0000, 0x4300, 0x6379, 0x656C, 0x6F50, 0x5373, 0x6372, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x40A0, 0x0000, 0x40A0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x0017, 0x0000, 0x7943, 0x6C63, 0x5065, 
            0x736F, 0x7541, 0x0078, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1800, 0x0000, 
            0x4300, 0x6379, 0x656C, 0x6F50, 0x4173, 0x7875, 0x7253, 0x0063, 
            0x0000, 0x8000, 0x003F, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x1900, 0x0000, 0x4300, 0x6379, 0x656C, 
            0x6853, 0x7061, 0x0065, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1A00, 0x0000, 
            0x4300, 0x6379, 0x656C, 0x6853, 0x7061, 0x4D65, 0x646F, 0x0000, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x001B, 0x0000, 0x7943, 0x6C63, 0x5365, 
            0x6168, 0x6570, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0xA000, 
            0x0040, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x1C00, 
            0x0000, 0x4300, 0x6379, 0x656C, 0x6853, 0x7061, 0x4165, 0x7875, 
            0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x001D, 0x0000, 0x7943, 0x6C63, 
            0x5365, 0x6168, 0x6570, 0x7541, 0x5378, 0x6372, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x40C0, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x001E, 0x0000, 0x7846, 0x6156, 0x756C, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x1F00, 0x0000, 0x4600, 0x5678, 0x6C61, 
            0x6575, 0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x2000, 0x0000, 
            0x4600, 0x5678, 0x6C61, 0x6575, 0x7253, 0x0063, 0x0000, 0x8000, 
            0x003F, 0xA000, 0x0040, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x2100, 0x0000, 0x4600, 0x5678, 0x6C61, 0x6575, 0x7541, 
            0x0078, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0xC000, 0x0023, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x2200, 0x0000, 0x4600, 0x5678, 
            0x6C61, 0x6575, 0x7541, 0x5378, 0x7672, 0x0063, 0x0000, 0x8000, 
            0x003F, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x2300, 0x0000, 0x4600, 0x4D78, 0x7869, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x8000, 0x3ED3, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0024, 0x0000, 0x7846, 0x6944, 0x0076, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0042, 0xC000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x2500, 0x0000, 0x4600, 0x5378, 0x6E79, 0x0063, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x9A3F, 0x74F9, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x2600, 0x0000, 0x4600, 0x5378, 0x6E69, 
            0x6853, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x4040, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0027, 0x0000, 0x7846, 
            0x6F74, 0x6950, 0x6374, 0x0068, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x2800, 
            0x0000, 0x4600, 0x7478, 0x436F, 0x7475, 0x0000, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0029, 0x0000, 0x7543, 0x0074, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x2A00, 0x0000, 0x4300, 0x7475, 0x6F4D, 0x0064, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x2B00, 0x0000, 0x4300, 0x7475, 0x7253, 0x0063, 0x0000, 
            0x8000, 0x003F, 0xA000, 0x0040, 0x8000, 0x0040, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x2C00, 0x0000, 0x4300, 0x7475, 0x7541, 0x0078, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x2D00, 0x0000, 0x4300, 0x7475, 0x7541, 
            0x5378, 0x6372, 0x0000, 0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 
            0x4000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x002E, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x6F4D, 0x6564, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x4080, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x002F, 0x0000, 0x6552, 0x0073, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x3000, 0x0000, 0x5200, 0x7365, 0x6F4D, 0x0064, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x3100, 0x0000, 0x5200, 0x7365, 0x7253, 0x0063, 0x0000, 
            0x8000, 0x003F, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x3200, 0x0000, 0x5200, 0x7365, 0x7541, 0x0078, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x3300, 0x0000, 0x5200, 0x7365, 0x7541, 
            0x5378, 0x6372, 0x0000, 0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 
            0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0034, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x3500, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4D72, 0x7869, 0x6F4D, 
            0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x3600, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x4D72, 0x7869, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 
            0xA000, 0x0040, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x3700, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4D72, 0x7869, 0x7541, 
            0x0078, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x3800, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x4D72, 0x7869, 0x7541, 0x5378, 0x6372, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0039, 0x0000, 0x7053, 0x6572, 0x6461, 0x0000, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x003A, 0x0000, 0x6E53, 0x7061, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x003B, 0x0000, 0x7846, 0x6F74, 0x6147, 
            0x6E69, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x003C, 0x0000, 0x6E45, 
            0x5476, 0x6D65, 0x6F70, 0x0031, 0x0000, 0x0000, 0x0000, 0x9000, 
            0x0041, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x3D00, 
            0x0000, 0x4500, 0x766E, 0x6944, 0x3176, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x4180, 0x0000, 0x4100, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x003E, 0x0000, 0x6E45, 0x4176, 0x0031, 0x0000, 0x0000, 
            0x0000, 0x1C40, 0x0046, 0xD300, 0x7243, 0x4A6A, 0xCD3E, 0xCCCC, 
            0x5C3D, 0x3F00, 0x0000, 0x4500, 0x766E, 0x3144, 0x0000, 0x0000, 
            0x0000, 0x4000, 0x461C, 0x3400, 0x459C, 0x6A72, 0x3E4A, 0xCCCD, 
            0x3DCC, 0x005C, 0x0040, 0x0000, 0x6E45, 0x4876, 0x0031, 0x0000, 
            0x0000, 0x0000, 0x1C40, 0x0046, 0x0000, 0x7200, 0x4A6A, 0xCD3E, 
            0xCCCC, 0x5C3D, 0x4100, 0x0000, 0x4500, 0x766E, 0x3153, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x5C29, 0x3E0F, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0042, 0x0000, 0x6E45, 0x5276, 0x0031, 
            0x0000, 0x0000, 0x0000, 0x1C40, 0x0046, 0xDF40, 0x7244, 0x4A6A, 
            0xCD3E, 0xCCCC, 0x5C3D, 0x4300, 0x0000, 0x4500, 0x766E, 0x7254, 
            0x6769, 0x0031, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x4400, 0x0000, 0x4500, 
            0x766E, 0x6554, 0x706D, 0x326F, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x4190, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0045, 0x0000, 0x6E45, 0x4476, 0x7669, 0x0032, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0041, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x4600, 0x0000, 0x4500, 0x766E, 0x3241, 0x0000, 0x0000, 
            0x0000, 0x4000, 0x461C, 0x5800, 0x4589, 0x6A72, 0x3E4A, 0xCCCD, 
            0x3DCC, 0x005C, 0x0047, 0x0000, 0x6E45, 0x4476, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x1C40, 0x9A46, 0xC22D, 0x7245, 0x4A6A, 0xCD3E, 
            0xCCCC, 0x5C3D, 0x4800, 0x0000, 0x4500, 0x766E, 0x3248, 0x0000, 
            0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 0x0000, 0x6A72, 0x3E4A, 
            0xCCCD, 0x3DCC, 0x005C, 0x0049, 0x0000, 0x6E45, 0x5376, 0x0032, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x0A3F, 0x23D7, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x4A00, 0x0000, 0x4500, 0x766E, 0x3252, 
            0x0000, 0x0000, 0x0000, 0x4000, 0x461C, 0xF000, 0x4506, 0x6A72, 
            0x3E4A, 0xCCCD, 0x3DCC, 0x005C, 0x004B, 0x0000, 0x6E45, 0x5476, 
            0x6972, 0x3267, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x004C, 0x0000, 
            0x7453, 0x6761, 0x7365, 0x0032, 0x0000, 0x8000, 0x003F, 0x0400, 
            0x0042, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x4D00, 
            0x0000, 0x7000, 0x736F, 0x6964, 0x0076, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0042, 0x0000, 0x0042, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x4E00, 0x0000, 0x5000, 0x736F, 0x6F4D, 0x6564, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x004F, 0x0000, 0x7551, 0x6E61, 0x0074, 0x0000, 
            0x8000, 0x003F, 0x2000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x5000, 0x0000, 0x5000, 0x736F, 0x7053, 0x6572, 
            0x6461, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0051, 0x0000, 0x7846, 
            0x6F54, 0x6147, 0x6E69, 0x7053, 0x6572, 0x6461, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0052, 0x0000, 0x7846, 0x6944, 0x5376, 0x7270, 
            0x0064, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x5300, 0x0000, 0x4600, 0x5478, 
            0x506F, 0x7469, 0x6863, 0x7053, 0x6472, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0xD70A, 0x3BA3, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0054, 0x0000, 0x7846, 0x6946, 0x746C, 0x7265, 0x7053, 
            0x6472, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0055, 0x0000, 0x734F, 
            0x5363, 0x6168, 0x6570, 0x7053, 0x6572, 0x6461, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0056, 0x0000, 0x734F, 0x5363, 0x7068, 0x7053, 
            0x6472, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0057, 0x0000, 0x3156, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x4204, 0x0000, 0x4200, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x005C, 0x0058, 0x0000, 0x3256, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x4204, 0x0000, 0x4200, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x0059, 0x0000, 0x3356, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x4204, 0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x005A, 0x0000, 0x6F4D, 0x5064, 0x6168, 0x6573, 
            0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x47AE, 0xBE61, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x005B, 0x0000, 0x3556, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x4204, 0x0000, 0x4200, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x005C, 0x0000, 0x4D53, 0x4F4F, 0x4854, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x5C29, 0x3E8F, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x005D, 0x0000, 0x6E45, 0x4D76, 
            0x646F, 0x3165, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x005E, 0x0000, 
            0x6E45, 0x4D76, 0x646F, 0x3265, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x005F, 0x0000, 0x6946, 0x656C, 0x6147, 0x6E69, 0x6552, 0x7473, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0060, 0x0000, 0x6946, 0x656C, 
            0x6147, 0x6E69, 0x6D53, 0x6F6F, 0x6874, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F00, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0061, 0x0000, 0x6544, 0x5374, 0x7270, 0x0064, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x6200, 0x0000, 0x5000, 0x7469, 0x6863, 0x6D53, 
            0x6F6F, 0x6874, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 
            0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(3)
		{
			0x3D3B, 0x013E, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                        // ArrangeNew_impl::modchain_t<NV>
		auto& split4 = this->getT(0).getT(0);                                                  // ArrangeNew_impl::split4_t<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0);                                          // ArrangeNew_impl::chain2_t<NV>
		auto& Env3 = this->getT(0).getT(0).getT(0).getT(0);                                    // ArrangeNew_impl::Env3_t<NV>
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(1);                                   // ArrangeNew_impl::peak2_t<NV>
		auto& clear2 = this->getT(0).getT(0).getT(0).getT(2);                                  // math::clear<NV>
		auto& chain19 = this->getT(0).getT(0).getT(1);                                         // ArrangeNew_impl::chain19_t<NV>
		auto& Env4 = this->getT(0).getT(0).getT(1).getT(0);                                    // ArrangeNew_impl::Env4_t<NV>
		auto& peak7 = this->getT(0).getT(0).getT(1).getT(1);                                   // ArrangeNew_impl::peak7_t<NV>
		auto& clear7 = this->getT(0).getT(0).getT(1).getT(2);                                  // math::clear<NV>
		auto& split = this->getT(0).getT(1);                                                   // ArrangeNew_impl::split_t<NV>
		auto& chain = this->getT(0).getT(1).getT(0);                                           // ArrangeNew_impl::chain_t<NV>
		auto& chain1 = this->getT(0).getT(1).getT(0).getT(0);                                  // ArrangeNew_impl::chain1_t<NV>
		auto& chain9 = this->getT(0).getT(1).getT(0).getT(0).getT(0);                          // ArrangeNew_impl::chain9_t<NV>
		auto& split1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0);                  // ArrangeNew_impl::split1_t<NV>
		auto& branch = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);          // ArrangeNew_impl::branch_t<NV>
		auto& chain75 = this->getT(0).getT(1).getT(0).getT(0).                                 // ArrangeNew_impl::chain75_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& global_cable = this->getT(0).getT(1).getT(0).getT(0).                            // ArrangeNew_impl::global_cable_t<NV>
                             getT(0).getT(0).getT(0).getT(0).
                             getT(0);
		auto& pma54 = this->getT(0).getT(1).getT(0).getT(0).                                   // ArrangeNew_impl::pma54_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(1);
		auto& add54 = this->getT(0).getT(1).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(2);
		auto& chain77 = this->getT(0).getT(1).getT(0).getT(0).                                 // ArrangeNew_impl::chain77_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& global_cable2 = this->getT(0).getT(1).getT(0).getT(0).                           // ArrangeNew_impl::global_cable2_t<NV>
                              getT(0).getT(0).getT(0).getT(1).
                              getT(0);
		auto& pma56 = this->getT(0).getT(1).getT(0).getT(0).                                   // ArrangeNew_impl::pma56_t<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(1);
		auto& add56 = this->getT(0).getT(1).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(2);
		auto& chain76 = this->getT(0).getT(1).getT(0).getT(0).                                 // ArrangeNew_impl::chain76_t<NV>
                        getT(0).getT(0).getT(0).getT(2);
		auto& global_cable1 = this->getT(0).getT(1).getT(0).getT(0).                           // ArrangeNew_impl::global_cable1_t<NV>
                              getT(0).getT(0).getT(0).getT(2).
                              getT(0);
		auto& pma55 = this->getT(0).getT(1).getT(0).getT(0).                                   // ArrangeNew_impl::pma55_t<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(1);
		auto& add55 = this->getT(0).getT(1).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(2);
		auto& chain20 = this->getT(0).getT(1).getT(0).getT(0).                                 // ArrangeNew_impl::chain20_t<NV>
                        getT(0).getT(0).getT(0).getT(3);
		auto& pma = this->getT(0).getT(1).getT(0).getT(0).                                     // ArrangeNew_impl::pma_t<NV>
                    getT(0).getT(0).getT(0).getT(3).
                    getT(0);
		auto& add = this->getT(0).getT(1).getT(0).getT(0).                                     // math::add<NV>
                    getT(0).getT(0).getT(0).getT(3).
                    getT(1);
		auto& chain21 = this->getT(0).getT(1).getT(0).getT(0).                                 // ArrangeNew_impl::chain21_t<NV>
                        getT(0).getT(0).getT(0).getT(4);
		auto& pma13 = this->getT(0).getT(1).getT(0).getT(0).                                   // ArrangeNew_impl::pma13_t<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add13 = this->getT(0).getT(1).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(1);
		auto& branch1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(1);         // ArrangeNew_impl::branch1_t<NV>
		auto& chain3 = this->getT(0).getT(1).getT(0).getT(0).                                  // ArrangeNew_impl::chain3_t<NV>
                       getT(0).getT(0).getT(1).getT(0);
		auto& midi1 = this->getT(0).getT(1).getT(0).getT(0).                                   // ArrangeNew_impl::midi1_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(0);
		auto& pma1 = this->getT(0).getT(1).getT(0).getT(0).                                    // ArrangeNew_impl::pma1_t<NV>
                     getT(0).getT(0).getT(1).getT(0).
                     getT(1);
		auto& add1 = this->getT(0).getT(1).getT(0).getT(0).                                    // math::add<NV>
                     getT(0).getT(0).getT(1).getT(0).
                     getT(2);
		auto& chain4 = this->getT(0).getT(1).getT(0).getT(0).                                  // ArrangeNew_impl::chain4_t<NV>
                       getT(0).getT(0).getT(1).getT(1);
		auto& midi2 = this->getT(0).getT(1).getT(0).getT(0).                                   // ArrangeNew_impl::midi2_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(0);
		auto& pma2 = this->getT(0).getT(1).getT(0).getT(0).                                    // ArrangeNew_impl::pma2_t<NV>
                     getT(0).getT(0).getT(1).getT(1).
                     getT(1);
		auto& add2 = this->getT(0).getT(1).getT(0).getT(0).                                    // math::add<NV>
                     getT(0).getT(0).getT(1).getT(1).
                     getT(2);
		auto& chain5 = this->getT(0).getT(1).getT(0).getT(0).                                  // ArrangeNew_impl::chain5_t<NV>
                       getT(0).getT(0).getT(1).getT(2);
		auto& midi3 = this->getT(0).getT(1).getT(0).getT(0).                                   // ArrangeNew_impl::midi3_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(0);
		auto& pma3 = this->getT(0).getT(1).getT(0).getT(0).                                    // ArrangeNew_impl::pma3_t<NV>
                     getT(0).getT(0).getT(1).getT(2).
                     getT(1);
		auto& add3 = this->getT(0).getT(1).getT(0).getT(0).                                    // math::add<NV>
                     getT(0).getT(0).getT(1).getT(2).
                     getT(2);
		auto& chain6 = this->getT(0).getT(1).getT(0).getT(0).                                  // ArrangeNew_impl::chain6_t<NV>
                       getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc = this->getT(0).getT(1).getT(0).getT(0).                                 // ArrangeNew_impl::midi_cc_t<NV>
                        getT(0).getT(0).getT(1).getT(3).
                        getT(0);
		auto& pma4 = this->getT(0).getT(1).getT(0).getT(0).                                    // ArrangeNew_impl::pma4_t<NV>
                     getT(0).getT(0).getT(1).getT(3).
                     getT(1);
		auto& add4 = this->getT(0).getT(1).getT(0).getT(0).                                    // math::add<NV>
                     getT(0).getT(0).getT(1).getT(3).
                     getT(2);
		auto& chain7 = this->getT(0).getT(1).getT(0).getT(0).                                  // ArrangeNew_impl::chain7_t<NV>
                       getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc1 = this->getT(0).getT(1).getT(0).getT(0).                                // ArrangeNew_impl::midi_cc1_t<NV>
                         getT(0).getT(0).getT(1).getT(4).
                         getT(0);
		auto& pma5 = this->getT(0).getT(1).getT(0).getT(0).                                    // ArrangeNew_impl::pma5_t<NV>
                     getT(0).getT(0).getT(1).getT(4).
                     getT(1);
		auto& add5 = this->getT(0).getT(1).getT(0).getT(0).                                    // math::add<NV>
                     getT(0).getT(0).getT(1).getT(4).
                     getT(2);
		auto& chain8 = this->getT(0).getT(1).getT(0).getT(0).                                  // ArrangeNew_impl::chain8_t<NV>
                       getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc2 = this->getT(0).getT(1).getT(0).getT(0).                                // ArrangeNew_impl::midi_cc2_t<NV>
                         getT(0).getT(0).getT(1).getT(5).
                         getT(0);
		auto& pma6 = this->getT(0).getT(1).getT(0).getT(0).                                    // ArrangeNew_impl::pma6_t<NV>
                     getT(0).getT(0).getT(1).getT(5).
                     getT(1);
		auto& add6 = this->getT(0).getT(1).getT(0).getT(0).                                    // math::add<NV>
                     getT(0).getT(0).getT(1).getT(5).
                     getT(2);
		auto& peak = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(1);                    // ArrangeNew_impl::peak_t<NV>
		auto& clear = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(2);                   // math::clear<NV>
		auto& no_midi4 = this->getT(0).getT(1).getT(0).getT(0).getT(1);                        // ArrangeNew_impl::no_midi4_t<NV>
		auto& pack_resizer = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(0);            // ArrangeNew_impl::pack_resizer_t
		auto& split2 = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(1);                  // ArrangeNew_impl::split2_t<NV>
		auto& clone_pack = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(1).getT(0);      // ArrangeNew_impl::clone_pack_t<NV>
		auto& clone_forward = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(1).getT(1);   // ArrangeNew_impl::clone_forward_t<NV>
		auto& clone_forward2 = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(1).getT(2);  // ArrangeNew_impl::clone_forward2_t<NV>
		auto& clone_forward1 = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(1).getT(3);  // ArrangeNew_impl::clone_forward1_t<NV>
		auto& clone_forward6 = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(1).getT(4);  // ArrangeNew_impl::clone_forward6_t<NV>
		auto& clone_forward7 = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(1).getT(5);  // ArrangeNew_impl::clone_forward7_t<NV>
		auto& clone_forward8 = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(1).getT(6);  // ArrangeNew_impl::clone_forward8_t<NV>
		auto& chain10 = this->getT(0).getT(1).getT(1);                                         // ArrangeNew_impl::chain10_t<NV>
		auto& chain11 = this->getT(0).getT(1).getT(1).getT(0);                                 // ArrangeNew_impl::chain11_t<NV>
		auto& chain12 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                         // ArrangeNew_impl::chain12_t<NV>
		auto& split3 = this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(0);                  // ArrangeNew_impl::split3_t<NV>
		auto& branch3 = this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(0).getT(0);         // ArrangeNew_impl::branch3_t<NV>
		auto& chain78 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain78_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& global_cable3 = this->getT(0).getT(1).getT(1).getT(0).                           // ArrangeNew_impl::global_cable3_t<NV>
                              getT(0).getT(0).getT(0).getT(0).
                              getT(0);
		auto& pma57 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::pma57_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(1);
		auto& add57 = this->getT(0).getT(1).getT(1).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(2);
		auto& chain80 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain80_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& global_cable5 = this->getT(0).getT(1).getT(1).getT(0).                           // ArrangeNew_impl::global_cable5_t<NV>
                              getT(0).getT(0).getT(0).getT(1).
                              getT(0);
		auto& pma59 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::pma59_t<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(1);
		auto& add59 = this->getT(0).getT(1).getT(1).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(2);
		auto& chain79 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain79_t<NV>
                        getT(0).getT(0).getT(0).getT(2);
		auto& global_cable4 = this->getT(0).getT(1).getT(1).getT(0).                           // ArrangeNew_impl::global_cable4_t<NV>
                              getT(0).getT(0).getT(0).getT(2).
                              getT(0);
		auto& pma58 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::pma58_t<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(1);
		auto& add58 = this->getT(0).getT(1).getT(1).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(2);
		auto& chain22 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain22_t<NV>
                        getT(0).getT(0).getT(0).getT(3);
		auto& pma14 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::pma14_t<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(0);
		auto& add14 = this->getT(0).getT(1).getT(1).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(1);
		auto& chain23 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain23_t<NV>
                        getT(0).getT(0).getT(0).getT(4);
		auto& pma15 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::pma15_t<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add15 = this->getT(0).getT(1).getT(1).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(1);
		auto& branch2 = this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(0).getT(1);         // ArrangeNew_impl::branch2_t<NV>
		auto& chain13 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain13_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& midi5 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::midi5_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(0);
		auto& pma7 = this->getT(0).getT(1).getT(1).getT(0).                                    // ArrangeNew_impl::pma7_t<NV>
                     getT(0).getT(0).getT(1).getT(0).
                     getT(1);
		auto& add7 = this->getT(0).getT(1).getT(1).getT(0).                                    // math::add<NV>
                     getT(0).getT(0).getT(1).getT(0).
                     getT(2);
		auto& chain14 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain14_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& midi6 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::midi6_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(0);
		auto& pma8 = this->getT(0).getT(1).getT(1).getT(0).                                    // ArrangeNew_impl::pma8_t<NV>
                     getT(0).getT(0).getT(1).getT(1).
                     getT(1);
		auto& add8 = this->getT(0).getT(1).getT(1).getT(0).                                    // math::add<NV>
                     getT(0).getT(0).getT(1).getT(1).
                     getT(2);
		auto& chain15 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain15_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& midi7 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::midi7_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(0);
		auto& pma9 = this->getT(0).getT(1).getT(1).getT(0).                                    // ArrangeNew_impl::pma9_t<NV>
                     getT(0).getT(0).getT(1).getT(2).
                     getT(1);
		auto& add9 = this->getT(0).getT(1).getT(1).getT(0).                                    // math::add<NV>
                     getT(0).getT(0).getT(1).getT(2).
                     getT(2);
		auto& chain16 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain16_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc3 = this->getT(0).getT(1).getT(1).getT(0).                                // ArrangeNew_impl::midi_cc3_t<NV>
                         getT(0).getT(0).getT(1).getT(3).
                         getT(0);
		auto& pma10 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::pma10_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add10 = this->getT(0).getT(1).getT(1).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain17 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain17_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc4 = this->getT(0).getT(1).getT(1).getT(0).                                // ArrangeNew_impl::midi_cc4_t<NV>
                         getT(0).getT(0).getT(1).getT(4).
                         getT(0);
		auto& pma11 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::pma11_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add11 = this->getT(0).getT(1).getT(1).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain18 = this->getT(0).getT(1).getT(1).getT(0).                                 // ArrangeNew_impl::chain18_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc5 = this->getT(0).getT(1).getT(1).getT(0).                                // ArrangeNew_impl::midi_cc5_t<NV>
                         getT(0).getT(0).getT(1).getT(5).
                         getT(0);
		auto& pma12 = this->getT(0).getT(1).getT(1).getT(0).                                   // ArrangeNew_impl::pma12_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add12 = this->getT(0).getT(1).getT(1).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak1 = this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(1);                   // ArrangeNew_impl::peak1_t<NV>
		auto& clear1 = this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(2);                  // math::clear<NV>
		auto& no_midi5 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                        // ArrangeNew_impl::no_midi5_t<NV>
		auto& split23 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0);                 // ArrangeNew_impl::split23_t<NV>
		auto& clone_cable = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(0);     // ArrangeNew_impl::clone_cable_t<NV>
		auto& clone_cable29 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(1);   // ArrangeNew_impl::clone_cable29_t<NV>
		auto& clone_cable28 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(2);   // ArrangeNew_impl::clone_cable28_t<NV>
		auto& clone_cable30 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(3);   // ArrangeNew_impl::clone_cable30_t<NV>
		auto& chain27 = this->getT(0).getT(1).getT(2);                                         // ArrangeNew_impl::chain27_t<NV>
		auto& chain28 = this->getT(0).getT(1).getT(2).getT(0);                                 // ArrangeNew_impl::chain28_t<NV>
		auto& chain29 = this->getT(0).getT(1).getT(2).getT(0).getT(0);                         // ArrangeNew_impl::chain29_t<NV>
		auto& split6 = this->getT(0).getT(1).getT(2).getT(0).getT(0).getT(0);                  // ArrangeNew_impl::split6_t<NV>
		auto& branch8 = this->getT(0).getT(1).getT(2).getT(0).getT(0).getT(0).getT(0);         // ArrangeNew_impl::branch8_t<NV>
		auto& chain82 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain82_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& global_cable7 = this->getT(0).getT(1).getT(2).getT(0).                           // ArrangeNew_impl::global_cable7_t<NV>
                              getT(0).getT(0).getT(0).getT(0).
                              getT(0);
		auto& pma61 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma61_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(1);
		auto& add61 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(2);
		auto& chain84 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain84_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& global_cable9 = this->getT(0).getT(1).getT(2).getT(0).                           // ArrangeNew_impl::global_cable9_t<NV>
                              getT(0).getT(0).getT(0).getT(1).
                              getT(0);
		auto& pma63 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma63_t<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(1);
		auto& add63 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(2);
		auto& chain83 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain83_t<NV>
                        getT(0).getT(0).getT(0).getT(2);
		auto& global_cable8 = this->getT(0).getT(1).getT(2).getT(0).                           // ArrangeNew_impl::global_cable8_t<NV>
                              getT(0).getT(0).getT(0).getT(2).
                              getT(0);
		auto& pma62 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma62_t<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(1);
		auto& add62 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(2);
		auto& chain24 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain24_t<NV>
                        getT(0).getT(0).getT(0).getT(3);
		auto& pma16 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma16_t<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(0);
		auto& add16 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(1);
		auto& chain25 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain25_t<NV>
                        getT(0).getT(0).getT(0).getT(4);
		auto& pma17 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma17_t<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add17 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(1);
		auto& branch4 = this->getT(0).getT(1).getT(2).getT(0).getT(0).getT(0).getT(1);         // ArrangeNew_impl::branch4_t<NV>
		auto& chain30 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain30_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& midi11 = this->getT(0).getT(1).getT(2).getT(0).                                  // ArrangeNew_impl::midi11_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma19 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma19_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add19 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain31 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain31_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& midi12 = this->getT(0).getT(1).getT(2).getT(0).                                  // ArrangeNew_impl::midi12_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma20 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma20_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add20 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain32 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain32_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& midi13 = this->getT(0).getT(1).getT(2).getT(0).                                  // ArrangeNew_impl::midi13_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma21 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma21_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add21 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain33 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain33_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc9 = this->getT(0).getT(1).getT(2).getT(0).                                // ArrangeNew_impl::midi_cc9_t<NV>
                         getT(0).getT(0).getT(1).getT(3).
                         getT(0);
		auto& pma22 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma22_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add22 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain34 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain34_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc10 = this->getT(0).getT(1).getT(2).getT(0).                               // ArrangeNew_impl::midi_cc10_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma23 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma23_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add23 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain35 = this->getT(0).getT(1).getT(2).getT(0).                                 // ArrangeNew_impl::chain35_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc11 = this->getT(0).getT(1).getT(2).getT(0).                               // ArrangeNew_impl::midi_cc11_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma24 = this->getT(0).getT(1).getT(2).getT(0).                                   // ArrangeNew_impl::pma24_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add24 = this->getT(0).getT(1).getT(2).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak3 = this->getT(0).getT(1).getT(2).getT(0).getT(0).getT(1);                   // ArrangeNew_impl::peak3_t<NV>
		auto& clear3 = this->getT(0).getT(1).getT(2).getT(0).getT(0).getT(2);                  // math::clear<NV>
		auto& no_midi13 = this->getT(0).getT(1).getT(2).getT(0).getT(1);                       // ArrangeNew_impl::no_midi13_t<NV>
		auto& split19 = this->getT(0).getT(1).getT(2).getT(0).getT(1).getT(0);                 // ArrangeNew_impl::split19_t<NV>
		auto& clone_cable2 = this->getT(0).getT(1).getT(2).getT(0).getT(1).getT(0).getT(0);    // ArrangeNew_impl::clone_cable2_t<NV>
		auto& clone_cable23 = this->getT(0).getT(1).getT(2).getT(0).getT(1).getT(0).getT(1);   // ArrangeNew_impl::clone_cable23_t<NV>
		auto& clone_cable24 = this->getT(0).getT(1).getT(2).getT(0).getT(1).getT(0).getT(2);   // ArrangeNew_impl::clone_cable24_t<NV>
		auto& chain36 = this->getT(0).getT(1).getT(3);                                         // ArrangeNew_impl::chain36_t<NV>
		auto& chain37 = this->getT(0).getT(1).getT(3).getT(0);                                 // ArrangeNew_impl::chain37_t<NV>
		auto& chain38 = this->getT(0).getT(1).getT(3).getT(0).getT(0);                         // ArrangeNew_impl::chain38_t<NV>
		auto& clear8 = this->getT(0).getT(1).getT(3).getT(0).getT(0).getT(0);                  // math::clear<NV>
		auto& split7 = this->getT(0).getT(1).getT(3).getT(0).getT(0).getT(1);                  // ArrangeNew_impl::split7_t<NV>
		auto& branch9 = this->getT(0).getT(1).getT(3).getT(0).getT(0).getT(1).getT(0);         // ArrangeNew_impl::branch9_t<NV>
		auto& chain85 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain85_t<NV>
                        getT(0).getT(1).getT(0).getT(0);
		auto& global_cable10 = this->getT(0).getT(1).getT(3).getT(0).                          // ArrangeNew_impl::global_cable10_t<NV>
                               getT(0).getT(1).getT(0).getT(0).
                               getT(0);
		auto& pma64 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma64_t<NV>
                      getT(0).getT(1).getT(0).getT(0).
                      getT(1);
		auto& add64 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(0).getT(0).
                      getT(2);
		auto& chain87 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain87_t<NV>
                        getT(0).getT(1).getT(0).getT(1);
		auto& global_cable12 = this->getT(0).getT(1).getT(3).getT(0).                          // ArrangeNew_impl::global_cable12_t<NV>
                               getT(0).getT(1).getT(0).getT(1).
                               getT(0);
		auto& pma66 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma66_t<NV>
                      getT(0).getT(1).getT(0).getT(1).
                      getT(1);
		auto& add66 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(0).getT(1).
                      getT(2);
		auto& chain86 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain86_t<NV>
                        getT(0).getT(1).getT(0).getT(2);
		auto& global_cable11 = this->getT(0).getT(1).getT(3).getT(0).                          // ArrangeNew_impl::global_cable11_t<NV>
                               getT(0).getT(1).getT(0).getT(2).
                               getT(0);
		auto& pma65 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma65_t<NV>
                      getT(0).getT(1).getT(0).getT(2).
                      getT(1);
		auto& add65 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(0).getT(2).
                      getT(2);
		auto& chain26 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain26_t<NV>
                        getT(0).getT(1).getT(0).getT(3);
		auto& pma18 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma18_t<NV>
                      getT(0).getT(1).getT(0).getT(3).
                      getT(0);
		auto& add18 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(0).getT(3).
                      getT(1);
		auto& chain63 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain63_t<NV>
                        getT(0).getT(1).getT(0).getT(4);
		auto& pma43 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma43_t<NV>
                      getT(0).getT(1).getT(0).getT(4).
                      getT(0);
		auto& add43 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(0).getT(4).
                      getT(1);
		auto& branch5 = this->getT(0).getT(1).getT(3).getT(0).getT(0).getT(1).getT(1);         // ArrangeNew_impl::branch5_t<NV>
		auto& chain39 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain39_t<NV>
                        getT(0).getT(1).getT(1).getT(0);
		auto& midi14 = this->getT(0).getT(1).getT(3).getT(0).                                  // ArrangeNew_impl::midi14_t<NV>
                       getT(0).getT(1).getT(1).getT(0).
                       getT(0);
		auto& pma25 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma25_t<NV>
                      getT(0).getT(1).getT(1).getT(0).
                      getT(1);
		auto& add25 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(1).getT(0).
                      getT(2);
		auto& chain40 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain40_t<NV>
                        getT(0).getT(1).getT(1).getT(1);
		auto& midi15 = this->getT(0).getT(1).getT(3).getT(0).                                  // ArrangeNew_impl::midi15_t<NV>
                       getT(0).getT(1).getT(1).getT(1).
                       getT(0);
		auto& pma26 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma26_t<NV>
                      getT(0).getT(1).getT(1).getT(1).
                      getT(1);
		auto& add26 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1).
                      getT(2);
		auto& chain41 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain41_t<NV>
                        getT(0).getT(1).getT(1).getT(2);
		auto& midi16 = this->getT(0).getT(1).getT(3).getT(0).                                  // ArrangeNew_impl::midi16_t<NV>
                       getT(0).getT(1).getT(1).getT(2).
                       getT(0);
		auto& pma27 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma27_t<NV>
                      getT(0).getT(1).getT(1).getT(2).
                      getT(1);
		auto& add27 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2).
                      getT(2);
		auto& chain42 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain42_t<NV>
                        getT(0).getT(1).getT(1).getT(3);
		auto& midi_cc12 = this->getT(0).getT(1).getT(3).getT(0).                               // ArrangeNew_impl::midi_cc12_t<NV>
                          getT(0).getT(1).getT(1).getT(3).
                          getT(0);
		auto& pma28 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma28_t<NV>
                      getT(0).getT(1).getT(1).getT(3).
                      getT(1);
		auto& add28 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(1).getT(3).
                      getT(2);
		auto& chain43 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain43_t<NV>
                        getT(0).getT(1).getT(1).getT(4);
		auto& midi_cc13 = this->getT(0).getT(1).getT(3).getT(0).                               // ArrangeNew_impl::midi_cc13_t<NV>
                          getT(0).getT(1).getT(1).getT(4).
                          getT(0);
		auto& pma29 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma29_t<NV>
                      getT(0).getT(1).getT(1).getT(4).
                      getT(1);
		auto& add29 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(1).getT(4).
                      getT(2);
		auto& chain44 = this->getT(0).getT(1).getT(3).getT(0).                                 // ArrangeNew_impl::chain44_t<NV>
                        getT(0).getT(1).getT(1).getT(5);
		auto& midi_cc14 = this->getT(0).getT(1).getT(3).getT(0).                               // ArrangeNew_impl::midi_cc14_t<NV>
                          getT(0).getT(1).getT(1).getT(5).
                          getT(0);
		auto& pma30 = this->getT(0).getT(1).getT(3).getT(0).                                   // ArrangeNew_impl::pma30_t<NV>
                      getT(0).getT(1).getT(1).getT(5).
                      getT(1);
		auto& add30 = this->getT(0).getT(1).getT(3).getT(0).                                   // math::add<NV>
                      getT(0).getT(1).getT(1).getT(5).
                      getT(2);
		auto& smoother = this->getT(0).getT(1).getT(3).getT(0).getT(0).getT(2);                // core::smoother<NV>
		auto& peak4 = this->getT(0).getT(1).getT(3).getT(0).getT(0).getT(3);                   // ArrangeNew_impl::peak4_t<NV>
		auto& clear4 = this->getT(0).getT(1).getT(3).getT(0).getT(0).getT(4);                  // math::clear<NV>
		auto& no_midi7 = this->getT(0).getT(1).getT(3).getT(0).getT(1);                        // ArrangeNew_impl::no_midi7_t<NV>
		auto& split5 = this->getT(0).getT(1).getT(3).getT(0).getT(1).getT(0);                  // ArrangeNew_impl::split5_t<NV>
		auto& clone_cable3 = this->getT(0).getT(1).getT(3).getT(0).getT(1).getT(0).getT(0);    // ArrangeNew_impl::clone_cable3_t<NV>
		auto& clone_cable7 = this->getT(0).getT(1).getT(3).getT(0).getT(1).getT(0).getT(1);    // ArrangeNew_impl::clone_cable7_t<NV>
		auto& clone_cable8 = this->getT(0).getT(1).getT(3).getT(0).getT(1).getT(0).getT(2);    // ArrangeNew_impl::clone_cable8_t<NV>
		auto& clone_cable32 = this->getT(0).getT(1).getT(3).getT(0).getT(1).getT(0).getT(3);   // ArrangeNew_impl::clone_cable32_t<NV>
		auto& clone_cable31 = this->getT(0).getT(1).getT(3).getT(0).getT(1).getT(0).getT(4);   // ArrangeNew_impl::clone_cable31_t<NV>
		auto& chain45 = this->getT(0).getT(1).getT(4);                                         // ArrangeNew_impl::chain45_t<NV>
		auto& chain46 = this->getT(0).getT(1).getT(4).getT(0);                                 // ArrangeNew_impl::chain46_t<NV>
		auto& chain47 = this->getT(0).getT(1).getT(4).getT(0).getT(0);                         // ArrangeNew_impl::chain47_t<NV>
		auto& split8 = this->getT(0).getT(1).getT(4).getT(0).getT(0).getT(0);                  // ArrangeNew_impl::split8_t<NV>
		auto& branch10 = this->getT(0).getT(1).getT(4).getT(0).getT(0).getT(0).getT(0);        // ArrangeNew_impl::branch10_t<NV>
		auto& chain88 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain88_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& global_cable13 = this->getT(0).getT(1).getT(4).getT(0).                          // ArrangeNew_impl::global_cable13_t<NV>
                               getT(0).getT(0).getT(0).getT(0).
                               getT(0);
		auto& pma73 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma73_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(1);
		auto& add73 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(2);
		auto& chain90 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain90_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& global_cable15 = this->getT(0).getT(1).getT(4).getT(0).                          // ArrangeNew_impl::global_cable15_t<NV>
                               getT(0).getT(0).getT(0).getT(1).
                               getT(0);
		auto& pma75 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma75_t<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(1);
		auto& add75 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(2);
		auto& chain89 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain89_t<NV>
                        getT(0).getT(0).getT(0).getT(2);
		auto& global_cable14 = this->getT(0).getT(1).getT(4).getT(0).                          // ArrangeNew_impl::global_cable14_t<NV>
                               getT(0).getT(0).getT(0).getT(2).
                               getT(0);
		auto& pma74 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma74_t<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(1);
		auto& add74 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(2);
		auto& chain64 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain64_t<NV>
                        getT(0).getT(0).getT(0).getT(3);
		auto& pma44 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma44_t<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(0);
		auto& add44 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(1);
		auto& chain65 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain65_t<NV>
                        getT(0).getT(0).getT(0).getT(4);
		auto& pma45 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma45_t<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add45 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(1);
		auto& branch6 = this->getT(0).getT(1).getT(4).getT(0).getT(0).getT(0).getT(1);         // ArrangeNew_impl::branch6_t<NV>
		auto& chain48 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain48_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& midi17 = this->getT(0).getT(1).getT(4).getT(0).                                  // ArrangeNew_impl::midi17_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma31 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma31_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add31 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain49 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain49_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& midi18 = this->getT(0).getT(1).getT(4).getT(0).                                  // ArrangeNew_impl::midi18_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma32 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma32_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add32 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain50 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain50_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& midi19 = this->getT(0).getT(1).getT(4).getT(0).                                  // ArrangeNew_impl::midi19_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma33 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma33_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add33 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain51 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain51_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc15 = this->getT(0).getT(1).getT(4).getT(0).                               // ArrangeNew_impl::midi_cc15_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma34 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma34_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add34 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain52 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain52_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc16 = this->getT(0).getT(1).getT(4).getT(0).                               // ArrangeNew_impl::midi_cc16_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma35 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma35_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add35 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain53 = this->getT(0).getT(1).getT(4).getT(0).                                 // ArrangeNew_impl::chain53_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc17 = this->getT(0).getT(1).getT(4).getT(0).                               // ArrangeNew_impl::midi_cc17_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma36 = this->getT(0).getT(1).getT(4).getT(0).                                   // ArrangeNew_impl::pma36_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add36 = this->getT(0).getT(1).getT(4).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak5 = this->getT(0).getT(1).getT(4).getT(0).getT(0).getT(1);                   // ArrangeNew_impl::peak5_t<NV>
		auto& clear5 = this->getT(0).getT(1).getT(4).getT(0).getT(0).getT(2);                  // math::clear<NV>
		auto& no_midi8 = this->getT(0).getT(1).getT(4).getT(0).getT(1);                        // ArrangeNew_impl::no_midi8_t
		auto& no_midi14 = this->getT(0).getT(1).getT(4).getT(0).getT(2);                       // ArrangeNew_impl::no_midi14_t<NV>
		auto& split22 = this->getT(0).getT(1).getT(4).getT(0).getT(2).getT(0);                 // ArrangeNew_impl::split22_t<NV>
		auto& clone_cable4 = this->getT(0).getT(1).getT(4).getT(0).getT(2).getT(0).getT(0);    // ArrangeNew_impl::clone_cable4_t<NV>
		auto& clone_cable26 = this->getT(0).getT(1).getT(4).getT(0).getT(2).getT(0).getT(1);   // ArrangeNew_impl::clone_cable26_t<NV>
		auto& clone_cable27 = this->getT(0).getT(1).getT(4).getT(0).getT(2).getT(0).getT(2);   // ArrangeNew_impl::clone_cable27_t<NV>
		auto& split9 = this->getT(0).getT(2);                                                  // ArrangeNew_impl::split9_t<NV>
		auto& chain54 = this->getT(0).getT(2).getT(0);                                         // ArrangeNew_impl::chain54_t<NV>
		auto& chain55 = this->getT(0).getT(2).getT(0).getT(0);                                 // ArrangeNew_impl::chain55_t<NV>
		auto& chain56 = this->getT(0).getT(2).getT(0).getT(0).getT(0);                         // ArrangeNew_impl::chain56_t<NV>
		auto& split10 = this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(0);                 // ArrangeNew_impl::split10_t<NV>
		auto& branch11 = this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(0).getT(0);        // ArrangeNew_impl::branch11_t<NV>
		auto& chain91 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain91_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& global_cable16 = this->getT(0).getT(2).getT(0).getT(0).                          // ArrangeNew_impl::global_cable16_t<NV>
                               getT(0).getT(0).getT(0).getT(0).
                               getT(0);
		auto& pma76 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma76_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(1);
		auto& add76 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(2);
		auto& chain93 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain93_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& global_cable18 = this->getT(0).getT(2).getT(0).getT(0).                          // ArrangeNew_impl::global_cable18_t<NV>
                               getT(0).getT(0).getT(0).getT(1).
                               getT(0);
		auto& pma78 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma78_t<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(1);
		auto& add78 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(2);
		auto& chain92 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain92_t<NV>
                        getT(0).getT(0).getT(0).getT(2);
		auto& global_cable17 = this->getT(0).getT(2).getT(0).getT(0).                          // ArrangeNew_impl::global_cable17_t<NV>
                               getT(0).getT(0).getT(0).getT(2).
                               getT(0);
		auto& pma77 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma77_t<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(1);
		auto& add77 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(2);
		auto& chain66 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain66_t<NV>
                        getT(0).getT(0).getT(0).getT(3);
		auto& pma46 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma46_t<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(0);
		auto& add46 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(1);
		auto& chain67 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain67_t<NV>
                        getT(0).getT(0).getT(0).getT(4);
		auto& pma47 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma47_t<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add47 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(1);
		auto& branch7 = this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(0).getT(1);         // ArrangeNew_impl::branch7_t<NV>
		auto& chain57 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain57_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& midi20 = this->getT(0).getT(2).getT(0).getT(0).                                  // ArrangeNew_impl::midi20_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma37 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma37_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add37 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain58 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain58_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& midi21 = this->getT(0).getT(2).getT(0).getT(0).                                  // ArrangeNew_impl::midi21_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma38 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma38_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add38 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain59 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain59_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& midi22 = this->getT(0).getT(2).getT(0).getT(0).                                  // ArrangeNew_impl::midi22_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma39 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma39_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add39 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain60 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain60_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc18 = this->getT(0).getT(2).getT(0).getT(0).                               // ArrangeNew_impl::midi_cc18_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma40 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma40_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add40 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain61 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain61_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc19 = this->getT(0).getT(2).getT(0).getT(0).                               // ArrangeNew_impl::midi_cc19_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma41 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma41_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add41 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain62 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::chain62_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc20 = this->getT(0).getT(2).getT(0).getT(0).                               // ArrangeNew_impl::midi_cc20_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma42 = this->getT(0).getT(2).getT(0).getT(0).                                   // ArrangeNew_impl::pma42_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add42 = this->getT(0).getT(2).getT(0).getT(0).                                   // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak6 = this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(1);                   // ArrangeNew_impl::peak6_t<NV>
		auto& clear6 = this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(2);                  // math::clear<NV>
		auto& no_midi3 = this->getT(0).getT(2).getT(0).getT(0).getT(1);                        // ArrangeNew_impl::no_midi3_t<NV>
		auto& pack_resizer2 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(0);           // ArrangeNew_impl::pack_resizer2_t
		auto& pack_resizer5 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(1);           // ArrangeNew_impl::pack_resizer5_t
		auto& pack_resizer4 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(2);           // ArrangeNew_impl::pack_resizer4_t
		auto& split11 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3);                 // ArrangeNew_impl::split11_t<NV>
		auto& clone_pack2 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(0);     // ArrangeNew_impl::clone_pack2_t<NV>
		auto& clone_cable9 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(1);    // ArrangeNew_impl::clone_cable9_t<NV>
		auto& clone_forward11 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(2); // ArrangeNew_impl::clone_forward11_t<NV>
		auto& clone_forward14 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(3); // ArrangeNew_impl::clone_forward14_t<NV>
		auto& no_midi9 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(4);        // ArrangeNew_impl::no_midi9_t<NV>
		auto& split12 = this->getT(0).getT(2).getT(0).getT(0).                                 // ArrangeNew_impl::split12_t<NV>
                        getT(1).getT(3).getT(4).getT(0);
		auto& clone_cable1 = this->getT(0).getT(2).getT(0).getT(0).                          // ArrangeNew_impl::clone_cable1_t<NV>
                             getT(1).getT(3).getT(4).getT(0).
                             getT(0);
		auto& no_midi10 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(5);     // ArrangeNew_impl::no_midi10_t<NV>
		auto& split13 = this->getT(0).getT(2).getT(0).getT(0).                               // ArrangeNew_impl::split13_t<NV>
                        getT(1).getT(3).getT(5).getT(0);
		auto& clone_cable17 = this->getT(0).getT(2).getT(0).getT(0).                         // ArrangeNew_impl::clone_cable17_t<NV>
                              getT(1).getT(3).getT(5).getT(0).
                              getT(0);
		auto& no_midi11 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(6);     // ArrangeNew_impl::no_midi11_t<NV>
		auto& split14 = this->getT(0).getT(2).getT(0).getT(0).                               // ArrangeNew_impl::split14_t<NV>
                        getT(1).getT(3).getT(6).getT(0);
		auto& clone_forward12 = this->getT(0).getT(2).getT(0).getT(0).                       // ArrangeNew_impl::clone_forward12_t<NV>
                                getT(1).getT(3).getT(6).getT(0).
                                getT(0);
		auto& clone_cable19 = this->getT(0).getT(2).getT(0).getT(0).                         // ArrangeNew_impl::clone_cable19_t<NV>
                              getT(1).getT(3).getT(6).getT(0).
                              getT(1);
		auto& clone_cable20 = this->getT(0).getT(2).getT(0).getT(0).                         // ArrangeNew_impl::clone_cable20_t<NV>
                              getT(1).getT(3).getT(6).getT(0).
                              getT(2);
		auto& no_midi12 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(7);     // ArrangeNew_impl::no_midi12_t<NV>
		auto& split15 = this->getT(0).getT(2).getT(0).getT(0).                               // ArrangeNew_impl::split15_t<NV>
                        getT(1).getT(3).getT(7).getT(0);
		auto& clone_forward13 = this->getT(0).getT(2).getT(0).getT(0).                       // ArrangeNew_impl::clone_forward13_t<NV>
                                getT(1).getT(3).getT(7).getT(0).
                                getT(0);
		auto& clone_cable21 = this->getT(0).getT(2).getT(0).getT(0).                         // ArrangeNew_impl::clone_cable21_t<NV>
                              getT(1).getT(3).getT(7).getT(0).
                              getT(1);
		auto& clone_cable22 = this->getT(0).getT(2).getT(0).getT(0).                         // ArrangeNew_impl::clone_cable22_t<NV>
                              getT(1).getT(3).getT(7).getT(0).
                              getT(2);
		auto& clone_cable6 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(8);  // ArrangeNew_impl::clone_cable6_t<NV>
		auto& clone_cable5 = this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(9);  // ArrangeNew_impl::clone_cable5_t<NV>
		auto& split16 = this->getT(0).getT(3);                                               // ArrangeNew_impl::split16_t<NV>
		auto& chain99 = this->getT(0).getT(3).getT(0);                                       // ArrangeNew_impl::chain99_t<NV>
		auto& chain100 = this->getT(0).getT(3).getT(0).getT(0);                              // ArrangeNew_impl::chain100_t<NV>
		auto& chain101 = this->getT(0).getT(3).getT(0).getT(0).getT(0);                      // ArrangeNew_impl::chain101_t<NV>
		auto& split17 = this->getT(0).getT(3).getT(0).getT(0).getT(0).getT(0);               // ArrangeNew_impl::split17_t<NV>
		auto& branch13 = this->getT(0).getT(3).getT(0).getT(0).getT(0).getT(0).getT(0);      // ArrangeNew_impl::branch13_t<NV>
		auto& chain94 = this->getT(0).getT(3).getT(0).getT(0).                               // ArrangeNew_impl::chain94_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& global_cable19 = this->getT(0).getT(3).getT(0).getT(0).                        // ArrangeNew_impl::global_cable19_t<NV>
                               getT(0).getT(0).getT(0).getT(0).
                               getT(0);
		auto& pma91 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma91_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(1);
		auto& add91 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(2);
		auto& chain95 = this->getT(0).getT(3).getT(0).getT(0).                               // ArrangeNew_impl::chain95_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& global_cable20 = this->getT(0).getT(3).getT(0).getT(0).                        // ArrangeNew_impl::global_cable20_t<NV>
                               getT(0).getT(0).getT(0).getT(1).
                               getT(0);
		auto& pma92 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma92_t<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(1);
		auto& add92 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(2);
		auto& chain96 = this->getT(0).getT(3).getT(0).getT(0).                               // ArrangeNew_impl::chain96_t<NV>
                        getT(0).getT(0).getT(0).getT(2);
		auto& global_cable21 = this->getT(0).getT(3).getT(0).getT(0).                        // ArrangeNew_impl::global_cable21_t<NV>
                               getT(0).getT(0).getT(0).getT(2).
                               getT(0);
		auto& pma93 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma93_t<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(1);
		auto& add93 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(2);
		auto& chain68 = this->getT(0).getT(3).getT(0).getT(0).                               // ArrangeNew_impl::chain68_t<NV>
                        getT(0).getT(0).getT(0).getT(3);
		auto& pma48 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma48_t<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(0);
		auto& add48 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(1);
		auto& chain69 = this->getT(0).getT(3).getT(0).getT(0).                               // ArrangeNew_impl::chain69_t<NV>
                        getT(0).getT(0).getT(0).getT(4);
		auto& pma49 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma49_t<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add49 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(1);
		auto& branch12 = this->getT(0).getT(3).getT(0).getT(0).getT(0).getT(0).getT(1);      // ArrangeNew_impl::branch12_t<NV>
		auto& chain102 = this->getT(0).getT(3).getT(0).getT(0).                              // ArrangeNew_impl::chain102_t<NV>
                         getT(0).getT(0).getT(1).getT(0);
		auto& midi35 = this->getT(0).getT(3).getT(0).getT(0).                                // ArrangeNew_impl::midi35_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma67 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma67_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add67 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain103 = this->getT(0).getT(3).getT(0).getT(0).                              // ArrangeNew_impl::chain103_t<NV>
                         getT(0).getT(0).getT(1).getT(1);
		auto& midi36 = this->getT(0).getT(3).getT(0).getT(0).                                // ArrangeNew_impl::midi36_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma68 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma68_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add68 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain104 = this->getT(0).getT(3).getT(0).getT(0).                              // ArrangeNew_impl::chain104_t<NV>
                         getT(0).getT(0).getT(1).getT(2);
		auto& midi37 = this->getT(0).getT(3).getT(0).getT(0).                                // ArrangeNew_impl::midi37_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma69 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma69_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add69 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain105 = this->getT(0).getT(3).getT(0).getT(0).                              // ArrangeNew_impl::chain105_t<NV>
                         getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc33 = this->getT(0).getT(3).getT(0).getT(0).                             // ArrangeNew_impl::midi_cc33_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma70 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma70_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add70 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain106 = this->getT(0).getT(3).getT(0).getT(0).                              // ArrangeNew_impl::chain106_t<NV>
                         getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc34 = this->getT(0).getT(3).getT(0).getT(0).                             // ArrangeNew_impl::midi_cc34_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma71 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma71_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add71 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain107 = this->getT(0).getT(3).getT(0).getT(0).                              // ArrangeNew_impl::chain107_t<NV>
                         getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc35 = this->getT(0).getT(3).getT(0).getT(0).                             // ArrangeNew_impl::midi_cc35_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma72 = this->getT(0).getT(3).getT(0).getT(0).                                 // ArrangeNew_impl::pma72_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add72 = this->getT(0).getT(3).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak11 = this->getT(0).getT(3).getT(0).getT(0).getT(0).getT(1);                // ArrangeNew_impl::peak11_t<NV>
		auto& clear11 = this->getT(0).getT(3).getT(0).getT(0).getT(0).getT(2);               // math::clear<NV>
		auto& pack_resizer3 = this->getT(0).getT(3).getT(0).getT(0).getT(1);                 // ArrangeNew_impl::pack_resizer3_t
		auto& no_midi = this->getT(0).getT(3).getT(0).getT(0).getT(2);                       // ArrangeNew_impl::no_midi_t<NV>
		auto& split18 = this->getT(0).getT(3).getT(0).getT(0).getT(2).getT(0);               // ArrangeNew_impl::split18_t<NV>
		auto& clone_pack3 = this->getT(0).getT(3).getT(0).getT(0).getT(2).getT(0).getT(0);   // ArrangeNew_impl::clone_pack3_t<NV>
		auto& clone_cable14 = this->getT(0).getT(3).getT(0).getT(0).getT(2).getT(0).getT(1); // ArrangeNew_impl::clone_cable14_t<NV>
		auto& clone_cable13 = this->getT(0).getT(3).getT(0).getT(0).getT(2).getT(0).getT(2); // ArrangeNew_impl::clone_cable13_t<NV>
		auto& chain117 = this->getT(0).getT(3).getT(1);                                      // ArrangeNew_impl::chain117_t<NV>
		auto& chain118 = this->getT(0).getT(3).getT(1).getT(0);                              // ArrangeNew_impl::chain118_t<NV>
		auto& chain119 = this->getT(0).getT(3).getT(1).getT(0).getT(0);                      // ArrangeNew_impl::chain119_t<NV>
		auto& split20 = this->getT(0).getT(3).getT(1).getT(0).getT(0).getT(0);               // ArrangeNew_impl::split20_t<NV>
		auto& branch16 = this->getT(0).getT(3).getT(1).getT(0).getT(0).getT(0).getT(0);      // ArrangeNew_impl::branch16_t<NV>
		auto& chain97 = this->getT(0).getT(3).getT(1).getT(0).                               // ArrangeNew_impl::chain97_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& global_cable22 = this->getT(0).getT(3).getT(1).getT(0).                   // ArrangeNew_impl::global_cable22_t<NV>
                               getT(0).getT(0).getT(0).getT(0).
                               getT(0);
		auto& pma94 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma94_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(1);
		auto& add94 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(2);
		auto& chain108 = this->getT(0).getT(3).getT(1).getT(0).                         // ArrangeNew_impl::chain108_t<NV>
                         getT(0).getT(0).getT(0).getT(1);
		auto& global_cable24 = this->getT(0).getT(3).getT(1).getT(0).                   // ArrangeNew_impl::global_cable24_t<NV>
                               getT(0).getT(0).getT(0).getT(1).
                               getT(0);
		auto& pma96 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma96_t<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(1);
		auto& add96 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(2);
		auto& chain98 = this->getT(0).getT(3).getT(1).getT(0).                          // ArrangeNew_impl::chain98_t<NV>
                        getT(0).getT(0).getT(0).getT(2);
		auto& global_cable23 = this->getT(0).getT(3).getT(1).getT(0).                   // ArrangeNew_impl::global_cable23_t<NV>
                               getT(0).getT(0).getT(0).getT(2).
                               getT(0);
		auto& pma95 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma95_t<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(1);
		auto& add95 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(2);
		auto& chain70 = this->getT(0).getT(3).getT(1).getT(0).                          // ArrangeNew_impl::chain70_t<NV>
                        getT(0).getT(0).getT(0).getT(3);
		auto& pma50 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma50_t<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(0);
		auto& add50 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(1);
		auto& chain71 = this->getT(0).getT(3).getT(1).getT(0).                          // ArrangeNew_impl::chain71_t<NV>
                        getT(0).getT(0).getT(0).getT(4);
		auto& pma51 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma51_t<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add51 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(1);
		auto& branch14 = this->getT(0).getT(3).getT(1).getT(0).getT(0).getT(0).getT(1); // ArrangeNew_impl::branch14_t<NV>
		auto& chain120 = this->getT(0).getT(3).getT(1).getT(0).                         // ArrangeNew_impl::chain120_t<NV>
                         getT(0).getT(0).getT(1).getT(0);
		auto& midi41 = this->getT(0).getT(3).getT(1).getT(0).                           // ArrangeNew_impl::midi41_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma79 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma79_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add79 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain121 = this->getT(0).getT(3).getT(1).getT(0).                         // ArrangeNew_impl::chain121_t<NV>
                         getT(0).getT(0).getT(1).getT(1);
		auto& midi42 = this->getT(0).getT(3).getT(1).getT(0).                           // ArrangeNew_impl::midi42_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma80 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma80_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add80 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain122 = this->getT(0).getT(3).getT(1).getT(0).                         // ArrangeNew_impl::chain122_t<NV>
                         getT(0).getT(0).getT(1).getT(2);
		auto& midi43 = this->getT(0).getT(3).getT(1).getT(0).                           // ArrangeNew_impl::midi43_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma81 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma81_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add81 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain123 = this->getT(0).getT(3).getT(1).getT(0).                         // ArrangeNew_impl::chain123_t<NV>
                         getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc39 = this->getT(0).getT(3).getT(1).getT(0).                        // ArrangeNew_impl::midi_cc39_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma82 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma82_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add82 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain124 = this->getT(0).getT(3).getT(1).getT(0).                         // ArrangeNew_impl::chain124_t<NV>
                         getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc40 = this->getT(0).getT(3).getT(1).getT(0).                        // ArrangeNew_impl::midi_cc40_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma83 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma83_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add83 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain125 = this->getT(0).getT(3).getT(1).getT(0).                         // ArrangeNew_impl::chain125_t<NV>
                         getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc41 = this->getT(0).getT(3).getT(1).getT(0).                        // ArrangeNew_impl::midi_cc41_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma84 = this->getT(0).getT(3).getT(1).getT(0).                            // ArrangeNew_impl::pma84_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add84 = this->getT(0).getT(3).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak13 = this->getT(0).getT(3).getT(1).getT(0).getT(0).getT(1);           // ArrangeNew_impl::peak13_t<NV>
		auto& clear13 = this->getT(0).getT(3).getT(1).getT(0).getT(0).getT(2);          // math::clear<NV>
		auto& no_midi1 = this->getT(0).getT(3).getT(1).getT(0).getT(1);                 // ArrangeNew_impl::no_midi1_t<NV>
		auto& clone_cable10 = this->getT(0).getT(3).getT(1).getT(0).getT(1).getT(0);    // ArrangeNew_impl::clone_cable10_t<NV>
		auto& chain126 = this->getT(0).getT(3).getT(2);                                 // ArrangeNew_impl::chain126_t<NV>
		auto& chain127 = this->getT(0).getT(3).getT(2).getT(0);                         // ArrangeNew_impl::chain127_t<NV>
		auto& chain128 = this->getT(0).getT(3).getT(2).getT(0).getT(0);                 // ArrangeNew_impl::chain128_t<NV>
		auto& split21 = this->getT(0).getT(3).getT(2).getT(0).getT(0).getT(0);          // ArrangeNew_impl::split21_t<NV>
		auto& branch17 = this->getT(0).getT(3).getT(2).getT(0).getT(0).getT(0).getT(0); // ArrangeNew_impl::branch17_t<NV>
		auto& chain109 = this->getT(0).getT(3).getT(2).getT(0).                         // ArrangeNew_impl::chain109_t<NV>
                         getT(0).getT(0).getT(0).getT(0);
		auto& global_cable25 = this->getT(0).getT(3).getT(2).getT(0).                   // ArrangeNew_impl::global_cable25_t<NV>
                               getT(0).getT(0).getT(0).getT(0).
                               getT(0);
		auto& pma97 = this->getT(0).getT(3).getT(2).getT(0).                            // ArrangeNew_impl::pma97_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(1);
		auto& add97 = this->getT(0).getT(3).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(2);
		auto& chain111 = this->getT(0).getT(3).getT(2).getT(0).                         // ArrangeNew_impl::chain111_t<NV>
                         getT(0).getT(0).getT(0).getT(1);
		auto& global_cable27 = this->getT(0).getT(3).getT(2).getT(0).                   // ArrangeNew_impl::global_cable27_t<NV>
                               getT(0).getT(0).getT(0).getT(1).
                               getT(0);
		auto& pma99 = this->getT(0).getT(3).getT(2).getT(0).                            // ArrangeNew_impl::pma99_t<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(1);
		auto& add99 = this->getT(0).getT(3).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(2);
		auto& chain110 = this->getT(0).getT(3).getT(2).getT(0).                         // ArrangeNew_impl::chain110_t<NV>
                         getT(0).getT(0).getT(0).getT(2);
		auto& global_cable26 = this->getT(0).getT(3).getT(2).getT(0).                   // ArrangeNew_impl::global_cable26_t<NV>
                               getT(0).getT(0).getT(0).getT(2).
                               getT(0);
		auto& pma98 = this->getT(0).getT(3).getT(2).getT(0).                            // ArrangeNew_impl::pma98_t<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(1);
		auto& add98 = this->getT(0).getT(3).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(2);
		auto& chain72 = this->getT(0).getT(3).getT(2).getT(0).                          // ArrangeNew_impl::chain72_t<NV>
                        getT(0).getT(0).getT(0).getT(3);
		auto& pma52 = this->getT(0).getT(3).getT(2).getT(0).                            // ArrangeNew_impl::pma52_t<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(0);
		auto& add52 = this->getT(0).getT(3).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(0).getT(3).
                      getT(1);
		auto& chain73 = this->getT(0).getT(3).getT(2).getT(0).                          // ArrangeNew_impl::chain73_t<NV>
                        getT(0).getT(0).getT(0).getT(4);
		auto& pma53 = this->getT(0).getT(3).getT(2).getT(0).                            // ArrangeNew_impl::pma53_t<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add53 = this->getT(0).getT(3).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(1);
		auto& branch15 = this->getT(0).getT(3).getT(2).getT(0).getT(0).getT(0).getT(1); // ArrangeNew_impl::branch15_t<NV>
		auto& chain129 = this->getT(0).getT(3).getT(2).getT(0).                         // ArrangeNew_impl::chain129_t<NV>
                         getT(0).getT(0).getT(1).getT(0);
		auto& midi44 = this->getT(0).getT(3).getT(2).getT(0).                        // ArrangeNew_impl::midi44_t<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& pma85 = this->getT(0).getT(3).getT(2).getT(0).                         // ArrangeNew_impl::pma85_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& add85 = this->getT(0).getT(3).getT(2).getT(0).                         // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain130 = this->getT(0).getT(3).getT(2).getT(0).                      // ArrangeNew_impl::chain130_t<NV>
                         getT(0).getT(0).getT(1).getT(1);
		auto& midi45 = this->getT(0).getT(3).getT(2).getT(0).                        // ArrangeNew_impl::midi45_t<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(0);
		auto& pma86 = this->getT(0).getT(3).getT(2).getT(0).                         // ArrangeNew_impl::pma86_t<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& add86 = this->getT(0).getT(3).getT(2).getT(0).                         // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(2);
		auto& chain131 = this->getT(0).getT(3).getT(2).getT(0).                      // ArrangeNew_impl::chain131_t<NV>
                         getT(0).getT(0).getT(1).getT(2);
		auto& midi46 = this->getT(0).getT(3).getT(2).getT(0).                        // ArrangeNew_impl::midi46_t<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(0);
		auto& pma87 = this->getT(0).getT(3).getT(2).getT(0).                         // ArrangeNew_impl::pma87_t<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& add87 = this->getT(0).getT(3).getT(2).getT(0).                         // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(2);
		auto& chain132 = this->getT(0).getT(3).getT(2).getT(0).                      // ArrangeNew_impl::chain132_t<NV>
                         getT(0).getT(0).getT(1).getT(3);
		auto& midi_cc42 = this->getT(0).getT(3).getT(2).getT(0).                     // ArrangeNew_impl::midi_cc42_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& pma88 = this->getT(0).getT(3).getT(2).getT(0).                         // ArrangeNew_impl::pma88_t<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& add88 = this->getT(0).getT(3).getT(2).getT(0).                         // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(2);
		auto& chain133 = this->getT(0).getT(3).getT(2).getT(0).                      // ArrangeNew_impl::chain133_t<NV>
                         getT(0).getT(0).getT(1).getT(4);
		auto& midi_cc43 = this->getT(0).getT(3).getT(2).getT(0).                     // ArrangeNew_impl::midi_cc43_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& pma89 = this->getT(0).getT(3).getT(2).getT(0).                         // ArrangeNew_impl::pma89_t<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& add89 = this->getT(0).getT(3).getT(2).getT(0).                         // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(2);
		auto& chain134 = this->getT(0).getT(3).getT(2).getT(0).                      // ArrangeNew_impl::chain134_t<NV>
                         getT(0).getT(0).getT(1).getT(5);
		auto& midi_cc44 = this->getT(0).getT(3).getT(2).getT(0).                     // ArrangeNew_impl::midi_cc44_t<NV>
                          getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma90 = this->getT(0).getT(3).getT(2).getT(0).                         // ArrangeNew_impl::pma90_t<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& add90 = this->getT(0).getT(3).getT(2).getT(0).                         // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(2);
		auto& peak14 = this->getT(0).getT(3).getT(2).getT(0).getT(0).getT(1);        // ArrangeNew_impl::peak14_t<NV>
		auto& clear14 = this->getT(0).getT(3).getT(2).getT(0).getT(0).getT(2);       // math::clear<NV>
		auto& no_midi2 = this->getT(0).getT(3).getT(2).getT(0).getT(1);              // ArrangeNew_impl::no_midi2_t<NV>
		auto& clone_cable11 = this->getT(0).getT(3).getT(2).getT(0).getT(1).getT(0); // ArrangeNew_impl::clone_cable11_t<NV>
		auto& clone = this->getT(1);                                                 // ArrangeNew_impl::clone_t<NV>                                                 // ArrangeNew_impl::clone_child_t<NV>
		auto chain74 = this->getT(1).getT(0);                                        // ArrangeNew_impl::chain74_t<NV>
		auto input_toggle = this->getT(1).getT(0).getT(0);                           // ArrangeNew_impl::input_toggle_t<NV>
		auto input_toggle32 = this->getT(1).getT(0).getT(1);                         // ArrangeNew_impl::input_toggle32_t<NV>
		auto input_toggle35 = this->getT(1).getT(0).getT(2);                         // ArrangeNew_impl::input_toggle35_t<NV>
		auto input_toggle34 = this->getT(1).getT(0).getT(3);                         // ArrangeNew_impl::input_toggle34_t<NV>
		auto input_toggle36 = this->getT(1).getT(0).getT(4);                         // ArrangeNew_impl::input_toggle36_t<NV>
		auto input_toggle37 = this->getT(1).getT(0).getT(5);                         // ArrangeNew_impl::input_toggle37_t<NV>
		auto input_toggle38 = this->getT(1).getT(0).getT(6);                         // ArrangeNew_impl::input_toggle38_t<NV>
		auto xnode1 = this->getT(1).getT(1);                                         // ArrangeNew_impl::xnode1_t<NV>
		auto jpanner = this->getT(1).getT(2);                                        // jdsp::jpanner<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& Harm_p = this->getParameterT(0);
		Harm_p.connectT(0, pma);   // Harm -> pma::Add
		Harm_p.connectT(1, pma13); // Harm -> pma13::Add
		Harm_p.connectT(2, pma56); // Harm -> pma56::Add
		Harm_p.connectT(3, pma55); // Harm -> pma55::Add
		Harm_p.connectT(4, pma54); // Harm -> pma54::Add
		
		auto& HarmMod_p = this->getParameterT(1);
		HarmMod_p.connectT(0, pma);   // HarmMod -> pma::Multiply
		HarmMod_p.connectT(1, pma13); // HarmMod -> pma13::Multiply
		HarmMod_p.connectT(2, pma56); // HarmMod -> pma56::Multiply
		HarmMod_p.connectT(3, pma54); // HarmMod -> pma54::Multiply
		HarmMod_p.connectT(4, pma55); // HarmMod -> pma55::Multiply
		
		this->getParameterT(2).connectT(0, branch); // HarmSrc -> branch::Index
		
		auto& HarmAux_p = this->getParameterT(3);
		HarmAux_p.connectT(0, pma1); // HarmAux -> pma1::Multiply
		HarmAux_p.connectT(1, pma2); // HarmAux -> pma2::Multiply
		HarmAux_p.connectT(2, pma3); // HarmAux -> pma3::Multiply
		HarmAux_p.connectT(3, pma4); // HarmAux -> pma4::Multiply
		HarmAux_p.connectT(4, pma5); // HarmAux -> pma5::Multiply
		HarmAux_p.connectT(5, pma6); // HarmAux -> pma6::Multiply
		
		this->getParameterT(4).connectT(0, branch1); // HarmAuxSrc -> branch1::Index
		
		this->getParameterT(5).connectT(0, clone_forward); // Min -> clone_forward::Value
		
		this->getParameterT(6).connectT(0, clone_forward2); // Max -> clone_forward2::Value
		
		this->getParameterT(7).connectT(0, clone_forward1); // Step -> clone_forward1::Value
		
		auto& Detune_p = this->getParameterT(8);
		Detune_p.connectT(0, pma14); // Detune -> pma14::Add
		Detune_p.connectT(1, pma15); // Detune -> pma15::Add
		Detune_p.connectT(2, pma59); // Detune -> pma59::Add
		Detune_p.connectT(3, pma58); // Detune -> pma58::Add
		Detune_p.connectT(4, pma57); // Detune -> pma57::Add
		
		auto& DetuneMod_p = this->getParameterT(9);
		DetuneMod_p.connectT(0, pma14); // DetuneMod -> pma14::Multiply
		DetuneMod_p.connectT(1, pma15); // DetuneMod -> pma15::Multiply
		DetuneMod_p.connectT(2, pma57); // DetuneMod -> pma57::Multiply
		DetuneMod_p.connectT(3, pma59); // DetuneMod -> pma59::Multiply
		DetuneMod_p.connectT(4, pma58); // DetuneMod -> pma58::Multiply
		
		this->getParameterT(10).connectT(0, branch3); // DetuneSrc -> branch3::Index
		
		auto& DetuneAux_p = this->getParameterT(11);
		DetuneAux_p.connectT(0, pma7);  // DetuneAux -> pma7::Multiply
		DetuneAux_p.connectT(1, pma8);  // DetuneAux -> pma8::Multiply
		DetuneAux_p.connectT(2, pma9);  // DetuneAux -> pma9::Multiply
		DetuneAux_p.connectT(3, pma10); // DetuneAux -> pma10::Multiply
		DetuneAux_p.connectT(4, pma11); // DetuneAux -> pma11::Multiply
		DetuneAux_p.connectT(5, pma12); // DetuneAux -> pma12::Multiply
		
		this->getParameterT(12).connectT(0, branch2); // DetuneAuxSrc -> branch2::Index
		
		this->getParameterT(13).connectT(0, clone_forward6); // OscType -> clone_forward6::Value
		
		auto& Shape_p = this->getParameterT(14);
		Shape_p.connectT(0, pma16); // Shape -> pma16::Add
		Shape_p.connectT(1, pma17); // Shape -> pma17::Add
		Shape_p.connectT(2, pma62); // Shape -> pma62::Add
		Shape_p.connectT(3, pma63); // Shape -> pma63::Add
		Shape_p.connectT(4, pma61); // Shape -> pma61::Add
		
		auto& ShapeMod_p = this->getParameterT(15);
		ShapeMod_p.connectT(0, pma16); // ShapeMod -> pma16::Multiply
		ShapeMod_p.connectT(1, pma17); // ShapeMod -> pma17::Multiply
		ShapeMod_p.connectT(2, pma61); // ShapeMod -> pma61::Multiply
		ShapeMod_p.connectT(3, pma63); // ShapeMod -> pma63::Multiply
		ShapeMod_p.connectT(4, pma62); // ShapeMod -> pma62::Multiply
		
		this->getParameterT(16).connectT(0, branch8); // ShapeSrc -> branch8::Index
		
		auto& ShapeAux_p = this->getParameterT(17);
		ShapeAux_p.connectT(0, pma19); // ShapeAux -> pma19::Multiply
		ShapeAux_p.connectT(1, pma20); // ShapeAux -> pma20::Multiply
		ShapeAux_p.connectT(2, pma21); // ShapeAux -> pma21::Multiply
		ShapeAux_p.connectT(3, pma22); // ShapeAux -> pma22::Multiply
		ShapeAux_p.connectT(4, pma23); // ShapeAux -> pma23::Multiply
		ShapeAux_p.connectT(5, pma24); // ShapeAux -> pma24::Multiply
		
		this->getParameterT(18).connectT(0, branch4); // ShapeAuxSrc -> branch4::Index
		
		this->getParameterT(19).connectT(0, clone_forward7); // VoiceMode -> clone_forward7::Value
		
		auto& CyclePos_p = this->getParameterT(20);
		CyclePos_p.connectT(0, pma18); // CyclePos -> pma18::Add
		CyclePos_p.connectT(1, pma43); // CyclePos -> pma43::Add
		CyclePos_p.connectT(2, pma64); // CyclePos -> pma64::Add
		CyclePos_p.connectT(3, pma66); // CyclePos -> pma66::Add
		CyclePos_p.connectT(4, pma65); // CyclePos -> pma65::Add
		
		auto& CyclePosMod_p = this->getParameterT(21);
		CyclePosMod_p.connectT(0, pma18); // CyclePosMod -> pma18::Multiply
		CyclePosMod_p.connectT(1, pma43); // CyclePosMod -> pma43::Multiply
		CyclePosMod_p.connectT(2, pma64); // CyclePosMod -> pma64::Multiply
		CyclePosMod_p.connectT(3, pma66); // CyclePosMod -> pma66::Multiply
		CyclePosMod_p.connectT(4, pma65); // CyclePosMod -> pma65::Multiply
		
		this->getParameterT(22).connectT(0, branch9); // CyclePosSrc -> branch9::Index
		
		auto& CyclePosAux_p = this->getParameterT(23);
		CyclePosAux_p.connectT(0, pma25); // CyclePosAux -> pma25::Multiply
		CyclePosAux_p.connectT(1, pma26); // CyclePosAux -> pma26::Multiply
		CyclePosAux_p.connectT(2, pma27); // CyclePosAux -> pma27::Multiply
		CyclePosAux_p.connectT(3, pma28); // CyclePosAux -> pma28::Multiply
		CyclePosAux_p.connectT(4, pma29); // CyclePosAux -> pma29::Multiply
		CyclePosAux_p.connectT(5, pma30); // CyclePosAux -> pma30::Multiply
		
		this->getParameterT(24).connectT(0, branch5); // CyclePosAuxSrc -> branch5::Index
		
		auto& CycleShape_p = this->getParameterT(25);
		CycleShape_p.connectT(0, pma44); // CycleShape -> pma44::Add
		CycleShape_p.connectT(1, pma45); // CycleShape -> pma45::Add
		CycleShape_p.connectT(2, pma73); // CycleShape -> pma73::Add
		CycleShape_p.connectT(3, pma75); // CycleShape -> pma75::Add
		CycleShape_p.connectT(4, pma74); // CycleShape -> pma74::Add
		
		auto& CycleShapeMod_p = this->getParameterT(26);
		CycleShapeMod_p.connectT(0, pma44); // CycleShapeMod -> pma44::Multiply
		CycleShapeMod_p.connectT(1, pma45); // CycleShapeMod -> pma45::Multiply
		CycleShapeMod_p.connectT(2, pma73); // CycleShapeMod -> pma73::Multiply
		CycleShapeMod_p.connectT(3, pma75); // CycleShapeMod -> pma75::Multiply
		CycleShapeMod_p.connectT(4, pma74); // CycleShapeMod -> pma74::Multiply
		
		this->getParameterT(27).connectT(0, branch10); // CycleShapeSrc -> branch10::Index
		
		auto& CycleShapeAux_p = this->getParameterT(28);
		CycleShapeAux_p.connectT(0, pma31); // CycleShapeAux -> pma31::Multiply
		CycleShapeAux_p.connectT(1, pma32); // CycleShapeAux -> pma32::Multiply
		CycleShapeAux_p.connectT(2, pma33); // CycleShapeAux -> pma33::Multiply
		CycleShapeAux_p.connectT(3, pma34); // CycleShapeAux -> pma34::Multiply
		CycleShapeAux_p.connectT(4, pma35); // CycleShapeAux -> pma35::Multiply
		CycleShapeAux_p.connectT(5, pma36); // CycleShapeAux -> pma36::Multiply
		
		this->getParameterT(29).connectT(0, branch6); // CycleShapeAuxSrc -> branch6::Index
		
		auto& FxValue_p = this->getParameterT(30);
		FxValue_p.connectT(0, pma46); // FxValue -> pma46::Add
		FxValue_p.connectT(1, pma47); // FxValue -> pma47::Add
		FxValue_p.connectT(2, pma76); // FxValue -> pma76::Add
		FxValue_p.connectT(3, pma78); // FxValue -> pma78::Add
		FxValue_p.connectT(4, pma77); // FxValue -> pma77::Add
		
		auto& FxValueMod_p = this->getParameterT(31);
		FxValueMod_p.connectT(0, pma46); // FxValueMod -> pma46::Multiply
		FxValueMod_p.connectT(1, pma47); // FxValueMod -> pma47::Multiply
		FxValueMod_p.connectT(2, pma76); // FxValueMod -> pma76::Multiply
		FxValueMod_p.connectT(3, pma78); // FxValueMod -> pma78::Multiply
		FxValueMod_p.connectT(4, pma77); // FxValueMod -> pma77::Multiply
		
		this->getParameterT(32).connectT(0, branch11); // FxValueSrc -> branch11::Index
		
		auto& FxValueAux_p = this->getParameterT(33);
		FxValueAux_p.connectT(0, pma37); // FxValueAux -> pma37::Multiply
		FxValueAux_p.connectT(1, pma38); // FxValueAux -> pma38::Multiply
		FxValueAux_p.connectT(2, pma39); // FxValueAux -> pma39::Multiply
		FxValueAux_p.connectT(3, pma40); // FxValueAux -> pma40::Multiply
		FxValueAux_p.connectT(4, pma41); // FxValueAux -> pma41::Multiply
		FxValueAux_p.connectT(5, pma42); // FxValueAux -> pma42::Multiply
		
		this->getParameterT(34).connectT(0, branch7); // FxValueAuxSrvc -> branch7::Index
		
		this->getParameterT(36).connectT(0, clone_cable17); // FxDiv -> clone_cable17::Value
		
		this->getParameterT(38).connectT(0, clone_cable5); // FxSinSh -> clone_cable5::Value
		
		auto& FxtoPitch_p = this->getParameterT(39);
		FxtoPitch_p.connectT(0, clone_forward12); // FxtoPitch -> clone_forward12::Value
		FxtoPitch_p.connectT(1, clone_cable19);   // FxtoPitch -> clone_cable19::Value
		
		auto& FxtoCut_p = this->getParameterT(40);
		FxtoCut_p.connectT(0, clone_forward13); // FxtoCut -> clone_forward13::Value
		FxtoCut_p.connectT(1, clone_cable21);   // FxtoCut -> clone_cable21::Value
		
		auto& Cut_p = this->getParameterT(41);
		Cut_p.connectT(0, pma48); // Cut -> pma48::Add
		Cut_p.connectT(1, pma49); // Cut -> pma49::Add
		Cut_p.connectT(2, pma91); // Cut -> pma91::Add
		Cut_p.connectT(3, pma92); // Cut -> pma92::Add
		Cut_p.connectT(4, pma93); // Cut -> pma93::Add
		
		auto& CutMod_p = this->getParameterT(42);
		CutMod_p.connectT(0, pma48); // CutMod -> pma48::Multiply
		CutMod_p.connectT(1, pma49); // CutMod -> pma49::Multiply
		CutMod_p.connectT(2, pma91); // CutMod -> pma91::Multiply
		CutMod_p.connectT(3, pma92); // CutMod -> pma92::Multiply
		CutMod_p.connectT(4, pma93); // CutMod -> pma93::Multiply
		
		this->getParameterT(43).connectT(0, branch13); // CutSrc -> branch13::Index
		
		auto& CutAux_p = this->getParameterT(44);
		CutAux_p.connectT(0, pma67); // CutAux -> pma67::Multiply
		CutAux_p.connectT(1, pma68); // CutAux -> pma68::Multiply
		CutAux_p.connectT(2, pma69); // CutAux -> pma69::Multiply
		CutAux_p.connectT(3, pma70); // CutAux -> pma70::Multiply
		CutAux_p.connectT(4, pma71); // CutAux -> pma71::Multiply
		CutAux_p.connectT(5, pma72); // CutAux -> pma72::Multiply
		
		this->getParameterT(45).connectT(0, branch12); // CutAuxSrc -> branch12::Index
		
		this->getParameterT(46).connectT(0, clone_cable14); // FilterMode -> clone_cable14::Value
		
		auto& Res_p = this->getParameterT(47);
		Res_p.connectT(0, pma50); // Res -> pma50::Add
		Res_p.connectT(1, pma51); // Res -> pma51::Add
		Res_p.connectT(2, pma94); // Res -> pma94::Add
		Res_p.connectT(3, pma96); // Res -> pma96::Add
		Res_p.connectT(4, pma95); // Res -> pma95::Add
		
		auto& ResMod_p = this->getParameterT(48);
		ResMod_p.connectT(0, pma50); // ResMod -> pma50::Multiply
		ResMod_p.connectT(1, pma51); // ResMod -> pma51::Multiply
		ResMod_p.connectT(2, pma94); // ResMod -> pma94::Multiply
		ResMod_p.connectT(3, pma96); // ResMod -> pma96::Multiply
		ResMod_p.connectT(4, pma95); // ResMod -> pma95::Multiply
		
		this->getParameterT(49).connectT(0, branch16); // ResSrc -> branch16::Index
		
		auto& ResAux_p = this->getParameterT(50);
		ResAux_p.connectT(0, pma79); // ResAux -> pma79::Multiply
		ResAux_p.connectT(1, pma80); // ResAux -> pma80::Multiply
		ResAux_p.connectT(2, pma81); // ResAux -> pma81::Multiply
		ResAux_p.connectT(3, pma82); // ResAux -> pma82::Multiply
		ResAux_p.connectT(4, pma83); // ResAux -> pma83::Multiply
		ResAux_p.connectT(5, pma84); // ResAux -> pma84::Multiply
		
		this->getParameterT(51).connectT(0, branch14); // ResAuxSrc -> branch14::Index
		
		auto& FilterMix_p = this->getParameterT(52);
		FilterMix_p.connectT(0, pma52); // FilterMix -> pma52::Add
		FilterMix_p.connectT(1, pma53); // FilterMix -> pma53::Add
		FilterMix_p.connectT(2, pma97); // FilterMix -> pma97::Add
		FilterMix_p.connectT(3, pma99); // FilterMix -> pma99::Add
		FilterMix_p.connectT(4, pma98); // FilterMix -> pma98::Add
		
		auto& FilterMixMod_p = this->getParameterT(53);
		FilterMixMod_p.connectT(0, pma52); // FilterMixMod -> pma52::Multiply
		FilterMixMod_p.connectT(1, pma53); // FilterMixMod -> pma53::Multiply
		FilterMixMod_p.connectT(2, pma97); // FilterMixMod -> pma97::Multiply
		FilterMixMod_p.connectT(3, pma99); // FilterMixMod -> pma99::Multiply
		FilterMixMod_p.connectT(4, pma98); // FilterMixMod -> pma98::Multiply
		
		this->getParameterT(54).connectT(0, branch17); // FilterMixSrc -> branch17::Index
		
		auto& FilterMixAux_p = this->getParameterT(55);
		FilterMixAux_p.connectT(0, pma85); // FilterMixAux -> pma85::Multiply
		FilterMixAux_p.connectT(1, pma86); // FilterMixAux -> pma86::Multiply
		FilterMixAux_p.connectT(2, pma87); // FilterMixAux -> pma87::Multiply
		FilterMixAux_p.connectT(3, pma88); // FilterMixAux -> pma88::Multiply
		FilterMixAux_p.connectT(4, pma89); // FilterMixAux -> pma89::Multiply
		FilterMixAux_p.connectT(5, pma90); // FilterMixAux -> pma90::Multiply
		
		this->getParameterT(56).connectT(0, branch15); // FilterMixAuxSrc -> branch15::Index
		
		this->getParameterT(57).connectT(0, clone_cable13); // Spread -> clone_cable13::Value
		
		this->getParameterT(59).connectT(0, clone_cable1); // FxtoGain -> clone_cable1::Value
		
		this->getParameterT(60).connectT(0, Env3); // EnvTempo1 -> Env3::Tempo
		
		this->getParameterT(61).connectT(0, Env3); // EnvDiv1 -> Env3::Multi
		
		this->getParameterT(62).connectT(0, Env3); // EnvA1 -> Env3::a
		
		this->getParameterT(63).connectT(0, Env3); // EnvD1 -> Env3::d
		
		this->getParameterT(64).connectT(0, Env3); // EnvH1 -> Env3::h
		
		this->getParameterT(65).connectT(0, Env3); // EnvS1 -> Env3::s
		
		this->getParameterT(66).connectT(0, Env3); // EnvR1 -> Env3::r
		
		this->getParameterT(67).connectT(0, Env3); // EnvTrig1 -> Env3::trig
		
		this->getParameterT(68).connectT(0, Env4); // EnvTempo2 -> Env4::Tempo
		
		this->getParameterT(69).connectT(0, Env4); // EnvDiv2 -> Env4::Multi
		
		this->getParameterT(70).connectT(0, Env4); // EnvA2 -> Env4::a
		
		this->getParameterT(71).connectT(0, Env4); // EnvD2 -> Env4::d
		
		this->getParameterT(72).connectT(0, Env4); // EnvH2 -> Env4::h
		
		this->getParameterT(73).connectT(0, Env4); // EnvS2 -> Env4::s
		
		this->getParameterT(74).connectT(0, Env4); // EnvR2 -> Env4::r
		
		this->getParameterT(75).connectT(0, Env4); // EnvTrig2 -> Env4::trig
		
		this->getParameterT(76).connectT(0, clone_forward8); // Stages2 -> clone_forward8::NumClones
		
		this->getParameterT(77).connectT(0, clone_cable32); // posdiv -> clone_cable32::Value
		
		this->getParameterT(78).connectT(0, clone_cable31); // PosMode -> clone_cable31::Value
		
		this->getParameterT(79).connectT(0, clone_forward8); // Quant -> clone_forward8::Value
		
		this->getParameterT(80).connectT(0, clone_cable8); // PosSpread -> clone_cable8::Value
		
		this->getParameterT(85).connectT(0, clone_cable24); // OscShapeSpread -> clone_cable24::Value
		
		this->getParameterT(86).connectT(0, clone_cable27); // OscShpSprd -> clone_cable27::Value
		
		auto& V1_p = this->getParameterT(87);
		V1_p.connectT(0, pack_resizer);   // V1 -> pack_resizer::NumSliders
		V1_p.connectT(1, clone_pack);     // V1 -> clone_pack::NumClones
		V1_p.connectT(2, clone_forward);  // V1 -> clone_forward::NumClones
		V1_p.connectT(3, clone_forward2); // V1 -> clone_forward2::NumClones
		V1_p.connectT(4, clone_forward1); // V1 -> clone_forward1::NumClones
		V1_p.connectT(5, clone_forward6); // V1 -> clone_forward6::NumClones
		V1_p.connectT(6, clone_forward7); // V1 -> clone_forward7::NumClones
		V1_p.connectT(7, clone_cable);    // V1 -> clone_cable::NumClones
		V1_p.connectT(8, clone_cable2);   // V1 -> clone_cable2::NumClones
		V1_p.connectT(9, clone_cable23);  // V1 -> clone_cable23::NumClones
		V1_p.connectT(10, clone_cable24); // V1 -> clone_cable24::NumClones
		V1_p.connectT(11, clone_cable3);  // V1 -> clone_cable3::NumClones
		V1_p.connectT(12, clone_cable7);  // V1 -> clone_cable7::NumClones
		V1_p.connectT(13, clone_cable8);  // V1 -> clone_cable8::NumClones
		V1_p.connectT(14, clone_cable4);  // V1 -> clone_cable4::NumClones
		V1_p.connectT(15, clone_cable26); // V1 -> clone_cable26::NumClones
		V1_p.connectT(16, clone_cable27); // V1 -> clone_cable27::NumClones
		V1_p.connectT(17, clone_cable29); // V1 -> clone_cable29::NumClones
		V1_p.connectT(18, clone_cable28); // V1 -> clone_cable28::NumClones
		V1_p.connectT(19, clone_cable30); // V1 -> clone_cable30::NumClones
		
		auto& V2_p = this->getParameterT(88);
		V2_p.connectT(0, clone_pack2);      // V2 -> clone_pack2::NumClones
		V2_p.connectT(1, clone_forward11);  // V2 -> clone_forward11::NumClones
		V2_p.connectT(2, clone_cable1);     // V2 -> clone_cable1::NumClones
		V2_p.connectT(3, clone_cable17);    // V2 -> clone_cable17::NumClones
		V2_p.connectT(4, clone_forward12);  // V2 -> clone_forward12::NumClones
		V2_p.connectT(5, clone_cable19);    // V2 -> clone_cable19::NumClones
		V2_p.connectT(6, clone_forward13);  // V2 -> clone_forward13::NumClones
		V2_p.connectT(7, clone_cable21);    // V2 -> clone_cable21::NumClones
		V2_p.connectT(8, clone_cable22);    // V2 -> clone_cable22::NumClones
		V2_p.connectT(9, clone_cable6);     // V2 -> clone_cable6::NumClones
		V2_p.connectT(10, clone_cable5);    // V2 -> clone_cable5::NumClones
		V2_p.connectT(11, clone_pack3);     // V2 -> clone_pack3::NumClones
		V2_p.connectT(12, pack_resizer3);   // V2 -> pack_resizer3::NumSliders
		V2_p.connectT(13, clone_cable14);   // V2 -> clone_cable14::NumClones
		V2_p.connectT(14, clone_cable13);   // V2 -> clone_cable13::NumClones
		V2_p.connectT(15, clone_cable10);   // V2 -> clone_cable10::NumClones
		V2_p.connectT(16, clone_cable11);   // V2 -> clone_cable11::NumClones
		V2_p.connectT(17, pack_resizer2);   // V2 -> pack_resizer2::NumSliders
		V2_p.connectT(18, pack_resizer5);   // V2 -> pack_resizer5::NumSliders
		V2_p.connectT(19, pack_resizer4);   // V2 -> pack_resizer4::NumSliders
		V2_p.connectT(20, clone_forward14); // V2 -> clone_forward14::NumClones
		V2_p.connectT(21, clone_cable32);   // V2 -> clone_cable32::NumClones
		V2_p.connectT(22, clone_cable31);   // V2 -> clone_cable31::NumClones
		
		auto& V3_p = this->getParameterT(89);
		V3_p.connectT(0, clone);         // V3 -> clone::NumClones
		V3_p.connectT(1, clone_cable20); // V3 -> clone_cable20::NumClones
		
		this->getParameterT(90).connectT(0, clone_cable9); // ModPhase -> clone_cable9::Value
		
		this->getParameterT(91).connectT(0, clone_cable9); // V5 -> clone_cable9::NumClones
		
		this->getParameterT(92).connectT(0, clone_cable6); // SMOOTH -> clone_cable6::Value
		
		this->getParameterT(93).connectT(0, Env3); // EnvMode1 -> Env3::mode
		
		this->getParameterT(94).connectT(0, Env4); // EnvMode2 -> Env4::mode
		
		this->getParameterT(95).connectT(0, clone_forward11); // FileGainRest -> clone_forward11::Value
		
		this->getParameterT(96).connectT(0, clone_forward14); // FileGainSmooth -> clone_forward14::Value
		
		this->getParameterT(97).connectT(0, clone_cable28); // DetSprd -> clone_cable28::Value
		
		this->getParameterT(98).connectT(0, clone_cable30); // PitchSmooth -> clone_cable30::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma.getWrappedObject().getParameter().connectT(0, add);                        // pma -> add::Value
		pma14.getWrappedObject().getParameter().connectT(0, add14);                    // pma14 -> add14::Value
		pma16.getWrappedObject().getParameter().connectT(0, add16);                    // pma16 -> add16::Value
		pma18.getWrappedObject().getParameter().connectT(0, add18);                    // pma18 -> add18::Value
		pma44.getWrappedObject().getParameter().connectT(0, add44);                    // pma44 -> add44::Value
		pma46.getWrappedObject().getParameter().connectT(0, add46);                    // pma46 -> add46::Value
		pma48.getWrappedObject().getParameter().connectT(0, add48);                    // pma48 -> add48::Value
		pma50.getWrappedObject().getParameter().connectT(0, add50);                    // pma50 -> add50::Value
		pma52.getWrappedObject().getParameter().connectT(0, add52);                    // pma52 -> add52::Value
		peak2.getParameter().connectT(0, pma);                                         // peak2 -> pma::Value
		peak2.getParameter().connectT(1, pma14);                                       // peak2 -> pma14::Value
		peak2.getParameter().connectT(2, pma16);                                       // peak2 -> pma16::Value
		peak2.getParameter().connectT(3, pma18);                                       // peak2 -> pma18::Value
		peak2.getParameter().connectT(4, pma44);                                       // peak2 -> pma44::Value
		peak2.getParameter().connectT(5, pma46);                                       // peak2 -> pma46::Value
		peak2.getParameter().connectT(6, pma48);                                       // peak2 -> pma48::Value
		peak2.getParameter().connectT(7, pma50);                                       // peak2 -> pma50::Value
		peak2.getParameter().connectT(8, pma52);                                       // peak2 -> pma52::Value
		pma13.getWrappedObject().getParameter().connectT(0, add13);                    // pma13 -> add13::Value
		pma15.getWrappedObject().getParameter().connectT(0, add15);                    // pma15 -> add15::Value
		pma17.getWrappedObject().getParameter().connectT(0, add17);                    // pma17 -> add17::Value
		pma43.getWrappedObject().getParameter().connectT(0, add43);                    // pma43 -> add43::Value
		pma45.getWrappedObject().getParameter().connectT(0, add45);                    // pma45 -> add45::Value
		pma47.getWrappedObject().getParameter().connectT(0, add47);                    // pma47 -> add47::Value
		pma49.getWrappedObject().getParameter().connectT(0, add49);                    // pma49 -> add49::Value
		pma51.getWrappedObject().getParameter().connectT(0, add51);                    // pma51 -> add51::Value
		pma53.getWrappedObject().getParameter().connectT(0, add53);                    // pma53 -> add53::Value
		peak7.getParameter().connectT(0, pma13);                                       // peak7 -> pma13::Value
		peak7.getParameter().connectT(1, pma15);                                       // peak7 -> pma15::Value
		peak7.getParameter().connectT(2, pma17);                                       // peak7 -> pma17::Value
		peak7.getParameter().connectT(3, pma43);                                       // peak7 -> pma43::Value
		peak7.getParameter().connectT(4, pma45);                                       // peak7 -> pma45::Value
		peak7.getParameter().connectT(5, pma47);                                       // peak7 -> pma47::Value
		peak7.getParameter().connectT(6, pma49);                                       // peak7 -> pma49::Value
		peak7.getParameter().connectT(7, pma51);                                       // peak7 -> pma51::Value
		peak7.getParameter().connectT(8, pma53);                                       // peak7 -> pma53::Value
		pma54.getWrappedObject().getParameter().connectT(0, add54);                    // pma54 -> add54::Value
		global_cable.getWrappedObject().getParameter().connectT(0, pma54);             // global_cable -> pma54::Value
		pma56.getWrappedObject().getParameter().connectT(0, add56);                    // pma56 -> add56::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, pma56);            // global_cable2 -> pma56::Value
		pma55.getWrappedObject().getParameter().connectT(0, add55);                    // pma55 -> add55::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, pma55);            // global_cable1 -> pma55::Value
		pma1.getWrappedObject().getParameter().connectT(0, add1);                      // pma1 -> add1::Value
		midi1.getParameter().connectT(0, pma1);                                        // midi1 -> pma1::Value
		pma2.getWrappedObject().getParameter().connectT(0, add2);                      // pma2 -> add2::Value
		midi2.getParameter().connectT(0, pma2);                                        // midi2 -> pma2::Value
		pma3.getWrappedObject().getParameter().connectT(0, add3);                      // pma3 -> add3::Value
		midi3.getParameter().connectT(0, pma3);                                        // midi3 -> pma3::Value
		pma4.getWrappedObject().getParameter().connectT(0, add4);                      // pma4 -> add4::Value
		midi_cc.getWrappedObject().getParameter().connectT(0, pma4);                   // midi_cc -> pma4::Value
		pma5.getWrappedObject().getParameter().connectT(0, add5);                      // pma5 -> add5::Value
		midi_cc1.getWrappedObject().getParameter().connectT(0, pma5);                  // midi_cc1 -> pma5::Value
		pma6.getWrappedObject().getParameter().connectT(0, add6);                      // pma6 -> add6::Value
		midi_cc2.getWrappedObject().getParameter().connectT(0, pma6);                  // midi_cc2 -> pma6::Value
		clone_pack.getWrappedObject().getParameter().connectT(0, xnode1);              // clone_pack -> xnode1::Harm
		peak.getParameter().connectT(0, clone_pack);                                   // peak -> clone_pack::Value
		clone_forward.getWrappedObject().getParameter().connectT(0, xnode1);           // clone_forward -> xnode1::min
		clone_forward2.getWrappedObject().getParameter().connectT(0, xnode1);          // clone_forward2 -> xnode1::max
		clone_forward1.getWrappedObject().getParameter().connectT(0, xnode1);          // clone_forward1 -> xnode1::step
		clone_forward6.getWrappedObject().getParameter().connectT(0, xnode1);          // clone_forward6 -> xnode1::Mode
		clone_forward7.getWrappedObject().getParameter().connectT(0, xnode1);          // clone_forward7 -> xnode1::pbTYPE
		clone_forward8.getWrappedObject().getParameter().connectT(0, xnode1);          // clone_forward8 -> xnode1::PosQuant
		pma57.getWrappedObject().getParameter().connectT(0, add57);                    // pma57 -> add57::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, pma57);            // global_cable3 -> pma57::Value
		pma59.getWrappedObject().getParameter().connectT(0, add59);                    // pma59 -> add59::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, pma59);            // global_cable5 -> pma59::Value
		pma58.getWrappedObject().getParameter().connectT(0, add58);                    // pma58 -> add58::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, pma58);            // global_cable4 -> pma58::Value
		pma7.getWrappedObject().getParameter().connectT(0, add7);                      // pma7 -> add7::Value
		midi5.getParameter().connectT(0, pma7);                                        // midi5 -> pma7::Value
		pma8.getWrappedObject().getParameter().connectT(0, add8);                      // pma8 -> add8::Value
		midi6.getParameter().connectT(0, pma8);                                        // midi6 -> pma8::Value
		pma9.getWrappedObject().getParameter().connectT(0, add9);                      // pma9 -> add9::Value
		midi7.getParameter().connectT(0, pma9);                                        // midi7 -> pma9::Value
		pma10.getWrappedObject().getParameter().connectT(0, add10);                    // pma10 -> add10::Value
		midi_cc3.getWrappedObject().getParameter().connectT(0, pma10);                 // midi_cc3 -> pma10::Value
		pma11.getWrappedObject().getParameter().connectT(0, add11);                    // pma11 -> add11::Value
		midi_cc4.getWrappedObject().getParameter().connectT(0, pma11);                 // midi_cc4 -> pma11::Value
		pma12.getWrappedObject().getParameter().connectT(0, add12);                    // pma12 -> add12::Value
		midi_cc5.getWrappedObject().getParameter().connectT(0, pma12);                 // midi_cc5 -> pma12::Value
		input_toggle38.getWrappedObject().getParameter().connectT(0, xnode1);          // input_toggle38 -> xnode1::DET
		clone_cable.getWrappedObject().getParameter().connectT(0, input_toggle38);     // clone_cable -> input_toggle38::Value1
		clone_cable29.getWrappedObject().getParameter().connectT(0, input_toggle38);   // clone_cable29 -> input_toggle38::Value2
		peak1.getParameter().connectT(0, clone_cable);                                 // peak1 -> clone_cable::Value
		peak1.getParameter().connectT(1, clone_cable29);                               // peak1 -> clone_cable29::Value
		clone_cable28.getWrappedObject().getParameter().connectT(0, input_toggle38);   // clone_cable28 -> input_toggle38::Input
		clone_cable30.getWrappedObject().getParameter().connectT(0, xnode1);           // clone_cable30 -> xnode1::PitchSmooth
		pma61.getWrappedObject().getParameter().connectT(0, add61);                    // pma61 -> add61::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, pma61);            // global_cable7 -> pma61::Value
		pma63.getWrappedObject().getParameter().connectT(0, add63);                    // pma63 -> add63::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, pma63);            // global_cable9 -> pma63::Value
		pma62.getWrappedObject().getParameter().connectT(0, add62);                    // pma62 -> add62::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, pma62);            // global_cable8 -> pma62::Value
		pma19.getWrappedObject().getParameter().connectT(0, add19);                    // pma19 -> add19::Value
		midi11.getParameter().connectT(0, pma19);                                      // midi11 -> pma19::Value
		pma20.getWrappedObject().getParameter().connectT(0, add20);                    // pma20 -> add20::Value
		midi12.getParameter().connectT(0, pma20);                                      // midi12 -> pma20::Value
		pma21.getWrappedObject().getParameter().connectT(0, add21);                    // pma21 -> add21::Value
		midi13.getParameter().connectT(0, pma21);                                      // midi13 -> pma21::Value
		pma22.getWrappedObject().getParameter().connectT(0, add22);                    // pma22 -> add22::Value
		midi_cc9.getWrappedObject().getParameter().connectT(0, pma22);                 // midi_cc9 -> pma22::Value
		pma23.getWrappedObject().getParameter().connectT(0, add23);                    // pma23 -> add23::Value
		midi_cc10.getWrappedObject().getParameter().connectT(0, pma23);                // midi_cc10 -> pma23::Value
		pma24.getWrappedObject().getParameter().connectT(0, add24);                    // pma24 -> add24::Value
		midi_cc11.getWrappedObject().getParameter().connectT(0, pma24);                // midi_cc11 -> pma24::Value
		input_toggle36.getWrappedObject().getParameter().connectT(0, xnode1);          // input_toggle36 -> xnode1::OscShapes
		clone_cable2.getWrappedObject().getParameter().connectT(0, input_toggle36);    // clone_cable2 -> input_toggle36::Value1
		clone_cable23.getWrappedObject().getParameter().connectT(0, input_toggle36);   // clone_cable23 -> input_toggle36::Value2
		peak3.getParameter().connectT(0, clone_cable2);                                // peak3 -> clone_cable2::Value
		peak3.getParameter().connectT(1, clone_cable23);                               // peak3 -> clone_cable23::Value
		clone_cable24.getWrappedObject().getParameter().connectT(0, input_toggle36);   // clone_cable24 -> input_toggle36::Input
		pma64.getWrappedObject().getParameter().connectT(0, add64);                    // pma64 -> add64::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, pma64);           // global_cable10 -> pma64::Value
		pma66.getWrappedObject().getParameter().connectT(0, add66);                    // pma66 -> add66::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, pma66);           // global_cable12 -> pma66::Value
		pma65.getWrappedObject().getParameter().connectT(0, add65);                    // pma65 -> add65::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, pma65);           // global_cable11 -> pma65::Value
		pma25.getWrappedObject().getParameter().connectT(0, add25);                    // pma25 -> add25::Value
		midi14.getParameter().connectT(0, pma25);                                      // midi14 -> pma25::Value
		pma26.getWrappedObject().getParameter().connectT(0, add26);                    // pma26 -> add26::Value
		midi15.getParameter().connectT(0, pma26);                                      // midi15 -> pma26::Value
		pma27.getWrappedObject().getParameter().connectT(0, add27);                    // pma27 -> add27::Value
		midi16.getParameter().connectT(0, pma27);                                      // midi16 -> pma27::Value
		pma28.getWrappedObject().getParameter().connectT(0, add28);                    // pma28 -> add28::Value
		midi_cc12.getWrappedObject().getParameter().connectT(0, pma28);                // midi_cc12 -> pma28::Value
		pma29.getWrappedObject().getParameter().connectT(0, add29);                    // pma29 -> add29::Value
		midi_cc13.getWrappedObject().getParameter().connectT(0, pma29);                // midi_cc13 -> pma29::Value
		pma30.getWrappedObject().getParameter().connectT(0, add30);                    // pma30 -> add30::Value
		midi_cc14.getWrappedObject().getParameter().connectT(0, pma30);                // midi_cc14 -> pma30::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, xnode1);            // input_toggle -> xnode1::UserPs
		clone_cable3.getWrappedObject().getParameter().connectT(0, input_toggle);      // clone_cable3 -> input_toggle::Value1
		clone_cable7.getWrappedObject().getParameter().connectT(0, input_toggle);      // clone_cable7 -> input_toggle::Value2
		peak4.getParameter().connectT(0, clone_cable3);                                // peak4 -> clone_cable3::Value
		peak4.getParameter().connectT(1, clone_cable7);                                // peak4 -> clone_cable7::Value
		clone_cable8.getWrappedObject().getParameter().connectT(0, input_toggle);      // clone_cable8 -> input_toggle::Input
		clone_cable32.getWrappedObject().getParameter().connectT(0, xnode1);           // clone_cable32 -> xnode1::PosDiv
		clone_cable31.getWrappedObject().getParameter().connectT(0, xnode1);           // clone_cable31 -> xnode1::FileMode
		pma73.getWrappedObject().getParameter().connectT(0, add73);                    // pma73 -> add73::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, pma73);           // global_cable13 -> pma73::Value
		pma75.getWrappedObject().getParameter().connectT(0, add75);                    // pma75 -> add75::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, pma75);           // global_cable15 -> pma75::Value
		pma74.getWrappedObject().getParameter().connectT(0, add74);                    // pma74 -> add74::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, pma74);           // global_cable14 -> pma74::Value
		pma31.getWrappedObject().getParameter().connectT(0, add31);                    // pma31 -> add31::Value
		midi17.getParameter().connectT(0, pma31);                                      // midi17 -> pma31::Value
		pma32.getWrappedObject().getParameter().connectT(0, add32);                    // pma32 -> add32::Value
		midi18.getParameter().connectT(0, pma32);                                      // midi18 -> pma32::Value
		pma33.getWrappedObject().getParameter().connectT(0, add33);                    // pma33 -> add33::Value
		midi19.getParameter().connectT(0, pma33);                                      // midi19 -> pma33::Value
		pma34.getWrappedObject().getParameter().connectT(0, add34);                    // pma34 -> add34::Value
		midi_cc15.getWrappedObject().getParameter().connectT(0, pma34);                // midi_cc15 -> pma34::Value
		pma35.getWrappedObject().getParameter().connectT(0, add35);                    // pma35 -> add35::Value
		midi_cc16.getWrappedObject().getParameter().connectT(0, pma35);                // midi_cc16 -> pma35::Value
		pma36.getWrappedObject().getParameter().connectT(0, add36);                    // pma36 -> add36::Value
		midi_cc17.getWrappedObject().getParameter().connectT(0, pma36);                // midi_cc17 -> pma36::Value
		input_toggle37.getWrappedObject().getParameter().connectT(0, xnode1);          // input_toggle37 -> xnode1::UserInput
		clone_cable4.getWrappedObject().getParameter().connectT(0, input_toggle37);    // clone_cable4 -> input_toggle37::Value1
		clone_cable26.getWrappedObject().getParameter().connectT(0, input_toggle37);   // clone_cable26 -> input_toggle37::Value2
		peak5.getParameter().connectT(0, clone_cable4);                                // peak5 -> clone_cable4::Value
		peak5.getParameter().connectT(1, clone_cable26);                               // peak5 -> clone_cable26::Value
		clone_cable27.getWrappedObject().getParameter().connectT(0, input_toggle37);   // clone_cable27 -> input_toggle37::Input
		pma76.getWrappedObject().getParameter().connectT(0, add76);                    // pma76 -> add76::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, pma76);           // global_cable16 -> pma76::Value
		pma78.getWrappedObject().getParameter().connectT(0, add78);                    // pma78 -> add78::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, pma78);           // global_cable18 -> pma78::Value
		pma77.getWrappedObject().getParameter().connectT(0, add77);                    // pma77 -> add77::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, pma77);           // global_cable17 -> pma77::Value
		pma37.getWrappedObject().getParameter().connectT(0, add37);                    // pma37 -> add37::Value
		midi20.getParameter().connectT(0, pma37);                                      // midi20 -> pma37::Value
		pma38.getWrappedObject().getParameter().connectT(0, add38);                    // pma38 -> add38::Value
		midi21.getParameter().connectT(0, pma38);                                      // midi21 -> pma38::Value
		pma39.getWrappedObject().getParameter().connectT(0, add39);                    // pma39 -> add39::Value
		midi22.getParameter().connectT(0, pma39);                                      // midi22 -> pma39::Value
		pma40.getWrappedObject().getParameter().connectT(0, add40);                    // pma40 -> add40::Value
		midi_cc18.getWrappedObject().getParameter().connectT(0, pma40);                // midi_cc18 -> pma40::Value
		pma41.getWrappedObject().getParameter().connectT(0, add41);                    // pma41 -> add41::Value
		midi_cc19.getWrappedObject().getParameter().connectT(0, pma41);                // midi_cc19 -> pma41::Value
		pma42.getWrappedObject().getParameter().connectT(0, add42);                    // pma42 -> add42::Value
		midi_cc20.getWrappedObject().getParameter().connectT(0, pma42);                // midi_cc20 -> pma42::Value
		clone_pack2.getWrappedObject().getParameter().connectT(0, xnode1);             // clone_pack2 -> xnode1::FxValue
		peak6.getParameter().connectT(0, clone_pack2);                                 // peak6 -> clone_pack2::Value
		clone_cable9.getWrappedObject().getParameter().connectT(0, xnode1);            // clone_cable9 -> xnode1::Phase
		clone_forward11.getWrappedObject().getParameter().connectT(0, xnode1);         // clone_forward11 -> xnode1::GainReset
		clone_forward14.getWrappedObject().getParameter().connectT(0, xnode1);         // clone_forward14 -> xnode1::GainSmooth
		input_toggle32.getWrappedObject().getParameter().connectT(0, xnode1);          // input_toggle32 -> xnode1::ShToGain
		clone_cable1.getWrappedObject().getParameter().connectT(0, input_toggle32);    // clone_cable1 -> input_toggle32::Value1
		clone_cable17.getWrappedObject().getParameter().connectT(0, xnode1);           // clone_cable17 -> xnode1::FxShDiv
		input_toggle35.getWrappedObject().getParameter().connectT(0, xnode1);          // input_toggle35 -> xnode1::shPitch
		clone_forward12.getWrappedObject().getParameter().connectT(0, input_toggle35); // clone_forward12 -> input_toggle35::Value1
		clone_cable19.getWrappedObject().getParameter().connectT(0, input_toggle35);   // clone_cable19 -> input_toggle35::Value2
		clone_cable20.getWrappedObject().getParameter().connectT(0, input_toggle35);   // clone_cable20 -> input_toggle35::Input
		input_toggle34.getWrappedObject().getParameter().connectT(0, xnode1);          // input_toggle34 -> xnode1::FilterFxMod
		clone_forward13.getWrappedObject().getParameter().connectT(0, input_toggle34); // clone_forward13 -> input_toggle34::Value1
		clone_cable21.getWrappedObject().getParameter().connectT(0, input_toggle34);   // clone_cable21 -> input_toggle34::Value2
		clone_cable22.getWrappedObject().getParameter().connectT(0, input_toggle34);   // clone_cable22 -> input_toggle34::Input
		clone_cable6.getWrappedObject().getParameter().connectT(0, xnode1);            // clone_cable6 -> xnode1::ShSmooth
		clone_cable5.getWrappedObject().getParameter().connectT(0, xnode1);            // clone_cable5 -> xnode1::ModMode
		pma91.getWrappedObject().getParameter().connectT(0, add91);                    // pma91 -> add91::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, pma91);           // global_cable19 -> pma91::Value
		pma92.getWrappedObject().getParameter().connectT(0, add92);                    // pma92 -> add92::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, pma92);           // global_cable20 -> pma92::Value
		pma93.getWrappedObject().getParameter().connectT(0, add93);                    // pma93 -> add93::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, pma93);           // global_cable21 -> pma93::Value
		pma67.getWrappedObject().getParameter().connectT(0, add67);                    // pma67 -> add67::Value
		midi35.getParameter().connectT(0, pma67);                                      // midi35 -> pma67::Value
		pma68.getWrappedObject().getParameter().connectT(0, add68);                    // pma68 -> add68::Value
		midi36.getParameter().connectT(0, pma68);                                      // midi36 -> pma68::Value
		pma69.getWrappedObject().getParameter().connectT(0, add69);                    // pma69 -> add69::Value
		midi37.getParameter().connectT(0, pma69);                                      // midi37 -> pma69::Value
		pma70.getWrappedObject().getParameter().connectT(0, add70);                    // pma70 -> add70::Value
		midi_cc33.getWrappedObject().getParameter().connectT(0, pma70);                // midi_cc33 -> pma70::Value
		pma71.getWrappedObject().getParameter().connectT(0, add71);                    // pma71 -> add71::Value
		midi_cc34.getWrappedObject().getParameter().connectT(0, pma71);                // midi_cc34 -> pma71::Value
		pma72.getWrappedObject().getParameter().connectT(0, add72);                    // pma72 -> add72::Value
		midi_cc35.getWrappedObject().getParameter().connectT(0, pma72);                // midi_cc35 -> pma72::Value
		clone_pack3.getWrappedObject().getParameter().connectT(0, xnode1);             // clone_pack3 -> xnode1::FilterCut
		peak11.getParameter().connectT(0, clone_pack3);                                // peak11 -> clone_pack3::Value
		clone_cable14.getWrappedObject().getParameter().connectT(0, xnode1);           // clone_cable14 -> xnode1::FilterType
		clone_cable13.getWrappedObject().getParameter().connectT(0, jpanner);          // clone_cable13 -> jpanner::Pan
		pma94.getWrappedObject().getParameter().connectT(0, add94);                    // pma94 -> add94::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, pma94);           // global_cable22 -> pma94::Value
		pma96.getWrappedObject().getParameter().connectT(0, add96);                    // pma96 -> add96::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, pma96);           // global_cable24 -> pma96::Value
		pma95.getWrappedObject().getParameter().connectT(0, add95);                    // pma95 -> add95::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, pma95);           // global_cable23 -> pma95::Value
		pma79.getWrappedObject().getParameter().connectT(0, add79);                    // pma79 -> add79::Value
		midi41.getParameter().connectT(0, pma79);                                      // midi41 -> pma79::Value
		pma80.getWrappedObject().getParameter().connectT(0, add80);                    // pma80 -> add80::Value
		midi42.getParameter().connectT(0, pma80);                                      // midi42 -> pma80::Value
		pma81.getWrappedObject().getParameter().connectT(0, add81);                    // pma81 -> add81::Value
		midi43.getParameter().connectT(0, pma81);                                      // midi43 -> pma81::Value
		pma82.getWrappedObject().getParameter().connectT(0, add82);                    // pma82 -> add82::Value
		midi_cc39.getWrappedObject().getParameter().connectT(0, pma82);                // midi_cc39 -> pma82::Value
		pma83.getWrappedObject().getParameter().connectT(0, add83);                    // pma83 -> add83::Value
		midi_cc40.getWrappedObject().getParameter().connectT(0, pma83);                // midi_cc40 -> pma83::Value
		pma84.getWrappedObject().getParameter().connectT(0, add84);                    // pma84 -> add84::Value
		midi_cc41.getWrappedObject().getParameter().connectT(0, pma84);                // midi_cc41 -> pma84::Value
		clone_cable10.getWrappedObject().getParameter().connectT(0, xnode1);           // clone_cable10 -> xnode1::FilterRes
		peak13.getParameter().connectT(0, clone_cable10);                              // peak13 -> clone_cable10::Value
		pma97.getWrappedObject().getParameter().connectT(0, add97);                    // pma97 -> add97::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, pma97);           // global_cable25 -> pma97::Value
		pma99.getWrappedObject().getParameter().connectT(0, add99);                    // pma99 -> add99::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, pma99);           // global_cable27 -> pma99::Value
		pma98.getWrappedObject().getParameter().connectT(0, add98);                    // pma98 -> add98::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, pma98);           // global_cable26 -> pma98::Value
		pma85.getWrappedObject().getParameter().connectT(0, add85);                    // pma85 -> add85::Value
		midi44.getParameter().connectT(0, pma85);                                      // midi44 -> pma85::Value
		pma86.getWrappedObject().getParameter().connectT(0, add86);                    // pma86 -> add86::Value
		midi45.getParameter().connectT(0, pma86);                                      // midi45 -> pma86::Value
		pma87.getWrappedObject().getParameter().connectT(0, add87);                    // pma87 -> add87::Value
		midi46.getParameter().connectT(0, pma87);                                      // midi46 -> pma87::Value
		pma88.getWrappedObject().getParameter().connectT(0, add88);                    // pma88 -> add88::Value
		midi_cc42.getWrappedObject().getParameter().connectT(0, pma88);                // midi_cc42 -> pma88::Value
		pma89.getWrappedObject().getParameter().connectT(0, add89);                    // pma89 -> add89::Value
		midi_cc43.getWrappedObject().getParameter().connectT(0, pma89);                // midi_cc43 -> pma89::Value
		pma90.getWrappedObject().getParameter().connectT(0, add90);                    // pma90 -> add90::Value
		midi_cc44.getWrappedObject().getParameter().connectT(0, pma90);                // midi_cc44 -> pma90::Value
		clone_cable11.getWrappedObject().getParameter().connectT(0, xnode1);           // clone_cable11 -> xnode1::FilterMix
		peak14.getParameter().connectT(0, clone_cable11);                              // peak14 -> clone_cable11::Value
		
		// Default Values --------------------------------------------------------------------------
		
		;                          // Env3::Tempo is automated
		;                          // Env3::Multi is automated
		Env3.setParameterT(2, 1.); // project::Env2::Sync
		Env3.setParameterT(3, 1.); // project::Env2::Unsynced
		;                          // Env3::a is automated
		;                          // Env3::d is automated
		;                          // Env3::h is automated
		;                          // Env3::s is automated
		;                          // Env3::r is automated
		;                          // Env3::trig is automated
		;                          // Env3::mode is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		;                          // Env4::Tempo is automated
		;                          // Env4::Multi is automated
		Env4.setParameterT(2, 1.); // project::Env2::Sync
		Env4.setParameterT(3, 0.); // project::Env2::Unsynced
		;                          // Env4::a is automated
		;                          // Env4::d is automated
		;                          // Env4::h is automated
		;                          // Env4::s is automated
		;                          // Env4::r is automated
		;                          // Env4::trig is automated
		;                          // Env4::mode is automated
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		; // branch::Index is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma54::Value is automated
		; // pma54::Multiply is automated
		; // pma54::Add is automated
		
		; // add54::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma56::Value is automated
		; // pma56::Multiply is automated
		; // pma56::Add is automated
		
		; // add56::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma55::Value is automated
		; // pma55::Multiply is automated
		; // pma55::Add is automated
		
		; // add55::Value is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // add::Value is automated
		
		; // pma13::Value is automated
		; // pma13::Multiply is automated
		; // pma13::Add is automated
		
		; // add13::Value is automated
		
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
		
		; // clone_forward8::NumClones is automated
		; // clone_forward8::Value is automated
		
		; // branch3::Index is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma57::Value is automated
		; // pma57::Multiply is automated
		; // pma57::Add is automated
		
		; // add57::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma59::Value is automated
		; // pma59::Multiply is automated
		; // pma59::Add is automated
		
		; // add59::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma58::Value is automated
		; // pma58::Multiply is automated
		; // pma58::Add is automated
		
		; // add58::Value is automated
		
		; // pma14::Value is automated
		; // pma14::Multiply is automated
		; // pma14::Add is automated
		
		; // add14::Value is automated
		
		; // pma15::Value is automated
		; // pma15::Multiply is automated
		; // pma15::Add is automated
		
		; // add15::Value is automated
		
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
		
		;                                   // clone_cable29::NumClones is automated
		;                                   // clone_cable29::Value is automated
		clone_cable29.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable28::NumClones is automated
		;                                   // clone_cable28::Value is automated
		clone_cable28.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable30::NumClones is automated
		;                                   // clone_cable30::Value is automated
		clone_cable30.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // branch8::Index is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma61::Value is automated
		; // pma61::Multiply is automated
		; // pma61::Add is automated
		
		; // add61::Value is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma63::Value is automated
		; // pma63::Multiply is automated
		; // pma63::Add is automated
		
		; // add63::Value is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma62::Value is automated
		; // pma62::Multiply is automated
		; // pma62::Add is automated
		
		; // add62::Value is automated
		
		; // pma16::Value is automated
		; // pma16::Multiply is automated
		; // pma16::Add is automated
		
		; // add16::Value is automated
		
		; // pma17::Value is automated
		; // pma17::Multiply is automated
		; // pma17::Add is automated
		
		; // add17::Value is automated
		
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
		
		;                                   // clone_cable23::NumClones is automated
		;                                   // clone_cable23::Value is automated
		clone_cable23.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable24::NumClones is automated
		;                                   // clone_cable24::Value is automated
		clone_cable24.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clear8.setParameterT(0, 0.); // math::clear::Value
		
		; // branch9::Index is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma64::Value is automated
		; // pma64::Multiply is automated
		; // pma64::Add is automated
		
		; // add64::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma66::Value is automated
		; // pma66::Multiply is automated
		; // pma66::Add is automated
		
		; // add66::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma65::Value is automated
		; // pma65::Multiply is automated
		; // pma65::Add is automated
		
		; // add65::Value is automated
		
		; // pma18::Value is automated
		; // pma18::Multiply is automated
		; // pma18::Add is automated
		
		; // add18::Value is automated
		
		; // pma43::Value is automated
		; // pma43::Multiply is automated
		; // pma43::Add is automated
		
		; // add43::Value is automated
		
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
		
		smoother.setParameterT(0, 0.); // core::smoother::SmoothingTime
		smoother.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		;                                  // clone_cable3::NumClones is automated
		;                                  // clone_cable3::Value is automated
		clone_cable3.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable7::NumClones is automated
		;                                  // clone_cable7::Value is automated
		clone_cable7.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable8::NumClones is automated
		;                                  // clone_cable8::Value is automated
		clone_cable8.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable32::NumClones is automated
		;                                   // clone_cable32::Value is automated
		clone_cable32.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable31::NumClones is automated
		;                                   // clone_cable31::Value is automated
		clone_cable31.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // branch10::Index is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma73::Value is automated
		; // pma73::Multiply is automated
		; // pma73::Add is automated
		
		; // add73::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma75::Value is automated
		; // pma75::Multiply is automated
		; // pma75::Add is automated
		
		; // add75::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma74::Value is automated
		; // pma74::Multiply is automated
		; // pma74::Add is automated
		
		; // add74::Value is automated
		
		; // pma44::Value is automated
		; // pma44::Multiply is automated
		; // pma44::Add is automated
		
		; // add44::Value is automated
		
		; // pma45::Value is automated
		; // pma45::Multiply is automated
		; // pma45::Add is automated
		
		; // add45::Value is automated
		
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
		
		;                                   // clone_cable26::NumClones is automated
		;                                   // clone_cable26::Value is automated
		clone_cable26.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable27::NumClones is automated
		;                                   // clone_cable27::Value is automated
		clone_cable27.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // branch11::Index is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma76::Value is automated
		; // pma76::Multiply is automated
		; // pma76::Add is automated
		
		; // add76::Value is automated
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma78::Value is automated
		; // pma78::Multiply is automated
		; // pma78::Add is automated
		
		; // add78::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma77::Value is automated
		; // pma77::Multiply is automated
		; // pma77::Add is automated
		
		; // add77::Value is automated
		
		; // pma46::Value is automated
		; // pma46::Multiply is automated
		; // pma46::Add is automated
		
		; // add46::Value is automated
		
		; // pma47::Value is automated
		; // pma47::Multiply is automated
		; // pma47::Add is automated
		
		; // add47::Value is automated
		
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
		
		; // pack_resizer5::NumSliders is automated
		
		; // pack_resizer4::NumSliders is automated
		
		; // clone_pack2::NumClones is automated
		; // clone_pack2::Value is automated
		
		;                                  // clone_cable9::NumClones is automated
		;                                  // clone_cable9::Value is automated
		clone_cable9.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // clone_forward11::NumClones is automated
		; // clone_forward11::Value is automated
		
		; // clone_forward14::NumClones is automated
		; // clone_forward14::Value is automated
		
		;                                  // clone_cable1::NumClones is automated
		;                                  // clone_cable1::Value is automated
		clone_cable1.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable17::NumClones is automated
		;                                   // clone_cable17::Value is automated
		clone_cable17.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // clone_forward12::NumClones is automated
		; // clone_forward12::Value is automated
		
		;                                   // clone_cable19::NumClones is automated
		;                                   // clone_cable19::Value is automated
		clone_cable19.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable20::NumClones is automated
		clone_cable20.setParameterT(1, 0.); // control::clone_cable::Value
		clone_cable20.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // clone_forward13::NumClones is automated
		; // clone_forward13::Value is automated
		
		;                                   // clone_cable21::NumClones is automated
		;                                   // clone_cable21::Value is automated
		clone_cable21.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable22::NumClones is automated
		clone_cable22.setParameterT(1, 0.); // control::clone_cable::Value
		clone_cable22.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable6::NumClones is automated
		;                                  // clone_cable6::Value is automated
		clone_cable6.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable5::NumClones is automated
		;                                  // clone_cable5::Value is automated
		clone_cable5.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // branch13::Index is automated
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma91::Value is automated
		; // pma91::Multiply is automated
		; // pma91::Add is automated
		
		; // add91::Value is automated
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma92::Value is automated
		; // pma92::Multiply is automated
		; // pma92::Add is automated
		
		; // add92::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma93::Value is automated
		; // pma93::Multiply is automated
		; // pma93::Add is automated
		
		; // add93::Value is automated
		
		; // pma48::Value is automated
		; // pma48::Multiply is automated
		; // pma48::Add is automated
		
		; // add48::Value is automated
		
		; // pma49::Value is automated
		; // pma49::Multiply is automated
		; // pma49::Add is automated
		
		; // add49::Value is automated
		
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
		
		;                                   // clone_cable13::NumClones is automated
		;                                   // clone_cable13::Value is automated
		clone_cable13.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // branch16::Index is automated
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma94::Value is automated
		; // pma94::Multiply is automated
		; // pma94::Add is automated
		
		; // add94::Value is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma96::Value is automated
		; // pma96::Multiply is automated
		; // pma96::Add is automated
		
		; // add96::Value is automated
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma95::Value is automated
		; // pma95::Multiply is automated
		; // pma95::Add is automated
		
		; // add95::Value is automated
		
		; // pma50::Value is automated
		; // pma50::Multiply is automated
		; // pma50::Add is automated
		
		; // add50::Value is automated
		
		; // pma51::Value is automated
		; // pma51::Multiply is automated
		; // pma51::Add is automated
		
		; // add51::Value is automated
		
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
		
		; // branch17::Index is automated
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma97::Value is automated
		; // pma97::Multiply is automated
		; // pma97::Add is automated
		
		; // add97::Value is automated
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma99::Value is automated
		; // pma99::Multiply is automated
		; // pma99::Add is automated
		
		; // add99::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma98::Value is automated
		; // pma98::Multiply is automated
		; // pma98::Add is automated
		
		; // add98::Value is automated
		
		; // pma52::Value is automated
		; // pma52::Multiply is automated
		; // pma52::Add is automated
		
		; // add52::Value is automated
		
		; // pma53::Value is automated
		; // pma53::Multiply is automated
		; // pma53::Add is automated
		
		; // add53::Value is automated
		
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
		clone.setParameterT(1, 1.); // container::clone::SplitSignal
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		input_toggle32.setParameterT(0, 0.); // control::input_toggle::Input
		;                                    // input_toggle32::Value1 is automated
		input_toggle32.setParameterT(2, 0.); // control::input_toggle::Value2
		
		; // input_toggle35::Input is automated
		; // input_toggle35::Value1 is automated
		; // input_toggle35::Value2 is automated
		
		; // input_toggle34::Input is automated
		; // input_toggle34::Value1 is automated
		; // input_toggle34::Value2 is automated
		
		; // input_toggle36::Input is automated
		; // input_toggle36::Value1 is automated
		; // input_toggle36::Value2 is automated
		
		; // input_toggle37::Input is automated
		; // input_toggle37::Value1 is automated
		; // input_toggle37::Value2 is automated
		
		; // input_toggle38::Input is automated
		; // input_toggle38::Value1 is automated
		; // input_toggle38::Value2 is automated
		
		; // xnode1::Harm is automated
		; // xnode1::min is automated
		; // xnode1::max is automated
		; // xnode1::step is automated
		; // xnode1::Mode is automated
		; // xnode1::GainSmooth is automated
		; // xnode1::FxValue is automated
		; // xnode1::FxShDiv is automated
		; // xnode1::GainReset is automated
		; // xnode1::shPitch is automated
		; // xnode1::FilterMix is automated
		; // xnode1::FilterType is automated
		; // xnode1::FilterRes is automated
		; // xnode1::FilterCut is automated
		; // xnode1::FilterFxMod is automated
		; // xnode1::DET is automated
		; // xnode1::ShSmooth is automated
		; // xnode1::OscShapes is automated
		; // xnode1::pbTYPE is automated
		; // xnode1::ModMode is automated
		; // xnode1::UserPs is automated
		; // xnode1::UserInput is automated
		; // xnode1::PitchSmooth is automated
		; // xnode1::ShToGain is automated
		; // xnode1::Phase is automated
		; // xnode1::PosDiv is automated
		; // xnode1::FileMode is automated
		; // xnode1::PosQuant is automated
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 3.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 2.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 16.);
		this->setParameterT(7, 0.5);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 2.08167e-17);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 6.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, -1.);
		this->setParameterT(16, 3.);
		this->setParameterT(17, 0.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 4.);
		this->setParameterT(20, 0.);
		this->setParameterT(21, 0.);
		this->setParameterT(22, 5.);
		this->setParameterT(23, 0.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 1.);
		this->setParameterT(26, 0.);
		this->setParameterT(27, 3.);
		this->setParameterT(28, 0.);
		this->setParameterT(29, 2.);
		this->setParameterT(30, 0.);
		this->setParameterT(31, 0.);
		this->setParameterT(32, 3.);
		this->setParameterT(33, 2.08167e-17);
		this->setParameterT(34, 1.);
		this->setParameterT(35, 0.413086);
		this->setParameterT(36, 6.);
		this->setParameterT(37, 0.956934);
		this->setParameterT(38, 3.);
		this->setParameterT(39, 0.);
		this->setParameterT(40, 0.);
		this->setParameterT(41, 1.);
		this->setParameterT(42, 0.);
		this->setParameterT(43, 4.);
		this->setParameterT(44, 0.);
		this->setParameterT(45, 2.);
		this->setParameterT(46, 3.);
		this->setParameterT(47, 0.);
		this->setParameterT(48, 0.);
		this->setParameterT(49, 1.);
		this->setParameterT(50, 0.);
		this->setParameterT(51, 2.);
		this->setParameterT(52, 0.);
		this->setParameterT(53, 0.);
		this->setParameterT(54, 3.);
		this->setParameterT(55, 0.);
		this->setParameterT(56, 1.);
		this->setParameterT(57, 0.);
		this->setParameterT(58, 0.);
		this->setParameterT(59, 1.);
		this->setParameterT(60, 5.);
		this->setParameterT(61, 8.);
		this->setParameterT(62, 422.);
		this->setParameterT(63, 4998.5);
		this->setParameterT(64, 0.);
		this->setParameterT(65, 0.14);
		this->setParameterT(66, 1786.);
		this->setParameterT(67, 1.);
		this->setParameterT(68, 0.);
		this->setParameterT(69, 6.);
		this->setParameterT(70, 4395.);
		this->setParameterT(71, 6213.7);
		this->setParameterT(72, 0.);
		this->setParameterT(73, 0.64);
		this->setParameterT(74, 2159.);
		this->setParameterT(75, 1.);
		this->setParameterT(76, 2.);
		this->setParameterT(77, 32.);
		this->setParameterT(78, 1.);
		this->setParameterT(79, 1.);
		this->setParameterT(80, 0.);
		this->setParameterT(81, 0.);
		this->setParameterT(82, 0.);
		this->setParameterT(83, 0.005);
		this->setParameterT(84, 0.);
		this->setParameterT(85, 0.);
		this->setParameterT(86, 0.);
		this->setParameterT(87, 32.);
		this->setParameterT(88, 32.);
		this->setParameterT(89, 32.);
		this->setParameterT(90, -0.22);
		this->setParameterT(91, 32.);
		this->setParameterT(92, 0.28);
		this->setParameterT(93, 1.);
		this->setParameterT(94, 1.);
		this->setParameterT(95, 0.);
		this->setParameterT(96, 0.5);
		this->setParameterT(97, 0.);
		this->setParameterT(98, 16.);
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
		
		this->getT(0).getT(1).getT(0).getT(0).  // ArrangeNew_impl::global_cable_t<NV>
        getT(0).getT(0).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(0).  // ArrangeNew_impl::global_cable2_t<NV>
        getT(0).getT(0).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(0).  // ArrangeNew_impl::global_cable1_t<NV>
        getT(0).getT(0).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(1).getT(0).  // ArrangeNew_impl::global_cable3_t<NV>
        getT(0).getT(0).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(1).getT(0).  // ArrangeNew_impl::global_cable5_t<NV>
        getT(0).getT(0).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(1).getT(0).  // ArrangeNew_impl::global_cable4_t<NV>
        getT(0).getT(0).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(2).getT(0).  // ArrangeNew_impl::global_cable7_t<NV>
        getT(0).getT(0).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(2).getT(0).  // ArrangeNew_impl::global_cable9_t<NV>
        getT(0).getT(0).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(2).getT(0).  // ArrangeNew_impl::global_cable8_t<NV>
        getT(0).getT(0).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(3).getT(0).  // ArrangeNew_impl::global_cable10_t<NV>
        getT(0).getT(1).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(3).getT(0).  // ArrangeNew_impl::global_cable12_t<NV>
        getT(0).getT(1).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(3).getT(0).  // ArrangeNew_impl::global_cable11_t<NV>
        getT(0).getT(1).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(4).getT(0).  // ArrangeNew_impl::global_cable13_t<NV>
        getT(0).getT(0).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(4).getT(0).  // ArrangeNew_impl::global_cable15_t<NV>
        getT(0).getT(0).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(4).getT(0).  // ArrangeNew_impl::global_cable14_t<NV>
        getT(0).getT(0).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(2).getT(0).getT(0).  // ArrangeNew_impl::global_cable16_t<NV>
        getT(0).getT(0).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(2).getT(0).getT(0).  // ArrangeNew_impl::global_cable18_t<NV>
        getT(0).getT(0).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(2).getT(0).getT(0).  // ArrangeNew_impl::global_cable17_t<NV>
        getT(0).getT(0).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(3).getT(0).getT(0).  // ArrangeNew_impl::global_cable19_t<NV>
        getT(0).getT(0).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(3).getT(0).getT(0).  // ArrangeNew_impl::global_cable20_t<NV>
        getT(0).getT(0).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(3).getT(0).getT(0).  // ArrangeNew_impl::global_cable21_t<NV>
        getT(0).getT(0).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(3).getT(1).getT(0).  // ArrangeNew_impl::global_cable22_t<NV>
        getT(0).getT(0).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(3).getT(1).getT(0).  // ArrangeNew_impl::global_cable24_t<NV>
        getT(0).getT(0).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(3).getT(1).getT(0).  // ArrangeNew_impl::global_cable23_t<NV>
        getT(0).getT(0).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(3).getT(2).getT(0).  // ArrangeNew_impl::global_cable25_t<NV>
        getT(0).getT(0).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(3).getT(2).getT(0).  // ArrangeNew_impl::global_cable27_t<NV>
        getT(0).getT(0).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(3).getT(2).getT(0).  // ArrangeNew_impl::global_cable26_t<NV>
        getT(0).getT(0).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);                         // ArrangeNew_impl::Env3_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);                         // ArrangeNew_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);                         // ArrangeNew_impl::Env4_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);                         // ArrangeNew_impl::peak7_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);         // ArrangeNew_impl::pack_resizer_t
		this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).setExternalData(b, index); // ArrangeNew_impl::clone_pack_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak1_t<NV>
		this->getT(0).getT(1).getT(2).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak3_t<NV>
		this->getT(0).getT(1).getT(3).getT(0).getT(0).getT(3).setExternalData(b, index);         // ArrangeNew_impl::peak4_t<NV>
		this->getT(0).getT(1).getT(4).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak5_t<NV>
		this->getT(0).getT(2).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak6_t<NV>
		this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);         // ArrangeNew_impl::pack_resizer2_t
		this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);         // ArrangeNew_impl::pack_resizer5_t
		this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index);         // ArrangeNew_impl::pack_resizer4_t
		this->getT(0).getT(2).getT(0).getT(0).getT(1).getT(3).getT(0).setExternalData(b, index); // ArrangeNew_impl::clone_pack2_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak11_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).getT(1).setExternalData(b, index);                 // ArrangeNew_impl::pack_resizer3_t
		this->getT(0).getT(3).getT(0).getT(0).getT(2).getT(0).getT(0).setExternalData(b, index); // ArrangeNew_impl::clone_pack3_t<NV>
		this->getT(0).getT(3).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak13_t<NV>
		this->getT(0).getT(3).getT(2).getT(0).getT(0).getT(1).setExternalData(b, index);         // ArrangeNew_impl::peak14_t<NV>
		this->getT(1).getT(1).setExternalData(b, index);                                         // ArrangeNew_impl::xnode1_t<NV>
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


