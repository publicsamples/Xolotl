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
template <int NV> using oscillator10_t = oscillator9_t<NV>;
template <int NV> using oscillator11_t = oscillator9_t<NV>;
template <int NV>
using file_player5_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<0>>;
template <int NV> using oscillator13_t = oscillator9_t<NV>;

template <int NV>
using pma_unscaled3_t = control::pma_unscaled<NV, 
                                              parameter::plain<filters::ladder<NV>, 0>>;
template <int NV>
using converter4_t = control::converter<parameter::plain<pma_unscaled3_t<NV>, 2>, 
                                        conversion_logic::midi2freq>;
template <int NV>
using midi2_t = wrap::mod<parameter::plain<converter4_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using normaliser_t = control::normaliser<parameter::plain<pma_unscaled3_t<NV>, 0>>;

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
                                   wrap::fix<2, oscillator13_t<NV>>, 
                                   midi2_t<NV>, 
                                   converter4_t<NV>, 
                                   normaliser_t<NV>, 
                                   pma_unscaled3_t<NV>, 
                                   filters::ladder<NV>>;
template <int NV> using oscillator14_t = oscillator9_t<NV>;

template <int NV>
using pma_unscaled1_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<oscillator9_t<NV>, 2>, 
                                           parameter::plain<oscillator10_t<NV>, 2>, 
                                           parameter::plain<core::phasor<NV>, 2>, 
                                           parameter::plain<oscillator11_t<NV>, 2>, 
                                           parameter::plain<file_player5_t<NV>, 3>, 
                                           parameter::plain<core::phasor<NV>, 2>, 
                                           parameter::plain<chain45_t<NV>, 0>, 
                                           parameter::plain<oscillator14_t<NV>, 2>>;

template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, pma_unscaled1_mod<NV>>;
template <int NV>
using pma_unscaled2_t = control::pma_unscaled<NV, 
                                              parameter::plain<pma_unscaled1_t<NV>, 2>>;
template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, 
                                             parameter::plain<pma_unscaled2_t<NV>, 2>>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled_t<NV>, 2>>;

template <int NV>
using midi_cc_t = control::midi_cc<parameter::plain<pma_unscaled2_t<NV>, 0>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, minmax_t<NV>>, 
                                      pma_unscaled_t<NV>, 
                                      midi_cc_t<NV>, 
                                      pma_unscaled2_t<NV>, 
                                      pma_unscaled1_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

namespace custom
{

struct expr5
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.cos(Math.PI * 4.0 * value * input);
		;
	}
};
}

template <int NV>
using smoothed_parameter5_t = wrap::mod<parameter::plain<math::expr<NV, custom::expr5>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator11_t<NV>>, 
                                   smoothed_parameter5_t<NV>, 
                                   math::expr<NV, custom::expr5>>;

DECLARE_PARAMETER_RANGE(smoothed_parameter3_modRange, 
                        0., 
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

struct table_t_data
{
	span<float, 512> data =
	{
		1.f, 0.990268f, 0.980536f, 0.970805f, 0.961073f, 0.951341f,
		0.942476f, 0.934072f, 0.925668f, 0.917264f, 0.90886f, 0.900456f,
		0.892708f, 0.885361f, 0.878014f, 0.870667f, 0.86332f, 0.855973f,
		0.848626f, 0.842057f, 0.835571f, 0.829086f, 0.8226f, 0.816114f,
		0.809628f, 0.803143f, 0.797015f, 0.791244f, 0.785474f, 0.779703f,
		0.773933f, 0.768162f, 0.762392f, 0.756622f, 0.7511f, 0.745933f,
		0.740766f, 0.735599f, 0.730432f, 0.725266f, 0.720099f, 0.714932f,
		0.709765f, 0.704928f, 0.700277f, 0.695626f, 0.690976f, 0.686325f,
		0.681674f, 0.677023f, 0.672372f, 0.667722f, 0.663151f, 0.658947f,
		0.654743f, 0.650538f, 0.646334f, 0.64213f, 0.637925f, 0.633721f,
		0.629516f, 0.625312f, 0.621122f, 0.617307f, 0.613493f, 0.609678f,
		0.605864f, 0.602049f, 0.598235f, 0.59442f, 0.590606f, 0.586791f,
		0.582977f, 0.579234f, 0.575763f, 0.572291f, 0.56882f, 0.56535f,
		0.561879f, 0.558407f, 0.554937f, 0.551466f, 0.547994f, 0.544523f,
		0.541053f, 0.537793f, 0.534627f, 0.53146f, 0.528294f, 0.525128f,
		0.521962f, 0.518796f, 0.51563f, 0.512464f, 0.509298f, 0.506132f,
		0.502965f, 0.499934f, 0.49704f, 0.494146f, 0.491253f, 0.488359f,
		0.485465f, 0.482572f, 0.479678f, 0.476784f, 0.473891f, 0.470997f,
		0.468104f, 0.46521f, 0.462465f, 0.459816f, 0.457168f, 0.454519f,
		0.45187f, 0.449222f, 0.446573f, 0.443924f, 0.441275f, 0.438627f,
		0.435978f, 0.433329f, 0.430681f, 0.42804f, 0.425613f, 0.423186f,
		0.420758f, 0.418331f, 0.415904f, 0.413476f, 0.411049f, 0.408622f,
		0.406195f, 0.403767f, 0.40134f, 0.398913f, 0.396485f, 0.394058f,
		0.391788f, 0.389562f, 0.387335f, 0.385109f, 0.382883f, 0.380657f,
		0.378431f, 0.376204f, 0.373978f, 0.371752f, 0.369526f, 0.3673f,
		0.365073f, 0.362847f, 0.360621f, 0.358549f, 0.356506f, 0.354463f,
		0.352421f, 0.350378f, 0.348335f, 0.346292f, 0.34425f, 0.342207f,
		0.340164f, 0.338121f, 0.336079f, 0.334036f, 0.331993f, 0.32995f,
		0.327944f, 0.326069f, 0.324194f, 0.322319f, 0.320445f, 0.31857f,
		0.316695f, 0.31482f, 0.312946f, 0.311071f, 0.309196f, 0.307321f,
		0.305447f, 0.303572f, 0.301697f, 0.299823f, 0.297948f, 0.296213f,
		0.294492f, 0.292772f, 0.291052f, 0.289332f, 0.287611f, 0.285891f,
		0.284171f, 0.282451f, 0.28073f, 0.27901f, 0.27729f, 0.27557f,
		0.273849f, 0.272129f, 0.270409f, 0.268689f, 0.267098f, 0.26552f,
		0.263942f, 0.262365f, 0.260787f, 0.259209f, 0.257631f, 0.256054f,
		0.254476f, 0.252898f, 0.25132f, 0.249743f, 0.248165f, 0.246587f,
		0.245009f, 0.243432f, 0.241854f, 0.240306f, 0.23886f, 0.237414f,
		0.235968f, 0.234523f, 0.233077f, 0.231631f, 0.230185f, 0.228739f,
		0.227293f, 0.225847f, 0.224402f, 0.222956f, 0.22151f, 0.220064f,
		0.218618f, 0.217172f, 0.215726f, 0.214281f, 0.21294f, 0.211616f,
		0.210293f, 0.208969f, 0.207646f, 0.206322f, 0.204999f, 0.203675f,
		0.202352f, 0.201028f, 0.199705f, 0.198382f, 0.197058f, 0.195735f,
		0.194411f, 0.193088f, 0.191764f, 0.190441f, 0.189117f, 0.187886f,
		0.186676f, 0.185466f, 0.184257f, 0.183047f, 0.181838f, 0.180628f,
		0.179419f, 0.178209f, 0.176999f, 0.17579f, 0.17458f, 0.173371f,
		0.172161f, 0.170951f, 0.169742f, 0.168532f, 0.167323f, 0.166113f,
		0.164911f, 0.163807f, 0.162704f, 0.161601f, 0.160498f, 0.159394f,
		0.158291f, 0.157188f, 0.156084f, 0.154981f, 0.153878f, 0.152774f,
		0.151671f, 0.150568f, 0.149464f, 0.148361f, 0.147258f, 0.146154f,
		0.145051f, 0.143948f, 0.142844f, 0.141805f, 0.140801f, 0.139797f,
		0.138793f, 0.137789f, 0.136785f, 0.135781f, 0.134777f, 0.133773f,
		0.132769f, 0.131765f, 0.130761f, 0.129757f, 0.128753f, 0.127749f,
		0.126745f, 0.125741f, 0.124737f, 0.123733f, 0.122729f, 0.121725f,
		0.120771f, 0.119861f, 0.11895f, 0.118039f, 0.117128f, 0.116217f,
		0.115306f, 0.114395f, 0.113484f, 0.112574f, 0.111663f, 0.110752f,
		0.109841f, 0.10893f, 0.108019f, 0.107108f, 0.106197f, 0.105287f,
		0.104376f, 0.103465f, 0.102554f, 0.101643f, 0.100797f, 0.0999737f,
		0.0991503f, 0.0983269f, 0.0975034f, 0.09668f, 0.0958565f, 0.0950331f,
		0.0942096f, 0.0933862f, 0.0925627f, 0.0917393f, 0.0909159f, 0.0900924f,
		0.089269f, 0.0884455f, 0.087622f, 0.0867986f, 0.0859752f, 0.0851517f,
		0.0843283f, 0.0835049f, 0.0827031f, 0.0819619f, 0.0812207f, 0.0804795f,
		0.0797383f, 0.0789971f, 0.078256f, 0.0775148f, 0.0767736f, 0.0760324f,
		0.0752912f, 0.07455f, 0.0738088f, 0.0730676f, 0.0723264f, 0.0715852f,
		0.0708441f, 0.0701029f, 0.0693617f, 0.0686205f, 0.0678793f, 0.0671381f,
		0.066397f, 0.0656635f, 0.0649998f, 0.0643362f, 0.0636725f, 0.0630088f,
		0.0623451f, 0.0616815f, 0.0610178f, 0.0603542f, 0.0596905f, 0.0590268f,
		0.0583631f, 0.0576995f, 0.0570358f, 0.0563722f, 0.0557085f, 0.0550448f,
		0.0543812f, 0.0537175f, 0.0530538f, 0.0523902f, 0.0517265f, 0.0510628f,
		0.0503992f, 0.0497538f, 0.0491633f, 0.0485729f, 0.0479824f, 0.047392f,
		0.0468014f, 0.046211f, 0.0456206f, 0.0450301f, 0.0444396f, 0.0438491f,
		0.0432587f, 0.0426682f, 0.0420777f, 0.0414873f, 0.0408968f, 0.0403063f,
		0.0397158f, 0.0391254f, 0.0385349f, 0.0379444f, 0.0373539f, 0.0367635f,
		0.036173f, 0.0355825f, 0.0350416f, 0.0345204f, 0.0339991f, 0.0334778f,
		0.0329566f, 0.0324354f, 0.0319141f, 0.0313929f, 0.0308716f, 0.0303504f,
		0.0298291f, 0.0293078f, 0.0287866f, 0.0282654f, 0.0277441f, 0.0272229f,
		0.0267016f, 0.0261803f, 0.0256591f, 0.0251378f, 0.0246166f, 0.0240954f,
		0.0235741f, 0.0230528f, 0.0225316f, 0.0220428f, 0.0215871f, 0.0211315f,
		0.0206757f, 0.02022f, 0.0197644f, 0.0193087f, 0.0188529f, 0.0183973f,
		0.0179416f, 0.0174859f, 0.0170302f, 0.0165745f, 0.0161188f, 0.0156631f,
		0.0152074f, 0.0147517f, 0.014296f, 0.0138403f, 0.0133846f, 0.0129289f,
		0.0124732f, 0.0120175f, 0.0115619f, 0.0111061f, 0.0106505f, 0.0102315f,
		0.00983793f, 0.00944442f, 0.00905091f, 0.0086574f, 0.00826389f, 0.00787038f,
		0.00747687f, 0.0070833f, 0.00668979f, 0.00629628f, 0.00590277f, 0.00550926f,
		0.00511575f, 0.00472224f, 0.00432867f, 0.00393516f, 0.00354165f, 0.00314814f,
		0.00275463f, 0.00236112f, 0.00196761f, 0.0015741f, 0.00118053f, 0.00078702f,
		0.00039351f, 0.f
	};
};

using table_t = wrap::data<math::table, 
                           data::embedded::table<table_t_data>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator10_t<NV>>, 
                                   core::gain<NV>, 
                                   math::fmod<NV>, 
                                   table_t>;

struct table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.0494648f, 0.0954759f, 0.138488f, 0.17888f, 0.216969f,
		0.252796f, 0.286707f, 0.318972f, 0.349767f, 0.379246f, 0.407398f,
		0.434097f, 0.459832f, 0.484693f, 0.508356f, 0.531111f, 0.55322f,
		0.574334f, 0.594689f, 0.614569f, 0.633419f, 0.651823f, 0.669632f,
		0.686705f, 0.703509f, 0.7194f, 0.735069f, 0.750073f, 0.764711f,
		0.778871f, 0.792573f, 0.80593f, 0.81878f, 0.831372f, 0.843446f,
		0.855308f, 0.866674f, 0.877838f, 0.888558f, 0.899054f, 0.909184f,
		0.919041f, 0.928632f, 0.937877f, 0.946973f, 0.955631f, 0.964275f,
		0.972369f, 0.980463f, 0.988151f, 0.995704f, 1.f, 1.f,
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
		1.f, 0.991059f, 0.981597f, 0.971945f, 0.962125f, 0.952252f,
		0.942063f, 0.931875f, 0.921385f, 0.910818f, 0.900064f, 0.889107f,
		0.878072f, 0.866714f, 0.855356f, 0.843608f, 0.831837f, 0.819757f,
		0.807561f, 0.795127f, 0.782492f, 0.769681f, 0.756594f, 0.743381f,
		0.729827f, 0.716185f, 0.70215f, 0.688049f, 0.673517f, 0.658927f,
		0.643881f, 0.628769f, 0.613192f, 0.597521f, 0.581394f, 0.565126f,
		0.548431f, 0.531523f, 0.514239f, 0.496647f, 0.478753f, 0.460427f,
		0.4419f, 0.422786f, 0.403508f, 0.383644f, 0.363485f, 0.342913f,
		0.321806f, 0.300446f, 0.278371f, 0.255941f, 0.233069f, 0.209486f,
		0.185525f, 0.160953f, 0.135683f, 0.109941f, 0.0835153f, 0.0562782f,
		0.0284539f, 0.f
	};
};

using table1_t = wrap::data<math::table, 
                            data::embedded::table<table1_t_data>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator14_t<NV>>, 
                                   core::gain<NV>, 
                                   table1_t>;

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
using oscilloscope_t = wrap::data<analyse::oscilloscope, 
                                  data::external::displaybuffer<0>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, oscilloscope_t>, 
                                      control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch_t<NV>>, 
                                   midichain_t<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain32_t<NV>>>;

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
                                     wrap::fix<1, tempo_sync_t<NV>>, 
                                     wrap::no_process<math::sig2mod<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, modchain_t<NV>>, 
                                   fx::sampleandhold<NV>>;

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using modchain5_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, tempo_sync2_t<NV>>, 
                                      wrap::no_process<math::sig2mod<NV>>>;

template <int NV>
using modchain5_t = wrap::control_rate<modchain5_t_<NV>>;

DECLARE_PARAMETER_RANGE_STEP(peak1_modRange, 
                             0., 
                             24., 
                             0.1);

template <int NV>
using peak1_mod = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      peak1_modRange>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, ramp_t<NV>>, 
                                      math::pi<NV>, 
                                      math::sin<NV>, 
                                      peak1_t<NV>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, modchain5_t<NV>>, 
                                   modchain3_t<NV>, 
                                   core::gain<NV>, 
                                   math::pi<NV>, 
                                   wrap::no_process<math::sin<NV>>, 
                                   math::sig2mod<NV>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain10_t<NV>>>;

template <int NV>
using converter_t = control::converter<parameter::plain<core::phasor_fm<NV>, 2>, 
                                       conversion_logic::ms2freq>;
template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, tempo_sync1_t<NV>>, 
                                      wrap::no_process<math::sig2mod<NV>>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, modchain4_t<NV>>, 
                                   converter_t<NV>, 
                                   core::phasor_fm<NV>, 
                                   core::mono2stereo>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain17_t<NV>>, 
                                    chain18_t<NV>, 
                                    chain20_t<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, branch5_t<NV>>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain7_t<NV>>>;

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

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<pma_t<NV>, 0>, 
                                  parameter::plain<pma_unscaled1_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using multi_t = container::multi<parameter::empty, 
                                 wrap::fix<1, core::smoother<NV>>, 
                                 wrap::fix<1, core::smoother<NV>>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain33_t<NV>>, 
                                  peak_t<NV>, 
                                  multi_t<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain2_t<NV>>, 
                                 chain3_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader_t<NV>>, 
                                  split_t<NV>>;
using oscilloscope1_t = wrap::data<analyse::oscilloscope, 
                                   data::external::displaybuffer<1>>;

using midichain1_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, oscilloscope1_t>>;

using midichain1_t = wrap::event<midichain1_t_>;

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
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::allpass<NV>>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, filters::svf<NV>>, 
                                    filters::svf<NV>, 
                                    filters::svf<NV>, 
                                    chain42_t<NV>>;

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
                                  wrap::fix<2, midichain1_t>, 
                                  xfader1_t<NV>, 
                                  split1_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, modchain1_t<NV>>, 
                                 chain9_t<NV>, 
                                 chain1_t<NV>, 
                                 chain4_t<NV>, 
                                 core::gain<NV>>;

using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

template <int NV>
using smoothed_parameter1_t = wrap::mod<parameter::plain<math::mul<NV>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

struct cable_pack_t_data
{
	span<float, 16> data =
	{
		1.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter1_t<NV>, 0>>, 
                                data::embedded::sliderpack<cable_pack_t_data>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack_t<NV>>, 
                                   smoothed_parameter1_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter2_t = smoothed_parameter1_t<NV>;

struct cable_pack1_t_data
{
	span<float, 16> data =
	{
		0.f, 1.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack1_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter2_t<NV>, 0>>, 
                                 data::embedded::sliderpack<cable_pack1_t_data>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack1_t<NV>>, 
                                   smoothed_parameter2_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter4_t = smoothed_parameter1_t<NV>;

struct cable_pack3_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 1.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack3_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter4_t<NV>, 0>>, 
                                 data::embedded::sliderpack<cable_pack3_t_data>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack3_t<NV>>, 
                                   smoothed_parameter4_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter6_t = smoothed_parameter1_t<NV>;

struct cable_pack4_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack4_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter6_t<NV>, 0>>, 
                                 data::embedded::sliderpack<cable_pack4_t_data>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack4_t<NV>>, 
                                   smoothed_parameter6_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter7_t = smoothed_parameter1_t<NV>;

struct cable_pack5_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack5_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter7_t<NV>, 0>>, 
                                 data::embedded::sliderpack<cable_pack5_t_data>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack5_t<NV>>, 
                                   smoothed_parameter7_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter8_t = smoothed_parameter1_t<NV>;

struct cable_pack6_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 1.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack6_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter8_t<NV>, 0>>, 
                                 data::embedded::sliderpack<cable_pack6_t_data>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack6_t<NV>>, 
                                   smoothed_parameter8_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter9_t = smoothed_parameter1_t<NV>;

struct cable_pack7_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		1.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack7_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter9_t<NV>, 0>>, 
                                 data::embedded::sliderpack<cable_pack7_t_data>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack7_t<NV>>, 
                                   smoothed_parameter9_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter10_t = smoothed_parameter1_t<NV>;

struct cable_pack8_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack8_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter10_t<NV>, 0>>, 
                                 data::embedded::sliderpack<cable_pack8_t_data>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack8_t<NV>>, 
                                   smoothed_parameter10_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter11_t = smoothed_parameter1_t<NV>;

struct cable_pack9_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack9_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter11_t<NV>, 0>>, 
                                 data::embedded::sliderpack<cable_pack9_t_data>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack9_t<NV>>, 
                                   smoothed_parameter11_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter12_t = smoothed_parameter1_t<NV>;

struct cable_pack10_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack10_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter12_t<NV>, 0>>, 
                                  data::embedded::sliderpack<cable_pack10_t_data>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack10_t<NV>>, 
                                   smoothed_parameter12_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter13_t = smoothed_parameter1_t<NV>;

struct cable_pack11_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack11_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter13_t<NV>, 0>>, 
                                  data::embedded::sliderpack<cable_pack11_t_data>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack11_t<NV>>, 
                                   smoothed_parameter13_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter14_t = smoothed_parameter1_t<NV>;

struct cable_pack12_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 1.f,
		0.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack12_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter14_t<NV>, 0>>, 
                                  data::embedded::sliderpack<cable_pack12_t_data>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack12_t<NV>>, 
                                   smoothed_parameter14_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter15_t = smoothed_parameter1_t<NV>;

struct cable_pack13_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		1.f, 0.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack13_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter15_t<NV>, 0>>, 
                                  data::embedded::sliderpack<cable_pack13_t_data>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack13_t<NV>>, 
                                   smoothed_parameter15_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter16_t = smoothed_parameter1_t<NV>;

struct cable_pack14_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f
	};
};

template <int NV>
using cable_pack14_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter16_t<NV>, 0>>, 
                                  data::embedded::sliderpack<cable_pack14_t_data>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack14_t<NV>>, 
                                   smoothed_parameter16_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter17_t = smoothed_parameter1_t<NV>;

struct cable_pack15_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f
	};
};

template <int NV>
using cable_pack15_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter17_t<NV>, 0>>, 
                                  data::embedded::sliderpack<cable_pack15_t_data>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack15_t<NV>>, 
                                   smoothed_parameter17_t<NV>, 
                                   math::mul<NV>>;

template <int NV> using smoothed_parameter18_t = smoothed_parameter1_t<NV>;

struct cable_pack16_t_data
{
	span<float, 16> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	};
};

template <int NV>
using cable_pack16_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter18_t<NV>, 0>>, 
                                  data::embedded::sliderpack<cable_pack16_t_data>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_pack16_t<NV>>, 
                                   smoothed_parameter18_t<NV>, 
                                   math::mul<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain19_t<NV>>, 
                                    chain21_t<NV>, 
                                    chain23_t<NV>, 
                                    chain24_t<NV>, 
                                    chain25_t<NV>, 
                                    chain26_t<NV>, 
                                    chain27_t<NV>, 
                                    chain28_t<NV>, 
                                    chain29_t<NV>, 
                                    chain30_t<NV>, 
                                    chain31_t<NV>, 
                                    chain35_t<NV>, 
                                    chain36_t<NV>, 
                                    chain38_t<NV>, 
                                    chain39_t<NV>, 
                                    chain40_t<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain41_t>, 
                                    branch1_t<NV>>;

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
using FxValue_2 = parameter::from0To1<xnode_impl::tempo_sync2_t<NV>, 
                                      0, 
                                      FxValue_0Range>;

template <int NV>
using FxValue_3 = parameter::from0To1<xnode_impl::tempo_sync1_t<NV>, 
                                      0, 
                                      FxValue_0Range>;

template <int NV>
using FxValue_4 = parameter::from0To1<xnode_impl::tempo_sync2_t<NV>, 
                                      3, 
                                      FxValue_1Range>;

template <int NV>
using FxValue_5 = parameter::from0To1<xnode_impl::tempo_sync1_t<NV>, 
                                      3, 
                                      FxValue_1Range>;

template <int NV>
using FxValue = parameter::chain<ranges::Identity, 
                                 FxValue_0<NV>, 
                                 FxValue_1<NV>, 
                                 FxValue_2<NV>, 
                                 FxValue_3<NV>, 
                                 FxValue_4<NV>, 
                                 FxValue_5<NV>>;

template <int NV>
using FxShDiv = parameter::chain<ranges::Identity, 
                                 parameter::plain<xnode_impl::tempo_sync_t<NV>, 1>, 
                                 parameter::plain<xnode_impl::tempo_sync2_t<NV>, 1>, 
                                 parameter::plain<xnode_impl::tempo_sync1_t<NV>, 1>>;

template <int NV>
using FxShSync = parameter::chain<ranges::Identity, 
                                  parameter::plain<xnode_impl::tempo_sync_t<NV>, 2>, 
                                  parameter::plain<xnode_impl::tempo_sync2_t<NV>, 2>, 
                                  parameter::plain<xnode_impl::tempo_sync1_t<NV>, 2>>;

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

template <int NV>
using ShSmooth = parameter::chain<ranges::Identity, 
                                  parameter::plain<core::smoother<NV>, 0>, 
                                  parameter::plain<core::smoother<NV>, 0>>;

template <int NV>
using OscShapes_3 = parameter::from0To1<filters::ladder<NV>, 
                                        1, 
                                        FilterRes_0Range>;

DECLARE_PARAMETER_RANGE_STEP(OscShapes_4Range, 
                             0., 
                             20., 
                             0.1);

template <int NV>
using OscShapes_4 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        OscShapes_4Range>;

template <int NV> using OscShapes_5 = OscShapes_4<NV>;

template <int NV> using OscShapes_6 = OscShapes_4<NV>;

template <int NV>
using OscShapes = parameter::chain<ranges::Identity, 
                                   parameter::plain<xnode_impl::smoothed_parameter3_t<NV>, 0>, 
                                   parameter::plain<xnode_impl::smoothed_parameter_t<NV>, 0>, 
                                   parameter::plain<xnode_impl::smoothed_parameter5_t<NV>, 0>, 
                                   OscShapes_3<NV>, 
                                   OscShapes_4<NV>, 
                                   OscShapes_5<NV>, 
                                   OscShapes_6<NV>>;

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

DECLARE_PARAMETER_RANGE_STEP(ShSinMix_InputRange, 
                             1., 
                             3., 
                             1.);
template <int NV>
using ShSinMix_0 = parameter::from0To1<xnode_impl::branch5_t<NV>, 
                                       0, 
                                       TYPE_0Range>;

template <int NV>
using ShSinMix = parameter::chain<ShSinMix_InputRange, ShSinMix_0<NV>>;

template <int NV>
using xf = parameter::chain<ranges::Identity, 
                            parameter::plain<xnode_impl::cable_pack1_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack3_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack4_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack5_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack6_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack7_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack8_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack9_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack10_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack11_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack12_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack13_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack14_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack15_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack16_t<NV>, 0>, 
                            parameter::plain<xnode_impl::cable_pack_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(SxSmooth_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_STEP(SxSmooth_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using SxSmooth_0 = parameter::from0To1<xnode_impl::smoothed_parameter1_t<NV>, 
                                       1, 
                                       SxSmooth_0Range>;

template <int NV>
using SxSmooth_1 = parameter::from0To1<xnode_impl::smoothed_parameter2_t<NV>, 
                                       1, 
                                       SxSmooth_0Range>;

template <int NV>
using SxSmooth_2 = parameter::from0To1<xnode_impl::smoothed_parameter6_t<NV>, 
                                       1, 
                                       SxSmooth_0Range>;

template <int NV>
using SxSmooth_3 = parameter::from0To1<xnode_impl::smoothed_parameter7_t<NV>, 
                                       1, 
                                       SxSmooth_0Range>;

template <int NV>
using SxSmooth_4 = parameter::from0To1<xnode_impl::smoothed_parameter8_t<NV>, 
                                       1, 
                                       SxSmooth_0Range>;

template <int NV>
using SxSmooth_5 = parameter::from0To1<xnode_impl::smoothed_parameter9_t<NV>, 
                                       1, 
                                       SxSmooth_0Range>;

template <int NV>
using SxSmooth_6 = parameter::from0To1<xnode_impl::smoothed_parameter10_t<NV>, 
                                       1, 
                                       SxSmooth_0Range>;

template <int NV>
using SxSmooth_7 = parameter::from0To1<xnode_impl::smoothed_parameter11_t<NV>, 
                                       1, 
                                       SxSmooth_0Range>;

template <int NV>
using SxSmooth_8 = parameter::from0To1<xnode_impl::smoothed_parameter12_t<NV>, 
                                       1, 
                                       SxSmooth_0Range>;

template <int NV>
using SxSmooth_9 = parameter::from0To1<xnode_impl::smoothed_parameter13_t<NV>, 
                                       1, 
                                       SxSmooth_0Range>;

template <int NV>
using SxSmooth_10 = parameter::from0To1<xnode_impl::smoothed_parameter14_t<NV>, 
                                        1, 
                                        SxSmooth_0Range>;

template <int NV>
using SxSmooth_11 = parameter::from0To1<xnode_impl::smoothed_parameter15_t<NV>, 
                                        1, 
                                        SxSmooth_0Range>;

template <int NV>
using SxSmooth_12 = parameter::from0To1<xnode_impl::smoothed_parameter16_t<NV>, 
                                        1, 
                                        SxSmooth_0Range>;

template <int NV>
using SxSmooth_13 = parameter::from0To1<xnode_impl::smoothed_parameter17_t<NV>, 
                                        1, 
                                        SxSmooth_0Range>;

template <int NV>
using SxSmooth_14 = parameter::from0To1<xnode_impl::smoothed_parameter18_t<NV>, 
                                        1, 
                                        SxSmooth_0Range>;

template <int NV>
using SxSmooth_15 = parameter::from0To1<xnode_impl::smoothed_parameter4_t<NV>, 
                                        1, 
                                        SxSmooth_0Range>;

template <int NV>
using SxSmooth = parameter::chain<SxSmooth_InputRange, 
                                  SxSmooth_0<NV>, 
                                  SxSmooth_1<NV>, 
                                  SxSmooth_2<NV>, 
                                  SxSmooth_3<NV>, 
                                  SxSmooth_4<NV>, 
                                  SxSmooth_5<NV>, 
                                  SxSmooth_6<NV>, 
                                  SxSmooth_7<NV>, 
                                  SxSmooth_8<NV>, 
                                  SxSmooth_9<NV>, 
                                  SxSmooth_10<NV>, 
                                  SxSmooth_11<NV>, 
                                  SxSmooth_12<NV>, 
                                  SxSmooth_13<NV>, 
                                  SxSmooth_14<NV>, 
                                  SxSmooth_15<NV>>;

template <int NV>
using UserInput = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xnode_impl::xfader_c0Range>;

template <int NV>
using rel_0 = parameter::from0To1<core::gain<NV>, 
                                  2, 
                                  xnode_impl::xfader_c0Range>;

template <int NV> using rel_1 = rel_0<NV>;

template <int NV> using rel_2 = rel_0<NV>;

template <int NV> using rel_3 = rel_0<NV>;

template <int NV> using rel_4 = rel_0<NV>;

template <int NV> using rel_5 = rel_0<NV>;

template <int NV> using rel_6 = rel_0<NV>;

template <int NV> using rel_7 = rel_0<NV>;

template <int NV> using rel_8 = rel_0<NV>;

template <int NV> using rel_9 = rel_0<NV>;

template <int NV>
using rel = parameter::chain<ranges::Identity, 
                             rel_0<NV>, 
                             rel_1<NV>, 
                             rel_2<NV>, 
                             rel_3<NV>, 
                             rel_4<NV>, 
                             rel_5<NV>, 
                             rel_6<NV>, 
                             rel_7<NV>, 
                             rel_8<NV>, 
                             rel_9<NV>>;

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
using SfStage = parameter::plain<xnode_impl::branch1_t<NV>, 
                                 0>;
template <int NV>
using FadeOn = parameter::plain<xnode_impl::branch4_t<NV>, 
                                0>;
using crv = parameter::empty;
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
                                      xf<NV>, 
                                      SxSmooth<NV>, 
                                      SfStage<NV>, 
                                      FadeOn<NV>, 
                                      UserInput<NV>, 
                                      rel<NV>, 
                                      crv>;
}

template <int NV>
using xnode_t_ = container::chain<xnode_t_parameters::xnode_t_plist<NV>, 
                                  wrap::fix<2, chain_t<NV>>, 
                                  branch4_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public xnode_impl::xnode_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 2;
		
		SNEX_METADATA_ID(xnode);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(464)
		{
			0x005C, 0x0000, 0x0000, 0x6148, 0x6D72, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0591, 0x3F13, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0001, 0x0000, 0x696D, 0x006E, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x0200, 0x0000, 0x6D00, 0x7861, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x4180, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0003, 0x0000, 0x7473, 0x7065, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0004, 0x0000, 0x6F4D, 0x6564, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0005, 0x0000, 0x7846, 0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0600, 0x0000, 0x4600, 0x5678, 0x6C61, 0x6575, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x9BD3, 0x3EEE, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0007, 0x0000, 0x7846, 0x6853, 0x6944, 0x0076, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x0000, 0x0042, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x0800, 0x0000, 0x4600, 0x5378, 0x5368, 
            0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0900, 0x0000, 0x7300, 
            0x5068, 0x7469, 0x6863, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000A, 
            0x0000, 0x6946, 0x746C, 0x7265, 0x694D, 0x0078, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x0B00, 0x0000, 0x4600, 0x6C69, 0x6574, 0x5472, 0x7079, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x4000, 0x0040, 0x4000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x0C00, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x5272, 0x7365, 0x0000, 0x999A, 0x3E99, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x8918, 0x3E87, 0x0000, 0x0000, 0x005C, 0x000D, 
            0x0000, 0x6946, 0x746C, 0x7265, 0x7543, 0x0074, 0x0000, 0x8000, 
            0x0024, 0x8000, 0x383F, 0x16BD, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x0E00, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4672, 0x4D78, 
            0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x6F4E, 0xBEA8, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000F, 0x0000, 0x4544, 
            0x0054, 0x0000, 0x0000, 0x0000, 0x0000, 0x4640, 0x805E, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x1000, 0x0000, 0x5300, 0x5368, 
            0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 0x0000, 0xFA00, 0x0044, 
            0x0000, 0x6900, 0x6CEE, 0xCD3E, 0xCCCC, 0x5C3D, 0x1100, 0x0000, 
            0x4F00, 0x6373, 0x6853, 0x7061, 0x7365, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3E88, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0012, 0x0000, 0x5954, 0x4550, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0013, 0x0000, 0x6853, 0x6953, 0x4D6E, 0x7869, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x4040, 0x0000, 0x4000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x0014, 0x0000, 0x6678, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x506C, 0x3E89, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0015, 0x0000, 0x7853, 0x6D53, 0x6F6F, 0x6874, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x447A, 0x0000, 0x0000, 0x209B, 
            0x3E9A, 0xCCCD, 0x3DCC, 0x005C, 0x0016, 0x0000, 0x6653, 0x7453, 
            0x6761, 0x0065, 0x0000, 0x0000, 0x0000, 0x7000, 0x0041, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x1700, 0x0000, 0x4600, 
            0x6461, 0x4F65, 0x006E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x1800, 0x0000, 
            0x5500, 0x6573, 0x4972, 0x706E, 0x7475, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x5287, 0x3F0E, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0019, 0x0000, 0x6572, 0x006C, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x4E3F, 0x8A6F, 0x003D, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x1A00, 0x0000, 0x6300, 0x7672, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x642D, 0x3F03, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(17)
		{
			0x003A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
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
		auto& midi_cc = this->getT(0).getT(0).getT(2);                                            // xnode_impl::midi_cc_t<NV>
		auto& pma_unscaled2 = this->getT(0).getT(0).getT(3);                                      // xnode_impl::pma_unscaled2_t<NV>
		auto& pma_unscaled1 = this->getT(0).getT(0).getT(4);                                      // xnode_impl::pma_unscaled1_t<NV>
		auto& chain9 = this->getT(0).getT(1);                                                     // xnode_impl::chain9_t<NV>
		auto& chain32 = this->getT(0).getT(1).getT(0);                                            // xnode_impl::chain32_t<NV>
		auto& branch = this->getT(0).getT(1).getT(0).getT(0);                                     // xnode_impl::branch_t<NV>
		auto& chain8 = this->getT(0).getT(1).getT(0).getT(0).getT(0);                             // xnode_impl::chain8_t<NV>
		auto& branch3 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0);                    // xnode_impl::branch3_t<NV>
		auto& chain34 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);            // xnode_impl::chain34_t<NV>
		auto& oscillator11 = this->getT(0).getT(1).getT(0).getT(0).                               // xnode_impl::oscillator11_t<NV>
                             getT(0).getT(0).getT(0).getT(0);
		auto& smoothed_parameter5 = this->getT(0).getT(1).getT(0).getT(0).                        // xnode_impl::smoothed_parameter5_t<NV>
                                    getT(0).getT(0).getT(0).getT(1);
		auto& expr5 = this->getT(0).getT(1).getT(0).getT(0).                                      // math::expr<NV, custom::expr5>
                      getT(0).getT(0).getT(0).getT(2);
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
		auto& oscillator10 = this->getT(0).getT(1).getT(0).getT(0).                               // xnode_impl::oscillator10_t<NV>
                             getT(0).getT(0).getT(2).getT(0);
		auto& gain4 = this->getT(0).getT(1).getT(0).getT(0).                                      // core::gain<NV>
                      getT(0).getT(0).getT(2).getT(1);
		auto& fmod1 = this->getT(0).getT(1).getT(0).getT(0).                                      // math::fmod<NV>
                      getT(0).getT(0).getT(2).getT(2);
		auto& table = this->getT(0).getT(1).getT(0).getT(0).                                      // xnode_impl::table_t
                      getT(0).getT(0).getT(2).getT(3);
		auto& chain13 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(3);            // xnode_impl::chain13_t<NV>
		auto& oscillator14 = this->getT(0).getT(1).getT(0).getT(0).                               // xnode_impl::oscillator14_t<NV>
                             getT(0).getT(0).getT(3).getT(0);
		auto& gain7 = this->getT(0).getT(1).getT(0).getT(0).                                      // core::gain<NV>
                      getT(0).getT(0).getT(3).getT(1);
		auto& table1 = this->getT(0).getT(1).getT(0).getT(0).                                     // xnode_impl::table1_t
                       getT(0).getT(0).getT(3).getT(2);
		auto& chain22 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(4);            // xnode_impl::chain22_t<NV>
		auto& phasor4 = this->getT(0).getT(1).getT(0).getT(0).                                    // core::phasor<NV>
                        getT(0).getT(0).getT(4).getT(0);
		auto& mono2stereo2 = this->getT(0).getT(1).getT(0).getT(0).                               // core::mono2stereo
                             getT(0).getT(0).getT(4).getT(1);
		auto& gain6 = this->getT(0).getT(1).getT(0).getT(0).                                      // core::gain<NV>
                      getT(0).getT(0).getT(4).getT(2);
		auto& pi1 = this->getT(0).getT(1).getT(0).getT(0).                                        // math::pi<NV>
                    getT(0).getT(0).getT(4).getT(3);
		auto& rect1 = this->getT(0).getT(1).getT(0).getT(0).                                      // math::rect<NV>
                      getT(0).getT(0).getT(4).getT(4);
		auto& chain45 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(5);            // xnode_impl::chain45_t<NV>
		auto& oscillator13 = this->getT(0).getT(1).getT(0).getT(0).                               // xnode_impl::oscillator13_t<NV>
                             getT(0).getT(0).getT(5).getT(0);
		auto& midi2 = this->getT(0).getT(1).getT(0).getT(0).                                      // xnode_impl::midi2_t<NV>
                      getT(0).getT(0).getT(5).getT(1);
		auto& converter4 = this->getT(0).getT(1).getT(0).getT(0).                                 // xnode_impl::converter4_t<NV>
                           getT(0).getT(0).getT(5).getT(2);
		auto& normaliser = this->getT(0).getT(1).getT(0).getT(0).                                 // xnode_impl::normaliser_t<NV>
                           getT(0).getT(0).getT(5).getT(3);
		auto& pma_unscaled3 = this->getT(0).getT(1).getT(0).getT(0).                              // xnode_impl::pma_unscaled3_t<NV>
                              getT(0).getT(0).getT(5).getT(4);
		auto& ladder = this->getT(0).getT(1).getT(0).getT(0).                                     // filters::ladder<NV>
                       getT(0).getT(0).getT(5).getT(5);
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
		auto& midichain = this->getT(0).getT(1).getT(0).getT(1);                                  // xnode_impl::midichain_t<NV>
		auto& oscilloscope = this->getT(0).getT(1).getT(0).getT(1).getT(0);                       // xnode_impl::oscilloscope_t
		auto& midi = this->getT(0).getT(1).getT(0).getT(1).getT(1);                               // control::midi<midi_logic::notenumber<NV>>
		auto& chain1 = this->getT(0).getT(2);                                                     // xnode_impl::chain1_t<NV>
		auto& xfader = this->getT(0).getT(2).getT(0);                                             // xnode_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(2).getT(1);                                              // xnode_impl::split_t<NV>
		auto& chain2 = this->getT(0).getT(2).getT(1).getT(0);                                     // xnode_impl::chain2_t<NV>
		auto& gain = this->getT(0).getT(2).getT(1).getT(0).getT(0);                               // core::gain<NV>
		auto& chain3 = this->getT(0).getT(2).getT(1).getT(1);                                     // xnode_impl::chain3_t<NV>
		auto& chain33 = this->getT(0).getT(2).getT(1).getT(1).getT(0);                            // xnode_impl::chain33_t<NV>
		auto& chain7 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(0);                     // xnode_impl::chain7_t<NV>
		auto& branch5 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(0).getT(0);            // xnode_impl::branch5_t<NV>
		auto& chain17 = this->getT(0).getT(2).getT(1).getT(1).                                    // xnode_impl::chain17_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& modchain = this->getT(0).getT(2).getT(1).getT(1).                        // xnode_impl::modchain_t<NV>
                         getT(0).getT(0).getT(0).getT(0).
                         getT(0);
		auto& tempo_sync = this->getT(0).getT(2).getT(1).getT(1).getT(0).              // xnode_impl::tempo_sync_t<NV>
                           getT(0).getT(0).getT(0).getT(0).getT(0);
		auto& sig2mod = this->getT(0).getT(2).getT(1).getT(1).getT(0).                 // wrap::no_process<math::sig2mod<NV>>
                        getT(0).getT(0).getT(0).getT(0).getT(1);
		auto& sampleandhold = this->getT(0).getT(2).getT(1).getT(1).                   // fx::sampleandhold<NV>
                              getT(0).getT(0).getT(0).getT(0).
                              getT(1);
		auto& chain18 = this->getT(0).getT(2).getT(1).getT(1).                         // xnode_impl::chain18_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& chain10 = this->getT(0).getT(2).getT(1).getT(1).                         // xnode_impl::chain10_t<NV>
                        getT(0).getT(0).getT(0).getT(1).
                        getT(0);
		auto& modchain5 = this->getT(0).getT(2).getT(1).getT(1).getT(0).               // xnode_impl::modchain5_t<NV>
                          getT(0).getT(0).getT(1).getT(0).getT(0);
		auto& tempo_sync2 = this->getT(0).getT(2).getT(1).getT(1).getT(0).             // xnode_impl::tempo_sync2_t<NV>
                            getT(0).getT(0).getT(1).getT(0).getT(0).
                            getT(0);
		auto& sig2mod3 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                // wrap::no_process<math::sig2mod<NV>>
                         getT(0).getT(0).getT(1).getT(0).getT(0).
                         getT(1);
		auto& modchain3 = this->getT(0).getT(2).getT(1).getT(1).getT(0).               // xnode_impl::modchain3_t<NV>
                          getT(0).getT(0).getT(1).getT(0).getT(1);
		auto& ramp = this->getT(0).getT(2).getT(1).getT(1).getT(0).                    // xnode_impl::ramp_t<NV>
                     getT(0).getT(0).getT(1).getT(0).getT(1).
                     getT(0);
		auto& pi3 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                     // math::pi<NV>
                    getT(0).getT(0).getT(1).getT(0).getT(1).
                    getT(1);
		auto& sin2 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                    // math::sin<NV>
                     getT(0).getT(0).getT(1).getT(0).getT(1).
                     getT(2);
		auto& peak1 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                   // xnode_impl::peak1_t<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(1).
                      getT(3);
		auto& gain8 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                   // core::gain<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(2);
		auto& pi = this->getT(0).getT(2).getT(1).getT(1).getT(0).                      // math::pi<NV>
                   getT(0).getT(0).getT(1).getT(0).getT(3);
		auto& sin = this->getT(0).getT(2).getT(1).getT(1).getT(0).                     // wrap::no_process<math::sin<NV>>
                    getT(0).getT(0).getT(1).getT(0).getT(4);
		auto& sig2mod1 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                // math::sig2mod<NV>
                         getT(0).getT(0).getT(1).getT(0).getT(5);
		auto& chain20 = this->getT(0).getT(2).getT(1).getT(1).                         // xnode_impl::chain20_t<NV>
                        getT(0).getT(0).getT(0).getT(2);
		auto& modchain4 = this->getT(0).getT(2).getT(1).getT(1).                       // xnode_impl::modchain4_t<NV>
                          getT(0).getT(0).getT(0).getT(2).
                          getT(0);
		auto& tempo_sync1 = this->getT(0).getT(2).getT(1).getT(1).getT(0).             // xnode_impl::tempo_sync1_t<NV>
                            getT(0).getT(0).getT(2).getT(0).getT(0);
		auto& sig2mod2 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                // wrap::no_process<math::sig2mod<NV>>
                         getT(0).getT(0).getT(2).getT(0).getT(1);
		auto& converter = this->getT(0).getT(2).getT(1).getT(1).                       // xnode_impl::converter_t<NV>
                          getT(0).getT(0).getT(0).getT(2).
                          getT(1);
		auto& phasor_fm = this->getT(0).getT(2).getT(1).getT(1).                       // core::phasor_fm<NV>
                          getT(0).getT(0).getT(0).getT(2).
                          getT(2);
		auto& mono2stereo = this->getT(0).getT(2).getT(1).getT(1).                     // core::mono2stereo
                            getT(0).getT(0).getT(0).getT(2).
                            getT(3);
		auto& peak = this->getT(0).getT(2).getT(1).getT(1).getT(1);                    // xnode_impl::peak_t<NV>
		auto& multi = this->getT(0).getT(2).getT(1).getT(1).getT(2);                   // xnode_impl::multi_t<NV>
		auto& smoother = this->getT(0).getT(2).getT(1).getT(1).getT(2).getT(0);        // core::smoother<NV>
		auto& smoother1 = this->getT(0).getT(2).getT(1).getT(1).getT(2).getT(1);       // core::smoother<NV>
		auto& gain1 = this->getT(0).getT(2).getT(1).getT(1).getT(3);                   // core::gain<NV>
		auto& chain4 = this->getT(0).getT(3);                                          // xnode_impl::chain4_t<NV>
		auto& midichain1 = this->getT(0).getT(3).getT(0);                              // xnode_impl::midichain1_t
		auto& oscilloscope1 = this->getT(0).getT(3).getT(0).getT(0);                   // xnode_impl::oscilloscope1_t
		auto& xfader1 = this->getT(0).getT(3).getT(1);                                 // xnode_impl::xfader1_t<NV>
		auto& split1 = this->getT(0).getT(3).getT(2);                                  // xnode_impl::split1_t<NV>
		auto& chain5 = this->getT(0).getT(3).getT(2).getT(0);                          // xnode_impl::chain5_t<NV>
		auto& gain2 = this->getT(0).getT(3).getT(2).getT(0).getT(0);                   // core::gain<NV>
		auto& chain6 = this->getT(0).getT(3).getT(2).getT(1);                          // xnode_impl::chain6_t<NV>
		auto& modchain2 = this->getT(0).getT(3).getT(2).getT(1).getT(0);               // xnode_impl::modchain2_t<NV>
		auto& pma = this->getT(0).getT(3).getT(2).getT(1).getT(0).getT(0);             // xnode_impl::pma_t<NV>
		auto& branch2 = this->getT(0).getT(3).getT(2).getT(1).getT(1);                 // xnode_impl::branch2_t<NV>
		auto& svf = this->getT(0).getT(3).getT(2).getT(1).getT(1).getT(0);             // filters::svf<NV>
		auto& svf2 = this->getT(0).getT(3).getT(2).getT(1).getT(1).getT(1);            // filters::svf<NV>
		auto& svf1 = this->getT(0).getT(3).getT(2).getT(1).getT(1).getT(2);            // filters::svf<NV>
		auto& chain42 = this->getT(0).getT(3).getT(2).getT(1).getT(1).getT(3);         // xnode_impl::chain42_t<NV>
		auto& allpass = this->getT(0).getT(3).getT(2).getT(1).getT(1).getT(3).getT(0); // filters::allpass<NV>
		auto& gain3 = this->getT(0).getT(3).getT(2).getT(1).getT(2);                   // core::gain<NV>
		auto& gain5 = this->getT(0).getT(4);                                           // core::gain<NV>
		auto& branch4 = this->getT(1);                                                 // xnode_impl::branch4_t<NV>
		auto& chain41 = this->getT(1).getT(0);                                         // xnode_impl::chain41_t
		auto& branch1 = this->getT(1).getT(1);                                         // xnode_impl::branch1_t<NV>
		auto& chain19 = this->getT(1).getT(1).getT(0);                                 // xnode_impl::chain19_t<NV>
		auto& cable_pack = this->getT(1).getT(1).getT(0).getT(0);                      // xnode_impl::cable_pack_t<NV>
		auto& smoothed_parameter1 = this->getT(1).getT(1).getT(0).getT(1);             // xnode_impl::smoothed_parameter1_t<NV>
		auto& mul17 = this->getT(1).getT(1).getT(0).getT(2);                           // math::mul<NV>
		auto& chain21 = this->getT(1).getT(1).getT(1);                                 // xnode_impl::chain21_t<NV>
		auto& cable_pack1 = this->getT(1).getT(1).getT(1).getT(0);                     // xnode_impl::cable_pack1_t<NV>
		auto& smoothed_parameter2 = this->getT(1).getT(1).getT(1).getT(1);             // xnode_impl::smoothed_parameter2_t<NV>
		auto& mul = this->getT(1).getT(1).getT(1).getT(2);                             // math::mul<NV>
		auto& chain23 = this->getT(1).getT(1).getT(2);                                 // xnode_impl::chain23_t<NV>
		auto& cable_pack3 = this->getT(1).getT(1).getT(2).getT(0);                     // xnode_impl::cable_pack3_t<NV>
		auto& smoothed_parameter4 = this->getT(1).getT(1).getT(2).getT(1);             // xnode_impl::smoothed_parameter4_t<NV>
		auto& mul15 = this->getT(1).getT(1).getT(2).getT(2);                           // math::mul<NV>
		auto& chain24 = this->getT(1).getT(1).getT(3);                                 // xnode_impl::chain24_t<NV>
		auto& cable_pack4 = this->getT(1).getT(1).getT(3).getT(0);                     // xnode_impl::cable_pack4_t<NV>
		auto& smoothed_parameter6 = this->getT(1).getT(1).getT(3).getT(1);             // xnode_impl::smoothed_parameter6_t<NV>
		auto& mul16 = this->getT(1).getT(1).getT(3).getT(2);                           // math::mul<NV>
		auto& chain25 = this->getT(1).getT(1).getT(4);                                 // xnode_impl::chain25_t<NV>
		auto& cable_pack5 = this->getT(1).getT(1).getT(4).getT(0);                     // xnode_impl::cable_pack5_t<NV>
		auto& smoothed_parameter7 = this->getT(1).getT(1).getT(4).getT(1);             // xnode_impl::smoothed_parameter7_t<NV>
		auto& mul18 = this->getT(1).getT(1).getT(4).getT(2);                           // math::mul<NV>
		auto& chain26 = this->getT(1).getT(1).getT(5);                                 // xnode_impl::chain26_t<NV>
		auto& cable_pack6 = this->getT(1).getT(1).getT(5).getT(0);                     // xnode_impl::cable_pack6_t<NV>
		auto& smoothed_parameter8 = this->getT(1).getT(1).getT(5).getT(1);             // xnode_impl::smoothed_parameter8_t<NV>
		auto& mul19 = this->getT(1).getT(1).getT(5).getT(2);                           // math::mul<NV>
		auto& chain27 = this->getT(1).getT(1).getT(6);                                 // xnode_impl::chain27_t<NV>
		auto& cable_pack7 = this->getT(1).getT(1).getT(6).getT(0);                     // xnode_impl::cable_pack7_t<NV>
		auto& smoothed_parameter9 = this->getT(1).getT(1).getT(6).getT(1);             // xnode_impl::smoothed_parameter9_t<NV>
		auto& mul13 = this->getT(1).getT(1).getT(6).getT(2);                           // math::mul<NV>
		auto& chain28 = this->getT(1).getT(1).getT(7);                                 // xnode_impl::chain28_t<NV>
		auto& cable_pack8 = this->getT(1).getT(1).getT(7).getT(0);                     // xnode_impl::cable_pack8_t<NV>
		auto& smoothed_parameter10 = this->getT(1).getT(1).getT(7).getT(1);            // xnode_impl::smoothed_parameter10_t<NV>
		auto& mul21 = this->getT(1).getT(1).getT(7).getT(2);                           // math::mul<NV>
		auto& chain29 = this->getT(1).getT(1).getT(8);                                 // xnode_impl::chain29_t<NV>
		auto& cable_pack9 = this->getT(1).getT(1).getT(8).getT(0);                     // xnode_impl::cable_pack9_t<NV>
		auto& smoothed_parameter11 = this->getT(1).getT(1).getT(8).getT(1);            // xnode_impl::smoothed_parameter11_t<NV>
		auto& mul22 = this->getT(1).getT(1).getT(8).getT(2);                           // math::mul<NV>
		auto& chain30 = this->getT(1).getT(1).getT(9);                                 // xnode_impl::chain30_t<NV>
		auto& cable_pack10 = this->getT(1).getT(1).getT(9).getT(0);                    // xnode_impl::cable_pack10_t<NV>
		auto& smoothed_parameter12 = this->getT(1).getT(1).getT(9).getT(1);            // xnode_impl::smoothed_parameter12_t<NV>
		auto& mul20 = this->getT(1).getT(1).getT(9).getT(2);                           // math::mul<NV>
		auto& chain31 = this->getT(1).getT(1).getT(10);                                // xnode_impl::chain31_t<NV>
		auto& cable_pack11 = this->getT(1).getT(1).getT(10).getT(0);                   // xnode_impl::cable_pack11_t<NV>
		auto& smoothed_parameter13 = this->getT(1).getT(1).getT(10).getT(1);           // xnode_impl::smoothed_parameter13_t<NV>
		auto& mul23 = this->getT(1).getT(1).getT(10).getT(2);                          // math::mul<NV>
		auto& chain35 = this->getT(1).getT(1).getT(11);                                // xnode_impl::chain35_t<NV>
		auto& cable_pack12 = this->getT(1).getT(1).getT(11).getT(0);                   // xnode_impl::cable_pack12_t<NV>
		auto& smoothed_parameter14 = this->getT(1).getT(1).getT(11).getT(1);           // xnode_impl::smoothed_parameter14_t<NV>
		auto& mul25 = this->getT(1).getT(1).getT(11).getT(2);                          // math::mul<NV>
		auto& chain36 = this->getT(1).getT(1).getT(12);                                // xnode_impl::chain36_t<NV>
		auto& cable_pack13 = this->getT(1).getT(1).getT(12).getT(0);                   // xnode_impl::cable_pack13_t<NV>
		auto& smoothed_parameter15 = this->getT(1).getT(1).getT(12).getT(1);           // xnode_impl::smoothed_parameter15_t<NV>
		auto& mul24 = this->getT(1).getT(1).getT(12).getT(2);                          // math::mul<NV>
		auto& chain38 = this->getT(1).getT(1).getT(13);                                // xnode_impl::chain38_t<NV>
		auto& cable_pack14 = this->getT(1).getT(1).getT(13).getT(0);                   // xnode_impl::cable_pack14_t<NV>
		auto& smoothed_parameter16 = this->getT(1).getT(1).getT(13).getT(1);           // xnode_impl::smoothed_parameter16_t<NV>
		auto& mul27 = this->getT(1).getT(1).getT(13).getT(2);                          // math::mul<NV>
		auto& chain39 = this->getT(1).getT(1).getT(14);                                // xnode_impl::chain39_t<NV>
		auto& cable_pack15 = this->getT(1).getT(1).getT(14).getT(0);                   // xnode_impl::cable_pack15_t<NV>
		auto& smoothed_parameter17 = this->getT(1).getT(1).getT(14).getT(1);           // xnode_impl::smoothed_parameter17_t<NV>
		auto& mul28 = this->getT(1).getT(1).getT(14).getT(2);                          // math::mul<NV>
		auto& chain40 = this->getT(1).getT(1).getT(15);                                // xnode_impl::chain40_t<NV>
		auto& cable_pack16 = this->getT(1).getT(1).getT(15).getT(0);                   // xnode_impl::cable_pack16_t<NV>
		auto& smoothed_parameter18 = this->getT(1).getT(1).getT(15).getT(1);           // xnode_impl::smoothed_parameter18_t<NV>
		auto& mul26 = this->getT(1).getT(1).getT(15).getT(2);                          // math::mul<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain45.getParameterT(0).connectT(0, normaliser); // harm -> normaliser::Value
		chain45.getParameterT(0).connectT(0, normaliser); // harm -> normaliser::Value
		this->getParameterT(0).connectT(0, minmax);       // Harm -> minmax::Value
		
		this->getParameterT(1).connectT(0, minmax); // min -> minmax::Minimum
		
		this->getParameterT(2).connectT(0, minmax); // max -> minmax::Maximum
		
		this->getParameterT(3).connectT(0, minmax); // step -> minmax::Step
		
		this->getParameterT(4).connectT(0, branch3); // Mode -> branch3::Index
		
		this->getParameterT(5).connectT(0, xfader); // FxMix -> xfader::Value
		
		auto& FxValue_p = this->getParameterT(6);
		FxValue_p.connectT(0, tempo_sync);  // FxValue -> tempo_sync::Tempo
		FxValue_p.connectT(1, tempo_sync);  // FxValue -> tempo_sync::UnsyncedTime
		FxValue_p.connectT(2, tempo_sync2); // FxValue -> tempo_sync2::Tempo
		FxValue_p.connectT(3, tempo_sync1); // FxValue -> tempo_sync1::Tempo
		FxValue_p.connectT(4, tempo_sync2); // FxValue -> tempo_sync2::UnsyncedTime
		FxValue_p.connectT(5, tempo_sync1); // FxValue -> tempo_sync1::UnsyncedTime
		
		auto& FxShDiv_p = this->getParameterT(7);
		FxShDiv_p.connectT(0, tempo_sync);  // FxShDiv -> tempo_sync::Multiplier
		FxShDiv_p.connectT(1, tempo_sync2); // FxShDiv -> tempo_sync2::Multiplier
		FxShDiv_p.connectT(2, tempo_sync1); // FxShDiv -> tempo_sync1::Multiplier
		
		auto& FxShSync_p = this->getParameterT(8);
		FxShSync_p.connectT(0, tempo_sync);  // FxShSync -> tempo_sync::Enabled
		FxShSync_p.connectT(1, tempo_sync2); // FxShSync -> tempo_sync2::Enabled
		FxShSync_p.connectT(2, tempo_sync1); // FxShSync -> tempo_sync1::Enabled
		
		this->getParameterT(9).connectT(0, pma_unscaled1); // shPitch -> pma_unscaled1::Multiply
		
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
		ShSmooth_p.connectT(0, smoother);  // ShSmooth -> smoother::SmoothingTime
		ShSmooth_p.connectT(1, smoother1); // ShSmooth -> smoother1::SmoothingTime
		
		auto& OscShapes_p = this->getParameterT(17);
		OscShapes_p.connectT(0, smoothed_parameter3); // OscShapes -> smoothed_parameter3::Value
		OscShapes_p.connectT(1, smoothed_parameter);  // OscShapes -> smoothed_parameter::Value
		OscShapes_p.connectT(2, smoothed_parameter5); // OscShapes -> smoothed_parameter5::Value
		OscShapes_p.connectT(3, ladder);              // OscShapes -> ladder::Q
		OscShapes_p.connectT(4, gain4);               // OscShapes -> gain4::Gain
		OscShapes_p.connectT(5, gain6);               // OscShapes -> gain6::Gain
		OscShapes_p.connectT(6, gain7);               // OscShapes -> gain7::Gain
		
		this->getParameterT(18).connectT(0, branch); // TYPE -> branch::Index
		
		this->getParameterT(19).connectT(0, branch5); // ShSinMix -> branch5::Index
		
		auto& xf_p = this->getParameterT(20);
		xf_p.connectT(0, cable_pack1);   // xf -> cable_pack1::Value
		xf_p.connectT(1, cable_pack3);   // xf -> cable_pack3::Value
		xf_p.connectT(2, cable_pack4);   // xf -> cable_pack4::Value
		xf_p.connectT(3, cable_pack5);   // xf -> cable_pack5::Value
		xf_p.connectT(4, cable_pack6);   // xf -> cable_pack6::Value
		xf_p.connectT(5, cable_pack7);   // xf -> cable_pack7::Value
		xf_p.connectT(6, cable_pack8);   // xf -> cable_pack8::Value
		xf_p.connectT(7, cable_pack9);   // xf -> cable_pack9::Value
		xf_p.connectT(8, cable_pack10);  // xf -> cable_pack10::Value
		xf_p.connectT(9, cable_pack11);  // xf -> cable_pack11::Value
		xf_p.connectT(10, cable_pack12); // xf -> cable_pack12::Value
		xf_p.connectT(11, cable_pack13); // xf -> cable_pack13::Value
		xf_p.connectT(12, cable_pack14); // xf -> cable_pack14::Value
		xf_p.connectT(13, cable_pack15); // xf -> cable_pack15::Value
		xf_p.connectT(14, cable_pack16); // xf -> cable_pack16::Value
		xf_p.connectT(15, cable_pack);   // xf -> cable_pack::Value
		
		auto& SxSmooth_p = this->getParameterT(21);
		SxSmooth_p.connectT(0, smoothed_parameter1);   // SxSmooth -> smoothed_parameter1::SmoothingTime
		SxSmooth_p.connectT(1, smoothed_parameter2);   // SxSmooth -> smoothed_parameter2::SmoothingTime
		SxSmooth_p.connectT(2, smoothed_parameter6);   // SxSmooth -> smoothed_parameter6::SmoothingTime
		SxSmooth_p.connectT(3, smoothed_parameter7);   // SxSmooth -> smoothed_parameter7::SmoothingTime
		SxSmooth_p.connectT(4, smoothed_parameter8);   // SxSmooth -> smoothed_parameter8::SmoothingTime
		SxSmooth_p.connectT(5, smoothed_parameter9);   // SxSmooth -> smoothed_parameter9::SmoothingTime
		SxSmooth_p.connectT(6, smoothed_parameter10);  // SxSmooth -> smoothed_parameter10::SmoothingTime
		SxSmooth_p.connectT(7, smoothed_parameter11);  // SxSmooth -> smoothed_parameter11::SmoothingTime
		SxSmooth_p.connectT(8, smoothed_parameter12);  // SxSmooth -> smoothed_parameter12::SmoothingTime
		SxSmooth_p.connectT(9, smoothed_parameter13);  // SxSmooth -> smoothed_parameter13::SmoothingTime
		SxSmooth_p.connectT(10, smoothed_parameter14); // SxSmooth -> smoothed_parameter14::SmoothingTime
		SxSmooth_p.connectT(11, smoothed_parameter15); // SxSmooth -> smoothed_parameter15::SmoothingTime
		SxSmooth_p.connectT(12, smoothed_parameter16); // SxSmooth -> smoothed_parameter16::SmoothingTime
		SxSmooth_p.connectT(13, smoothed_parameter17); // SxSmooth -> smoothed_parameter17::SmoothingTime
		SxSmooth_p.connectT(14, smoothed_parameter18); // SxSmooth -> smoothed_parameter18::SmoothingTime
		SxSmooth_p.connectT(15, smoothed_parameter4);  // SxSmooth -> smoothed_parameter4::SmoothingTime
		
		this->getParameterT(22).connectT(0, branch1); // SfStage -> branch1::Index
		
		this->getParameterT(23).connectT(0, branch4); // FadeOn -> branch4::Index
		
		this->getParameterT(24).connectT(0, gain11); // UserInput -> gain11::Gain
		
		auto& rel_p = this->getParameterT(25);
		rel_p.connectT(0, gain4);  // rel -> gain4::ResetValue
		rel_p.connectT(1, gain7);  // rel -> gain7::ResetValue
		rel_p.connectT(2, gain6);  // rel -> gain6::ResetValue
		rel_p.connectT(3, gain11); // rel -> gain11::ResetValue
		rel_p.connectT(4, gain1);  // rel -> gain1::ResetValue
		rel_p.connectT(5, gain);   // rel -> gain::ResetValue
		rel_p.connectT(6, gain8);  // rel -> gain8::ResetValue
		rel_p.connectT(7, gain5);  // rel -> gain5::ResetValue
		rel_p.connectT(8, gain3);  // rel -> gain3::ResetValue
		rel_p.connectT(9, gain2);  // rel -> gain2::ResetValue
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma_unscaled3.getWrappedObject().getParameter().connectT(0, ladder);        // pma_unscaled3 -> ladder::Frequency
		converter4.getWrappedObject().getParameter().connectT(0, pma_unscaled3);    // converter4 -> pma_unscaled3::Add
		midi2.getParameter().connectT(0, converter4);                               // midi2 -> converter4::Value
		normaliser.getWrappedObject().getParameter().connectT(0, pma_unscaled3);    // normaliser -> pma_unscaled3::Value
		pma_unscaled1.getWrappedObject().getParameter().connectT(0, oscillator9);   // pma_unscaled1 -> oscillator9::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(1, oscillator10);  // pma_unscaled1 -> oscillator10::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(2, phasor4);       // pma_unscaled1 -> phasor4::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(3, oscillator11);  // pma_unscaled1 -> oscillator11::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(4, file_player5);  // pma_unscaled1 -> file_player5::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(5, phasor5);       // pma_unscaled1 -> phasor5::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(6, chain45);       // pma_unscaled1 -> chain45::harm
		pma_unscaled1.getWrappedObject().getParameter().connectT(7, oscillator14);  // pma_unscaled1 -> oscillator14::FreqRatio
		pma_unscaled2.getWrappedObject().getParameter().connectT(0, pma_unscaled1); // pma_unscaled2 -> pma_unscaled1::Add
		pma_unscaled.getWrappedObject().getParameter().connectT(0, pma_unscaled2);  // pma_unscaled -> pma_unscaled2::Add
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled);         // minmax -> pma_unscaled::Add
		midi_cc.getWrappedObject().getParameter().connectT(0, pma_unscaled2);       // midi_cc -> pma_unscaled2::Value
		smoothed_parameter5.getParameter().connectT(0, expr5);                      // smoothed_parameter5 -> expr5::Value
		smoothed_parameter3.getParameter().connectT(0, pi7);                        // smoothed_parameter3 -> pi7::Value
		smoothed_parameter.getParameter().connectT(0, add3);                        // smoothed_parameter -> add3::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                        // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);                       // xfader -> gain1::Gain
		tempo_sync.getParameter().connectT(0, sampleandhold);               // tempo_sync -> sampleandhold::Counter
		tempo_sync2.getParameter().connectT(0, ramp);                       // tempo_sync2 -> ramp::PeriodTime
		peak1.getParameter().connectT(0, gain8);                            // peak1 -> gain8::Gain
		converter.getWrappedObject().getParameter().connectT(0, phasor_fm); // converter -> phasor_fm::FreqRatio
		tempo_sync1.getParameter().connectT(0, converter);                  // tempo_sync1 -> converter::Value
		pma.getWrappedObject().getParameter().connectT(0, svf);             // pma -> svf::Frequency
		pma.getWrappedObject().getParameter().connectT(1, svf2);            // pma -> svf2::Frequency
		pma.getWrappedObject().getParameter().connectT(2, svf1);            // pma -> svf1::Frequency
		pma.getWrappedObject().getParameter().connectT(3, allpass);         // pma -> allpass::Frequency
		peak.getParameter().connectT(0, pma);                               // peak -> pma::Value
		peak.getParameter().connectT(1, pma_unscaled1);                     // peak -> pma_unscaled1::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain2);                                    // xfader1 -> gain2::Gain
		xfader1_p.getParameterT(1).connectT(0, gain3);                                    // xfader1 -> gain3::Gain
		smoothed_parameter1.getParameter().connectT(0, mul17);                            // smoothed_parameter1 -> mul17::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, smoothed_parameter1);    // cable_pack -> smoothed_parameter1::Value
		smoothed_parameter2.getParameter().connectT(0, mul);                              // smoothed_parameter2 -> mul::Value
		cable_pack1.getWrappedObject().getParameter().connectT(0, smoothed_parameter2);   // cable_pack1 -> smoothed_parameter2::Value
		smoothed_parameter4.getParameter().connectT(0, mul15);                            // smoothed_parameter4 -> mul15::Value
		cable_pack3.getWrappedObject().getParameter().connectT(0, smoothed_parameter4);   // cable_pack3 -> smoothed_parameter4::Value
		smoothed_parameter6.getParameter().connectT(0, mul16);                            // smoothed_parameter6 -> mul16::Value
		cable_pack4.getWrappedObject().getParameter().connectT(0, smoothed_parameter6);   // cable_pack4 -> smoothed_parameter6::Value
		smoothed_parameter7.getParameter().connectT(0, mul18);                            // smoothed_parameter7 -> mul18::Value
		cable_pack5.getWrappedObject().getParameter().connectT(0, smoothed_parameter7);   // cable_pack5 -> smoothed_parameter7::Value
		smoothed_parameter8.getParameter().connectT(0, mul19);                            // smoothed_parameter8 -> mul19::Value
		cable_pack6.getWrappedObject().getParameter().connectT(0, smoothed_parameter8);   // cable_pack6 -> smoothed_parameter8::Value
		smoothed_parameter9.getParameter().connectT(0, mul13);                            // smoothed_parameter9 -> mul13::Value
		cable_pack7.getWrappedObject().getParameter().connectT(0, smoothed_parameter9);   // cable_pack7 -> smoothed_parameter9::Value
		smoothed_parameter10.getParameter().connectT(0, mul21);                           // smoothed_parameter10 -> mul21::Value
		cable_pack8.getWrappedObject().getParameter().connectT(0, smoothed_parameter10);  // cable_pack8 -> smoothed_parameter10::Value
		smoothed_parameter11.getParameter().connectT(0, mul22);                           // smoothed_parameter11 -> mul22::Value
		cable_pack9.getWrappedObject().getParameter().connectT(0, smoothed_parameter11);  // cable_pack9 -> smoothed_parameter11::Value
		smoothed_parameter12.getParameter().connectT(0, mul20);                           // smoothed_parameter12 -> mul20::Value
		cable_pack10.getWrappedObject().getParameter().connectT(0, smoothed_parameter12); // cable_pack10 -> smoothed_parameter12::Value
		smoothed_parameter13.getParameter().connectT(0, mul23);                           // smoothed_parameter13 -> mul23::Value
		cable_pack11.getWrappedObject().getParameter().connectT(0, smoothed_parameter13); // cable_pack11 -> smoothed_parameter13::Value
		smoothed_parameter14.getParameter().connectT(0, mul25);                           // smoothed_parameter14 -> mul25::Value
		cable_pack12.getWrappedObject().getParameter().connectT(0, smoothed_parameter14); // cable_pack12 -> smoothed_parameter14::Value
		smoothed_parameter15.getParameter().connectT(0, mul24);                           // smoothed_parameter15 -> mul24::Value
		cable_pack13.getWrappedObject().getParameter().connectT(0, smoothed_parameter15); // cable_pack13 -> smoothed_parameter15::Value
		smoothed_parameter16.getParameter().connectT(0, mul27);                           // smoothed_parameter16 -> mul27::Value
		cable_pack14.getWrappedObject().getParameter().connectT(0, smoothed_parameter16); // cable_pack14 -> smoothed_parameter16::Value
		smoothed_parameter17.getParameter().connectT(0, mul28);                           // smoothed_parameter17 -> mul28::Value
		cable_pack15.getWrappedObject().getParameter().connectT(0, smoothed_parameter17); // cable_pack15 -> smoothed_parameter17::Value
		smoothed_parameter18.getParameter().connectT(0, mul26);                           // smoothed_parameter18 -> mul26::Value
		cable_pack16.getWrappedObject().getParameter().connectT(0, smoothed_parameter18); // cable_pack16 -> smoothed_parameter18::Value
		
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
		
		midi_cc.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                                   // pma_unscaled2::Value is automated
		pma_unscaled2.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled2::Add is automated
		
		; // pma_unscaled1::Value is automated
		; // pma_unscaled1::Multiply is automated
		; // pma_unscaled1::Add is automated
		
		; // branch::Index is automated
		
		; // branch3::Index is automated
		
		oscillator11.setParameterT(0, 2.);   // core::oscillator::Mode
		oscillator11.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                    // oscillator11::FreqRatio is automated
		oscillator11.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator11.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator11.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                                            // smoothed_parameter5::Value is automated
		smoothed_parameter5.setParameterT(1, 317.4); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter5.setParameterT(2, 1.);    // control::smoothed_parameter::Enabled
		
		; // expr5::Value is automated
		
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
		
		oscillator10.setParameterT(0, 2.);   // core::oscillator::Mode
		oscillator10.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                    // oscillator10::FreqRatio is automated
		oscillator10.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator10.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator10.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		;                            // gain4::ResetValue is automated
		
		fmod1.setParameterT(0, 1.); // math::fmod::Value
		
		oscillator14.setParameterT(0, 2.);   // core::oscillator::Mode
		oscillator14.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                    // oscillator14::FreqRatio is automated
		oscillator14.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator14.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator14.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                            // gain7::Gain is automated
		gain7.setParameterT(1, 20.); // core::gain::Smoothing
		;                            // gain7::ResetValue is automated
		
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
		
		oscillator13.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator13.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator13.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator13.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator13.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator13.setParameterT(5, 1.);   // core::oscillator::Gain
		
		; // converter4::Value is automated
		
		; // normaliser::Value is automated
		
		;                                   // pma_unscaled3::Value is automated
		pma_unscaled3.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled3::Add is automated
		
		;                              // ladder::Frequency is automated
		;                              // ladder::Q is automated
		ladder.setParameterT(2, 0.);   // filters::ladder::Gain
		ladder.setParameterT(3, 0.01); // filters::ladder::Smoothing
		ladder.setParameterT(4, 0.);   // filters::ladder::Mode
		ladder.setParameterT(5, 1.);   // filters::ladder::Enabled
		
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
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		;                           // gain::ResetValue is automated
		
		; // branch5::Index is automated
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // sampleandhold::Counter is automated
		
		; // tempo_sync2::Tempo is automated
		; // tempo_sync2::Multiplier is automated
		; // tempo_sync2::Enabled is automated
		; // tempo_sync2::UnsyncedTime is automated
		
		sig2mod3.setParameterT(0, 0.); // math::sig2mod::Value
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		pi3.setParameterT(0, 1.); // math::pi::Value
		
		sin2.setParameterT(0, 2.); // math::sin::Value
		
		;                            // gain8::Gain is automated
		gain8.setParameterT(1, 0.9); // core::gain::Smoothing
		;                            // gain8::ResetValue is automated
		
		pi.setParameterT(0, 0.503571); // math::pi::Value
		
		sin.setParameterT(0, 0.43099); // math::sin::Value
		
		sig2mod1.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // tempo_sync1::Tempo is automated
		; // tempo_sync1::Multiplier is automated
		; // tempo_sync1::Enabled is automated
		; // tempo_sync1::UnsyncedTime is automated
		
		sig2mod2.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // converter::Value is automated
		
		phasor_fm.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm.setParameterT(1, 220.); // core::phasor_fm::Frequency
		;                                 // phasor_fm::FreqRatio is automated
		phasor_fm.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		;                              // smoother::SmoothingTime is automated
		smoother.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		;                               // smoother1::SmoothingTime is automated
		smoother1.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		;                            // gain1::ResetValue is automated
		
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
		
		gain5.setParameterT(0, -21.);  // core::gain::Gain
		gain5.setParameterT(1, 167.6); // core::gain::Smoothing
		;                              // gain5::ResetValue is automated
		
		; // branch4::Index is automated
		
		; // branch1::Index is automated
		
		; // cable_pack::Value is automated
		
		;                                         // smoothed_parameter1::Value is automated
		;                                         // smoothed_parameter1::SmoothingTime is automated
		smoothed_parameter1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul17::Value is automated
		
		; // cable_pack1::Value is automated
		
		;                                         // smoothed_parameter2::Value is automated
		;                                         // smoothed_parameter2::SmoothingTime is automated
		smoothed_parameter2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul::Value is automated
		
		; // cable_pack3::Value is automated
		
		;                                         // smoothed_parameter4::Value is automated
		;                                         // smoothed_parameter4::SmoothingTime is automated
		smoothed_parameter4.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul15::Value is automated
		
		; // cable_pack4::Value is automated
		
		;                                         // smoothed_parameter6::Value is automated
		;                                         // smoothed_parameter6::SmoothingTime is automated
		smoothed_parameter6.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul16::Value is automated
		
		; // cable_pack5::Value is automated
		
		;                                         // smoothed_parameter7::Value is automated
		;                                         // smoothed_parameter7::SmoothingTime is automated
		smoothed_parameter7.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul18::Value is automated
		
		; // cable_pack6::Value is automated
		
		;                                         // smoothed_parameter8::Value is automated
		;                                         // smoothed_parameter8::SmoothingTime is automated
		smoothed_parameter8.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul19::Value is automated
		
		; // cable_pack7::Value is automated
		
		;                                         // smoothed_parameter9::Value is automated
		;                                         // smoothed_parameter9::SmoothingTime is automated
		smoothed_parameter9.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul13::Value is automated
		
		; // cable_pack8::Value is automated
		
		;                                          // smoothed_parameter10::Value is automated
		;                                          // smoothed_parameter10::SmoothingTime is automated
		smoothed_parameter10.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul21::Value is automated
		
		; // cable_pack9::Value is automated
		
		;                                          // smoothed_parameter11::Value is automated
		;                                          // smoothed_parameter11::SmoothingTime is automated
		smoothed_parameter11.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul22::Value is automated
		
		; // cable_pack10::Value is automated
		
		;                                          // smoothed_parameter12::Value is automated
		;                                          // smoothed_parameter12::SmoothingTime is automated
		smoothed_parameter12.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul20::Value is automated
		
		; // cable_pack11::Value is automated
		
		;                                          // smoothed_parameter13::Value is automated
		;                                          // smoothed_parameter13::SmoothingTime is automated
		smoothed_parameter13.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul23::Value is automated
		
		; // cable_pack12::Value is automated
		
		;                                          // smoothed_parameter14::Value is automated
		;                                          // smoothed_parameter14::SmoothingTime is automated
		smoothed_parameter14.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul25::Value is automated
		
		; // cable_pack13::Value is automated
		
		;                                          // smoothed_parameter15::Value is automated
		;                                          // smoothed_parameter15::SmoothingTime is automated
		smoothed_parameter15.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul24::Value is automated
		
		; // cable_pack14::Value is automated
		
		;                                          // smoothed_parameter16::Value is automated
		;                                          // smoothed_parameter16::SmoothingTime is automated
		smoothed_parameter16.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul27::Value is automated
		
		; // cable_pack15::Value is automated
		
		;                                          // smoothed_parameter17::Value is automated
		;                                          // smoothed_parameter17::SmoothingTime is automated
		smoothed_parameter17.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul28::Value is automated
		
		; // cable_pack16::Value is automated
		
		;                                          // smoothed_parameter18::Value is automated
		;                                          // smoothed_parameter18::SmoothingTime is automated
		smoothed_parameter18.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // mul26::Value is automated
		
		this->setParameterT(0, 0.574304);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 16.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.466033);
		this->setParameterT(7, 32.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 3.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 0.588825);
		this->setParameterT(14, -0.328974);
		this->setParameterT(15, 1.00288);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 0.265625);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 2.);
		this->setParameterT(20, 0.268192);
		this->setParameterT(21, 0.);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 0.);
		this->setParameterT(24, 0.555947);
		this->setParameterT(25, 0.0675951);
		this->setParameterT(26, 0.513247);
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
		
		this->getT(0).getT(1).getT(0).getT(0).                                                   // xnode_impl::oscillator11_t<NV>
        getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).                                                   // xnode_impl::oscillator9_t<NV>
        getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).                                                   // xnode_impl::oscillator10_t<NV>
        getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).                                                   // xnode_impl::table_t
        getT(0).getT(0).getT(2).getT(3).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).                                                   // xnode_impl::oscillator14_t<NV>
        getT(0).getT(0).getT(3).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).                                                   // xnode_impl::table1_t
        getT(0).getT(0).getT(3).getT(2).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).                                                   // xnode_impl::oscillator13_t<NV>
        getT(0).getT(0).getT(5).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index); // xnode_impl::file_player5_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).getT(4).setExternalData(b, index); // xnode_impl::file_player6_t<NV>
		this->getT(0).getT(1).getT(0).getT(1).getT(0).setExternalData(b, index);                 // xnode_impl::oscilloscope_t
		this->getT(0).getT(2).getT(1).getT(1).getT(0).                                           // xnode_impl::ramp_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(1).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(2).getT(1).getT(1).getT(0).                           // xnode_impl::peak1_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(0).getT(2).getT(1).getT(1).getT(1).setExternalData(b, index); // xnode_impl::peak_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).setExternalData(b, index);         // xnode_impl::oscilloscope1_t
		this->getT(1).getT(1).getT(0).getT(0).setExternalData(b, index);         // xnode_impl::cable_pack_t<NV>
		this->getT(1).getT(1).getT(1).getT(0).setExternalData(b, index);         // xnode_impl::cable_pack1_t<NV>
		this->getT(1).getT(1).getT(2).getT(0).setExternalData(b, index);         // xnode_impl::cable_pack3_t<NV>
		this->getT(1).getT(1).getT(3).getT(0).setExternalData(b, index);         // xnode_impl::cable_pack4_t<NV>
		this->getT(1).getT(1).getT(4).getT(0).setExternalData(b, index);         // xnode_impl::cable_pack5_t<NV>
		this->getT(1).getT(1).getT(5).getT(0).setExternalData(b, index);         // xnode_impl::cable_pack6_t<NV>
		this->getT(1).getT(1).getT(6).getT(0).setExternalData(b, index);         // xnode_impl::cable_pack7_t<NV>
		this->getT(1).getT(1).getT(7).getT(0).setExternalData(b, index);         // xnode_impl::cable_pack8_t<NV>
		this->getT(1).getT(1).getT(8).getT(0).setExternalData(b, index);         // xnode_impl::cable_pack9_t<NV>
		this->getT(1).getT(1).getT(9).getT(0).setExternalData(b, index);         // xnode_impl::cable_pack10_t<NV>
		this->getT(1).getT(1).getT(10).getT(0).setExternalData(b, index);        // xnode_impl::cable_pack11_t<NV>
		this->getT(1).getT(1).getT(11).getT(0).setExternalData(b, index);        // xnode_impl::cable_pack12_t<NV>
		this->getT(1).getT(1).getT(12).getT(0).setExternalData(b, index);        // xnode_impl::cable_pack13_t<NV>
		this->getT(1).getT(1).getT(13).getT(0).setExternalData(b, index);        // xnode_impl::cable_pack14_t<NV>
		this->getT(1).getT(1).getT(14).getT(0).setExternalData(b, index);        // xnode_impl::cable_pack15_t<NV>
		this->getT(1).getT(1).getT(15).getT(0).setExternalData(b, index);        // xnode_impl::cable_pack16_t<NV>
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


