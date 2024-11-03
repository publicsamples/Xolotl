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
using oscillator6_t = wrap::no_data<core::oscillator<NV>>;
template <int NV> using oscillator7_t = oscillator6_t<NV>;
template <int NV> using oscillator8_t = oscillator6_t<NV>;
DECLARE_PARAMETER_RANGE_STEP(sliderbank_c0_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using sliderbank_c0_0 = parameter::from0To1<oscillator6_t<NV>, 
                                            0, 
                                            sliderbank_c0_0Range>;

template <int NV>
using sliderbank_c0_1 = parameter::from0To1<oscillator7_t<NV>, 
                                            0, 
                                            sliderbank_c0_0Range>;

template <int NV>
using sliderbank_c0_2 = parameter::from0To1<oscillator8_t<NV>, 
                                            0, 
                                            sliderbank_c0_0Range>;

template <int NV>
using sliderbank_c0 = parameter::chain<ranges::Identity, 
                                       sliderbank_c0_0<NV>, 
                                       sliderbank_c0_1<NV>, 
                                       sliderbank_c0_2<NV>>;

template <int NV>
using converter1_t = control::converter<parameter::plain<oscillator7_t<NV>, 1>, 
                                        conversion_logic::ms2freq>;
template <int NV>
using tempo_sync4_t = wrap::mod<parameter::plain<converter1_t<NV>, 0>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(sliderbank_c1_1Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using sliderbank_c1_1 = parameter::from0To1<tempo_sync4_t<NV>, 
                                            1, 
                                            sliderbank_c1_1Range>;

template <int NV>
using sliderbank_c1 = parameter::chain<ranges::Identity, 
                                       parameter::plain<oscillator6_t<NV>, 4>, 
                                       sliderbank_c1_1<NV>, 
                                       parameter::plain<oscillator8_t<NV>, 4>>;

DECLARE_PARAMETER_RANGE(sliderbank_c2_0Range, 
                        0., 
                        0.1);

template <int NV>
using sliderbank_c2_0 = parameter::from0To1<oscillator6_t<NV>, 
                                            5, 
                                            sliderbank_c2_0Range>;

DECLARE_PARAMETER_RANGE(sliderbank_c2_1Range, 
                        0.001, 
                        1.);

template <int NV>
using sliderbank_c2_1 = parameter::from0To1<oscillator7_t<NV>, 
                                            5, 
                                            sliderbank_c2_1Range>;

template <int NV>
using sliderbank_c2 = parameter::chain<ranges::Identity, 
                                       sliderbank_c2_0<NV>, 
                                       sliderbank_c2_1<NV>, 
                                       parameter::plain<oscillator8_t<NV>, 5>>;

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(sliderbank_c3Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using sliderbank_c3 = parameter::from0To1<tempo_sync1_t<NV>, 
                                          0, 
                                          sliderbank_c3Range>;

template <int NV>
using converter_t = control::converter<parameter::plain<oscillator6_t<NV>, 2>, 
                                       conversion_logic::ms2freq>;
template <int NV>
using tempo_sync3_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                                control::tempo_sync<NV>>;
template <int NV>
using sliderbank_c4_0 = parameter::from0To1<tempo_sync1_t<NV>, 
                                            1, 
                                            sliderbank_c1_1Range>;

template <int NV>
using sliderbank_c4_1 = parameter::from0To1<tempo_sync3_t<NV>, 
                                            1, 
                                            sliderbank_c1_1Range>;

template <int NV>
using sliderbank_c4 = parameter::chain<ranges::Identity, 
                                       sliderbank_c4_0<NV>, 
                                       sliderbank_c4_1<NV>>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::add<NV>, 0>, 
                                  parameter::plain<math::add<NV>, 0>, 
                                  parameter::plain<math::add<NV>, 0>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
DECLARE_PARAMETER_RANGE(sliderbank_c5Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using sliderbank_c5 = parameter::from0To1<pma1_t<NV>, 
                                          2, 
                                          sliderbank_c5Range>;

DECLARE_PARAMETER_RANGE(sliderbank_c6Range, 
                        -1., 
                        1.);

template <int NV>
using sliderbank_c6 = parameter::from0To1<pma1_t<NV>, 
                                          1, 
                                          sliderbank_c6Range>;

using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::pi<NV>>, 
                                   math::sin<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain8_t>, 
                                    chain13_t<NV>>;
template <int NV>
using sliderbank_multimod = parameter::list<sliderbank_c0<NV>, 
                                            sliderbank_c1<NV>, 
                                            sliderbank_c2<NV>, 
                                            sliderbank_c3<NV>, 
                                            sliderbank_c4<NV>, 
                                            sliderbank_c5<NV>, 
                                            sliderbank_c6<NV>, 
                                            parameter::plain<branch1_t<NV>, 0>>;

template <int NV>
using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod<NV>>, 
                                data::external::sliderpack<5>>;

template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;
template <int NV> using oscillator4_t = oscillator6_t<NV>;
template <int NV> using oscillator3_t = oscillator6_t<NV>;
template <int NV> using oscillator1_t = oscillator6_t<NV>;
template <int NV> using oscillator2_t = oscillator6_t<NV>;
template <int NV> using oscillator_t = oscillator6_t<NV>;

DECLARE_PARAMETER_RANGE_SKEW(cable_table_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using cable_table_mod = parameter::from0To1<filters::one_pole<NV>, 
                                            0, 
                                            cable_table_modRange>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00391388f, 0.00782776f, 0.0117417f, 0.0156556f, 0.0195695f,
		0.0234834f, 0.0273973f, 0.0313112f, 0.035225f, 0.0391389f, 0.0430529f,
		0.0469667f, 0.0508806f, 0.0547945f, 0.0587084f, 0.0626223f, 0.0665362f,
		0.0704501f, 0.074364f, 0.0782779f, 0.0821918f, 0.0861057f, 0.0900196f,
		0.0939335f, 0.0978473f, 0.101761f, 0.105675f, 0.109589f, 0.113503f,
		0.117417f, 0.121331f, 0.125245f, 0.129158f, 0.133072f, 0.136986f,
		0.1409f, 0.144814f, 0.148728f, 0.152642f, 0.156556f, 0.16047f,
		0.164384f, 0.168297f, 0.172211f, 0.176125f, 0.180039f, 0.183953f,
		0.187867f, 0.191781f, 0.195695f, 0.199609f, 0.203523f, 0.207436f,
		0.21135f, 0.215264f, 0.219178f, 0.223092f, 0.227006f, 0.23092f,
		0.234834f, 0.238748f, 0.242661f, 0.246575f, 0.250489f, 0.254403f,
		0.258317f, 0.262231f, 0.266145f, 0.270059f, 0.273973f, 0.277887f,
		0.2818f, 0.285714f, 0.289628f, 0.293542f, 0.297456f, 0.30137f,
		0.305284f, 0.309198f, 0.313112f, 0.317025f, 0.320939f, 0.324853f,
		0.328767f, 0.332681f, 0.336595f, 0.340509f, 0.344423f, 0.348337f,
		0.35225f, 0.356164f, 0.360078f, 0.363992f, 0.367906f, 0.37182f,
		0.375734f, 0.379648f, 0.383562f, 0.387476f, 0.391389f, 0.395303f,
		0.399217f, 0.403131f, 0.407045f, 0.410959f, 0.414873f, 0.418787f,
		0.422701f, 0.426615f, 0.430528f, 0.434442f, 0.438356f, 0.44227f,
		0.446184f, 0.450098f, 0.454012f, 0.457926f, 0.46184f, 0.465753f,
		0.469667f, 0.473581f, 0.477495f, 0.481409f, 0.485323f, 0.489237f,
		0.493151f, 0.497065f, 0.500978f, 0.504892f, 0.508806f, 0.51272f,
		0.516634f, 0.520548f, 0.524462f, 0.528376f, 0.53229f, 0.536204f,
		0.540117f, 0.544031f, 0.547945f, 0.551859f, 0.555773f, 0.559687f,
		0.563601f, 0.567515f, 0.571429f, 0.575342f, 0.579256f, 0.58317f,
		0.587084f, 0.590998f, 0.594912f, 0.598826f, 0.60274f, 0.606654f,
		0.610568f, 0.614481f, 0.618395f, 0.622309f, 0.626223f, 0.630137f,
		0.634051f, 0.637965f, 0.641879f, 0.645793f, 0.649706f, 0.65362f,
		0.657534f, 0.661448f, 0.665362f, 0.669276f, 0.67319f, 0.677104f,
		0.681018f, 0.684932f, 0.688845f, 0.692759f, 0.696673f, 0.700587f,
		0.704501f, 0.708415f, 0.712329f, 0.716243f, 0.720157f, 0.72407f,
		0.727984f, 0.731898f, 0.735812f, 0.739726f, 0.74364f, 0.747554f,
		0.751468f, 0.755382f, 0.759296f, 0.763209f, 0.767123f, 0.771037f,
		0.774951f, 0.778865f, 0.782779f, 0.786693f, 0.790607f, 0.794521f,
		0.798434f, 0.802348f, 0.806262f, 0.810176f, 0.81409f, 0.818004f,
		0.821918f, 0.825832f, 0.829746f, 0.833659f, 0.837573f, 0.841487f,
		0.845401f, 0.849315f, 0.853229f, 0.857143f, 0.861057f, 0.864971f,
		0.868885f, 0.872798f, 0.876712f, 0.880626f, 0.88454f, 0.888454f,
		0.892368f, 0.896282f, 0.900196f, 0.90411f, 0.908023f, 0.911937f,
		0.915851f, 0.919765f, 0.923679f, 0.927593f, 0.931507f, 0.935421f,
		0.939335f, 0.943249f, 0.947162f, 0.951076f, 0.95499f, 0.958904f,
		0.962818f, 0.966732f, 0.970646f, 0.97456f, 0.978474f, 0.982388f,
		0.986301f, 0.990215f, 0.994129f, 0.998043f, 1.f, 1.f,
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
		1.f, 1.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::embedded::table<cable_table_t_data>>;

template <int NV> using cable_table1_mod = cable_table_mod<NV>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.0019266f, 0.00581014f, 0.00969368f, 0.0135772f,
		0.0174608f, 0.0213443f, 0.025228f, 0.0291115f, 0.032995f, 0.0368786f,
		0.0407621f, 0.0446457f, 0.0485292f, 0.0524127f, 0.0562964f, 0.0601799f,
		0.0640635f, 0.067947f, 0.0718306f, 0.0757141f, 0.0795977f, 0.0834812f,
		0.0873649f, 0.0912484f, 0.0951319f, 0.0990155f, 0.102899f, 0.106783f,
		0.110666f, 0.11455f, 0.118433f, 0.122317f, 0.1262f, 0.130084f,
		0.133967f, 0.137851f, 0.141735f, 0.145618f, 0.149502f, 0.153385f,
		0.157269f, 0.161152f, 0.165036f, 0.168919f, 0.172803f, 0.176686f,
		0.18057f, 0.184454f, 0.188337f, 0.192221f, 0.196104f, 0.199988f,
		0.203871f, 0.207755f, 0.211639f, 0.215522f, 0.219406f, 0.223289f,
		0.227173f, 0.231056f, 0.23494f, 0.238823f, 0.242707f, 0.246591f,
		0.250474f, 0.254358f, 0.258241f, 0.262125f, 0.266008f, 0.269892f,
		0.273775f, 0.277659f, 0.281543f, 0.285426f, 0.28931f, 0.293193f,
		0.297077f, 0.30096f, 0.304844f, 0.308727f, 0.312611f, 0.316494f,
		0.320378f, 0.324262f, 0.328145f, 0.332029f, 0.335912f, 0.339796f,
		0.343679f, 0.347563f, 0.351447f, 0.35533f, 0.359214f, 0.363097f,
		0.366981f, 0.370864f, 0.374748f, 0.378631f, 0.382515f, 0.386398f,
		0.390282f, 0.394166f, 0.398049f, 0.401933f, 0.405816f, 0.4097f,
		0.413583f, 0.417467f, 0.42135f, 0.425234f, 0.429118f, 0.433001f,
		0.436885f, 0.440768f, 0.444652f, 0.448535f, 0.452419f, 0.456302f,
		0.460186f, 0.46407f, 0.467953f, 0.471837f, 0.47572f, 0.479604f,
		0.483487f, 0.487371f, 0.491254f, 0.495138f, 0.499022f, 0.502905f,
		0.506789f, 0.510672f, 0.514556f, 0.518439f, 0.522323f, 0.526206f,
		0.53009f, 0.533974f, 0.537857f, 0.541741f, 0.545624f, 0.549508f,
		0.553391f, 0.557275f, 0.561158f, 0.565042f, 0.568925f, 0.572809f,
		0.576693f, 0.580576f, 0.58446f, 0.588343f, 0.592227f, 0.59611f,
		0.599994f, 0.603877f, 0.607761f, 0.611645f, 0.615528f, 0.619412f,
		0.623295f, 0.627179f, 0.631062f, 0.634946f, 0.638829f, 0.642713f,
		0.646597f, 0.65048f, 0.654364f, 0.658247f, 0.662131f, 0.666014f,
		0.669898f, 0.673781f, 0.677665f, 0.681549f, 0.685432f, 0.689316f,
		0.693199f, 0.697083f, 0.700966f, 0.70485f, 0.708733f, 0.712617f,
		0.716501f, 0.720384f, 0.724268f, 0.728151f, 0.732035f, 0.735918f,
		0.739802f, 0.743685f, 0.747569f, 0.751453f, 0.755336f, 0.75922f,
		0.763103f, 0.766987f, 0.77087f, 0.774754f, 0.778637f, 0.782521f,
		0.786404f, 0.790288f, 0.794172f, 0.798055f, 0.801939f, 0.805822f,
		0.809706f, 0.813589f, 0.817473f, 0.821356f, 0.82524f, 0.829124f,
		0.833007f, 0.836891f, 0.840774f, 0.844658f, 0.848541f, 0.852425f,
		0.856308f, 0.860192f, 0.864076f, 0.867959f, 0.871843f, 0.875726f,
		0.87961f, 0.883493f, 0.887377f, 0.89126f, 0.895144f, 0.899028f,
		0.902911f, 0.906795f, 0.910678f, 0.914562f, 0.918445f, 0.922329f,
		0.926212f, 0.930096f, 0.93398f, 0.937863f, 0.941747f, 0.94563f,
		0.949514f, 0.953397f, 0.957281f, 0.961165f, 0.965048f, 0.968932f,
		0.972815f, 0.976699f, 0.980582f, 0.984466f, 0.988349f, 0.992233f,
		0.996117f, 1.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod<NV>>, 
                                  data::embedded::table<cable_table1_t_data>>;

template <int NV>
using pma2_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table_t<NV>, 0>, 
                                  parameter::plain<cable_table1_t<NV>, 0>>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, pma2_t<NV>>, 
                                      cable_table_t<NV>, 
                                      cable_table1_t<NV>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

template <int NV>
using input_toggle5_t = control::input_toggle<parameter::plain<oscillator4_t<NV>, 3>>;

namespace chain14_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(NoiseFilter_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using NoiseFilter_0 = parameter::from0To1<xnode_impl::pma2_t<NV>, 
                                          2, 
                                          xnode_impl::sliderbank_c5Range>;

template <int NV>
using NoiseFilter = parameter::chain<NoiseFilter_InputRange, NoiseFilter_0<NV>>;

}

template <int NV>
using chain14_t = container::chain<chain14_t_parameters::NoiseFilter<NV>, 
                                   wrap::fix<2, modchain4_t<NV>>, 
                                   input_toggle5_t<NV>, 
                                   oscillator4_t<NV>, 
                                   filters::one_pole<NV>, 
                                   filters::one_pole<NV>>;

template <int NV>
using pma_unscaled1_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player_t<NV>, 3>, 
                                           parameter::plain<oscillator4_t<NV>, 2>, 
                                           parameter::plain<oscillator3_t<NV>, 2>, 
                                           parameter::plain<oscillator1_t<NV>, 2>, 
                                           parameter::plain<oscillator2_t<NV>, 2>, 
                                           parameter::plain<oscillator_t<NV>, 2>, 
                                           parameter::plain<tempo_sync3_t<NV>, 0>, 
                                           parameter::plain<tempo_sync4_t<NV>, 0>, 
                                           parameter::plain<oscillator7_t<NV>, 2>, 
                                           parameter::plain<oscillator8_t<NV>, 2>, 
                                           parameter::plain<chain14_t<NV>, 0>>;

template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, pma_unscaled1_mod<NV>>;
template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, 
                                             parameter::plain<pma_unscaled1_t<NV>, 2>>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled_t<NV>, 2>>;
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
using input_toggle6_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player_t<NV>, 1>, 
                                           parameter::plain<core::gain<NV>, 0>>;

template <int NV>
using input_toggle6_t = control::input_toggle<input_toggle6_mod<NV>>;

template <int NV>
using input_toggle7_t = control::input_toggle<parameter::plain<oscillator6_t<NV>, 3>>;

template <int NV>
using input_toggle8_t = control::input_toggle<parameter::plain<oscillator7_t<NV>, 3>>;

template <int NV>
using input_toggle4_t = control::input_toggle<parameter::plain<oscillator8_t<NV>, 3>>;
template <int NV> using oscillator5_t = oscillator6_t<NV>;

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
                                        parameter::plain<oscillator5_t<NV>, 5>>;

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
using ahdsr_multimod = parameter::list<parameter::empty, ahdsr_c1<NV>>;

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

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank_t<NV>>, 
                                      minmax_t<NV>, 
                                      pma_unscaled_t<NV>, 
                                      pma_unscaled1_t<NV>, 
                                      pack_resizer_t, 
                                      sliderbank1_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using no_midi1_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, ahdsr_t<NV>>>;

template <int NV>
using no_midi1_t = wrap::no_midi<no_midi1_t_<NV>>;

template <int NV>
using modchain5_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, no_midi1_t<NV>>>;

template <int NV>
using modchain5_t = wrap::control_rate<modchain5_t_<NV>>;

template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, tempo_sync1_t<NV>>, 
                                      ramp_t<NV>, 
                                      branch1_t<NV>, 
                                      peak1_t<NV>, 
                                      pma1_t<NV>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle2_t<NV>>, 
                                   oscillator_t<NV>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle3_t<NV>>, 
                                   oscillator2_t<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle9_t<NV>>, 
                                   oscillator1_t<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle1_t<NV>>, 
                                   oscillator3_t<NV>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle6_t<NV>>, 
                                   file_player_t<NV>>;
template <int NV>
using file_player1_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, input_toggle7_t<NV>>, 
                                       tempo_sync3_t<NV>, 
                                       converter_t<NV>, 
                                       oscillator6_t<NV>, 
                                       math::add<NV>, 
                                       file_player1_t<NV>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fix8_block_t<NV>>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<2, oscillator7_t<NV>>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;
template <int NV> using file_player2_t = file_player1_t<NV>;

template <int NV>
using fix8_block4_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, input_toggle8_t<NV>>, 
                                        tempo_sync4_t<NV>, 
                                        converter1_t<NV>, 
                                        no_midi_t<NV>, 
                                        math::add<NV>, 
                                        file_player2_t<NV>>;

template <int NV>
using fix8_block4_t = wrap::fix_block<8, fix8_block4_t_<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fix8_block4_t<NV>>>;
template <int NV> using file_player3_t = file_player1_t<NV>;

template <int NV>
using fix8_block5_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, input_toggle4_t<NV>>, 
                                        oscillator8_t<NV>, 
                                        math::add<NV>, 
                                        file_player3_t<NV>>;

template <int NV>
using fix8_block5_t = wrap::fix_block<8, fix8_block5_t_<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fix8_block5_t<NV>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain21_t<NV>>, 
                                   chain25_t<NV>, 
                                   chain24_t<NV>, 
                                   chain23_t<NV>, 
                                   chain14_t<NV>, 
                                   chain26_t<NV>, 
                                   chain16_t<NV>, 
                                   chain19_t<NV>, 
                                   chain20_t<NV>>;

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
using converter2_t = control::converter<parameter::plain<oscillator5_t<NV>, 1>, 
                                        conversion_logic::ms2freq>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>, 
                                        parameter::plain<converter2_t<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, tempo_sync_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using no_midi2_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, oscillator5_t<NV>>>;

template <int NV>
using no_midi2_t = wrap::no_midi<no_midi2_t_<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, wrap::no_process<math::clear<NV>>>, 
                                  converter2_t<NV>, 
                                  no_midi2_t<NV>, 
                                  fx::sampleandhold<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma_mod_0Range, 
                             0., 
                             100., 
                             0.01);

template <int NV>
using pma_mod_0 = parameter::from0To1<project::Comb<NV>, 
                                      1, 
                                      pma_mod_0Range>;

template <int NV>
using pma_mod_1 = parameter::from0To1<filters::svf<NV>, 
                                      0, 
                                      cable_table_modRange>;

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

using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

template <int NV>
using peak2_t = wrap::mod<parameter::plain<ahdsr_t<NV>, 8>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::rect<NV>>, 
                                   peak2_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain17_t>, 
                                  chain18_t<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  chain7_t<NV>, 
                                  peak_t<NV>, 
                                  split4_t<NV>, 
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
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, filters::svf<NV>>, 
                                    filters::svf<NV>, 
                                    filters::svf<NV>, 
                                    project::Comb<NV>>;

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
                                 modchain5_t<NV>, 
                                 modchain3_t<NV>, 
                                 branch_t<NV>, 
                                 chain1_t<NV>, 
                                 chain4_t<NV>, 
                                 core::gain<NV>, 
                                 core::gain<NV>>;

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

template <int NV>
using Harm_1 = parameter::from0To1<xnode_impl::oscillator5_t<NV>, 
                                   2, 
                                   xnode_impl::sliderbank_c1_1Range>;

template <int NV>
using Harm = parameter::chain<ranges::Identity, 
                              parameter::plain<xnode_impl::minmax_t<NV>, 0>, 
                              Harm_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Mode_InputRange, 
                             0., 
                             8., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Mode_0Range, 
                             0., 
                             8., 
                             1.);

template <int NV>
using Mode_0 = parameter::from0To1<xnode_impl::branch_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_1 = parameter::from0To1<xnode_impl::oscillator5_t<NV>, 
                                   0, 
                                   xnode_impl::sliderbank_c0_0Range>;

template <int NV>
using Mode = parameter::chain<Mode_InputRange, 
                              Mode_0<NV>, 
                              Mode_1<NV>>;

template <int NV>
using FxValue_0 = parameter::from0To1<xnode_impl::tempo_sync_t<NV>, 
                                      0, 
                                      xnode_impl::sliderbank_c3Range>;

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

DECLARE_PARAMETER_RANGE_SKEW(FilterRes_InputRange, 
                             0.3, 
                             9.9, 
                             0.264718);
DECLARE_PARAMETER_RANGE_STEP(FilterRes_0Range, 
                             0., 
                             1, 
                             0.01);

template <int NV>
using FilterRes_0 = parameter::from0To1<project::Comb<NV>, 
                                        0, 
                                        FilterRes_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(FilterRes_1Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using FilterRes_1 = parameter::from0To1<filters::svf<NV>, 
                                        1, 
                                        FilterRes_1Range>;

template <int NV> using FilterRes_2 = FilterRes_1<NV>;

template <int NV> using FilterRes_3 = FilterRes_1<NV>;

template <int NV>
using FilterRes = parameter::chain<FilterRes_InputRange, 
                                   FilterRes_0<NV>, 
                                   FilterRes_1<NV>, 
                                   FilterRes_2<NV>, 
                                   FilterRes_3<NV>>;

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
                                  wrap::fix<2, fix8_block1_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public xnode_impl::xnode_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 8;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(xnode);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(260)
		{
			0x005B, 0x0000, 0x4800, 0x7261, 0x006D, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x015B, 
            0x0000, 0x6D00, 0x6E69, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0002, 0x0000, 
            0x616D, 0x0078, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x4170, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 0x0000, 0x7300, 0x6574, 
            0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 0xD70A, 0x3C86, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 0x4D00, 0x646F, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x4100, 0x0000, 0x4080, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x055B, 0x0000, 0x4600, 0x4D78, 0x7869, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0006, 0x0000, 0x7846, 0x6156, 0x756C, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0xC859, 0x3E24, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x075B, 0x0000, 0x4600, 0x5378, 0x4468, 0x7669, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0008, 0x0000, 0x7846, 0x6853, 0x7953, 
            0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0009, 0x0000, 0x6873, 0x6950, 
            0x6374, 0x0068, 0x0000, 0xBF80, 0x0000, 0x3F80, 0xE560, 0xBB6E, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x4D72, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000B, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x7954, 0x6570, 0x0000, 0x0000, 0x0000, 
            0x4000, 0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x000C, 0x0000, 0x6946, 0x746C, 0x7265, 0x6552, 0x0073, 0x999A, 
            0x3E99, 0x6666, 0x411E, 0x6666, 0x411E, 0x8918, 0x3E87, 0x0000, 
            0x0000, 0x0D5B, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4372, 0x7475, 
            0x0000, 0x8000, 0x0024, 0x8000, 0x9E3F, 0xAF45, 0x003E, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000E, 0x0000, 0x6946, 0x746C, 0x7265, 
            0x7846, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0F5B, 0x0000, 0x4400, 
            0x5445, 0x0000, 0x0000, 0x0000, 0x0000, 0xCD40, 0x20CC, 0x003D, 
            0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block1 = this->getT(0);                                                   // xnode_impl::fix8_block1_t<NV>
		auto& frame2_block = this->getT(0).getT(0);                                          // xnode_impl::frame2_block_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0);                                         // xnode_impl::chain_t<NV>
		auto& modchain1 = this->getT(0).getT(0).getT(0).getT(0);                             // xnode_impl::modchain1_t<NV>
		auto& sliderbank = this->getT(0).getT(0).getT(0).getT(0).getT(0);                    // xnode_impl::sliderbank_t<NV>
		auto& minmax = this->getT(0).getT(0).getT(0).getT(0).getT(1);                        // xnode_impl::minmax_t<NV>
		auto& pma_unscaled = this->getT(0).getT(0).getT(0).getT(0).getT(2);                  // xnode_impl::pma_unscaled_t<NV>
		auto& pma_unscaled1 = this->getT(0).getT(0).getT(0).getT(0).getT(3);                 // xnode_impl::pma_unscaled1_t<NV>
		auto& pack_resizer = this->getT(0).getT(0).getT(0).getT(0).getT(4);                  // xnode_impl::pack_resizer_t
		auto& sliderbank1 = this->getT(0).getT(0).getT(0).getT(0).getT(5);                   // xnode_impl::sliderbank1_t<NV>
		auto& modchain5 = this->getT(0).getT(0).getT(0).getT(1);                             // xnode_impl::modchain5_t<NV>
		auto& no_midi1 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                      // xnode_impl::no_midi1_t<NV>
		auto& ahdsr = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);                 // xnode_impl::ahdsr_t<NV>
		auto& modchain3 = this->getT(0).getT(0).getT(0).getT(2);                             // xnode_impl::modchain3_t<NV>
		auto& tempo_sync1 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                   // xnode_impl::tempo_sync1_t<NV>
		auto& ramp = this->getT(0).getT(0).getT(0).getT(2).getT(1);                          // xnode_impl::ramp_t<NV>
		auto& branch1 = this->getT(0).getT(0).getT(0).getT(2).getT(2);                       // xnode_impl::branch1_t<NV>
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(2).getT(2).getT(0);                // xnode_impl::chain8_t
		auto& chain13 = this->getT(0).getT(0).getT(0).getT(2).getT(2).getT(1);               // xnode_impl::chain13_t<NV>
		auto& pi = this->getT(0).getT(0).getT(0).getT(2).getT(2).getT(1).getT(0);            // math::pi<NV>
		auto& sin = this->getT(0).getT(0).getT(0).getT(2).getT(2).getT(1).getT(1);           // math::sin<NV>
		auto& peak1 = this->getT(0).getT(0).getT(0).getT(2).getT(3);                         // xnode_impl::peak1_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(0).getT(2).getT(4);                          // xnode_impl::pma1_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0).getT(3);                                // xnode_impl::branch_t<NV>
		auto& chain21 = this->getT(0).getT(0).getT(0).getT(3).getT(0);                       // xnode_impl::chain21_t<NV>
		auto& input_toggle2 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0);         // xnode_impl::input_toggle2_t<NV>
		auto& oscillator = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1);            // xnode_impl::oscillator_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(0).getT(3).getT(1);                       // xnode_impl::chain25_t<NV>
		auto& input_toggle3 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0);         // xnode_impl::input_toggle3_t<NV>
		auto& oscillator2 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1);           // xnode_impl::oscillator2_t<NV>
		auto& chain24 = this->getT(0).getT(0).getT(0).getT(3).getT(2);                       // xnode_impl::chain24_t<NV>
		auto& input_toggle9 = this->getT(0).getT(0).getT(0).getT(3).getT(2).getT(0);         // xnode_impl::input_toggle9_t<NV>
		auto& oscillator1 = this->getT(0).getT(0).getT(0).getT(3).getT(2).getT(1);           // xnode_impl::oscillator1_t<NV>
		auto& chain23 = this->getT(0).getT(0).getT(0).getT(3).getT(3);                       // xnode_impl::chain23_t<NV>
		auto& input_toggle1 = this->getT(0).getT(0).getT(0).getT(3).getT(3).getT(0);         // xnode_impl::input_toggle1_t<NV>
		auto& oscillator3 = this->getT(0).getT(0).getT(0).getT(3).getT(3).getT(1);           // xnode_impl::oscillator3_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(3).getT(4);                       // xnode_impl::chain14_t<NV>
		auto& modchain4 = this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(0);             // xnode_impl::modchain4_t<NV>
		auto& pma2 = this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(0).getT(0);          // xnode_impl::pma2_t<NV>
		auto& cable_table = this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(0).getT(1);   // xnode_impl::cable_table_t<NV>
		auto& cable_table1 = this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(0).getT(2);  // xnode_impl::cable_table1_t<NV>
		auto& input_toggle5 = this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(1);         // xnode_impl::input_toggle5_t<NV>
		auto& oscillator4 = this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(2);           // xnode_impl::oscillator4_t<NV>
		auto& one_pole = this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(3);              // filters::one_pole<NV>
		auto& one_pole1 = this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(4);             // filters::one_pole<NV>
		auto& chain26 = this->getT(0).getT(0).getT(0).getT(3).getT(5);                       // xnode_impl::chain26_t<NV>
		auto& input_toggle6 = this->getT(0).getT(0).getT(0).getT(3).getT(5).getT(0);         // xnode_impl::input_toggle6_t<NV>
		auto& file_player = this->getT(0).getT(0).getT(0).getT(3).getT(5).getT(1);           // xnode_impl::file_player_t<NV>
		auto& chain16 = this->getT(0).getT(0).getT(0).getT(3).getT(6);                       // xnode_impl::chain16_t<NV>
		auto& fix8_block = this->getT(0).getT(0).getT(0).getT(3).getT(6).getT(0);            // xnode_impl::fix8_block_t<NV>
		auto& input_toggle7 = this->getT(0).getT(0).getT(0).getT(3).getT(6).getT(0).getT(0); // xnode_impl::input_toggle7_t<NV>
		auto& tempo_sync3 = this->getT(0).getT(0).getT(0).getT(3).getT(6).getT(0).getT(1);   // xnode_impl::tempo_sync3_t<NV>
		auto& converter = this->getT(0).getT(0).getT(0).getT(3).getT(6).getT(0).getT(2);     // xnode_impl::converter_t<NV>
		auto& oscillator6 = this->getT(0).getT(0).getT(0).getT(3).getT(6).getT(0).getT(3);   // xnode_impl::oscillator6_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(3).getT(6).getT(0).getT(4);           // math::add<NV>
		auto& file_player1 = this->getT(0).getT(0).getT(0).getT(3).getT(6).getT(0).getT(5);  // xnode_impl::file_player1_t<NV>
		auto& chain19 = this->getT(0).getT(0).getT(0).getT(3).getT(7);                       // xnode_impl::chain19_t<NV>
		auto& fix8_block4 = this->getT(0).getT(0).getT(0).getT(3).getT(7).getT(0);           // xnode_impl::fix8_block4_t<NV>
		auto& input_toggle8 = this->getT(0).getT(0).getT(0).getT(3).getT(7).getT(0).getT(0); // xnode_impl::input_toggle8_t<NV>
		auto& tempo_sync4 = this->getT(0).getT(0).getT(0).getT(3).getT(7).getT(0).getT(1);   // xnode_impl::tempo_sync4_t<NV>
		auto& converter1 = this->getT(0).getT(0).getT(0).getT(3).getT(7).getT(0).getT(2);    // xnode_impl::converter1_t<NV>
		auto& no_midi = this->getT(0).getT(0).getT(0).getT(3).getT(7).getT(0).getT(3);       // xnode_impl::no_midi_t<NV>
		auto& oscillator7 = this->getT(0).getT(0).getT(0).getT(3).                           // xnode_impl::oscillator7_t<NV>
                            getT(7).getT(0).getT(3).getT(0);
		auto& add1 = this->getT(0).getT(0).getT(0).getT(3).getT(7).getT(0).getT(4);          // math::add<NV>
		auto& file_player2 = this->getT(0).getT(0).getT(0).getT(3).getT(7).getT(0).getT(5);  // xnode_impl::file_player2_t<NV>
		auto& chain20 = this->getT(0).getT(0).getT(0).getT(3).getT(8);                       // xnode_impl::chain20_t<NV>
		auto& fix8_block5 = this->getT(0).getT(0).getT(0).getT(3).getT(8).getT(0);           // xnode_impl::fix8_block5_t<NV>
		auto& input_toggle4 = this->getT(0).getT(0).getT(0).getT(3).getT(8).getT(0).getT(0); // xnode_impl::input_toggle4_t<NV>
		auto& oscillator8 = this->getT(0).getT(0).getT(0).getT(3).getT(8).getT(0).getT(1);   // xnode_impl::oscillator8_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(3).getT(8).getT(0).getT(2);          // math::add<NV>
		auto& file_player3 = this->getT(0).getT(0).getT(0).getT(3).getT(8).getT(0).getT(3);  // xnode_impl::file_player3_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(4);                                // xnode_impl::chain1_t<NV>
		auto& xfader = this->getT(0).getT(0).getT(0).getT(4).getT(0);                        // xnode_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(0).getT(0).getT(4).getT(1);                         // xnode_impl::split_t<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(4).getT(1).getT(0);                // xnode_impl::chain2_t<NV>
		auto& gain = this->getT(0).getT(0).getT(0).getT(4).getT(1).getT(0).getT(0);          // core::gain<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(4).getT(1).getT(1);                // xnode_impl::chain3_t<NV>
		auto& modchain = this->getT(0).getT(0).getT(0).getT(4).getT(1).getT(1).getT(0);      // xnode_impl::modchain_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(0).getT(4).                            // xnode_impl::tempo_sync_t<NV>
                           getT(1).getT(1).getT(0).getT(0);
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(4).getT(1).getT(1).getT(1);    // xnode_impl::chain7_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(0).getT(4).                            // wrap::no_process<math::clear<NV>>
                       getT(1).getT(1).getT(1).getT(0);
		auto& converter2 = this->getT(0).getT(0).getT(0).getT(4).                        // xnode_impl::converter2_t<NV>
                           getT(1).getT(1).getT(1).getT(1);
		auto& no_midi2 = this->getT(0).getT(0).getT(0).getT(4).                          // xnode_impl::no_midi2_t<NV>
                         getT(1).getT(1).getT(1).getT(2);
		auto& oscillator5 = this->getT(0).getT(0).getT(0).getT(4).                       // xnode_impl::oscillator5_t<NV>
                            getT(1).getT(1).getT(1).getT(2).
                            getT(0);
		auto& sampleandhold = this->getT(0).getT(0).getT(0).getT(4).                     // fx::sampleandhold<NV>
                              getT(1).getT(1).getT(1).getT(3);
		auto& peak = this->getT(0).getT(0).getT(0).getT(4).getT(1).getT(1).getT(2);      // xnode_impl::peak_t<NV>
		auto& split4 = this->getT(0).getT(0).getT(0).getT(4).getT(1).getT(1).getT(3);    // xnode_impl::split4_t<NV>
		auto& chain17 = this->getT(0).getT(0).getT(0).getT(4).                           // xnode_impl::chain17_t
                        getT(1).getT(1).getT(3).getT(0);
		auto& chain18 = this->getT(0).getT(0).getT(0).getT(4).                           // xnode_impl::chain18_t<NV>
                        getT(1).getT(1).getT(3).getT(1);
		auto& rect = this->getT(0).getT(0).getT(0).getT(4).                              // math::rect<NV>
                     getT(1).getT(1).getT(3).getT(1).
                     getT(0);
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(4).                             // xnode_impl::peak2_t<NV>
                      getT(1).getT(1).getT(3).getT(1).
                      getT(1);
		auto& clear2 = this->getT(0).getT(0).getT(0).getT(4).                            // math::clear<NV>
                       getT(1).getT(1).getT(3).getT(1).
                       getT(2);
		auto& gain1 = this->getT(0).getT(0).getT(0).getT(4).getT(1).getT(1).getT(4);     // core::gain<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(5);                            // xnode_impl::chain4_t<NV>
		auto& xfader1 = this->getT(0).getT(0).getT(0).getT(5).getT(0);                   // xnode_impl::xfader1_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(0).getT(5).getT(1);                    // xnode_impl::split1_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(5).getT(1).getT(0);            // xnode_impl::chain5_t<NV>
		auto& gain2 = this->getT(0).getT(0).getT(0).getT(5).getT(1).getT(0).getT(0);     // core::gain<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(5).getT(1).getT(1);            // xnode_impl::chain6_t<NV>
		auto& modchain2 = this->getT(0).getT(0).getT(0).getT(5).getT(1).getT(1).getT(0); // xnode_impl::modchain2_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0).getT(5).                               // xnode_impl::pma_t<NV>
                    getT(1).getT(1).getT(0).getT(0);
		auto& branch2 = this->getT(0).getT(0).getT(0).getT(5).getT(1).getT(1).getT(1); // xnode_impl::branch2_t<NV>
		auto& svf = this->getT(0).getT(0).getT(0).getT(5).                             // filters::svf<NV>
                    getT(1).getT(1).getT(1).getT(0);
		auto& svf2 = this->getT(0).getT(0).getT(0).getT(5).                          // filters::svf<NV>
                     getT(1).getT(1).getT(1).getT(1);
		auto& svf1 = this->getT(0).getT(0).getT(0).getT(5).                          // filters::svf<NV>
                     getT(1).getT(1).getT(1).getT(2);
		auto& faust3 = this->getT(0).getT(0).getT(0).getT(5).                        // project::Comb<NV>
                       getT(1).getT(1).getT(1).getT(3);
		auto& gain3 = this->getT(0).getT(0).getT(0).getT(5).getT(1).getT(1).getT(2); // core::gain<NV>
		auto& gain4 = this->getT(0).getT(0).getT(0).getT(6);                         // core::gain<NV>
		auto& gain5 = this->getT(0).getT(0).getT(0).getT(7);                         // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain14.getParameterT(0).connectT(0, pma2); // NoiseFilter -> pma2::Add
		chain14.getParameterT(0).connectT(0, pma2); // NoiseFilter -> pma2::Add
		auto& Harm_p = this->getParameterT(0);
		Harm_p.connectT(0, minmax);      // Harm -> minmax::Value
		Harm_p.connectT(1, oscillator5); // Harm -> oscillator5::FreqRatio
		
		this->getParameterT(1).connectT(0, minmax); // min -> minmax::Minimum
		
		this->getParameterT(2).connectT(0, minmax); // max -> minmax::Maximum
		
		this->getParameterT(3).connectT(0, minmax); // step -> minmax::Step
		
		auto& Mode_p = this->getParameterT(4);
		Mode_p.connectT(0, branch);      // Mode -> branch::Index
		Mode_p.connectT(1, oscillator5); // Mode -> oscillator5::Mode
		
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
		FilterRes_p.connectT(0, faust3); // FilterRes -> faust3::aN
		FilterRes_p.connectT(1, svf);    // FilterRes -> svf::Q
		FilterRes_p.connectT(2, svf2);   // FilterRes -> svf2::Q
		FilterRes_p.connectT(3, svf1);   // FilterRes -> svf1::Q
		
		this->getParameterT(13).connectT(0, pma); // FilterCut -> pma::Add
		
		this->getParameterT(14).connectT(0, pma); // FilterFxMod -> pma::Multiply
		
		this->getParameterT(15).connectT(0, pma_unscaled); // DET -> pma_unscaled::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		converter1.getWrappedObject().getParameter().connectT(0, oscillator7); // converter1 -> oscillator7::Frequency
		tempo_sync4.getParameter().connectT(0, converter1);                    // tempo_sync4 -> converter1::Value
		tempo_sync1.getParameter().connectT(0, ramp);                          // tempo_sync1 -> ramp::PeriodTime
		converter.getWrappedObject().getParameter().connectT(0, oscillator6);  // converter -> oscillator6::FreqRatio
		tempo_sync3.getParameter().connectT(0, converter);                     // tempo_sync3 -> converter::Value
		pma1.getWrappedObject().getParameter().connectT(0, add);               // pma1 -> add::Value
		pma1.getWrappedObject().getParameter().connectT(1, add1);              // pma1 -> add1::Value
		pma1.getWrappedObject().getParameter().connectT(2, add2);              // pma1 -> add2::Value
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, oscillator6);                    // sliderbank -> oscillator6::Mode
		sliderbank_p.getParameterT(0).connectT(1, oscillator7);                    // sliderbank -> oscillator7::Mode
		sliderbank_p.getParameterT(0).connectT(2, oscillator8);                    // sliderbank -> oscillator8::Mode
		sliderbank_p.getParameterT(1).connectT(0, oscillator6);                    // sliderbank -> oscillator6::Phase
		sliderbank_p.getParameterT(1).connectT(1, tempo_sync4);                    // sliderbank -> tempo_sync4::Multiplier
		sliderbank_p.getParameterT(1).connectT(2, oscillator8);                    // sliderbank -> oscillator8::Phase
		sliderbank_p.getParameterT(2).connectT(0, oscillator6);                    // sliderbank -> oscillator6::Gain
		sliderbank_p.getParameterT(2).connectT(1, oscillator7);                    // sliderbank -> oscillator7::Gain
		sliderbank_p.getParameterT(2).connectT(2, oscillator8);                    // sliderbank -> oscillator8::Gain
		sliderbank_p.getParameterT(3).connectT(0, tempo_sync1);                    // sliderbank -> tempo_sync1::Tempo
		sliderbank_p.getParameterT(4).connectT(0, tempo_sync1);                    // sliderbank -> tempo_sync1::Multiplier
		sliderbank_p.getParameterT(4).connectT(1, tempo_sync3);                    // sliderbank -> tempo_sync3::Multiplier
		sliderbank_p.getParameterT(5).connectT(0, pma1);                           // sliderbank -> pma1::Add
		sliderbank_p.getParameterT(6).connectT(0, pma1);                           // sliderbank -> pma1::Multiply
		sliderbank_p.getParameterT(7).connectT(0, branch1);                        // sliderbank -> branch1::Index
		cable_table.getWrappedObject().getParameter().connectT(0, one_pole);       // cable_table -> one_pole::Frequency
		cable_table1.getWrappedObject().getParameter().connectT(0, one_pole1);     // cable_table1 -> one_pole1::Frequency
		pma2.getWrappedObject().getParameter().connectT(0, cable_table);           // pma2 -> cable_table::Value
		pma2.getWrappedObject().getParameter().connectT(1, cable_table1);          // pma2 -> cable_table1::Value
		input_toggle5.getWrappedObject().getParameter().connectT(0, oscillator4);  // input_toggle5 -> oscillator4::Gate
		pma_unscaled1.getWrappedObject().getParameter().connectT(0, file_player);  // pma_unscaled1 -> file_player::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(1, oscillator4);  // pma_unscaled1 -> oscillator4::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(2, oscillator3);  // pma_unscaled1 -> oscillator3::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(3, oscillator1);  // pma_unscaled1 -> oscillator1::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(4, oscillator2);  // pma_unscaled1 -> oscillator2::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(5, oscillator);   // pma_unscaled1 -> oscillator::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(6, tempo_sync3);  // pma_unscaled1 -> tempo_sync3::Tempo
		pma_unscaled1.getWrappedObject().getParameter().connectT(7, tempo_sync4);  // pma_unscaled1 -> tempo_sync4::Tempo
		pma_unscaled1.getWrappedObject().getParameter().connectT(8, oscillator7);  // pma_unscaled1 -> oscillator7::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(9, oscillator8);  // pma_unscaled1 -> oscillator8::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(10, chain14);     // pma_unscaled1 -> chain14::NoiseFilter
		pma_unscaled.getWrappedObject().getParameter().connectT(0, pma_unscaled1); // pma_unscaled -> pma_unscaled1::Add
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled);        // minmax -> pma_unscaled::Add
		input_toggle2.getWrappedObject().getParameter().connectT(0, oscillator);   // input_toggle2 -> oscillator::Gate
		input_toggle3.getWrappedObject().getParameter().connectT(0, oscillator2);  // input_toggle3 -> oscillator2::Gate
		input_toggle9.getWrappedObject().getParameter().connectT(0, oscillator1);  // input_toggle9 -> oscillator1::Gate
		input_toggle1.getWrappedObject().getParameter().connectT(0, oscillator3);  // input_toggle1 -> oscillator3::Phase
		input_toggle6.getWrappedObject().getParameter().connectT(0, file_player);  // input_toggle6 -> file_player::Gate
		input_toggle6.getWrappedObject().getParameter().connectT(1, gain4);        // input_toggle6 -> gain4::Gain
		input_toggle7.getWrappedObject().getParameter().connectT(0, oscillator6);  // input_toggle7 -> oscillator6::Gate
		input_toggle8.getWrappedObject().getParameter().connectT(0, oscillator7);  // input_toggle8 -> oscillator7::Gate
		input_toggle4.getWrappedObject().getParameter().connectT(0, oscillator8);  // input_toggle4 -> oscillator8::Gate
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
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
		sliderbank1_p.getParameterT(1).connectT(0, ahdsr);         // sliderbank1 -> ahdsr::Attack
		sliderbank1_p.getParameterT(2).connectT(0, ahdsr);         // sliderbank1 -> ahdsr::Decay
		sliderbank1_p.getParameterT(3).connectT(0, ahdsr);         // sliderbank1 -> ahdsr::Release
		peak1.getParameter().connectT(0, pma1);                    // peak1 -> pma1::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                           // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);                          // xfader -> gain1::Gain
		converter2.getWrappedObject().getParameter().connectT(0, oscillator5); // converter2 -> oscillator5::Frequency
		tempo_sync.getParameter().connectT(0, sampleandhold);                  // tempo_sync -> sampleandhold::Counter
		tempo_sync.getParameter().connectT(1, converter2);                     // tempo_sync -> converter2::Value
		pma.getWrappedObject().getParameter().connectT(0, faust3);             // pma -> faust3::del
		pma.getWrappedObject().getParameter().connectT(1, svf);                // pma -> svf::Frequency
		pma.getWrappedObject().getParameter().connectT(2, svf2);               // pma -> svf2::Frequency
		pma.getWrappedObject().getParameter().connectT(3, svf1);               // pma -> svf1::Frequency
		peak.getParameter().connectT(0, pma);                                  // peak -> pma::Value
		peak.getParameter().connectT(1, pma_unscaled1);                        // peak -> pma_unscaled1::Value
		peak2.getParameter().connectT(0, ahdsr);                               // peak2 -> ahdsr::Gate
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain2); // xfader1 -> gain2::Gain
		xfader1_p.getParameterT(1).connectT(0, gain3); // xfader1 -> gain3::Gain
		
		// Default Values --------------------------------------------------------------------------
		
		sliderbank.setParameterT(0, 1.); // control::sliderbank::Value
		
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
		
		pack_resizer.setParameterT(0, 4.); // control::pack_resizer::NumSliders
		
		sliderbank1.setParameterT(0, 1.); // control::sliderbank::Value
		
		;                            // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 0.);  // envelope::ahdsr::Hold
		;                            // ahdsr::Decay is automated
		ahdsr.setParameterT(4, 0.);  // envelope::ahdsr::Sustain
		;                            // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		;                            // ahdsr::Gate is automated
		
		;                                   // tempo_sync1::Tempo is automated
		;                                   // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch1::Index is automated
		
		pi.setParameterT(0, 2.); // math::pi::Value
		
		sin.setParameterT(0, 2.); // math::sin::Value
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // branch::Index is automated
		
		;                                   // input_toggle2::Input is automated
		input_toggle2.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle2::Value2 is automated
		
		oscillator.setParameterT(0, 0.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 440.); // core::oscillator::Frequency
		;                                  // oscillator::FreqRatio is automated
		;                                  // oscillator::Gate is automated
		oscillator.setParameterT(4, 1.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                                         // input_toggle3::Input is automated
		input_toggle3.setParameterT(1, 0.961907); // control::input_toggle::Value1
		;                                         // input_toggle3::Value2 is automated
		
		oscillator2.setParameterT(0, 1.);   // core::oscillator::Mode
		oscillator2.setParameterT(1, 440.); // core::oscillator::Frequency
		;                                   // oscillator2::FreqRatio is automated
		;                                   // oscillator2::Gate is automated
		oscillator2.setParameterT(4, 1.);   // core::oscillator::Phase
		oscillator2.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                                   // input_toggle9::Input is automated
		input_toggle9.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle9::Value2 is automated
		
		oscillator1.setParameterT(0, 2.);   // core::oscillator::Mode
		oscillator1.setParameterT(1, 440.); // core::oscillator::Frequency
		;                                   // oscillator1::FreqRatio is automated
		;                                   // oscillator1::Gate is automated
		oscillator1.setParameterT(4, 1.);   // core::oscillator::Phase
		oscillator1.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                                   // input_toggle1::Input is automated
		input_toggle1.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle1::Value2 is automated
		
		oscillator3.setParameterT(0, 3.);   // core::oscillator::Mode
		oscillator3.setParameterT(1, 440.); // core::oscillator::Frequency
		;                                   // oscillator3::FreqRatio is automated
		oscillator3.setParameterT(3, 1.);   // core::oscillator::Gate
		;                                   // oscillator3::Phase is automated
		oscillator3.setParameterT(5, 1.);   // core::oscillator::Gain
		
		; // chain14::NoiseFilter is automated
		
		pma2.setParameterT(0, 0.); // control::pma::Value
		pma2.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma2::Add is automated
		
		; // cable_table::Value is automated
		
		; // cable_table1::Value is automated
		
		;                                   // input_toggle5::Input is automated
		input_toggle5.setParameterT(1, 1.); // control::input_toggle::Value1
		input_toggle5.setParameterT(2, 0.); // control::input_toggle::Value2
		
		oscillator4.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator4.setParameterT(1, 55.5); // core::oscillator::Frequency
		;                                   // oscillator4::FreqRatio is automated
		;                                   // oscillator4::Gate is automated
		oscillator4.setParameterT(4, 1.);   // core::oscillator::Phase
		oscillator4.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                 // one_pole1::Frequency is automated
		one_pole1.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                   // input_toggle6::Input is automated
		input_toggle6.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle6::Value2 is automated
		
		file_player.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		;                                   // file_player::Gate is automated
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                   // file_player::FreqRatio is automated
		
		;                                   // input_toggle7::Input is automated
		input_toggle7.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle7::Value2 is automated
		
		;                                   // tempo_sync3::Tempo is automated
		;                                   // tempo_sync3::Multiplier is automated
		tempo_sync3.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync3.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // converter::Value is automated
		
		;                                   // oscillator6::Mode is automated
		oscillator6.setParameterT(1, 22.9); // core::oscillator::Frequency
		;                                   // oscillator6::FreqRatio is automated
		;                                   // oscillator6::Gate is automated
		;                                   // oscillator6::Phase is automated
		;                                   // oscillator6::Gain is automated
		
		; // add::Value is automated
		
		file_player1.setParameterT(0, 1.);   // core::file_player::PlaybackMode
		file_player1.setParameterT(1, 1.);   // core::file_player::Gate
		file_player1.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player1.setParameterT(3, 1.37); // core::file_player::FreqRatio
		
		; // input_toggle8::Input is automated
		; // input_toggle8::Value1 is automated
		; // input_toggle8::Value2 is automated
		
		;                                   // tempo_sync4::Tempo is automated
		;                                   // tempo_sync4::Multiplier is automated
		tempo_sync4.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync4.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // converter1::Value is automated
		
		;                                       // oscillator7::Mode is automated
		;                                       // oscillator7::Frequency is automated
		;                                       // oscillator7::FreqRatio is automated
		;                                       // oscillator7::Gate is automated
		oscillator7.setParameterT(4, 0.510524); // core::oscillator::Phase
		;                                       // oscillator7::Gain is automated
		
		; // add1::Value is automated
		
		file_player2.setParameterT(0, 1.);   // core::file_player::PlaybackMode
		file_player2.setParameterT(1, 1.);   // core::file_player::Gate
		file_player2.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player2.setParameterT(3, 1.37); // core::file_player::FreqRatio
		
		;                                   // input_toggle4::Input is automated
		input_toggle4.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle4::Value2 is automated
		
		;                                    // oscillator8::Mode is automated
		oscillator8.setParameterT(1, 679.4); // core::oscillator::Frequency
		;                                    // oscillator8::FreqRatio is automated
		;                                    // oscillator8::Gate is automated
		;                                    // oscillator8::Phase is automated
		;                                    // oscillator8::Gain is automated
		
		; // add2::Value is automated
		
		file_player3.setParameterT(0, 1.);   // core::file_player::PlaybackMode
		file_player3.setParameterT(1, 1.);   // core::file_player::Gate
		file_player3.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player3.setParameterT(3, 1.37); // core::file_player::FreqRatio
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // converter2::Value is automated
		
		;                                 // oscillator5::Mode is automated
		;                                 // oscillator5::Frequency is automated
		;                                 // oscillator5::FreqRatio is automated
		oscillator5.setParameterT(3, 1.); // core::oscillator::Gate
		oscillator5.setParameterT(4, 0.); // core::oscillator::Phase
		;                                 // oscillator5::Gain is automated
		
		; // sampleandhold::Counter is automated
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
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
		
		; // faust3::aN is automated
		; // faust3::del is automated
		
		;                             // gain3::Gain is automated
		gain3.setParameterT(1, 20.);  // core::gain::Smoothing
		gain3.setParameterT(2, -1.3); // core::gain::ResetValue
		
		;                              // gain4::Gain is automated
		gain4.setParameterT(1, 142.9); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);    // core::gain::ResetValue
		
		gain5.setParameterT(0, -5.1);  // core::gain::Gain
		gain5.setParameterT(1, 167.6); // core::gain::Smoothing
		gain5.setParameterT(2, -20.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 15.);
		this->setParameterT(3, 0.01646);
		this->setParameterT(4, 4.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 0.160921);
		this->setParameterT(7, 16.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, -0.00364526);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 2.);
		this->setParameterT(12, 9.9);
		this->setParameterT(13, 0.342328);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 0.0392578);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);                 // xnode_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(4).setExternalData(b, index);                 // xnode_impl::pack_resizer_t
		this->getT(0).getT(0).getT(0).getT(0).getT(5).setExternalData(b, index);                 // xnode_impl::sliderbank1_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);         // xnode_impl::ahdsr_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).setExternalData(b, index);                 // xnode_impl::ramp_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(3).setExternalData(b, index);                 // xnode_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).setExternalData(b, index);         // xnode_impl::oscillator_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1).setExternalData(b, index);         // xnode_impl::oscillator2_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(2).getT(1).setExternalData(b, index);         // xnode_impl::oscillator1_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(3).getT(1).setExternalData(b, index);         // xnode_impl::oscillator3_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(0).getT(1).setExternalData(b, index); // xnode_impl::cable_table_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(0).getT(2).setExternalData(b, index); // xnode_impl::cable_table1_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(4).getT(2).setExternalData(b, index);         // xnode_impl::oscillator4_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(5).getT(1).setExternalData(b, index);         // xnode_impl::file_player_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(6).getT(0).getT(3).setExternalData(b, index); // xnode_impl::oscillator6_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(6).getT(0).getT(5).setExternalData(b, index); // xnode_impl::file_player1_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).                                                   // xnode_impl::oscillator7_t<NV>
        getT(7).getT(0).getT(3).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(3).getT(7).getT(0).getT(5).setExternalData(b, index); // xnode_impl::file_player2_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(8).getT(0).getT(1).setExternalData(b, index); // xnode_impl::oscillator8_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(8).getT(0).getT(3).setExternalData(b, index); // xnode_impl::file_player3_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).                                                   // xnode_impl::oscillator5_t<NV>
        getT(1).getT(1).getT(1).getT(2).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(4).getT(1).getT(1).getT(2).setExternalData(b, index); // xnode_impl::peak_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).                                                   // xnode_impl::peak2_t<NV>
        getT(1).getT(1).getT(3).getT(1).
        getT(1).setExternalData(b, index);
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


