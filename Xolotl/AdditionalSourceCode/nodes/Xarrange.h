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

namespace Xarrange_impl
{
// ==============================| Node & Parameter type declarations |==============================

struct xnode1_t_matrix
{
	static const int NumTables = 0;
	static const int NumSliderPacks = 15;
	static const int NumAudioFiles = 3;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 0;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][15] =
	{
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },                         // 
		{ 1000, 1001, 1002, 1003, 1004, 6, 1005, 9, 1006, 1007, 1008, 1009, 1010, 1011, 1012 }, //  | 0->e[0] | 1->e[1] | 2->e[2] | 3->e[3] | 4->e[4] | 5->6 | 6->e[5] | 7->9 | 8->e[6] | 9->e[7] | 10->e[8] | 11->e[9] | 12->e[10] | 13->e[11] | 14->e[12]
		{ 1013, 1014, 1015, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }                    //  | 0->e[13] | 1->e[14] | 2->e[15]
	};
	
private:
	
	span<float, 16> d0 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d1 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d2 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d3 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d4 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d5 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d6 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d7 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d8 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d9 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d10 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d11 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d12 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
public:
	
	const span<dyn<float>, 13> embeddedData = { d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12 };
};

template <int NV>
using xnode1_t = wrap::data<project::xnode<NV>, 
                            data::matrix<xnode1_t_matrix>>;
template <int NV>
using clone_pack_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<xnode1_t<NV>, 0>>>, 
                                data::external::sliderpack<0>>;
template <int NV>
using pma6_t = control::pma<NV, 
                            parameter::plain<clone_pack_t<NV>, 1>>;
template <int NV>
using pma2_t = control::pma<NV, 
                            parameter::plain<pma6_t<NV>, 0>>;
template <int NV>
using pma3_t = control::pma<NV, 
                            parameter::plain<pma2_t<NV>, 2>>;
DECLARE_PARAMETER_RANGE(pma_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using pma_mod = parameter::from0To1<pma3_t<NV>, 
                                    2, 
                                    pma_modRange>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using event_data_reader_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                                      routing::event_data_reader<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, event_data_reader_t<NV>>, 
                                  pma_t<NV>>;
using global_cable_t_index = runtime_target::indexers::fix_hash<3357039>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable_t<NV>>, 
                                   math::add<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<3357040>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>>;
using global_cable12_t_index = runtime_target::indexers::fix_hash<3357041>;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = runtime_target::indexers::fix_hash<3357042>;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain18_t<NV>>, 
                                   chain22_t<NV>, 
                                   chain23_t<NV>, 
                                   chain24_t<NV>>;

template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch_t<NV>>, 
                                   peak1_t<NV>, 
                                   math::clear<NV>, 
                                   pma3_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain25_t<NV>>>;

template <int NV>
using midi2_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi2_t<NV>>, 
                                  pma2_t<NV>>;

template <int NV>
using midi_cc_t = control::midi_cc<parameter::plain<pma6_t<NV>, 2>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc_t<NV>>, 
                                  pma6_t<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain3_t<NV>>, 
                                  chain10_t<NV>, 
                                  chain6_t<NV>, 
                                  chain5_t<NV>>;

DECLARE_PARAMETER_RANGE(clone_cable11_modRange, 
                        0., 
                        2.);

template <int NV>
using clone_cable11_mod = parameter::from0To1<xnode1_t<NV>, 
                                              15, 
                                              clone_cable11_modRange>;

template <int NV>
using clone_cable11_t = control::clone_cable<parameter::cloned<clone_cable11_mod<NV>>, 
                                             duplilogic::spread>;
DECLARE_PARAMETER_RANGE(pma29_modRange, 
                        -1., 
                        1.);

template <int NV>
using pma29_mod = parameter::from0To1<clone_cable11_t<NV>, 
                                      1, 
                                      pma29_modRange>;

template <int NV>
using pma29_t = control::pma<NV, pma29_mod<NV>>;
template <int NV>
using pma28_t = control::pma<NV, 
                             parameter::plain<pma29_t<NV>, 2>>;
template <int NV>
using event_data_reader7_t = wrap::mod<parameter::plain<pma28_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader7_t<NV>>, 
                                   pma28_t<NV>>;
using global_cable7_t_index = global_cable_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   math::add<NV>>;
using global_cable32_t_index = global_cable11_t_index;

template <int NV>
using global_cable32_t = routing::global_cable<global_cable32_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable32_t<NV>>, 
                                   math::add<NV>>;
using global_cable33_t_index = global_cable12_t_index;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain72_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable33_t<NV>>, 
                                   math::add<NV>>;
using global_cable34_t_index = global_cable13_t_index;

template <int NV>
using global_cable34_t = routing::global_cable<global_cable34_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable34_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain70_t<NV>>, 
                                    chain71_t<NV>, 
                                    chain72_t<NV>, 
                                    chain73_t<NV>>;

template <int NV>
using peak7_t = wrap::mod<parameter::plain<pma29_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch7_t<NV>>, 
                                   peak7_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain69_t<NV>>, 
                                   pma29_t<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain67_t<NV>>, 
                                  chain68_t<NV>>;

template <int NV>
using clone_pack2_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<xnode1_t<NV>, 6>>>, 
                                 data::external::sliderpack<2>>;
template <int NV>
using pma27_t = control::pma<NV, 
                             parameter::plain<clone_pack2_t<NV>, 1>>;
template <int NV>
using pma26_t = control::pma<NV, 
                             parameter::plain<pma27_t<NV>, 2>>;
template <int NV>
using pma25_t = control::pma<NV, 
                             parameter::plain<pma26_t<NV>, 2>>;
template <int NV>
using pma24_t = control::pma<NV, 
                             parameter::plain<pma25_t<NV>, 2>>;
template <int NV>
using event_data_reader6_t = wrap::mod<parameter::plain<pma24_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader6_t<NV>>, 
                                   pma24_t<NV>>;
using global_cable6_t_index = global_cable_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>>;
using global_cable29_t_index = global_cable11_t_index;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable29_t<NV>>, 
                                   math::add<NV>>;
using global_cable30_t_index = global_cable12_t_index;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable30_t<NV>>, 
                                   math::add<NV>>;
using global_cable31_t_index = global_cable13_t_index;

template <int NV>
using global_cable31_t = routing::global_cable<global_cable31_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable31_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain61_t<NV>>, 
                                    chain62_t<NV>, 
                                    chain63_t<NV>, 
                                    chain64_t<NV>>;

template <int NV>
using peak6_t = wrap::mod<parameter::plain<pma25_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   peak6_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain60_t<NV>>, 
                                   pma25_t<NV>>;

template <int NV>
using midi13_t = wrap::mod<parameter::plain<pma26_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi13_t<NV>>, 
                                   pma26_t<NV>>;

template <int NV>
using midi14_t = wrap::mod<parameter::plain<pma27_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi14_t<NV>>, 
                                   pma27_t<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain58_t<NV>>, 
                                  chain59_t<NV>, 
                                  chain65_t<NV>, 
                                  chain66_t<NV>>;

template <int NV>
using clone_pack1_mod = parameter::from0To1<xnode1_t<NV>, 
                                            13, 
                                            pma_modRange>;

template <int NV>
using clone_pack1_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack1_mod<NV>>>, 
                                 data::external::sliderpack<3>>;
template <int NV>
using pma23_t = control::pma<NV, 
                             parameter::plain<clone_pack1_t<NV>, 1>>;
template <int NV>
using pma22_t = control::pma<NV, 
                             parameter::plain<pma23_t<NV>, 2>>;
template <int NV>
using pma21_t = control::pma<NV, 
                             parameter::plain<pma22_t<NV>, 2>>;
template <int NV>
using pma20_t = control::pma<NV, 
                             parameter::plain<pma21_t<NV>, 2>>;
template <int NV>
using event_data_reader5_t = wrap::mod<parameter::plain<pma20_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader5_t<NV>>, 
                                   pma20_t<NV>>;
using global_cable5_t_index = global_cable_t_index;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable5_t<NV>>, 
                                   math::add<NV>>;
using global_cable26_t_index = global_cable11_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>>;
using global_cable27_t_index = global_cable12_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable27_t<NV>>, 
                                   math::add<NV>>;
using global_cable28_t_index = global_cable13_t_index;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable28_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain52_t<NV>>, 
                                    chain53_t<NV>, 
                                    chain54_t<NV>, 
                                    chain55_t<NV>>;

template <int NV>
using peak5_t = wrap::mod<parameter::plain<pma21_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   peak5_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain51_t<NV>>, 
                                   pma21_t<NV>>;

template <int NV>
using midi11_t = wrap::mod<parameter::plain<pma22_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi11_t<NV>>, 
                                   pma22_t<NV>>;

template <int NV>
using midi12_t = wrap::mod<parameter::plain<pma23_t<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi12_t<NV>>, 
                                   pma23_t<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain49_t<NV>>, 
                                  chain50_t<NV>, 
                                  chain56_t<NV>, 
                                  chain57_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_cable14_modRange, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using clone_cable14_mod = parameter::from0To1<xnode1_t<NV>, 
                                              12, 
                                              clone_cable14_modRange>;

template <int NV>
using clone_cable14_t = control::clone_cable<parameter::cloned<clone_cable14_mod<NV>>, 
                                             duplilogic::fixed>;
template <int NV>
using pma17_t = control::pma<NV, 
                             parameter::plain<clone_cable14_t<NV>, 1>>;
template <int NV>
using pma16_t = control::pma<NV, 
                             parameter::plain<pma17_t<NV>, 2>>;
template <int NV>
using event_data_reader4_t = wrap::mod<parameter::plain<pma16_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader4_t<NV>>, 
                                   pma16_t<NV>>;
using global_cable4_t_index = global_cable_t_index;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = global_cable11_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   math::add<NV>>;
using global_cable24_t_index = global_cable12_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>>;
using global_cable25_t_index = global_cable13_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain43_t<NV>>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>, 
                                    chain46_t<NV>>;

template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma17_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch4_t<NV>>, 
                                   peak4_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain42_t<NV>>, 
                                   pma17_t<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain40_t<NV>>, 
                                  chain41_t<NV>>;

template <int NV>
using clone_cable1_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 10>>, 
                                            duplilogic::fixed>;
template <int NV>
using pma13_t = control::pma<NV, 
                             parameter::plain<clone_cable1_t<NV>, 1>>;
template <int NV>
using pma12_t = control::pma<NV, 
                             parameter::plain<pma13_t<NV>, 2>>;
template <int NV>
using event_data_reader3_t = wrap::mod<parameter::plain<pma12_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader3_t<NV>>, 
                                   pma12_t<NV>>;
using global_cable3_t_index = global_cable_t_index;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   math::add<NV>>;
using global_cable20_t_index = global_cable11_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = global_cable12_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>>;
using global_cable22_t_index = global_cable13_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain21_t<NV>>, 
                                    chain35_t<NV>, 
                                    chain36_t<NV>, 
                                    chain37_t<NV>>;

template <int NV>
using peak3_t = wrap::mod<parameter::plain<pma13_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak3_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain34_t<NV>>, 
                                   pma13_t<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain16_t<NV>>, 
                                  chain17_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, split2_t<NV>>, 
                                  split9_t<NV>, 
                                  split8_t<NV>, 
                                  split7_t<NV>, 
                                  split6_t<NV>, 
                                  split5_t<NV>>;
using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<0>>;
using pack_resizer1_t = wrap::data<control::pack_resizer, 
                                   data::external::sliderpack<2>>;
using pack_resizer2_t = wrap::data<control::pack_resizer, 
                                   data::external::sliderpack<3>>;

using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, pack_resizer_t>, 
                                  pack_resizer1_t, 
                                  pack_resizer2_t>;

DECLARE_PARAMETER_RANGE_STEP(clone_cable_modRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using clone_cable_mod = parameter::from0To1<xnode1_t<NV>, 
                                            1, 
                                            clone_cable_modRange>;

template <int NV>
using clone_cable_t = control::clone_cable<parameter::cloned<clone_cable_mod<NV>>, 
                                           duplilogic::fixed>;

template <int NV>
using clone_cable4_mod = parameter::from0To1<xnode1_t<NV>, 
                                             2, 
                                             clone_cable_modRange>;

template <int NV>
using clone_cable4_t = control::clone_cable<parameter::cloned<clone_cable4_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable3_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 3>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_forward_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 4>>>;

template <int NV>
using clone_cable12_mod = parameter::from0To1<xnode1_t<NV>, 
                                              9, 
                                              pma29_modRange>;

template <int NV>
using clone_cable12_t = control::clone_cable<parameter::cloned<clone_cable12_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, clone_pack_t<NV>>, 
                                 clone_cable_t<NV>, 
                                 clone_cable4_t<NV>, 
                                 clone_cable3_t<NV>, 
                                 clone_forward_t<NV>, 
                                 clone_cable11_t<NV>, 
                                 clone_cable12_t<NV>>;

template <int NV>
using clone_cable2_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 5>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable9_mod = parameter::from0To1<xnode1_t<NV>, 
                                             7, 
                                             clone_cable_modRange>;

template <int NV>
using clone_cable9_t = control::clone_cable<parameter::cloned<clone_cable9_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable8_t = control::clone_cable<parameter::cloned<parameter::plain<xnode1_t<NV>, 8>>, 
                                            duplilogic::fixed>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, clone_pack2_t<NV>>, 
                                  clone_cable2_t<NV>, 
                                  clone_cable9_t<NV>, 
                                  clone_cable8_t<NV>>;

template <int NV>
using clone_forward1_t = control::clone_forward<parameter::cloned<parameter::plain<xnode1_t<NV>, 11>>>;

template <int NV>
using clone_cable13_mod = parameter::from0To1<xnode1_t<NV>, 
                                              14, 
                                              pma29_modRange>;

template <int NV>
using clone_cable13_t = control::clone_cable<parameter::cloned<clone_cable13_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV>
using clone_cable10_mod = parameter::from0To1<jdsp::jpanner<NV>, 
                                              0, 
                                              pma29_modRange>;

template <int NV>
using clone_cable10_t = control::clone_cable<parameter::cloned<clone_cable10_mod<NV>>, 
                                             duplilogic::spread>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, clone_pack1_t<NV>>, 
                                  clone_cable1_t<NV>, 
                                  clone_forward1_t<NV>, 
                                  clone_cable14_t<NV>, 
                                  clone_cable13_t<NV>, 
                                  clone_cable10_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain_t<NV>>, 
                                 chain2_t<NV>, 
                                 chain1_t<NV>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, split1_t>, 
                                    split_t<NV>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, chain4_t<NV>>, 
                                     no_midi_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using clone1_child_t = container::chain<parameter::empty, 
                                        wrap::fix<2, xnode1_t<NV>>, 
                                        jdsp::jpanner<NV>>;
template <int NV>
using clone1_t = wrap::clonesplit<clone1_child_t<NV>, 32>;

namespace Xarrange_t_parameters
{
// Parameter list for Xarrange_impl::Xarrange_t ----------------------------------------------------

template <int NV>
using Stages = parameter::chain<ranges::Identity, 
                                parameter::plain<Xarrange_impl::clone1_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_pack_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_pack2_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_pack1_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable2_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable1_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable4_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable9_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable3_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_forward_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable11_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable8_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable13_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable14_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::pack_resizer_t, 0>, 
                                parameter::plain<Xarrange_impl::pack_resizer1_t, 0>, 
                                parameter::plain<Xarrange_impl::pack_resizer2_t, 0>, 
                                parameter::plain<Xarrange_impl::clone_forward1_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable10_t<NV>, 0>, 
                                parameter::plain<Xarrange_impl::clone_cable12_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(Min_InputRange, 
                        1., 
                        16.);

template <int NV>
using Min = parameter::chain<Min_InputRange, 
                             parameter::plain<Xarrange_impl::clone_cable_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(MAX_InputRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using MAX = parameter::chain<MAX_InputRange, 
                             parameter::plain<Xarrange_impl::clone_cable4_t<NV>, 1>>;

template <int NV>
using SampleOSc = parameter::plain<Xarrange_impl::clone_forward_t<NV>, 
                                   1>;
template <int NV>
using FXmix = parameter::plain<Xarrange_impl::clone_cable2_t<NV>, 
                               1>;
template <int NV>
using SHtempoSync = parameter::plain<Xarrange_impl::clone_cable8_t<NV>, 
                                     1>;
template <int NV>
using SHDiv = parameter::plain<Xarrange_impl::clone_cable9_t<NV>, 
                               1>;
template <int NV>
using FilterType = parameter::plain<Xarrange_impl::clone_forward1_t<NV>, 
                                    1>;
template <int NV>
using FilterFXMod = parameter::plain<Xarrange_impl::clone_cable13_t<NV>, 
                                     1>;
template <int NV>
using Harm = parameter::plain<Xarrange_impl::pma_t<NV>, 
                              2>;
template <int NV>
using HarmEnvSrc = parameter::plain<Xarrange_impl::event_data_reader_t<NV>, 
                                    0>;
template <int NV>
using EnvMod = parameter::plain<Xarrange_impl::pma_t<NV>, 
                                1>;
template <int NV>
using HarmLfoSrc = parameter::plain<Xarrange_impl::branch_t<NV>, 
                                    0>;
template <int NV>
using HarmLFoMod = parameter::plain<Xarrange_impl::pma3_t<NV>, 
                                    1>;
template <int NV>
using HarmTrk = parameter::plain<Xarrange_impl::pma2_t<NV>, 
                                 1>;
using HarmPb = parameter::empty;
template <int NV>
using Step = parameter::plain<Xarrange_impl::clone_cable3_t<NV>, 
                              1>;
template <int NV>
using Detune = parameter::plain<Xarrange_impl::pma28_t<NV>, 
                                2>;
template <int NV>
using DetuneEnvMod = parameter::plain<Xarrange_impl::pma28_t<NV>, 
                                      1>;
template <int NV>
using Detuneenvsrc = parameter::plain<Xarrange_impl::event_data_reader7_t<NV>, 
                                      0>;
template <int NV>
using DetuneLFOmod = parameter::plain<Xarrange_impl::pma29_t<NV>, 
                                      1>;
template <int NV>
using DetuneLFOsrc = parameter::plain<Xarrange_impl::branch7_t<NV>, 
                                      0>;
template <int NV>
using FxOffset = parameter::plain<Xarrange_impl::pma24_t<NV>, 
                                  2>;
template <int NV>
using FxEnvMod = parameter::plain<Xarrange_impl::pma24_t<NV>, 
                                  1>;
template <int NV>
using FxEnvSrc = parameter::plain<Xarrange_impl::event_data_reader6_t<NV>, 
                                  0>;
template <int NV>
using FxLfoMod = parameter::plain<Xarrange_impl::pma25_t<NV>, 
                                  1>;
template <int NV>
using FXLfoSrc = parameter::plain<Xarrange_impl::branch6_t<NV>, 
                                  0>;
template <int NV>
using FxVel = parameter::plain<Xarrange_impl::pma27_t<NV>, 
                               1>;
template <int NV>
using FxTrk = parameter::plain<Xarrange_impl::pma26_t<NV>, 
                               1>;
template <int NV>
using CutOffset = parameter::plain<Xarrange_impl::pma20_t<NV>, 
                                   2>;
template <int NV>
using CutEnvMod = parameter::plain<Xarrange_impl::pma20_t<NV>, 
                                   1>;
template <int NV>
using utEnvSrc = parameter::plain<Xarrange_impl::event_data_reader5_t<NV>, 
                                  0>;
template <int NV>
using CutlfoMod = parameter::plain<Xarrange_impl::pma21_t<NV>, 
                                   1>;
template <int NV>
using CutLfoSrc = parameter::plain<Xarrange_impl::branch5_t<NV>, 
                                   0>;
template <int NV>
using CutVel = parameter::plain<Xarrange_impl::pma23_t<NV>, 
                                1>;
template <int NV>
using CutTrk = parameter::plain<Xarrange_impl::pma22_t<NV>, 
                                1>;
template <int NV>
using Q = parameter::plain<Xarrange_impl::pma16_t<NV>, 
                           2>;
template <int NV>
using QEnvMod = parameter::plain<Xarrange_impl::pma16_t<NV>, 
                                 1>;
template <int NV>
using qEnvSrc = parameter::plain<Xarrange_impl::event_data_reader4_t<NV>, 
                                 0>;
template <int NV>
using qLfoMod = parameter::plain<Xarrange_impl::pma17_t<NV>, 
                                 1>;
template <int NV>
using qLfoSrc = parameter::plain<Xarrange_impl::branch4_t<NV>, 
                                 0>;
template <int NV>
using Mix = parameter::plain<Xarrange_impl::pma12_t<NV>, 
                             2>;
template <int NV>
using MixEnvMod = parameter::plain<Xarrange_impl::pma12_t<NV>, 
                                   1>;
template <int NV>
using MixSrc = parameter::plain<Xarrange_impl::event_data_reader3_t<NV>, 
                                0>;
template <int NV>
using MixLfo = parameter::plain<Xarrange_impl::pma13_t<NV>, 
                                1>;
template <int NV>
using MixLfoSrc = parameter::plain<Xarrange_impl::branch3_t<NV>, 
                                   0>;
template <int NV>
using PanSpread = parameter::plain<Xarrange_impl::clone_cable10_t<NV>, 
                                   1>;
template <int NV>
using PitchSh = parameter::plain<Xarrange_impl::clone_cable12_t<NV>, 
                                 1>;
template <int NV>
using Xarrange_t_plist = parameter::list<Stages<NV>, 
                                         SampleOSc<NV>, 
                                         Min<NV>, 
                                         FXmix<NV>, 
                                         SHtempoSync<NV>, 
                                         SHDiv<NV>, 
                                         FilterType<NV>, 
                                         FilterFXMod<NV>, 
                                         Harm<NV>, 
                                         HarmEnvSrc<NV>, 
                                         EnvMod<NV>, 
                                         HarmLfoSrc<NV>, 
                                         HarmLFoMod<NV>, 
                                         HarmTrk<NV>, 
                                         HarmPb, 
                                         MAX<NV>, 
                                         Step<NV>, 
                                         Detune<NV>, 
                                         DetuneEnvMod<NV>, 
                                         Detuneenvsrc<NV>, 
                                         DetuneLFOmod<NV>, 
                                         DetuneLFOsrc<NV>, 
                                         FxOffset<NV>, 
                                         FxEnvMod<NV>, 
                                         FxEnvSrc<NV>, 
                                         FxLfoMod<NV>, 
                                         FXLfoSrc<NV>, 
                                         FxVel<NV>, 
                                         FxTrk<NV>, 
                                         CutOffset<NV>, 
                                         CutEnvMod<NV>, 
                                         utEnvSrc<NV>, 
                                         CutlfoMod<NV>, 
                                         CutLfoSrc<NV>, 
                                         CutVel<NV>, 
                                         CutTrk<NV>, 
                                         Q<NV>, 
                                         QEnvMod<NV>, 
                                         qEnvSrc<NV>, 
                                         qLfoMod<NV>, 
                                         qLfoSrc<NV>, 
                                         Mix<NV>, 
                                         MixEnvMod<NV>, 
                                         MixSrc<NV>, 
                                         MixLfo<NV>, 
                                         MixLfoSrc<NV>, 
                                         PanSpread<NV>, 
                                         PitchSh<NV>>;
}

template <int NV>
using Xarrange_t_ = container::chain<Xarrange_t_parameters::Xarrange_t_plist<NV>, 
                                     wrap::fix<2, modchain_t<NV>>, 
                                     clone1_t<NV>, 
                                     core::gain<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Xarrange_impl::Xarrange_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 10;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Xarrange);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(804)
		{
			0x005B, 0x0000, 0x5300, 0x6174, 0x6567, 0x0073, 0x0000, 0x3F80, 
            0x0000, 0x4200, 0x0000, 0x4110, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x015B, 0x0000, 0x5300, 0x6D61, 0x6C70, 0x4F65, 0x6353, 0x0000, 
            0x0000, 0x0000, 0x3000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0002, 0x0000, 0x694D, 0x006E, 0x0000, 0x3F80, 
            0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x035B, 0x0000, 0x4600, 0x6D58, 0x7869, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0004, 0x0000, 0x4853, 0x6574, 0x706D, 0x536F, 0x6E79, 0x0063, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x055B, 0x0000, 0x5300, 0x4448, 0x7669, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0006, 0x0000, 0x6946, 0x746C, 0x7265, 0x7954, 
            0x6570, 0x0000, 0x0000, 0x0000, 0xA000, 0x0040, 0x8400, 0x003C, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 0x6946, 0x746C, 
            0x7265, 0x5846, 0x6F4D, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0xCCCD, 0x3D20, 0x0000, 0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 
            0x4800, 0x7261, 0x006D, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 0x4800, 
            0x7261, 0x456D, 0x766E, 0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x4180, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0A5B, 
            0x0000, 0x4500, 0x766E, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0B5B, 
            0x0000, 0x4800, 0x7261, 0x4C6D, 0x6F66, 0x7253, 0x0063, 0x0000, 
            0x0000, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0C5B, 0x0000, 0x4800, 0x7261, 0x4C6D, 0x6F46, 0x6F4D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0D5B, 0x0000, 0x4800, 0x7261, 0x546D, 
            0x6B72, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x000E, 0x0000, 0x6148, 0x6D72, 
            0x6250, 0x0000, 0x8000, 0x00BF, 0x8000, 0x583F, 0x3439, 0x00BC, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x000F, 0x0000, 0x414D, 0x0058, 
            0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x4160, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x105B, 0x0000, 0x5300, 0x6574, 0x0070, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x115B, 0x0000, 0x4400, 0x7465, 0x6E75, 0x0065, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x125B, 0x0000, 0x4400, 0x7465, 0x6E75, 0x4565, 0x766E, 
            0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x4B33, 0x3F75, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x135B, 0x0000, 0x4400, 0x7465, 
            0x6E75, 0x6565, 0x766E, 0x7273, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x4180, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x145B, 
            0x0000, 0x4400, 0x7465, 0x6E75, 0x4C65, 0x4F46, 0x6F6D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x155B, 0x0000, 0x4400, 0x7465, 0x6E75, 0x4C65, 
            0x4F46, 0x7273, 0x0063, 0x0000, 0x0000, 0x0000, 0x4040, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x165B, 0x0000, 0x4600, 
            0x4F78, 0x6666, 0x6573, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x175B, 0x0000, 
            0x4600, 0x4578, 0x766E, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0xCCCD, 0xBDA0, 0x0000, 0x3F80, 0x0000, 0x0000, 0x185B, 
            0x0000, 0x4600, 0x4578, 0x766E, 0x7253, 0x0063, 0x0000, 0x0000, 
            0x0000, 0x4180, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x195B, 0x0000, 0x4600, 0x4C78, 0x6F66, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x1A5B, 0x0000, 0x4600, 0x4C58, 0x6F66, 0x7253, 0x0063, 
            0x0000, 0x0000, 0x0000, 0x4040, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x1B5B, 0x0000, 0x4600, 0x5678, 0x6C65, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x001C, 0x0000, 0x7846, 0x7254, 0x006B, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0xCCCD, 0xBDDC, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x1D5B, 0x0000, 0x4300, 0x7475, 0x664F, 0x7366, 0x7465, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x913F, 0x3A05, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x001E, 0x0000, 0x7543, 0x4574, 0x766E, 
            0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x1F5B, 0x0000, 0x7500, 0x4574, 
            0x766E, 0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 0x4180, 0x0000, 
            0x4150, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x205B, 0x0000, 0x4300, 
            0x7475, 0x666C, 0x4D6F, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0021, 
            0x0000, 0x7543, 0x4C74, 0x6F66, 0x7253, 0x0063, 0x0000, 0x0000, 
            0x0000, 0x4040, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x225B, 0x0000, 0x4300, 0x7475, 0x6556, 0x006C, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x37A7, 0xBE83, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x235B, 0x0000, 0x4300, 0x7475, 0x7254, 0x006B, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x8CCD, 0x3F15, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x245B, 0x0000, 0x5100, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0025, 0x0000, 
            0x4551, 0x766E, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x265B, 0x0000, 
            0x7100, 0x6E45, 0x5376, 0x6372, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0027, 
            0x0000, 0x4C71, 0x6F66, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x285B, 
            0x0000, 0x7100, 0x664C, 0x536F, 0x6372, 0x0000, 0x0000, 0x0000, 
            0x4000, 0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0029, 0x0000, 0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x2A5B, 0x0000, 
            0x4D00, 0x7869, 0x6E45, 0x4D76, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x002B, 0x0000, 0x694D, 0x5378, 0x6372, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x002C, 0x0000, 0x694D, 0x4C78, 0x6F66, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x002D, 0x0000, 0x694D, 0x4C78, 0x6F66, 0x7253, 0x0063, 0x0000, 
            0x0000, 0x0000, 0x4040, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x2E5B, 0x0000, 0x5000, 0x6E61, 0x7053, 0x6572, 0x6461, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x002F, 0x0000, 0x6950, 0x6374, 0x5368, 
            0x0068, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                // Xarrange_impl::modchain_t<NV>
		auto& chain4 = this->getT(0).getT(0);                                          // Xarrange_impl::chain4_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(0);                                  // Xarrange_impl::split2_t<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(0);                          // Xarrange_impl::chain3_t<NV>
		auto& event_data_reader = this->getT(0).getT(0).getT(0).getT(0).getT(0);       // Xarrange_impl::event_data_reader_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0).getT(0).getT(1);                     // Xarrange_impl::pma_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(1);                         // Xarrange_impl::chain10_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                 // Xarrange_impl::chain25_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);          // Xarrange_impl::branch_t<NV>
		auto& chain18 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0); // Xarrange_impl::chain18_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(1).                    // Xarrange_impl::global_cable_t<NV>
                             getT(0).getT(0).getT(0).getT(0);
		auto& add10 = this->getT(0).getT(0).getT(0).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1);
		auto& chain22 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1); // Xarrange_impl::chain22_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(0).getT(1).                  // Xarrange_impl::global_cable11_t<NV>
                               getT(0).getT(0).getT(1).getT(0);
		auto& add11 = this->getT(0).getT(0).getT(0).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& chain23 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(2); // Xarrange_impl::chain23_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(0).getT(1).                  // Xarrange_impl::global_cable12_t<NV>
                               getT(0).getT(0).getT(2).getT(0);
		auto& add12 = this->getT(0).getT(0).getT(0).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(2).getT(1);
		auto& chain24 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(3); // Xarrange_impl::chain24_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(0).getT(1).                  // Xarrange_impl::global_cable13_t<NV>
                               getT(0).getT(0).getT(3).getT(0);
		auto& add13 = this->getT(0).getT(0).getT(0).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(3).getT(1);
		auto& peak1 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);           // Xarrange_impl::peak1_t<NV>
		auto& clear = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);           // math::clear<NV>
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3);            // Xarrange_impl::pma3_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(2);                          // Xarrange_impl::chain6_t<NV>
		auto& midi2 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                   // Xarrange_impl::midi2_t<NV>
		auto& pma2 = this->getT(0).getT(0).getT(0).getT(2).getT(1);                    // Xarrange_impl::pma2_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(3);                          // Xarrange_impl::chain5_t<NV>
		auto& midi_cc = this->getT(0).getT(0).getT(0).getT(3).getT(0);                 // Xarrange_impl::midi_cc_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(3).getT(1);                    // Xarrange_impl::pma6_t<NV>
		auto& split9 = this->getT(0).getT(0).getT(1);                                  // Xarrange_impl::split9_t<NV>
		auto& chain67 = this->getT(0).getT(0).getT(1).getT(0);                         // Xarrange_impl::chain67_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(1).getT(0).getT(0);      // Xarrange_impl::event_data_reader7_t<NV>
		auto& pma28 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                   // Xarrange_impl::pma28_t<NV>
		auto& chain68 = this->getT(0).getT(0).getT(1).getT(1);                         // Xarrange_impl::chain68_t<NV>
		auto& chain69 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                 // Xarrange_impl::chain69_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0);         // Xarrange_impl::branch7_t<NV>
		auto& chain70 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).getT(0); // Xarrange_impl::chain70_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(1).getT(1).                   // Xarrange_impl::global_cable7_t<NV>
                              getT(0).getT(0).getT(0).getT(0);
		auto& add38 = this->getT(0).getT(0).getT(1).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1);
		auto& chain71 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).getT(1); // Xarrange_impl::chain71_t<NV>
		auto& global_cable32 = this->getT(0).getT(0).getT(1).getT(1).                  // Xarrange_impl::global_cable32_t<NV>
                               getT(0).getT(0).getT(1).getT(0);
		auto& add39 = this->getT(0).getT(0).getT(1).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& chain72 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).getT(2); // Xarrange_impl::chain72_t<NV>
		auto& global_cable33 = this->getT(0).getT(0).getT(1).getT(1).                  // Xarrange_impl::global_cable33_t<NV>
                               getT(0).getT(0).getT(2).getT(0);
		auto& add40 = this->getT(0).getT(0).getT(1).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(2).getT(1);
		auto& chain73 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).getT(3); // Xarrange_impl::chain73_t<NV>
		auto& global_cable34 = this->getT(0).getT(0).getT(1).getT(1).                  // Xarrange_impl::global_cable34_t<NV>
                               getT(0).getT(0).getT(3).getT(0);
		auto& add41 = this->getT(0).getT(0).getT(1).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(3).getT(1);
		auto& peak7 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(1);           // Xarrange_impl::peak7_t<NV>
		auto& clear7 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(2);          // math::clear<NV>
		auto& pma29 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                   // Xarrange_impl::pma29_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(2);                                  // Xarrange_impl::split8_t<NV>
		auto& chain58 = this->getT(0).getT(0).getT(2).getT(0);                         // Xarrange_impl::chain58_t<NV>
		auto& event_data_reader6 = this->getT(0).getT(0).getT(2).getT(0).getT(0);      // Xarrange_impl::event_data_reader6_t<NV>
		auto& pma24 = this->getT(0).getT(0).getT(2).getT(0).getT(1);                   // Xarrange_impl::pma24_t<NV>
		auto& chain59 = this->getT(0).getT(0).getT(2).getT(1);                         // Xarrange_impl::chain59_t<NV>
		auto& chain60 = this->getT(0).getT(0).getT(2).getT(1).getT(0);                 // Xarrange_impl::chain60_t<NV>
		auto& branch6 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);         // Xarrange_impl::branch6_t<NV>
		auto& chain61 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(0); // Xarrange_impl::chain61_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(2).getT(1).                   // Xarrange_impl::global_cable6_t<NV>
                              getT(0).getT(0).getT(0).getT(0);
		auto& add34 = this->getT(0).getT(0).getT(2).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1);
		auto& chain62 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(1); // Xarrange_impl::chain62_t<NV>
		auto& global_cable29 = this->getT(0).getT(0).getT(2).getT(1).                  // Xarrange_impl::global_cable29_t<NV>
                               getT(0).getT(0).getT(1).getT(0);
		auto& add35 = this->getT(0).getT(0).getT(2).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& chain63 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(2); // Xarrange_impl::chain63_t<NV>
		auto& global_cable30 = this->getT(0).getT(0).getT(2).getT(1).                  // Xarrange_impl::global_cable30_t<NV>
                               getT(0).getT(0).getT(2).getT(0);
		auto& add36 = this->getT(0).getT(0).getT(2).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(2).getT(1);
		auto& chain64 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(3); // Xarrange_impl::chain64_t<NV>
		auto& global_cable31 = this->getT(0).getT(0).getT(2).getT(1).                  // Xarrange_impl::global_cable31_t<NV>
                               getT(0).getT(0).getT(3).getT(0);
		auto& add37 = this->getT(0).getT(0).getT(2).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(3).getT(1);
		auto& peak6 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);           // Xarrange_impl::peak6_t<NV>
		auto& clear6 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);          // math::clear<NV>
		auto& pma25 = this->getT(0).getT(0).getT(2).getT(1).getT(1);                   // Xarrange_impl::pma25_t<NV>
		auto& chain65 = this->getT(0).getT(0).getT(2).getT(2);                         // Xarrange_impl::chain65_t<NV>
		auto& midi13 = this->getT(0).getT(0).getT(2).getT(2).getT(0);                  // Xarrange_impl::midi13_t<NV>
		auto& pma26 = this->getT(0).getT(0).getT(2).getT(2).getT(1);                   // Xarrange_impl::pma26_t<NV>
		auto& chain66 = this->getT(0).getT(0).getT(2).getT(3);                         // Xarrange_impl::chain66_t<NV>
		auto& midi14 = this->getT(0).getT(0).getT(2).getT(3).getT(0);                  // Xarrange_impl::midi14_t<NV>
		auto& pma27 = this->getT(0).getT(0).getT(2).getT(3).getT(1);                   // Xarrange_impl::pma27_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(3);                                  // Xarrange_impl::split7_t<NV>
		auto& chain49 = this->getT(0).getT(0).getT(3).getT(0);                         // Xarrange_impl::chain49_t<NV>
		auto& event_data_reader5 = this->getT(0).getT(0).getT(3).getT(0).getT(0);      // Xarrange_impl::event_data_reader5_t<NV>
		auto& pma20 = this->getT(0).getT(0).getT(3).getT(0).getT(1);                   // Xarrange_impl::pma20_t<NV>
		auto& chain50 = this->getT(0).getT(0).getT(3).getT(1);                         // Xarrange_impl::chain50_t<NV>
		auto& chain51 = this->getT(0).getT(0).getT(3).getT(1).getT(0);                 // Xarrange_impl::chain51_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(0);         // Xarrange_impl::branch5_t<NV>
		auto& chain52 = this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(0).getT(0); // Xarrange_impl::chain52_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(3).getT(1).                   // Xarrange_impl::global_cable5_t<NV>
                              getT(0).getT(0).getT(0).getT(0);
		auto& add30 = this->getT(0).getT(0).getT(3).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1);
		auto& chain53 = this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(0).getT(1); // Xarrange_impl::chain53_t<NV>
		auto& global_cable26 = this->getT(0).getT(0).getT(3).getT(1).                  // Xarrange_impl::global_cable26_t<NV>
                               getT(0).getT(0).getT(1).getT(0);
		auto& add31 = this->getT(0).getT(0).getT(3).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& chain54 = this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(0).getT(2); // Xarrange_impl::chain54_t<NV>
		auto& global_cable27 = this->getT(0).getT(0).getT(3).getT(1).                  // Xarrange_impl::global_cable27_t<NV>
                               getT(0).getT(0).getT(2).getT(0);
		auto& add32 = this->getT(0).getT(0).getT(3).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(2).getT(1);
		auto& chain55 = this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(0).getT(3); // Xarrange_impl::chain55_t<NV>
		auto& global_cable28 = this->getT(0).getT(0).getT(3).getT(1).                  // Xarrange_impl::global_cable28_t<NV>
                               getT(0).getT(0).getT(3).getT(0);
		auto& add33 = this->getT(0).getT(0).getT(3).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(3).getT(1);
		auto& peak5 = this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(1);           // Xarrange_impl::peak5_t<NV>
		auto& clear5 = this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(2);          // math::clear<NV>
		auto& pma21 = this->getT(0).getT(0).getT(3).getT(1).getT(1);                   // Xarrange_impl::pma21_t<NV>
		auto& chain56 = this->getT(0).getT(0).getT(3).getT(2);                         // Xarrange_impl::chain56_t<NV>
		auto& midi11 = this->getT(0).getT(0).getT(3).getT(2).getT(0);                  // Xarrange_impl::midi11_t<NV>
		auto& pma22 = this->getT(0).getT(0).getT(3).getT(2).getT(1);                   // Xarrange_impl::pma22_t<NV>
		auto& chain57 = this->getT(0).getT(0).getT(3).getT(3);                         // Xarrange_impl::chain57_t<NV>
		auto& midi12 = this->getT(0).getT(0).getT(3).getT(3).getT(0);                  // Xarrange_impl::midi12_t<NV>
		auto& pma23 = this->getT(0).getT(0).getT(3).getT(3).getT(1);                   // Xarrange_impl::pma23_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(4);                                  // Xarrange_impl::split6_t<NV>
		auto& chain40 = this->getT(0).getT(0).getT(4).getT(0);                         // Xarrange_impl::chain40_t<NV>
		auto& event_data_reader4 = this->getT(0).getT(0).getT(4).getT(0).getT(0);      // Xarrange_impl::event_data_reader4_t<NV>
		auto& pma16 = this->getT(0).getT(0).getT(4).getT(0).getT(1);                   // Xarrange_impl::pma16_t<NV>
		auto& chain41 = this->getT(0).getT(0).getT(4).getT(1);                         // Xarrange_impl::chain41_t<NV>
		auto& chain42 = this->getT(0).getT(0).getT(4).getT(1).getT(0);                 // Xarrange_impl::chain42_t<NV>
		auto& branch4 = this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(0);         // Xarrange_impl::branch4_t<NV>
		auto& chain43 = this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(0).getT(0); // Xarrange_impl::chain43_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(4).getT(1).                   // Xarrange_impl::global_cable4_t<NV>
                              getT(0).getT(0).getT(0).getT(0);
		auto& add26 = this->getT(0).getT(0).getT(4).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1);
		auto& chain44 = this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(0).getT(1); // Xarrange_impl::chain44_t<NV>
		auto& global_cable23 = this->getT(0).getT(0).getT(4).getT(1).                  // Xarrange_impl::global_cable23_t<NV>
                               getT(0).getT(0).getT(1).getT(0);
		auto& add27 = this->getT(0).getT(0).getT(4).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& chain45 = this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(0).getT(2); // Xarrange_impl::chain45_t<NV>
		auto& global_cable24 = this->getT(0).getT(0).getT(4).getT(1).                  // Xarrange_impl::global_cable24_t<NV>
                               getT(0).getT(0).getT(2).getT(0);
		auto& add28 = this->getT(0).getT(0).getT(4).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(2).getT(1);
		auto& chain46 = this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(0).getT(3); // Xarrange_impl::chain46_t<NV>
		auto& global_cable25 = this->getT(0).getT(0).getT(4).getT(1).                  // Xarrange_impl::global_cable25_t<NV>
                               getT(0).getT(0).getT(3).getT(0);
		auto& add29 = this->getT(0).getT(0).getT(4).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(3).getT(1);
		auto& peak4 = this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(1);           // Xarrange_impl::peak4_t<NV>
		auto& clear4 = this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(2);          // math::clear<NV>
		auto& pma17 = this->getT(0).getT(0).getT(4).getT(1).getT(1);                   // Xarrange_impl::pma17_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(5);                                  // Xarrange_impl::split5_t<NV>
		auto& chain16 = this->getT(0).getT(0).getT(5).getT(0);                         // Xarrange_impl::chain16_t<NV>
		auto& event_data_reader3 = this->getT(0).getT(0).getT(5).getT(0).getT(0);      // Xarrange_impl::event_data_reader3_t<NV>
		auto& pma12 = this->getT(0).getT(0).getT(5).getT(0).getT(1);                   // Xarrange_impl::pma12_t<NV>
		auto& chain17 = this->getT(0).getT(0).getT(5).getT(1);                         // Xarrange_impl::chain17_t<NV>
		auto& chain34 = this->getT(0).getT(0).getT(5).getT(1).getT(0);                 // Xarrange_impl::chain34_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(0);         // Xarrange_impl::branch3_t<NV>
		auto& chain21 = this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(0).getT(0); // Xarrange_impl::chain21_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(5).getT(1).                   // Xarrange_impl::global_cable3_t<NV>
                              getT(0).getT(0).getT(0).getT(0);
		auto& add22 = this->getT(0).getT(0).getT(5).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(0).getT(1); // Xarrange_impl::chain35_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(5).getT(1).                  // Xarrange_impl::global_cable20_t<NV>
                               getT(0).getT(0).getT(1).getT(0);
		auto& add23 = this->getT(0).getT(0).getT(5).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(0).getT(2); // Xarrange_impl::chain36_t<NV>
		auto& global_cable21 = this->getT(0).getT(0).getT(5).getT(1).                  // Xarrange_impl::global_cable21_t<NV>
                               getT(0).getT(0).getT(2).getT(0);
		auto& add24 = this->getT(0).getT(0).getT(5).getT(1).                           // math::add<NV>
                      getT(0).getT(0).getT(2).getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(0).getT(3); // Xarrange_impl::chain37_t<NV>
		auto& global_cable22 = this->getT(0).getT(0).getT(5).getT(1).                  // Xarrange_impl::global_cable22_t<NV>
                               getT(0).getT(0).getT(3).getT(0);
		auto& add25 = this->getT(0).getT(0).getT(5).getT(1).                  // math::add<NV>
                      getT(0).getT(0).getT(3).getT(1);
		auto& peak3 = this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(1);  // Xarrange_impl::peak3_t<NV>
		auto& clear3 = this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(2); // math::clear<NV>
		auto& pma13 = this->getT(0).getT(0).getT(5).getT(1).getT(1);          // Xarrange_impl::pma13_t<NV>
		auto& no_midi = this->getT(0).getT(1);                                // Xarrange_impl::no_midi_t<NV>
		auto& split1 = this->getT(0).getT(1).getT(0);                         // Xarrange_impl::split1_t
		auto& pack_resizer = this->getT(0).getT(1).getT(0).getT(0);           // Xarrange_impl::pack_resizer_t
		auto& pack_resizer1 = this->getT(0).getT(1).getT(0).getT(1);          // Xarrange_impl::pack_resizer1_t
		auto& pack_resizer2 = this->getT(0).getT(1).getT(0).getT(2);          // Xarrange_impl::pack_resizer2_t
		auto& split = this->getT(0).getT(1).getT(1);                          // Xarrange_impl::split_t<NV>
		auto& chain = this->getT(0).getT(1).getT(1).getT(0);                  // Xarrange_impl::chain_t<NV>
		auto& clone_pack = this->getT(0).getT(1).getT(1).getT(0).getT(0);     // Xarrange_impl::clone_pack_t<NV>
		auto& clone_cable = this->getT(0).getT(1).getT(1).getT(0).getT(1);    // Xarrange_impl::clone_cable_t<NV>
		auto& clone_cable4 = this->getT(0).getT(1).getT(1).getT(0).getT(2);   // Xarrange_impl::clone_cable4_t<NV>
		auto& clone_cable3 = this->getT(0).getT(1).getT(1).getT(0).getT(3);   // Xarrange_impl::clone_cable3_t<NV>
		auto& clone_forward = this->getT(0).getT(1).getT(1).getT(0).getT(4);  // Xarrange_impl::clone_forward_t<NV>
		auto& clone_cable11 = this->getT(0).getT(1).getT(1).getT(0).getT(5);  // Xarrange_impl::clone_cable11_t<NV>
		auto& clone_cable12 = this->getT(0).getT(1).getT(1).getT(0).getT(6);  // Xarrange_impl::clone_cable12_t<NV>
		auto& chain2 = this->getT(0).getT(1).getT(1).getT(1);                 // Xarrange_impl::chain2_t<NV>
		auto& clone_pack2 = this->getT(0).getT(1).getT(1).getT(1).getT(0);    // Xarrange_impl::clone_pack2_t<NV>
		auto& clone_cable2 = this->getT(0).getT(1).getT(1).getT(1).getT(1);   // Xarrange_impl::clone_cable2_t<NV>
		auto& clone_cable9 = this->getT(0).getT(1).getT(1).getT(1).getT(2);   // Xarrange_impl::clone_cable9_t<NV>
		auto& clone_cable8 = this->getT(0).getT(1).getT(1).getT(1).getT(3);   // Xarrange_impl::clone_cable8_t<NV>
		auto& chain1 = this->getT(0).getT(1).getT(1).getT(2);                 // Xarrange_impl::chain1_t<NV>
		auto& clone_pack1 = this->getT(0).getT(1).getT(1).getT(2).getT(0);    // Xarrange_impl::clone_pack1_t<NV>
		auto& clone_cable1 = this->getT(0).getT(1).getT(1).getT(2).getT(1);   // Xarrange_impl::clone_cable1_t<NV>
		auto& clone_forward1 = this->getT(0).getT(1).getT(1).getT(2).getT(2); // Xarrange_impl::clone_forward1_t<NV>
		auto& clone_cable14 = this->getT(0).getT(1).getT(1).getT(2).getT(3);  // Xarrange_impl::clone_cable14_t<NV>
		auto& clone_cable13 = this->getT(0).getT(1).getT(1).getT(2).getT(4);  // Xarrange_impl::clone_cable13_t<NV>
		auto& clone_cable10 = this->getT(0).getT(1).getT(1).getT(2).getT(5);  // Xarrange_impl::clone_cable10_t<NV>
		auto& clone1 = this->getT(1);                                         // Xarrange_impl::clone1_t<NV>                                         // Xarrange_impl::clone1_child_t<NV>
		auto xnode1 = this->getT(1).getT(0);                                  // Xarrange_impl::xnode1_t<NV>
		auto jpanner = this->getT(1).getT(1);                                 // jdsp::jpanner<NV>
		auto& gain = this->getT(2);                                           // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& Stages_p = this->getParameterT(0);
		Stages_p.connectT(0, clone1);          // Stages -> clone1::NumClones
		Stages_p.connectT(1, clone_pack);      // Stages -> clone_pack::NumClones
		Stages_p.connectT(2, clone_pack2);     // Stages -> clone_pack2::NumClones
		Stages_p.connectT(3, clone_pack1);     // Stages -> clone_pack1::NumClones
		Stages_p.connectT(4, clone_cable);     // Stages -> clone_cable::NumClones
		Stages_p.connectT(5, clone_cable2);    // Stages -> clone_cable2::NumClones
		Stages_p.connectT(6, clone_cable1);    // Stages -> clone_cable1::NumClones
		Stages_p.connectT(7, clone_cable4);    // Stages -> clone_cable4::NumClones
		Stages_p.connectT(8, clone_cable9);    // Stages -> clone_cable9::NumClones
		Stages_p.connectT(9, clone_cable3);    // Stages -> clone_cable3::NumClones
		Stages_p.connectT(10, clone_forward);  // Stages -> clone_forward::NumClones
		Stages_p.connectT(11, clone_cable11);  // Stages -> clone_cable11::NumClones
		Stages_p.connectT(12, clone_cable8);   // Stages -> clone_cable8::NumClones
		Stages_p.connectT(13, clone_cable13);  // Stages -> clone_cable13::NumClones
		Stages_p.connectT(14, clone_cable14);  // Stages -> clone_cable14::NumClones
		Stages_p.connectT(15, pack_resizer);   // Stages -> pack_resizer::NumSliders
		Stages_p.connectT(16, pack_resizer1);  // Stages -> pack_resizer1::NumSliders
		Stages_p.connectT(17, pack_resizer2);  // Stages -> pack_resizer2::NumSliders
		Stages_p.connectT(18, clone_forward1); // Stages -> clone_forward1::NumClones
		Stages_p.connectT(19, clone_cable10);  // Stages -> clone_cable10::NumClones
		Stages_p.connectT(20, clone_cable12);  // Stages -> clone_cable12::NumClones
		
		this->getParameterT(1).connectT(0, clone_forward); // SampleOSc -> clone_forward::Value
		
		this->getParameterT(2).connectT(0, clone_cable); // Min -> clone_cable::Value
		
		this->getParameterT(3).connectT(0, clone_cable2); // FXmix -> clone_cable2::Value
		
		this->getParameterT(4).connectT(0, clone_cable8); // SHtempoSync -> clone_cable8::Value
		
		this->getParameterT(5).connectT(0, clone_cable9); // SHDiv -> clone_cable9::Value
		
		this->getParameterT(6).connectT(0, clone_forward1); // FilterType -> clone_forward1::Value
		
		this->getParameterT(7).connectT(0, clone_cable13); // FilterFXMod -> clone_cable13::Value
		
		this->getParameterT(8).connectT(0, pma); // Harm -> pma::Add
		
		this->getParameterT(9).connectT(0, event_data_reader); // HarmEnvSrc -> event_data_reader::SlotIndex
		
		this->getParameterT(10).connectT(0, pma); // EnvMod -> pma::Multiply
		
		this->getParameterT(11).connectT(0, branch); // HarmLfoSrc -> branch::Index
		
		this->getParameterT(12).connectT(0, pma3); // HarmLFoMod -> pma3::Multiply
		
		this->getParameterT(13).connectT(0, pma2); // HarmTrk -> pma2::Multiply
		
		this->getParameterT(15).connectT(0, clone_cable4); // MAX -> clone_cable4::Value
		
		this->getParameterT(16).connectT(0, clone_cable3); // Step -> clone_cable3::Value
		
		this->getParameterT(17).connectT(0, pma28); // Detune -> pma28::Add
		
		this->getParameterT(18).connectT(0, pma28); // DetuneEnvMod -> pma28::Multiply
		
		this->getParameterT(19).connectT(0, event_data_reader7); // Detuneenvsrc -> event_data_reader7::SlotIndex
		
		this->getParameterT(20).connectT(0, pma29); // DetuneLFOmod -> pma29::Multiply
		
		this->getParameterT(21).connectT(0, branch7); // DetuneLFOsrc -> branch7::Index
		
		this->getParameterT(22).connectT(0, pma24); // FxOffset -> pma24::Add
		
		this->getParameterT(23).connectT(0, pma24); // FxEnvMod -> pma24::Multiply
		
		this->getParameterT(24).connectT(0, event_data_reader6); // FxEnvSrc -> event_data_reader6::SlotIndex
		
		this->getParameterT(25).connectT(0, pma25); // FxLfoMod -> pma25::Multiply
		
		this->getParameterT(26).connectT(0, branch6); // FXLfoSrc -> branch6::Index
		
		this->getParameterT(27).connectT(0, pma27); // FxVel -> pma27::Multiply
		
		this->getParameterT(28).connectT(0, pma26); // FxTrk -> pma26::Multiply
		
		this->getParameterT(29).connectT(0, pma20); // CutOffset -> pma20::Add
		
		this->getParameterT(30).connectT(0, pma20); // CutEnvMod -> pma20::Multiply
		
		this->getParameterT(31).connectT(0, event_data_reader5); // utEnvSrc -> event_data_reader5::SlotIndex
		
		this->getParameterT(32).connectT(0, pma21); // CutlfoMod -> pma21::Multiply
		
		this->getParameterT(33).connectT(0, branch5); // CutLfoSrc -> branch5::Index
		
		this->getParameterT(34).connectT(0, pma23); // CutVel -> pma23::Multiply
		
		this->getParameterT(35).connectT(0, pma22); // CutTrk -> pma22::Multiply
		
		this->getParameterT(36).connectT(0, pma16); // Q -> pma16::Add
		
		this->getParameterT(37).connectT(0, pma16); // QEnvMod -> pma16::Multiply
		
		this->getParameterT(38).connectT(0, event_data_reader4); // qEnvSrc -> event_data_reader4::SlotIndex
		
		this->getParameterT(39).connectT(0, pma17); // qLfoMod -> pma17::Multiply
		
		this->getParameterT(40).connectT(0, branch4); // qLfoSrc -> branch4::Index
		
		this->getParameterT(41).connectT(0, pma12); // Mix -> pma12::Add
		
		this->getParameterT(42).connectT(0, pma12); // MixEnvMod -> pma12::Multiply
		
		this->getParameterT(43).connectT(0, event_data_reader3); // MixSrc -> event_data_reader3::SlotIndex
		
		this->getParameterT(44).connectT(0, pma13); // MixLfo -> pma13::Multiply
		
		this->getParameterT(45).connectT(0, branch3); // MixLfoSrc -> branch3::Index
		
		this->getParameterT(46).connectT(0, clone_cable10); // PanSpread -> clone_cable10::Value
		
		this->getParameterT(47).connectT(0, clone_cable12); // PitchSh -> clone_cable12::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		clone_pack.getWrappedObject().getParameter().connectT(0, xnode1);     // clone_pack -> xnode1::Harm
		pma6.getWrappedObject().getParameter().connectT(0, clone_pack);       // pma6 -> clone_pack::Value
		pma2.getWrappedObject().getParameter().connectT(0, pma6);             // pma2 -> pma6::Value
		pma3.getWrappedObject().getParameter().connectT(0, pma2);             // pma3 -> pma2::Add
		pma.getWrappedObject().getParameter().connectT(0, pma3);              // pma -> pma3::Add
		event_data_reader.getParameter().connectT(0, pma);                    // event_data_reader -> pma::Value
		global_cable.getWrappedObject().getParameter().connectT(0, add10);    // global_cable -> add10::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add11);  // global_cable11 -> add11::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add12);  // global_cable12 -> add12::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add13);  // global_cable13 -> add13::Value
		peak1.getParameter().connectT(0, pma3);                               // peak1 -> pma3::Value
		midi2.getParameter().connectT(0, pma2);                               // midi2 -> pma2::Value
		midi_cc.getWrappedObject().getParameter().connectT(0, pma6);          // midi_cc -> pma6::Add
		clone_cable11.getWrappedObject().getParameter().connectT(0, xnode1);  // clone_cable11 -> xnode1::DET
		pma29.getWrappedObject().getParameter().connectT(0, clone_cable11);   // pma29 -> clone_cable11::Value
		pma28.getWrappedObject().getParameter().connectT(0, pma29);           // pma28 -> pma29::Add
		event_data_reader7.getParameter().connectT(0, pma28);                 // event_data_reader7 -> pma28::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add38);   // global_cable7 -> add38::Value
		global_cable32.getWrappedObject().getParameter().connectT(0, add39);  // global_cable32 -> add39::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add40);  // global_cable33 -> add40::Value
		global_cable34.getWrappedObject().getParameter().connectT(0, add41);  // global_cable34 -> add41::Value
		peak7.getParameter().connectT(0, pma29);                              // peak7 -> pma29::Value
		clone_pack2.getWrappedObject().getParameter().connectT(0, xnode1);    // clone_pack2 -> xnode1::FxValue
		pma27.getWrappedObject().getParameter().connectT(0, clone_pack2);     // pma27 -> clone_pack2::Value
		pma26.getWrappedObject().getParameter().connectT(0, pma27);           // pma26 -> pma27::Add
		pma25.getWrappedObject().getParameter().connectT(0, pma26);           // pma25 -> pma26::Add
		pma24.getWrappedObject().getParameter().connectT(0, pma25);           // pma24 -> pma25::Add
		event_data_reader6.getParameter().connectT(0, pma24);                 // event_data_reader6 -> pma24::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add34);   // global_cable6 -> add34::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add35);  // global_cable29 -> add35::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add36);  // global_cable30 -> add36::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add37);  // global_cable31 -> add37::Value
		peak6.getParameter().connectT(0, pma25);                              // peak6 -> pma25::Value
		midi13.getParameter().connectT(0, pma26);                             // midi13 -> pma26::Value
		midi14.getParameter().connectT(0, pma27);                             // midi14 -> pma27::Value
		clone_pack1.getWrappedObject().getParameter().connectT(0, xnode1);    // clone_pack1 -> xnode1::FilterCut
		pma23.getWrappedObject().getParameter().connectT(0, clone_pack1);     // pma23 -> clone_pack1::Value
		pma22.getWrappedObject().getParameter().connectT(0, pma23);           // pma22 -> pma23::Add
		pma21.getWrappedObject().getParameter().connectT(0, pma22);           // pma21 -> pma22::Add
		pma20.getWrappedObject().getParameter().connectT(0, pma21);           // pma20 -> pma21::Add
		event_data_reader5.getParameter().connectT(0, pma20);                 // event_data_reader5 -> pma20::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add30);   // global_cable5 -> add30::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add31);  // global_cable26 -> add31::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add32);  // global_cable27 -> add32::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add33);  // global_cable28 -> add33::Value
		peak5.getParameter().connectT(0, pma21);                              // peak5 -> pma21::Value
		midi11.getParameter().connectT(0, pma22);                             // midi11 -> pma22::Value
		midi12.getParameter().connectT(0, pma23);                             // midi12 -> pma23::Value
		clone_cable14.getWrappedObject().getParameter().connectT(0, xnode1);  // clone_cable14 -> xnode1::FilterRes
		pma17.getWrappedObject().getParameter().connectT(0, clone_cable14);   // pma17 -> clone_cable14::Value
		pma16.getWrappedObject().getParameter().connectT(0, pma17);           // pma16 -> pma17::Add
		event_data_reader4.getParameter().connectT(0, pma16);                 // event_data_reader4 -> pma16::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add26);   // global_cable4 -> add26::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add27);  // global_cable23 -> add27::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add28);  // global_cable24 -> add28::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add29);  // global_cable25 -> add29::Value
		peak4.getParameter().connectT(0, pma17);                              // peak4 -> pma17::Value
		clone_cable1.getWrappedObject().getParameter().connectT(0, xnode1);   // clone_cable1 -> xnode1::FilterMix
		pma13.getWrappedObject().getParameter().connectT(0, clone_cable1);    // pma13 -> clone_cable1::Value
		pma12.getWrappedObject().getParameter().connectT(0, pma13);           // pma12 -> pma13::Add
		event_data_reader3.getParameter().connectT(0, pma12);                 // event_data_reader3 -> pma12::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add22);   // global_cable3 -> add22::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add23);  // global_cable20 -> add23::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add24);  // global_cable21 -> add24::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add25);  // global_cable22 -> add25::Value
		peak3.getParameter().connectT(0, pma13);                              // peak3 -> pma13::Value
		clone_cable.getWrappedObject().getParameter().connectT(0, xnode1);    // clone_cable -> xnode1::min
		clone_cable4.getWrappedObject().getParameter().connectT(0, xnode1);   // clone_cable4 -> xnode1::max
		clone_cable3.getWrappedObject().getParameter().connectT(0, xnode1);   // clone_cable3 -> xnode1::step
		clone_forward.getWrappedObject().getParameter().connectT(0, xnode1);  // clone_forward -> xnode1::Mode
		clone_cable12.getWrappedObject().getParameter().connectT(0, xnode1);  // clone_cable12 -> xnode1::shPitch
		clone_cable2.getWrappedObject().getParameter().connectT(0, xnode1);   // clone_cable2 -> xnode1::FxMix
		clone_cable9.getWrappedObject().getParameter().connectT(0, xnode1);   // clone_cable9 -> xnode1::FxShDiv
		clone_cable8.getWrappedObject().getParameter().connectT(0, xnode1);   // clone_cable8 -> xnode1::FxShSync
		clone_forward1.getWrappedObject().getParameter().connectT(0, xnode1); // clone_forward1 -> xnode1::FilterType
		clone_cable13.getWrappedObject().getParameter().connectT(0, xnode1);  // clone_cable13 -> xnode1::FilterFxMod
		clone_cable10.getWrappedObject().getParameter().connectT(0, jpanner); // clone_cable10 -> jpanner::Pan
		
		// Default Values --------------------------------------------------------------------------
		
		;                                       // event_data_reader::SlotIndex is automated
		event_data_reader.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // branch::Index is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		midi_cc.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc.setParameterT(2, 0.5);  // control::midi_cc::DefaultValue
		
		;                          // pma6::Value is automated
		pma6.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma6::Add is automated
		
		;                                        // event_data_reader7::SlotIndex is automated
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma28::Value is automated
		; // pma28::Multiply is automated
		; // pma28::Add is automated
		
		; // branch7::Index is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add38::Value is automated
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add39::Value is automated
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add40::Value is automated
		
		global_cable34.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add41::Value is automated
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		; // pma29::Value is automated
		; // pma29::Multiply is automated
		; // pma29::Add is automated
		
		;                                        // event_data_reader6::SlotIndex is automated
		event_data_reader6.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma24::Value is automated
		; // pma24::Multiply is automated
		; // pma24::Add is automated
		
		; // branch6::Index is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add34::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add35::Value is automated
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add36::Value is automated
		
		global_cable31.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add37::Value is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		; // pma25::Value is automated
		; // pma25::Multiply is automated
		; // pma25::Add is automated
		
		; // pma26::Value is automated
		; // pma26::Multiply is automated
		; // pma26::Add is automated
		
		; // pma27::Value is automated
		; // pma27::Multiply is automated
		; // pma27::Add is automated
		
		;                                        // event_data_reader5::SlotIndex is automated
		event_data_reader5.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma20::Value is automated
		; // pma20::Multiply is automated
		; // pma20::Add is automated
		
		; // branch5::Index is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add30::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // pma21::Value is automated
		; // pma21::Multiply is automated
		; // pma21::Add is automated
		
		; // pma22::Value is automated
		; // pma22::Multiply is automated
		; // pma22::Add is automated
		
		; // pma23::Value is automated
		; // pma23::Multiply is automated
		; // pma23::Add is automated
		
		;                                        // event_data_reader4::SlotIndex is automated
		event_data_reader4.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma16::Value is automated
		; // pma16::Multiply is automated
		; // pma16::Add is automated
		
		; // branch4::Index is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add29::Value is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		; // pma17::Value is automated
		; // pma17::Multiply is automated
		; // pma17::Add is automated
		
		;                                        // event_data_reader3::SlotIndex is automated
		event_data_reader3.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma12::Value is automated
		; // pma12::Multiply is automated
		; // pma12::Add is automated
		
		; // branch3::Index is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add22::Value is automated
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add23::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add24::Value is automated
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add25::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // pma13::Value is automated
		; // pma13::Multiply is automated
		; // pma13::Add is automated
		
		; // pack_resizer::NumSliders is automated
		
		; // pack_resizer1::NumSliders is automated
		
		; // pack_resizer2::NumSliders is automated
		
		; // clone_pack::NumClones is automated
		; // clone_pack::Value is automated
		
		;                                 // clone_cable::NumClones is automated
		;                                 // clone_cable::Value is automated
		clone_cable.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable4::NumClones is automated
		;                                  // clone_cable4::Value is automated
		clone_cable4.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable3::NumClones is automated
		;                                  // clone_cable3::Value is automated
		clone_cable3.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // clone_forward::NumClones is automated
		; // clone_forward::Value is automated
		
		;                                   // clone_cable11::NumClones is automated
		;                                   // clone_cable11::Value is automated
		clone_cable11.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable12::NumClones is automated
		;                                   // clone_cable12::Value is automated
		clone_cable12.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // clone_pack2::NumClones is automated
		; // clone_pack2::Value is automated
		
		;                                  // clone_cable2::NumClones is automated
		;                                  // clone_cable2::Value is automated
		clone_cable2.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable9::NumClones is automated
		;                                  // clone_cable9::Value is automated
		clone_cable9.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable8::NumClones is automated
		;                                  // clone_cable8::Value is automated
		clone_cable8.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // clone_pack1::NumClones is automated
		; // clone_pack1::Value is automated
		
		;                                  // clone_cable1::NumClones is automated
		;                                  // clone_cable1::Value is automated
		clone_cable1.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // clone_forward1::NumClones is automated
		; // clone_forward1::Value is automated
		
		;                                   // clone_cable14::NumClones is automated
		;                                   // clone_cable14::Value is automated
		clone_cable14.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable13::NumClones is automated
		;                                   // clone_cable13::Value is automated
		clone_cable13.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable10::NumClones is automated
		;                                   // clone_cable10::Value is automated
		clone_cable10.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                            // clone1::NumClones is automated
		clone1.setParameterT(1, 1.); // container::clone::SplitSignal
		
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
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		gain.setParameterT(0, -6.8); // core::gain::Gain
		gain.setParameterT(1, 0.);   // core::gain::Smoothing
		gain.setParameterT(2, -22.); // core::gain::ResetValue
		
		this->setParameterT(0, 9.);
		this->setParameterT(1, 4.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.0161133);
		this->setParameterT(7, 0.0392578);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 16.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 0.);
		this->setParameterT(14, -0.011);
		this->setParameterT(15, 14.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 0.958179);
		this->setParameterT(19, 0.);
		this->setParameterT(20, 0.);
		this->setParameterT(21, 0.);
		this->setParameterT(22, 1.);
		this->setParameterT(23, -0.0785156);
		this->setParameterT(24, 0.);
		this->setParameterT(25, 0.);
		this->setParameterT(26, 0.);
		this->setParameterT(27, 0.);
		this->setParameterT(28, -0.107813);
		this->setParameterT(29, 0.726647);
		this->setParameterT(30, -1.);
		this->setParameterT(31, 13.);
		this->setParameterT(32, 0.);
		this->setParameterT(33, 2.);
		this->setParameterT(34, -0.256284);
		this->setParameterT(35, 0.58418);
		this->setParameterT(36, 1.);
		this->setParameterT(37, 0.);
		this->setParameterT(38, 0.);
		this->setParameterT(39, 0.);
		this->setParameterT(40, 0.);
		this->setParameterT(41, 1.);
		this->setParameterT(42, 0.);
		this->setParameterT(43, 1.);
		this->setParameterT(44, 0.);
		this->setParameterT(45, 0.);
		this->setParameterT(46, 1.);
		this->setParameterT(47, 1.);
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
		
		this->getT(0).getT(0).getT(0).getT(1).  // Xarrange_impl::global_cable_t<NV>
        getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(1).  // Xarrange_impl::global_cable11_t<NV>
        getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(1).  // Xarrange_impl::global_cable12_t<NV>
        getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(1).  // Xarrange_impl::global_cable13_t<NV>
        getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).  // Xarrange_impl::global_cable7_t<NV>
        getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).  // Xarrange_impl::global_cable32_t<NV>
        getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).  // Xarrange_impl::global_cable33_t<NV>
        getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).  // Xarrange_impl::global_cable34_t<NV>
        getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(1).  // Xarrange_impl::global_cable6_t<NV>
        getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(1).  // Xarrange_impl::global_cable29_t<NV>
        getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(1).  // Xarrange_impl::global_cable30_t<NV>
        getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(1).  // Xarrange_impl::global_cable31_t<NV>
        getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(1).  // Xarrange_impl::global_cable5_t<NV>
        getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(1).  // Xarrange_impl::global_cable26_t<NV>
        getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(1).  // Xarrange_impl::global_cable27_t<NV>
        getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(1).  // Xarrange_impl::global_cable28_t<NV>
        getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(1).  // Xarrange_impl::global_cable4_t<NV>
        getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(1).  // Xarrange_impl::global_cable23_t<NV>
        getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(1).  // Xarrange_impl::global_cable24_t<NV>
        getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(1).  // Xarrange_impl::global_cable25_t<NV>
        getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(5).getT(1).  // Xarrange_impl::global_cable3_t<NV>
        getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(5).getT(1).  // Xarrange_impl::global_cable20_t<NV>
        getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(5).getT(1).  // Xarrange_impl::global_cable21_t<NV>
        getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(5).getT(1).  // Xarrange_impl::global_cable22_t<NV>
        getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).setExternalData(b, index); // Xarrange_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(1).setExternalData(b, index); // Xarrange_impl::peak7_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1).setExternalData(b, index); // Xarrange_impl::peak6_t<NV>
		this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(1).setExternalData(b, index); // Xarrange_impl::peak5_t<NV>
		this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(1).setExternalData(b, index); // Xarrange_impl::peak4_t<NV>
		this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(1).setExternalData(b, index); // Xarrange_impl::peak3_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);                 // Xarrange_impl::pack_resizer_t
		this->getT(0).getT(1).getT(0).getT(1).setExternalData(b, index);                 // Xarrange_impl::pack_resizer1_t
		this->getT(0).getT(1).getT(0).getT(2).setExternalData(b, index);                 // Xarrange_impl::pack_resizer2_t
		this->getT(0).getT(1).getT(1).getT(0).getT(0).setExternalData(b, index);         // Xarrange_impl::clone_pack_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(0).setExternalData(b, index);         // Xarrange_impl::clone_pack2_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(0).setExternalData(b, index);         // Xarrange_impl::clone_pack1_t<NV>
		this->getT(1).getT(0).setExternalData(b, index);                                 // Xarrange_impl::xnode1_t<NV>
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
using Xarrange = wrap::node<Xarrange_impl::instance<NV>>;
}


