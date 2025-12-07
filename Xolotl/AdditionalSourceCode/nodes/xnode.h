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
using oscillator9_t = wrap::no_data<core::oscillator<NV>>;
template <int NV> using oscillator11_t = oscillator9_t<NV>;
template <int NV>
using file_player5_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<0>>;

template <int NV> using oscillator13_t = oscillator9_t<NV>;
template <int NV> using oscillator15_t = oscillator9_t<NV>;

template <int NV>
using pma_unscaled3_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<oscillator13_t<NV>, 2>, 
                                           parameter::plain<oscillator15_t<NV>, 2>>;

template <int NV>
using pma_unscaled3_t = control::pma_unscaled<NV, pma_unscaled3_mod<NV>>;

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
                                  wrap::fix<2, oscillator13_t<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, oscillator15_t<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain2_t<NV>>, 
                                 chain7_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader_t<NV>>, 
                                  split_t<NV>>;

template <int NV>
using converter_t = control::converter<parameter::plain<fx::sampleandhold<NV>, 0>, 
                                       conversion_logic::freq2samples>;
template <int NV>
using normaliser_t = control::normaliser<parameter::plain<converter_t<NV>, 0>>;

namespace chain45_t_parameters
{
DECLARE_PARAMETER_RANGE(harm_InputRange, 
                        1., 
                        16.);
DECLARE_PARAMETER_RANGE_SKEW(harm_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using harm_0 = parameter::from0To1<xnode_impl::normaliser_t<NV>, 
                                   0, 
                                   harm_0Range>;

template <int NV>
using harm = parameter::chain<harm_InputRange, harm_0<NV>>;

}

template <int NV>
using chain45_t = container::chain<chain45_t_parameters::harm<NV>, 
                                   wrap::fix<2, pma_unscaled3_t<NV>>, 
                                   chain1_t<NV>, 
                                   normaliser_t<NV>, 
                                   converter_t<NV>, 
                                   fx::sampleandhold<NV>>;
template <int NV> using oscillator12_t = oscillator9_t<NV>;
template <int NV> using oscillator14_t = oscillator9_t<NV>;

template <int NV>
using pma_unscaled1_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<oscillator9_t<NV>, 2>, 
                                           parameter::plain<core::phasor<NV>, 2>, 
                                           parameter::plain<oscillator11_t<NV>, 2>, 
                                           parameter::plain<file_player5_t<NV>, 3>, 
                                           parameter::plain<core::phasor<NV>, 2>, 
                                           parameter::plain<chain45_t<NV>, 0>, 
                                           parameter::plain<oscillator12_t<NV>, 2>, 
                                           parameter::plain<core::phasor<NV>, 2>, 
                                           parameter::plain<core::fm, 2>, 
                                           parameter::plain<oscillator14_t<NV>, 2>>;

template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, pma_unscaled1_mod<NV>>;
template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, 
                                             parameter::plain<pma_unscaled1_t<NV>, 2>>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled_t<NV>, 2>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, minmax_t<NV>>, 
                                      pma_unscaled_t<NV>, 
                                      pma_unscaled1_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV> using xfader2_c0 = xfader_c0<NV>;

template <int NV> using xfader2_c1 = xfader_c0<NV>;

template <int NV>
using xfader2_multimod = parameter::list<xfader2_c0<NV>, xfader2_c1<NV>>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::rms>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator11_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator12_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain16_t<NV>>, 
                                  chain20_t<NV>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader2_t<NV>>, 
                                   split2_t<NV>>;

DECLARE_PARAMETER_RANGE(smoothed_parameter3_modRange, 
                        0.1, 
                        5.);

template <int NV>
using smoothed_parameter3_mod = parameter::from0To1<math::pi<NV>, 
                                                    0, 
                                                    smoothed_parameter3_modRange>;

template <int NV>
using smoothed_parameter3_t = wrap::mod<smoothed_parameter3_mod<NV>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator9_t<NV>>, 
                                   smoothed_parameter3_t<NV>, 
                                   math::pi<NV>, 
                                   math::sin<NV>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::phasor<NV>>, 
                                   core::mono2stereo, 
                                   core::gain<NV>, 
                                   math::fmod<NV>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator14_t<NV>>, 
                                   core::fm, 
                                   core::mono2stereo>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::phasor<NV>>, 
                                   core::mono2stereo, 
                                   core::gain<NV>, 
                                   math::pi<NV>, 
                                   math::rect<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain34_t<NV>>, 
                                    chain11_t<NV>, 
                                    chain12_t<NV>, 
                                    chain13_t<NV>, 
                                    chain22_t<NV>, 
                                    chain45_t<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, branch3_t<NV>>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<2, file_player5_t<NV>>, 
                                   wrap::no_process<math::fmod<NV>>, 
                                   wrap::no_process<math::pi<NV>>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain37_t<NV>>>;

template <int NV>
using smoothed_parameter_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using file_player6_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::phasor<NV>>, 
                                   smoothed_parameter_t<NV>, 
                                   core::gain<NV>, 
                                   math::add<NV>, 
                                   file_player6_t<NV>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain43_t<NV>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain8_t<NV>>, 
                                   chain15_t<NV>, 
                                   chain14_t<NV>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch_t<NV>>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain32_t<NV>>>;

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV> using ramp1_t = ramp_t<NV>;
template <int NV> using ramp3_t = ramp_t<NV>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>, 
                                        parameter::plain<ramp_t<NV>, 0>, 
                                        parameter::plain<ramp1_t<NV>, 0>, 
                                        parameter::plain<ramp3_t<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;
template <int NV> using oscillator_t = oscillator9_t<NV>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, wrap::no_process<math::clear<NV>>>, 
                                   wrap::no_process<math::sig2mod<NV>>, 
                                   oscillator_t<NV>, 
                                   fx::sampleandhold<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, ramp_t<NV>>, 
                                   math::pi<NV>, 
                                   math::sin<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain10_t<NV>>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, ramp1_t<NV>>, 
                                   math::mod_inv<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain25_t<NV>>>;

template <int NV>
using simple_ar_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                           parameter::empty>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod<NV>>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<simple_ar_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, ramp3_t<NV>>, 
                                   math::rect<NV>, 
                                   peak1_t<NV>, 
                                   math::clear<NV>, 
                                   simple_ar_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain28_t<NV>>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain21_t<NV>>, 
                                    chain23_t<NV>, 
                                    chain24_t<NV>, 
                                    chain27_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma_mod_0 = parameter::from0To1<filters::svf<NV>, 
                                      0, 
                                      pma_mod_0Range>;

template <int NV> using pma_mod_1 = pma_mod_0<NV>;

template <int NV> using pma_mod_2 = pma_mod_0<NV>;

template <int NV>
using pma_mod_3 = parameter::from0To1<filters::allpass<NV>, 
                                      0, 
                                      pma_mod_0Range>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 pma_mod_0<NV>, 
                                 pma_mod_1<NV>, 
                                 pma_mod_2<NV>, 
                                 pma_mod_3<NV>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;

template <int NV> using pma1_mod = xfader_c0<NV>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<pma_unscaled1_t<NV>, 0>, 
                                  parameter::plain<pma_t<NV>, 0>, 
                                  parameter::plain<pma1_t<NV>, 0>, 
                                  parameter::plain<pma_unscaled3_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using modchain8_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, tempo_sync_t<NV>>, 
                                      branch1_t<NV>, 
                                      peak_t<NV>>;

template <int NV>
using modchain8_t = wrap::control_rate<modchain8_t_<NV>>;

template <int NV> using xfader1_c0 = xfader_c0<NV>;

template <int NV> using xfader1_c1 = xfader_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, pma_t<NV>>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, filters::svf<NV>>, 
                                    filters::svf<NV>, 
                                    filters::svf<NV>, 
                                    filters::allpass<NV>>;

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

struct cable_table_t_data
{
	span<float, 512> data =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		0.998332f, 0.994386f, 0.99044f, 0.986494f, 0.982548f, 0.978602f,
		0.974656f, 0.97071f, 0.966764f, 0.962818f, 0.958872f, 0.954926f,
		0.95098f, 0.947034f, 0.943088f, 0.939142f, 0.935196f, 0.93125f,
		0.927304f, 0.923358f, 0.919412f, 0.915466f, 0.91152f, 0.907574f,
		0.903628f, 0.899682f, 0.895736f, 0.89179f, 0.887844f, 0.883898f,
		0.879953f, 0.876007f, 0.872061f, 0.868115f, 0.864169f, 0.860223f,
		0.856277f, 0.852331f, 0.848385f, 0.844439f, 0.840493f, 0.836547f,
		0.832601f, 0.828655f, 0.824709f, 0.820763f, 0.816817f, 0.812871f,
		0.808925f, 0.804979f, 0.801033f, 0.797087f, 0.793141f, 0.789195f,
		0.785249f, 0.781303f, 0.777357f, 0.773411f, 0.769465f, 0.765519f,
		0.761573f, 0.757627f, 0.753681f, 0.749735f, 0.745789f, 0.741843f,
		0.737897f, 0.733951f, 0.730005f, 0.726059f, 0.722113f, 0.718168f,
		0.714222f, 0.710276f, 0.70633f, 0.702384f, 0.698438f, 0.694492f,
		0.690546f, 0.6866f, 0.682654f, 0.678708f, 0.674762f, 0.670816f,
		0.66687f, 0.662924f, 0.658978f, 0.655032f, 0.651086f, 0.64714f,
		0.643194f, 0.639248f, 0.635302f, 0.631356f, 0.62741f, 0.623464f,
		0.619518f, 0.615572f, 0.611626f, 0.60768f, 0.603734f, 0.599788f,
		0.595842f, 0.591896f, 0.58795f, 0.584004f, 0.580058f, 0.576112f,
		0.572166f, 0.56822f, 0.564274f, 0.560328f, 0.556383f, 0.552437f,
		0.548491f, 0.544545f, 0.540599f, 0.536653f, 0.532707f, 0.528761f,
		0.524815f, 0.520869f, 0.516923f, 0.512977f, 0.509031f, 0.505085f,
		0.501139f, 0.497193f, 0.493247f, 0.489301f, 0.485355f, 0.481409f,
		0.477463f, 0.473517f, 0.469571f, 0.465625f, 0.461679f, 0.457733f,
		0.453787f, 0.449841f, 0.445895f, 0.441949f, 0.438003f, 0.434057f,
		0.430111f, 0.426165f, 0.422219f, 0.418273f, 0.414327f, 0.410381f,
		0.406435f, 0.402489f, 0.398544f, 0.394598f, 0.390652f, 0.386706f,
		0.38276f, 0.378814f, 0.374868f, 0.370922f, 0.366976f, 0.36303f,
		0.359084f, 0.355138f, 0.351192f, 0.347246f, 0.3433f, 0.339354f,
		0.335408f, 0.331462f, 0.327516f, 0.32357f, 0.319624f, 0.315678f,
		0.311732f, 0.307786f, 0.30384f, 0.299894f, 0.295948f, 0.292002f,
		0.288056f, 0.28411f, 0.280164f, 0.276218f, 0.272272f, 0.268326f,
		0.26438f, 0.260434f, 0.256488f, 0.252542f, 0.248596f, 0.24465f,
		0.240705f, 0.236759f, 0.232812f, 0.228867f, 0.224921f, 0.220975f,
		0.217029f, 0.213083f, 0.209137f, 0.205191f, 0.201245f, 0.197299f,
		0.193353f, 0.189407f, 0.185461f, 0.181515f, 0.177569f, 0.173623f,
		0.169677f, 0.165731f, 0.161785f, 0.157839f, 0.153893f, 0.149947f,
		0.146001f, 0.142055f, 0.138109f, 0.134163f, 0.130217f, 0.126271f,
		0.122325f, 0.118379f, 0.114433f, 0.110487f, 0.106541f, 0.102595f,
		0.0986494f, 0.0947034f, 0.0907575f, 0.0868114f, 0.0828655f, 0.0789196f,
		0.0749735f, 0.0710276f, 0.0670816f, 0.0631356f, 0.0591896f, 0.0552437f,
		0.0512978f, 0.0473517f, 0.0434057f, 0.0394597f, 0.0355138f, 0.0315678f,
		0.0276219f, 0.0236759f, 0.0197299f, 0.015784f, 0.0118378f, 0.00789195f,
		0.00394595f, 0.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<pma1_t<NV>, 2>>, 
                                 data::embedded::table<cable_table_t_data>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table_t<NV>>, 
                                   pma1_t<NV>>;

template <int NV>
using modchain7_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain40_t<NV>>>;

template <int NV>
using modchain7_t = wrap::control_rate<modchain7_t_<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, modchain1_t<NV>>, 
                                 chain9_t<NV>, 
                                 modchain8_t<NV>, 
                                 chain4_t<NV>, 
                                 modchain7_t<NV>, 
                                 core::gain<NV>, 
                                 core::gain<NV>>;

namespace xnode_t_parameters
{
// Parameter list for xnode_impl::xnode_t ----------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(Mode_InputRange, 
                             1., 
                             6., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Mode_0Range, 
                             0., 
                             5., 
                             1.);

template <int NV>
using Mode_0 = parameter::from0To1<xnode_impl::branch3_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode = parameter::chain<Mode_InputRange, Mode_0<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(FxMixRange, 
                             0., 
                             10000., 
                             0.30103);

template <int NV>
using FxMix = parameter::from0To1<xnode_impl::simple_ar_t<NV>, 
                                  0, 
                                  FxMixRange>;

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

template <int NV>
using shPitch = parameter::chain<ranges::Identity, 
                                 parameter::plain<xnode_impl::pma_unscaled1_t<NV>, 1>, 
                                 parameter::plain<xnode_impl::pma_unscaled3_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_SKEW(FilterRes_InputRange, 
                             0.3, 
                             1., 
                             0.264718);
DECLARE_PARAMETER_RANGE_SKEW(FilterRes_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using FilterRes_0 = parameter::from0To1<filters::svf<NV>, 
                                        1, 
                                        FilterRes_0Range>;

template <int NV> using FilterRes_1 = FilterRes_0<NV>;

template <int NV> using FilterRes_2 = FilterRes_0<NV>;

template <int NV>
using FilterRes_3 = parameter::from0To1<filters::allpass<NV>, 
                                        1, 
                                        FilterRes_0Range>;

template <int NV>
using FilterRes = parameter::chain<FilterRes_InputRange, 
                                   FilterRes_0<NV>, 
                                   FilterRes_1<NV>, 
                                   FilterRes_2<NV>, 
                                   FilterRes_3<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(ShSmooth_InputRange, 
                             0., 
                             2000., 
                             0.231378);

template <int NV>
using ShSmooth = parameter::chain<ShSmooth_InputRange, 
                                  parameter::plain<xnode_impl::ramp_t<NV>, 1>, 
                                  parameter::plain<xnode_impl::ramp1_t<NV>, 1>, 
                                  parameter::plain<xnode_impl::ramp3_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(OscShapes_1Range, 
                             0., 
                             20., 
                             0.1);

template <int NV>
using OscShapes_1 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        OscShapes_1Range>;

template <int NV> using OscShapes_2 = OscShapes_1<NV>;

template <int NV>
using OscShapes = parameter::chain<ranges::Identity, 
                                   parameter::plain<xnode_impl::smoothed_parameter3_t<NV>, 0>, 
                                   OscShapes_1<NV>, 
                                   OscShapes_2<NV>, 
                                   parameter::plain<xnode_impl::xfader2_t<NV>, 0>, 
                                   parameter::plain<core::fm, 1>, 
                                   parameter::plain<xnode_impl::xfader_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(TYPE_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(TYPE_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using TYPE_0 = parameter::from0To1<xnode_impl::branch_t<NV>, 
                                   0, 
                                   TYPE_0Range>;

template <int NV>
using TYPE = parameter::chain<TYPE_InputRange, TYPE_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ShSinMixRange, 
                             0., 
                             3., 
                             1.);

template <int NV>
using ShSinMix = parameter::from0To1<xnode_impl::branch1_t<NV>, 
                                     0, 
                                     ShSinMixRange>;

template <int NV>
using UserInput = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xnode_impl::xfader_c0Range>;

template <int NV>
using snap_0 = parameter::from0To1<core::gain<NV>, 
                                   2, 
                                   xnode_impl::xfader_c0Range>;

template <int NV> using snap_1 = snap_0<NV>;

template <int NV> using snap_2 = snap_0<NV>;

template <int NV> using snap_3 = snap_0<NV>;

template <int NV> using snap_4 = snap_0<NV>;

template <int NV> using snap_5 = snap_0<NV>;

template <int NV>
using snap = parameter::chain<ranges::Identity, 
                              snap_0<NV>, 
                              snap_1<NV>, 
                              snap_2<NV>, 
                              snap_3<NV>, 
                              snap_4<NV>, 
                              snap_5<NV>>;

DECLARE_PARAMETER_RANGE(ShToGain_0Range, 
                        -1., 
                        1.);

template <int NV>
using ShToGain_0 = parameter::from0To1<xnode_impl::pma1_t<NV>, 
                                       1, 
                                       ShToGain_0Range>;

template <int NV>
using ShToGain = parameter::chain<ranges::Identity, 
                                  ShToGain_0<NV>, 
                                  parameter::plain<xnode_impl::cable_table_t<NV>, 0>>;

template <int NV>
using SHInput = parameter::from0To1<xnode_impl::simple_ar_t<NV>, 
                                    1, 
                                    FxMixRange>;

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
using FxShDiv = parameter::plain<xnode_impl::tempo_sync_t<NV>, 
                                 1>;
template <int NV>
using FxShSync = parameter::plain<xnode_impl::tempo_sync_t<NV>, 
                                  2>;
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
using UserPs = parameter::plain<xnode_impl::smoothed_parameter_t<NV>, 
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
                                      DET<NV>, 
                                      ShSmooth<NV>, 
                                      OscShapes<NV>, 
                                      TYPE<NV>, 
                                      ShSinMix<NV>, 
                                      UserPs<NV>, 
                                      UserInput<NV>, 
                                      snap<NV>, 
                                      ShToGain<NV>, 
                                      SHInput<NV>>;
}

template <int NV>
using xnode_t_ = container::chain<xnode_t_parameters::xnode_t_plist<NV>, 
                                  wrap::fix<2, chain_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public xnode_impl::xnode_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(xnode);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(434)
		{
			0x005C, 0x0000, 0x0000, 0x6148, 0x6D72, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0001, 0x0000, 0x696D, 0x006E, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x0200, 0x0000, 0x6D00, 0x7861, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x4180, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0003, 0x0000, 0x7473, 0x7065, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0004, 0x0000, 0x6F4D, 0x6564, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x40C0, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0005, 0x0000, 0x7846, 0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x7480, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0600, 0x0000, 0x4600, 0x5678, 0x6C61, 0x6575, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0xD37A, 0x3F58, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0007, 0x0000, 0x7846, 0x6853, 0x6944, 0x0076, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x9000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x0800, 0x0000, 0x4600, 0x5378, 0x5368, 
            0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0900, 0x0000, 0x7300, 
            0x5068, 0x7469, 0x6863, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000A, 
            0x0000, 0x6946, 0x746C, 0x7265, 0x694D, 0x0078, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x0B00, 0x0000, 0x4600, 0x6C69, 0x6574, 0x5472, 0x7079, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x4000, 0x0040, 0x4000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x0C00, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x5272, 0x7365, 0x0000, 0x999A, 0x3E99, 0x0000, 0x3F80, 
            0x999A, 0x3E99, 0x8918, 0x3E87, 0x0000, 0x0000, 0x005C, 0x000D, 
            0x0000, 0x6946, 0x746C, 0x7265, 0x7543, 0x0074, 0x0000, 0x8000, 
            0x0024, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x0E00, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4672, 0x4D78, 
            0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0xBD38, 0x3BE9, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000F, 0x0000, 0x4544, 
            0x0054, 0x0000, 0x0000, 0x0000, 0x0000, 0x4640, 0x805E, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x1000, 0x0000, 0x5300, 0x5368, 
            0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 0x0000, 0xFA00, 0x0044, 
            0x0000, 0x6900, 0x6CEE, 0xCD3E, 0xCCCC, 0x5C3D, 0x1100, 0x0000, 
            0x4F00, 0x6373, 0x6853, 0x7061, 0x7365, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x4DEA, 0x3DAF, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0012, 0x0000, 0x5954, 0x4550, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0013, 0x0000, 0x6853, 0x6953, 0x4D6E, 0x7869, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0014, 0x0000, 0x7355, 0x7265, 0x7350, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x4DEA, 0x3EAA, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0015, 0x0000, 0x7355, 0x7265, 
            0x6E49, 0x7570, 0x0074, 0x0000, 0x0000, 0x0000, 0x8000, 0x9C3F, 
            0x90DE, 0x003D, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1600, 0x0000, 
            0x7300, 0x616E, 0x0070, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0400, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1700, 0x0000, 
            0x5300, 0x5468, 0x476F, 0x6961, 0x006E, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x2D3F, 0x0564, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x1800, 0x0000, 0x5300, 0x4948, 0x706E, 0x7475, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0xEF4E, 0x3F22, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000
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
		
		auto& chain = this->getT(0);                                                              // xnode_impl::chain_t<NV>
		auto& modchain1 = this->getT(0).getT(0);                                                  // xnode_impl::modchain1_t<NV>
		auto& minmax = this->getT(0).getT(0).getT(0);                                             // xnode_impl::minmax_t<NV>
		auto& pma_unscaled = this->getT(0).getT(0).getT(1);                                       // xnode_impl::pma_unscaled_t<NV>
		auto& pma_unscaled1 = this->getT(0).getT(0).getT(2);                                      // xnode_impl::pma_unscaled1_t<NV>
		auto& chain9 = this->getT(0).getT(1);                                                     // xnode_impl::chain9_t<NV>
		auto& chain32 = this->getT(0).getT(1).getT(0);                                            // xnode_impl::chain32_t<NV>
		auto& branch = this->getT(0).getT(1).getT(0).getT(0);                                     // xnode_impl::branch_t<NV>
		auto& chain8 = this->getT(0).getT(1).getT(0).getT(0).getT(0);                             // xnode_impl::chain8_t<NV>
		auto& branch3 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0);                    // xnode_impl::branch3_t<NV>
		auto& chain34 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);            // xnode_impl::chain34_t<NV>
		auto& xfader2 = this->getT(0).getT(1).getT(0).getT(0).                                    // xnode_impl::xfader2_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& split2 = this->getT(0).getT(1).getT(0).getT(0).                                     // xnode_impl::split2_t<NV>
                       getT(0).getT(0).getT(0).getT(1);
		auto& chain16 = this->getT(0).getT(1).getT(0).getT(0).                                    // xnode_impl::chain16_t<NV>
                        getT(0).getT(0).getT(0).getT(1).
                        getT(0);
		auto& oscillator11 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // xnode_impl::oscillator11_t<NV>
                             getT(0).getT(0).getT(1).getT(0).getT(0);
		auto& gain26 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                             // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(0).getT(1);
		auto& chain20 = this->getT(0).getT(1).getT(0).getT(0).                                    // xnode_impl::chain20_t<NV>
                        getT(0).getT(0).getT(0).getT(1).
                        getT(1);
		auto& oscillator12 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // xnode_impl::oscillator12_t<NV>
                             getT(0).getT(0).getT(1).getT(1).getT(0);
		auto& gain27 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                             // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(1).getT(1);
		auto& chain11 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(1);            // xnode_impl::chain11_t<NV>
		auto& oscillator9 = this->getT(0).getT(1).getT(0).getT(0).                                // xnode_impl::oscillator9_t<NV>
                            getT(0).getT(0).getT(1).getT(0);
		auto& smoothed_parameter3 = this->getT(0).getT(1).getT(0).getT(0).                        // xnode_impl::smoothed_parameter3_t<NV>
                                    getT(0).getT(0).getT(1).getT(1);
		auto& pi7 = this->getT(0).getT(1).getT(0).getT(0).                                        // math::pi<NV>
                    getT(0).getT(0).getT(1).getT(2);
		auto& sin1 = this->getT(0).getT(1).getT(0).getT(0).                                       // math::sin<NV>
                     getT(0).getT(0).getT(1).getT(3);
		auto& chain12 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(2);            // xnode_impl::chain12_t<NV>
		auto& phasor = this->getT(0).getT(1).getT(0).getT(0).                                     // core::phasor<NV>
                       getT(0).getT(0).getT(2).getT(0);
		auto& mono2stereo4 = this->getT(0).getT(1).getT(0).getT(0).                               // core::mono2stereo
                             getT(0).getT(0).getT(2).getT(1);
		auto& gain4 = this->getT(0).getT(1).getT(0).getT(0).                                      // core::gain<NV>
                      getT(0).getT(0).getT(2).getT(2);
		auto& fmod1 = this->getT(0).getT(1).getT(0).getT(0).                                      // math::fmod<NV>
                      getT(0).getT(0).getT(2).getT(3);
		auto& chain13 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(3);            // xnode_impl::chain13_t<NV>
		auto& oscillator14 = this->getT(0).getT(1).getT(0).getT(0).                               // xnode_impl::oscillator14_t<NV>
                             getT(0).getT(0).getT(3).getT(0);
		auto& fm = this->getT(0).getT(1).getT(0).getT(0).                                         // core::fm
                   getT(0).getT(0).getT(3).getT(1);
		auto& mono2stereo2 = this->getT(0).getT(1).getT(0).getT(0).                               // core::mono2stereo
                             getT(0).getT(0).getT(3).getT(2);
		auto& chain22 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(4);            // xnode_impl::chain22_t<NV>
		auto& phasor4 = this->getT(0).getT(1).getT(0).getT(0).                                    // core::phasor<NV>
                        getT(0).getT(0).getT(4).getT(0);
		auto& mono2stereo3 = this->getT(0).getT(1).getT(0).getT(0).                               // core::mono2stereo
                             getT(0).getT(0).getT(4).getT(1);
		auto& gain6 = this->getT(0).getT(1).getT(0).getT(0).                                      // core::gain<NV>
                      getT(0).getT(0).getT(4).getT(2);
		auto& pi1 = this->getT(0).getT(1).getT(0).getT(0).                                        // math::pi<NV>
                    getT(0).getT(0).getT(4).getT(3);
		auto& rect1 = this->getT(0).getT(1).getT(0).getT(0).                                      // math::rect<NV>
                      getT(0).getT(0).getT(4).getT(4);
		auto& chain45 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(5);            // xnode_impl::chain45_t<NV>
		auto& pma_unscaled3 = this->getT(0).getT(1).getT(0).getT(0).                              // xnode_impl::pma_unscaled3_t<NV>
                              getT(0).getT(0).getT(5).getT(0);
		auto& chain1 = this->getT(0).getT(1).getT(0).getT(0).                                     // xnode_impl::chain1_t<NV>
                       getT(0).getT(0).getT(5).getT(1);
		auto& xfader = this->getT(0).getT(1).getT(0).getT(0).                                     // xnode_impl::xfader_t<NV>
                       getT(0).getT(0).getT(5).getT(1).
                       getT(0);
		auto& split = this->getT(0).getT(1).getT(0).getT(0).                                      // xnode_impl::split_t<NV>
                      getT(0).getT(0).getT(5).getT(1).
                      getT(1);
		auto& chain2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                             // xnode_impl::chain2_t<NV>
                       getT(0).getT(5).getT(1).getT(1).getT(0);
		auto& oscillator13 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // xnode_impl::oscillator13_t<NV>
                             getT(0).getT(5).getT(1).getT(1).getT(0).
                             getT(0);
		auto& gain = this->getT(0).getT(1).getT(0).getT(0).getT(0).                               // core::gain<NV>
                     getT(0).getT(5).getT(1).getT(1).getT(0).
                     getT(1);
		auto& chain7 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                             // xnode_impl::chain7_t<NV>
                       getT(0).getT(5).getT(1).getT(1).getT(1);
		auto& oscillator15 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // xnode_impl::oscillator15_t<NV>
                             getT(0).getT(5).getT(1).getT(1).getT(1).
                             getT(0);
		auto& gain7 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                              // core::gain<NV>
                      getT(0).getT(5).getT(1).getT(1).getT(1).
                      getT(1);
		auto& normaliser = this->getT(0).getT(1).getT(0).getT(0).                                 // xnode_impl::normaliser_t<NV>
                           getT(0).getT(0).getT(5).getT(2);
		auto& converter = this->getT(0).getT(1).getT(0).getT(0).                                  // xnode_impl::converter_t<NV>
                          getT(0).getT(0).getT(5).getT(3);
		auto& sampleandhold2 = this->getT(0).getT(1).getT(0).getT(0).                             // fx::sampleandhold<NV>
                               getT(0).getT(0).getT(5).getT(4);
		auto& chain15 = this->getT(0).getT(1).getT(0).getT(0).getT(1);                            // xnode_impl::chain15_t<NV>
		auto& chain37 = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(0);                    // xnode_impl::chain37_t<NV>
		auto& file_player5 = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(0).getT(0);       // xnode_impl::file_player5_t<NV>
		auto& fmod = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(0).getT(1);               // wrap::no_process<math::fmod<NV>>
		auto& pi2 = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(0).getT(2);                // wrap::no_process<math::pi<NV>>
		auto& chain14 = this->getT(0).getT(1).getT(0).getT(0).getT(2);                            // xnode_impl::chain14_t<NV>
		auto& chain43 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);                    // xnode_impl::chain43_t<NV>
		auto& phasor5 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).getT(0);            // core::phasor<NV>
		auto& smoothed_parameter = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).getT(1); // xnode_impl::smoothed_parameter_t<NV>
		auto& gain11 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).getT(2);             // core::gain<NV>
		auto& add3 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).getT(3);               // math::add<NV>
		auto& file_player6 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).getT(4);       // xnode_impl::file_player6_t<NV>
		auto& modchain8 = this->getT(0).getT(2);                                                  // xnode_impl::modchain8_t<NV>
		auto& tempo_sync = this->getT(0).getT(2).getT(0);                                         // xnode_impl::tempo_sync_t<NV>
		auto& branch1 = this->getT(0).getT(2).getT(1);                                            // xnode_impl::branch1_t<NV>
		auto& chain21 = this->getT(0).getT(2).getT(1).getT(0);                                    // xnode_impl::chain21_t<NV>
		auto& clear = this->getT(0).getT(2).getT(1).getT(0).getT(0);                              // wrap::no_process<math::clear<NV>>
		auto& sig2mod2 = this->getT(0).getT(2).getT(1).getT(0).getT(1);                           // wrap::no_process<math::sig2mod<NV>>
		auto& oscillator = this->getT(0).getT(2).getT(1).getT(0).getT(2);                         // xnode_impl::oscillator_t<NV>
		auto& sampleandhold1 = this->getT(0).getT(2).getT(1).getT(0).getT(3);                     // fx::sampleandhold<NV>
		auto& chain23 = this->getT(0).getT(2).getT(1).getT(1);                                    // xnode_impl::chain23_t<NV>
		auto& chain10 = this->getT(0).getT(2).getT(1).getT(1).getT(0);                            // xnode_impl::chain10_t<NV>
		auto& ramp = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(0);                       // xnode_impl::ramp_t<NV>
		auto& pi = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1);                         // math::pi<NV>
		auto& sin2 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2);                       // math::sin<NV>
		auto& chain24 = this->getT(0).getT(2).getT(1).getT(2);                                    // xnode_impl::chain24_t<NV>
		auto& chain25 = this->getT(0).getT(2).getT(1).getT(2).getT(0);                            // xnode_impl::chain25_t<NV>
		auto& ramp1 = this->getT(0).getT(2).getT(1).getT(2).getT(0).getT(0);                      // xnode_impl::ramp1_t<NV>
		auto& mod_inv1 = this->getT(0).getT(2).getT(1).getT(2).getT(0).getT(1);                   // math::mod_inv<NV>
		auto& chain27 = this->getT(0).getT(2).getT(1).getT(3);                                    // xnode_impl::chain27_t<NV>
		auto& chain28 = this->getT(0).getT(2).getT(1).getT(3).getT(0);                            // xnode_impl::chain28_t<NV>
		auto& ramp3 = this->getT(0).getT(2).getT(1).getT(3).getT(0).getT(0);                      // xnode_impl::ramp3_t<NV>
		auto& rect = this->getT(0).getT(2).getT(1).getT(3).getT(0).getT(1);                       // math::rect<NV>
		auto& peak1 = this->getT(0).getT(2).getT(1).getT(3).getT(0).getT(2);                      // xnode_impl::peak1_t<NV>
		auto& clear1 = this->getT(0).getT(2).getT(1).getT(3).getT(0).getT(3);                     // math::clear<NV>
		auto& simple_ar = this->getT(0).getT(2).getT(1).getT(3).getT(0).getT(4);                  // xnode_impl::simple_ar_t<NV>
		auto& add = this->getT(0).getT(2).getT(1).getT(3).getT(0).getT(5);                        // math::add<NV>
		auto& peak = this->getT(0).getT(2).getT(2);                                               // xnode_impl::peak_t<NV>
		auto& chain4 = this->getT(0).getT(3);                                                     // xnode_impl::chain4_t<NV>
		auto& xfader1 = this->getT(0).getT(3).getT(0);                                            // xnode_impl::xfader1_t<NV>
		auto& split1 = this->getT(0).getT(3).getT(1);                                             // xnode_impl::split1_t<NV>
		auto& chain5 = this->getT(0).getT(3).getT(1).getT(0);                                     // xnode_impl::chain5_t<NV>
		auto& gain2 = this->getT(0).getT(3).getT(1).getT(0).getT(0);                              // core::gain<NV>
		auto& chain6 = this->getT(0).getT(3).getT(1).getT(1);                                     // xnode_impl::chain6_t<NV>
		auto& modchain2 = this->getT(0).getT(3).getT(1).getT(1).getT(0);                          // xnode_impl::modchain2_t<NV>
		auto& pma = this->getT(0).getT(3).getT(1).getT(1).getT(0).getT(0);                        // xnode_impl::pma_t<NV>
		auto& branch2 = this->getT(0).getT(3).getT(1).getT(1).getT(1);                            // xnode_impl::branch2_t<NV>
		auto& svf = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(0);                        // filters::svf<NV>
		auto& svf2 = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(1);                       // filters::svf<NV>
		auto& svf1 = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(2);                       // filters::svf<NV>
		auto& allpass = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(3);                    // filters::allpass<NV>
		auto& gain3 = this->getT(0).getT(3).getT(1).getT(1).getT(2);                              // core::gain<NV>
		auto& modchain7 = this->getT(0).getT(4);                                                  // xnode_impl::modchain7_t<NV>
		auto& chain40 = this->getT(0).getT(4).getT(0);                                            // xnode_impl::chain40_t<NV>
		auto& cable_table = this->getT(0).getT(4).getT(0).getT(0);                                // xnode_impl::cable_table_t<NV>
		auto& pma1 = this->getT(0).getT(4).getT(0).getT(1);                                       // xnode_impl::pma1_t<NV>
		auto& gain9 = this->getT(0).getT(5);                                                      // core::gain<NV>
		auto& gain5 = this->getT(0).getT(6);                                                      // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain45.getParameterT(0).connectT(0, normaliser); // harm -> normaliser::Value
		chain45.getParameterT(0).connectT(0, normaliser); // harm -> normaliser::Value
		this->getParameterT(0).connectT(0, minmax);       // Harm -> minmax::Value
		
		this->getParameterT(1).connectT(0, minmax); // min -> minmax::Minimum
		
		this->getParameterT(2).connectT(0, minmax); // max -> minmax::Maximum
		
		this->getParameterT(3).connectT(0, minmax); // step -> minmax::Step
		
		this->getParameterT(4).connectT(0, branch3); // Mode -> branch3::Index
		
		this->getParameterT(5).connectT(0, simple_ar); // FxMix -> simple_ar::Attack
		
		auto& FxValue_p = this->getParameterT(6);
		FxValue_p.connectT(0, tempo_sync); // FxValue -> tempo_sync::Tempo
		FxValue_p.connectT(1, tempo_sync); // FxValue -> tempo_sync::UnsyncedTime
		
		this->getParameterT(7).connectT(0, tempo_sync); // FxShDiv -> tempo_sync::Multiplier
		
		this->getParameterT(8).connectT(0, tempo_sync); // FxShSync -> tempo_sync::Enabled
		
		auto& shPitch_p = this->getParameterT(9);
		shPitch_p.connectT(0, pma_unscaled1); // shPitch -> pma_unscaled1::Multiply
		shPitch_p.connectT(1, pma_unscaled3); // shPitch -> pma_unscaled3::Multiply
		
		this->getParameterT(10).connectT(0, xfader1); // FilterMix -> xfader1::Value
		
		this->getParameterT(11).connectT(0, branch2); // FilterType -> branch2::Index
		
		auto& FilterRes_p = this->getParameterT(12);
		FilterRes_p.connectT(0, svf);     // FilterRes -> svf::Q
		FilterRes_p.connectT(1, svf2);    // FilterRes -> svf2::Q
		FilterRes_p.connectT(2, svf1);    // FilterRes -> svf1::Q
		FilterRes_p.connectT(3, allpass); // FilterRes -> allpass::Q
		
		this->getParameterT(13).connectT(0, pma); // FilterCut -> pma::Add
		
		this->getParameterT(14).connectT(0, pma); // FilterFxMod -> pma::Multiply
		
		this->getParameterT(15).connectT(0, pma_unscaled); // DET -> pma_unscaled::Value
		
		auto& ShSmooth_p = this->getParameterT(16);
		ShSmooth_p.connectT(0, ramp);  // ShSmooth -> ramp::LoopStart
		ShSmooth_p.connectT(1, ramp1); // ShSmooth -> ramp1::LoopStart
		ShSmooth_p.connectT(2, ramp3); // ShSmooth -> ramp3::LoopStart
		
		auto& OscShapes_p = this->getParameterT(17);
		OscShapes_p.connectT(0, smoothed_parameter3); // OscShapes -> smoothed_parameter3::Value
		OscShapes_p.connectT(1, gain4);               // OscShapes -> gain4::Gain
		OscShapes_p.connectT(2, gain6);               // OscShapes -> gain6::Gain
		OscShapes_p.connectT(3, xfader2);             // OscShapes -> xfader2::Value
		OscShapes_p.connectT(4, fm);                  // OscShapes -> fm::Modulator
		OscShapes_p.connectT(5, xfader);              // OscShapes -> xfader::Value
		
		this->getParameterT(18).connectT(0, branch); // TYPE -> branch::Index
		
		this->getParameterT(19).connectT(0, branch1); // ShSinMix -> branch1::Index
		
		this->getParameterT(20).connectT(0, smoothed_parameter); // UserPs -> smoothed_parameter::Value
		
		this->getParameterT(21).connectT(0, gain11); // UserInput -> gain11::Gain
		
		auto& snap_p = this->getParameterT(22);
		snap_p.connectT(0, gain4);  // snap -> gain4::ResetValue
		snap_p.connectT(1, gain6);  // snap -> gain6::ResetValue
		snap_p.connectT(2, gain11); // snap -> gain11::ResetValue
		snap_p.connectT(3, gain5);  // snap -> gain5::ResetValue
		snap_p.connectT(4, gain3);  // snap -> gain3::ResetValue
		snap_p.connectT(5, gain2);  // snap -> gain2::ResetValue
		
		auto& ShToGain_p = this->getParameterT(23);
		ShToGain_p.connectT(0, pma1);        // ShToGain -> pma1::Multiply
		ShToGain_p.connectT(1, cable_table); // ShToGain -> cable_table::Value
		
		this->getParameterT(24).connectT(0, simple_ar); // SHInput -> simple_ar::Release
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma_unscaled3.getWrappedObject().getParameter().connectT(0, oscillator13); // pma_unscaled3 -> oscillator13::FreqRatio
		pma_unscaled3.getWrappedObject().getParameter().connectT(1, oscillator15); // pma_unscaled3 -> oscillator15::FreqRatio
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                               // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain7);                              // xfader -> gain7::Gain
		converter.getWrappedObject().getParameter().connectT(0, sampleandhold2);   // converter -> sampleandhold2::Counter
		normaliser.getWrappedObject().getParameter().connectT(0, converter);       // normaliser -> converter::Value
		pma_unscaled1.getWrappedObject().getParameter().connectT(0, oscillator9);  // pma_unscaled1 -> oscillator9::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(1, phasor4);      // pma_unscaled1 -> phasor4::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(2, oscillator11); // pma_unscaled1 -> oscillator11::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(3, file_player5); // pma_unscaled1 -> file_player5::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(4, phasor5);      // pma_unscaled1 -> phasor5::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(5, chain45);      // pma_unscaled1 -> chain45::harm
		pma_unscaled1.getWrappedObject().getParameter().connectT(6, oscillator12); // pma_unscaled1 -> oscillator12::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(7, phasor);       // pma_unscaled1 -> phasor::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(8, fm);           // pma_unscaled1 -> fm::FreqMultiplier
		pma_unscaled1.getWrappedObject().getParameter().connectT(9, oscillator14); // pma_unscaled1 -> oscillator14::FreqRatio
		pma_unscaled.getWrappedObject().getParameter().connectT(0, pma_unscaled1); // pma_unscaled -> pma_unscaled1::Add
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled);        // minmax -> pma_unscaled::Add
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, gain26);        // xfader2 -> gain26::Gain
		xfader2_p.getParameterT(1).connectT(0, gain27);        // xfader2 -> gain27::Gain
		smoothed_parameter3.getParameter().connectT(0, pi7);   // smoothed_parameter3 -> pi7::Value
		smoothed_parameter.getParameter().connectT(0, add3);   // smoothed_parameter -> add3::Value
		tempo_sync.getParameter().connectT(0, sampleandhold1); // tempo_sync -> sampleandhold1::Counter
		tempo_sync.getParameter().connectT(1, ramp);           // tempo_sync -> ramp::PeriodTime
		tempo_sync.getParameter().connectT(2, ramp1);          // tempo_sync -> ramp1::PeriodTime
		tempo_sync.getParameter().connectT(3, ramp3);          // tempo_sync -> ramp3::PeriodTime
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		simple_ar_p.getParameterT(0).connectT(0, add);              // simple_ar -> add::Value
		peak1.getParameter().connectT(0, simple_ar);                // peak1 -> simple_ar::Gate
		pma.getWrappedObject().getParameter().connectT(0, svf);     // pma -> svf::Frequency
		pma.getWrappedObject().getParameter().connectT(1, svf2);    // pma -> svf2::Frequency
		pma.getWrappedObject().getParameter().connectT(2, svf1);    // pma -> svf1::Frequency
		pma.getWrappedObject().getParameter().connectT(3, allpass); // pma -> allpass::Frequency
		pma1.getWrappedObject().getParameter().connectT(0, gain9);  // pma1 -> gain9::Gain
		peak.getParameter().connectT(0, pma_unscaled1);             // peak -> pma_unscaled1::Value
		peak.getParameter().connectT(1, pma);                       // peak -> pma::Value
		peak.getParameter().connectT(2, pma1);                      // peak -> pma1::Value
		peak.getParameter().connectT(3, pma_unscaled3);             // peak -> pma_unscaled3::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain2);                   // xfader1 -> gain2::Gain
		xfader1_p.getParameterT(1).connectT(0, gain3);                   // xfader1 -> gain3::Gain
		cable_table.getWrappedObject().getParameter().connectT(0, pma1); // cable_table -> pma1::Add
		
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
		
		; // branch3::Index is automated
		
		; // xfader2::Value is automated
		
		oscillator11.setParameterT(0, 2.);   // core::oscillator::Mode
		oscillator11.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                    // oscillator11::FreqRatio is automated
		oscillator11.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator11.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator11.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                             // gain26::Gain is automated
		gain26.setParameterT(1, 20.); // core::gain::Smoothing
		gain26.setParameterT(2, 0.);  // core::gain::ResetValue
		
		oscillator12.setParameterT(0, 0.);       // core::oscillator::Mode
		oscillator12.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                        // oscillator12::FreqRatio is automated
		oscillator12.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator12.setParameterT(4, 0.533075); // core::oscillator::Phase
		oscillator12.setParameterT(5, 1.);       // core::oscillator::Gain
		
		;                             // gain27::Gain is automated
		gain27.setParameterT(1, 20.); // core::gain::Smoothing
		gain27.setParameterT(2, 0.);  // core::gain::ResetValue
		
		oscillator9.setParameterT(0, 2.);   // core::oscillator::Mode
		oscillator9.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                   // oscillator9::FreqRatio is automated
		oscillator9.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator9.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator9.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                                            // smoothed_parameter3::Value is automated
		smoothed_parameter3.setParameterT(1, 317.4); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter3.setParameterT(2, 1.);    // control::smoothed_parameter::Enabled
		
		; // pi7::Value is automated
		
		sin1.setParameterT(0, 1.); // math::sin::Value
		
		phasor.setParameterT(0, 1.);   // core::phasor::Gate
		phasor.setParameterT(1, 110.); // core::phasor::Frequency
		;                              // phasor::FreqRatio is automated
		phasor.setParameterT(3, 0.);   // core::phasor::Phase
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		;                            // gain4::ResetValue is automated
		
		fmod1.setParameterT(0, 1.); // math::fmod::Value
		
		oscillator14.setParameterT(0, 0.);   // core::oscillator::Mode
		oscillator14.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                    // oscillator14::FreqRatio is automated
		oscillator14.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator14.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator14.setParameterT(5, 1.);   // core::oscillator::Gain
		
		fm.setParameterT(0, 110.); // core::fm::Frequency
		;                          // fm::Modulator is automated
		;                          // fm::FreqMultiplier is automated
		fm.setParameterT(3, 1.);   // core::fm::Gate
		
		phasor4.setParameterT(0, 1.);   // core::phasor::Gate
		phasor4.setParameterT(1, 220.); // core::phasor::Frequency
		;                               // phasor4::FreqRatio is automated
		phasor4.setParameterT(3, 0.);   // core::phasor::Phase
		
		;                            // gain6::Gain is automated
		gain6.setParameterT(1, 20.); // core::gain::Smoothing
		;                            // gain6::ResetValue is automated
		
		pi1.setParameterT(0, 0.520583); // math::pi::Value
		
		rect1.setParameterT(0, 0.); // math::rect::Value
		
		; // chain45::harm is automated
		
		;                                   // pma_unscaled3::Value is automated
		;                                   // pma_unscaled3::Multiply is automated
		pma_unscaled3.setParameterT(2, 2.); // control::pma_unscaled::Add
		
		; // xfader::Value is automated
		
		oscillator13.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator13.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                    // oscillator13::FreqRatio is automated
		oscillator13.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator13.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator13.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		oscillator15.setParameterT(0, 0.);   // core::oscillator::Mode
		oscillator15.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                    // oscillator15::FreqRatio is automated
		oscillator15.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator15.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator15.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                            // gain7::Gain is automated
		gain7.setParameterT(1, 20.); // core::gain::Smoothing
		gain7.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // normaliser::Value is automated
		
		; // converter::Value is automated
		
		; // sampleandhold2::Counter is automated
		
		file_player5.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player5.setParameterT(1, 1.);   // core::file_player::Gate
		file_player5.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player5::FreqRatio is automated
		
		fmod.setParameterT(0, 0.85461); // math::fmod::Value
		
		pi2.setParameterT(0, 0.61253); // math::pi::Value
		
		phasor5.setParameterT(0, 1.);       // core::phasor::Gate
		phasor5.setParameterT(1, 220.);     // core::phasor::Frequency
		;                                   // phasor5::FreqRatio is automated
		phasor5.setParameterT(3, 0.596823); // core::phasor::Phase
		
		;                                          // smoothed_parameter::Value is automated
		smoothed_parameter.setParameterT(1, 100.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		;                             // gain11::Gain is automated
		gain11.setParameterT(1, 20.); // core::gain::Smoothing
		;                             // gain11::ResetValue is automated
		
		; // add3::Value is automated
		
		file_player6.setParameterT(0, 1.);   // core::file_player::PlaybackMode
		file_player6.setParameterT(1, 1.);   // core::file_player::Gate
		file_player6.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player6.setParameterT(3, 1.);   // core::file_player::FreqRatio
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		; // branch1::Index is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		sig2mod2.setParameterT(0, 0.); // math::sig2mod::Value
		
		oscillator.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		; // sampleandhold1::Counter is automated
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		pi.setParameterT(0, 1.); // math::pi::Value
		
		sin2.setParameterT(0, 2.); // math::sin::Value
		
		;                           // ramp1::PeriodTime is automated
		;                           // ramp1::LoopStart is automated
		ramp1.setParameterT(2, 1.); // core::ramp::Gate
		
		mod_inv1.setParameterT(0, 0.); // math::mod_inv::Value
		
		;                           // ramp3::PeriodTime is automated
		;                           // ramp3::LoopStart is automated
		ramp3.setParameterT(2, 1.); // core::ramp::Gate
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		;                                     // simple_ar::Attack is automated
		;                                     // simple_ar::Release is automated
		;                                     // simple_ar::Gate is automated
		simple_ar.setParameterT(3, 0.497332); // envelope::simple_ar::AttackCurve
		
		; // add::Value is automated
		
		; // xfader1::Value is automated
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		;                            // gain2::ResetValue is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // branch2::Index is automated
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);   // filters::svf::Mode
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf2.setParameterT(4, 1.);   // filters::svf::Mode
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 2.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                               // allpass::Frequency is automated
		;                               // allpass::Q is automated
		allpass.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		;                            // gain3::Gain is automated
		gain3.setParameterT(1, 20.); // core::gain::Smoothing
		;                            // gain3::ResetValue is automated
		
		; // cable_table::Value is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		;                            // gain9::Gain is automated
		gain9.setParameterT(1, 0.3); // core::gain::Smoothing
		gain9.setParameterT(2, 0.);  // core::gain::ResetValue
		
		gain5.setParameterT(0, -25.);  // core::gain::Gain
		gain5.setParameterT(1, 167.6); // core::gain::Smoothing
		;                              // gain5::ResetValue is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 16.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 3.);
		this->setParameterT(5, 0.955078);
		this->setParameterT(6, 0.846977);
		this->setParameterT(7, 18.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 3.);
		this->setParameterT(12, 0.3);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 0.00713315);
		this->setParameterT(15, 1.00288);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 0.0855978);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 1.);
		this->setParameterT(20, 0.332626);
		this->setParameterT(21, 0.0707371);
		this->setParameterT(22, 0.515625);
		this->setParameterT(23, 0.52106);
		this->setParameterT(24, 0.636464);
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
		
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                                           // xnode_impl::oscillator11_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                                           // xnode_impl::oscillator12_t<NV>
        getT(0).getT(0).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).                                                   // xnode_impl::oscillator9_t<NV>
        getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).                                                   // xnode_impl::oscillator14_t<NV>
        getT(0).getT(0).getT(3).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                                           // xnode_impl::oscillator13_t<NV>
        getT(0).getT(5).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                                           // xnode_impl::oscillator15_t<NV>
        getT(0).getT(5).getT(1).getT(1).getT(1).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index); // xnode_impl::file_player5_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).getT(4).setExternalData(b, index); // xnode_impl::file_player6_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(2).setExternalData(b, index);                 // xnode_impl::oscillator_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(0).setExternalData(b, index);         // xnode_impl::ramp_t<NV>
		this->getT(0).getT(2).getT(1).getT(2).getT(0).getT(0).setExternalData(b, index);         // xnode_impl::ramp1_t<NV>
		this->getT(0).getT(2).getT(1).getT(3).getT(0).getT(0).setExternalData(b, index);         // xnode_impl::ramp3_t<NV>
		this->getT(0).getT(2).getT(1).getT(3).getT(0).getT(2).setExternalData(b, index);         // xnode_impl::peak1_t<NV>
		this->getT(0).getT(2).getT(1).getT(3).getT(0).getT(4).setExternalData(b, index);         // xnode_impl::simple_ar_t<NV>
		this->getT(0).getT(2).getT(2).setExternalData(b, index);                                 // xnode_impl::peak_t<NV>
		this->getT(0).getT(4).getT(0).getT(0).setExternalData(b, index);                         // xnode_impl::cable_table_t<NV>
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


