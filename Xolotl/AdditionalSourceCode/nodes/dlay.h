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

namespace dlay_impl
{
// ==============================| Node & Parameter type declarations |==============================

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
using xfader_t = control::xfader<xfader_multimod<NV>, faders::overlap>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;
using global_cable_t_index = runtime_target::indexers::fix_hash<3357039>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable_t<NV>>, 
                                   math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<3357040>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<3357041>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable2_t<NV>>, 
                                   math::add<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<3357042>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable1_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch28_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain47_t<NV>>, 
                                     chain50_t<NV>, 
                                     chain49_t<NV>, 
                                     chain48_t<NV>>;

template <int NV>
using smoothed_parameter_unscaled7_t = wrap::mod<parameter::plain<jdsp::jdelay_thiran<NV>, 1>, 
                                                 control::smoothed_parameter_unscaled<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter_unscaled9_t = smoothed_parameter_unscaled7_t<NV>;

template <int NV>
using tempo_sync3_mod = parameter::chain<ranges::Identity, 
                                         parameter::plain<core::fix_delay, 0>, 
                                         parameter::plain<project::RevDel<NV>, 0>, 
                                         parameter::plain<project::granular<NV>, 4>, 
                                         parameter::plain<smoothed_parameter_unscaled7_t<NV>, 0>, 
                                         parameter::plain<smoothed_parameter_unscaled9_t<NV>, 0>>;

template <int NV>
using tempo_sync3_t = wrap::mod<tempo_sync3_mod<NV>, 
                                control::tempo_sync<NV>>;

template <int NV>
using minmax_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<project::klp2<NV>, 0>, 
                                    parameter::plain<project::klp2<NV>, 0>, 
                                    parameter::plain<project::klp2<NV>, 0>, 
                                    parameter::plain<project::klp2<NV>, 0>, 
                                    parameter::plain<project::klp2<NV>, 0>, 
                                    parameter::plain<project::klp2<NV>, 0>>;

template <int NV>
using minmax_t = control::minmax<NV, minmax_mod<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(smoothed_parameter_mod_0Range, 
                             0., 
                             1000., 
                             0.30103);

using smoothed_parameter_mod_0 = parameter::from0To1<wrap::no_process<core::fix_delay>, 
                                                     0, 
                                                     smoothed_parameter_mod_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(smoothed_parameter_mod_1Range, 
                             0., 
                             1000., 
                             0.30103);

template <int NV>
using smoothed_parameter_mod_1 = parameter::from0To1<jdsp::jdelay_thiran<NV>, 
                                                     1, 
                                                     smoothed_parameter_mod_1Range>;

template <int NV>
using smoothed_parameter_mod = parameter::chain<ranges::Identity, 
                                                smoothed_parameter_mod_0, 
                                                smoothed_parameter_mod_1<NV>>;

template <int NV>
using smoothed_parameter_t = wrap::mod<smoothed_parameter_mod<NV>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
DECLARE_PARAMETER_RANGE_STEP(pma_mod_0Range, 
                             0., 
                             2000., 
                             0.1);

template <int NV>
using pma_mod_0 = parameter::from0To1<tempo_sync3_t<NV>, 
                                      3, 
                                      pma_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma_mod_1Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma_mod_1 = parameter::from0To1<tempo_sync3_t<NV>, 
                                      0, 
                                      pma_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(pma_mod_3Range, 
                             5., 
                             16., 
                             1.);

template <int NV>
using pma_mod_3 = parameter::from0To1<project::klp2<NV>, 
                                      0, 
                                      pma_mod_3Range>;

template <int NV> using pma_mod_4 = pma_mod_3<NV>;

template <int NV> using pma_mod_5 = pma_mod_3<NV>;

template <int NV> using pma_mod_6 = pma_mod_3<NV>;

template <int NV> using pma_mod_7 = pma_mod_3<NV>;

template <int NV> using pma_mod_8 = pma_mod_3<NV>;

template <int NV> using pma_mod_10 = pma_mod_3<NV>;

template <int NV> using pma_mod_11 = pma_mod_3<NV>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 pma_mod_0<NV>, 
                                 pma_mod_1<NV>, 
                                 parameter::plain<minmax_t<NV>, 0>, 
                                 pma_mod_3<NV>, 
                                 pma_mod_4<NV>, 
                                 pma_mod_5<NV>, 
                                 pma_mod_6<NV>, 
                                 pma_mod_7<NV>, 
                                 pma_mod_8<NV>, 
                                 parameter::plain<smoothed_parameter_t<NV>, 0>, 
                                 pma_mod_10<NV>, 
                                 pma_mod_11<NV>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;

template <int NV>
using smoothed_parameter_unscaled10_t = smoothed_parameter_unscaled7_t<NV>;

template <int NV>
using smoothed_parameter_unscaled11_t = smoothed_parameter_unscaled7_t<NV>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<smoothed_parameter_unscaled10_t<NV>, 0>, 
                                        parameter::plain<smoothed_parameter_unscaled11_t<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;

template <int NV>
using minmax2_mod = parameter::chain<ranges::Identity, 
                                     parameter::plain<project::klp2<NV>, 0>, 
                                     parameter::plain<project::klp2<NV>, 0>>;

template <int NV>
using minmax2_t = control::minmax<NV, minmax2_mod<NV>>;
template <int NV>
using pma1_mod_0 = parameter::from0To1<tempo_sync_t<NV>, 
                                       0, 
                                       pma_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(pma1_mod_2Range, 
                             0., 
                             1000., 
                             0.1);

template <int NV>
using pma1_mod_2 = parameter::from0To1<tempo_sync_t<NV>, 
                                       3, 
                                       pma1_mod_2Range>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  pma1_mod_0<NV>, 
                                  parameter::plain<minmax2_t<NV>, 0>, 
                                  pma1_mod_2<NV>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;

template <int NV>
using peak1_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma_t<NV>, 0>, 
                                   parameter::plain<pma1_t<NV>, 0>>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch28_t<NV>>, 
                                   peak1_t<NV>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma_t<NV>>, 
                                   minmax_t<NV>, 
                                   tempo_sync3_t<NV>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma1_t<NV>>, 
                                   minmax2_t<NV>, 
                                   tempo_sync_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain34_t<NV>>, 
                                  chain35_t<NV>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain51_t<NV>>, 
                                      split3_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;
using stereo_cable = cable::block<2>;

using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, project::klp2<NV>>>;

template <int NV> using chain1_t = chain_t<NV>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain_t<NV>>, 
                                   chain1_t<NV>>;
using comp_t = wrap::no_data<dynamics::comp>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, branch_t<NV>>, 
                                  comp_t, 
                                  routing::send<stereo_cable>, 
                                  core::gain<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain4_t>, 
                                    chain5_t<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::fix_delay>, 
                                  filters::svf<NV>, 
                                  branch1_t<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, routing::receive<stereo_cable>>, 
                                  chain6_t<NV>>;

using chain19_t = chain4_t;

template <int NV> using chain20_t = chain_t<NV>;

template <int NV> using chain21_t = chain_t<NV>;
template <int NV>
using branch8_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain20_t<NV>>, 
                                    chain21_t<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain19_t>, 
                                    branch8_t<NV>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   smoothed_parameter_unscaled7_t<NV>, 
                                   jdsp::jdelay_thiran<NV>, 
                                   filters::one_pole<NV>, 
                                   branch7_t<NV>, 
                                   routing::send<stereo_cable>, 
                                   jdsp::jpanner<NV>>;

using chain25_t = chain4_t;

template <int NV> using chain26_t = chain_t<NV>;

template <int NV> using chain27_t = chain_t<NV>;
template <int NV>
using branch11_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain26_t<NV>>, 
                                     chain27_t<NV>>;
template <int NV>
using branch10_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain25_t>, 
                                     branch11_t<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   smoothed_parameter_unscaled10_t<NV>, 
                                   jdsp::jdelay_thiran<NV>, 
                                   filters::one_pole<NV>, 
                                   branch10_t<NV>, 
                                   routing::send<stereo_cable>, 
                                   jdsp::jpanner<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain22_t<NV>>, 
                                  chain15_t<NV>>;

using chain31_t = chain4_t;

template <int NV> using chain32_t = chain_t<NV>;

template <int NV> using chain33_t = chain_t<NV>;
template <int NV>
using branch15_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain32_t<NV>>, 
                                     chain33_t<NV>>;
template <int NV>
using branch14_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain31_t>, 
                                     branch15_t<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   smoothed_parameter_unscaled9_t<NV>, 
                                   jdsp::jdelay_thiran<NV>, 
                                   filters::one_pole<NV>, 
                                   branch14_t<NV>, 
                                   routing::send<stereo_cable>, 
                                   jdsp::jpanner<NV>>;

using chain28_t = chain4_t;

template <int NV> using chain29_t = chain_t<NV>;

template <int NV> using chain30_t = chain_t<NV>;
template <int NV>
using branch13_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain29_t<NV>>, 
                                     chain30_t<NV>>;
template <int NV>
using branch12_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain28_t>, 
                                     branch13_t<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   smoothed_parameter_unscaled11_t<NV>, 
                                   jdsp::jdelay_thiran<NV>, 
                                   filters::one_pole<NV>, 
                                   branch12_t<NV>, 
                                   routing::send<stereo_cable>, 
                                   jdsp::jpanner<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain23_t<NV>>, 
                                  chain24_t<NV>>;
template <int NV>
using branch9_t = container::branch<parameter::empty, 
                                    wrap::fix<2, split1_t<NV>>, 
                                    split2_t<NV>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch9_t<NV>>>;

template <int NV>
using dynamic_blocksize1_t_ = container::chain<parameter::empty, 
                                               wrap::fix<2, chain13_t<NV>>>;

template <int NV>
using dynamic_blocksize1_t = wrap::dynamic_blocksize<dynamic_blocksize1_t_<NV>>;

template <int NV>
using dynamic_blocksize_t_ = container::chain<parameter::empty, 
                                              wrap::fix<2, smoothed_parameter_t<NV>>, 
                                              routing::receive<stereo_cable>, 
                                              jdsp::jdelay_thiran<NV>, 
                                              wrap::no_process<core::fix_delay>, 
                                              filters::one_pole<NV>, 
                                              routing::send<stereo_cable>>;

template <int NV>
using dynamic_blocksize_t = wrap::dynamic_blocksize<dynamic_blocksize_t_<NV>>;

using chain37_t = chain4_t;

template <int NV> using chain39_t = chain_t<NV>;

template <int NV> using chain40_t = chain_t<NV>;
template <int NV>
using branch17_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain39_t<NV>>, 
                                     chain40_t<NV>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch17_t<NV>>, 
                                   core::gain<NV>>;
template <int NV>
using branch16_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain37_t>, 
                                     chain38_t<NV>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<2, dynamic_blocksize_t<NV>>, 
                                   branch16_t<NV>>;

template <int NV>
using minmax1_t = control::minmax<NV, 
                                  parameter::plain<project::RevDel<NV>, 1>>;

using chain7_t = chain4_t;

template <int NV> using chain11_t = chain_t<NV>;

template <int NV> using chain12_t = chain_t<NV>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain11_t<NV>>, 
                                    chain12_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch4_t<NV>>, 
                                   core::gain<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain7_t>, 
                                    chain10_t<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax1_t<NV>>, 
                                  project::RevDel<NV>, 
                                  filters::one_pole<NV>, 
                                  branch2_t<NV>>;

using chain16_t = chain4_t;

template <int NV> using chain41_t = chain_t<NV>;

template <int NV> using chain42_t = chain_t<NV>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain41_t<NV>>, 
                                    chain42_t<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain16_t>, 
                                    branch6_t<NV>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, project::granular<NV>>, 
                                   filters::one_pole<NV>, 
                                   branch5_t<NV>>;

template <int NV>
using smoothed_parameter_unscaled_t = wrap::mod<parameter::plain<core::fix_delay, 0>, 
                                                control::smoothed_parameter_unscaled<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<smoothed_parameter_unscaled_t<NV>, 0>, 
                                control::tempo_sync<NV>>;
template <int NV>
using pma17_mod = parameter::from0To1<tempo_sync2_t<NV>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma17_t = control::pma<NV, pma17_mod<NV>>;
DECLARE_PARAMETER_RANGE(pma18_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using pma18_mod = parameter::from0To1<pma17_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma18_t = control::pma<NV, pma18_mod<NV>>;

template <int NV>
using tempo_sync9_t = wrap::mod<parameter::plain<fx::sampleandhold<NV>, 0>, 
                                control::tempo_sync<NV>>;
template <int NV>
using sliderbank_c0_0 = parameter::from0To1<pma18_t<NV>, 
                                            2, 
                                            pma18_modRange>;

template <int NV>
using sliderbank_c0_1 = parameter::from0To1<tempo_sync9_t<NV>, 
                                            0, 
                                            pma_mod_1Range>;

template <int NV>
using sliderbank_c0 = parameter::chain<ranges::Identity, 
                                       sliderbank_c0_0<NV>, 
                                       sliderbank_c0_1<NV>>;

template <int NV>
using smoothed_parameter_unscaled1_t = smoothed_parameter_unscaled_t<NV>;
template <int NV>
using tempo_sync25_t = wrap::mod<parameter::plain<smoothed_parameter_unscaled1_t<NV>, 0>, 
                                 control::tempo_sync<NV>>;
template <int NV>
using pma56_mod = parameter::from0To1<tempo_sync25_t<NV>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma56_t = control::pma<NV, pma56_mod<NV>>;
template <int NV>
using pma57_mod = parameter::from0To1<pma56_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma57_t = control::pma<NV, pma57_mod<NV>>;

template <int NV> using tempo_sync24_t = tempo_sync9_t<NV>;
template <int NV>
using sliderbank_c1_0 = parameter::from0To1<pma57_t<NV>, 
                                            2, 
                                            pma18_modRange>;

template <int NV>
using sliderbank_c1_1 = parameter::from0To1<tempo_sync24_t<NV>, 
                                            0, 
                                            pma_mod_1Range>;

template <int NV>
using sliderbank_c1 = parameter::chain<ranges::Identity, 
                                       sliderbank_c1_0<NV>, 
                                       sliderbank_c1_1<NV>>;

template <int NV>
using smoothed_parameter_unscaled6_t = smoothed_parameter_unscaled_t<NV>;
template <int NV>
using tempo_sync23_t = wrap::mod<parameter::plain<smoothed_parameter_unscaled6_t<NV>, 0>, 
                                 control::tempo_sync<NV>>;
template <int NV>
using pma51_mod = parameter::from0To1<tempo_sync23_t<NV>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma51_t = control::pma<NV, pma51_mod<NV>>;
template <int NV>
using pma52_mod = parameter::from0To1<pma51_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma52_t = control::pma<NV, pma52_mod<NV>>;

template <int NV> using tempo_sync22_t = tempo_sync9_t<NV>;
template <int NV>
using sliderbank_c2_0 = parameter::from0To1<pma52_t<NV>, 
                                            2, 
                                            pma18_modRange>;

template <int NV>
using sliderbank_c2_1 = parameter::from0To1<tempo_sync22_t<NV>, 
                                            0, 
                                            pma_mod_1Range>;

template <int NV>
using sliderbank_c2 = parameter::chain<ranges::Identity, 
                                       sliderbank_c2_0<NV>, 
                                       sliderbank_c2_1<NV>>;

template <int NV>
using smoothed_parameter_unscaled5_t = smoothed_parameter_unscaled_t<NV>;
template <int NV>
using tempo_sync21_t = wrap::mod<parameter::plain<smoothed_parameter_unscaled5_t<NV>, 0>, 
                                 control::tempo_sync<NV>>;
template <int NV>
using pma46_mod = parameter::from0To1<tempo_sync21_t<NV>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma46_t = control::pma<NV, pma46_mod<NV>>;
template <int NV>
using pma47_mod = parameter::from0To1<pma46_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma47_t = control::pma<NV, pma47_mod<NV>>;

template <int NV> using tempo_sync20_t = tempo_sync9_t<NV>;
template <int NV>
using sliderbank_c3_0 = parameter::from0To1<pma47_t<NV>, 
                                            2, 
                                            pma18_modRange>;

template <int NV>
using sliderbank_c3_1 = parameter::from0To1<tempo_sync20_t<NV>, 
                                            0, 
                                            pma_mod_1Range>;

template <int NV>
using sliderbank_c3 = parameter::chain<ranges::Identity, 
                                       sliderbank_c3_0<NV>, 
                                       sliderbank_c3_1<NV>>;

template <int NV> using tempo_sync18_t = tempo_sync9_t<NV>;

template <int NV>
using smoothed_parameter_unscaled4_t = smoothed_parameter_unscaled_t<NV>;
template <int NV>
using tempo_sync19_t = wrap::mod<parameter::plain<smoothed_parameter_unscaled4_t<NV>, 0>, 
                                 control::tempo_sync<NV>>;
template <int NV>
using pma41_mod = parameter::from0To1<tempo_sync19_t<NV>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma41_t = control::pma<NV, pma41_mod<NV>>;
template <int NV>
using pma42_mod = parameter::from0To1<pma41_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma42_t = control::pma<NV, pma42_mod<NV>>;
template <int NV>
using sliderbank_c4_0 = parameter::from0To1<tempo_sync18_t<NV>, 
                                            0, 
                                            pma_mod_1Range>;

template <int NV>
using sliderbank_c4_1 = parameter::from0To1<pma42_t<NV>, 
                                            2, 
                                            pma18_modRange>;

template <int NV>
using sliderbank_c4 = parameter::chain<ranges::Identity, 
                                       sliderbank_c4_0<NV>, 
                                       sliderbank_c4_1<NV>>;

template <int NV>
using smoothed_parameter_unscaled3_t = smoothed_parameter_unscaled_t<NV>;
template <int NV>
using tempo_sync17_t = wrap::mod<parameter::plain<smoothed_parameter_unscaled3_t<NV>, 0>, 
                                 control::tempo_sync<NV>>;
template <int NV>
using pma36_mod = parameter::from0To1<tempo_sync17_t<NV>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma36_t = control::pma<NV, pma36_mod<NV>>;
template <int NV>
using pma37_mod = parameter::from0To1<pma36_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma37_t = control::pma<NV, pma37_mod<NV>>;

template <int NV> using tempo_sync16_t = tempo_sync9_t<NV>;
template <int NV>
using sliderbank_c5_0 = parameter::from0To1<pma37_t<NV>, 
                                            2, 
                                            pma18_modRange>;

template <int NV>
using sliderbank_c5_1 = parameter::from0To1<tempo_sync16_t<NV>, 
                                            0, 
                                            pma_mod_1Range>;

template <int NV>
using sliderbank_c5 = parameter::chain<ranges::Identity, 
                                       sliderbank_c5_0<NV>, 
                                       sliderbank_c5_1<NV>>;

template <int NV> using tempo_sync14_t = tempo_sync9_t<NV>;

using smoothed_parameter1_mod = parameter::from0To1<core::fix_delay, 
                                                    0, 
                                                    smoothed_parameter_mod_0Range>;

template <int NV>
using smoothed_parameter1_t = wrap::mod<smoothed_parameter1_mod, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using tempo_sync15_t = wrap::mod<parameter::plain<smoothed_parameter1_t<NV>, 0>, 
                                 control::tempo_sync<NV>>;
template <int NV>
using pma31_mod = parameter::from0To1<tempo_sync15_t<NV>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma31_t = control::pma<NV, pma31_mod<NV>>;
template <int NV>
using pma32_mod = parameter::from0To1<pma31_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma32_t = control::pma<NV, pma32_mod<NV>>;
template <int NV>
using sliderbank_c6_0 = parameter::from0To1<tempo_sync14_t<NV>, 
                                            0, 
                                            pma_mod_1Range>;

template <int NV>
using sliderbank_c6_1 = parameter::from0To1<pma32_t<NV>, 
                                            2, 
                                            pma18_modRange>;

template <int NV>
using sliderbank_c6 = parameter::chain<ranges::Identity, 
                                       sliderbank_c6_0<NV>, 
                                       sliderbank_c6_1<NV>>;

template <int NV> using tempo_sync12_t = tempo_sync9_t<NV>;

template <int NV>
using smoothed_parameter_unscaled2_t = smoothed_parameter_unscaled_t<NV>;
template <int NV>
using tempo_sync13_t = wrap::mod<parameter::plain<smoothed_parameter_unscaled2_t<NV>, 0>, 
                                 control::tempo_sync<NV>>;
template <int NV>
using pma26_mod = parameter::from0To1<tempo_sync13_t<NV>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma26_t = control::pma<NV, pma26_mod<NV>>;
template <int NV>
using pma27_mod = parameter::from0To1<pma26_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma27_t = control::pma<NV, pma27_mod<NV>>;
template <int NV>
using sliderbank_c7_0 = parameter::from0To1<tempo_sync12_t<NV>, 
                                            0, 
                                            pma_mod_1Range>;

template <int NV>
using sliderbank_c7_1 = parameter::from0To1<pma27_t<NV>, 
                                            2, 
                                            pma18_modRange>;

template <int NV>
using sliderbank_c7 = parameter::chain<ranges::Identity, 
                                       sliderbank_c7_0<NV>, 
                                       sliderbank_c7_1<NV>>;

template <int NV>
using sliderbank_multimod = parameter::list<sliderbank_c0<NV>, 
                                            sliderbank_c1<NV>, 
                                            sliderbank_c2<NV>, 
                                            sliderbank_c3<NV>, 
                                            sliderbank_c4<NV>, 
                                            sliderbank_c5<NV>, 
                                            sliderbank_c6<NV>, 
                                            sliderbank_c7<NV>>;

template <int NV>
using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod<NV>>, 
                                data::external::sliderpack<0>>;

DECLARE_PARAMETER_RANGE_SKEW(pma19_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma19_mod = parameter::from0To1<filters::svf<NV>, 
                                      0, 
                                      pma19_modRange>;

template <int NV>
using pma19_t = control::pma<NV, pma19_mod<NV>>;
template <int NV>
using pma20_mod = parameter::from0To1<pma19_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma20_t = control::pma<NV, pma20_mod<NV>>;
template <int NV>
using sliderbank1_c0 = parameter::from0To1<pma20_t<NV>, 
                                           2, 
                                           pma18_modRange>;

template <int NV> using pma59_mod = pma19_mod<NV>;

template <int NV>
using pma59_t = control::pma<NV, pma59_mod<NV>>;
template <int NV>
using pma60_mod = parameter::from0To1<pma59_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma60_t = control::pma<NV, pma60_mod<NV>>;
template <int NV>
using sliderbank1_c1 = parameter::from0To1<pma60_t<NV>, 
                                           2, 
                                           pma18_modRange>;

template <int NV> using pma54_mod = pma19_mod<NV>;

template <int NV>
using pma54_t = control::pma<NV, pma54_mod<NV>>;
template <int NV>
using pma55_mod = parameter::from0To1<pma54_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma55_t = control::pma<NV, pma55_mod<NV>>;
template <int NV>
using sliderbank1_c2 = parameter::from0To1<pma55_t<NV>, 
                                           2, 
                                           pma18_modRange>;

template <int NV> using pma49_mod = pma19_mod<NV>;

template <int NV>
using pma49_t = control::pma<NV, pma49_mod<NV>>;
template <int NV>
using pma50_mod = parameter::from0To1<pma49_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma50_t = control::pma<NV, pma50_mod<NV>>;
template <int NV>
using sliderbank1_c3 = parameter::from0To1<pma50_t<NV>, 
                                           2, 
                                           pma18_modRange>;

template <int NV> using pma44_mod = pma19_mod<NV>;

template <int NV>
using pma44_t = control::pma<NV, pma44_mod<NV>>;
template <int NV>
using pma45_mod = parameter::from0To1<pma44_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma45_t = control::pma<NV, pma45_mod<NV>>;
template <int NV>
using sliderbank1_c4 = parameter::from0To1<pma45_t<NV>, 
                                           2, 
                                           pma18_modRange>;

template <int NV> using pma39_mod = pma19_mod<NV>;

template <int NV>
using pma39_t = control::pma<NV, pma39_mod<NV>>;
template <int NV>
using pma40_mod = parameter::from0To1<pma39_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma40_t = control::pma<NV, pma40_mod<NV>>;
template <int NV>
using sliderbank1_c5 = parameter::from0To1<pma40_t<NV>, 
                                           2, 
                                           pma18_modRange>;

template <int NV> using pma34_mod = pma19_mod<NV>;

template <int NV>
using pma34_t = control::pma<NV, pma34_mod<NV>>;
template <int NV>
using pma35_mod = parameter::from0To1<pma34_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma35_t = control::pma<NV, pma35_mod<NV>>;
template <int NV>
using sliderbank1_c6 = parameter::from0To1<pma35_t<NV>, 
                                           2, 
                                           pma18_modRange>;

template <int NV> using pma29_mod = pma19_mod<NV>;

template <int NV>
using pma29_t = control::pma<NV, pma29_mod<NV>>;
template <int NV>
using pma30_mod = parameter::from0To1<pma29_t<NV>, 
                                      2, 
                                      pma18_modRange>;

template <int NV>
using pma30_t = control::pma<NV, pma30_mod<NV>>;
template <int NV>
using sliderbank1_c7 = parameter::from0To1<pma30_t<NV>, 
                                           2, 
                                           pma18_modRange>;

template <int NV>
using sliderbank1_multimod = parameter::list<sliderbank1_c0<NV>, 
                                             sliderbank1_c1<NV>, 
                                             sliderbank1_c2<NV>, 
                                             sliderbank1_c3<NV>, 
                                             sliderbank1_c4<NV>, 
                                             sliderbank1_c5<NV>, 
                                             sliderbank1_c6<NV>, 
                                             sliderbank1_c7<NV>>;

template <int NV>
using sliderbank1_t = wrap::data<control::sliderbank<sliderbank1_multimod<NV>>, 
                                 data::external::sliderpack<1>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, sliderbank_t<NV>>, 
                                     sliderbank1_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

using chain58_t = chain4_t;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<math::clear<NV>>>>;
template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<math::clear<NV>>>, 
                                   oscillator_t<NV>>;
template <int NV>
using branch18_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain60_t<NV>>, 
                                     chain61_t<NV>>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<pma17_t<NV>, 0>, 
                                  parameter::plain<pma19_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync9_t<NV>>, 
                                   branch18_t<NV>, 
                                   fx::sampleandhold<NV>, 
                                   peak_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain58_t>, 
                                  chain59_t<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, pma17_t<NV>>, 
                                  pma18_t<NV>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split8_t<NV>>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(cable_table_modRange, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using cable_table_mod = parameter::from0To1<filters::svf<NV>, 
                                            1, 
                                            cable_table_modRange>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::embedded::table<cable_table_t_data>>;

using comp1_t = comp_t;
using cable_table1_mod = parameter::from0To1<comp1_t, 
                                             0, 
                                             xfader_c0Range>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998659f, 0.997317f, 0.995976f, 0.994635f, 0.993294f,
		0.991952f, 0.990611f, 0.98927f, 0.987929f, 0.986587f, 0.985246f,
		0.983905f, 0.982563f, 0.981222f, 0.979881f, 0.97854f, 0.977198f,
		0.975857f, 0.974516f, 0.973174f, 0.971833f, 0.970492f, 0.969151f,
		0.967809f, 0.966468f, 0.965127f, 0.963785f, 0.962444f, 0.961103f,
		0.959762f, 0.95842f, 0.957079f, 0.955738f, 0.954397f, 0.953055f,
		0.951714f, 0.950373f, 0.949031f, 0.94769f, 0.946349f, 0.945008f,
		0.943666f, 0.942325f, 0.940984f, 0.939642f, 0.938301f, 0.93696f,
		0.935619f, 0.934277f, 0.932936f, 0.931595f, 0.930254f, 0.928912f,
		0.927571f, 0.92623f, 0.924888f, 0.923547f, 0.922206f, 0.920865f,
		0.919523f, 0.918182f, 0.916841f, 0.915499f, 0.914158f, 0.912817f,
		0.911476f, 0.910134f, 0.908793f, 0.907452f, 0.906111f, 0.904769f,
		0.903428f, 0.902087f, 0.900745f, 0.899404f, 0.898063f, 0.896722f,
		0.89538f, 0.894039f, 0.892698f, 0.891356f, 0.890015f, 0.888674f,
		0.887333f, 0.885991f, 0.88465f, 0.883309f, 0.881967f, 0.880626f,
		0.879285f, 0.877944f, 0.876602f, 0.875261f, 0.87392f, 0.872579f,
		0.871237f, 0.869896f, 0.868555f, 0.867213f, 0.865872f, 0.864531f,
		0.86319f, 0.861848f, 0.860507f, 0.859166f, 0.857825f, 0.856483f,
		0.855142f, 0.853801f, 0.852459f, 0.851118f, 0.849777f, 0.848436f,
		0.847094f, 0.845753f, 0.844412f, 0.84307f, 0.841729f, 0.840388f,
		0.839047f, 0.837705f, 0.836364f, 0.835023f, 0.833681f, 0.83234f,
		0.830999f, 0.829658f, 0.828316f, 0.826975f, 0.825634f, 0.824293f,
		0.822951f, 0.82161f, 0.820269f, 0.818927f, 0.817586f, 0.816245f,
		0.814904f, 0.813562f, 0.812221f, 0.81088f, 0.809538f, 0.808197f,
		0.806856f, 0.805515f, 0.804173f, 0.802832f, 0.801491f, 0.80015f,
		0.798808f, 0.797467f, 0.796126f, 0.794784f, 0.793443f, 0.792102f,
		0.790761f, 0.789419f, 0.788078f, 0.786737f, 0.785395f, 0.784054f,
		0.782713f, 0.781372f, 0.78003f, 0.778689f, 0.777348f, 0.776007f,
		0.774665f, 0.773324f, 0.771983f, 0.770641f, 0.7693f, 0.767959f,
		0.766618f, 0.765276f, 0.763935f, 0.762594f, 0.761252f, 0.759911f,
		0.75857f, 0.757229f, 0.755887f, 0.754546f, 0.753205f, 0.751863f,
		0.750522f, 0.749181f, 0.74784f, 0.746498f, 0.745157f, 0.743816f,
		0.742475f, 0.741133f, 0.739792f, 0.738451f, 0.737109f, 0.735768f,
		0.734427f, 0.733086f, 0.731744f, 0.730403f, 0.729062f, 0.72772f,
		0.726379f, 0.725038f, 0.723697f, 0.722355f, 0.721014f, 0.719673f,
		0.718332f, 0.71699f, 0.715649f, 0.714308f, 0.712966f, 0.711625f,
		0.710284f, 0.708943f, 0.707601f, 0.70626f, 0.704919f, 0.703578f,
		0.702236f, 0.700895f, 0.699554f, 0.698212f, 0.696871f, 0.69553f,
		0.694189f, 0.692847f, 0.691506f, 0.690165f, 0.688823f, 0.687482f,
		0.686141f, 0.6848f, 0.683458f, 0.682117f, 0.680776f, 0.679434f,
		0.678093f, 0.676752f, 0.675411f, 0.674069f, 0.672728f, 0.671387f,
		0.670045f, 0.668704f, 0.667363f, 0.666022f, 0.66468f, 0.663339f,
		0.661998f, 0.660657f, 0.659315f, 0.657974f, 0.656633f, 0.655291f,
		0.65395f, 0.652609f, 0.651268f, 0.649926f, 0.648585f, 0.647244f,
		0.645903f, 0.644561f, 0.64322f, 0.641879f, 0.640537f, 0.639196f,
		0.637855f, 0.636514f, 0.635172f, 0.633831f, 0.63249f, 0.631148f,
		0.629807f, 0.628466f, 0.627125f, 0.625783f, 0.624442f, 0.623101f,
		0.62176f, 0.620418f, 0.619077f, 0.617736f, 0.616394f, 0.615053f,
		0.613712f, 0.612371f, 0.611029f, 0.609688f, 0.608347f, 0.607005f,
		0.605664f, 0.604323f, 0.602982f, 0.60164f, 0.600299f, 0.598958f,
		0.597616f, 0.596275f, 0.594934f, 0.593593f, 0.592251f, 0.59091f,
		0.589569f, 0.588228f, 0.586886f, 0.585545f, 0.584204f, 0.582862f,
		0.581521f, 0.58018f, 0.578839f, 0.577497f, 0.576156f, 0.574815f,
		0.573473f, 0.572132f, 0.570791f, 0.56945f, 0.568108f, 0.566767f,
		0.565426f, 0.564085f, 0.562743f, 0.561402f, 0.560061f, 0.558719f,
		0.557378f, 0.556037f, 0.554696f, 0.553354f, 0.552013f, 0.550672f,
		0.54933f, 0.547989f, 0.546648f, 0.545307f, 0.543965f, 0.542624f,
		0.541283f, 0.539941f, 0.5386f, 0.537259f, 0.535918f, 0.534576f,
		0.533235f, 0.531894f, 0.530553f, 0.529211f, 0.52787f, 0.526529f,
		0.525187f, 0.523846f, 0.522505f, 0.521164f, 0.519822f, 0.518481f,
		0.51714f, 0.515799f, 0.514457f, 0.513116f, 0.511775f, 0.510433f,
		0.509092f, 0.507751f, 0.50641f, 0.505068f, 0.503727f, 0.502386f,
		0.501044f, 0.499703f, 0.498362f, 0.497021f, 0.495679f, 0.494338f,
		0.492997f, 0.491655f, 0.490314f, 0.488973f, 0.487632f, 0.48629f,
		0.484949f, 0.483608f, 0.482267f, 0.480925f, 0.479584f, 0.478243f,
		0.476901f, 0.47556f, 0.474219f, 0.472878f, 0.471536f, 0.470195f,
		0.468854f, 0.467512f, 0.466171f, 0.46483f, 0.463489f, 0.462147f,
		0.460806f, 0.459465f, 0.458124f, 0.456782f, 0.455441f, 0.4541f,
		0.452758f, 0.451417f, 0.450076f, 0.448735f, 0.447393f, 0.446052f,
		0.444711f, 0.443369f, 0.442028f, 0.440687f, 0.439346f, 0.438004f,
		0.436663f, 0.435322f, 0.433981f, 0.432639f, 0.431298f, 0.429957f,
		0.428615f, 0.427274f, 0.425933f, 0.424591f, 0.42325f, 0.421909f,
		0.420568f, 0.419226f, 0.417885f, 0.416544f, 0.415203f, 0.413861f,
		0.41252f, 0.411179f, 0.409838f, 0.408496f, 0.407155f, 0.405814f,
		0.404472f, 0.403131f, 0.40179f, 0.400449f, 0.399107f, 0.397766f,
		0.396425f, 0.395083f, 0.393742f, 0.392401f, 0.39106f, 0.389718f,
		0.388377f, 0.387036f, 0.385695f, 0.384353f, 0.383012f, 0.381671f,
		0.380329f, 0.378988f, 0.377647f, 0.376306f, 0.374964f, 0.373623f,
		0.372282f, 0.37094f, 0.369599f, 0.368258f, 0.366917f, 0.365575f,
		0.364234f, 0.362893f, 0.361551f, 0.36021f, 0.358869f, 0.357528f,
		0.356186f, 0.354845f, 0.353504f, 0.352163f, 0.350821f, 0.34948f,
		0.348139f, 0.346797f, 0.345456f, 0.344115f, 0.342774f, 0.341432f,
		0.340091f, 0.33875f, 0.337408f, 0.336067f, 0.334726f, 0.333385f,
		0.332043f, 0.330702f, 0.329361f, 0.32802f, 0.326678f, 0.325337f,
		0.323996f, 0.322654f, 0.321313f, 0.319972f, 0.318631f, 0.317289f,
		0.315948f, 0.314607f
	};
};

using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod>, 
                                  data::embedded::table<cable_table1_t_data>>;

template <int NV>
using pma2_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table_t<NV>, 0>, 
                                  parameter::plain<cable_table1_t, 0>>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, pma19_t<NV>>, 
                                  pma20_t<NV>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split9_t<NV>>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync2_t<NV>>, 
                                   smoothed_parameter_unscaled_t<NV>, 
                                   core::fix_delay, 
                                   pma2_t<NV>, 
                                   cable_table_t<NV>, 
                                   cable_table1_t, 
                                   modchain3_t<NV>, 
                                   filters::svf<NV>, 
                                   comp1_t, 
                                   core::gain<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain43_t<NV>>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   split6_t<NV>, 
                                   modchain2_t<NV>, 
                                   split4_t<NV>, 
                                   routing::send<stereo_cable>>;

using chain105_t = chain4_t;

template <int NV> using chain107_t = chain60_t<NV>;
template <int NV> using oscillator8_t = oscillator_t<NV>;

template <int NV>
using chain108_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::clear<NV>>, 
                                    oscillator8_t<NV>, 
                                    wrap::no_process<math::clear<NV>>>;
template <int NV>
using branch26_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain107_t<NV>>, 
                                     chain108_t<NV>>;

template <int NV>
using peak8_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma56_t<NV>, 0>, 
                                   parameter::plain<pma59_t<NV>, 0>>;

template <int NV>
using peak8_t = wrap::mod<peak8_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain106_t = container::chain<parameter::empty, 
                                    wrap::fix<2, tempo_sync24_t<NV>>, 
                                    branch26_t<NV>, 
                                    fx::sampleandhold<NV>, 
                                    peak8_t<NV>, 
                                    core::gain<NV>>;

template <int NV>
using split39_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain105_t>, 
                                   chain106_t<NV>>;

template <int NV>
using split40_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma56_t<NV>>, 
                                   pma57_t<NV>>;

template <int NV>
using modchain18_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split40_t<NV>>>;

template <int NV>
using modchain18_t = wrap::control_rate<modchain18_t_<NV>>;

template <int NV> using cable_table44_mod = cable_table_mod<NV>;

struct cable_table44_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
};

template <int NV>
using cable_table44_t = wrap::data<control::cable_table<cable_table44_mod<NV>>, 
                                   data::embedded::table<cable_table44_t_data>>;

using comp23_t = comp_t;
using cable_table45_mod = parameter::from0To1<comp23_t, 
                                              0, 
                                              xfader_c0Range>;

struct cable_table45_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998769f, 0.997537f, 0.996306f, 0.995075f, 0.993843f,
		0.992612f, 0.991381f, 0.990149f, 0.988918f, 0.987687f, 0.986455f,
		0.985224f, 0.983993f, 0.982761f, 0.98153f, 0.980299f, 0.979067f,
		0.977836f, 0.976605f, 0.975373f, 0.974142f, 0.972911f, 0.971679f,
		0.970448f, 0.969217f, 0.967985f, 0.966754f, 0.965523f, 0.964291f,
		0.96306f, 0.961829f, 0.960597f, 0.959366f, 0.958135f, 0.956903f,
		0.955672f, 0.954441f, 0.953209f, 0.951978f, 0.950746f, 0.949515f,
		0.948284f, 0.947052f, 0.945821f, 0.94459f, 0.943358f, 0.942127f,
		0.940896f, 0.939664f, 0.938433f, 0.937202f, 0.93597f, 0.934739f,
		0.933508f, 0.932276f, 0.931045f, 0.929814f, 0.928582f, 0.927351f,
		0.92612f, 0.924888f, 0.923657f, 0.922426f, 0.921194f, 0.919963f,
		0.918732f, 0.9175f, 0.916269f, 0.915038f, 0.913806f, 0.912575f,
		0.911344f, 0.910112f, 0.908881f, 0.90765f, 0.906418f, 0.905187f,
		0.903956f, 0.902724f, 0.901493f, 0.900262f, 0.89903f, 0.897799f,
		0.896568f, 0.895336f, 0.894105f, 0.892874f, 0.891642f, 0.890411f,
		0.88918f, 0.887948f, 0.886717f, 0.885486f, 0.884254f, 0.883023f,
		0.881792f, 0.88056f, 0.879329f, 0.878098f, 0.876866f, 0.875635f,
		0.874404f, 0.873172f, 0.871941f, 0.87071f, 0.869478f, 0.868247f,
		0.867016f, 0.865784f, 0.864553f, 0.863322f, 0.86209f, 0.860859f,
		0.859627f, 0.858396f, 0.857165f, 0.855933f, 0.854702f, 0.853471f,
		0.852239f, 0.851008f, 0.849777f, 0.848545f, 0.847314f, 0.846083f,
		0.844851f, 0.84362f, 0.842389f, 0.841157f, 0.839926f, 0.838695f,
		0.837463f, 0.836232f, 0.835001f, 0.833769f, 0.832538f, 0.831307f,
		0.830075f, 0.828844f, 0.827613f, 0.826381f, 0.82515f, 0.823919f,
		0.822687f, 0.821456f, 0.820225f, 0.818993f, 0.817762f, 0.816531f,
		0.815299f, 0.814068f, 0.812837f, 0.811605f, 0.810374f, 0.809143f,
		0.807911f, 0.80668f, 0.805449f, 0.804217f, 0.802986f, 0.801755f,
		0.800523f, 0.799292f, 0.798061f, 0.796829f, 0.795598f, 0.794367f,
		0.793135f, 0.791904f, 0.790673f, 0.789441f, 0.78821f, 0.786979f,
		0.785747f, 0.784516f, 0.783285f, 0.782053f, 0.780822f, 0.779591f,
		0.778359f, 0.777128f, 0.775897f, 0.774665f, 0.773434f, 0.772203f,
		0.770971f, 0.76974f, 0.768509f, 0.767277f, 0.766046f, 0.764814f,
		0.763583f, 0.762352f, 0.76112f, 0.759889f, 0.758658f, 0.757427f,
		0.756195f, 0.754964f, 0.753733f, 0.752501f, 0.75127f, 0.750038f,
		0.748807f, 0.747576f, 0.746344f, 0.745113f, 0.743882f, 0.74265f,
		0.741419f, 0.740188f, 0.738956f, 0.737725f, 0.736494f, 0.735262f,
		0.734031f, 0.7328f, 0.731568f, 0.730337f, 0.729106f, 0.727874f,
		0.726643f, 0.725412f, 0.72418f, 0.722949f, 0.721718f, 0.720486f,
		0.719255f, 0.718024f, 0.716792f, 0.715561f, 0.71433f, 0.713098f,
		0.711867f, 0.710636f, 0.709404f, 0.708173f, 0.706942f, 0.70571f,
		0.704479f, 0.703248f, 0.702016f, 0.700785f, 0.699554f, 0.698322f,
		0.697091f, 0.69586f, 0.694628f, 0.693397f, 0.692166f, 0.690934f,
		0.689703f, 0.688472f, 0.68724f, 0.686009f, 0.684778f, 0.683546f,
		0.682315f, 0.681084f, 0.679852f, 0.678621f, 0.67739f, 0.676158f,
		0.674927f, 0.673696f, 0.672464f, 0.671233f, 0.670002f, 0.66877f,
		0.667539f, 0.666308f, 0.665076f, 0.663845f, 0.662614f, 0.661382f,
		0.660151f, 0.658919f, 0.657688f, 0.656457f, 0.655226f, 0.653994f,
		0.652763f, 0.651531f, 0.6503f, 0.649069f, 0.647837f, 0.646606f,
		0.645375f, 0.644143f, 0.642912f, 0.641681f, 0.640449f, 0.639218f,
		0.637987f, 0.636755f, 0.635524f, 0.634293f, 0.633061f, 0.63183f,
		0.630599f, 0.629367f, 0.628136f, 0.626905f, 0.625673f, 0.624442f,
		0.623211f, 0.621979f, 0.620748f, 0.619517f, 0.618285f, 0.617054f,
		0.615823f, 0.614591f, 0.61336f, 0.612129f, 0.610897f, 0.609666f,
		0.608435f, 0.607203f, 0.605972f, 0.604741f, 0.603509f, 0.602278f,
		0.601047f, 0.599815f, 0.598584f, 0.597353f, 0.596121f, 0.59489f,
		0.593659f, 0.592427f, 0.591196f, 0.589965f, 0.588733f, 0.587502f,
		0.586271f, 0.585039f, 0.583808f, 0.582577f, 0.581345f, 0.580114f,
		0.578883f, 0.577651f, 0.57642f, 0.575189f, 0.573957f, 0.572726f,
		0.571494f, 0.570263f, 0.569032f, 0.567801f, 0.566569f, 0.565338f,
		0.564106f, 0.562875f, 0.561644f, 0.560412f, 0.559181f, 0.55795f,
		0.556718f, 0.555487f, 0.554256f, 0.553024f, 0.551793f, 0.550562f,
		0.54933f, 0.548099f, 0.546868f, 0.545636f, 0.544405f, 0.543174f,
		0.541942f, 0.540711f, 0.53948f, 0.538248f, 0.537017f, 0.535786f,
		0.534554f, 0.533323f, 0.532092f, 0.53086f, 0.529629f, 0.528398f,
		0.527166f, 0.525935f, 0.524704f, 0.523472f, 0.522241f, 0.52101f,
		0.519778f, 0.518547f, 0.517316f, 0.516084f, 0.514853f, 0.513622f,
		0.51239f, 0.511159f, 0.509928f, 0.508696f, 0.507465f, 0.506234f,
		0.505002f, 0.503771f, 0.50254f, 0.501308f, 0.500077f, 0.498846f,
		0.497614f, 0.496383f, 0.495152f, 0.49392f, 0.492689f, 0.491458f,
		0.490226f, 0.488995f, 0.487764f, 0.486532f, 0.485301f, 0.48407f,
		0.482838f, 0.481607f, 0.480376f, 0.479144f, 0.477913f, 0.476682f,
		0.47545f, 0.474219f, 0.472988f, 0.471756f, 0.470525f, 0.469293f,
		0.468062f, 0.466831f, 0.465599f, 0.464368f, 0.463137f, 0.461905f,
		0.460674f, 0.459443f, 0.458211f, 0.45698f, 0.455749f, 0.454517f,
		0.453286f, 0.452055f, 0.450823f, 0.449592f, 0.448361f, 0.447129f,
		0.445898f, 0.444667f, 0.443435f, 0.442204f, 0.440973f, 0.439741f,
		0.43851f, 0.437279f, 0.436047f, 0.434816f, 0.433585f, 0.432353f,
		0.431122f, 0.429891f, 0.428659f, 0.427428f, 0.426197f, 0.424965f,
		0.423734f, 0.422503f, 0.421271f, 0.42004f, 0.418809f, 0.417577f,
		0.416346f, 0.415115f, 0.413883f, 0.412652f, 0.411421f, 0.410189f,
		0.408958f, 0.407727f, 0.406495f, 0.405264f, 0.404033f, 0.402801f,
		0.40157f, 0.400339f, 0.399107f, 0.397876f, 0.396645f, 0.395413f,
		0.394182f, 0.392951f, 0.391719f, 0.390488f, 0.389257f, 0.388025f,
		0.386794f, 0.385563f, 0.384331f, 0.3831f, 0.381868f, 0.380637f,
		0.379406f, 0.378175f, 0.376943f, 0.375712f, 0.374481f, 0.373249f,
		0.372018f, 0.370786f
	};
};

using cable_table45_t = wrap::data<control::cable_table<cable_table45_mod>, 
                                   data::embedded::table<cable_table45_t_data>>;

template <int NV>
using pma58_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table44_t<NV>, 0>, 
                                   parameter::plain<cable_table45_t, 0>>;

template <int NV>
using pma58_t = control::pma<NV, pma58_mod<NV>>;

template <int NV>
using split42_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma59_t<NV>>, 
                                   pma60_t<NV>>;

template <int NV>
using modchain19_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split42_t<NV>>>;

template <int NV>
using modchain19_t = wrap::control_rate<modchain19_t_<NV>>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<2, tempo_sync25_t<NV>>, 
                                    smoothed_parameter_unscaled1_t<NV>, 
                                    core::fix_delay, 
                                    pma58_t<NV>, 
                                    cable_table44_t<NV>, 
                                    cable_table45_t, 
                                    modchain19_t<NV>, 
                                    filters::svf<NV>, 
                                    comp23_t, 
                                    core::gain<NV>>;

template <int NV>
using split41_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain109_t<NV>>>;

template <int NV>
using chain104_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<stereo_cable>>, 
                                    split39_t<NV>, 
                                    modchain18_t<NV>, 
                                    split41_t<NV>, 
                                    routing::send<stereo_cable>>;

using chain99_t = chain4_t;

template <int NV> using chain101_t = chain60_t<NV>;
template <int NV> using oscillator7_t = oscillator_t<NV>;

template <int NV>
using chain102_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::clear<NV>>, 
                                    oscillator7_t<NV>, 
                                    wrap::no_process<math::clear<NV>>>;
template <int NV>
using branch25_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain101_t<NV>>, 
                                     chain102_t<NV>>;

template <int NV>
using peak7_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma51_t<NV>, 0>, 
                                   parameter::plain<pma54_t<NV>, 0>>;

template <int NV>
using peak7_t = wrap::mod<peak7_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain100_t = container::chain<parameter::empty, 
                                    wrap::fix<2, tempo_sync22_t<NV>>, 
                                    branch25_t<NV>, 
                                    fx::sampleandhold<NV>, 
                                    peak7_t<NV>, 
                                    core::gain<NV>>;

template <int NV>
using split35_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain99_t>, 
                                   chain100_t<NV>>;

template <int NV>
using split36_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma51_t<NV>>, 
                                   pma52_t<NV>>;

template <int NV>
using modchain16_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split36_t<NV>>>;

template <int NV>
using modchain16_t = wrap::control_rate<modchain16_t_<NV>>;

template <int NV> using cable_table42_mod = cable_table_mod<NV>;

struct cable_table42_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
};

template <int NV>
using cable_table42_t = wrap::data<control::cable_table<cable_table42_mod<NV>>, 
                                   data::embedded::table<cable_table42_t_data>>;

using comp22_t = comp_t;
using cable_table43_mod = parameter::from0To1<comp22_t, 
                                              0, 
                                              xfader_c0Range>;

struct cable_table43_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998769f, 0.997537f, 0.996306f, 0.995075f, 0.993843f,
		0.992612f, 0.991381f, 0.990149f, 0.988918f, 0.987687f, 0.986455f,
		0.985224f, 0.983993f, 0.982761f, 0.98153f, 0.980299f, 0.979067f,
		0.977836f, 0.976605f, 0.975373f, 0.974142f, 0.972911f, 0.971679f,
		0.970448f, 0.969217f, 0.967985f, 0.966754f, 0.965523f, 0.964291f,
		0.96306f, 0.961829f, 0.960597f, 0.959366f, 0.958135f, 0.956903f,
		0.955672f, 0.954441f, 0.953209f, 0.951978f, 0.950746f, 0.949515f,
		0.948284f, 0.947052f, 0.945821f, 0.94459f, 0.943358f, 0.942127f,
		0.940896f, 0.939664f, 0.938433f, 0.937202f, 0.93597f, 0.934739f,
		0.933508f, 0.932276f, 0.931045f, 0.929814f, 0.928582f, 0.927351f,
		0.92612f, 0.924888f, 0.923657f, 0.922426f, 0.921194f, 0.919963f,
		0.918732f, 0.9175f, 0.916269f, 0.915038f, 0.913806f, 0.912575f,
		0.911344f, 0.910112f, 0.908881f, 0.90765f, 0.906418f, 0.905187f,
		0.903956f, 0.902724f, 0.901493f, 0.900262f, 0.89903f, 0.897799f,
		0.896568f, 0.895336f, 0.894105f, 0.892874f, 0.891642f, 0.890411f,
		0.88918f, 0.887948f, 0.886717f, 0.885486f, 0.884254f, 0.883023f,
		0.881792f, 0.88056f, 0.879329f, 0.878098f, 0.876866f, 0.875635f,
		0.874404f, 0.873172f, 0.871941f, 0.87071f, 0.869478f, 0.868247f,
		0.867016f, 0.865784f, 0.864553f, 0.863322f, 0.86209f, 0.860859f,
		0.859627f, 0.858396f, 0.857165f, 0.855933f, 0.854702f, 0.853471f,
		0.852239f, 0.851008f, 0.849777f, 0.848545f, 0.847314f, 0.846083f,
		0.844851f, 0.84362f, 0.842389f, 0.841157f, 0.839926f, 0.838695f,
		0.837463f, 0.836232f, 0.835001f, 0.833769f, 0.832538f, 0.831307f,
		0.830075f, 0.828844f, 0.827613f, 0.826381f, 0.82515f, 0.823919f,
		0.822687f, 0.821456f, 0.820225f, 0.818993f, 0.817762f, 0.816531f,
		0.815299f, 0.814068f, 0.812837f, 0.811605f, 0.810374f, 0.809143f,
		0.807911f, 0.80668f, 0.805449f, 0.804217f, 0.802986f, 0.801755f,
		0.800523f, 0.799292f, 0.798061f, 0.796829f, 0.795598f, 0.794367f,
		0.793135f, 0.791904f, 0.790673f, 0.789441f, 0.78821f, 0.786979f,
		0.785747f, 0.784516f, 0.783285f, 0.782053f, 0.780822f, 0.779591f,
		0.778359f, 0.777128f, 0.775897f, 0.774665f, 0.773434f, 0.772203f,
		0.770971f, 0.76974f, 0.768509f, 0.767277f, 0.766046f, 0.764814f,
		0.763583f, 0.762352f, 0.76112f, 0.759889f, 0.758658f, 0.757427f,
		0.756195f, 0.754964f, 0.753733f, 0.752501f, 0.75127f, 0.750038f,
		0.748807f, 0.747576f, 0.746344f, 0.745113f, 0.743882f, 0.74265f,
		0.741419f, 0.740188f, 0.738956f, 0.737725f, 0.736494f, 0.735262f,
		0.734031f, 0.7328f, 0.731568f, 0.730337f, 0.729106f, 0.727874f,
		0.726643f, 0.725412f, 0.72418f, 0.722949f, 0.721718f, 0.720486f,
		0.719255f, 0.718024f, 0.716792f, 0.715561f, 0.71433f, 0.713098f,
		0.711867f, 0.710636f, 0.709404f, 0.708173f, 0.706942f, 0.70571f,
		0.704479f, 0.703248f, 0.702016f, 0.700785f, 0.699554f, 0.698322f,
		0.697091f, 0.69586f, 0.694628f, 0.693397f, 0.692166f, 0.690934f,
		0.689703f, 0.688472f, 0.68724f, 0.686009f, 0.684778f, 0.683546f,
		0.682315f, 0.681084f, 0.679852f, 0.678621f, 0.67739f, 0.676158f,
		0.674927f, 0.673696f, 0.672464f, 0.671233f, 0.670002f, 0.66877f,
		0.667539f, 0.666308f, 0.665076f, 0.663845f, 0.662614f, 0.661382f,
		0.660151f, 0.658919f, 0.657688f, 0.656457f, 0.655226f, 0.653994f,
		0.652763f, 0.651531f, 0.6503f, 0.649069f, 0.647837f, 0.646606f,
		0.645375f, 0.644143f, 0.642912f, 0.641681f, 0.640449f, 0.639218f,
		0.637987f, 0.636755f, 0.635524f, 0.634293f, 0.633061f, 0.63183f,
		0.630599f, 0.629367f, 0.628136f, 0.626905f, 0.625673f, 0.624442f,
		0.623211f, 0.621979f, 0.620748f, 0.619517f, 0.618285f, 0.617054f,
		0.615823f, 0.614591f, 0.61336f, 0.612129f, 0.610897f, 0.609666f,
		0.608435f, 0.607203f, 0.605972f, 0.604741f, 0.603509f, 0.602278f,
		0.601047f, 0.599815f, 0.598584f, 0.597353f, 0.596121f, 0.59489f,
		0.593659f, 0.592427f, 0.591196f, 0.589965f, 0.588733f, 0.587502f,
		0.586271f, 0.585039f, 0.583808f, 0.582577f, 0.581345f, 0.580114f,
		0.578883f, 0.577651f, 0.57642f, 0.575189f, 0.573957f, 0.572726f,
		0.571494f, 0.570263f, 0.569032f, 0.567801f, 0.566569f, 0.565338f,
		0.564106f, 0.562875f, 0.561644f, 0.560412f, 0.559181f, 0.55795f,
		0.556718f, 0.555487f, 0.554256f, 0.553024f, 0.551793f, 0.550562f,
		0.54933f, 0.548099f, 0.546868f, 0.545636f, 0.544405f, 0.543174f,
		0.541942f, 0.540711f, 0.53948f, 0.538248f, 0.537017f, 0.535786f,
		0.534554f, 0.533323f, 0.532092f, 0.53086f, 0.529629f, 0.528398f,
		0.527166f, 0.525935f, 0.524704f, 0.523472f, 0.522241f, 0.52101f,
		0.519778f, 0.518547f, 0.517316f, 0.516084f, 0.514853f, 0.513622f,
		0.51239f, 0.511159f, 0.509928f, 0.508696f, 0.507465f, 0.506234f,
		0.505002f, 0.503771f, 0.50254f, 0.501308f, 0.500077f, 0.498846f,
		0.497614f, 0.496383f, 0.495152f, 0.49392f, 0.492689f, 0.491458f,
		0.490226f, 0.488995f, 0.487764f, 0.486532f, 0.485301f, 0.48407f,
		0.482838f, 0.481607f, 0.480376f, 0.479144f, 0.477913f, 0.476682f,
		0.47545f, 0.474219f, 0.472988f, 0.471756f, 0.470525f, 0.469293f,
		0.468062f, 0.466831f, 0.465599f, 0.464368f, 0.463137f, 0.461905f,
		0.460674f, 0.459443f, 0.458211f, 0.45698f, 0.455749f, 0.454517f,
		0.453286f, 0.452055f, 0.450823f, 0.449592f, 0.448361f, 0.447129f,
		0.445898f, 0.444667f, 0.443435f, 0.442204f, 0.440973f, 0.439741f,
		0.43851f, 0.437279f, 0.436047f, 0.434816f, 0.433585f, 0.432353f,
		0.431122f, 0.429891f, 0.428659f, 0.427428f, 0.426197f, 0.424965f,
		0.423734f, 0.422503f, 0.421271f, 0.42004f, 0.418809f, 0.417577f,
		0.416346f, 0.415115f, 0.413883f, 0.412652f, 0.411421f, 0.410189f,
		0.408958f, 0.407727f, 0.406495f, 0.405264f, 0.404033f, 0.402801f,
		0.40157f, 0.400339f, 0.399107f, 0.397876f, 0.396645f, 0.395413f,
		0.394182f, 0.392951f, 0.391719f, 0.390488f, 0.389257f, 0.388025f,
		0.386794f, 0.385563f, 0.384331f, 0.3831f, 0.381868f, 0.380637f,
		0.379406f, 0.378175f, 0.376943f, 0.375712f, 0.374481f, 0.373249f,
		0.372018f, 0.370786f
	};
};

using cable_table43_t = wrap::data<control::cable_table<cable_table43_mod>, 
                                   data::embedded::table<cable_table43_t_data>>;

template <int NV>
using pma53_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table42_t<NV>, 0>, 
                                   parameter::plain<cable_table43_t, 0>>;

template <int NV>
using pma53_t = control::pma<NV, pma53_mod<NV>>;

template <int NV>
using split38_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma54_t<NV>>, 
                                   pma55_t<NV>>;

template <int NV>
using modchain17_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split38_t<NV>>>;

template <int NV>
using modchain17_t = wrap::control_rate<modchain17_t_<NV>>;

template <int NV>
using chain103_t = container::chain<parameter::empty, 
                                    wrap::fix<2, tempo_sync23_t<NV>>, 
                                    smoothed_parameter_unscaled6_t<NV>, 
                                    core::fix_delay, 
                                    pma53_t<NV>, 
                                    cable_table42_t<NV>, 
                                    cable_table43_t, 
                                    modchain17_t<NV>, 
                                    filters::svf<NV>, 
                                    comp22_t, 
                                    core::gain<NV>>;

template <int NV>
using split37_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain103_t<NV>>>;

template <int NV>
using chain98_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   split35_t<NV>, 
                                   modchain16_t<NV>, 
                                   split37_t<NV>, 
                                   routing::send<stereo_cable>>;

using chain93_t = chain4_t;

template <int NV> using chain95_t = chain60_t<NV>;
template <int NV> using oscillator6_t = oscillator_t<NV>;

template <int NV>
using chain96_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   oscillator6_t<NV>, 
                                   wrap::no_process<math::clear<NV>>>;
template <int NV>
using branch24_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain95_t<NV>>, 
                                     chain96_t<NV>>;

template <int NV>
using peak6_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma46_t<NV>, 0>, 
                                   parameter::plain<pma49_t<NV>, 0>>;

template <int NV>
using peak6_t = wrap::mod<peak6_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain94_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync20_t<NV>>, 
                                   branch24_t<NV>, 
                                   fx::sampleandhold<NV>, 
                                   peak6_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split31_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain93_t>, 
                                   chain94_t<NV>>;

template <int NV>
using split32_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma46_t<NV>>, 
                                   pma47_t<NV>>;

template <int NV>
using modchain14_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split32_t<NV>>>;

template <int NV>
using modchain14_t = wrap::control_rate<modchain14_t_<NV>>;

template <int NV> using cable_table40_mod = cable_table_mod<NV>;

struct cable_table40_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
};

template <int NV>
using cable_table40_t = wrap::data<control::cable_table<cable_table40_mod<NV>>, 
                                   data::embedded::table<cable_table40_t_data>>;

using comp21_t = comp_t;
using cable_table41_mod = parameter::from0To1<comp21_t, 
                                              0, 
                                              xfader_c0Range>;

struct cable_table41_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998769f, 0.997537f, 0.996306f, 0.995075f, 0.993843f,
		0.992612f, 0.991381f, 0.990149f, 0.988918f, 0.987687f, 0.986455f,
		0.985224f, 0.983993f, 0.982761f, 0.98153f, 0.980299f, 0.979067f,
		0.977836f, 0.976605f, 0.975373f, 0.974142f, 0.972911f, 0.971679f,
		0.970448f, 0.969217f, 0.967985f, 0.966754f, 0.965523f, 0.964291f,
		0.96306f, 0.961829f, 0.960597f, 0.959366f, 0.958135f, 0.956903f,
		0.955672f, 0.954441f, 0.953209f, 0.951978f, 0.950746f, 0.949515f,
		0.948284f, 0.947052f, 0.945821f, 0.94459f, 0.943358f, 0.942127f,
		0.940896f, 0.939664f, 0.938433f, 0.937202f, 0.93597f, 0.934739f,
		0.933508f, 0.932276f, 0.931045f, 0.929814f, 0.928582f, 0.927351f,
		0.92612f, 0.924888f, 0.923657f, 0.922426f, 0.921194f, 0.919963f,
		0.918732f, 0.9175f, 0.916269f, 0.915038f, 0.913806f, 0.912575f,
		0.911344f, 0.910112f, 0.908881f, 0.90765f, 0.906418f, 0.905187f,
		0.903956f, 0.902724f, 0.901493f, 0.900262f, 0.89903f, 0.897799f,
		0.896568f, 0.895336f, 0.894105f, 0.892874f, 0.891642f, 0.890411f,
		0.88918f, 0.887948f, 0.886717f, 0.885486f, 0.884254f, 0.883023f,
		0.881792f, 0.88056f, 0.879329f, 0.878098f, 0.876866f, 0.875635f,
		0.874404f, 0.873172f, 0.871941f, 0.87071f, 0.869478f, 0.868247f,
		0.867016f, 0.865784f, 0.864553f, 0.863322f, 0.86209f, 0.860859f,
		0.859627f, 0.858396f, 0.857165f, 0.855933f, 0.854702f, 0.853471f,
		0.852239f, 0.851008f, 0.849777f, 0.848545f, 0.847314f, 0.846083f,
		0.844851f, 0.84362f, 0.842389f, 0.841157f, 0.839926f, 0.838695f,
		0.837463f, 0.836232f, 0.835001f, 0.833769f, 0.832538f, 0.831307f,
		0.830075f, 0.828844f, 0.827613f, 0.826381f, 0.82515f, 0.823919f,
		0.822687f, 0.821456f, 0.820225f, 0.818993f, 0.817762f, 0.816531f,
		0.815299f, 0.814068f, 0.812837f, 0.811605f, 0.810374f, 0.809143f,
		0.807911f, 0.80668f, 0.805449f, 0.804217f, 0.802986f, 0.801755f,
		0.800523f, 0.799292f, 0.798061f, 0.796829f, 0.795598f, 0.794367f,
		0.793135f, 0.791904f, 0.790673f, 0.789441f, 0.78821f, 0.786979f,
		0.785747f, 0.784516f, 0.783285f, 0.782053f, 0.780822f, 0.779591f,
		0.778359f, 0.777128f, 0.775897f, 0.774665f, 0.773434f, 0.772203f,
		0.770971f, 0.76974f, 0.768509f, 0.767277f, 0.766046f, 0.764814f,
		0.763583f, 0.762352f, 0.76112f, 0.759889f, 0.758658f, 0.757427f,
		0.756195f, 0.754964f, 0.753733f, 0.752501f, 0.75127f, 0.750038f,
		0.748807f, 0.747576f, 0.746344f, 0.745113f, 0.743882f, 0.74265f,
		0.741419f, 0.740188f, 0.738956f, 0.737725f, 0.736494f, 0.735262f,
		0.734031f, 0.7328f, 0.731568f, 0.730337f, 0.729106f, 0.727874f,
		0.726643f, 0.725412f, 0.72418f, 0.722949f, 0.721718f, 0.720486f,
		0.719255f, 0.718024f, 0.716792f, 0.715561f, 0.71433f, 0.713098f,
		0.711867f, 0.710636f, 0.709404f, 0.708173f, 0.706942f, 0.70571f,
		0.704479f, 0.703248f, 0.702016f, 0.700785f, 0.699554f, 0.698322f,
		0.697091f, 0.69586f, 0.694628f, 0.693397f, 0.692166f, 0.690934f,
		0.689703f, 0.688472f, 0.68724f, 0.686009f, 0.684778f, 0.683546f,
		0.682315f, 0.681084f, 0.679852f, 0.678621f, 0.67739f, 0.676158f,
		0.674927f, 0.673696f, 0.672464f, 0.671233f, 0.670002f, 0.66877f,
		0.667539f, 0.666308f, 0.665076f, 0.663845f, 0.662614f, 0.661382f,
		0.660151f, 0.658919f, 0.657688f, 0.656457f, 0.655226f, 0.653994f,
		0.652763f, 0.651531f, 0.6503f, 0.649069f, 0.647837f, 0.646606f,
		0.645375f, 0.644143f, 0.642912f, 0.641681f, 0.640449f, 0.639218f,
		0.637987f, 0.636755f, 0.635524f, 0.634293f, 0.633061f, 0.63183f,
		0.630599f, 0.629367f, 0.628136f, 0.626905f, 0.625673f, 0.624442f,
		0.623211f, 0.621979f, 0.620748f, 0.619517f, 0.618285f, 0.617054f,
		0.615823f, 0.614591f, 0.61336f, 0.612129f, 0.610897f, 0.609666f,
		0.608435f, 0.607203f, 0.605972f, 0.604741f, 0.603509f, 0.602278f,
		0.601047f, 0.599815f, 0.598584f, 0.597353f, 0.596121f, 0.59489f,
		0.593659f, 0.592427f, 0.591196f, 0.589965f, 0.588733f, 0.587502f,
		0.586271f, 0.585039f, 0.583808f, 0.582577f, 0.581345f, 0.580114f,
		0.578883f, 0.577651f, 0.57642f, 0.575189f, 0.573957f, 0.572726f,
		0.571494f, 0.570263f, 0.569032f, 0.567801f, 0.566569f, 0.565338f,
		0.564106f, 0.562875f, 0.561644f, 0.560412f, 0.559181f, 0.55795f,
		0.556718f, 0.555487f, 0.554256f, 0.553024f, 0.551793f, 0.550562f,
		0.54933f, 0.548099f, 0.546868f, 0.545636f, 0.544405f, 0.543174f,
		0.541942f, 0.540711f, 0.53948f, 0.538248f, 0.537017f, 0.535786f,
		0.534554f, 0.533323f, 0.532092f, 0.53086f, 0.529629f, 0.528398f,
		0.527166f, 0.525935f, 0.524704f, 0.523472f, 0.522241f, 0.52101f,
		0.519778f, 0.518547f, 0.517316f, 0.516084f, 0.514853f, 0.513622f,
		0.51239f, 0.511159f, 0.509928f, 0.508696f, 0.507465f, 0.506234f,
		0.505002f, 0.503771f, 0.50254f, 0.501308f, 0.500077f, 0.498846f,
		0.497614f, 0.496383f, 0.495152f, 0.49392f, 0.492689f, 0.491458f,
		0.490226f, 0.488995f, 0.487764f, 0.486532f, 0.485301f, 0.48407f,
		0.482838f, 0.481607f, 0.480376f, 0.479144f, 0.477913f, 0.476682f,
		0.47545f, 0.474219f, 0.472988f, 0.471756f, 0.470525f, 0.469293f,
		0.468062f, 0.466831f, 0.465599f, 0.464368f, 0.463137f, 0.461905f,
		0.460674f, 0.459443f, 0.458211f, 0.45698f, 0.455749f, 0.454517f,
		0.453286f, 0.452055f, 0.450823f, 0.449592f, 0.448361f, 0.447129f,
		0.445898f, 0.444667f, 0.443435f, 0.442204f, 0.440973f, 0.439741f,
		0.43851f, 0.437279f, 0.436047f, 0.434816f, 0.433585f, 0.432353f,
		0.431122f, 0.429891f, 0.428659f, 0.427428f, 0.426197f, 0.424965f,
		0.423734f, 0.422503f, 0.421271f, 0.42004f, 0.418809f, 0.417577f,
		0.416346f, 0.415115f, 0.413883f, 0.412652f, 0.411421f, 0.410189f,
		0.408958f, 0.407727f, 0.406495f, 0.405264f, 0.404033f, 0.402801f,
		0.40157f, 0.400339f, 0.399107f, 0.397876f, 0.396645f, 0.395413f,
		0.394182f, 0.392951f, 0.391719f, 0.390488f, 0.389257f, 0.388025f,
		0.386794f, 0.385563f, 0.384331f, 0.3831f, 0.381868f, 0.380637f,
		0.379406f, 0.378175f, 0.376943f, 0.375712f, 0.374481f, 0.373249f,
		0.372018f, 0.370786f
	};
};

using cable_table41_t = wrap::data<control::cable_table<cable_table41_mod>, 
                                   data::embedded::table<cable_table41_t_data>>;

template <int NV>
using pma48_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table40_t<NV>, 0>, 
                                   parameter::plain<cable_table41_t, 0>>;

template <int NV>
using pma48_t = control::pma<NV, pma48_mod<NV>>;

template <int NV>
using split34_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma49_t<NV>>, 
                                   pma50_t<NV>>;

template <int NV>
using modchain15_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split34_t<NV>>>;

template <int NV>
using modchain15_t = wrap::control_rate<modchain15_t_<NV>>;

template <int NV>
using chain97_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync21_t<NV>>, 
                                   smoothed_parameter_unscaled5_t<NV>, 
                                   core::fix_delay, 
                                   pma48_t<NV>, 
                                   cable_table40_t<NV>, 
                                   cable_table41_t, 
                                   modchain15_t<NV>, 
                                   filters::svf<NV>, 
                                   comp21_t, 
                                   core::gain<NV>>;

template <int NV>
using split33_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain97_t<NV>>>;

template <int NV>
using chain92_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   split31_t<NV>, 
                                   modchain14_t<NV>, 
                                   split33_t<NV>, 
                                   routing::send<stereo_cable>>;

using chain87_t = chain4_t;

template <int NV> using chain89_t = chain60_t<NV>;
template <int NV> using oscillator5_t = oscillator_t<NV>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   oscillator5_t<NV>, 
                                   wrap::no_process<math::clear<NV>>>;
template <int NV>
using branch23_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain89_t<NV>>, 
                                     chain90_t<NV>>;

template <int NV>
using peak5_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma41_t<NV>, 0>, 
                                   parameter::plain<pma44_t<NV>, 0>>;

template <int NV>
using peak5_t = wrap::mod<peak5_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain88_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync18_t<NV>>, 
                                   branch23_t<NV>, 
                                   fx::sampleandhold<NV>, 
                                   peak5_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split27_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain87_t>, 
                                   chain88_t<NV>>;

template <int NV>
using split28_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma41_t<NV>>, 
                                   pma42_t<NV>>;

template <int NV>
using modchain12_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split28_t<NV>>>;

template <int NV>
using modchain12_t = wrap::control_rate<modchain12_t_<NV>>;

template <int NV> using cable_table38_mod = cable_table_mod<NV>;

struct cable_table38_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
};

template <int NV>
using cable_table38_t = wrap::data<control::cable_table<cable_table38_mod<NV>>, 
                                   data::embedded::table<cable_table38_t_data>>;

using comp20_t = comp_t;
using cable_table39_mod = parameter::from0To1<comp20_t, 
                                              0, 
                                              xfader_c0Range>;

struct cable_table39_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998769f, 0.997537f, 0.996306f, 0.995075f, 0.993843f,
		0.992612f, 0.991381f, 0.990149f, 0.988918f, 0.987687f, 0.986455f,
		0.985224f, 0.983993f, 0.982761f, 0.98153f, 0.980299f, 0.979067f,
		0.977836f, 0.976605f, 0.975373f, 0.974142f, 0.972911f, 0.971679f,
		0.970448f, 0.969217f, 0.967985f, 0.966754f, 0.965523f, 0.964291f,
		0.96306f, 0.961829f, 0.960597f, 0.959366f, 0.958135f, 0.956903f,
		0.955672f, 0.954441f, 0.953209f, 0.951978f, 0.950746f, 0.949515f,
		0.948284f, 0.947052f, 0.945821f, 0.94459f, 0.943358f, 0.942127f,
		0.940896f, 0.939664f, 0.938433f, 0.937202f, 0.93597f, 0.934739f,
		0.933508f, 0.932276f, 0.931045f, 0.929814f, 0.928582f, 0.927351f,
		0.92612f, 0.924888f, 0.923657f, 0.922426f, 0.921194f, 0.919963f,
		0.918732f, 0.9175f, 0.916269f, 0.915038f, 0.913806f, 0.912575f,
		0.911344f, 0.910112f, 0.908881f, 0.90765f, 0.906418f, 0.905187f,
		0.903956f, 0.902724f, 0.901493f, 0.900262f, 0.89903f, 0.897799f,
		0.896568f, 0.895336f, 0.894105f, 0.892874f, 0.891642f, 0.890411f,
		0.88918f, 0.887948f, 0.886717f, 0.885486f, 0.884254f, 0.883023f,
		0.881792f, 0.88056f, 0.879329f, 0.878098f, 0.876866f, 0.875635f,
		0.874404f, 0.873172f, 0.871941f, 0.87071f, 0.869478f, 0.868247f,
		0.867016f, 0.865784f, 0.864553f, 0.863322f, 0.86209f, 0.860859f,
		0.859627f, 0.858396f, 0.857165f, 0.855933f, 0.854702f, 0.853471f,
		0.852239f, 0.851008f, 0.849777f, 0.848545f, 0.847314f, 0.846083f,
		0.844851f, 0.84362f, 0.842389f, 0.841157f, 0.839926f, 0.838695f,
		0.837463f, 0.836232f, 0.835001f, 0.833769f, 0.832538f, 0.831307f,
		0.830075f, 0.828844f, 0.827613f, 0.826381f, 0.82515f, 0.823919f,
		0.822687f, 0.821456f, 0.820225f, 0.818993f, 0.817762f, 0.816531f,
		0.815299f, 0.814068f, 0.812837f, 0.811605f, 0.810374f, 0.809143f,
		0.807911f, 0.80668f, 0.805449f, 0.804217f, 0.802986f, 0.801755f,
		0.800523f, 0.799292f, 0.798061f, 0.796829f, 0.795598f, 0.794367f,
		0.793135f, 0.791904f, 0.790673f, 0.789441f, 0.78821f, 0.786979f,
		0.785747f, 0.784516f, 0.783285f, 0.782053f, 0.780822f, 0.779591f,
		0.778359f, 0.777128f, 0.775897f, 0.774665f, 0.773434f, 0.772203f,
		0.770971f, 0.76974f, 0.768509f, 0.767277f, 0.766046f, 0.764814f,
		0.763583f, 0.762352f, 0.76112f, 0.759889f, 0.758658f, 0.757427f,
		0.756195f, 0.754964f, 0.753733f, 0.752501f, 0.75127f, 0.750038f,
		0.748807f, 0.747576f, 0.746344f, 0.745113f, 0.743882f, 0.74265f,
		0.741419f, 0.740188f, 0.738956f, 0.737725f, 0.736494f, 0.735262f,
		0.734031f, 0.7328f, 0.731568f, 0.730337f, 0.729106f, 0.727874f,
		0.726643f, 0.725412f, 0.72418f, 0.722949f, 0.721718f, 0.720486f,
		0.719255f, 0.718024f, 0.716792f, 0.715561f, 0.71433f, 0.713098f,
		0.711867f, 0.710636f, 0.709404f, 0.708173f, 0.706942f, 0.70571f,
		0.704479f, 0.703248f, 0.702016f, 0.700785f, 0.699554f, 0.698322f,
		0.697091f, 0.69586f, 0.694628f, 0.693397f, 0.692166f, 0.690934f,
		0.689703f, 0.688472f, 0.68724f, 0.686009f, 0.684778f, 0.683546f,
		0.682315f, 0.681084f, 0.679852f, 0.678621f, 0.67739f, 0.676158f,
		0.674927f, 0.673696f, 0.672464f, 0.671233f, 0.670002f, 0.66877f,
		0.667539f, 0.666308f, 0.665076f, 0.663845f, 0.662614f, 0.661382f,
		0.660151f, 0.658919f, 0.657688f, 0.656457f, 0.655226f, 0.653994f,
		0.652763f, 0.651531f, 0.6503f, 0.649069f, 0.647837f, 0.646606f,
		0.645375f, 0.644143f, 0.642912f, 0.641681f, 0.640449f, 0.639218f,
		0.637987f, 0.636755f, 0.635524f, 0.634293f, 0.633061f, 0.63183f,
		0.630599f, 0.629367f, 0.628136f, 0.626905f, 0.625673f, 0.624442f,
		0.623211f, 0.621979f, 0.620748f, 0.619517f, 0.618285f, 0.617054f,
		0.615823f, 0.614591f, 0.61336f, 0.612129f, 0.610897f, 0.609666f,
		0.608435f, 0.607203f, 0.605972f, 0.604741f, 0.603509f, 0.602278f,
		0.601047f, 0.599815f, 0.598584f, 0.597353f, 0.596121f, 0.59489f,
		0.593659f, 0.592427f, 0.591196f, 0.589965f, 0.588733f, 0.587502f,
		0.586271f, 0.585039f, 0.583808f, 0.582577f, 0.581345f, 0.580114f,
		0.578883f, 0.577651f, 0.57642f, 0.575189f, 0.573957f, 0.572726f,
		0.571494f, 0.570263f, 0.569032f, 0.567801f, 0.566569f, 0.565338f,
		0.564106f, 0.562875f, 0.561644f, 0.560412f, 0.559181f, 0.55795f,
		0.556718f, 0.555487f, 0.554256f, 0.553024f, 0.551793f, 0.550562f,
		0.54933f, 0.548099f, 0.546868f, 0.545636f, 0.544405f, 0.543174f,
		0.541942f, 0.540711f, 0.53948f, 0.538248f, 0.537017f, 0.535786f,
		0.534554f, 0.533323f, 0.532092f, 0.53086f, 0.529629f, 0.528398f,
		0.527166f, 0.525935f, 0.524704f, 0.523472f, 0.522241f, 0.52101f,
		0.519778f, 0.518547f, 0.517316f, 0.516084f, 0.514853f, 0.513622f,
		0.51239f, 0.511159f, 0.509928f, 0.508696f, 0.507465f, 0.506234f,
		0.505002f, 0.503771f, 0.50254f, 0.501308f, 0.500077f, 0.498846f,
		0.497614f, 0.496383f, 0.495152f, 0.49392f, 0.492689f, 0.491458f,
		0.490226f, 0.488995f, 0.487764f, 0.486532f, 0.485301f, 0.48407f,
		0.482838f, 0.481607f, 0.480376f, 0.479144f, 0.477913f, 0.476682f,
		0.47545f, 0.474219f, 0.472988f, 0.471756f, 0.470525f, 0.469293f,
		0.468062f, 0.466831f, 0.465599f, 0.464368f, 0.463137f, 0.461905f,
		0.460674f, 0.459443f, 0.458211f, 0.45698f, 0.455749f, 0.454517f,
		0.453286f, 0.452055f, 0.450823f, 0.449592f, 0.448361f, 0.447129f,
		0.445898f, 0.444667f, 0.443435f, 0.442204f, 0.440973f, 0.439741f,
		0.43851f, 0.437279f, 0.436047f, 0.434816f, 0.433585f, 0.432353f,
		0.431122f, 0.429891f, 0.428659f, 0.427428f, 0.426197f, 0.424965f,
		0.423734f, 0.422503f, 0.421271f, 0.42004f, 0.418809f, 0.417577f,
		0.416346f, 0.415115f, 0.413883f, 0.412652f, 0.411421f, 0.410189f,
		0.408958f, 0.407727f, 0.406495f, 0.405264f, 0.404033f, 0.402801f,
		0.40157f, 0.400339f, 0.399107f, 0.397876f, 0.396645f, 0.395413f,
		0.394182f, 0.392951f, 0.391719f, 0.390488f, 0.389257f, 0.388025f,
		0.386794f, 0.385563f, 0.384331f, 0.3831f, 0.381868f, 0.380637f,
		0.379406f, 0.378175f, 0.376943f, 0.375712f, 0.374481f, 0.373249f,
		0.372018f, 0.370786f
	};
};

using cable_table39_t = wrap::data<control::cable_table<cable_table39_mod>, 
                                   data::embedded::table<cable_table39_t_data>>;

template <int NV>
using pma43_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table38_t<NV>, 0>, 
                                   parameter::plain<cable_table39_t, 0>>;

template <int NV>
using pma43_t = control::pma<NV, pma43_mod<NV>>;

template <int NV>
using split30_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma44_t<NV>>, 
                                   pma45_t<NV>>;

template <int NV>
using modchain13_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split30_t<NV>>>;

template <int NV>
using modchain13_t = wrap::control_rate<modchain13_t_<NV>>;

template <int NV>
using chain91_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync19_t<NV>>, 
                                   smoothed_parameter_unscaled4_t<NV>, 
                                   core::fix_delay, 
                                   pma43_t<NV>, 
                                   cable_table38_t<NV>, 
                                   cable_table39_t, 
                                   modchain13_t<NV>, 
                                   filters::svf<NV>, 
                                   comp20_t, 
                                   core::gain<NV>>;

template <int NV>
using split29_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain91_t<NV>>>;

template <int NV>
using chain86_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   split27_t<NV>, 
                                   modchain12_t<NV>, 
                                   split29_t<NV>, 
                                   routing::send<stereo_cable>>;

using chain81_t = chain4_t;

template <int NV> using chain83_t = chain60_t<NV>;
template <int NV> using oscillator4_t = oscillator_t<NV>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   oscillator4_t<NV>, 
                                   wrap::no_process<math::clear<NV>>>;
template <int NV>
using branch22_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain83_t<NV>>, 
                                     chain84_t<NV>>;

template <int NV>
using peak4_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma36_t<NV>, 0>, 
                                   parameter::plain<pma39_t<NV>, 0>>;

template <int NV>
using peak4_t = wrap::mod<peak4_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync16_t<NV>>, 
                                   branch22_t<NV>, 
                                   fx::sampleandhold<NV>, 
                                   peak4_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split23_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain81_t>, 
                                   chain82_t<NV>>;

template <int NV>
using split24_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma36_t<NV>>, 
                                   pma37_t<NV>>;

template <int NV>
using modchain10_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split24_t<NV>>>;

template <int NV>
using modchain10_t = wrap::control_rate<modchain10_t_<NV>>;

template <int NV> using cable_table36_mod = cable_table_mod<NV>;

struct cable_table36_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
};

template <int NV>
using cable_table36_t = wrap::data<control::cable_table<cable_table36_mod<NV>>, 
                                   data::embedded::table<cable_table36_t_data>>;

using comp19_t = comp_t;
using cable_table37_mod = parameter::from0To1<comp19_t, 
                                              0, 
                                              xfader_c0Range>;

struct cable_table37_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998769f, 0.997537f, 0.996306f, 0.995075f, 0.993843f,
		0.992612f, 0.991381f, 0.990149f, 0.988918f, 0.987687f, 0.986455f,
		0.985224f, 0.983993f, 0.982761f, 0.98153f, 0.980299f, 0.979067f,
		0.977836f, 0.976605f, 0.975373f, 0.974142f, 0.972911f, 0.971679f,
		0.970448f, 0.969217f, 0.967985f, 0.966754f, 0.965523f, 0.964291f,
		0.96306f, 0.961829f, 0.960597f, 0.959366f, 0.958135f, 0.956903f,
		0.955672f, 0.954441f, 0.953209f, 0.951978f, 0.950746f, 0.949515f,
		0.948284f, 0.947052f, 0.945821f, 0.94459f, 0.943358f, 0.942127f,
		0.940896f, 0.939664f, 0.938433f, 0.937202f, 0.93597f, 0.934739f,
		0.933508f, 0.932276f, 0.931045f, 0.929814f, 0.928582f, 0.927351f,
		0.92612f, 0.924888f, 0.923657f, 0.922426f, 0.921194f, 0.919963f,
		0.918732f, 0.9175f, 0.916269f, 0.915038f, 0.913806f, 0.912575f,
		0.911344f, 0.910112f, 0.908881f, 0.90765f, 0.906418f, 0.905187f,
		0.903956f, 0.902724f, 0.901493f, 0.900262f, 0.89903f, 0.897799f,
		0.896568f, 0.895336f, 0.894105f, 0.892874f, 0.891642f, 0.890411f,
		0.88918f, 0.887948f, 0.886717f, 0.885486f, 0.884254f, 0.883023f,
		0.881792f, 0.88056f, 0.879329f, 0.878098f, 0.876866f, 0.875635f,
		0.874404f, 0.873172f, 0.871941f, 0.87071f, 0.869478f, 0.868247f,
		0.867016f, 0.865784f, 0.864553f, 0.863322f, 0.86209f, 0.860859f,
		0.859627f, 0.858396f, 0.857165f, 0.855933f, 0.854702f, 0.853471f,
		0.852239f, 0.851008f, 0.849777f, 0.848545f, 0.847314f, 0.846083f,
		0.844851f, 0.84362f, 0.842389f, 0.841157f, 0.839926f, 0.838695f,
		0.837463f, 0.836232f, 0.835001f, 0.833769f, 0.832538f, 0.831307f,
		0.830075f, 0.828844f, 0.827613f, 0.826381f, 0.82515f, 0.823919f,
		0.822687f, 0.821456f, 0.820225f, 0.818993f, 0.817762f, 0.816531f,
		0.815299f, 0.814068f, 0.812837f, 0.811605f, 0.810374f, 0.809143f,
		0.807911f, 0.80668f, 0.805449f, 0.804217f, 0.802986f, 0.801755f,
		0.800523f, 0.799292f, 0.798061f, 0.796829f, 0.795598f, 0.794367f,
		0.793135f, 0.791904f, 0.790673f, 0.789441f, 0.78821f, 0.786979f,
		0.785747f, 0.784516f, 0.783285f, 0.782053f, 0.780822f, 0.779591f,
		0.778359f, 0.777128f, 0.775897f, 0.774665f, 0.773434f, 0.772203f,
		0.770971f, 0.76974f, 0.768509f, 0.767277f, 0.766046f, 0.764814f,
		0.763583f, 0.762352f, 0.76112f, 0.759889f, 0.758658f, 0.757427f,
		0.756195f, 0.754964f, 0.753733f, 0.752501f, 0.75127f, 0.750038f,
		0.748807f, 0.747576f, 0.746344f, 0.745113f, 0.743882f, 0.74265f,
		0.741419f, 0.740188f, 0.738956f, 0.737725f, 0.736494f, 0.735262f,
		0.734031f, 0.7328f, 0.731568f, 0.730337f, 0.729106f, 0.727874f,
		0.726643f, 0.725412f, 0.72418f, 0.722949f, 0.721718f, 0.720486f,
		0.719255f, 0.718024f, 0.716792f, 0.715561f, 0.71433f, 0.713098f,
		0.711867f, 0.710636f, 0.709404f, 0.708173f, 0.706942f, 0.70571f,
		0.704479f, 0.703248f, 0.702016f, 0.700785f, 0.699554f, 0.698322f,
		0.697091f, 0.69586f, 0.694628f, 0.693397f, 0.692166f, 0.690934f,
		0.689703f, 0.688472f, 0.68724f, 0.686009f, 0.684778f, 0.683546f,
		0.682315f, 0.681084f, 0.679852f, 0.678621f, 0.67739f, 0.676158f,
		0.674927f, 0.673696f, 0.672464f, 0.671233f, 0.670002f, 0.66877f,
		0.667539f, 0.666308f, 0.665076f, 0.663845f, 0.662614f, 0.661382f,
		0.660151f, 0.658919f, 0.657688f, 0.656457f, 0.655226f, 0.653994f,
		0.652763f, 0.651531f, 0.6503f, 0.649069f, 0.647837f, 0.646606f,
		0.645375f, 0.644143f, 0.642912f, 0.641681f, 0.640449f, 0.639218f,
		0.637987f, 0.636755f, 0.635524f, 0.634293f, 0.633061f, 0.63183f,
		0.630599f, 0.629367f, 0.628136f, 0.626905f, 0.625673f, 0.624442f,
		0.623211f, 0.621979f, 0.620748f, 0.619517f, 0.618285f, 0.617054f,
		0.615823f, 0.614591f, 0.61336f, 0.612129f, 0.610897f, 0.609666f,
		0.608435f, 0.607203f, 0.605972f, 0.604741f, 0.603509f, 0.602278f,
		0.601047f, 0.599815f, 0.598584f, 0.597353f, 0.596121f, 0.59489f,
		0.593659f, 0.592427f, 0.591196f, 0.589965f, 0.588733f, 0.587502f,
		0.586271f, 0.585039f, 0.583808f, 0.582577f, 0.581345f, 0.580114f,
		0.578883f, 0.577651f, 0.57642f, 0.575189f, 0.573957f, 0.572726f,
		0.571494f, 0.570263f, 0.569032f, 0.567801f, 0.566569f, 0.565338f,
		0.564106f, 0.562875f, 0.561644f, 0.560412f, 0.559181f, 0.55795f,
		0.556718f, 0.555487f, 0.554256f, 0.553024f, 0.551793f, 0.550562f,
		0.54933f, 0.548099f, 0.546868f, 0.545636f, 0.544405f, 0.543174f,
		0.541942f, 0.540711f, 0.53948f, 0.538248f, 0.537017f, 0.535786f,
		0.534554f, 0.533323f, 0.532092f, 0.53086f, 0.529629f, 0.528398f,
		0.527166f, 0.525935f, 0.524704f, 0.523472f, 0.522241f, 0.52101f,
		0.519778f, 0.518547f, 0.517316f, 0.516084f, 0.514853f, 0.513622f,
		0.51239f, 0.511159f, 0.509928f, 0.508696f, 0.507465f, 0.506234f,
		0.505002f, 0.503771f, 0.50254f, 0.501308f, 0.500077f, 0.498846f,
		0.497614f, 0.496383f, 0.495152f, 0.49392f, 0.492689f, 0.491458f,
		0.490226f, 0.488995f, 0.487764f, 0.486532f, 0.485301f, 0.48407f,
		0.482838f, 0.481607f, 0.480376f, 0.479144f, 0.477913f, 0.476682f,
		0.47545f, 0.474219f, 0.472988f, 0.471756f, 0.470525f, 0.469293f,
		0.468062f, 0.466831f, 0.465599f, 0.464368f, 0.463137f, 0.461905f,
		0.460674f, 0.459443f, 0.458211f, 0.45698f, 0.455749f, 0.454517f,
		0.453286f, 0.452055f, 0.450823f, 0.449592f, 0.448361f, 0.447129f,
		0.445898f, 0.444667f, 0.443435f, 0.442204f, 0.440973f, 0.439741f,
		0.43851f, 0.437279f, 0.436047f, 0.434816f, 0.433585f, 0.432353f,
		0.431122f, 0.429891f, 0.428659f, 0.427428f, 0.426197f, 0.424965f,
		0.423734f, 0.422503f, 0.421271f, 0.42004f, 0.418809f, 0.417577f,
		0.416346f, 0.415115f, 0.413883f, 0.412652f, 0.411421f, 0.410189f,
		0.408958f, 0.407727f, 0.406495f, 0.405264f, 0.404033f, 0.402801f,
		0.40157f, 0.400339f, 0.399107f, 0.397876f, 0.396645f, 0.395413f,
		0.394182f, 0.392951f, 0.391719f, 0.390488f, 0.389257f, 0.388025f,
		0.386794f, 0.385563f, 0.384331f, 0.3831f, 0.381868f, 0.380637f,
		0.379406f, 0.378175f, 0.376943f, 0.375712f, 0.374481f, 0.373249f,
		0.372018f, 0.370786f
	};
};

using cable_table37_t = wrap::data<control::cable_table<cable_table37_mod>, 
                                   data::embedded::table<cable_table37_t_data>>;

template <int NV>
using pma38_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table36_t<NV>, 0>, 
                                   parameter::plain<cable_table37_t, 0>>;

template <int NV>
using pma38_t = control::pma<NV, pma38_mod<NV>>;

template <int NV>
using split26_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma39_t<NV>>, 
                                   pma40_t<NV>>;

template <int NV>
using modchain11_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split26_t<NV>>>;

template <int NV>
using modchain11_t = wrap::control_rate<modchain11_t_<NV>>;

template <int NV>
using chain85_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync17_t<NV>>, 
                                   smoothed_parameter_unscaled3_t<NV>, 
                                   core::fix_delay, 
                                   pma38_t<NV>, 
                                   cable_table36_t<NV>, 
                                   cable_table37_t, 
                                   modchain11_t<NV>, 
                                   filters::svf<NV>, 
                                   comp19_t, 
                                   core::gain<NV>>;

template <int NV>
using split25_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain85_t<NV>>>;

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   split23_t<NV>, 
                                   modchain10_t<NV>, 
                                   split25_t<NV>, 
                                   routing::send<stereo_cable>>;

using chain75_t = chain4_t;

template <int NV> using chain77_t = chain60_t<NV>;
template <int NV> using oscillator3_t = oscillator_t<NV>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   oscillator3_t<NV>, 
                                   wrap::no_process<math::clear<NV>>>;
template <int NV>
using branch21_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain77_t<NV>>, 
                                     chain78_t<NV>>;

template <int NV>
using peak3_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma31_t<NV>, 0>, 
                                   parameter::plain<pma34_t<NV>, 0>>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync14_t<NV>>, 
                                   branch21_t<NV>, 
                                   fx::sampleandhold<NV>, 
                                   peak3_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split19_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain75_t>, 
                                   chain76_t<NV>>;

template <int NV>
using split20_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma31_t<NV>>, 
                                   pma32_t<NV>>;

template <int NV>
using modchain8_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split20_t<NV>>>;

template <int NV>
using modchain8_t = wrap::control_rate<modchain8_t_<NV>>;

template <int NV> using cable_table34_mod = cable_table_mod<NV>;

struct cable_table34_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
};

template <int NV>
using cable_table34_t = wrap::data<control::cable_table<cable_table34_mod<NV>>, 
                                   data::embedded::table<cable_table34_t_data>>;

using comp18_t = comp_t;
using cable_table35_mod = parameter::from0To1<comp18_t, 
                                              0, 
                                              xfader_c0Range>;

struct cable_table35_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998769f, 0.997537f, 0.996306f, 0.995075f, 0.993843f,
		0.992612f, 0.991381f, 0.990149f, 0.988918f, 0.987687f, 0.986455f,
		0.985224f, 0.983993f, 0.982761f, 0.98153f, 0.980299f, 0.979067f,
		0.977836f, 0.976605f, 0.975373f, 0.974142f, 0.972911f, 0.971679f,
		0.970448f, 0.969217f, 0.967985f, 0.966754f, 0.965523f, 0.964291f,
		0.96306f, 0.961829f, 0.960597f, 0.959366f, 0.958135f, 0.956903f,
		0.955672f, 0.954441f, 0.953209f, 0.951978f, 0.950746f, 0.949515f,
		0.948284f, 0.947052f, 0.945821f, 0.94459f, 0.943358f, 0.942127f,
		0.940896f, 0.939664f, 0.938433f, 0.937202f, 0.93597f, 0.934739f,
		0.933508f, 0.932276f, 0.931045f, 0.929814f, 0.928582f, 0.927351f,
		0.92612f, 0.924888f, 0.923657f, 0.922426f, 0.921194f, 0.919963f,
		0.918732f, 0.9175f, 0.916269f, 0.915038f, 0.913806f, 0.912575f,
		0.911344f, 0.910112f, 0.908881f, 0.90765f, 0.906418f, 0.905187f,
		0.903956f, 0.902724f, 0.901493f, 0.900262f, 0.89903f, 0.897799f,
		0.896568f, 0.895336f, 0.894105f, 0.892874f, 0.891642f, 0.890411f,
		0.88918f, 0.887948f, 0.886717f, 0.885486f, 0.884254f, 0.883023f,
		0.881792f, 0.88056f, 0.879329f, 0.878098f, 0.876866f, 0.875635f,
		0.874404f, 0.873172f, 0.871941f, 0.87071f, 0.869478f, 0.868247f,
		0.867016f, 0.865784f, 0.864553f, 0.863322f, 0.86209f, 0.860859f,
		0.859627f, 0.858396f, 0.857165f, 0.855933f, 0.854702f, 0.853471f,
		0.852239f, 0.851008f, 0.849777f, 0.848545f, 0.847314f, 0.846083f,
		0.844851f, 0.84362f, 0.842389f, 0.841157f, 0.839926f, 0.838695f,
		0.837463f, 0.836232f, 0.835001f, 0.833769f, 0.832538f, 0.831307f,
		0.830075f, 0.828844f, 0.827613f, 0.826381f, 0.82515f, 0.823919f,
		0.822687f, 0.821456f, 0.820225f, 0.818993f, 0.817762f, 0.816531f,
		0.815299f, 0.814068f, 0.812837f, 0.811605f, 0.810374f, 0.809143f,
		0.807911f, 0.80668f, 0.805449f, 0.804217f, 0.802986f, 0.801755f,
		0.800523f, 0.799292f, 0.798061f, 0.796829f, 0.795598f, 0.794367f,
		0.793135f, 0.791904f, 0.790673f, 0.789441f, 0.78821f, 0.786979f,
		0.785747f, 0.784516f, 0.783285f, 0.782053f, 0.780822f, 0.779591f,
		0.778359f, 0.777128f, 0.775897f, 0.774665f, 0.773434f, 0.772203f,
		0.770971f, 0.76974f, 0.768509f, 0.767277f, 0.766046f, 0.764814f,
		0.763583f, 0.762352f, 0.76112f, 0.759889f, 0.758658f, 0.757427f,
		0.756195f, 0.754964f, 0.753733f, 0.752501f, 0.75127f, 0.750038f,
		0.748807f, 0.747576f, 0.746344f, 0.745113f, 0.743882f, 0.74265f,
		0.741419f, 0.740188f, 0.738956f, 0.737725f, 0.736494f, 0.735262f,
		0.734031f, 0.7328f, 0.731568f, 0.730337f, 0.729106f, 0.727874f,
		0.726643f, 0.725412f, 0.72418f, 0.722949f, 0.721718f, 0.720486f,
		0.719255f, 0.718024f, 0.716792f, 0.715561f, 0.71433f, 0.713098f,
		0.711867f, 0.710636f, 0.709404f, 0.708173f, 0.706942f, 0.70571f,
		0.704479f, 0.703248f, 0.702016f, 0.700785f, 0.699554f, 0.698322f,
		0.697091f, 0.69586f, 0.694628f, 0.693397f, 0.692166f, 0.690934f,
		0.689703f, 0.688472f, 0.68724f, 0.686009f, 0.684778f, 0.683546f,
		0.682315f, 0.681084f, 0.679852f, 0.678621f, 0.67739f, 0.676158f,
		0.674927f, 0.673696f, 0.672464f, 0.671233f, 0.670002f, 0.66877f,
		0.667539f, 0.666308f, 0.665076f, 0.663845f, 0.662614f, 0.661382f,
		0.660151f, 0.658919f, 0.657688f, 0.656457f, 0.655226f, 0.653994f,
		0.652763f, 0.651531f, 0.6503f, 0.649069f, 0.647837f, 0.646606f,
		0.645375f, 0.644143f, 0.642912f, 0.641681f, 0.640449f, 0.639218f,
		0.637987f, 0.636755f, 0.635524f, 0.634293f, 0.633061f, 0.63183f,
		0.630599f, 0.629367f, 0.628136f, 0.626905f, 0.625673f, 0.624442f,
		0.623211f, 0.621979f, 0.620748f, 0.619517f, 0.618285f, 0.617054f,
		0.615823f, 0.614591f, 0.61336f, 0.612129f, 0.610897f, 0.609666f,
		0.608435f, 0.607203f, 0.605972f, 0.604741f, 0.603509f, 0.602278f,
		0.601047f, 0.599815f, 0.598584f, 0.597353f, 0.596121f, 0.59489f,
		0.593659f, 0.592427f, 0.591196f, 0.589965f, 0.588733f, 0.587502f,
		0.586271f, 0.585039f, 0.583808f, 0.582577f, 0.581345f, 0.580114f,
		0.578883f, 0.577651f, 0.57642f, 0.575189f, 0.573957f, 0.572726f,
		0.571494f, 0.570263f, 0.569032f, 0.567801f, 0.566569f, 0.565338f,
		0.564106f, 0.562875f, 0.561644f, 0.560412f, 0.559181f, 0.55795f,
		0.556718f, 0.555487f, 0.554256f, 0.553024f, 0.551793f, 0.550562f,
		0.54933f, 0.548099f, 0.546868f, 0.545636f, 0.544405f, 0.543174f,
		0.541942f, 0.540711f, 0.53948f, 0.538248f, 0.537017f, 0.535786f,
		0.534554f, 0.533323f, 0.532092f, 0.53086f, 0.529629f, 0.528398f,
		0.527166f, 0.525935f, 0.524704f, 0.523472f, 0.522241f, 0.52101f,
		0.519778f, 0.518547f, 0.517316f, 0.516084f, 0.514853f, 0.513622f,
		0.51239f, 0.511159f, 0.509928f, 0.508696f, 0.507465f, 0.506234f,
		0.505002f, 0.503771f, 0.50254f, 0.501308f, 0.500077f, 0.498846f,
		0.497614f, 0.496383f, 0.495152f, 0.49392f, 0.492689f, 0.491458f,
		0.490226f, 0.488995f, 0.487764f, 0.486532f, 0.485301f, 0.48407f,
		0.482838f, 0.481607f, 0.480376f, 0.479144f, 0.477913f, 0.476682f,
		0.47545f, 0.474219f, 0.472988f, 0.471756f, 0.470525f, 0.469293f,
		0.468062f, 0.466831f, 0.465599f, 0.464368f, 0.463137f, 0.461905f,
		0.460674f, 0.459443f, 0.458211f, 0.45698f, 0.455749f, 0.454517f,
		0.453286f, 0.452055f, 0.450823f, 0.449592f, 0.448361f, 0.447129f,
		0.445898f, 0.444667f, 0.443435f, 0.442204f, 0.440973f, 0.439741f,
		0.43851f, 0.437279f, 0.436047f, 0.434816f, 0.433585f, 0.432353f,
		0.431122f, 0.429891f, 0.428659f, 0.427428f, 0.426197f, 0.424965f,
		0.423734f, 0.422503f, 0.421271f, 0.42004f, 0.418809f, 0.417577f,
		0.416346f, 0.415115f, 0.413883f, 0.412652f, 0.411421f, 0.410189f,
		0.408958f, 0.407727f, 0.406495f, 0.405264f, 0.404033f, 0.402801f,
		0.40157f, 0.400339f, 0.399107f, 0.397876f, 0.396645f, 0.395413f,
		0.394182f, 0.392951f, 0.391719f, 0.390488f, 0.389257f, 0.388025f,
		0.386794f, 0.385563f, 0.384331f, 0.3831f, 0.381868f, 0.380637f,
		0.379406f, 0.378175f, 0.376943f, 0.375712f, 0.374481f, 0.373249f,
		0.372018f, 0.370786f
	};
};

using cable_table35_t = wrap::data<control::cable_table<cable_table35_mod>, 
                                   data::embedded::table<cable_table35_t_data>>;

template <int NV>
using pma33_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table34_t<NV>, 0>, 
                                   parameter::plain<cable_table35_t, 0>>;

template <int NV>
using pma33_t = control::pma<NV, pma33_mod<NV>>;

template <int NV>
using split22_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma34_t<NV>>, 
                                   pma35_t<NV>>;

template <int NV>
using modchain9_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split22_t<NV>>>;

template <int NV>
using modchain9_t = wrap::control_rate<modchain9_t_<NV>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync15_t<NV>>, 
                                   smoothed_parameter1_t<NV>, 
                                   core::fix_delay, 
                                   pma33_t<NV>, 
                                   cable_table34_t<NV>, 
                                   cable_table35_t, 
                                   modchain9_t<NV>, 
                                   filters::svf<NV>, 
                                   comp18_t, 
                                   core::gain<NV>>;

template <int NV>
using split21_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain79_t<NV>>>;

template <int NV>
using chain74_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   split19_t<NV>, 
                                   modchain8_t<NV>, 
                                   split21_t<NV>, 
                                   routing::send<stereo_cable>>;

using chain69_t = chain4_t;

template <int NV> using chain71_t = chain60_t<NV>;
template <int NV> using oscillator2_t = oscillator_t<NV>;

template <int NV>
using chain72_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   oscillator2_t<NV>, 
                                   wrap::no_process<math::clear<NV>>>;
template <int NV>
using branch20_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain71_t<NV>>, 
                                     chain72_t<NV>>;

template <int NV>
using peak2_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma26_t<NV>, 0>, 
                                   parameter::plain<pma29_t<NV>, 0>>;

template <int NV>
using peak2_t = wrap::mod<peak2_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync12_t<NV>>, 
                                   branch20_t<NV>, 
                                   fx::sampleandhold<NV>, 
                                   peak2_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain69_t>, 
                                   chain70_t<NV>>;

template <int NV>
using split16_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma26_t<NV>>, 
                                   pma27_t<NV>>;

template <int NV>
using modchain6_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split16_t<NV>>>;

template <int NV>
using modchain6_t = wrap::control_rate<modchain6_t_<NV>>;

template <int NV> using cable_table32_mod = cable_table_mod<NV>;

struct cable_table32_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
};

template <int NV>
using cable_table32_t = wrap::data<control::cable_table<cable_table32_mod<NV>>, 
                                   data::embedded::table<cable_table32_t_data>>;

using comp17_t = comp_t;
using cable_table33_mod = parameter::from0To1<comp17_t, 
                                              0, 
                                              xfader_c0Range>;

struct cable_table33_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998769f, 0.997537f, 0.996306f, 0.995075f, 0.993843f,
		0.992612f, 0.991381f, 0.990149f, 0.988918f, 0.987687f, 0.986455f,
		0.985224f, 0.983993f, 0.982761f, 0.98153f, 0.980299f, 0.979067f,
		0.977836f, 0.976605f, 0.975373f, 0.974142f, 0.972911f, 0.971679f,
		0.970448f, 0.969217f, 0.967985f, 0.966754f, 0.965523f, 0.964291f,
		0.96306f, 0.961829f, 0.960597f, 0.959366f, 0.958135f, 0.956903f,
		0.955672f, 0.954441f, 0.953209f, 0.951978f, 0.950746f, 0.949515f,
		0.948284f, 0.947052f, 0.945821f, 0.94459f, 0.943358f, 0.942127f,
		0.940896f, 0.939664f, 0.938433f, 0.937202f, 0.93597f, 0.934739f,
		0.933508f, 0.932276f, 0.931045f, 0.929814f, 0.928582f, 0.927351f,
		0.92612f, 0.924888f, 0.923657f, 0.922426f, 0.921194f, 0.919963f,
		0.918732f, 0.9175f, 0.916269f, 0.915038f, 0.913806f, 0.912575f,
		0.911344f, 0.910112f, 0.908881f, 0.90765f, 0.906418f, 0.905187f,
		0.903956f, 0.902724f, 0.901493f, 0.900262f, 0.89903f, 0.897799f,
		0.896568f, 0.895336f, 0.894105f, 0.892874f, 0.891642f, 0.890411f,
		0.88918f, 0.887948f, 0.886717f, 0.885486f, 0.884254f, 0.883023f,
		0.881792f, 0.88056f, 0.879329f, 0.878098f, 0.876866f, 0.875635f,
		0.874404f, 0.873172f, 0.871941f, 0.87071f, 0.869478f, 0.868247f,
		0.867016f, 0.865784f, 0.864553f, 0.863322f, 0.86209f, 0.860859f,
		0.859627f, 0.858396f, 0.857165f, 0.855933f, 0.854702f, 0.853471f,
		0.852239f, 0.851008f, 0.849777f, 0.848545f, 0.847314f, 0.846083f,
		0.844851f, 0.84362f, 0.842389f, 0.841157f, 0.839926f, 0.838695f,
		0.837463f, 0.836232f, 0.835001f, 0.833769f, 0.832538f, 0.831307f,
		0.830075f, 0.828844f, 0.827613f, 0.826381f, 0.82515f, 0.823919f,
		0.822687f, 0.821456f, 0.820225f, 0.818993f, 0.817762f, 0.816531f,
		0.815299f, 0.814068f, 0.812837f, 0.811605f, 0.810374f, 0.809143f,
		0.807911f, 0.80668f, 0.805449f, 0.804217f, 0.802986f, 0.801755f,
		0.800523f, 0.799292f, 0.798061f, 0.796829f, 0.795598f, 0.794367f,
		0.793135f, 0.791904f, 0.790673f, 0.789441f, 0.78821f, 0.786979f,
		0.785747f, 0.784516f, 0.783285f, 0.782053f, 0.780822f, 0.779591f,
		0.778359f, 0.777128f, 0.775897f, 0.774665f, 0.773434f, 0.772203f,
		0.770971f, 0.76974f, 0.768509f, 0.767277f, 0.766046f, 0.764814f,
		0.763583f, 0.762352f, 0.76112f, 0.759889f, 0.758658f, 0.757427f,
		0.756195f, 0.754964f, 0.753733f, 0.752501f, 0.75127f, 0.750038f,
		0.748807f, 0.747576f, 0.746344f, 0.745113f, 0.743882f, 0.74265f,
		0.741419f, 0.740188f, 0.738956f, 0.737725f, 0.736494f, 0.735262f,
		0.734031f, 0.7328f, 0.731568f, 0.730337f, 0.729106f, 0.727874f,
		0.726643f, 0.725412f, 0.72418f, 0.722949f, 0.721718f, 0.720486f,
		0.719255f, 0.718024f, 0.716792f, 0.715561f, 0.71433f, 0.713098f,
		0.711867f, 0.710636f, 0.709404f, 0.708173f, 0.706942f, 0.70571f,
		0.704479f, 0.703248f, 0.702016f, 0.700785f, 0.699554f, 0.698322f,
		0.697091f, 0.69586f, 0.694628f, 0.693397f, 0.692166f, 0.690934f,
		0.689703f, 0.688472f, 0.68724f, 0.686009f, 0.684778f, 0.683546f,
		0.682315f, 0.681084f, 0.679852f, 0.678621f, 0.67739f, 0.676158f,
		0.674927f, 0.673696f, 0.672464f, 0.671233f, 0.670002f, 0.66877f,
		0.667539f, 0.666308f, 0.665076f, 0.663845f, 0.662614f, 0.661382f,
		0.660151f, 0.658919f, 0.657688f, 0.656457f, 0.655226f, 0.653994f,
		0.652763f, 0.651531f, 0.6503f, 0.649069f, 0.647837f, 0.646606f,
		0.645375f, 0.644143f, 0.642912f, 0.641681f, 0.640449f, 0.639218f,
		0.637987f, 0.636755f, 0.635524f, 0.634293f, 0.633061f, 0.63183f,
		0.630599f, 0.629367f, 0.628136f, 0.626905f, 0.625673f, 0.624442f,
		0.623211f, 0.621979f, 0.620748f, 0.619517f, 0.618285f, 0.617054f,
		0.615823f, 0.614591f, 0.61336f, 0.612129f, 0.610897f, 0.609666f,
		0.608435f, 0.607203f, 0.605972f, 0.604741f, 0.603509f, 0.602278f,
		0.601047f, 0.599815f, 0.598584f, 0.597353f, 0.596121f, 0.59489f,
		0.593659f, 0.592427f, 0.591196f, 0.589965f, 0.588733f, 0.587502f,
		0.586271f, 0.585039f, 0.583808f, 0.582577f, 0.581345f, 0.580114f,
		0.578883f, 0.577651f, 0.57642f, 0.575189f, 0.573957f, 0.572726f,
		0.571494f, 0.570263f, 0.569032f, 0.567801f, 0.566569f, 0.565338f,
		0.564106f, 0.562875f, 0.561644f, 0.560412f, 0.559181f, 0.55795f,
		0.556718f, 0.555487f, 0.554256f, 0.553024f, 0.551793f, 0.550562f,
		0.54933f, 0.548099f, 0.546868f, 0.545636f, 0.544405f, 0.543174f,
		0.541942f, 0.540711f, 0.53948f, 0.538248f, 0.537017f, 0.535786f,
		0.534554f, 0.533323f, 0.532092f, 0.53086f, 0.529629f, 0.528398f,
		0.527166f, 0.525935f, 0.524704f, 0.523472f, 0.522241f, 0.52101f,
		0.519778f, 0.518547f, 0.517316f, 0.516084f, 0.514853f, 0.513622f,
		0.51239f, 0.511159f, 0.509928f, 0.508696f, 0.507465f, 0.506234f,
		0.505002f, 0.503771f, 0.50254f, 0.501308f, 0.500077f, 0.498846f,
		0.497614f, 0.496383f, 0.495152f, 0.49392f, 0.492689f, 0.491458f,
		0.490226f, 0.488995f, 0.487764f, 0.486532f, 0.485301f, 0.48407f,
		0.482838f, 0.481607f, 0.480376f, 0.479144f, 0.477913f, 0.476682f,
		0.47545f, 0.474219f, 0.472988f, 0.471756f, 0.470525f, 0.469293f,
		0.468062f, 0.466831f, 0.465599f, 0.464368f, 0.463137f, 0.461905f,
		0.460674f, 0.459443f, 0.458211f, 0.45698f, 0.455749f, 0.454517f,
		0.453286f, 0.452055f, 0.450823f, 0.449592f, 0.448361f, 0.447129f,
		0.445898f, 0.444667f, 0.443435f, 0.442204f, 0.440973f, 0.439741f,
		0.43851f, 0.437279f, 0.436047f, 0.434816f, 0.433585f, 0.432353f,
		0.431122f, 0.429891f, 0.428659f, 0.427428f, 0.426197f, 0.424965f,
		0.423734f, 0.422503f, 0.421271f, 0.42004f, 0.418809f, 0.417577f,
		0.416346f, 0.415115f, 0.413883f, 0.412652f, 0.411421f, 0.410189f,
		0.408958f, 0.407727f, 0.406495f, 0.405264f, 0.404033f, 0.402801f,
		0.40157f, 0.400339f, 0.399107f, 0.397876f, 0.396645f, 0.395413f,
		0.394182f, 0.392951f, 0.391719f, 0.390488f, 0.389257f, 0.388025f,
		0.386794f, 0.385563f, 0.384331f, 0.3831f, 0.381868f, 0.380637f,
		0.379406f, 0.378175f, 0.376943f, 0.375712f, 0.374481f, 0.373249f,
		0.372018f, 0.370786f
	};
};

using cable_table33_t = wrap::data<control::cable_table<cable_table33_mod>, 
                                   data::embedded::table<cable_table33_t_data>>;

template <int NV>
using pma28_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table32_t<NV>, 0>, 
                                   parameter::plain<cable_table33_t, 0>>;

template <int NV>
using pma28_t = control::pma<NV, pma28_mod<NV>>;

template <int NV>
using split18_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma29_t<NV>>, 
                                   pma30_t<NV>>;

template <int NV>
using modchain7_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split18_t<NV>>>;

template <int NV>
using modchain7_t = wrap::control_rate<modchain7_t_<NV>>;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync13_t<NV>>, 
                                   smoothed_parameter_unscaled2_t<NV>, 
                                   core::fix_delay, 
                                   pma28_t<NV>, 
                                   cable_table32_t<NV>, 
                                   cable_table33_t, 
                                   modchain7_t<NV>, 
                                   filters::svf<NV>, 
                                   comp17_t, 
                                   core::gain<NV>>;

template <int NV>
using split17_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain73_t<NV>>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   split15_t<NV>, 
                                   modchain6_t<NV>, 
                                   split17_t<NV>, 
                                   routing::send<stereo_cable>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain18_t<NV>>, 
                                   chain104_t<NV>, 
                                   chain98_t<NV>, 
                                   chain92_t<NV>, 
                                   chain86_t<NV>, 
                                   chain80_t<NV>, 
                                   chain74_t<NV>, 
                                   chain68_t<NV>>;

using chain44_t = chain4_t;

template <int NV> using chain45_t = chain_t<NV>;

template <int NV> using chain46_t = chain_t<NV>;
template <int NV>
using branch27_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain45_t<NV>>, 
                                     chain46_t<NV>>;
template <int NV>
using branch19_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain44_t>, 
                                     branch27_t<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, modchain_t<NV>>, 
                                   split10_t<NV>, 
                                   branch19_t<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain8_t<NV>>, 
                                    dynamic_blocksize1_t<NV>, 
                                    chain36_t<NV>, 
                                    chain9_t<NV>, 
                                    chain14_t<NV>, 
                                    chain17_t<NV>>;

using multi_t = container::multi<parameter::empty, 
                                 wrap::fix<2, core::empty>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, modchain1_t<NV>>, 
                                  branch3_t<NV>, 
                                  multi_t, 
                                  wrap::no_process<math::clear<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain2_t<NV>>, 
                                 chain3_t<NV>>;

namespace dlay_t_parameters
{
// Parameter list for dlay_impl::dlay_t ------------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(Feedback_7Range, 
                             0., 
                             2., 
                             0.001);

template <int NV>
using Feedback_7 = parameter::from0To1<project::granular<NV>, 
                                       1, 
                                       Feedback_7Range>;

template <int NV>
using Feedback = parameter::chain<ranges::Identity, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<dlay_impl::minmax1_t<NV>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  Feedback_7<NV>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>, 
                                  parameter::plain<routing::receive<stereo_cable>, 0>>;

template <int NV>
using Sync = parameter::chain<ranges::Identity, 
                              parameter::plain<dlay_impl::branch8_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch11_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch15_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch13_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch4_t<NV>, 0>, 
                              parameter::plain<dlay_impl::tempo_sync3_t<NV>, 2>, 
                              parameter::plain<dlay_impl::branch17_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch6_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch27_t<NV>, 0>>;

template <int NV>
using DTime = parameter::chain<ranges::Identity, 
                               parameter::plain<dlay_impl::pma_t<NV>, 2>, 
                               parameter::plain<dlay_impl::sliderbank_t<NV>, 0>>;

template <int NV>
using Reverse = parameter::chain<ranges::Identity, 
                                 parameter::plain<dlay_impl::branch1_t<NV>, 0>, 
                                 parameter::plain<dlay_impl::branch7_t<NV>, 0>, 
                                 parameter::plain<dlay_impl::branch10_t<NV>, 0>, 
                                 parameter::plain<dlay_impl::branch14_t<NV>, 0>, 
                                 parameter::plain<dlay_impl::branch12_t<NV>, 0>, 
                                 parameter::plain<dlay_impl::branch2_t<NV>, 0>, 
                                 parameter::plain<dlay_impl::branch16_t<NV>, 0>, 
                                 parameter::plain<dlay_impl::branch5_t<NV>, 0>, 
                                 parameter::plain<dlay_impl::branch19_t<NV>, 0>>;

template <int NV>
using DtimeR = parameter::from0To1<dlay_impl::pma1_t<NV>, 
                                   2, 
                                   dlay_impl::pma18_modRange>;

DECLARE_PARAMETER_RANGE_SKEW(Tone_InputRange, 
                             0., 
                             1., 
                             0.277381);
DECLARE_PARAMETER_RANGE_SKEW(Tone_0Range, 
                             20., 
                             20000., 
                             0.277381);

template <int NV>
using Tone_0 = parameter::from0To1<filters::svf<NV>, 
                                   0, 
                                   Tone_0Range>;

template <int NV>
using Tone_1 = parameter::from0To1<filters::one_pole<NV>, 
                                   0, 
                                   dlay_impl::pma19_modRange>;

template <int NV> using Tone_2 = Tone_1<NV>;

template <int NV> using Tone_3 = Tone_1<NV>;

template <int NV> using Tone_4 = Tone_1<NV>;

template <int NV> using Tone_5 = Tone_1<NV>;

template <int NV> using Tone_6 = Tone_1<NV>;

template <int NV> using Tone_7 = Tone_1<NV>;

template <int NV>
using Tone = parameter::chain<Tone_InputRange, 
                              Tone_0<NV>, 
                              Tone_1<NV>, 
                              Tone_2<NV>, 
                              Tone_3<NV>, 
                              Tone_4<NV>, 
                              Tone_5<NV>, 
                              Tone_6<NV>, 
                              Tone_7<NV>, 
                              parameter::plain<dlay_impl::sliderbank1_t<NV>, 0>>;

template <int NV>
using Div = parameter::chain<ranges::Identity, 
                             parameter::plain<dlay_impl::tempo_sync9_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync24_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync22_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync20_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync18_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync16_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync14_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync12_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync2_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync25_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync23_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync21_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync19_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync17_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync15_t<NV>, 1>, 
                             parameter::plain<dlay_impl::tempo_sync13_t<NV>, 1>>;

template <int NV>
using MultiRes_0 = parameter::from0To1<dlay_impl::pma2_t<NV>, 
                                       2, 
                                       dlay_impl::pma18_modRange>;

template <int NV>
using MultiRes_1 = parameter::from0To1<dlay_impl::pma58_t<NV>, 
                                       2, 
                                       dlay_impl::pma18_modRange>;

template <int NV>
using MultiRes_2 = parameter::from0To1<dlay_impl::pma53_t<NV>, 
                                       2, 
                                       dlay_impl::pma18_modRange>;

template <int NV>
using MultiRes_3 = parameter::from0To1<dlay_impl::pma48_t<NV>, 
                                       2, 
                                       dlay_impl::pma18_modRange>;

template <int NV>
using MultiRes_4 = parameter::from0To1<dlay_impl::pma43_t<NV>, 
                                       2, 
                                       dlay_impl::pma18_modRange>;

template <int NV>
using MultiRes_5 = parameter::from0To1<dlay_impl::pma38_t<NV>, 
                                       2, 
                                       dlay_impl::pma18_modRange>;

template <int NV>
using MultiRes_6 = parameter::from0To1<dlay_impl::pma33_t<NV>, 
                                       2, 
                                       dlay_impl::pma18_modRange>;

template <int NV>
using MultiRes_7 = parameter::from0To1<dlay_impl::pma28_t<NV>, 
                                       2, 
                                       dlay_impl::pma18_modRange>;

template <int NV>
using MultiRes = parameter::chain<ranges::Identity, 
                                  MultiRes_0<NV>, 
                                  MultiRes_1<NV>, 
                                  MultiRes_2<NV>, 
                                  MultiRes_3<NV>, 
                                  MultiRes_4<NV>, 
                                  MultiRes_5<NV>, 
                                  MultiRes_6<NV>, 
                                  MultiRes_7<NV>>;

template <int NV>
using MultiDelSH = parameter::chain<ranges::Identity, 
                                    parameter::plain<dlay_impl::pma17_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma56_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma51_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma46_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma41_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma36_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma31_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma26_t<NV>, 1>>;

template <int NV>
using MultiCutSH = parameter::chain<ranges::Identity, 
                                    parameter::plain<dlay_impl::pma19_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma59_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma54_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma49_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma44_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma39_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma34_t<NV>, 1>, 
                                    parameter::plain<dlay_impl::pma29_t<NV>, 1>>;

template <int NV>
using SHIn = parameter::chain<ranges::Identity, 
                              parameter::plain<dlay_impl::branch18_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch26_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch25_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch24_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch23_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch22_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch21_t<NV>, 0>, 
                              parameter::plain<dlay_impl::branch20_t<NV>, 0>>;

template <int NV>
using ShMix_0 = parameter::from0To1<core::gain<NV>, 
                                    0, 
                                    dlay_impl::xfader_c0Range>;

template <int NV> using ShMix_1 = ShMix_0<NV>;

template <int NV> using ShMix_2 = ShMix_0<NV>;

template <int NV> using ShMix_3 = ShMix_0<NV>;

template <int NV> using ShMix_4 = ShMix_0<NV>;

template <int NV> using ShMix_5 = ShMix_0<NV>;

template <int NV> using ShMix_6 = ShMix_0<NV>;

template <int NV> using ShMix_7 = ShMix_0<NV>;

template <int NV>
using ShMix = parameter::chain<ranges::Identity, 
                               ShMix_0<NV>, 
                               ShMix_1<NV>, 
                               ShMix_2<NV>, 
                               ShMix_3<NV>, 
                               ShMix_4<NV>, 
                               ShMix_5<NV>, 
                               ShMix_6<NV>, 
                               ShMix_7<NV>>;

DECLARE_PARAMETER_RANGE_STEP(MultiFtype_InputRange, 
                             0., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(MultiFtype_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using MultiFtype_0 = parameter::from0To1<filters::svf<NV>, 
                                         4, 
                                         MultiFtype_0Range>;

template <int NV> using MultiFtype_1 = MultiFtype_0<NV>;

template <int NV> using MultiFtype_2 = MultiFtype_0<NV>;

template <int NV> using MultiFtype_3 = MultiFtype_0<NV>;

template <int NV> using MultiFtype_4 = MultiFtype_0<NV>;

template <int NV> using MultiFtype_5 = MultiFtype_0<NV>;

template <int NV> using MultiFtype_6 = MultiFtype_0<NV>;

template <int NV>
using MultiFtype = parameter::chain<MultiFtype_InputRange, 
                                    MultiFtype_0<NV>, 
                                    MultiFtype_1<NV>, 
                                    MultiFtype_2<NV>, 
                                    MultiFtype_3<NV>, 
                                    MultiFtype_4<NV>, 
                                    MultiFtype_5<NV>, 
                                    MultiFtype_6<NV>>;

template <int NV>
using mod = parameter::chain<ranges::Identity, 
                             parameter::plain<dlay_impl::pma_t<NV>, 1>, 
                             parameter::plain<dlay_impl::pma1_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(MODSRC_InputRange, 
                             0., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(MODSRC_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using MODSRC_0 = parameter::from0To1<dlay_impl::branch28_t<NV>, 
                                     0, 
                                     MODSRC_0Range>;

template <int NV>
using MODSRC = parameter::chain<MODSRC_InputRange, MODSRC_0<NV>>;

template <int NV>
using Mix = parameter::plain<dlay_impl::xfader_t<NV>, 
                             0>;
template <int NV>
using Mode = parameter::plain<dlay_impl::branch3_t<NV>, 
                              0>;
template <int NV>
using PingPong = parameter::plain<dlay_impl::branch9_t<NV>, 
                                  0>;
template <int NV>
using GranPos = parameter::plain<project::granular<NV>, 0>;
template <int NV>
using GranPitch = parameter::plain<project::granular<NV>, 3>;
template <int NV>
using dlay_t_plist = parameter::list<Mix<NV>, 
                                     Feedback<NV>, 
                                     Mode<NV>, 
                                     Sync<NV>, 
                                     DTime<NV>, 
                                     Reverse<NV>, 
                                     DtimeR<NV>, 
                                     PingPong<NV>, 
                                     Tone<NV>, 
                                     GranPos<NV>, 
                                     GranPitch<NV>, 
                                     Div<NV>, 
                                     MultiRes<NV>, 
                                     MultiDelSH<NV>, 
                                     MultiCutSH<NV>, 
                                     SHIn<NV>, 
                                     ShMix<NV>, 
                                     MultiFtype<NV>, 
                                     mod<NV>, 
                                     MODSRC<NV>>;
}

template <int NV>
using dlay_t_ = container::chain<dlay_t_parameters::dlay_t_plist<NV>, 
                                 wrap::fix<2, xfader_t<NV>>, 
                                 split_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public dlay_impl::dlay_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 2;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(dlay);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(324)
		{
			0x005B, 0x0000, 0x4D00, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 
            0xDB3F, 0x0752, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x6546, 0x6465, 0x6162, 0x6B63, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xF33F, 0x4A8B, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0002, 0x0000, 0x6F4D, 0x6564, 0x0000, 0x0000, 0x0000, 0xA000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0003, 
            0x0000, 0x7953, 0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0004, 0x0000, 
            0x5444, 0x6D69, 0x0065, 0x0000, 0x2480, 0x0000, 0x3F80, 0x88F8, 
            0x3EA5, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 0x5200, 
            0x7665, 0x7265, 0x6573, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 
            0x7444, 0x6D69, 0x5265, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 
            0x6950, 0x676E, 0x6F50, 0x676E, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0008, 
            0x0000, 0x6F54, 0x656E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0xDF3F, 0x8E04, 0x003E, 0x0000, 0x5B00, 0x0009, 0x0000, 
            0x7247, 0x6E61, 0x6F50, 0x0073, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0A3E, 0x3ED7, 0x0000, 0x3F80, 0x126F, 0x3A83, 0x0A5B, 0x0000, 
            0x4700, 0x6172, 0x506E, 0x7469, 0x6863, 0x0000, 0x0000, 0x003E, 
            0x8000, 0x0040, 0x8000, 0x0040, 0x8000, 0x6F3F, 0x8312, 0x5B3A, 
            0x000B, 0x0000, 0x6944, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4180, 
            0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0C5B, 0x0000, 
            0x4D00, 0x6C75, 0x6974, 0x6552, 0x0073, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xA3D7, 0x3EF0, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0D5B, 
            0x0000, 0x4D00, 0x6C75, 0x6974, 0x6544, 0x536C, 0x0048, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x1EB8, 0x3F05, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0E5B, 0x0000, 0x4D00, 0x6C75, 0x6974, 0x7543, 0x5374, 
            0x0048, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0F5B, 0x0000, 0x5300, 0x4948, 0x006E, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x105B, 0x0000, 0x5300, 0x4D68, 0x7869, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x0A3F, 0x23D7, 0x003C, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0011, 0x0000, 0x754D, 0x746C, 0x4669, 0x7974, 
            0x6570, 0x0000, 0x0000, 0x0000, 0xA000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0012, 0x0000, 0x6F6D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x135B, 0x0000, 0x4D00, 0x444F, 0x5253, 0x0043, 
            0x0000, 0x0000, 0x0000, 0x4080, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& xfader = this->getT(0);                                                        // dlay_impl::xfader_t<NV>
		auto& split = this->getT(1);                                                         // dlay_impl::split_t<NV>
		auto& chain2 = this->getT(1).getT(0);                                                // dlay_impl::chain2_t<NV>
		auto& gain = this->getT(1).getT(0).getT(0);                                          // core::gain<NV>
		auto& chain3 = this->getT(1).getT(1);                                                // dlay_impl::chain3_t<NV>
		auto& modchain1 = this->getT(1).getT(1).getT(0);                                     // dlay_impl::modchain1_t<NV>
		auto& chain51 = this->getT(1).getT(1).getT(0).getT(0);                               // dlay_impl::chain51_t<NV>
		auto& branch28 = this->getT(1).getT(1).getT(0).getT(0).getT(0);                      // dlay_impl::branch28_t<NV>
		auto& chain47 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(0);               // dlay_impl::chain47_t<NV>
		auto& global_cable = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);  // dlay_impl::global_cable_t<NV>
		auto& add = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain50 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(1);               // dlay_impl::chain50_t<NV>
		auto& global_cable3 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(1).getT(0); // dlay_impl::global_cable3_t<NV>
		auto& add3 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain49 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(2);               // dlay_impl::chain49_t<NV>
		auto& global_cable2 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(2).getT(0); // dlay_impl::global_cable2_t<NV>
		auto& add2 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain48 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(3);               // dlay_impl::chain48_t<NV>
		auto& global_cable1 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(3).getT(0); // dlay_impl::global_cable1_t<NV>
		auto& add1 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& peak1 = this->getT(1).getT(1).getT(0).getT(0).getT(1);                         // dlay_impl::peak1_t<NV>
		auto& split3 = this->getT(1).getT(1).getT(0).getT(1);                                // dlay_impl::split3_t<NV>
		auto& chain34 = this->getT(1).getT(1).getT(0).getT(1).getT(0);                       // dlay_impl::chain34_t<NV>
		auto& pma = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(0);                   // dlay_impl::pma_t<NV>
		auto& minmax = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(1);                // dlay_impl::minmax_t<NV>
		auto& tempo_sync3 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(2);           // dlay_impl::tempo_sync3_t<NV>
		auto& chain35 = this->getT(1).getT(1).getT(0).getT(1).getT(1);                       // dlay_impl::chain35_t<NV>
		auto& pma1 = this->getT(1).getT(1).getT(0).getT(1).getT(1).getT(0);                  // dlay_impl::pma1_t<NV>
		auto& minmax2 = this->getT(1).getT(1).getT(0).getT(1).getT(1).getT(1);               // dlay_impl::minmax2_t<NV>
		auto& tempo_sync = this->getT(1).getT(1).getT(0).getT(1).getT(1).getT(2);            // dlay_impl::tempo_sync_t<NV>
		auto& branch3 = this->getT(1).getT(1).getT(1);                                       // dlay_impl::branch3_t<NV>
		auto& chain8 = this->getT(1).getT(1).getT(1).getT(0);                                // dlay_impl::chain8_t<NV>
		auto& receive = this->getT(1).getT(1).getT(1).getT(0).getT(0);                       // routing::receive<stereo_cable>
		auto& chain6 = this->getT(1).getT(1).getT(1).getT(0).getT(1);                        // dlay_impl::chain6_t<NV>
		auto& fix_delay = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(0);             // core::fix_delay
		auto& svf = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(1);                   // filters::svf<NV>
		auto& branch1 = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(2);               // dlay_impl::branch1_t<NV>
		auto& chain4 = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(2).getT(0);        // dlay_impl::chain4_t
		auto& chain5 = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(2).getT(1);        // dlay_impl::chain5_t<NV>
		auto& branch = this->getT(1).getT(1).getT(1).getT(0).                                // dlay_impl::branch_t<NV>
                       getT(1).getT(2).getT(1).getT(0);
		auto& chain = this->getT(1).getT(1).getT(1).getT(0).                              // dlay_impl::chain_t<NV>
                      getT(1).getT(2).getT(1).getT(0).
                      getT(0);
		auto& faust6 = this->getT(1).getT(1).getT(1).getT(0).getT(1).                     // project::klp2<NV>
                       getT(2).getT(1).getT(0).getT(0).getT(0);
		auto& chain1 = this->getT(1).getT(1).getT(1).getT(0).                             // dlay_impl::chain1_t<NV>
                       getT(1).getT(2).getT(1).getT(0).
                       getT(1);
		auto& faust7 = this->getT(1).getT(1).getT(1).getT(0).getT(1).                     // project::klp2<NV>
                       getT(2).getT(1).getT(0).getT(1).getT(0);
		auto& comp = this->getT(1).getT(1).getT(1).getT(0).                               // dlay_impl::comp_t
                     getT(1).getT(2).getT(1).getT(1);
		auto& send = this->getT(1).getT(1).getT(1).getT(0).                               // routing::send<stereo_cable>
                     getT(1).getT(2).getT(1).getT(2);
		auto& gain2 = this->getT(1).getT(1).getT(1).getT(0).                              // core::gain<NV>
                      getT(1).getT(2).getT(1).getT(3);
		auto& dynamic_blocksize1 = this->getT(1).getT(1).getT(1).getT(1);                 // dlay_impl::dynamic_blocksize1_t<NV>
		auto& chain13 = this->getT(1).getT(1).getT(1).getT(1).getT(0);                    // dlay_impl::chain13_t<NV>
		auto& branch9 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0);            // dlay_impl::branch9_t<NV>
		auto& split1 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).getT(0);     // dlay_impl::split1_t<NV>
		auto& chain22 = this->getT(1).getT(1).getT(1).getT(1).                            // dlay_impl::chain22_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& receive1 = this->getT(1).getT(1).getT(1).getT(1).                           // routing::receive<stereo_cable>
                         getT(0).getT(0).getT(0).getT(0).
                         getT(0);
		auto& smoothed_parameter_unscaled7 = this->getT(1).getT(1).getT(1).getT(1).       // dlay_impl::smoothed_parameter_unscaled7_t<NV>
                                             getT(0).getT(0).getT(0).getT(0).
                                             getT(1);
		auto& jdelay_thiran1 = this->getT(1).getT(1).getT(1).getT(1).                     // jdsp::jdelay_thiran<NV>
                               getT(0).getT(0).getT(0).getT(0).
                               getT(2);
		auto& one_pole3 = this->getT(1).getT(1).getT(1).getT(1).                          // filters::one_pole<NV>
                          getT(0).getT(0).getT(0).getT(0).
                          getT(3);
		auto& branch7 = this->getT(1).getT(1).getT(1).getT(1).                            // dlay_impl::branch7_t<NV>
                        getT(0).getT(0).getT(0).getT(0).
                        getT(4);
		auto& chain19 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain19_t
                        getT(0).getT(0).getT(0).getT(4).getT(0);
		auto& branch8 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::branch8_t<NV>
                        getT(0).getT(0).getT(0).getT(4).getT(1);
		auto& chain20 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain20_t<NV>
                        getT(0).getT(0).getT(0).getT(4).getT(1).
                        getT(0);
		auto& faust2 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).             // project::klp2<NV>
                       getT(0).getT(0).getT(4).getT(1).getT(0).getT(0);
		auto& chain21 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain21_t<NV>
                        getT(0).getT(0).getT(0).getT(4).getT(1).
                        getT(1);
		auto& faust3 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).             // project::klp2<NV>
                       getT(0).getT(0).getT(4).getT(1).getT(1).getT(0);
		auto& send1 = this->getT(1).getT(1).getT(1).getT(1).                              // routing::send<stereo_cable>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(5);
		auto& jpanner = this->getT(1).getT(1).getT(1).getT(1).                            // jdsp::jpanner<NV>
                        getT(0).getT(0).getT(0).getT(0).
                        getT(6);
		auto& chain15 = this->getT(1).getT(1).getT(1).getT(1).                            // dlay_impl::chain15_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& receive2 = this->getT(1).getT(1).getT(1).getT(1).                           // routing::receive<stereo_cable>
                         getT(0).getT(0).getT(0).getT(1).
                         getT(0);
		auto& smoothed_parameter_unscaled10 = this->getT(1).getT(1).getT(1).getT(1).      // dlay_impl::smoothed_parameter_unscaled10_t<NV>
                                              getT(0).getT(0).getT(0).getT(1).
                                              getT(1);
		auto& jdelay_thiran4 = this->getT(1).getT(1).getT(1).getT(1).                     // jdsp::jdelay_thiran<NV>
                               getT(0).getT(0).getT(0).getT(1).
                               getT(2);
		auto& one_pole4 = this->getT(1).getT(1).getT(1).getT(1).                          // filters::one_pole<NV>
                          getT(0).getT(0).getT(0).getT(1).
                          getT(3);
		auto& branch10 = this->getT(1).getT(1).getT(1).getT(1).                           // dlay_impl::branch10_t<NV>
                         getT(0).getT(0).getT(0).getT(1).
                         getT(4);
		auto& chain25 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain25_t
                        getT(0).getT(0).getT(1).getT(4).getT(0);
		auto& branch11 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                   // dlay_impl::branch11_t<NV>
                         getT(0).getT(0).getT(1).getT(4).getT(1);
		auto& chain26 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain26_t<NV>
                        getT(0).getT(0).getT(1).getT(4).getT(1).
                        getT(0);
		auto& faust11 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).            // project::klp2<NV>
                        getT(0).getT(1).getT(4).getT(1).getT(0).getT(0);
		auto& chain27 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain27_t<NV>
                        getT(0).getT(0).getT(1).getT(4).getT(1).
                        getT(1);
		auto& faust12 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).            // project::klp2<NV>
                        getT(0).getT(1).getT(4).getT(1).getT(1).getT(0);
		auto& send2 = this->getT(1).getT(1).getT(1).getT(1).                              // routing::send<stereo_cable>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(5);
		auto& jpanner1 = this->getT(1).getT(1).getT(1).getT(1).                           // jdsp::jpanner<NV>
                         getT(0).getT(0).getT(0).getT(1).
                         getT(6);
		auto& split2 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).getT(1);     // dlay_impl::split2_t<NV>
		auto& chain23 = this->getT(1).getT(1).getT(1).getT(1).                            // dlay_impl::chain23_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& receive3 = this->getT(1).getT(1).getT(1).getT(1).                           // routing::receive<stereo_cable>
                         getT(0).getT(0).getT(1).getT(0).
                         getT(0);
		auto& smoothed_parameter_unscaled9 = this->getT(1).getT(1).getT(1).getT(1).       // dlay_impl::smoothed_parameter_unscaled9_t<NV>
                                             getT(0).getT(0).getT(1).getT(0).
                                             getT(1);
		auto& jdelay_thiran3 = this->getT(1).getT(1).getT(1).getT(1).                     // jdsp::jdelay_thiran<NV>
                               getT(0).getT(0).getT(1).getT(0).
                               getT(2);
		auto& one_pole5 = this->getT(1).getT(1).getT(1).getT(1).                          // filters::one_pole<NV>
                          getT(0).getT(0).getT(1).getT(0).
                          getT(3);
		auto& branch14 = this->getT(1).getT(1).getT(1).getT(1).                           // dlay_impl::branch14_t<NV>
                         getT(0).getT(0).getT(1).getT(0).
                         getT(4);
		auto& chain31 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain31_t
                        getT(0).getT(1).getT(0).getT(4).getT(0);
		auto& branch15 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                   // dlay_impl::branch15_t<NV>
                         getT(0).getT(1).getT(0).getT(4).getT(1);
		auto& chain32 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain32_t<NV>
                        getT(0).getT(1).getT(0).getT(4).getT(1).
                        getT(0);
		auto& faust15 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).            // project::klp2<NV>
                        getT(1).getT(0).getT(4).getT(1).getT(0).getT(0);
		auto& chain33 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain33_t<NV>
                        getT(0).getT(1).getT(0).getT(4).getT(1).
                        getT(1);
		auto& faust16 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).            // project::klp2<NV>
                        getT(1).getT(0).getT(4).getT(1).getT(1).getT(0);
		auto& send3 = this->getT(1).getT(1).getT(1).getT(1).                              // routing::send<stereo_cable>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(5);
		auto& jpanner2 = this->getT(1).getT(1).getT(1).getT(1).                           // jdsp::jpanner<NV>
                         getT(0).getT(0).getT(1).getT(0).
                         getT(6);
		auto& chain24 = this->getT(1).getT(1).getT(1).getT(1).                            // dlay_impl::chain24_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& receive4 = this->getT(1).getT(1).getT(1).getT(1).                           // routing::receive<stereo_cable>
                         getT(0).getT(0).getT(1).getT(1).
                         getT(0);
		auto& smoothed_parameter_unscaled11 = this->getT(1).getT(1).getT(1).getT(1).      // dlay_impl::smoothed_parameter_unscaled11_t<NV>
                                              getT(0).getT(0).getT(1).getT(1).
                                              getT(1);
		auto& jdelay_thiran2 = this->getT(1).getT(1).getT(1).getT(1).                     // jdsp::jdelay_thiran<NV>
                               getT(0).getT(0).getT(1).getT(1).
                               getT(2);
		auto& one_pole6 = this->getT(1).getT(1).getT(1).getT(1).                          // filters::one_pole<NV>
                          getT(0).getT(0).getT(1).getT(1).
                          getT(3);
		auto& branch12 = this->getT(1).getT(1).getT(1).getT(1).                           // dlay_impl::branch12_t<NV>
                         getT(0).getT(0).getT(1).getT(1).
                         getT(4);
		auto& chain28 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain28_t
                        getT(0).getT(1).getT(1).getT(4).getT(0);
		auto& branch13 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                   // dlay_impl::branch13_t<NV>
                         getT(0).getT(1).getT(1).getT(4).getT(1);
		auto& chain29 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain29_t<NV>
                        getT(0).getT(1).getT(1).getT(4).getT(1).
                        getT(0);
		auto& faust13 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).            // project::klp2<NV>
                        getT(1).getT(1).getT(4).getT(1).getT(0).getT(0);
		auto& chain30 = this->getT(1).getT(1).getT(1).getT(1).getT(0).                    // dlay_impl::chain30_t<NV>
                        getT(0).getT(1).getT(1).getT(4).getT(1).
                        getT(1);
		auto& faust14 = this->getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).            // project::klp2<NV>
                        getT(1).getT(1).getT(4).getT(1).getT(1).getT(0);
		auto& send4 = this->getT(1).getT(1).getT(1).getT(1).                              // routing::send<stereo_cable>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(5);
		auto& jpanner3 = this->getT(1).getT(1).getT(1).getT(1).                           // jdsp::jpanner<NV>
                         getT(0).getT(0).getT(1).getT(1).
                         getT(6);
		auto& chain36 = this->getT(1).getT(1).getT(1).getT(2);                            // dlay_impl::chain36_t<NV>
		auto& dynamic_blocksize = this->getT(1).getT(1).getT(1).getT(2).getT(0);          // dlay_impl::dynamic_blocksize_t<NV>
		auto& smoothed_parameter = this->getT(1).getT(1).getT(1).getT(2).getT(0).getT(0); // dlay_impl::smoothed_parameter_t<NV>
		auto& receive6 = this->getT(1).getT(1).getT(1).getT(2).getT(0).getT(1);           // routing::receive<stereo_cable>
		auto& jdelay_thiran = this->getT(1).getT(1).getT(1).getT(2).getT(0).getT(2);      // jdsp::jdelay_thiran<NV>
		auto& fix_delay1 = this->getT(1).getT(1).getT(1).getT(2).getT(0).getT(3);         // wrap::no_process<core::fix_delay>
		auto& one_pole = this->getT(1).getT(1).getT(1).getT(2).getT(0).getT(4);           // filters::one_pole<NV>
		auto& send6 = this->getT(1).getT(1).getT(1).getT(2).getT(0).getT(5);              // routing::send<stereo_cable>
		auto& branch16 = this->getT(1).getT(1).getT(1).getT(2).getT(1);                   // dlay_impl::branch16_t<NV>
		auto& chain37 = this->getT(1).getT(1).getT(1).getT(2).getT(1).getT(0);            // dlay_impl::chain37_t
		auto& chain38 = this->getT(1).getT(1).getT(1).getT(2).getT(1).getT(1);            // dlay_impl::chain38_t<NV>
		auto& branch17 = this->getT(1).getT(1).getT(1).getT(2).getT(1).getT(1).getT(0);   // dlay_impl::branch17_t<NV>
		auto& chain39 = this->getT(1).getT(1).getT(1).getT(2).                            // dlay_impl::chain39_t<NV>
                        getT(1).getT(1).getT(0).getT(0);
		auto& faust18 = this->getT(1).getT(1).getT(1).getT(2).                            // project::klp2<NV>
                        getT(1).getT(1).getT(0).getT(0).
                        getT(0);
		auto& chain40 = this->getT(1).getT(1).getT(1).getT(2).                            // dlay_impl::chain40_t<NV>
                        getT(1).getT(1).getT(0).getT(1);
		auto& faust19 = this->getT(1).getT(1).getT(1).getT(2).                            // project::klp2<NV>
                        getT(1).getT(1).getT(0).getT(1).
                        getT(0);
		auto& gain4 = this->getT(1).getT(1).getT(1).getT(2).getT(1).getT(1).getT(1);      // core::gain<NV>
		auto& chain9 = this->getT(1).getT(1).getT(1).getT(3);                             // dlay_impl::chain9_t<NV>
		auto& minmax1 = this->getT(1).getT(1).getT(1).getT(3).getT(0);                    // dlay_impl::minmax1_t<NV>
		auto& faust8 = this->getT(1).getT(1).getT(1).getT(3).getT(1);                     // project::RevDel<NV>
		auto& one_pole1 = this->getT(1).getT(1).getT(1).getT(3).getT(2);                  // filters::one_pole<NV>
		auto& branch2 = this->getT(1).getT(1).getT(1).getT(3).getT(3);                    // dlay_impl::branch2_t<NV>
		auto& chain7 = this->getT(1).getT(1).getT(1).getT(3).getT(3).getT(0);             // dlay_impl::chain7_t
		auto& chain10 = this->getT(1).getT(1).getT(1).getT(3).getT(3).getT(1);            // dlay_impl::chain10_t<NV>
		auto& branch4 = this->getT(1).getT(1).getT(1).getT(3).getT(3).getT(1).getT(0);    // dlay_impl::branch4_t<NV>
		auto& chain11 = this->getT(1).getT(1).getT(1).getT(3).                            // dlay_impl::chain11_t<NV>
                        getT(3).getT(1).getT(0).getT(0);
		auto& faust9 = this->getT(1).getT(1).getT(1).getT(3).                             // project::klp2<NV>
                       getT(3).getT(1).getT(0).getT(0).
                       getT(0);
		auto& chain12 = this->getT(1).getT(1).getT(1).getT(3).                            // dlay_impl::chain12_t<NV>
                        getT(3).getT(1).getT(0).getT(1);
		auto& faust10 = this->getT(1).getT(1).getT(1).getT(3).                            // project::klp2<NV>
                        getT(3).getT(1).getT(0).getT(1).
                        getT(0);
		auto& gain3 = this->getT(1).getT(1).getT(1).getT(3).getT(3).getT(1).getT(1);      // core::gain<NV>
		auto& chain14 = this->getT(1).getT(1).getT(1).getT(4);                            // dlay_impl::chain14_t<NV>
		auto& faust = this->getT(1).getT(1).getT(1).getT(4).getT(0);                      // project::granular<NV>
		auto& one_pole2 = this->getT(1).getT(1).getT(1).getT(4).getT(1);                  // filters::one_pole<NV>
		auto& branch5 = this->getT(1).getT(1).getT(1).getT(4).getT(2);                    // dlay_impl::branch5_t<NV>
		auto& chain16 = this->getT(1).getT(1).getT(1).getT(4).getT(2).getT(0);            // dlay_impl::chain16_t
		auto& branch6 = this->getT(1).getT(1).getT(1).getT(4).getT(2).getT(1);            // dlay_impl::branch6_t<NV>
		auto& chain41 = this->getT(1).getT(1).getT(1).getT(4).getT(2).getT(1).getT(0);    // dlay_impl::chain41_t<NV>
		auto& faust1 = this->getT(1).getT(1).getT(1).getT(4).                             // project::klp2<NV>
                       getT(2).getT(1).getT(0).getT(0);
		auto& chain42 = this->getT(1).getT(1).getT(1).getT(4).getT(2).getT(1).getT(1);    // dlay_impl::chain42_t<NV>
		auto& faust4 = this->getT(1).getT(1).getT(1).getT(4).                             // project::klp2<NV>
                       getT(2).getT(1).getT(1).getT(0);
		auto& chain17 = this->getT(1).getT(1).getT(1).getT(5);                            // dlay_impl::chain17_t<NV>
		auto& modchain = this->getT(1).getT(1).getT(1).getT(5).getT(0);                   // dlay_impl::modchain_t<NV>
		auto& sliderbank = this->getT(1).getT(1).getT(1).getT(5).getT(0).getT(0);         // dlay_impl::sliderbank_t<NV>
		auto& sliderbank1 = this->getT(1).getT(1).getT(1).getT(5).getT(0).getT(1);        // dlay_impl::sliderbank1_t<NV>
		auto& split10 = this->getT(1).getT(1).getT(1).getT(5).getT(1);                    // dlay_impl::split10_t<NV>
		auto& chain18 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(0);            // dlay_impl::chain18_t<NV>
		auto& receive7 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(0).getT(0);   // routing::receive<stereo_cable>
		auto& split6 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(0).getT(1);     // dlay_impl::split6_t<NV>
		auto& chain58 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain58_t
                        getT(1).getT(0).getT(1).getT(0);
		auto& chain59 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain59_t<NV>
                        getT(1).getT(0).getT(1).getT(1);
		auto& tempo_sync9 = this->getT(1).getT(1).getT(1).getT(5).                        // dlay_impl::tempo_sync9_t<NV>
                            getT(1).getT(0).getT(1).getT(1).
                            getT(0);
		auto& branch18 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::branch18_t<NV>
                         getT(1).getT(0).getT(1).getT(1).
                         getT(1);
		auto& chain60 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::chain60_t<NV>
                        getT(0).getT(1).getT(1).getT(1).getT(0);
		auto& clear4 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                     // wrap::no_process<math::clear<NV>>
                       getT(0).getT(1).getT(1).getT(1).getT(0).
                       getT(0);
		auto& chain61 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::chain61_t<NV>
                        getT(0).getT(1).getT(1).getT(1).getT(1);
		auto& clear2 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                     // wrap::no_process<math::clear<NV>>
                       getT(0).getT(1).getT(1).getT(1).getT(1).
                       getT(0);
		auto& oscillator = this->getT(1).getT(1).getT(1).getT(5).getT(1).                 // dlay_impl::oscillator_t<NV>
                           getT(0).getT(1).getT(1).getT(1).getT(1).
                           getT(1);
		auto& sampleandhold = this->getT(1).getT(1).getT(1).getT(5).                      // fx::sampleandhold<NV>
                              getT(1).getT(0).getT(1).getT(1).
                              getT(2);
		auto& peak = this->getT(1).getT(1).getT(1).getT(5).                               // dlay_impl::peak_t<NV>
                     getT(1).getT(0).getT(1).getT(1).
                     getT(3);
		auto& gain6 = this->getT(1).getT(1).getT(1).getT(5).                              // core::gain<NV>
                      getT(1).getT(0).getT(1).getT(1).
                      getT(4);
		auto& modchain2 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(0).getT(2);  // dlay_impl::modchain2_t<NV>
		auto& split8 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::split8_t<NV>
                       getT(1).getT(0).getT(2).getT(0);
		auto& pma17 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma17_t<NV>
                      getT(1).getT(0).getT(2).getT(0).
                      getT(0);
		auto& pma18 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma18_t<NV>
                      getT(1).getT(0).getT(2).getT(0).
                      getT(1);
		auto& split4 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(0).getT(3);     // dlay_impl::split4_t<NV>
		auto& chain43 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain43_t<NV>
                        getT(1).getT(0).getT(3).getT(0);
		auto& tempo_sync2 = this->getT(1).getT(1).getT(1).getT(5).                        // dlay_impl::tempo_sync2_t<NV>
                            getT(1).getT(0).getT(3).getT(0).
                            getT(0);
		auto& smoothed_parameter_unscaled = this->getT(1).getT(1).getT(1).getT(5).        // dlay_impl::smoothed_parameter_unscaled_t<NV>
                                            getT(1).getT(0).getT(3).getT(0).
                                            getT(1);
		auto& fix_delay2 = this->getT(1).getT(1).getT(1).getT(5).                         // core::fix_delay
                           getT(1).getT(0).getT(3).getT(0).
                           getT(2);
		auto& pma2 = this->getT(1).getT(1).getT(1).getT(5).                               // dlay_impl::pma2_t<NV>
                     getT(1).getT(0).getT(3).getT(0).
                     getT(3);
		auto& cable_table = this->getT(1).getT(1).getT(1).getT(5).                        // dlay_impl::cable_table_t<NV>
                            getT(1).getT(0).getT(3).getT(0).
                            getT(4);
		auto& cable_table1 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::cable_table1_t
                             getT(1).getT(0).getT(3).getT(0).
                             getT(5);
		auto& modchain3 = this->getT(1).getT(1).getT(1).getT(5).                          // dlay_impl::modchain3_t<NV>
                          getT(1).getT(0).getT(3).getT(0).
                          getT(6);
		auto& split9 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                     // dlay_impl::split9_t<NV>
                       getT(0).getT(3).getT(0).getT(6).getT(0);
		auto& pma19 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                      // dlay_impl::pma19_t<NV>
                      getT(0).getT(3).getT(0).getT(6).getT(0).
                      getT(0);
		auto& pma20 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                      // dlay_impl::pma20_t<NV>
                      getT(0).getT(3).getT(0).getT(6).getT(0).
                      getT(1);
		auto& svf1 = this->getT(1).getT(1).getT(1).getT(5).                               // filters::svf<NV>
                     getT(1).getT(0).getT(3).getT(0).
                     getT(7);
		auto& comp1 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::comp1_t
                      getT(1).getT(0).getT(3).getT(0).
                      getT(8);
		auto& gain5 = this->getT(1).getT(1).getT(1).getT(5).                              // core::gain<NV>
                      getT(1).getT(0).getT(3).getT(0).
                      getT(9);
		auto& send7 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(0).getT(4);      // routing::send<stereo_cable>
		auto& chain104 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(1);           // dlay_impl::chain104_t<NV>
		auto& receive15 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(1).getT(0);  // routing::receive<stereo_cable>
		auto& split39 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(1).getT(1);    // dlay_impl::split39_t<NV>
		auto& chain105 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain105_t
                         getT(1).getT(1).getT(1).getT(0);
		auto& chain106 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain106_t<NV>
                         getT(1).getT(1).getT(1).getT(1);
		auto& tempo_sync24 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::tempo_sync24_t<NV>
                             getT(1).getT(1).getT(1).getT(1).
                             getT(0);
		auto& branch26 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::branch26_t<NV>
                         getT(1).getT(1).getT(1).getT(1).
                         getT(1);
		auto& chain107 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::chain107_t<NV>
                         getT(1).getT(1).getT(1).getT(1).getT(0);
		auto& clear33 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                        getT(1).getT(1).getT(1).getT(1).getT(0).
                        getT(0);
		auto& chain108 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::chain108_t<NV>
                         getT(1).getT(1).getT(1).getT(1).getT(1);
		auto& clear34 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // math::clear<NV>
                        getT(1).getT(1).getT(1).getT(1).getT(1).
                        getT(0);
		auto& oscillator8 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                // dlay_impl::oscillator8_t<NV>
                            getT(1).getT(1).getT(1).getT(1).getT(1).
                            getT(1);
		auto& clear35 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                        getT(1).getT(1).getT(1).getT(1).getT(1).
                        getT(2);
		auto& sampleandhold8 = this->getT(1).getT(1).getT(1).getT(5).                     // fx::sampleandhold<NV>
                               getT(1).getT(1).getT(1).getT(1).
                               getT(2);
		auto& peak8 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::peak8_t<NV>
                      getT(1).getT(1).getT(1).getT(1).
                      getT(3);
		auto& gain7 = this->getT(1).getT(1).getT(1).getT(5).                              // core::gain<NV>
                      getT(1).getT(1).getT(1).getT(1).
                      getT(4);
		auto& modchain18 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(1).getT(2); // dlay_impl::modchain18_t<NV>
		auto& split40 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::split40_t<NV>
                        getT(1).getT(1).getT(2).getT(0);
		auto& pma56 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma56_t<NV>
                      getT(1).getT(1).getT(2).getT(0).
                      getT(0);
		auto& pma57 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma57_t<NV>
                      getT(1).getT(1).getT(2).getT(0).
                      getT(1);
		auto& split41 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(1).getT(3);    // dlay_impl::split41_t<NV>
		auto& chain109 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain109_t<NV>
                         getT(1).getT(1).getT(3).getT(0);
		auto& tempo_sync25 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::tempo_sync25_t<NV>
                             getT(1).getT(1).getT(3).getT(0).
                             getT(0);
		auto& smoothed_parameter_unscaled1 = this->getT(1).getT(1).getT(1).getT(5).       // dlay_impl::smoothed_parameter_unscaled1_t<NV>
                                             getT(1).getT(1).getT(3).getT(0).
                                             getT(1);
		auto& fix_delay24 = this->getT(1).getT(1).getT(1).getT(5).                        // core::fix_delay
                            getT(1).getT(1).getT(3).getT(0).
                            getT(2);
		auto& pma58 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma58_t<NV>
                      getT(1).getT(1).getT(3).getT(0).
                      getT(3);
		auto& cable_table44 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::cable_table44_t<NV>
                              getT(1).getT(1).getT(3).getT(0).
                              getT(4);
		auto& cable_table45 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::cable_table45_t
                              getT(1).getT(1).getT(3).getT(0).
                              getT(5);
		auto& modchain19 = this->getT(1).getT(1).getT(1).getT(5).                         // dlay_impl::modchain19_t<NV>
                           getT(1).getT(1).getT(3).getT(0).
                           getT(6);
		auto& split42 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::split42_t<NV>
                        getT(1).getT(3).getT(0).getT(6).getT(0);
		auto& pma59 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                      // dlay_impl::pma59_t<NV>
                      getT(1).getT(3).getT(0).getT(6).getT(0).
                      getT(0);
		auto& pma60 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                      // dlay_impl::pma60_t<NV>
                      getT(1).getT(3).getT(0).getT(6).getT(0).
                      getT(1);
		auto& svf23 = this->getT(1).getT(1).getT(1).getT(5).                              // filters::svf<NV>
                      getT(1).getT(1).getT(3).getT(0).
                      getT(7);
		auto& comp23 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::comp23_t
                       getT(1).getT(1).getT(3).getT(0).
                       getT(8);
		auto& gain27 = this->getT(1).getT(1).getT(1).getT(5).                             // core::gain<NV>
                       getT(1).getT(1).getT(3).getT(0).
                       getT(9);
		auto& send15 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(1).getT(4);     // routing::send<stereo_cable>
		auto& chain98 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(2);            // dlay_impl::chain98_t<NV>
		auto& receive14 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(2).getT(0);  // routing::receive<stereo_cable>
		auto& split35 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(2).getT(1);    // dlay_impl::split35_t<NV>
		auto& chain99 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain99_t
                        getT(1).getT(2).getT(1).getT(0);
		auto& chain100 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain100_t<NV>
                         getT(1).getT(2).getT(1).getT(1);
		auto& tempo_sync22 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::tempo_sync22_t<NV>
                             getT(1).getT(2).getT(1).getT(1).
                             getT(0);
		auto& branch25 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::branch25_t<NV>
                         getT(1).getT(2).getT(1).getT(1).
                         getT(1);
		auto& chain101 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::chain101_t<NV>
                         getT(2).getT(1).getT(1).getT(1).getT(0);
		auto& clear29 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                        getT(2).getT(1).getT(1).getT(1).getT(0).
                        getT(0);
		auto& chain102 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::chain102_t<NV>
                         getT(2).getT(1).getT(1).getT(1).getT(1);
		auto& clear30 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // math::clear<NV>
                        getT(2).getT(1).getT(1).getT(1).getT(1).
                        getT(0);
		auto& oscillator7 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                // dlay_impl::oscillator7_t<NV>
                            getT(2).getT(1).getT(1).getT(1).getT(1).
                            getT(1);
		auto& clear31 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                        getT(2).getT(1).getT(1).getT(1).getT(1).
                        getT(2);
		auto& sampleandhold7 = this->getT(1).getT(1).getT(1).getT(5).                     // fx::sampleandhold<NV>
                               getT(1).getT(2).getT(1).getT(1).
                               getT(2);
		auto& peak7 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::peak7_t<NV>
                      getT(1).getT(2).getT(1).getT(1).
                      getT(3);
		auto& gain8 = this->getT(1).getT(1).getT(1).getT(5).                              // core::gain<NV>
                      getT(1).getT(2).getT(1).getT(1).
                      getT(4);
		auto& modchain16 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(2).getT(2); // dlay_impl::modchain16_t<NV>
		auto& split36 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::split36_t<NV>
                        getT(1).getT(2).getT(2).getT(0);
		auto& pma51 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma51_t<NV>
                      getT(1).getT(2).getT(2).getT(0).
                      getT(0);
		auto& pma52 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma52_t<NV>
                      getT(1).getT(2).getT(2).getT(0).
                      getT(1);
		auto& split37 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(2).getT(3);    // dlay_impl::split37_t<NV>
		auto& chain103 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain103_t<NV>
                         getT(1).getT(2).getT(3).getT(0);
		auto& tempo_sync23 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::tempo_sync23_t<NV>
                             getT(1).getT(2).getT(3).getT(0).
                             getT(0);
		auto& smoothed_parameter_unscaled6 = this->getT(1).getT(1).getT(1).getT(5).       // dlay_impl::smoothed_parameter_unscaled6_t<NV>
                                             getT(1).getT(2).getT(3).getT(0).
                                             getT(1);
		auto& fix_delay23 = this->getT(1).getT(1).getT(1).getT(5).                        // core::fix_delay
                            getT(1).getT(2).getT(3).getT(0).
                            getT(2);
		auto& pma53 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma53_t<NV>
                      getT(1).getT(2).getT(3).getT(0).
                      getT(3);
		auto& cable_table42 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::cable_table42_t<NV>
                              getT(1).getT(2).getT(3).getT(0).
                              getT(4);
		auto& cable_table43 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::cable_table43_t
                              getT(1).getT(2).getT(3).getT(0).
                              getT(5);
		auto& modchain17 = this->getT(1).getT(1).getT(1).getT(5).                         // dlay_impl::modchain17_t<NV>
                           getT(1).getT(2).getT(3).getT(0).
                           getT(6);
		auto& split38 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::split38_t<NV>
                        getT(2).getT(3).getT(0).getT(6).getT(0);
		auto& pma54 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                      // dlay_impl::pma54_t<NV>
                      getT(2).getT(3).getT(0).getT(6).getT(0).
                      getT(0);
		auto& pma55 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                      // dlay_impl::pma55_t<NV>
                      getT(2).getT(3).getT(0).getT(6).getT(0).
                      getT(1);
		auto& svf22 = this->getT(1).getT(1).getT(1).getT(5).                              // filters::svf<NV>
                      getT(1).getT(2).getT(3).getT(0).
                      getT(7);
		auto& comp22 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::comp22_t
                       getT(1).getT(2).getT(3).getT(0).
                       getT(8);
		auto& gain26 = this->getT(1).getT(1).getT(1).getT(5).                             // core::gain<NV>
                       getT(1).getT(2).getT(3).getT(0).
                       getT(9);
		auto& send14 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(2).getT(4);     // routing::send<stereo_cable>
		auto& chain92 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(3);            // dlay_impl::chain92_t<NV>
		auto& receive13 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(3).getT(0);  // routing::receive<stereo_cable>
		auto& split31 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(3).getT(1);    // dlay_impl::split31_t<NV>
		auto& chain93 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain93_t
                        getT(1).getT(3).getT(1).getT(0);
		auto& chain94 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain94_t<NV>
                        getT(1).getT(3).getT(1).getT(1);
		auto& tempo_sync20 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::tempo_sync20_t<NV>
                             getT(1).getT(3).getT(1).getT(1).
                             getT(0);
		auto& branch24 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::branch24_t<NV>
                         getT(1).getT(3).getT(1).getT(1).
                         getT(1);
		auto& chain95 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::chain95_t<NV>
                        getT(3).getT(1).getT(1).getT(1).getT(0);
		auto& clear25 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                        getT(3).getT(1).getT(1).getT(1).getT(0).
                        getT(0);
		auto& chain96 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::chain96_t<NV>
                        getT(3).getT(1).getT(1).getT(1).getT(1);
		auto& clear26 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // math::clear<NV>
                        getT(3).getT(1).getT(1).getT(1).getT(1).
                        getT(0);
		auto& oscillator6 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                // dlay_impl::oscillator6_t<NV>
                            getT(3).getT(1).getT(1).getT(1).getT(1).
                            getT(1);
		auto& clear27 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                        getT(3).getT(1).getT(1).getT(1).getT(1).
                        getT(2);
		auto& sampleandhold6 = this->getT(1).getT(1).getT(1).getT(5).                     // fx::sampleandhold<NV>
                               getT(1).getT(3).getT(1).getT(1).
                               getT(2);
		auto& peak6 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::peak6_t<NV>
                      getT(1).getT(3).getT(1).getT(1).
                      getT(3);
		auto& gain9 = this->getT(1).getT(1).getT(1).getT(5).                              // core::gain<NV>
                      getT(1).getT(3).getT(1).getT(1).
                      getT(4);
		auto& modchain14 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(3).getT(2); // dlay_impl::modchain14_t<NV>
		auto& split32 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::split32_t<NV>
                        getT(1).getT(3).getT(2).getT(0);
		auto& pma46 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma46_t<NV>
                      getT(1).getT(3).getT(2).getT(0).
                      getT(0);
		auto& pma47 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma47_t<NV>
                      getT(1).getT(3).getT(2).getT(0).
                      getT(1);
		auto& split33 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(3).getT(3);    // dlay_impl::split33_t<NV>
		auto& chain97 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain97_t<NV>
                        getT(1).getT(3).getT(3).getT(0);
		auto& tempo_sync21 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::tempo_sync21_t<NV>
                             getT(1).getT(3).getT(3).getT(0).
                             getT(0);
		auto& smoothed_parameter_unscaled5 = this->getT(1).getT(1).getT(1).getT(5).       // dlay_impl::smoothed_parameter_unscaled5_t<NV>
                                             getT(1).getT(3).getT(3).getT(0).
                                             getT(1);
		auto& fix_delay22 = this->getT(1).getT(1).getT(1).getT(5).                        // core::fix_delay
                            getT(1).getT(3).getT(3).getT(0).
                            getT(2);
		auto& pma48 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma48_t<NV>
                      getT(1).getT(3).getT(3).getT(0).
                      getT(3);
		auto& cable_table40 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::cable_table40_t<NV>
                              getT(1).getT(3).getT(3).getT(0).
                              getT(4);
		auto& cable_table41 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::cable_table41_t
                              getT(1).getT(3).getT(3).getT(0).
                              getT(5);
		auto& modchain15 = this->getT(1).getT(1).getT(1).getT(5).                         // dlay_impl::modchain15_t<NV>
                           getT(1).getT(3).getT(3).getT(0).
                           getT(6);
		auto& split34 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::split34_t<NV>
                        getT(3).getT(3).getT(0).getT(6).getT(0);
		auto& pma49 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                      // dlay_impl::pma49_t<NV>
                      getT(3).getT(3).getT(0).getT(6).getT(0).
                      getT(0);
		auto& pma50 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                      // dlay_impl::pma50_t<NV>
                      getT(3).getT(3).getT(0).getT(6).getT(0).
                      getT(1);
		auto& svf21 = this->getT(1).getT(1).getT(1).getT(5).                              // filters::svf<NV>
                      getT(1).getT(3).getT(3).getT(0).
                      getT(7);
		auto& comp21 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::comp21_t
                       getT(1).getT(3).getT(3).getT(0).
                       getT(8);
		auto& gain25 = this->getT(1).getT(1).getT(1).getT(5).                             // core::gain<NV>
                       getT(1).getT(3).getT(3).getT(0).
                       getT(9);
		auto& send13 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(3).getT(4);     // routing::send<stereo_cable>
		auto& chain86 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(4);            // dlay_impl::chain86_t<NV>
		auto& receive12 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(4).getT(0);  // routing::receive<stereo_cable>
		auto& split27 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(4).getT(1);    // dlay_impl::split27_t<NV>
		auto& chain87 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain87_t
                        getT(1).getT(4).getT(1).getT(0);
		auto& chain88 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain88_t<NV>
                        getT(1).getT(4).getT(1).getT(1);
		auto& tempo_sync18 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::tempo_sync18_t<NV>
                             getT(1).getT(4).getT(1).getT(1).
                             getT(0);
		auto& branch23 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::branch23_t<NV>
                         getT(1).getT(4).getT(1).getT(1).
                         getT(1);
		auto& chain89 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::chain89_t<NV>
                        getT(4).getT(1).getT(1).getT(1).getT(0);
		auto& clear21 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                        getT(4).getT(1).getT(1).getT(1).getT(0).
                        getT(0);
		auto& chain90 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::chain90_t<NV>
                        getT(4).getT(1).getT(1).getT(1).getT(1);
		auto& clear22 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // math::clear<NV>
                        getT(4).getT(1).getT(1).getT(1).getT(1).
                        getT(0);
		auto& oscillator5 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                // dlay_impl::oscillator5_t<NV>
                            getT(4).getT(1).getT(1).getT(1).getT(1).
                            getT(1);
		auto& clear23 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                        getT(4).getT(1).getT(1).getT(1).getT(1).
                        getT(2);
		auto& sampleandhold5 = this->getT(1).getT(1).getT(1).getT(5).                     // fx::sampleandhold<NV>
                               getT(1).getT(4).getT(1).getT(1).
                               getT(2);
		auto& peak5 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::peak5_t<NV>
                      getT(1).getT(4).getT(1).getT(1).
                      getT(3);
		auto& gain10 = this->getT(1).getT(1).getT(1).getT(5).                             // core::gain<NV>
                       getT(1).getT(4).getT(1).getT(1).
                       getT(4);
		auto& modchain12 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(4).getT(2); // dlay_impl::modchain12_t<NV>
		auto& split28 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::split28_t<NV>
                        getT(1).getT(4).getT(2).getT(0);
		auto& pma41 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma41_t<NV>
                      getT(1).getT(4).getT(2).getT(0).
                      getT(0);
		auto& pma42 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma42_t<NV>
                      getT(1).getT(4).getT(2).getT(0).
                      getT(1);
		auto& split29 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(4).getT(3);    // dlay_impl::split29_t<NV>
		auto& chain91 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain91_t<NV>
                        getT(1).getT(4).getT(3).getT(0);
		auto& tempo_sync19 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::tempo_sync19_t<NV>
                             getT(1).getT(4).getT(3).getT(0).
                             getT(0);
		auto& smoothed_parameter_unscaled4 = this->getT(1).getT(1).getT(1).getT(5).       // dlay_impl::smoothed_parameter_unscaled4_t<NV>
                                             getT(1).getT(4).getT(3).getT(0).
                                             getT(1);
		auto& fix_delay21 = this->getT(1).getT(1).getT(1).getT(5).                        // core::fix_delay
                            getT(1).getT(4).getT(3).getT(0).
                            getT(2);
		auto& pma43 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::pma43_t<NV>
                      getT(1).getT(4).getT(3).getT(0).
                      getT(3);
		auto& cable_table38 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::cable_table38_t<NV>
                              getT(1).getT(4).getT(3).getT(0).
                              getT(4);
		auto& cable_table39 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::cable_table39_t
                              getT(1).getT(4).getT(3).getT(0).
                              getT(5);
		auto& modchain13 = this->getT(1).getT(1).getT(1).getT(5).                         // dlay_impl::modchain13_t<NV>
                           getT(1).getT(4).getT(3).getT(0).
                           getT(6);
		auto& split30 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::split30_t<NV>
                        getT(4).getT(3).getT(0).getT(6).getT(0);
		auto& pma44 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                      // dlay_impl::pma44_t<NV>
                      getT(4).getT(3).getT(0).getT(6).getT(0).
                      getT(0);
		auto& pma45 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                      // dlay_impl::pma45_t<NV>
                      getT(4).getT(3).getT(0).getT(6).getT(0).
                      getT(1);
		auto& svf20 = this->getT(1).getT(1).getT(1).getT(5).                              // filters::svf<NV>
                      getT(1).getT(4).getT(3).getT(0).
                      getT(7);
		auto& comp20 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::comp20_t
                       getT(1).getT(4).getT(3).getT(0).
                       getT(8);
		auto& gain24 = this->getT(1).getT(1).getT(1).getT(5).                             // core::gain<NV>
                       getT(1).getT(4).getT(3).getT(0).
                       getT(9);
		auto& send12 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(4).getT(4);     // routing::send<stereo_cable>
		auto& chain80 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(5);            // dlay_impl::chain80_t<NV>
		auto& receive11 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(5).getT(0);  // routing::receive<stereo_cable>
		auto& split23 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(5).getT(1);    // dlay_impl::split23_t<NV>
		auto& chain81 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain81_t
                        getT(1).getT(5).getT(1).getT(0);
		auto& chain82 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::chain82_t<NV>
                        getT(1).getT(5).getT(1).getT(1);
		auto& tempo_sync16 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::tempo_sync16_t<NV>
                             getT(1).getT(5).getT(1).getT(1).
                             getT(0);
		auto& branch22 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::branch22_t<NV>
                         getT(1).getT(5).getT(1).getT(1).
                         getT(1);
		auto& chain83 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::chain83_t<NV>
                        getT(5).getT(1).getT(1).getT(1).getT(0);
		auto& clear17 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                        getT(5).getT(1).getT(1).getT(1).getT(0).
                        getT(0);
		auto& chain84 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // dlay_impl::chain84_t<NV>
                        getT(5).getT(1).getT(1).getT(1).getT(1);
		auto& clear18 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // math::clear<NV>
                        getT(5).getT(1).getT(1).getT(1).getT(1).
                        getT(0);
		auto& oscillator4 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                // dlay_impl::oscillator4_t<NV>
                            getT(5).getT(1).getT(1).getT(1).getT(1).
                            getT(1);
		auto& clear19 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                        getT(5).getT(1).getT(1).getT(1).getT(1).
                        getT(2);
		auto& sampleandhold4 = this->getT(1).getT(1).getT(1).getT(5).                     // fx::sampleandhold<NV>
                               getT(1).getT(5).getT(1).getT(1).
                               getT(2);
		auto& peak4 = this->getT(1).getT(1).getT(1).getT(5).                              // dlay_impl::peak4_t<NV>
                      getT(1).getT(5).getT(1).getT(1).
                      getT(3);
		auto& gain11 = this->getT(1).getT(1).getT(1).getT(5).                             // core::gain<NV>
                       getT(1).getT(5).getT(1).getT(1).
                       getT(4);
		auto& modchain10 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(5).getT(2); // dlay_impl::modchain10_t<NV>
		auto& split24 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::split24_t<NV>
                        getT(1).getT(5).getT(2).getT(0);
		auto& pma36 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::pma36_t<NV>
                      getT(1).getT(5).getT(2).getT(0).
                      getT(0);
		auto& pma37 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::pma37_t<NV>
                      getT(1).getT(5).getT(2).getT(0).
                      getT(1);
		auto& split25 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(5).getT(3);   // dlay_impl::split25_t<NV>
		auto& chain85 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain85_t<NV>
                        getT(1).getT(5).getT(3).getT(0);
		auto& tempo_sync17 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::tempo_sync17_t<NV>
                             getT(1).getT(5).getT(3).getT(0).
                             getT(0);
		auto& smoothed_parameter_unscaled3 = this->getT(1).getT(1).getT(1).getT(5).      // dlay_impl::smoothed_parameter_unscaled3_t<NV>
                                             getT(1).getT(5).getT(3).getT(0).
                                             getT(1);
		auto& fix_delay20 = this->getT(1).getT(1).getT(1).getT(5).                       // core::fix_delay
                            getT(1).getT(5).getT(3).getT(0).
                            getT(2);
		auto& pma38 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::pma38_t<NV>
                      getT(1).getT(5).getT(3).getT(0).
                      getT(3);
		auto& cable_table36 = this->getT(1).getT(1).getT(1).getT(5).                     // dlay_impl::cable_table36_t<NV>
                              getT(1).getT(5).getT(3).getT(0).
                              getT(4);
		auto& cable_table37 = this->getT(1).getT(1).getT(1).getT(5).                     // dlay_impl::cable_table37_t
                              getT(1).getT(5).getT(3).getT(0).
                              getT(5);
		auto& modchain11 = this->getT(1).getT(1).getT(1).getT(5).                        // dlay_impl::modchain11_t<NV>
                           getT(1).getT(5).getT(3).getT(0).
                           getT(6);
		auto& split26 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::split26_t<NV>
                        getT(5).getT(3).getT(0).getT(6).getT(0);
		auto& pma39 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                     // dlay_impl::pma39_t<NV>
                      getT(5).getT(3).getT(0).getT(6).getT(0).
                      getT(0);
		auto& pma40 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                     // dlay_impl::pma40_t<NV>
                      getT(5).getT(3).getT(0).getT(6).getT(0).
                      getT(1);
		auto& svf19 = this->getT(1).getT(1).getT(1).getT(5).                             // filters::svf<NV>
                      getT(1).getT(5).getT(3).getT(0).
                      getT(7);
		auto& comp19 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::comp19_t
                       getT(1).getT(5).getT(3).getT(0).
                       getT(8);
		auto& gain23 = this->getT(1).getT(1).getT(1).getT(5).                            // core::gain<NV>
                       getT(1).getT(5).getT(3).getT(0).
                       getT(9);
		auto& send11 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(5).getT(4);    // routing::send<stereo_cable>
		auto& chain74 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(6);           // dlay_impl::chain74_t<NV>
		auto& receive10 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(6).getT(0); // routing::receive<stereo_cable>
		auto& split19 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(6).getT(1);   // dlay_impl::split19_t<NV>
		auto& chain75 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain75_t
                        getT(1).getT(6).getT(1).getT(0);
		auto& chain76 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain76_t<NV>
                        getT(1).getT(6).getT(1).getT(1);
		auto& tempo_sync14 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::tempo_sync14_t<NV>
                             getT(1).getT(6).getT(1).getT(1).
                             getT(0);
		auto& branch21 = this->getT(1).getT(1).getT(1).getT(5).                          // dlay_impl::branch21_t<NV>
                         getT(1).getT(6).getT(1).getT(1).
                         getT(1);
		auto& chain77 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::chain77_t<NV>
                        getT(6).getT(1).getT(1).getT(1).getT(0);
		auto& clear13 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // wrap::no_process<math::clear<NV>>
                        getT(6).getT(1).getT(1).getT(1).getT(0).
                        getT(0);
		auto& chain78 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::chain78_t<NV>
                        getT(6).getT(1).getT(1).getT(1).getT(1);
		auto& clear14 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // math::clear<NV>
                        getT(6).getT(1).getT(1).getT(1).getT(1).
                        getT(0);
		auto& oscillator3 = this->getT(1).getT(1).getT(1).getT(5).getT(1).               // dlay_impl::oscillator3_t<NV>
                            getT(6).getT(1).getT(1).getT(1).getT(1).
                            getT(1);
		auto& clear15 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // wrap::no_process<math::clear<NV>>
                        getT(6).getT(1).getT(1).getT(1).getT(1).
                        getT(2);
		auto& sampleandhold3 = this->getT(1).getT(1).getT(1).getT(5).                    // fx::sampleandhold<NV>
                               getT(1).getT(6).getT(1).getT(1).
                               getT(2);
		auto& peak3 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::peak3_t<NV>
                      getT(1).getT(6).getT(1).getT(1).
                      getT(3);
		auto& gain12 = this->getT(1).getT(1).getT(1).getT(5).                            // core::gain<NV>
                       getT(1).getT(6).getT(1).getT(1).
                       getT(4);
		auto& modchain8 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(6).getT(2); // dlay_impl::modchain8_t<NV>
		auto& split20 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::split20_t<NV>
                        getT(1).getT(6).getT(2).getT(0);
		auto& pma31 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::pma31_t<NV>
                      getT(1).getT(6).getT(2).getT(0).
                      getT(0);
		auto& pma32 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::pma32_t<NV>
                      getT(1).getT(6).getT(2).getT(0).
                      getT(1);
		auto& split21 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(6).getT(3);   // dlay_impl::split21_t<NV>
		auto& chain79 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain79_t<NV>
                        getT(1).getT(6).getT(3).getT(0);
		auto& tempo_sync15 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::tempo_sync15_t<NV>
                             getT(1).getT(6).getT(3).getT(0).
                             getT(0);
		auto& smoothed_parameter1 = this->getT(1).getT(1).getT(1).getT(5).               // dlay_impl::smoothed_parameter1_t<NV>
                                    getT(1).getT(6).getT(3).getT(0).
                                    getT(1);
		auto& fix_delay19 = this->getT(1).getT(1).getT(1).getT(5).                       // core::fix_delay
                            getT(1).getT(6).getT(3).getT(0).
                            getT(2);
		auto& pma33 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::pma33_t<NV>
                      getT(1).getT(6).getT(3).getT(0).
                      getT(3);
		auto& cable_table34 = this->getT(1).getT(1).getT(1).getT(5).                     // dlay_impl::cable_table34_t<NV>
                              getT(1).getT(6).getT(3).getT(0).
                              getT(4);
		auto& cable_table35 = this->getT(1).getT(1).getT(1).getT(5).                     // dlay_impl::cable_table35_t
                              getT(1).getT(6).getT(3).getT(0).
                              getT(5);
		auto& modchain9 = this->getT(1).getT(1).getT(1).getT(5).                         // dlay_impl::modchain9_t<NV>
                          getT(1).getT(6).getT(3).getT(0).
                          getT(6);
		auto& split22 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::split22_t<NV>
                        getT(6).getT(3).getT(0).getT(6).getT(0);
		auto& pma34 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                     // dlay_impl::pma34_t<NV>
                      getT(6).getT(3).getT(0).getT(6).getT(0).
                      getT(0);
		auto& pma35 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                     // dlay_impl::pma35_t<NV>
                      getT(6).getT(3).getT(0).getT(6).getT(0).
                      getT(1);
		auto& svf18 = this->getT(1).getT(1).getT(1).getT(5).                             // filters::svf<NV>
                      getT(1).getT(6).getT(3).getT(0).
                      getT(7);
		auto& comp18 = this->getT(1).getT(1).getT(1).getT(5).                            // dlay_impl::comp18_t
                       getT(1).getT(6).getT(3).getT(0).
                       getT(8);
		auto& gain22 = this->getT(1).getT(1).getT(1).getT(5).                            // core::gain<NV>
                       getT(1).getT(6).getT(3).getT(0).
                       getT(9);
		auto& send10 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(6).getT(4);    // routing::send<stereo_cable>
		auto& chain68 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(7);           // dlay_impl::chain68_t<NV>
		auto& receive9 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(7).getT(0);  // routing::receive<stereo_cable>
		auto& split15 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(7).getT(1);   // dlay_impl::split15_t<NV>
		auto& chain69 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain69_t
                        getT(1).getT(7).getT(1).getT(0);
		auto& chain70 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::chain70_t<NV>
                        getT(1).getT(7).getT(1).getT(1);
		auto& tempo_sync12 = this->getT(1).getT(1).getT(1).getT(5).                      // dlay_impl::tempo_sync12_t<NV>
                             getT(1).getT(7).getT(1).getT(1).
                             getT(0);
		auto& branch20 = this->getT(1).getT(1).getT(1).getT(5).                          // dlay_impl::branch20_t<NV>
                         getT(1).getT(7).getT(1).getT(1).
                         getT(1);
		auto& chain71 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::chain71_t<NV>
                        getT(7).getT(1).getT(1).getT(1).getT(0);
		auto& clear9 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                    // wrap::no_process<math::clear<NV>>
                       getT(7).getT(1).getT(1).getT(1).getT(0).
                       getT(0);
		auto& chain72 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::chain72_t<NV>
                        getT(7).getT(1).getT(1).getT(1).getT(1);
		auto& clear10 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // math::clear<NV>
                        getT(7).getT(1).getT(1).getT(1).getT(1).
                        getT(0);
		auto& oscillator2 = this->getT(1).getT(1).getT(1).getT(5).getT(1).               // dlay_impl::oscillator2_t<NV>
                            getT(7).getT(1).getT(1).getT(1).getT(1).
                            getT(1);
		auto& clear11 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // wrap::no_process<math::clear<NV>>
                        getT(7).getT(1).getT(1).getT(1).getT(1).
                        getT(2);
		auto& sampleandhold2 = this->getT(1).getT(1).getT(1).getT(5).                    // fx::sampleandhold<NV>
                               getT(1).getT(7).getT(1).getT(1).
                               getT(2);
		auto& peak2 = this->getT(1).getT(1).getT(1).getT(5).                             // dlay_impl::peak2_t<NV>
                      getT(1).getT(7).getT(1).getT(1).
                      getT(3);
		auto& gain13 = this->getT(1).getT(1).getT(1).getT(5).                            // core::gain<NV>
                       getT(1).getT(7).getT(1).getT(1).
                       getT(4);
		auto& modchain6 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(7).getT(2); // dlay_impl::modchain6_t<NV>
		auto& split16 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::split16_t<NV>
                        getT(1).getT(7).getT(2).getT(0);
		auto& pma26 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::pma26_t<NV>
                      getT(1).getT(7).getT(2).getT(0).
                      getT(0);
		auto& pma27 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::pma27_t<NV>
                      getT(1).getT(7).getT(2).getT(0).
                      getT(1);
		auto& split17 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(7).getT(3); // dlay_impl::split17_t<NV>
		auto& chain73 = this->getT(1).getT(1).getT(1).getT(5).                         // dlay_impl::chain73_t<NV>
                        getT(1).getT(7).getT(3).getT(0);
		auto& tempo_sync13 = this->getT(1).getT(1).getT(1).getT(5).                    // dlay_impl::tempo_sync13_t<NV>
                             getT(1).getT(7).getT(3).getT(0).
                             getT(0);
		auto& smoothed_parameter_unscaled2 = this->getT(1).getT(1).getT(1).getT(5).    // dlay_impl::smoothed_parameter_unscaled2_t<NV>
                                             getT(1).getT(7).getT(3).getT(0).
                                             getT(1);
		auto& fix_delay18 = this->getT(1).getT(1).getT(1).getT(5).                     // core::fix_delay
                            getT(1).getT(7).getT(3).getT(0).
                            getT(2);
		auto& pma28 = this->getT(1).getT(1).getT(1).getT(5).                           // dlay_impl::pma28_t<NV>
                      getT(1).getT(7).getT(3).getT(0).
                      getT(3);
		auto& cable_table32 = this->getT(1).getT(1).getT(1).getT(5).                   // dlay_impl::cable_table32_t<NV>
                              getT(1).getT(7).getT(3).getT(0).
                              getT(4);
		auto& cable_table33 = this->getT(1).getT(1).getT(1).getT(5).                   // dlay_impl::cable_table33_t
                              getT(1).getT(7).getT(3).getT(0).
                              getT(5);
		auto& modchain7 = this->getT(1).getT(1).getT(1).getT(5).                       // dlay_impl::modchain7_t<NV>
                          getT(1).getT(7).getT(3).getT(0).
                          getT(6);
		auto& split18 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                 // dlay_impl::split18_t<NV>
                        getT(7).getT(3).getT(0).getT(6).getT(0);
		auto& pma29 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::pma29_t<NV>
                      getT(7).getT(3).getT(0).getT(6).getT(0).
                      getT(0);
		auto& pma30 = this->getT(1).getT(1).getT(1).getT(5).getT(1).                   // dlay_impl::pma30_t<NV>
                      getT(7).getT(3).getT(0).getT(6).getT(0).
                      getT(1);
		auto& svf17 = this->getT(1).getT(1).getT(1).getT(5).                           // filters::svf<NV>
                      getT(1).getT(7).getT(3).getT(0).
                      getT(7);
		auto& comp17 = this->getT(1).getT(1).getT(1).getT(5).                          // dlay_impl::comp17_t
                       getT(1).getT(7).getT(3).getT(0).
                       getT(8);
		auto& gain21 = this->getT(1).getT(1).getT(1).getT(5).                          // core::gain<NV>
                       getT(1).getT(7).getT(3).getT(0).
                       getT(9);
		auto& send9 = this->getT(1).getT(1).getT(1).getT(5).getT(1).getT(7).getT(4);   // routing::send<stereo_cable>
		auto& branch19 = this->getT(1).getT(1).getT(1).getT(5).getT(2);                // dlay_impl::branch19_t<NV>
		auto& chain44 = this->getT(1).getT(1).getT(1).getT(5).getT(2).getT(0);         // dlay_impl::chain44_t
		auto& branch27 = this->getT(1).getT(1).getT(1).getT(5).getT(2).getT(1);        // dlay_impl::branch27_t<NV>
		auto& chain45 = this->getT(1).getT(1).getT(1).getT(5).getT(2).getT(1).getT(0); // dlay_impl::chain45_t<NV>
		auto& faust17 = this->getT(1).getT(1).getT(1).getT(5).                         // project::klp2<NV>
                        getT(2).getT(1).getT(0).getT(0);
		auto& chain46 = this->getT(1).getT(1).getT(1).getT(5).getT(2).getT(1).getT(1); // dlay_impl::chain46_t<NV>
		auto& faust20 = this->getT(1).getT(1).getT(1).getT(5).                         // project::klp2<NV>
                        getT(2).getT(1).getT(1).getT(0);
		auto& multi = this->getT(1).getT(1).getT(2); // dlay_impl::multi_t
		auto& clear = this->getT(1).getT(1).getT(3); // wrap::no_process<math::clear<NV>>
		auto& gain1 = this->getT(1).getT(1).getT(4); // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader); // Mix -> xfader::Value
		
		auto& Feedback_p = this->getParameterT(1);
		Feedback_p.connectT(0, receive);    // Feedback -> receive::Feedback
		Feedback_p.connectT(1, receive1);   // Feedback -> receive1::Feedback
		Feedback_p.connectT(2, receive2);   // Feedback -> receive2::Feedback
		Feedback_p.connectT(3, receive3);   // Feedback -> receive3::Feedback
		Feedback_p.connectT(4, receive4);   // Feedback -> receive4::Feedback
		Feedback_p.connectT(5, minmax1);    // Feedback -> minmax1::Value
		Feedback_p.connectT(6, receive6);   // Feedback -> receive6::Feedback
		Feedback_p.connectT(7, faust);      // Feedback -> faust::feedback
		Feedback_p.connectT(8, receive7);   // Feedback -> receive7::Feedback
		Feedback_p.connectT(9, receive15);  // Feedback -> receive15::Feedback
		Feedback_p.connectT(10, receive14); // Feedback -> receive14::Feedback
		Feedback_p.connectT(11, receive13); // Feedback -> receive13::Feedback
		Feedback_p.connectT(12, receive12); // Feedback -> receive12::Feedback
		Feedback_p.connectT(13, receive11); // Feedback -> receive11::Feedback
		Feedback_p.connectT(14, receive10); // Feedback -> receive10::Feedback
		Feedback_p.connectT(15, receive9);  // Feedback -> receive9::Feedback
		
		this->getParameterT(2).connectT(0, branch3); // Mode -> branch3::Index
		
		auto& Sync_p = this->getParameterT(3);
		Sync_p.connectT(0, branch8);     // Sync -> branch8::Index
		Sync_p.connectT(1, branch);      // Sync -> branch::Index
		Sync_p.connectT(2, branch11);    // Sync -> branch11::Index
		Sync_p.connectT(3, branch15);    // Sync -> branch15::Index
		Sync_p.connectT(4, branch13);    // Sync -> branch13::Index
		Sync_p.connectT(5, branch4);     // Sync -> branch4::Index
		Sync_p.connectT(6, tempo_sync3); // Sync -> tempo_sync3::Enabled
		Sync_p.connectT(7, branch17);    // Sync -> branch17::Index
		Sync_p.connectT(8, branch6);     // Sync -> branch6::Index
		Sync_p.connectT(9, branch27);    // Sync -> branch27::Index
		
		auto& DTime_p = this->getParameterT(4);
		DTime_p.connectT(0, pma);        // DTime -> pma::Add
		DTime_p.connectT(1, sliderbank); // DTime -> sliderbank::Value
		
		auto& Reverse_p = this->getParameterT(5);
		Reverse_p.connectT(0, branch1);  // Reverse -> branch1::Index
		Reverse_p.connectT(1, branch7);  // Reverse -> branch7::Index
		Reverse_p.connectT(2, branch10); // Reverse -> branch10::Index
		Reverse_p.connectT(3, branch14); // Reverse -> branch14::Index
		Reverse_p.connectT(4, branch12); // Reverse -> branch12::Index
		Reverse_p.connectT(5, branch2);  // Reverse -> branch2::Index
		Reverse_p.connectT(6, branch16); // Reverse -> branch16::Index
		Reverse_p.connectT(7, branch5);  // Reverse -> branch5::Index
		Reverse_p.connectT(8, branch19); // Reverse -> branch19::Index
		
		this->getParameterT(6).connectT(0, pma1); // DtimeR -> pma1::Add
		
		this->getParameterT(7).connectT(0, branch9); // PingPong -> branch9::Index
		
		auto& Tone_p = this->getParameterT(8);
		Tone_p.connectT(0, svf);         // Tone -> svf::Frequency
		Tone_p.connectT(1, one_pole3);   // Tone -> one_pole3::Frequency
		Tone_p.connectT(2, one_pole4);   // Tone -> one_pole4::Frequency
		Tone_p.connectT(3, one_pole5);   // Tone -> one_pole5::Frequency
		Tone_p.connectT(4, one_pole6);   // Tone -> one_pole6::Frequency
		Tone_p.connectT(5, one_pole);    // Tone -> one_pole::Frequency
		Tone_p.connectT(6, one_pole1);   // Tone -> one_pole1::Frequency
		Tone_p.connectT(7, one_pole2);   // Tone -> one_pole2::Frequency
		Tone_p.connectT(8, sliderbank1); // Tone -> sliderbank1::Value
		
		this->getParameterT(9).connectT(0, faust); // GranPos -> faust::decal
		
		this->getParameterT(10).connectT(0, faust); // GranPitch -> faust::speed
		
		auto& Div_p = this->getParameterT(11);
		Div_p.connectT(0, tempo_sync9);   // Div -> tempo_sync9::Multiplier
		Div_p.connectT(1, tempo_sync24);  // Div -> tempo_sync24::Multiplier
		Div_p.connectT(2, tempo_sync22);  // Div -> tempo_sync22::Multiplier
		Div_p.connectT(3, tempo_sync20);  // Div -> tempo_sync20::Multiplier
		Div_p.connectT(4, tempo_sync18);  // Div -> tempo_sync18::Multiplier
		Div_p.connectT(5, tempo_sync16);  // Div -> tempo_sync16::Multiplier
		Div_p.connectT(6, tempo_sync14);  // Div -> tempo_sync14::Multiplier
		Div_p.connectT(7, tempo_sync12);  // Div -> tempo_sync12::Multiplier
		Div_p.connectT(8, tempo_sync2);   // Div -> tempo_sync2::Multiplier
		Div_p.connectT(9, tempo_sync25);  // Div -> tempo_sync25::Multiplier
		Div_p.connectT(10, tempo_sync23); // Div -> tempo_sync23::Multiplier
		Div_p.connectT(11, tempo_sync21); // Div -> tempo_sync21::Multiplier
		Div_p.connectT(12, tempo_sync19); // Div -> tempo_sync19::Multiplier
		Div_p.connectT(13, tempo_sync17); // Div -> tempo_sync17::Multiplier
		Div_p.connectT(14, tempo_sync15); // Div -> tempo_sync15::Multiplier
		Div_p.connectT(15, tempo_sync13); // Div -> tempo_sync13::Multiplier
		
		auto& MultiRes_p = this->getParameterT(12);
		MultiRes_p.connectT(0, pma2);  // MultiRes -> pma2::Add
		MultiRes_p.connectT(1, pma58); // MultiRes -> pma58::Add
		MultiRes_p.connectT(2, pma53); // MultiRes -> pma53::Add
		MultiRes_p.connectT(3, pma48); // MultiRes -> pma48::Add
		MultiRes_p.connectT(4, pma43); // MultiRes -> pma43::Add
		MultiRes_p.connectT(5, pma38); // MultiRes -> pma38::Add
		MultiRes_p.connectT(6, pma33); // MultiRes -> pma33::Add
		MultiRes_p.connectT(7, pma28); // MultiRes -> pma28::Add
		
		auto& MultiDelSH_p = this->getParameterT(13);
		MultiDelSH_p.connectT(0, pma17); // MultiDelSH -> pma17::Multiply
		MultiDelSH_p.connectT(1, pma56); // MultiDelSH -> pma56::Multiply
		MultiDelSH_p.connectT(2, pma51); // MultiDelSH -> pma51::Multiply
		MultiDelSH_p.connectT(3, pma46); // MultiDelSH -> pma46::Multiply
		MultiDelSH_p.connectT(4, pma41); // MultiDelSH -> pma41::Multiply
		MultiDelSH_p.connectT(5, pma36); // MultiDelSH -> pma36::Multiply
		MultiDelSH_p.connectT(6, pma31); // MultiDelSH -> pma31::Multiply
		MultiDelSH_p.connectT(7, pma26); // MultiDelSH -> pma26::Multiply
		
		auto& MultiCutSH_p = this->getParameterT(14);
		MultiCutSH_p.connectT(0, pma19); // MultiCutSH -> pma19::Multiply
		MultiCutSH_p.connectT(1, pma59); // MultiCutSH -> pma59::Multiply
		MultiCutSH_p.connectT(2, pma54); // MultiCutSH -> pma54::Multiply
		MultiCutSH_p.connectT(3, pma49); // MultiCutSH -> pma49::Multiply
		MultiCutSH_p.connectT(4, pma44); // MultiCutSH -> pma44::Multiply
		MultiCutSH_p.connectT(5, pma39); // MultiCutSH -> pma39::Multiply
		MultiCutSH_p.connectT(6, pma34); // MultiCutSH -> pma34::Multiply
		MultiCutSH_p.connectT(7, pma29); // MultiCutSH -> pma29::Multiply
		
		auto& SHIn_p = this->getParameterT(15);
		SHIn_p.connectT(0, branch18); // SHIn -> branch18::Index
		SHIn_p.connectT(1, branch26); // SHIn -> branch26::Index
		SHIn_p.connectT(2, branch25); // SHIn -> branch25::Index
		SHIn_p.connectT(3, branch24); // SHIn -> branch24::Index
		SHIn_p.connectT(4, branch23); // SHIn -> branch23::Index
		SHIn_p.connectT(5, branch22); // SHIn -> branch22::Index
		SHIn_p.connectT(6, branch21); // SHIn -> branch21::Index
		SHIn_p.connectT(7, branch20); // SHIn -> branch20::Index
		
		auto& ShMix_p = this->getParameterT(16);
		ShMix_p.connectT(0, gain6);  // ShMix -> gain6::Gain
		ShMix_p.connectT(1, gain7);  // ShMix -> gain7::Gain
		ShMix_p.connectT(2, gain8);  // ShMix -> gain8::Gain
		ShMix_p.connectT(3, gain9);  // ShMix -> gain9::Gain
		ShMix_p.connectT(4, gain10); // ShMix -> gain10::Gain
		ShMix_p.connectT(5, gain11); // ShMix -> gain11::Gain
		ShMix_p.connectT(6, gain12); // ShMix -> gain12::Gain
		ShMix_p.connectT(7, gain13); // ShMix -> gain13::Gain
		
		auto& MultiFtype_p = this->getParameterT(17);
		MultiFtype_p.connectT(0, svf1);  // MultiFtype -> svf1::Mode
		MultiFtype_p.connectT(1, svf23); // MultiFtype -> svf23::Mode
		MultiFtype_p.connectT(2, svf22); // MultiFtype -> svf22::Mode
		MultiFtype_p.connectT(3, svf20); // MultiFtype -> svf20::Mode
		MultiFtype_p.connectT(4, svf19); // MultiFtype -> svf19::Mode
		MultiFtype_p.connectT(5, svf18); // MultiFtype -> svf18::Mode
		MultiFtype_p.connectT(6, svf17); // MultiFtype -> svf17::Mode
		
		auto& mod_p = this->getParameterT(18);
		mod_p.connectT(0, pma);  // mod -> pma::Multiply
		mod_p.connectT(1, pma1); // mod -> pma1::Multiply
		
		this->getParameterT(19).connectT(0, branch28); // MODSRC -> branch28::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                              // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);                             // xfader -> gain1::Gain
		global_cable.getWrappedObject().getParameter().connectT(0, add);          // global_cable -> add::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add3);        // global_cable3 -> add3::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2);        // global_cable2 -> add2::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add1);        // global_cable1 -> add1::Value
		smoothed_parameter_unscaled7.getParameter().connectT(0, jdelay_thiran1);  // smoothed_parameter_unscaled7 -> jdelay_thiran1::DelayTime
		smoothed_parameter_unscaled9.getParameter().connectT(0, jdelay_thiran3);  // smoothed_parameter_unscaled9 -> jdelay_thiran3::DelayTime
		tempo_sync3.getParameter().connectT(0, fix_delay);                        // tempo_sync3 -> fix_delay::DelayTime
		tempo_sync3.getParameter().connectT(1, faust8);                           // tempo_sync3 -> faust8::delayms
		tempo_sync3.getParameter().connectT(2, faust);                            // tempo_sync3 -> faust::taille
		tempo_sync3.getParameter().connectT(3, smoothed_parameter_unscaled7);     // tempo_sync3 -> smoothed_parameter_unscaled7::Value
		tempo_sync3.getParameter().connectT(4, smoothed_parameter_unscaled9);     // tempo_sync3 -> smoothed_parameter_unscaled9::Value
		minmax.getWrappedObject().getParameter().connectT(0, faust7);             // minmax -> faust7::Log2Delay
		minmax.getWrappedObject().getParameter().connectT(1, faust10);            // minmax -> faust10::Log2Delay
		minmax.getWrappedObject().getParameter().connectT(2, faust3);             // minmax -> faust3::Log2Delay
		minmax.getWrappedObject().getParameter().connectT(3, faust16);            // minmax -> faust16::Log2Delay
		minmax.getWrappedObject().getParameter().connectT(4, faust19);            // minmax -> faust19::Log2Delay
		minmax.getWrappedObject().getParameter().connectT(5, faust4);             // minmax -> faust4::Log2Delay
		smoothed_parameter.getParameter().connectT(0, fix_delay1);                // smoothed_parameter -> fix_delay1::DelayTime
		smoothed_parameter.getParameter().connectT(1, jdelay_thiran);             // smoothed_parameter -> jdelay_thiran::DelayTime
		pma.getWrappedObject().getParameter().connectT(0, tempo_sync3);           // pma -> tempo_sync3::UnsyncedTime
		pma.getWrappedObject().getParameter().connectT(1, tempo_sync3);           // pma -> tempo_sync3::Tempo
		pma.getWrappedObject().getParameter().connectT(2, minmax);                // pma -> minmax::Value
		pma.getWrappedObject().getParameter().connectT(3, faust6);                // pma -> faust6::Log2Delay
		pma.getWrappedObject().getParameter().connectT(4, faust9);                // pma -> faust9::Log2Delay
		pma.getWrappedObject().getParameter().connectT(5, faust2);                // pma -> faust2::Log2Delay
		pma.getWrappedObject().getParameter().connectT(6, faust11);               // pma -> faust11::Log2Delay
		pma.getWrappedObject().getParameter().connectT(7, faust15);               // pma -> faust15::Log2Delay
		pma.getWrappedObject().getParameter().connectT(8, faust13);               // pma -> faust13::Log2Delay
		pma.getWrappedObject().getParameter().connectT(9, smoothed_parameter);    // pma -> smoothed_parameter::Value
		pma.getWrappedObject().getParameter().connectT(10, faust18);              // pma -> faust18::Log2Delay
		pma.getWrappedObject().getParameter().connectT(11, faust1);               // pma -> faust1::Log2Delay
		smoothed_parameter_unscaled10.getParameter().connectT(0, jdelay_thiran4); // smoothed_parameter_unscaled10 -> jdelay_thiran4::DelayTime
		smoothed_parameter_unscaled11.getParameter().connectT(0, jdelay_thiran2); // smoothed_parameter_unscaled11 -> jdelay_thiran2::DelayTime
		tempo_sync.getParameter().connectT(0, smoothed_parameter_unscaled10);     // tempo_sync -> smoothed_parameter_unscaled10::Value
		tempo_sync.getParameter().connectT(1, smoothed_parameter_unscaled11);     // tempo_sync -> smoothed_parameter_unscaled11::Value
		minmax2.getWrappedObject().getParameter().connectT(0, faust12);           // minmax2 -> faust12::Log2Delay
		minmax2.getWrappedObject().getParameter().connectT(1, faust14);           // minmax2 -> faust14::Log2Delay
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync);           // pma1 -> tempo_sync::Tempo
		pma1.getWrappedObject().getParameter().connectT(1, minmax2);              // pma1 -> minmax2::Value
		pma1.getWrappedObject().getParameter().connectT(2, tempo_sync);           // pma1 -> tempo_sync::UnsyncedTime
		peak1.getParameter().connectT(0, pma);                                    // peak1 -> pma::Value
		peak1.getParameter().connectT(1, pma1);                                   // peak1 -> pma1::Value
		minmax1.getWrappedObject().getParameter().connectT(0, faust8);            // minmax1 -> faust8::feedback
		smoothed_parameter_unscaled.getParameter().connectT(0, fix_delay2);       // smoothed_parameter_unscaled -> fix_delay2::DelayTime
		tempo_sync2.getParameter().connectT(0, smoothed_parameter_unscaled);      // tempo_sync2 -> smoothed_parameter_unscaled::Value
		pma17.getWrappedObject().getParameter().connectT(0, tempo_sync2);         // pma17 -> tempo_sync2::Tempo
		pma18.getWrappedObject().getParameter().connectT(0, pma17);               // pma18 -> pma17::Add
		tempo_sync9.getParameter().connectT(0, sampleandhold);                    // tempo_sync9 -> sampleandhold::Counter
		smoothed_parameter_unscaled1.getParameter().connectT(0, fix_delay24);     // smoothed_parameter_unscaled1 -> fix_delay24::DelayTime
		tempo_sync25.getParameter().connectT(0, smoothed_parameter_unscaled1);    // tempo_sync25 -> smoothed_parameter_unscaled1::Value
		pma56.getWrappedObject().getParameter().connectT(0, tempo_sync25);        // pma56 -> tempo_sync25::Tempo
		pma57.getWrappedObject().getParameter().connectT(0, pma56);               // pma57 -> pma56::Add
		tempo_sync24.getParameter().connectT(0, sampleandhold8);                  // tempo_sync24 -> sampleandhold8::Counter
		smoothed_parameter_unscaled6.getParameter().connectT(0, fix_delay23);     // smoothed_parameter_unscaled6 -> fix_delay23::DelayTime
		tempo_sync23.getParameter().connectT(0, smoothed_parameter_unscaled6);    // tempo_sync23 -> smoothed_parameter_unscaled6::Value
		pma51.getWrappedObject().getParameter().connectT(0, tempo_sync23);        // pma51 -> tempo_sync23::Tempo
		pma52.getWrappedObject().getParameter().connectT(0, pma51);               // pma52 -> pma51::Add
		tempo_sync22.getParameter().connectT(0, sampleandhold7);                  // tempo_sync22 -> sampleandhold7::Counter
		smoothed_parameter_unscaled5.getParameter().connectT(0, fix_delay22);     // smoothed_parameter_unscaled5 -> fix_delay22::DelayTime
		tempo_sync21.getParameter().connectT(0, smoothed_parameter_unscaled5);    // tempo_sync21 -> smoothed_parameter_unscaled5::Value
		pma46.getWrappedObject().getParameter().connectT(0, tempo_sync21);        // pma46 -> tempo_sync21::Tempo
		pma47.getWrappedObject().getParameter().connectT(0, pma46);               // pma47 -> pma46::Add
		tempo_sync20.getParameter().connectT(0, sampleandhold6);                  // tempo_sync20 -> sampleandhold6::Counter
		tempo_sync18.getParameter().connectT(0, sampleandhold5);                  // tempo_sync18 -> sampleandhold5::Counter
		smoothed_parameter_unscaled4.getParameter().connectT(0, fix_delay21);     // smoothed_parameter_unscaled4 -> fix_delay21::DelayTime
		tempo_sync19.getParameter().connectT(0, smoothed_parameter_unscaled4);    // tempo_sync19 -> smoothed_parameter_unscaled4::Value
		pma41.getWrappedObject().getParameter().connectT(0, tempo_sync19);        // pma41 -> tempo_sync19::Tempo
		pma42.getWrappedObject().getParameter().connectT(0, pma41);               // pma42 -> pma41::Add
		smoothed_parameter_unscaled3.getParameter().connectT(0, fix_delay20);     // smoothed_parameter_unscaled3 -> fix_delay20::DelayTime
		tempo_sync17.getParameter().connectT(0, smoothed_parameter_unscaled3);    // tempo_sync17 -> smoothed_parameter_unscaled3::Value
		pma36.getWrappedObject().getParameter().connectT(0, tempo_sync17);        // pma36 -> tempo_sync17::Tempo
		pma37.getWrappedObject().getParameter().connectT(0, pma36);               // pma37 -> pma36::Add
		tempo_sync16.getParameter().connectT(0, sampleandhold4);                  // tempo_sync16 -> sampleandhold4::Counter
		tempo_sync14.getParameter().connectT(0, sampleandhold3);                  // tempo_sync14 -> sampleandhold3::Counter
		smoothed_parameter1.getParameter().connectT(0, fix_delay19);              // smoothed_parameter1 -> fix_delay19::DelayTime
		tempo_sync15.getParameter().connectT(0, smoothed_parameter1);             // tempo_sync15 -> smoothed_parameter1::Value
		pma31.getWrappedObject().getParameter().connectT(0, tempo_sync15);        // pma31 -> tempo_sync15::Tempo
		pma32.getWrappedObject().getParameter().connectT(0, pma31);               // pma32 -> pma31::Add
		tempo_sync12.getParameter().connectT(0, sampleandhold2);                  // tempo_sync12 -> sampleandhold2::Counter
		smoothed_parameter_unscaled2.getParameter().connectT(0, fix_delay18);     // smoothed_parameter_unscaled2 -> fix_delay18::DelayTime
		tempo_sync13.getParameter().connectT(0, smoothed_parameter_unscaled2);    // tempo_sync13 -> smoothed_parameter_unscaled2::Value
		pma26.getWrappedObject().getParameter().connectT(0, tempo_sync13);        // pma26 -> tempo_sync13::Tempo
		pma27.getWrappedObject().getParameter().connectT(0, pma26);               // pma27 -> pma26::Add
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, pma18);           // sliderbank -> pma18::Add
		sliderbank_p.getParameterT(0).connectT(1, tempo_sync9);     // sliderbank -> tempo_sync9::Tempo
		sliderbank_p.getParameterT(1).connectT(0, pma57);           // sliderbank -> pma57::Add
		sliderbank_p.getParameterT(1).connectT(1, tempo_sync24);    // sliderbank -> tempo_sync24::Tempo
		sliderbank_p.getParameterT(2).connectT(0, pma52);           // sliderbank -> pma52::Add
		sliderbank_p.getParameterT(2).connectT(1, tempo_sync22);    // sliderbank -> tempo_sync22::Tempo
		sliderbank_p.getParameterT(3).connectT(0, pma47);           // sliderbank -> pma47::Add
		sliderbank_p.getParameterT(3).connectT(1, tempo_sync20);    // sliderbank -> tempo_sync20::Tempo
		sliderbank_p.getParameterT(4).connectT(0, tempo_sync18);    // sliderbank -> tempo_sync18::Tempo
		sliderbank_p.getParameterT(4).connectT(1, pma42);           // sliderbank -> pma42::Add
		sliderbank_p.getParameterT(5).connectT(0, pma37);           // sliderbank -> pma37::Add
		sliderbank_p.getParameterT(5).connectT(1, tempo_sync16);    // sliderbank -> tempo_sync16::Tempo
		sliderbank_p.getParameterT(6).connectT(0, tempo_sync14);    // sliderbank -> tempo_sync14::Tempo
		sliderbank_p.getParameterT(6).connectT(1, pma32);           // sliderbank -> pma32::Add
		sliderbank_p.getParameterT(7).connectT(0, tempo_sync12);    // sliderbank -> tempo_sync12::Tempo
		sliderbank_p.getParameterT(7).connectT(1, pma27);           // sliderbank -> pma27::Add
		pma19.getWrappedObject().getParameter().connectT(0, svf1);  // pma19 -> svf1::Frequency
		pma20.getWrappedObject().getParameter().connectT(0, pma19); // pma20 -> pma19::Add
		pma59.getWrappedObject().getParameter().connectT(0, svf23); // pma59 -> svf23::Frequency
		pma60.getWrappedObject().getParameter().connectT(0, pma59); // pma60 -> pma59::Add
		pma54.getWrappedObject().getParameter().connectT(0, svf22); // pma54 -> svf22::Frequency
		pma55.getWrappedObject().getParameter().connectT(0, pma54); // pma55 -> pma54::Add
		pma49.getWrappedObject().getParameter().connectT(0, svf21); // pma49 -> svf21::Frequency
		pma50.getWrappedObject().getParameter().connectT(0, pma49); // pma50 -> pma49::Add
		pma44.getWrappedObject().getParameter().connectT(0, svf20); // pma44 -> svf20::Frequency
		pma45.getWrappedObject().getParameter().connectT(0, pma44); // pma45 -> pma44::Add
		pma39.getWrappedObject().getParameter().connectT(0, svf19); // pma39 -> svf19::Frequency
		pma40.getWrappedObject().getParameter().connectT(0, pma39); // pma40 -> pma39::Add
		pma34.getWrappedObject().getParameter().connectT(0, svf18); // pma34 -> svf18::Frequency
		pma35.getWrappedObject().getParameter().connectT(0, pma34); // pma35 -> pma34::Add
		pma29.getWrappedObject().getParameter().connectT(0, svf17); // pma29 -> svf17::Frequency
		pma30.getWrappedObject().getParameter().connectT(0, pma29); // pma30 -> pma29::Add
		auto& sliderbank1_p = sliderbank1.getWrappedObject().getParameter();
		sliderbank1_p.getParameterT(0).connectT(0, pma20);                   // sliderbank1 -> pma20::Add
		sliderbank1_p.getParameterT(1).connectT(0, pma60);                   // sliderbank1 -> pma60::Add
		sliderbank1_p.getParameterT(2).connectT(0, pma55);                   // sliderbank1 -> pma55::Add
		sliderbank1_p.getParameterT(3).connectT(0, pma50);                   // sliderbank1 -> pma50::Add
		sliderbank1_p.getParameterT(4).connectT(0, pma45);                   // sliderbank1 -> pma45::Add
		sliderbank1_p.getParameterT(5).connectT(0, pma40);                   // sliderbank1 -> pma40::Add
		sliderbank1_p.getParameterT(6).connectT(0, pma35);                   // sliderbank1 -> pma35::Add
		sliderbank1_p.getParameterT(7).connectT(0, pma30);                   // sliderbank1 -> pma30::Add
		peak.getParameter().connectT(0, pma17);                              // peak -> pma17::Value
		peak.getParameter().connectT(1, pma19);                              // peak -> pma19::Value
		cable_table.getWrappedObject().getParameter().connectT(0, svf1);     // cable_table -> svf1::Q
		cable_table1.getWrappedObject().getParameter().connectT(0, comp1);   // cable_table1 -> comp1::Threshhold
		pma2.getWrappedObject().getParameter().connectT(0, cable_table);     // pma2 -> cable_table::Value
		pma2.getWrappedObject().getParameter().connectT(1, cable_table1);    // pma2 -> cable_table1::Value
		peak8.getParameter().connectT(0, pma56);                             // peak8 -> pma56::Value
		peak8.getParameter().connectT(1, pma59);                             // peak8 -> pma59::Value
		cable_table44.getWrappedObject().getParameter().connectT(0, svf23);  // cable_table44 -> svf23::Q
		cable_table45.getWrappedObject().getParameter().connectT(0, comp23); // cable_table45 -> comp23::Threshhold
		pma58.getWrappedObject().getParameter().connectT(0, cable_table44);  // pma58 -> cable_table44::Value
		pma58.getWrappedObject().getParameter().connectT(1, cable_table45);  // pma58 -> cable_table45::Value
		peak7.getParameter().connectT(0, pma51);                             // peak7 -> pma51::Value
		peak7.getParameter().connectT(1, pma54);                             // peak7 -> pma54::Value
		cable_table42.getWrappedObject().getParameter().connectT(0, svf22);  // cable_table42 -> svf22::Q
		cable_table43.getWrappedObject().getParameter().connectT(0, comp22); // cable_table43 -> comp22::Threshhold
		pma53.getWrappedObject().getParameter().connectT(0, cable_table42);  // pma53 -> cable_table42::Value
		pma53.getWrappedObject().getParameter().connectT(1, cable_table43);  // pma53 -> cable_table43::Value
		peak6.getParameter().connectT(0, pma46);                             // peak6 -> pma46::Value
		peak6.getParameter().connectT(1, pma49);                             // peak6 -> pma49::Value
		cable_table40.getWrappedObject().getParameter().connectT(0, svf21);  // cable_table40 -> svf21::Q
		cable_table41.getWrappedObject().getParameter().connectT(0, comp21); // cable_table41 -> comp21::Threshhold
		pma48.getWrappedObject().getParameter().connectT(0, cable_table40);  // pma48 -> cable_table40::Value
		pma48.getWrappedObject().getParameter().connectT(1, cable_table41);  // pma48 -> cable_table41::Value
		peak5.getParameter().connectT(0, pma41);                             // peak5 -> pma41::Value
		peak5.getParameter().connectT(1, pma44);                             // peak5 -> pma44::Value
		cable_table38.getWrappedObject().getParameter().connectT(0, svf20);  // cable_table38 -> svf20::Q
		cable_table39.getWrappedObject().getParameter().connectT(0, comp20); // cable_table39 -> comp20::Threshhold
		pma43.getWrappedObject().getParameter().connectT(0, cable_table38);  // pma43 -> cable_table38::Value
		pma43.getWrappedObject().getParameter().connectT(1, cable_table39);  // pma43 -> cable_table39::Value
		peak4.getParameter().connectT(0, pma36);                             // peak4 -> pma36::Value
		peak4.getParameter().connectT(1, pma39);                             // peak4 -> pma39::Value
		cable_table36.getWrappedObject().getParameter().connectT(0, svf19);  // cable_table36 -> svf19::Q
		cable_table37.getWrappedObject().getParameter().connectT(0, comp19); // cable_table37 -> comp19::Threshhold
		pma38.getWrappedObject().getParameter().connectT(0, cable_table36);  // pma38 -> cable_table36::Value
		pma38.getWrappedObject().getParameter().connectT(1, cable_table37);  // pma38 -> cable_table37::Value
		peak3.getParameter().connectT(0, pma31);                             // peak3 -> pma31::Value
		peak3.getParameter().connectT(1, pma34);                             // peak3 -> pma34::Value
		cable_table34.getWrappedObject().getParameter().connectT(0, svf18);  // cable_table34 -> svf18::Q
		cable_table35.getWrappedObject().getParameter().connectT(0, comp18); // cable_table35 -> comp18::Threshhold
		pma33.getWrappedObject().getParameter().connectT(0, cable_table34);  // pma33 -> cable_table34::Value
		pma33.getWrappedObject().getParameter().connectT(1, cable_table35);  // pma33 -> cable_table35::Value
		peak2.getParameter().connectT(0, pma26);                             // peak2 -> pma26::Value
		peak2.getParameter().connectT(1, pma29);                             // peak2 -> pma29::Value
		cable_table32.getWrappedObject().getParameter().connectT(0, svf17);  // cable_table32 -> svf17::Q
		cable_table33.getWrappedObject().getParameter().connectT(0, comp17); // cable_table33 -> comp17::Threshhold
		pma28.getWrappedObject().getParameter().connectT(0, cable_table32);  // pma28 -> cable_table32::Value
		pma28.getWrappedObject().getParameter().connectT(1, cable_table33);  // pma28 -> cable_table33::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		send1.connect(receive1);
		send2.connect(receive2);
		send3.connect(receive4);
		send4.connect(receive3);
		send6.connect(receive6);
		send7.connect(receive15);
		send7.connect(receive7);
		send15.connect(receive14);
		send15.connect(receive15);
		send14.connect(receive13);
		send14.connect(receive14);
		send13.connect(receive12);
		send13.connect(receive13);
		send12.connect(receive11);
		send12.connect(receive12);
		send11.connect(receive10);
		send11.connect(receive11);
		send10.connect(receive10);
		send10.connect(receive9);
		send9.connect(receive7);
		send9.connect(receive9);
		
		// Default Values --------------------------------------------------------------------------
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch28::Index is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add3::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add1::Value is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                             // minmax::Value is automated
		minmax.setParameterT(1, 12.); // control::minmax::Minimum
		minmax.setParameterT(2, 16.); // control::minmax::Maximum
		minmax.setParameterT(3, 1.);  // control::minmax::Skew
		minmax.setParameterT(4, 0.);  // control::minmax::Step
		minmax.setParameterT(5, 1.);  // control::minmax::Polarity
		
		;                                 // tempo_sync3::Tempo is automated
		tempo_sync3.setParameterT(1, 1.); // control::tempo_sync::Multiplier
		;                                 // tempo_sync3::Enabled is automated
		;                                 // tempo_sync3::UnsyncedTime is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		;                              // minmax2::Value is automated
		minmax2.setParameterT(1, 12.); // control::minmax::Minimum
		minmax2.setParameterT(2, 16.); // control::minmax::Maximum
		minmax2.setParameterT(3, 1.);  // control::minmax::Skew
		minmax2.setParameterT(4, 0.);  // control::minmax::Step
		minmax2.setParameterT(5, 1.);  // control::minmax::Polarity
		
		;                                // tempo_sync::Tempo is automated
		tempo_sync.setParameterT(1, 1.); // control::tempo_sync::Multiplier
		tempo_sync.setParameterT(2, 1.); // control::tempo_sync::Enabled
		;                                // tempo_sync::UnsyncedTime is automated
		
		; // branch3::Index is automated
		
		; // receive::Feedback is automated
		
		;                                 // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 512.); // core::fix_delay::FadeTime
		
		;                           // svf::Frequency is automated
		svf.setParameterT(1, 0.3);  // filters::svf::Q
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);   // filters::svf::Mode
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		; // branch1::Index is automated
		
		; // branch::Index is automated
		
		; // faust6::Log2Delay is automated
		
		; // faust7::Log2Delay is automated
		
		comp.setParameterT(0, -3);    // dynamics::comp::Threshhold
		comp.setParameterT(1, 163.2); // dynamics::comp::Attack
		comp.setParameterT(2, 50.);   // dynamics::comp::Release
		comp.setParameterT(3, 2);     // dynamics::comp::Ratio
		comp.setParameterT(4, 0.);    // dynamics::comp::Sidechain
		
		gain2.setParameterT(0, 0.);  // core::gain::Gain
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		dynamic_blocksize1.setParameterT(0, 1.); // container::chain::BlockSize
		
		; // branch9::Index is automated
		
		; // receive1::Feedback is automated
		
		;                                                     // smoothed_parameter_unscaled7::Value is automated
		smoothed_parameter_unscaled7.setParameterT(1, 508.5); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled7.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		jdelay_thiran1.setParameterT(0, 1000.); // jdsp::jdelay_thiran::Limit
		;                                       // jdelay_thiran1::DelayTime is automated
		
		;                                 // one_pole3::Frequency is automated
		one_pole3.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole3.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole3.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole3.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole3.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // branch7::Index is automated
		
		; // branch8::Index is automated
		
		; // faust2::Log2Delay is automated
		
		; // faust3::Log2Delay is automated
		
		jpanner.setParameterT(0, -1.); // jdsp::jpanner::Pan
		jpanner.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		; // receive2::Feedback is automated
		
		;                                                      // smoothed_parameter_unscaled10::Value is automated
		smoothed_parameter_unscaled10.setParameterT(1, 520.1); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled10.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		jdelay_thiran4.setParameterT(0, 1000.); // jdsp::jdelay_thiran::Limit
		;                                       // jdelay_thiran4::DelayTime is automated
		
		;                                 // one_pole4::Frequency is automated
		one_pole4.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole4.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole4.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole4.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole4.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // branch10::Index is automated
		
		; // branch11::Index is automated
		
		; // faust11::Log2Delay is automated
		
		; // faust12::Log2Delay is automated
		
		jpanner1.setParameterT(0, 1.); // jdsp::jpanner::Pan
		jpanner1.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		; // receive3::Feedback is automated
		
		;                                                     // smoothed_parameter_unscaled9::Value is automated
		smoothed_parameter_unscaled9.setParameterT(1, 509.3); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled9.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		jdelay_thiran3.setParameterT(0, 1000.); // jdsp::jdelay_thiran::Limit
		;                                       // jdelay_thiran3::DelayTime is automated
		
		;                                 // one_pole5::Frequency is automated
		one_pole5.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole5.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole5.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole5.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole5.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // branch14::Index is automated
		
		; // branch15::Index is automated
		
		; // faust15::Log2Delay is automated
		
		; // faust16::Log2Delay is automated
		
		jpanner2.setParameterT(0, -1.); // jdsp::jpanner::Pan
		jpanner2.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		; // receive4::Feedback is automated
		
		;                                                     // smoothed_parameter_unscaled11::Value is automated
		smoothed_parameter_unscaled11.setParameterT(1, 520.); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled11.setParameterT(2, 1.);   // control::smoothed_parameter_unscaled::Enabled
		
		jdelay_thiran2.setParameterT(0, 1000.); // jdsp::jdelay_thiran::Limit
		;                                       // jdelay_thiran2::DelayTime is automated
		
		;                                 // one_pole6::Frequency is automated
		one_pole6.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole6.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole6.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole6.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole6.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // branch12::Index is automated
		
		; // branch13::Index is automated
		
		; // faust13::Log2Delay is automated
		
		; // faust14::Log2Delay is automated
		
		jpanner3.setParameterT(0, 1.); // jdsp::jpanner::Pan
		jpanner3.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		dynamic_blocksize.setParameterT(0, 1.); // container::chain::BlockSize
		
		;                                          // smoothed_parameter::Value is automated
		smoothed_parameter.setParameterT(1, 468.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		; // receive6::Feedback is automated
		
		jdelay_thiran.setParameterT(0, 1000.); // jdsp::jdelay_thiran::Limit
		;                                      // jdelay_thiran::DelayTime is automated
		
		;                                  // fix_delay1::DelayTime is automated
		fix_delay1.setParameterT(1, 512.); // core::fix_delay::FadeTime
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // branch16::Index is automated
		
		; // branch17::Index is automated
		
		; // faust18::Log2Delay is automated
		
		; // faust19::Log2Delay is automated
		
		gain4.setParameterT(0, 0.);  // core::gain::Gain
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // minmax1::Value is automated
		minmax1.setParameterT(1, 0.); // control::minmax::Minimum
		minmax1.setParameterT(2, 2.); // control::minmax::Maximum
		minmax1.setParameterT(3, 1.); // control::minmax::Skew
		minmax1.setParameterT(4, 0.); // control::minmax::Step
		minmax1.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // faust8::delayms is automated
		; // faust8::feedback is automated
		
		;                                 // one_pole1::Frequency is automated
		one_pole1.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // branch2::Index is automated
		
		; // branch4::Index is automated
		
		; // faust9::Log2Delay is automated
		
		; // faust10::Log2Delay is automated
		
		gain3.setParameterT(0, -0.799999); // core::gain::Gain
		gain3.setParameterT(1, 20.);       // core::gain::Smoothing
		gain3.setParameterT(2, 0.);        // core::gain::ResetValue
		
		;                           // faust::decal is automated
		;                           // faust::feedback is automated
		faust.setParameterT(2, 1.); // core::faust::population
		;                           // faust::speed is automated
		;                           // faust::taille is automated
		
		;                                 // one_pole2::Frequency is automated
		one_pole2.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole2.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole2.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole2.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole2.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // branch5::Index is automated
		
		; // branch6::Index is automated
		
		; // faust1::Log2Delay is automated
		
		; // faust4::Log2Delay is automated
		
		; // sliderbank::Value is automated
		
		; // sliderbank1::Value is automated
		
		; // receive7::Feedback is automated
		
		;                                   // tempo_sync9::Tempo is automated
		;                                   // tempo_sync9::Multiplier is automated
		tempo_sync9.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync9.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // branch18::Index is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		oscillator.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		; // sampleandhold::Counter is automated
		
		;                            // gain6::Gain is automated
		gain6.setParameterT(1, 20.); // core::gain::Smoothing
		gain6.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma17::Value is automated
		; // pma17::Multiply is automated
		; // pma17::Add is automated
		
		pma18.setParameterT(0, 0.); // control::pma::Value
		pma18.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma18::Add is automated
		
		;                                    // tempo_sync2::Tempo is automated
		;                                    // tempo_sync2::Multiplier is automated
		tempo_sync2.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync2.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		;                                                    // smoothed_parameter_unscaled::Value is automated
		smoothed_parameter_unscaled.setParameterT(1, 187.2); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		;                                  // fix_delay2::DelayTime is automated
		fix_delay2.setParameterT(1, 641.); // core::fix_delay::FadeTime
		
		pma2.setParameterT(0, 0.); // control::pma::Value
		pma2.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma2::Add is automated
		
		; // cable_table::Value is automated
		
		; // cable_table1::Value is automated
		
		; // pma19::Value is automated
		; // pma19::Multiply is automated
		; // pma19::Add is automated
		
		pma20.setParameterT(0, 0.); // control::pma::Value
		pma20.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma20::Add is automated
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf1::Mode is automated
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // comp1::Threshhold is automated
		comp1.setParameterT(1, 50.); // dynamics::comp::Attack
		comp1.setParameterT(2, 50.); // dynamics::comp::Release
		comp1.setParameterT(3, 2);   // dynamics::comp::Ratio
		comp1.setParameterT(4, 0.);  // dynamics::comp::Sidechain
		
		gain5.setParameterT(0, -11.); // core::gain::Gain
		gain5.setParameterT(1, 20.);  // core::gain::Smoothing
		gain5.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // receive15::Feedback is automated
		
		;                                    // tempo_sync24::Tempo is automated
		;                                    // tempo_sync24::Multiplier is automated
		tempo_sync24.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync24.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // branch26::Index is automated
		
		clear33.setParameterT(0, 0.); // math::clear::Value
		
		clear34.setParameterT(0, 0.); // math::clear::Value
		
		oscillator8.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator8.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator8.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator8.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator8.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator8.setParameterT(5, 1.);   // core::oscillator::Gain
		
		clear35.setParameterT(0, 0.); // math::clear::Value
		
		; // sampleandhold8::Counter is automated
		
		;                            // gain7::Gain is automated
		gain7.setParameterT(1, 20.); // core::gain::Smoothing
		gain7.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma56::Value is automated
		; // pma56::Multiply is automated
		; // pma56::Add is automated
		
		pma57.setParameterT(0, 0.); // control::pma::Value
		pma57.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma57::Add is automated
		
		;                                     // tempo_sync25::Tempo is automated
		;                                     // tempo_sync25::Multiplier is automated
		tempo_sync25.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync25.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		;                                                     // smoothed_parameter_unscaled1::Value is automated
		smoothed_parameter_unscaled1.setParameterT(1, 220.6); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled1.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		;                                   // fix_delay24::DelayTime is automated
		fix_delay24.setParameterT(1, 641.); // core::fix_delay::FadeTime
		
		pma58.setParameterT(0, 0.); // control::pma::Value
		pma58.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma58::Add is automated
		
		; // cable_table44::Value is automated
		
		; // cable_table45::Value is automated
		
		; // pma59::Value is automated
		; // pma59::Multiply is automated
		; // pma59::Add is automated
		
		pma60.setParameterT(0, 0.); // control::pma::Value
		pma60.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma60::Add is automated
		
		;                             // svf23::Frequency is automated
		;                             // svf23::Q is automated
		svf23.setParameterT(2, 0.);   // filters::svf::Gain
		svf23.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                             // svf23::Mode is automated
		svf23.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // comp23::Threshhold is automated
		comp23.setParameterT(1, 50.); // dynamics::comp::Attack
		comp23.setParameterT(2, 50.); // dynamics::comp::Release
		comp23.setParameterT(3, 2);   // dynamics::comp::Ratio
		comp23.setParameterT(4, 0.);  // dynamics::comp::Sidechain
		
		gain27.setParameterT(0, -12.); // core::gain::Gain
		gain27.setParameterT(1, 20.);  // core::gain::Smoothing
		gain27.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // receive14::Feedback is automated
		
		;                                    // tempo_sync22::Tempo is automated
		;                                    // tempo_sync22::Multiplier is automated
		tempo_sync22.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync22.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // branch25::Index is automated
		
		clear29.setParameterT(0, 0.); // math::clear::Value
		
		clear30.setParameterT(0, 0.); // math::clear::Value
		
		oscillator7.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator7.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator7.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator7.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator7.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator7.setParameterT(5, 1.);   // core::oscillator::Gain
		
		clear31.setParameterT(0, 0.); // math::clear::Value
		
		; // sampleandhold7::Counter is automated
		
		;                            // gain8::Gain is automated
		gain8.setParameterT(1, 20.); // core::gain::Smoothing
		gain8.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma51::Value is automated
		; // pma51::Multiply is automated
		; // pma51::Add is automated
		
		pma52.setParameterT(0, 0.); // control::pma::Value
		pma52.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma52::Add is automated
		
		;                                     // tempo_sync23::Tempo is automated
		;                                     // tempo_sync23::Multiplier is automated
		tempo_sync23.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync23.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		;                                                     // smoothed_parameter_unscaled6::Value is automated
		smoothed_parameter_unscaled6.setParameterT(1, 256.4); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled6.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		;                                   // fix_delay23::DelayTime is automated
		fix_delay23.setParameterT(1, 641.); // core::fix_delay::FadeTime
		
		pma53.setParameterT(0, 0.); // control::pma::Value
		pma53.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma53::Add is automated
		
		; // cable_table42::Value is automated
		
		; // cable_table43::Value is automated
		
		; // pma54::Value is automated
		; // pma54::Multiply is automated
		; // pma54::Add is automated
		
		pma55.setParameterT(0, 0.); // control::pma::Value
		pma55.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma55::Add is automated
		
		;                             // svf22::Frequency is automated
		;                             // svf22::Q is automated
		svf22.setParameterT(2, 0.);   // filters::svf::Gain
		svf22.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                             // svf22::Mode is automated
		svf22.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // comp22::Threshhold is automated
		comp22.setParameterT(1, 50.); // dynamics::comp::Attack
		comp22.setParameterT(2, 50.); // dynamics::comp::Release
		comp22.setParameterT(3, 2);   // dynamics::comp::Ratio
		comp22.setParameterT(4, 0.);  // dynamics::comp::Sidechain
		
		gain26.setParameterT(0, -12.); // core::gain::Gain
		gain26.setParameterT(1, 20.);  // core::gain::Smoothing
		gain26.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // receive13::Feedback is automated
		
		;                                    // tempo_sync20::Tempo is automated
		;                                    // tempo_sync20::Multiplier is automated
		tempo_sync20.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync20.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // branch24::Index is automated
		
		clear25.setParameterT(0, 0.); // math::clear::Value
		
		clear26.setParameterT(0, 0.); // math::clear::Value
		
		oscillator6.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator6.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator6.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator6.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator6.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator6.setParameterT(5, 1.);   // core::oscillator::Gain
		
		clear27.setParameterT(0, 0.); // math::clear::Value
		
		; // sampleandhold6::Counter is automated
		
		;                            // gain9::Gain is automated
		gain9.setParameterT(1, 20.); // core::gain::Smoothing
		gain9.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma46::Value is automated
		; // pma46::Multiply is automated
		; // pma46::Add is automated
		
		pma47.setParameterT(0, 0.); // control::pma::Value
		pma47.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma47::Add is automated
		
		;                                     // tempo_sync21::Tempo is automated
		;                                     // tempo_sync21::Multiplier is automated
		tempo_sync21.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync21.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		;                                                     // smoothed_parameter_unscaled5::Value is automated
		smoothed_parameter_unscaled5.setParameterT(1, 197.8); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled5.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		;                                   // fix_delay22::DelayTime is automated
		fix_delay22.setParameterT(1, 641.); // core::fix_delay::FadeTime
		
		pma48.setParameterT(0, 0.); // control::pma::Value
		pma48.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma48::Add is automated
		
		; // cable_table40::Value is automated
		
		; // cable_table41::Value is automated
		
		; // pma49::Value is automated
		; // pma49::Multiply is automated
		; // pma49::Add is automated
		
		pma50.setParameterT(0, 0.); // control::pma::Value
		pma50.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma50::Add is automated
		
		;                             // svf21::Frequency is automated
		;                             // svf21::Q is automated
		svf21.setParameterT(2, 0.);   // filters::svf::Gain
		svf21.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf21.setParameterT(4, 0.);   // filters::svf::Mode
		svf21.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // comp21::Threshhold is automated
		comp21.setParameterT(1, 50.); // dynamics::comp::Attack
		comp21.setParameterT(2, 50.); // dynamics::comp::Release
		comp21.setParameterT(3, 2);   // dynamics::comp::Ratio
		comp21.setParameterT(4, 0.);  // dynamics::comp::Sidechain
		
		gain25.setParameterT(0, -12.); // core::gain::Gain
		gain25.setParameterT(1, 20.);  // core::gain::Smoothing
		gain25.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // receive12::Feedback is automated
		
		;                                    // tempo_sync18::Tempo is automated
		;                                    // tempo_sync18::Multiplier is automated
		tempo_sync18.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync18.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // branch23::Index is automated
		
		clear21.setParameterT(0, 0.); // math::clear::Value
		
		clear22.setParameterT(0, 0.); // math::clear::Value
		
		oscillator5.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator5.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator5.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator5.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator5.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator5.setParameterT(5, 1.);   // core::oscillator::Gain
		
		clear23.setParameterT(0, 0.); // math::clear::Value
		
		; // sampleandhold5::Counter is automated
		
		;                             // gain10::Gain is automated
		gain10.setParameterT(1, 20.); // core::gain::Smoothing
		gain10.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma41::Value is automated
		; // pma41::Multiply is automated
		; // pma41::Add is automated
		
		pma42.setParameterT(0, 0.); // control::pma::Value
		pma42.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma42::Add is automated
		
		;                                     // tempo_sync19::Tempo is automated
		;                                     // tempo_sync19::Multiplier is automated
		tempo_sync19.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync19.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		;                                                     // smoothed_parameter_unscaled4::Value is automated
		smoothed_parameter_unscaled4.setParameterT(1, 155.9); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled4.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		;                                   // fix_delay21::DelayTime is automated
		fix_delay21.setParameterT(1, 641.); // core::fix_delay::FadeTime
		
		pma43.setParameterT(0, 0.); // control::pma::Value
		pma43.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma43::Add is automated
		
		; // cable_table38::Value is automated
		
		; // cable_table39::Value is automated
		
		; // pma44::Value is automated
		; // pma44::Multiply is automated
		; // pma44::Add is automated
		
		pma45.setParameterT(0, 0.); // control::pma::Value
		pma45.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma45::Add is automated
		
		;                             // svf20::Frequency is automated
		;                             // svf20::Q is automated
		svf20.setParameterT(2, 0.);   // filters::svf::Gain
		svf20.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                             // svf20::Mode is automated
		svf20.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // comp20::Threshhold is automated
		comp20.setParameterT(1, 50.); // dynamics::comp::Attack
		comp20.setParameterT(2, 50.); // dynamics::comp::Release
		comp20.setParameterT(3, 2);   // dynamics::comp::Ratio
		comp20.setParameterT(4, 0.);  // dynamics::comp::Sidechain
		
		gain24.setParameterT(0, -12.); // core::gain::Gain
		gain24.setParameterT(1, 20.);  // core::gain::Smoothing
		gain24.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // receive11::Feedback is automated
		
		;                                    // tempo_sync16::Tempo is automated
		;                                    // tempo_sync16::Multiplier is automated
		tempo_sync16.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync16.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // branch22::Index is automated
		
		clear17.setParameterT(0, 0.); // math::clear::Value
		
		clear18.setParameterT(0, 0.); // math::clear::Value
		
		oscillator4.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator4.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator4.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator4.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator4.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator4.setParameterT(5, 1.);   // core::oscillator::Gain
		
		clear19.setParameterT(0, 0.); // math::clear::Value
		
		; // sampleandhold4::Counter is automated
		
		;                             // gain11::Gain is automated
		gain11.setParameterT(1, 20.); // core::gain::Smoothing
		gain11.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma36::Value is automated
		; // pma36::Multiply is automated
		; // pma36::Add is automated
		
		pma37.setParameterT(0, 0.); // control::pma::Value
		pma37.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma37::Add is automated
		
		;                                     // tempo_sync17::Tempo is automated
		;                                     // tempo_sync17::Multiplier is automated
		tempo_sync17.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync17.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		;                                                     // smoothed_parameter_unscaled3::Value is automated
		smoothed_parameter_unscaled3.setParameterT(1, 153.8); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled3.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		;                                   // fix_delay20::DelayTime is automated
		fix_delay20.setParameterT(1, 641.); // core::fix_delay::FadeTime
		
		pma38.setParameterT(0, 0.); // control::pma::Value
		pma38.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma38::Add is automated
		
		; // cable_table36::Value is automated
		
		; // cable_table37::Value is automated
		
		; // pma39::Value is automated
		; // pma39::Multiply is automated
		; // pma39::Add is automated
		
		pma40.setParameterT(0, 0.); // control::pma::Value
		pma40.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma40::Add is automated
		
		;                             // svf19::Frequency is automated
		;                             // svf19::Q is automated
		svf19.setParameterT(2, 0.);   // filters::svf::Gain
		svf19.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                             // svf19::Mode is automated
		svf19.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // comp19::Threshhold is automated
		comp19.setParameterT(1, 50.); // dynamics::comp::Attack
		comp19.setParameterT(2, 50.); // dynamics::comp::Release
		comp19.setParameterT(3, 2);   // dynamics::comp::Ratio
		comp19.setParameterT(4, 0.);  // dynamics::comp::Sidechain
		
		gain23.setParameterT(0, -12.); // core::gain::Gain
		gain23.setParameterT(1, 20.);  // core::gain::Smoothing
		gain23.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // receive10::Feedback is automated
		
		;                                    // tempo_sync14::Tempo is automated
		;                                    // tempo_sync14::Multiplier is automated
		tempo_sync14.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync14.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // branch21::Index is automated
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		clear14.setParameterT(0, 0.); // math::clear::Value
		
		oscillator3.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator3.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator3.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator3.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator3.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator3.setParameterT(5, 1.);   // core::oscillator::Gain
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		; // sampleandhold3::Counter is automated
		
		;                             // gain12::Gain is automated
		gain12.setParameterT(1, 20.); // core::gain::Smoothing
		gain12.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma31::Value is automated
		; // pma31::Multiply is automated
		; // pma31::Add is automated
		
		pma32.setParameterT(0, 0.); // control::pma::Value
		pma32.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma32::Add is automated
		
		;                                     // tempo_sync15::Tempo is automated
		;                                     // tempo_sync15::Multiplier is automated
		tempo_sync15.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync15.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		;                                           // smoothed_parameter1::Value is automated
		smoothed_parameter1.setParameterT(1, 100.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter1.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		;                                   // fix_delay19::DelayTime is automated
		fix_delay19.setParameterT(1, 641.); // core::fix_delay::FadeTime
		
		pma33.setParameterT(0, 0.); // control::pma::Value
		pma33.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma33::Add is automated
		
		; // cable_table34::Value is automated
		
		; // cable_table35::Value is automated
		
		; // pma34::Value is automated
		; // pma34::Multiply is automated
		; // pma34::Add is automated
		
		pma35.setParameterT(0, 0.); // control::pma::Value
		pma35.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma35::Add is automated
		
		;                             // svf18::Frequency is automated
		;                             // svf18::Q is automated
		svf18.setParameterT(2, 0.);   // filters::svf::Gain
		svf18.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                             // svf18::Mode is automated
		svf18.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // comp18::Threshhold is automated
		comp18.setParameterT(1, 50.); // dynamics::comp::Attack
		comp18.setParameterT(2, 50.); // dynamics::comp::Release
		comp18.setParameterT(3, 2);   // dynamics::comp::Ratio
		comp18.setParameterT(4, 0.);  // dynamics::comp::Sidechain
		
		gain22.setParameterT(0, -12.); // core::gain::Gain
		gain22.setParameterT(1, 20.);  // core::gain::Smoothing
		gain22.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // receive9::Feedback is automated
		
		;                                    // tempo_sync12::Tempo is automated
		;                                    // tempo_sync12::Multiplier is automated
		tempo_sync12.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync12.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // branch20::Index is automated
		
		clear9.setParameterT(0, 0.); // math::clear::Value
		
		clear10.setParameterT(0, 0.); // math::clear::Value
		
		oscillator2.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator2.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator2.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator2.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator2.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator2.setParameterT(5, 1.);   // core::oscillator::Gain
		
		clear11.setParameterT(0, 0.); // math::clear::Value
		
		; // sampleandhold2::Counter is automated
		
		;                             // gain13::Gain is automated
		gain13.setParameterT(1, 20.); // core::gain::Smoothing
		gain13.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma26::Value is automated
		; // pma26::Multiply is automated
		; // pma26::Add is automated
		
		pma27.setParameterT(0, 0.); // control::pma::Value
		pma27.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma27::Add is automated
		
		;                                     // tempo_sync13::Tempo is automated
		;                                     // tempo_sync13::Multiplier is automated
		tempo_sync13.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync13.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		;                                                     // smoothed_parameter_unscaled2::Value is automated
		smoothed_parameter_unscaled2.setParameterT(1, 170.8); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled2.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		;                                   // fix_delay18::DelayTime is automated
		fix_delay18.setParameterT(1, 641.); // core::fix_delay::FadeTime
		
		pma28.setParameterT(0, 0.); // control::pma::Value
		pma28.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma28::Add is automated
		
		; // cable_table32::Value is automated
		
		; // cable_table33::Value is automated
		
		; // pma29::Value is automated
		; // pma29::Multiply is automated
		; // pma29::Add is automated
		
		pma30.setParameterT(0, 0.); // control::pma::Value
		pma30.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma30::Add is automated
		
		;                             // svf17::Frequency is automated
		;                             // svf17::Q is automated
		svf17.setParameterT(2, 0.);   // filters::svf::Gain
		svf17.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                             // svf17::Mode is automated
		svf17.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // comp17::Threshhold is automated
		comp17.setParameterT(1, 50.); // dynamics::comp::Attack
		comp17.setParameterT(2, 50.); // dynamics::comp::Release
		comp17.setParameterT(3, 2);   // dynamics::comp::Ratio
		comp17.setParameterT(4, 0.);  // dynamics::comp::Sidechain
		
		gain21.setParameterT(0, -12.); // core::gain::Gain
		gain21.setParameterT(1, 31.7); // core::gain::Smoothing
		gain21.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // branch19::Index is automated
		
		; // branch27::Index is automated
		
		faust17.setParameterT(0, 16.); // core::faust::Log2Delay
		
		faust20.setParameterT(0, 15.); // core::faust::Log2Delay
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.528608);
		this->setParameterT(1, 0.791198);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.323311);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 0.42);
		this->setParameterT(10, 4.);
		this->setParameterT(11, 4.);
		this->setParameterT(12, 0.47);
		this->setParameterT(13, 0.52);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.01);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 0.);
		this->setParameterT(19, 0.);
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
		
		this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // dlay_impl::global_cable_t<NV>
		this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // dlay_impl::global_cable3_t<NV>
		this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // dlay_impl::global_cable2_t<NV>
		this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // dlay_impl::global_cable1_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(1).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);         // dlay_impl::peak1_t<NV>
		this->getT(1).getT(1).getT(1).getT(0).                                           // dlay_impl::comp_t
        getT(1).getT(2).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).getT(0).getT(0).setExternalData(b, index); // dlay_impl::sliderbank_t<NV>
		this->getT(1).getT(1).getT(1).getT(5).getT(0).getT(1).setExternalData(b, index); // dlay_impl::sliderbank1_t<NV>
		this->getT(1).getT(1).getT(1).getT(5).getT(1).                                   // dlay_impl::oscillator_t<NV>
        getT(0).getT(1).getT(1).getT(1).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::peak_t<NV>
        getT(1).getT(0).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table_t<NV>
        getT(1).getT(0).getT(3).getT(0).
        getT(4).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table1_t
        getT(1).getT(0).getT(3).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::comp1_t
        getT(1).getT(0).getT(3).getT(0).
        getT(8).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).getT(1).  // dlay_impl::oscillator8_t<NV>
        getT(1).getT(1).getT(1).getT(1).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::peak8_t<NV>
        getT(1).getT(1).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table44_t<NV>
        getT(1).getT(1).getT(3).getT(0).
        getT(4).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table45_t
        getT(1).getT(1).getT(3).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::comp23_t
        getT(1).getT(1).getT(3).getT(0).
        getT(8).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).getT(1).  // dlay_impl::oscillator7_t<NV>
        getT(2).getT(1).getT(1).getT(1).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::peak7_t<NV>
        getT(1).getT(2).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table42_t<NV>
        getT(1).getT(2).getT(3).getT(0).
        getT(4).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table43_t
        getT(1).getT(2).getT(3).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::comp22_t
        getT(1).getT(2).getT(3).getT(0).
        getT(8).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).getT(1).  // dlay_impl::oscillator6_t<NV>
        getT(3).getT(1).getT(1).getT(1).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::peak6_t<NV>
        getT(1).getT(3).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table40_t<NV>
        getT(1).getT(3).getT(3).getT(0).
        getT(4).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table41_t
        getT(1).getT(3).getT(3).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::comp21_t
        getT(1).getT(3).getT(3).getT(0).
        getT(8).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).getT(1).  // dlay_impl::oscillator5_t<NV>
        getT(4).getT(1).getT(1).getT(1).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::peak5_t<NV>
        getT(1).getT(4).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table38_t<NV>
        getT(1).getT(4).getT(3).getT(0).
        getT(4).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table39_t
        getT(1).getT(4).getT(3).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::comp20_t
        getT(1).getT(4).getT(3).getT(0).
        getT(8).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).getT(1).  // dlay_impl::oscillator4_t<NV>
        getT(5).getT(1).getT(1).getT(1).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::peak4_t<NV>
        getT(1).getT(5).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table36_t<NV>
        getT(1).getT(5).getT(3).getT(0).
        getT(4).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table37_t
        getT(1).getT(5).getT(3).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::comp19_t
        getT(1).getT(5).getT(3).getT(0).
        getT(8).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).getT(1).  // dlay_impl::oscillator3_t<NV>
        getT(6).getT(1).getT(1).getT(1).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::peak3_t<NV>
        getT(1).getT(6).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table34_t<NV>
        getT(1).getT(6).getT(3).getT(0).
        getT(4).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::cable_table35_t
        getT(1).getT(6).getT(3).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).          // dlay_impl::comp18_t
        getT(1).getT(6).getT(3).getT(0).
        getT(8).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).getT(1).  // dlay_impl::oscillator2_t<NV>
        getT(7).getT(1).getT(1).getT(1).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).  // dlay_impl::peak2_t<NV>
        getT(1).getT(7).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).  // dlay_impl::cable_table32_t<NV>
        getT(1).getT(7).getT(3).getT(0).
        getT(4).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).  // dlay_impl::cable_table33_t
        getT(1).getT(7).getT(3).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(1).getT(1).getT(1).getT(5).  // dlay_impl::comp17_t
        getT(1).getT(7).getT(3).getT(0).
        getT(8).setExternalData(b, index);
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
using dlay = wrap::node<dlay_impl::instance<NV>>;
}


