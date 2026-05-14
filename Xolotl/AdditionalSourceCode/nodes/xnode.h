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

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, oscillator13_t<NV>>>;

template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<fx::sampleandhold<NV>, 0>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table1_modRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using cable_table1_mod = parameter::from0To1<tempo_sync2_t<NV>, 
                                             1, 
                                             cable_table1_modRange>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998043f, 0.996086f, 0.994129f, 0.992172f, 0.990215f,
		0.988258f, 0.986301f, 0.984344f, 0.982387f, 0.980431f, 0.978474f,
		0.976517f, 0.97456f, 0.972603f, 0.970646f, 0.968689f, 0.966732f,
		0.964775f, 0.962818f, 0.960861f, 0.958904f, 0.956947f, 0.95499f,
		0.953033f, 0.951076f, 0.949119f, 0.947162f, 0.945205f, 0.943249f,
		0.941292f, 0.939335f, 0.937378f, 0.935421f, 0.933464f, 0.931507f,
		0.92955f, 0.927593f, 0.925636f, 0.923679f, 0.921722f, 0.919765f,
		0.917808f, 0.915851f, 0.913894f, 0.911937f, 0.90998f, 0.908023f,
		0.906067f, 0.90411f, 0.902153f, 0.900196f, 0.898239f, 0.896282f,
		0.894325f, 0.892368f, 0.890411f, 0.888454f, 0.886497f, 0.88454f,
		0.882583f, 0.880626f, 0.878669f, 0.876712f, 0.874755f, 0.872798f,
		0.870842f, 0.868885f, 0.866928f, 0.864971f, 0.863014f, 0.861057f,
		0.8591f, 0.857143f, 0.855186f, 0.853229f, 0.851272f, 0.849315f,
		0.847358f, 0.845401f, 0.843444f, 0.841487f, 0.83953f, 0.837573f,
		0.835616f, 0.833659f, 0.831703f, 0.829746f, 0.827789f, 0.825832f,
		0.823875f, 0.821918f, 0.819961f, 0.818004f, 0.816047f, 0.81409f,
		0.812133f, 0.810176f, 0.808219f, 0.806262f, 0.804305f, 0.802348f,
		0.800391f, 0.798434f, 0.796477f, 0.794521f, 0.792564f, 0.790607f,
		0.78865f, 0.786693f, 0.784736f, 0.782779f, 0.780822f, 0.778865f,
		0.776908f, 0.774951f, 0.772994f, 0.771037f, 0.76908f, 0.767123f,
		0.765166f, 0.763209f, 0.761252f, 0.759295f, 0.757339f, 0.755382f,
		0.753425f, 0.751468f, 0.749511f, 0.747554f, 0.745597f, 0.74364f,
		0.741683f, 0.739726f, 0.737769f, 0.735812f, 0.733855f, 0.731898f,
		0.729941f, 0.727984f, 0.726027f, 0.72407f, 0.722113f, 0.720157f,
		0.7182f, 0.716243f, 0.714286f, 0.712329f, 0.710372f, 0.708415f,
		0.706458f, 0.704501f, 0.702544f, 0.700587f, 0.69863f, 0.696673f,
		0.694716f, 0.692759f, 0.690802f, 0.688845f, 0.686888f, 0.684932f,
		0.682975f, 0.681018f, 0.679061f, 0.677104f, 0.675147f, 0.67319f,
		0.671233f, 0.669276f, 0.667319f, 0.665362f, 0.663405f, 0.661448f,
		0.659491f, 0.657534f, 0.655577f, 0.65362f, 0.651663f, 0.649706f,
		0.64775f, 0.645793f, 0.643836f, 0.641879f, 0.639922f, 0.637965f,
		0.636008f, 0.634051f, 0.632094f, 0.630137f, 0.62818f, 0.626223f,
		0.624266f, 0.622309f, 0.620352f, 0.618395f, 0.616438f, 0.614481f,
		0.612524f, 0.610568f, 0.608611f, 0.606654f, 0.604697f, 0.60274f,
		0.600783f, 0.598826f, 0.596869f, 0.594912f, 0.592955f, 0.590998f,
		0.589041f, 0.587084f, 0.585127f, 0.58317f, 0.581213f, 0.579256f,
		0.577299f, 0.575342f, 0.573385f, 0.571429f, 0.569472f, 0.567515f,
		0.565558f, 0.563601f, 0.561644f, 0.559687f, 0.55773f, 0.555773f,
		0.553816f, 0.551859f, 0.549902f, 0.547945f, 0.545988f, 0.544031f,
		0.542074f, 0.540117f, 0.53816f, 0.536204f, 0.534247f, 0.53229f,
		0.530333f, 0.528376f, 0.526419f, 0.524462f, 0.522505f, 0.520548f,
		0.518591f, 0.516634f, 0.514677f, 0.51272f, 0.510763f, 0.508806f,
		0.506849f, 0.504892f, 0.502935f, 0.500978f, 0.499022f, 0.497065f,
		0.495108f, 0.493151f, 0.491194f, 0.489237f, 0.48728f, 0.485323f,
		0.483366f, 0.481409f, 0.479452f, 0.477495f, 0.475538f, 0.473581f,
		0.471624f, 0.469667f, 0.46771f, 0.465753f, 0.463796f, 0.46184f,
		0.459883f, 0.457926f, 0.455969f, 0.454012f, 0.452055f, 0.450098f,
		0.448141f, 0.446184f, 0.444227f, 0.44227f, 0.440313f, 0.438356f,
		0.436399f, 0.434442f, 0.432485f, 0.430528f, 0.428571f, 0.426614f,
		0.424658f, 0.422701f, 0.420744f, 0.418787f, 0.41683f, 0.414873f,
		0.412916f, 0.410959f, 0.409002f, 0.407045f, 0.405088f, 0.403131f,
		0.401174f, 0.399217f, 0.39726f, 0.395303f, 0.393346f, 0.391389f,
		0.389432f, 0.387476f, 0.385519f, 0.383562f, 0.381605f, 0.379648f,
		0.377691f, 0.375734f, 0.373777f, 0.37182f, 0.369863f, 0.367906f,
		0.365949f, 0.363992f, 0.362035f, 0.360078f, 0.358121f, 0.356164f,
		0.354207f, 0.352251f, 0.350294f, 0.348337f, 0.34638f, 0.344423f,
		0.342466f, 0.340509f, 0.338552f, 0.336595f, 0.334638f, 0.332681f,
		0.330724f, 0.328767f, 0.32681f, 0.324853f, 0.322896f, 0.320939f,
		0.318982f, 0.317025f, 0.315068f, 0.313112f, 0.311155f, 0.309198f,
		0.307241f, 0.305284f, 0.303327f, 0.30137f, 0.299413f, 0.297456f,
		0.295499f, 0.293542f, 0.291585f, 0.289628f, 0.287671f, 0.285714f,
		0.283757f, 0.2818f, 0.279843f, 0.277887f, 0.27593f, 0.273973f,
		0.272016f, 0.270059f, 0.268102f, 0.266145f, 0.264188f, 0.262231f,
		0.260274f, 0.258317f, 0.25636f, 0.254403f, 0.252446f, 0.250489f,
		0.248532f, 0.246575f, 0.244618f, 0.242661f, 0.240704f, 0.238748f,
		0.236791f, 0.234834f, 0.232877f, 0.23092f, 0.228963f, 0.227006f,
		0.225049f, 0.223092f, 0.221135f, 0.219178f, 0.217221f, 0.215264f,
		0.213307f, 0.21135f, 0.209393f, 0.207436f, 0.205479f, 0.203523f,
		0.201566f, 0.199609f, 0.197652f, 0.195695f, 0.193738f, 0.191781f,
		0.189824f, 0.187867f, 0.18591f, 0.183953f, 0.181996f, 0.180039f,
		0.178082f, 0.176125f, 0.174168f, 0.172211f, 0.170254f, 0.168297f,
		0.166341f, 0.164384f, 0.162427f, 0.16047f, 0.158513f, 0.156556f,
		0.154599f, 0.152642f, 0.150685f, 0.148728f, 0.146771f, 0.144814f,
		0.142857f, 0.1409f, 0.138943f, 0.136986f, 0.135029f, 0.133072f,
		0.131115f, 0.129158f, 0.127202f, 0.125245f, 0.123288f, 0.121331f,
		0.119374f, 0.117417f, 0.11546f, 0.113503f, 0.111546f, 0.109589f,
		0.107632f, 0.105675f, 0.103718f, 0.101761f, 0.0998043f, 0.0978474f,
		0.0958903f, 0.0939335f, 0.0919765f, 0.0900196f, 0.0880627f, 0.0861056f,
		0.0841488f, 0.0821917f, 0.0802348f, 0.0782779f, 0.0763209f, 0.0743641f,
		0.072407f, 0.0704501f, 0.0684931f, 0.0665362f, 0.0645792f, 0.0626223f,
		0.0606654f, 0.0587084f, 0.0567515f, 0.0547945f, 0.0528376f, 0.0508806f,
		0.0489237f, 0.0469668f, 0.0450097f, 0.0430529f, 0.0410959f, 0.039139f,
		0.037182f, 0.035225f, 0.0332682f, 0.0313111f, 0.0293542f, 0.0273973f,
		0.0254403f, 0.0234835f, 0.0215264f, 0.0195695f, 0.0176125f, 0.0156556f,
		0.0136986f, 0.0117417f, 0.00978482f, 0.00782776f, 0.00587088f, 0.00391382f,
		0.00195694f, 0.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod<NV>>, 
                                  data::embedded::table<cable_table1_t_data>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table2_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using cable_table2_mod = parameter::from0To1<tempo_sync2_t<NV>, 
                                             0, 
                                             cable_table2_modRange>;

struct cable_table2_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998043f, 0.996086f, 0.994129f, 0.992172f, 0.990215f,
		0.988258f, 0.986301f, 0.984344f, 0.982387f, 0.980431f, 0.978474f,
		0.976517f, 0.97456f, 0.972603f, 0.970646f, 0.968689f, 0.966732f,
		0.964775f, 0.962818f, 0.960861f, 0.958904f, 0.956947f, 0.95499f,
		0.953033f, 0.951076f, 0.949119f, 0.947162f, 0.945205f, 0.943249f,
		0.941292f, 0.939335f, 0.937378f, 0.935421f, 0.933464f, 0.931507f,
		0.92955f, 0.927593f, 0.925636f, 0.923679f, 0.921722f, 0.919765f,
		0.917808f, 0.915851f, 0.913894f, 0.911937f, 0.90998f, 0.908023f,
		0.906067f, 0.90411f, 0.902153f, 0.900196f, 0.898239f, 0.896282f,
		0.894325f, 0.892368f, 0.890411f, 0.888454f, 0.886497f, 0.88454f,
		0.882583f, 0.880626f, 0.878669f, 0.876712f, 0.874755f, 0.872798f,
		0.870842f, 0.868885f, 0.866928f, 0.864971f, 0.863014f, 0.861057f,
		0.8591f, 0.857143f, 0.855186f, 0.853229f, 0.851272f, 0.849315f,
		0.847358f, 0.845401f, 0.843444f, 0.841487f, 0.83953f, 0.837573f,
		0.835616f, 0.833659f, 0.831703f, 0.829746f, 0.827789f, 0.825832f,
		0.823875f, 0.821918f, 0.819961f, 0.818004f, 0.816047f, 0.81409f,
		0.812133f, 0.810176f, 0.808219f, 0.806262f, 0.804305f, 0.802348f,
		0.800391f, 0.798434f, 0.796477f, 0.794521f, 0.792564f, 0.790607f,
		0.78865f, 0.786693f, 0.784736f, 0.782779f, 0.780822f, 0.778865f,
		0.776908f, 0.774951f, 0.772994f, 0.771037f, 0.76908f, 0.767123f,
		0.765166f, 0.763209f, 0.761252f, 0.759295f, 0.757339f, 0.755382f,
		0.753425f, 0.751468f, 0.749511f, 0.747554f, 0.745597f, 0.74364f,
		0.741683f, 0.739726f, 0.737769f, 0.735812f, 0.733855f, 0.731898f,
		0.729941f, 0.727984f, 0.726027f, 0.72407f, 0.722113f, 0.720157f,
		0.7182f, 0.716243f, 0.714286f, 0.712329f, 0.710372f, 0.708415f,
		0.706458f, 0.704501f, 0.702544f, 0.700587f, 0.69863f, 0.696673f,
		0.694716f, 0.692759f, 0.690802f, 0.688845f, 0.686888f, 0.684932f,
		0.682975f, 0.681018f, 0.679061f, 0.677104f, 0.675147f, 0.67319f,
		0.671233f, 0.669276f, 0.667319f, 0.665362f, 0.663405f, 0.661448f,
		0.659491f, 0.657534f, 0.655577f, 0.65362f, 0.651663f, 0.649706f,
		0.64775f, 0.645793f, 0.643836f, 0.641879f, 0.639922f, 0.637965f,
		0.636008f, 0.634051f, 0.632094f, 0.630137f, 0.62818f, 0.626223f,
		0.624266f, 0.622309f, 0.620352f, 0.618395f, 0.616438f, 0.614481f,
		0.612524f, 0.610568f, 0.608611f, 0.606654f, 0.604697f, 0.60274f,
		0.600783f, 0.598826f, 0.596869f, 0.594912f, 0.592955f, 0.590998f,
		0.589041f, 0.587084f, 0.585127f, 0.58317f, 0.581213f, 0.579256f,
		0.577299f, 0.575342f, 0.573385f, 0.571429f, 0.569472f, 0.567515f,
		0.565558f, 0.563601f, 0.561644f, 0.559687f, 0.55773f, 0.555773f,
		0.553816f, 0.551859f, 0.549902f, 0.547945f, 0.545988f, 0.544031f,
		0.542074f, 0.540117f, 0.53816f, 0.536204f, 0.534247f, 0.53229f,
		0.530333f, 0.528376f, 0.526419f, 0.524462f, 0.522505f, 0.520548f,
		0.518591f, 0.516634f, 0.514677f, 0.51272f, 0.510763f, 0.508806f,
		0.506849f, 0.504892f, 0.502935f, 0.500978f, 0.499022f, 0.497065f,
		0.495108f, 0.493151f, 0.491194f, 0.489237f, 0.48728f, 0.485323f,
		0.483366f, 0.481409f, 0.479452f, 0.477495f, 0.475538f, 0.473581f,
		0.471624f, 0.469667f, 0.46771f, 0.465753f, 0.463796f, 0.46184f,
		0.459883f, 0.457926f, 0.455969f, 0.454012f, 0.452055f, 0.450098f,
		0.448141f, 0.446184f, 0.444227f, 0.44227f, 0.440313f, 0.438356f,
		0.436399f, 0.434442f, 0.432485f, 0.430528f, 0.428571f, 0.426614f,
		0.424658f, 0.422701f, 0.420744f, 0.418787f, 0.41683f, 0.414873f,
		0.412916f, 0.410959f, 0.409002f, 0.407045f, 0.405088f, 0.403131f,
		0.401174f, 0.399217f, 0.39726f, 0.395303f, 0.393346f, 0.391389f,
		0.389432f, 0.387476f, 0.385519f, 0.383562f, 0.381605f, 0.379648f,
		0.377691f, 0.375734f, 0.373777f, 0.37182f, 0.369863f, 0.367906f,
		0.365949f, 0.363992f, 0.362035f, 0.360078f, 0.358121f, 0.356164f,
		0.354207f, 0.352251f, 0.350294f, 0.348337f, 0.34638f, 0.344423f,
		0.342466f, 0.340509f, 0.338552f, 0.336595f, 0.334638f, 0.332681f,
		0.330724f, 0.328767f, 0.32681f, 0.324853f, 0.322896f, 0.320939f,
		0.318982f, 0.317025f, 0.315068f, 0.313112f, 0.311155f, 0.309198f,
		0.307241f, 0.305284f, 0.303327f, 0.30137f, 0.299413f, 0.297456f,
		0.295499f, 0.293542f, 0.291585f, 0.289628f, 0.287671f, 0.285714f,
		0.283757f, 0.2818f, 0.279843f, 0.277887f, 0.27593f, 0.273973f,
		0.272016f, 0.270059f, 0.268102f, 0.266145f, 0.264188f, 0.262231f,
		0.260274f, 0.258317f, 0.25636f, 0.254403f, 0.252446f, 0.250489f,
		0.248532f, 0.246575f, 0.244618f, 0.242661f, 0.240704f, 0.238748f,
		0.236791f, 0.234834f, 0.232877f, 0.23092f, 0.228963f, 0.227006f,
		0.225049f, 0.223092f, 0.221135f, 0.219178f, 0.217221f, 0.215264f,
		0.213307f, 0.21135f, 0.209393f, 0.207436f, 0.205479f, 0.203523f,
		0.201566f, 0.199609f, 0.197652f, 0.195695f, 0.193738f, 0.191781f,
		0.189824f, 0.187867f, 0.18591f, 0.183953f, 0.181996f, 0.180039f,
		0.178082f, 0.176125f, 0.174168f, 0.172211f, 0.170254f, 0.168297f,
		0.166341f, 0.164384f, 0.162427f, 0.16047f, 0.158513f, 0.156556f,
		0.154599f, 0.152642f, 0.150685f, 0.148728f, 0.146771f, 0.144814f,
		0.142857f, 0.1409f, 0.138943f, 0.136986f, 0.135029f, 0.133072f,
		0.131115f, 0.129158f, 0.127202f, 0.125245f, 0.123288f, 0.121331f,
		0.119374f, 0.117417f, 0.11546f, 0.113503f, 0.111546f, 0.109589f,
		0.107632f, 0.105675f, 0.103718f, 0.101761f, 0.0998043f, 0.0978474f,
		0.0958903f, 0.0939335f, 0.0919765f, 0.0900196f, 0.0880627f, 0.0861056f,
		0.0841488f, 0.0821917f, 0.0802348f, 0.0782779f, 0.0763209f, 0.0743641f,
		0.072407f, 0.0704501f, 0.0684931f, 0.0665362f, 0.0645792f, 0.0626223f,
		0.0606654f, 0.0587084f, 0.0567515f, 0.0547945f, 0.0528376f, 0.0508806f,
		0.0489237f, 0.0469668f, 0.0450097f, 0.0430529f, 0.0410959f, 0.039139f,
		0.037182f, 0.035225f, 0.0332682f, 0.0313111f, 0.0293542f, 0.0273973f,
		0.0254403f, 0.0234835f, 0.0215264f, 0.0195695f, 0.0176125f, 0.0156556f,
		0.0136986f, 0.0117417f, 0.00978482f, 0.00782776f, 0.00587088f, 0.00391382f,
		0.00195694f, 0.f
	};
};

template <int NV>
using cable_table2_t = wrap::data<control::cable_table<cable_table2_mod<NV>>, 
                                  data::embedded::table<cable_table2_t_data>>;

namespace chain45_t_parameters
{
DECLARE_PARAMETER_RANGE(harm_InputRange, 
                        1., 
                        16.);

template <int NV>
using harm = parameter::chain<harm_InputRange, 
                              parameter::plain<xnode_impl::cable_table1_t<NV>, 0>>;

}

template <int NV>
using chain45_t = container::chain<chain45_t_parameters::harm<NV>, 
                                   wrap::fix<2, chain2_t<NV>>, 
                                   cable_table1_t<NV>, 
                                   cable_table2_t<NV>, 
                                   tempo_sync2_t<NV>, 
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
                                           parameter::plain<oscillator14_t<NV>, 2>, 
                                           parameter::plain<wrap::no_process<core::phasor_fm<NV>>, 2>>;

template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, pma_unscaled1_mod<NV>>;

template <int NV>
struct one_shot_player: public data::base
{
	SNEX_NODE(one_shot_player);
	static const int NUM_CHANNELS = 2;
	ExternalData data;
	span<dyn<float>, NUM_CHANNELS> sample;
	double sr = 0.0;
	// Playback ratio multiplier, matching HISE-style FreqRatio behaviour.
	double pitchRatio = 1.0;
	double grainMs = 50.0;      // grain size in milliseconds
	double grainSize = 2048.0; // samples
	// Freeze + scrub
	bool freeze = true;
	double scrub = 0.0;   // 0..1
	int scrubMode = 0;    // 0 = latch, 1 = zero-crossing latch
	// Loop
	bool loop = false;
	double loopStart = 0.0; // 0..1
	double loopEnd = 1.0;   // 0..1
	// MIDI root note
	int rootNote = 60;
	double scanPhase = 0.0;
	//double smoothScrub = 0.0;
	void updateGrainSize()
	{
		if (sr <= 0.0)
			return;
		grainSize = (grainMs * sr) * 0.001;
		// safety clamp
		if (grainSize < 8.0)
			grainSize = 8.0;
		if (grainSize > (double)data.numSamples - 2.0)
			grainSize = (double)data.numSamples - 2.0;
	}
	inline double hann(double x)
	{
		// x = 0..1
		return 0.5 - 0.5 * Math.cos(2.0 * Math.PI * x);
	}
	inline double clamp01(double x)
	{
		if (x < 0.0)
			return 0.0;
		if (x > 1.0)
			return 1.0;
		return x;
	}
	void getLoopRange(double& startSample, double& endSample)
	{
		double maxSample = (double)data.numSamples - 2.0;
		if (maxSample < 0.0)
		{
			startSample = 0.0;
			endSample = 0.0;
			return;
		}
		startSample = clamp01(loopStart) * maxSample;
		endSample = clamp01(loopEnd) * maxSample;
		if (endSample < startSample)
		{
			double tmp = startSample;
			startSample = endSample;
			endSample = tmp;
		}
		if (endSample < startSample + 8.0)
			endSample = startSample + 8.0;
		if (endSample > maxSample)
			endSample = maxSample;
		if (startSample > endSample - 8.0)
			startSample = endSample - 8.0;
		if (startSample < 0.0)
			startSample = 0.0;
	}
	double findNearestZeroCrossing(double targetPos, double minPos, double maxPos)
	{
		if (data.numSamples < 2)
			return targetPos;
		int minIndex = (int)minPos;
		int maxIndex = (int)maxPos;
		if (minIndex < 0)
			minIndex = 0;
		if (maxIndex > data.numSamples - 2)
			maxIndex = data.numSamples - 2;
		int centre = (int)targetPos;
		if (centre < minIndex)
			centre = minIndex;
		if (centre > maxIndex)
			centre = maxIndex;
		int searchRadius = 128;
		int bestIndex = 0;
		int bestDistance = searchRadius + 1;
		bool foundCrossing = false;
		for (int offset = 0; offset <= searchRadius; offset++)
		{
			for (int c = 0; c < 2; c++)
			{
				int i = centre - offset;
				if (c == 1)
					i = centre + offset;
				if (i < minIndex || i > maxIndex)
					continue;
				float a = sample[0][i];
				float b = sample[0][i + 1];
				bool crossing = (a <= 0.0f && b > 0.0f) || (a >= 0.0f && b < 0.0f);
				if (crossing)
				{
					int dist = i - centre;
					if (dist < 0)
						dist = centre - i;
					if (dist < bestDistance)
					{
						bestDistance = dist;
						bestIndex = i;
						foundCrossing = true;
					}
				}
			}
			if (foundCrossing)
				break;
		}
		if (foundCrossing == false)
			return targetPos;
		return (double)bestIndex;
	}
	double getFreezeStartPosition(double scrubNorm, double loopRangeStart, double regionLength, double thisGrainSize)
	{
		double maxStart = regionLength - thisGrainSize;
		double targetStart = loopRangeStart + (scrubNorm * maxStart);
		if (scrubMode == 1)
		{
			double minStart = loopRangeStart;
			double maxAllowedStart = loopRangeStart + maxStart;
			targetStart = findNearestZeroCrossing(targetStart, minStart, maxAllowedStart);
		}
		return targetStart;
	}
	struct VoiceData
	{
		double uptime = 0.0;   // read position
		double delta = 1.0;    // playback speed
		int noteNumber = 60;
		double activeScrub = 0.0;
		double pendingScrub = 0.0;
		double grainStart = 0.0;
		bool hasPendingScrub = false;
		void reset()
		{
			uptime = 0.0;
			activeScrub = 0.0;
			pendingScrub = 0.0;
			grainStart = 0.0;
			hasPendingScrub = false;
		}
	};
	PolyData<VoiceData, NV> voiceData;
	void prepare(PrepareSpecs ps)
	{
		voiceData.prepare(ps);
		sr = ps.sampleRate;
	}
	void reset()
	{
		for (auto& v : voiceData)
			v.reset();
	}
	void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
	{
		double pos = 0.0;
		double windowDenom = grainSize;
		if (freeze)
		{
			double sampleEnd = (double)data.numSamples - 2.0;
			if (sampleEnd < 8.0)
				return;
			double thisGrainSize = grainSize;
			if (thisGrainSize > sampleEnd)
				thisGrainSize = sampleEnd;
			if (thisGrainSize < 8.0)
				return;
			windowDenom = thisGrainSize;
			if (v.uptime <= 0.0)
				v.grainStart = getFreezeStartPosition(v.activeScrub, 0.0, sampleEnd, thisGrainSize);
			pos = v.grainStart + v.uptime;
			v.uptime += v.delta;
			if (v.uptime >= thisGrainSize)
			{
				v.uptime -= thisGrainSize;
				if (v.hasPendingScrub)
				{
					v.activeScrub = v.pendingScrub;
					v.hasPendingScrub = false;
				}
				v.grainStart = getFreezeStartPosition(v.activeScrub, 0.0, sampleEnd, thisGrainSize);
			}
		}
		else
		{
			pos = v.uptime;
			v.uptime += v.delta;
			if (loop)
			{
				double loopRangeStart = 0.0;
				double loopRangeEnd = 0.0;
				getLoopRange(loopRangeStart, loopRangeEnd);
				if (loopRangeEnd - loopRangeStart < 8.0)
					return;
				if (pos < loopRangeStart || pos >= loopRangeEnd)
					pos = loopRangeStart;
				if (v.uptime >= loopRangeEnd)
					v.uptime = loopRangeStart;
			}
			else if (pos >= (data.numSamples - 1))
			{
				return;
			}
		}
		// --- interpolation ---
		int iPos = (int)pos;
		int iNext = iPos + 1;
		if (iNext >= data.numSamples)
			iNext = data.numSamples - 1;
		double frac = pos - (double)iPos;
		for (int ch = 0; ch < NUM_CHANNELS; ch++)
		{
			float s0 = sample[ch][iPos];
			float s1 = sample[ch][iNext];
			double winPhase = v.uptime / windowDenom;
			double win = hann(winPhase);
			fd[ch] += (float)(((1.0 - frac) * s0 + frac * s1) * win);
		}
	}
	template <typename ProcessDataType>
	void process(ProcessDataType& pd)
	{
		if (data.numSamples == 0)
			return;
		DataReadLock sl(data);
		auto& v = voiceData.get();
		auto fd = pd.toFrameData();
		while (fd.next())
			processInternal(fd.toSpan(), v);
		data.setDisplayedValue(v.uptime);
		bool isPlaying = (int)v.uptime < data.numSamples;
		gate.setModValueIfChanged((double)isPlaying);
	}
	void processFrame(span<float, NUM_CHANNELS>& fd)
	{
		if (data.numSamples == 0)
			return;
		DataReadLock sl(data);
		auto& v = voiceData.get();
		processInternal(fd, v);
	}
	// MIDI note handling
	void handleHiseEvent(HiseEvent& e)
	{
		if (e.isNoteOn())
		{
			auto& v = voiceData.get();
			v.reset();
			v.noteNumber = e.getNoteNumber();
			v.activeScrub = scrub;
			v.pendingScrub = scrub;
			if (loop && data.numSamples > 0)
			{
				double loopRangeStart = 0.0;
				double loopRangeEnd = 0.0;
				getLoopRange(loopRangeStart, loopRangeEnd);
				v.uptime = loopRangeStart;
			}
			double midiSemis = (double)(v.noteNumber - rootNote);
			double midiRatio = Math.pow(2.0, midiSemis / 12.0);
			double pitchMult = midiRatio * pitchRatio;
			if (sr > 0.0)
				v.delta = (data.sampleRate / sr) * pitchMult;
		}
	}
	void updateDelta()
	{
		if (data.numSamples == 0 || sr == 0.0)
			return;
		for (auto& v : voiceData)
		{
			double midiSemis = (double)(v.noteNumber - rootNote);
			double midiRatio = Math.pow(2.0, midiSemis / 12.0);
			double pitchMult = midiRatio * pitchRatio;
			v.delta = (data.sampleRate / sr) * pitchMult;
		}
	}
	void setExternalData(const ExternalData& ed, int index)
	{
		data = ed;
		ed.referBlockTo(sample[0], 0);
		ed.referBlockTo(sample[1], 1);
		updateDelta();
		updateGrainSize();
		reset();
	}
	ModValue gate;
	bool handleModulation(double& value)
	{
		return gate.getChangedValue(value);
	}
	template <int P>
	void setParameter(double v)
	{
		// FreqRatio: direct playback multiplier.
		if (P == 0)
		{
			pitchRatio = v;
			updateDelta();
		}
		// Loop
		if (P == 1)
		{
			loop = (v > 0.5);
		}
		// Freeze
		if (P == 2)
		{
			freeze = (v > 0.5);
		}
		// Scrub
		if (P == 3)
		{
			scrub = v;
			data.setDisplayedValue(scrub);
			for (auto& vd : voiceData)
			{
				vd.pendingScrub = scrub;
				vd.hasPendingScrub = true;
				if (!freeze)
					vd.activeScrub = scrub;
			}
		}
		// 0..1 → ~20ms .. ~500ms (musical)
		// Grain size in milliseconds (direct input from UI)
		if (P == 4)
		{
			grainMs = v;   // v is already an exact millisecond value
			updateGrainSize();
		}
		if (P == 5)
		{
			loopStart = clamp01(v);
		}
		if (P == 6)
		{
			loopEnd = clamp01(v);
		}
		if (P == 7)
		{
			scrubMode = (v > 0.5) ? 1 : 0;
		}
	}
};

template <int NV>
using snex_node_t = wrap::data<one_shot_player<NV>, 
                               data::external::audiofile<1>>;
template <int NV>
using pma_unscaled2_t = control::pma_unscaled<NV, 
                                              parameter::plain<snex_node_t<NV>, 0>>;

template <int NV>
using pma_unscaled_mod = parameter::chain<ranges::Identity, 
                                          parameter::plain<pma_unscaled1_t<NV>, 2>, 
                                          parameter::plain<pma_unscaled2_t<NV>, 2>>;

template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, pma_unscaled_mod<NV>>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled_t<NV>, 2>>;

template <int NV>
using smoothed_parameter_unscaled_mod = parameter::chain<ranges::Identity, 
                                                         parameter::plain<pma_unscaled1_t<NV>, 0>, 
                                                         parameter::plain<pma_unscaled2_t<NV>, 0>>;

template <int NV>
using smoothed_parameter_unscaled_t = wrap::mod<smoothed_parameter_unscaled_mod<NV>, 
                                                control::smoothed_parameter_unscaled<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, minmax_t<NV>>, 
                                      pma_unscaled_t<NV>, 
                                      smoothed_parameter_unscaled_t<NV>, 
                                      pma_unscaled1_t<NV>, 
                                      pma_unscaled2_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader2_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader2_c0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       xfader2_c0Range>;

template <int NV> using xfader2_c1 = xfader2_c0<NV>;

template <int NV>
using xfader2_multimod = parameter::list<xfader2_c0<NV>, xfader2_c1<NV>>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::linear>;

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
                                   wrap::no_process<core::phasor_fm<NV>>, 
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
using converter1_t = control::converter<parameter::plain<core::phasor<NV>, 1>, 
                                        conversion_logic::ms2freq>;
template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<converter1_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, tempo_sync1_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::phasor<NV>>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, converter1_t<NV>>, 
                                   core::phasor<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain17_t<NV>>, 
                                    chain18_t<NV>>;

DECLARE_PARAMETER_RANGE(smoothed_parameter_mod_1Range, 
                        0., 
                        0.999997);

template <int NV>
using smoothed_parameter_mod_1 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_1Range>;

DECLARE_PARAMETER_RANGE(smoothed_parameter_mod_2Range, 
                        0., 
                        0.999997);

template <int NV>
using smoothed_parameter_mod_2 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_2Range>;

DECLARE_PARAMETER_RANGE(smoothed_parameter_mod_3Range, 
                        0., 
                        0.999997);

template <int NV>
using smoothed_parameter_mod_3 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_3Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_4Range, 
                             0., 
                             0.999997, 
                             0.00195312);

template <int NV>
using smoothed_parameter_mod_4 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_4Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_5Range, 
                             0., 
                             0.999997, 
                             0.00390625);

template <int NV>
using smoothed_parameter_mod_5 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_5Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_6Range, 
                             0., 
                             0.999997, 
                             0.0078125);

template <int NV>
using smoothed_parameter_mod_6 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_6Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_7Range, 
                             0., 
                             0.999997, 
                             0.015625);

template <int NV>
using smoothed_parameter_mod_7 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_7Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_8Range, 
                             0., 
                             0.999997, 
                             0.03125);

template <int NV>
using smoothed_parameter_mod_8 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_8Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_9Range, 
                             0., 
                             0.999997, 
                             0.0625);

template <int NV>
using smoothed_parameter_mod_9 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_9Range>;

template <int NV>
using smoothed_parameter_mod = parameter::chain<ranges::Identity, 
                                                parameter::plain<math::add<NV>, 0>, 
                                                smoothed_parameter_mod_1<NV>, 
                                                smoothed_parameter_mod_2<NV>, 
                                                smoothed_parameter_mod_3<NV>, 
                                                smoothed_parameter_mod_4<NV>, 
                                                smoothed_parameter_mod_5<NV>, 
                                                smoothed_parameter_mod_6<NV>, 
                                                smoothed_parameter_mod_7<NV>, 
                                                smoothed_parameter_mod_8<NV>, 
                                                smoothed_parameter_mod_9<NV>>;

template <int NV>
using smoothed_parameter_t = wrap::mod<smoothed_parameter_mod<NV>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<2, math::add<NV>>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter_t<NV>>, 
                                  branch4_t<NV>>;
template <int NV>
using file_player6_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch5_t<NV>>, 
                                   core::gain<NV>, 
                                   chain9_t<NV>, 
                                   file_player6_t<NV>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, modchain_t<NV>>, 
                                   chain43_t<NV>>;

template <int NV>
using smoothed_parameter2_mod_1 = smoothed_parameter_mod_1<NV>;

template <int NV>
using smoothed_parameter2_mod_2 = smoothed_parameter_mod_2<NV>;

template <int NV>
using smoothed_parameter2_mod_3 = smoothed_parameter_mod_3<NV>;

template <int NV>
using smoothed_parameter2_mod_4 = smoothed_parameter_mod_4<NV>;

template <int NV>
using smoothed_parameter2_mod_5 = smoothed_parameter_mod_5<NV>;

template <int NV>
using smoothed_parameter2_mod_6 = smoothed_parameter_mod_6<NV>;

template <int NV>
using smoothed_parameter2_mod_7 = smoothed_parameter_mod_7<NV>;

template <int NV>
using smoothed_parameter2_mod_8 = smoothed_parameter_mod_8<NV>;

template <int NV>
using smoothed_parameter2_mod_9 = smoothed_parameter_mod_9<NV>;

template <int NV>
using smoothed_parameter2_mod = parameter::chain<ranges::Identity, 
                                                 parameter::plain<math::add<NV>, 0>, 
                                                 smoothed_parameter2_mod_1<NV>, 
                                                 smoothed_parameter2_mod_2<NV>, 
                                                 smoothed_parameter2_mod_3<NV>, 
                                                 smoothed_parameter2_mod_4<NV>, 
                                                 smoothed_parameter2_mod_5<NV>, 
                                                 smoothed_parameter2_mod_6<NV>, 
                                                 smoothed_parameter2_mod_7<NV>, 
                                                 smoothed_parameter2_mod_8<NV>, 
                                                 smoothed_parameter2_mod_9<NV>>;

template <int NV>
using smoothed_parameter2_t = wrap::mod<smoothed_parameter2_mod<NV>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, math::add<NV>>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, smoothed_parameter2_t<NV>>, 
                                   branch6_t<NV>>;

template <int NV>
using peak2_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<snex_node_t<NV>, 3>, 
                                   parameter::plain<snex_node_t<NV>, 5>>;

template <int NV>
using peak2_t = wrap::mod<peak2_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain26_t<NV>>, 
                                      peak2_t<NV>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, modchain3_t<NV>>, 
                                   snex_node_t<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain8_t<NV>>, 
                                   chain15_t<NV>, 
                                   chain14_t<NV>, 
                                   chain19_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(simple_ar_c0Range, 
                             0., 
                             1., 
                             1.);

template <int NV>
using simple_ar_c0 = parameter::from0To1<core::phasor<NV>, 
                                         0, 
                                         simple_ar_c0Range>;

template <int NV>
using simple_ar_multimod = parameter::list<simple_ar_c0<NV>, parameter::empty>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod<NV>>>;

template <int NV> using converter_t = converter1_t<NV>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>, 
                                        parameter::plain<converter_t<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync_t<NV>>, 
                                    converter_t<NV>, 
                                    core::phasor<NV>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using cable_table3_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<0>>;

template <int NV>
using peak1_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table3_t<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;
template <int NV> using oscillator_t = oscillator9_t<NV>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   wrap::no_process<math::sig2mod<NV>>, 
                                   oscillator_t<NV>, 
                                   fx::sampleandhold<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>, 
                                   math::pi<NV>, 
                                   math::sin<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain10_t<NV>>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>, 
                                   math::mod_inv<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain25_t<NV>>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table3_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain28_t<NV>>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain1_t>, 
                                    chain21_t<NV>, 
                                    chain23_t<NV>, 
                                    chain24_t<NV>, 
                                    chain27_t<NV>>;

template <int NV> using pma1_mod = xfader2_c0<NV>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;

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
using smoothed_parameter1_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<pma1_t<NV>, 0>, 
                                  parameter::plain<smoothed_parameter_unscaled_t<NV>, 0>, 
                                  parameter::plain<smoothed_parameter1_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using modchain8_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, no_midi_t<NV>>, 
                                      peak1_t<NV>, 
                                      math::clear<NV>, 
                                      branch1_t<NV>, 
                                      peak_t<NV>>;

template <int NV>
using modchain8_t = wrap::control_rate<modchain8_t_<NV>>;

template <int NV> using xfader1_c0 = xfader2_c0<NV>;

template <int NV> using xfader1_c1 = xfader2_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, smoothed_parameter1_t<NV>>, 
                                      pma_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::allpass<NV>>, 
                                  wrap::no_process<math::tanh<NV>>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain7_t>, 
                                    filters::svf<NV>, 
                                    filters::svf<NV>, 
                                    filters::svf<NV>, 
                                    chain3_t<NV>>;

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
                                 wrap::fix<2, chain4_t<NV>>, 
                                 modchain7_t<NV>, 
                                 core::gain<NV>, 
                                 core::gain<NV>>;

namespace xnode_t_parameters
{
// Parameter list for xnode_impl::xnode_t ----------------------------------------------------------

template <int NV>
using Harm_1 = parameter::from0To1<xnode_impl::tempo_sync1_t<NV>, 
                                   0, 
                                   xnode_impl::cable_table2_modRange>;

template <int NV>
using Harm = parameter::chain<ranges::Identity, 
                              parameter::plain<xnode_impl::minmax_t<NV>, 0>, 
                              Harm_1<NV>>;

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

template <int NV>
using FxValue_0 = parameter::from0To1<xnode_impl::tempo_sync_t<NV>, 
                                      0, 
                                      xnode_impl::cable_table2_modRange>;

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
                                 parameter::plain<xnode_impl::pma_unscaled2_t<NV>, 1>>;

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

DECLARE_PARAMETER_RANGE(DET_InputRange, 
                        0., 
                        2.);

template <int NV>
using DET = parameter::chain<DET_InputRange, 
                             parameter::plain<xnode_impl::pma_unscaled_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_SKEW(ShSmooth_InputRange, 
                             0., 
                             2000., 
                             0.231378);
DECLARE_PARAMETER_RANGE_STEP(ShSmooth_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using ShSmooth_0 = parameter::from0To1<xnode_impl::smoothed_parameter_t<NV>, 
                                       1, 
                                       ShSmooth_0Range>;

template <int NV>
using ShSmooth_1 = parameter::from0To1<xnode_impl::smoothed_parameter2_t<NV>, 
                                       1, 
                                       ShSmooth_0Range>;

template <int NV>
using ShSmooth = parameter::chain<ShSmooth_InputRange, 
                                  ShSmooth_0<NV>, 
                                  ShSmooth_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(OscShapes_1Range, 
                             0., 
                             20., 
                             0.1);

template <int NV>
using OscShapes_1 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        OscShapes_1Range>;

DECLARE_PARAMETER_RANGE_STEP(OscShapes_2Range, 
                             0., 
                             32., 
                             0.1);

template <int NV>
using OscShapes_2 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        OscShapes_2Range>;

template <int NV>
using OscShapes = parameter::chain<ranges::Identity, 
                                   parameter::plain<xnode_impl::smoothed_parameter3_t<NV>, 0>, 
                                   OscShapes_1<NV>, 
                                   OscShapes_2<NV>, 
                                   parameter::plain<xnode_impl::xfader2_t<NV>, 0>, 
                                   parameter::plain<core::fm, 1>, 
                                   parameter::plain<xnode_impl::cable_table2_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(pbTYPE_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(pbTYPE_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using pbTYPE_0 = parameter::from0To1<xnode_impl::branch_t<NV>, 
                                     0, 
                                     pbTYPE_0Range>;

template <int NV>
using pbTYPE = parameter::chain<pbTYPE_InputRange, pbTYPE_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ModModeRange, 
                             0., 
                             4., 
                             1.);

template <int NV>
using ModMode = parameter::from0To1<xnode_impl::branch1_t<NV>, 
                                    0, 
                                    ModModeRange>;

template <int NV>
using UserPs = parameter::chain<ranges::Identity, 
                                parameter::plain<xnode_impl::smoothed_parameter_t<NV>, 0>, 
                                parameter::plain<xnode_impl::smoothed_parameter2_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(UserInput_InputRange, 
                             0., 
                             1., 
                             0.832689);
DECLARE_PARAMETER_RANGE_STEP(UserInput_0Range, 
                             -100., 
                             0., 
                             0.1);

template <int NV>
using UserInput_0 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        UserInput_0Range>;

DECLARE_PARAMETER_RANGE(UserInput_1Range, 
                        0., 
                        500.);

template <int NV>
using UserInput_1 = parameter::from0To1<xnode_impl::snex_node_t<NV>, 
                                        4, 
                                        UserInput_1Range>;

template <int NV>
using UserInput = parameter::chain<UserInput_InputRange, 
                                   UserInput_0<NV>, 
                                   UserInput_1<NV>, 
                                   parameter::plain<xnode_impl::snex_node_t<NV>, 6>>;

template <int NV>
using PitchSmooth = parameter::from0To1<xnode_impl::smoothed_parameter_unscaled_t<NV>, 
                                        1, 
                                        ShSmooth_0Range>;

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
using Phase = parameter::chain<ranges::Identity, 
                               parameter::plain<core::phasor<NV>, 3>, 
                               parameter::plain<xnode_impl::oscillator_t<NV>, 4>>;

template <int NV>
using FileMode_0 = parameter::from0To1<xnode_impl::branch5_t<NV>, 
                                       0, 
                                       xnode_impl::simple_ar_c0Range>;

template <int NV>
using FileMode = parameter::chain<ranges::Identity, 
                                  FileMode_0<NV>, 
                                  parameter::plain<xnode_impl::snex_node_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(PosQuant_InputRange, 
                             1., 
                             10., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(PosQuant_0Range, 
                             0., 
                             9., 
                             1.);

template <int NV>
using PosQuant_0 = parameter::from0To1<xnode_impl::branch4_t<NV>, 
                                       0, 
                                       PosQuant_0Range>;

template <int NV>
using PosQuant_1 = parameter::from0To1<xnode_impl::branch6_t<NV>, 
                                       0, 
                                       PosQuant_0Range>;

template <int NV>
using PosQuant = parameter::chain<PosQuant_InputRange, 
                                  PosQuant_0<NV>, 
                                  PosQuant_1<NV>>;

template <int NV>
using min = parameter::plain<xnode_impl::minmax_t<NV>, 
                             1>;
template <int NV>
using max = parameter::plain<xnode_impl::minmax_t<NV>, 
                             2>;
template <int NV>
using step = parameter::plain<xnode_impl::minmax_t<NV>, 
                              4>;
using GainSmooth = parameter::empty;
template <int NV>
using FxShDiv = parameter::plain<xnode_impl::tempo_sync_t<NV>, 
                                 1>;
template <int NV>
using GainReset = parameter::plain<xnode_impl::snex_node_t<NV>, 
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
using PosDiv = parameter::plain<xnode_impl::tempo_sync1_t<NV>, 
                                1>;
template <int NV>
using xnode_t_plist = parameter::list<Harm<NV>, 
                                      min<NV>, 
                                      max<NV>, 
                                      step<NV>, 
                                      Mode<NV>, 
                                      GainSmooth, 
                                      FxValue<NV>, 
                                      FxShDiv<NV>, 
                                      GainReset<NV>, 
                                      shPitch<NV>, 
                                      FilterMix<NV>, 
                                      FilterType<NV>, 
                                      FilterRes<NV>, 
                                      FilterCut<NV>, 
                                      FilterFxMod<NV>, 
                                      DET<NV>, 
                                      ShSmooth<NV>, 
                                      OscShapes<NV>, 
                                      pbTYPE<NV>, 
                                      ModMode<NV>, 
                                      UserPs<NV>, 
                                      UserInput<NV>, 
                                      PitchSmooth<NV>, 
                                      ShToGain<NV>, 
                                      Phase<NV>, 
                                      PosDiv<NV>, 
                                      FileMode<NV>, 
                                      PosQuant<NV>>;
}

template <int NV>
using xnode_t_ = container::chain<xnode_t_parameters::xnode_t_plist<NV>, 
                                  wrap::fix<2, modchain1_t<NV>>, 
                                  branch_t<NV>, 
                                  simple_ar_t<NV>, 
                                  modchain8_t<NV>, 
                                  chain_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public xnode_impl::xnode_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(xnode);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(494)
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
            0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0005, 0x0000, 0x6147, 0x6E69, 0x6D53, 0x6F6F, 0x6874, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0006, 0x0000, 0x7846, 0x6156, 0x756C, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x8000, 0xD33F, 0xAB9B, 0x003E, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x0700, 0x0000, 0x4600, 0x5378, 
            0x4468, 0x7669, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 
            0x4170, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0008, 0x0000, 
            0x6147, 0x6E69, 0x6552, 0x6573, 0x0074, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0900, 0x0000, 0x7300, 0x5068, 0x7469, 0x6863, 0x0000, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x1643, 0xBF62, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x000A, 0x0000, 0x6946, 0x746C, 0x7265, 0x694D, 
            0x0078, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x0B00, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x5472, 0x7079, 0x0065, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x0040, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0C00, 
            0x0000, 0x4600, 0x6C69, 0x6574, 0x5272, 0x7365, 0x0000, 0x999A, 
            0x3E99, 0x0000, 0x3F80, 0x999A, 0x3E99, 0x8918, 0x3E87, 0x0000, 
            0x0000, 0x005C, 0x000D, 0x0000, 0x6946, 0x746C, 0x7265, 0x7543, 
            0x0074, 0x0000, 0x8000, 0x0024, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x0E00, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x4672, 0x4D78, 0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0xBD38, 0x3BE9, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x000F, 0x0000, 0x4544, 0x0054, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x5940, 0x8148, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1000, 
            0x0000, 0x5300, 0x5368, 0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 
            0x0000, 0xFA00, 0x0044, 0x0000, 0x6900, 0x6CEE, 0xCD3E, 0xCCCC, 
            0x5C3D, 0x1100, 0x0000, 0x4F00, 0x6373, 0x6853, 0x7061, 0x7365, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0012, 0x0000, 0x6270, 0x5954, 
            0x4550, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x4080, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0013, 0x0000, 0x6F4D, 
            0x4D64, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1400, 0x0000, 
            0x5500, 0x6573, 0x5072, 0x0073, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x4E3F, 0x206F, 0x003E, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1500, 
            0x0000, 0x5500, 0x6573, 0x4972, 0x706E, 0x7475, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x6813, 0x3D0D, 0x2B15, 0x3F55, 0x0000, 
            0x0000, 0x005C, 0x0016, 0x0000, 0x6950, 0x6374, 0x5368, 0x6F6D, 
            0x746F, 0x0068, 0x0000, 0x0000, 0x0000, 0x8000, 0xB23F, 0x1890, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1700, 0x0000, 0x5300, 
            0x5468, 0x476F, 0x6961, 0x006E, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1800, 
            0x0000, 0x5000, 0x6168, 0x6573, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0019, 0x0000, 0x6F50, 0x4473, 0x7669, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x4200, 0x0000, 0x4100, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x001A, 0x0000, 0x6946, 0x656C, 0x6F4D, 0x6564, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x001B, 0x0000, 0x6F50, 0x5173, 0x6175, 
            0x746E, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4120, 0x0000, 0x40C0, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain1 = this->getT(0);                                                    // xnode_impl::modchain1_t<NV>
		auto& minmax = this->getT(0).getT(0);                                               // xnode_impl::minmax_t<NV>
		auto& pma_unscaled = this->getT(0).getT(1);                                         // xnode_impl::pma_unscaled_t<NV>
		auto& smoothed_parameter_unscaled = this->getT(0).getT(2);                          // xnode_impl::smoothed_parameter_unscaled_t<NV>
		auto& pma_unscaled1 = this->getT(0).getT(3);                                        // xnode_impl::pma_unscaled1_t<NV>
		auto& pma_unscaled2 = this->getT(0).getT(4);                                        // xnode_impl::pma_unscaled2_t<NV>
		auto& branch = this->getT(1);                                                       // xnode_impl::branch_t<NV>
		auto& chain8 = this->getT(1).getT(0);                                               // xnode_impl::chain8_t<NV>
		auto& branch3 = this->getT(1).getT(0).getT(0);                                      // xnode_impl::branch3_t<NV>
		auto& chain34 = this->getT(1).getT(0).getT(0).getT(0);                              // xnode_impl::chain34_t<NV>
		auto& xfader2 = this->getT(1).getT(0).getT(0).getT(0).getT(0);                      // xnode_impl::xfader2_t<NV>
		auto& split2 = this->getT(1).getT(0).getT(0).getT(0).getT(1);                       // xnode_impl::split2_t<NV>
		auto& chain16 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(0);              // xnode_impl::chain16_t<NV>
		auto& oscillator11 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0); // xnode_impl::oscillator11_t<NV>
		auto& gain26 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);       // core::gain<NV>
		auto& chain20 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(1);              // xnode_impl::chain20_t<NV>
		auto& oscillator12 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0); // xnode_impl::oscillator12_t<NV>
		auto& gain27 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);       // core::gain<NV>
		auto& chain11 = this->getT(1).getT(0).getT(0).getT(1);                              // xnode_impl::chain11_t<NV>
		auto& oscillator9 = this->getT(1).getT(0).getT(0).getT(1).getT(0);                  // xnode_impl::oscillator9_t<NV>
		auto& smoothed_parameter3 = this->getT(1).getT(0).getT(0).getT(1).getT(1);          // xnode_impl::smoothed_parameter3_t<NV>
		auto& pi7 = this->getT(1).getT(0).getT(0).getT(1).getT(2);                          // math::pi<NV>
		auto& sin1 = this->getT(1).getT(0).getT(0).getT(1).getT(3);                         // math::sin<NV>
		auto& chain12 = this->getT(1).getT(0).getT(0).getT(2);                              // xnode_impl::chain12_t<NV>
		auto& phasor = this->getT(1).getT(0).getT(0).getT(2).getT(0);                       // core::phasor<NV>
		auto& mono2stereo4 = this->getT(1).getT(0).getT(0).getT(2).getT(1);                 // core::mono2stereo
		auto& gain4 = this->getT(1).getT(0).getT(0).getT(2).getT(2);                        // core::gain<NV>
		auto& fmod1 = this->getT(1).getT(0).getT(0).getT(2).getT(3);                        // math::fmod<NV>
		auto& chain13 = this->getT(1).getT(0).getT(0).getT(3);                              // xnode_impl::chain13_t<NV>
		auto& oscillator14 = this->getT(1).getT(0).getT(0).getT(3).getT(0);                 // xnode_impl::oscillator14_t<NV>
		auto& phasor_fm = this->getT(1).getT(0).getT(0).getT(3).getT(1);                    // wrap::no_process<core::phasor_fm<NV>>
		auto& fm = this->getT(1).getT(0).getT(0).getT(3).getT(2);                           // core::fm
		auto& mono2stereo2 = this->getT(1).getT(0).getT(0).getT(3).getT(3);                 // core::mono2stereo
		auto& chain22 = this->getT(1).getT(0).getT(0).getT(4);                              // xnode_impl::chain22_t<NV>
		auto& phasor4 = this->getT(1).getT(0).getT(0).getT(4).getT(0);                      // core::phasor<NV>
		auto& mono2stereo3 = this->getT(1).getT(0).getT(0).getT(4).getT(1);                 // core::mono2stereo
		auto& gain6 = this->getT(1).getT(0).getT(0).getT(4).getT(2);                        // core::gain<NV>
		auto& pi1 = this->getT(1).getT(0).getT(0).getT(4).getT(3);                          // math::pi<NV>
		auto& rect1 = this->getT(1).getT(0).getT(0).getT(4).getT(4);                        // math::rect<NV>
		auto& chain45 = this->getT(1).getT(0).getT(0).getT(5);                              // xnode_impl::chain45_t<NV>
		auto& chain2 = this->getT(1).getT(0).getT(0).getT(5).getT(0);                       // xnode_impl::chain2_t<NV>
		auto& oscillator13 = this->getT(1).getT(0).getT(0).getT(5).getT(0).getT(0);         // xnode_impl::oscillator13_t<NV>
		auto& cable_table1 = this->getT(1).getT(0).getT(0).getT(5).getT(1);                 // xnode_impl::cable_table1_t<NV>
		auto& cable_table2 = this->getT(1).getT(0).getT(0).getT(5).getT(2);                 // xnode_impl::cable_table2_t<NV>
		auto& tempo_sync2 = this->getT(1).getT(0).getT(0).getT(5).getT(3);                  // xnode_impl::tempo_sync2_t<NV>
		auto& sampleandhold2 = this->getT(1).getT(0).getT(0).getT(5).getT(4);               // fx::sampleandhold<NV>
		auto& chain15 = this->getT(1).getT(1);                                              // xnode_impl::chain15_t<NV>
		auto& chain37 = this->getT(1).getT(1).getT(0);                                      // xnode_impl::chain37_t<NV>
		auto& file_player5 = this->getT(1).getT(1).getT(0).getT(0);                         // xnode_impl::file_player5_t<NV>
		auto& fmod = this->getT(1).getT(1).getT(0).getT(1);                                 // wrap::no_process<math::fmod<NV>>
		auto& pi2 = this->getT(1).getT(1).getT(0).getT(2);                                  // wrap::no_process<math::pi<NV>>
		auto& chain14 = this->getT(1).getT(2);                                              // xnode_impl::chain14_t<NV>
		auto& modchain = this->getT(1).getT(2).getT(0);                                     // xnode_impl::modchain_t<NV>
		auto& tempo_sync1 = this->getT(1).getT(2).getT(0).getT(0);                          // xnode_impl::tempo_sync1_t<NV>
		auto& chain43 = this->getT(1).getT(2).getT(1);                                      // xnode_impl::chain43_t<NV>
		auto& branch5 = this->getT(1).getT(2).getT(1).getT(0);                              // xnode_impl::branch5_t<NV>
		auto& chain17 = this->getT(1).getT(2).getT(1).getT(0).getT(0);                      // xnode_impl::chain17_t<NV>
		auto& phasor5 = this->getT(1).getT(2).getT(1).getT(0).getT(0).getT(0);              // core::phasor<NV>
		auto& chain18 = this->getT(1).getT(2).getT(1).getT(0).getT(1);                      // xnode_impl::chain18_t<NV>
		auto& converter1 = this->getT(1).getT(2).getT(1).getT(0).getT(1).getT(0);           // xnode_impl::converter1_t<NV>
		auto& phasor6 = this->getT(1).getT(2).getT(1).getT(0).getT(1).getT(1);              // core::phasor<NV>
		auto& gain11 = this->getT(1).getT(2).getT(1).getT(1);                               // core::gain<NV>
		auto& chain9 = this->getT(1).getT(2).getT(1).getT(2);                               // xnode_impl::chain9_t<NV>
		auto& smoothed_parameter = this->getT(1).getT(2).getT(1).getT(2).getT(0);           // xnode_impl::smoothed_parameter_t<NV>
		auto& branch4 = this->getT(1).getT(2).getT(1).getT(2).getT(1);                      // xnode_impl::branch4_t<NV>
		auto& add1 = this->getT(1).getT(2).getT(1).getT(2).getT(1).getT(0);                 // math::add<NV>
		auto& add4 = this->getT(1).getT(2).getT(1).getT(2).getT(1).getT(1);                 // math::add<NV>
		auto& add11 = this->getT(1).getT(2).getT(1).getT(2).getT(1).getT(2);                // math::add<NV>
		auto& add3 = this->getT(1).getT(2).getT(1).getT(2).getT(1).getT(3);                 // math::add<NV>
		auto& add10 = this->getT(1).getT(2).getT(1).getT(2).getT(1).getT(4);                // math::add<NV>
		auto& add5 = this->getT(1).getT(2).getT(1).getT(2).getT(1).getT(5);                 // math::add<NV>
		auto& add6 = this->getT(1).getT(2).getT(1).getT(2).getT(1).getT(6);                 // math::add<NV>
		auto& add7 = this->getT(1).getT(2).getT(1).getT(2).getT(1).getT(7);                 // math::add<NV>
		auto& add8 = this->getT(1).getT(2).getT(1).getT(2).getT(1).getT(8);                 // math::add<NV>
		auto& add9 = this->getT(1).getT(2).getT(1).getT(2).getT(1).getT(9);                 // math::add<NV>
		auto& file_player6 = this->getT(1).getT(2).getT(1).getT(3);                         // xnode_impl::file_player6_t<NV>
		auto& chain19 = this->getT(1).getT(3);                                              // xnode_impl::chain19_t<NV>
		auto& modchain3 = this->getT(1).getT(3).getT(0);                                    // xnode_impl::modchain3_t<NV>
		auto& chain26 = this->getT(1).getT(3).getT(0).getT(0);                              // xnode_impl::chain26_t<NV>
		auto& smoothed_parameter2 = this->getT(1).getT(3).getT(0).getT(0).getT(0);          // xnode_impl::smoothed_parameter2_t<NV>
		auto& branch6 = this->getT(1).getT(3).getT(0).getT(0).getT(1);                      // xnode_impl::branch6_t<NV>
		auto& add13 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(0);                // math::add<NV>
		auto& add14 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(1);                // math::add<NV>
		auto& add15 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(2);                // math::add<NV>
		auto& add16 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(3);                // math::add<NV>
		auto& add17 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(4);                // math::add<NV>
		auto& add18 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(5);                // math::add<NV>
		auto& add19 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(6);                // math::add<NV>
		auto& add20 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(7);                // math::add<NV>
		auto& add21 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(8);                // math::add<NV>
		auto& add22 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(9);                // math::add<NV>
		auto& peak2 = this->getT(1).getT(3).getT(0).getT(1);                                // xnode_impl::peak2_t<NV>
		auto& snex_node = this->getT(1).getT(3).getT(1);                                    // xnode_impl::snex_node_t<NV>
		auto& simple_ar = this->getT(2);                                                    // xnode_impl::simple_ar_t<NV>
		auto& modchain8 = this->getT(3);                                                    // xnode_impl::modchain8_t<NV>
		auto& no_midi = this->getT(3).getT(0);                                              // xnode_impl::no_midi_t<NV>
		auto& tempo_sync = this->getT(3).getT(0).getT(0);                                   // xnode_impl::tempo_sync_t<NV>
		auto& converter = this->getT(3).getT(0).getT(1);                                    // xnode_impl::converter_t<NV>
		auto& phasor1 = this->getT(3).getT(0).getT(2);                                      // core::phasor<NV>
		auto& peak1 = this->getT(3).getT(1);                                                // xnode_impl::peak1_t<NV>
		auto& clear2 = this->getT(3).getT(2);                                               // math::clear<NV>
		auto& branch1 = this->getT(3).getT(3);                                              // xnode_impl::branch1_t<NV>
		auto& chain1 = this->getT(3).getT(3).getT(0);                                       // xnode_impl::chain1_t
		auto& chain21 = this->getT(3).getT(3).getT(1);                                      // xnode_impl::chain21_t<NV>
		auto& clear = this->getT(3).getT(3).getT(1).getT(0);                                // math::clear<NV>
		auto& sig2mod2 = this->getT(3).getT(3).getT(1).getT(1);                             // wrap::no_process<math::sig2mod<NV>>
		auto& oscillator = this->getT(3).getT(3).getT(1).getT(2);                           // xnode_impl::oscillator_t<NV>
		auto& sampleandhold1 = this->getT(3).getT(3).getT(1).getT(3);                       // fx::sampleandhold<NV>
		auto& chain23 = this->getT(3).getT(3).getT(2);                                      // xnode_impl::chain23_t<NV>
		auto& chain10 = this->getT(3).getT(3).getT(2).getT(0);                              // xnode_impl::chain10_t<NV>
		auto& add12 = this->getT(3).getT(3).getT(2).getT(0).getT(0);                        // math::add<NV>
		auto& pi = this->getT(3).getT(3).getT(2).getT(0).getT(1);                           // math::pi<NV>
		auto& sin2 = this->getT(3).getT(3).getT(2).getT(0).getT(2);                         // math::sin<NV>
		auto& chain24 = this->getT(3).getT(3).getT(3);                                      // xnode_impl::chain24_t<NV>
		auto& chain25 = this->getT(3).getT(3).getT(3).getT(0);                              // xnode_impl::chain25_t<NV>
		auto& add2 = this->getT(3).getT(3).getT(3).getT(0).getT(0);                         // math::add<NV>
		auto& mod_inv1 = this->getT(3).getT(3).getT(3).getT(0).getT(1);                     // math::mod_inv<NV>
		auto& chain27 = this->getT(3).getT(3).getT(4);                                      // xnode_impl::chain27_t<NV>
		auto& chain28 = this->getT(3).getT(3).getT(4).getT(0);                              // xnode_impl::chain28_t<NV>
		auto& cable_table3 = this->getT(3).getT(3).getT(4).getT(0).getT(0);                 // xnode_impl::cable_table3_t<NV>
		auto& add = this->getT(3).getT(3).getT(4).getT(0).getT(1);                          // math::add<NV>
		auto& peak = this->getT(3).getT(4);                                                 // xnode_impl::peak_t<NV>
		auto& chain = this->getT(4);                                                        // xnode_impl::chain_t<NV>
		auto& chain4 = this->getT(4).getT(0);                                               // xnode_impl::chain4_t<NV>
		auto& xfader1 = this->getT(4).getT(0).getT(0);                                      // xnode_impl::xfader1_t<NV>
		auto& split1 = this->getT(4).getT(0).getT(1);                                       // xnode_impl::split1_t<NV>
		auto& chain5 = this->getT(4).getT(0).getT(1).getT(0);                               // xnode_impl::chain5_t<NV>
		auto& gain2 = this->getT(4).getT(0).getT(1).getT(0).getT(0);                        // core::gain<NV>
		auto& chain6 = this->getT(4).getT(0).getT(1).getT(1);                               // xnode_impl::chain6_t<NV>
		auto& modchain2 = this->getT(4).getT(0).getT(1).getT(1).getT(0);                    // xnode_impl::modchain2_t<NV>
		auto& smoothed_parameter1 = this->getT(4).getT(0).getT(1).getT(1).getT(0).getT(0);  // xnode_impl::smoothed_parameter1_t<NV>
		auto& pma = this->getT(4).getT(0).getT(1).getT(1).getT(0).getT(1);                  // xnode_impl::pma_t<NV>
		auto& branch2 = this->getT(4).getT(0).getT(1).getT(1).getT(1);                      // xnode_impl::branch2_t<NV>
		auto& chain7 = this->getT(4).getT(0).getT(1).getT(1).getT(1).getT(0);               // xnode_impl::chain7_t
		auto& svf = this->getT(4).getT(0).getT(1).getT(1).getT(1).getT(1);                  // filters::svf<NV>
		auto& svf2 = this->getT(4).getT(0).getT(1).getT(1).getT(1).getT(2);                 // filters::svf<NV>
		auto& svf1 = this->getT(4).getT(0).getT(1).getT(1).getT(1).getT(3);                 // filters::svf<NV>
		auto& chain3 = this->getT(4).getT(0).getT(1).getT(1).getT(1).getT(4);               // xnode_impl::chain3_t<NV>
		auto& allpass = this->getT(4).getT(0).getT(1).getT(1).getT(1).getT(4).getT(0);      // filters::allpass<NV>
		auto& tanh1 = this->getT(4).getT(0).getT(1).getT(1).getT(1).getT(4).getT(1);        // wrap::no_process<math::tanh<NV>>
		auto& gain3 = this->getT(4).getT(0).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& modchain7 = this->getT(4).getT(1);                                            // xnode_impl::modchain7_t<NV>
		auto& chain40 = this->getT(4).getT(1).getT(0);                                      // xnode_impl::chain40_t<NV>
		auto& cable_table = this->getT(4).getT(1).getT(0).getT(0);                          // xnode_impl::cable_table_t<NV>
		auto& pma1 = this->getT(4).getT(1).getT(0).getT(1);                                 // xnode_impl::pma1_t<NV>
		auto& gain9 = this->getT(4).getT(2);                                                // core::gain<NV>
		auto& gain5 = this->getT(4).getT(3);                                                // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain45.getParameterT(0).connectT(0, cable_table1); // harm -> cable_table1::Value
		chain45.getParameterT(0).connectT(0, cable_table1); // harm -> cable_table1::Value
		auto& Harm_p = this->getParameterT(0);
		Harm_p.connectT(0, minmax);      // Harm -> minmax::Value
		Harm_p.connectT(1, tempo_sync1); // Harm -> tempo_sync1::Tempo
		
		this->getParameterT(1).connectT(0, minmax); // min -> minmax::Minimum
		
		this->getParameterT(2).connectT(0, minmax); // max -> minmax::Maximum
		
		this->getParameterT(3).connectT(0, minmax); // step -> minmax::Step
		
		this->getParameterT(4).connectT(0, branch3); // Mode -> branch3::Index
		
		auto& FxValue_p = this->getParameterT(6);
		FxValue_p.connectT(0, tempo_sync); // FxValue -> tempo_sync::Tempo
		FxValue_p.connectT(1, tempo_sync); // FxValue -> tempo_sync::UnsyncedTime
		
		this->getParameterT(7).connectT(0, tempo_sync); // FxShDiv -> tempo_sync::Multiplier
		
		this->getParameterT(8).connectT(0, snex_node); // GainReset -> snex_node::freeze
		
		auto& shPitch_p = this->getParameterT(9);
		shPitch_p.connectT(0, pma_unscaled1); // shPitch -> pma_unscaled1::Multiply
		shPitch_p.connectT(1, pma_unscaled2); // shPitch -> pma_unscaled2::Multiply
		
		this->getParameterT(10).connectT(0, xfader1); // FilterMix -> xfader1::Value
		
		this->getParameterT(11).connectT(0, branch2); // FilterType -> branch2::Index
		
		auto& FilterRes_p = this->getParameterT(12);
		FilterRes_p.connectT(0, svf);     // FilterRes -> svf::Q
		FilterRes_p.connectT(1, svf2);    // FilterRes -> svf2::Q
		FilterRes_p.connectT(2, svf1);    // FilterRes -> svf1::Q
		FilterRes_p.connectT(3, allpass); // FilterRes -> allpass::Q
		
		this->getParameterT(13).connectT(0, pma); // FilterCut -> pma::Add
		
		this->getParameterT(14).connectT(0, pma); // FilterFxMod -> pma::Multiply
		
		this->getParameterT(15).connectT(0, pma_unscaled); // DET -> pma_unscaled::Multiply
		
		auto& ShSmooth_p = this->getParameterT(16);
		ShSmooth_p.connectT(0, smoothed_parameter);  // ShSmooth -> smoothed_parameter::SmoothingTime
		ShSmooth_p.connectT(1, smoothed_parameter2); // ShSmooth -> smoothed_parameter2::SmoothingTime
		
		auto& OscShapes_p = this->getParameterT(17);
		OscShapes_p.connectT(0, smoothed_parameter3); // OscShapes -> smoothed_parameter3::Value
		OscShapes_p.connectT(1, gain4);               // OscShapes -> gain4::Gain
		OscShapes_p.connectT(2, gain6);               // OscShapes -> gain6::Gain
		OscShapes_p.connectT(3, xfader2);             // OscShapes -> xfader2::Value
		OscShapes_p.connectT(4, fm);                  // OscShapes -> fm::Modulator
		OscShapes_p.connectT(5, cable_table2);        // OscShapes -> cable_table2::Value
		
		this->getParameterT(18).connectT(0, branch); // pbTYPE -> branch::Index
		
		this->getParameterT(19).connectT(0, branch1); // ModMode -> branch1::Index
		
		auto& UserPs_p = this->getParameterT(20);
		UserPs_p.connectT(0, smoothed_parameter);  // UserPs -> smoothed_parameter::Value
		UserPs_p.connectT(1, smoothed_parameter2); // UserPs -> smoothed_parameter2::Value
		
		auto& UserInput_p = this->getParameterT(21);
		UserInput_p.connectT(0, gain11);    // UserInput -> gain11::Gain
		UserInput_p.connectT(1, snex_node); // UserInput -> snex_node::grainSize
		UserInput_p.connectT(2, snex_node); // UserInput -> snex_node::loopEnd
		
		this->getParameterT(22).connectT(0, smoothed_parameter_unscaled); // PitchSmooth -> smoothed_parameter_unscaled::SmoothingTime
		
		auto& ShToGain_p = this->getParameterT(23);
		ShToGain_p.connectT(0, pma1);        // ShToGain -> pma1::Multiply
		ShToGain_p.connectT(1, cable_table); // ShToGain -> cable_table::Value
		
		auto& Phase_p = this->getParameterT(24);
		Phase_p.connectT(0, phasor1);    // Phase -> phasor1::Phase
		Phase_p.connectT(1, oscillator); // Phase -> oscillator::Phase
		
		this->getParameterT(25).connectT(0, tempo_sync1); // PosDiv -> tempo_sync1::Multiplier
		
		auto& FileMode_p = this->getParameterT(26);
		FileMode_p.connectT(0, branch5);   // FileMode -> branch5::Index
		FileMode_p.connectT(1, snex_node); // FileMode -> snex_node::Loop
		
		auto& PosQuant_p = this->getParameterT(27);
		PosQuant_p.connectT(0, branch4); // PosQuant -> branch4::Index
		PosQuant_p.connectT(1, branch6); // PosQuant -> branch6::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		tempo_sync2.getParameter().connectT(0, sampleandhold2);                    // tempo_sync2 -> sampleandhold2::Counter
		cable_table1.getWrappedObject().getParameter().connectT(0, tempo_sync2);   // cable_table1 -> tempo_sync2::Multiplier
		cable_table2.getWrappedObject().getParameter().connectT(0, tempo_sync2);   // cable_table2 -> tempo_sync2::Tempo
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
		pma_unscaled1.getWrappedObject().getParameter().connectT(10, phasor_fm);   // pma_unscaled1 -> phasor_fm::FreqRatio
		pma_unscaled2.getWrappedObject().getParameter().connectT(0, snex_node);    // pma_unscaled2 -> snex_node::FreqRatio
		pma_unscaled.getWrappedObject().getParameter().connectT(0, pma_unscaled1); // pma_unscaled -> pma_unscaled1::Add
		pma_unscaled.getWrappedObject().getParameter().connectT(1, pma_unscaled2); // pma_unscaled -> pma_unscaled2::Add
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled);        // minmax -> pma_unscaled::Add
		smoothed_parameter_unscaled.getParameter().connectT(0, pma_unscaled1);     // smoothed_parameter_unscaled -> pma_unscaled1::Value
		smoothed_parameter_unscaled.getParameter().connectT(1, pma_unscaled2);     // smoothed_parameter_unscaled -> pma_unscaled2::Value
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, gain26);                    // xfader2 -> gain26::Gain
		xfader2_p.getParameterT(1).connectT(0, gain27);                    // xfader2 -> gain27::Gain
		smoothed_parameter3.getParameter().connectT(0, pi7);               // smoothed_parameter3 -> pi7::Value
		converter1.getWrappedObject().getParameter().connectT(0, phasor6); // converter1 -> phasor6::Frequency
		tempo_sync1.getParameter().connectT(0, converter1);                // tempo_sync1 -> converter1::Value
		smoothed_parameter.getParameter().connectT(0, add1);               // smoothed_parameter -> add1::Value
		smoothed_parameter.getParameter().connectT(1, add4);               // smoothed_parameter -> add4::Value
		smoothed_parameter.getParameter().connectT(2, add11);              // smoothed_parameter -> add11::Value
		smoothed_parameter.getParameter().connectT(3, add3);               // smoothed_parameter -> add3::Value
		smoothed_parameter.getParameter().connectT(4, add10);              // smoothed_parameter -> add10::Value
		smoothed_parameter.getParameter().connectT(5, add5);               // smoothed_parameter -> add5::Value
		smoothed_parameter.getParameter().connectT(6, add6);               // smoothed_parameter -> add6::Value
		smoothed_parameter.getParameter().connectT(7, add7);               // smoothed_parameter -> add7::Value
		smoothed_parameter.getParameter().connectT(8, add8);               // smoothed_parameter -> add8::Value
		smoothed_parameter.getParameter().connectT(9, add9);               // smoothed_parameter -> add9::Value
		smoothed_parameter2.getParameter().connectT(0, add13);             // smoothed_parameter2 -> add13::Value
		smoothed_parameter2.getParameter().connectT(1, add14);             // smoothed_parameter2 -> add14::Value
		smoothed_parameter2.getParameter().connectT(2, add15);             // smoothed_parameter2 -> add15::Value
		smoothed_parameter2.getParameter().connectT(3, add16);             // smoothed_parameter2 -> add16::Value
		smoothed_parameter2.getParameter().connectT(4, add17);             // smoothed_parameter2 -> add17::Value
		smoothed_parameter2.getParameter().connectT(5, add18);             // smoothed_parameter2 -> add18::Value
		smoothed_parameter2.getParameter().connectT(6, add19);             // smoothed_parameter2 -> add19::Value
		smoothed_parameter2.getParameter().connectT(7, add20);             // smoothed_parameter2 -> add20::Value
		smoothed_parameter2.getParameter().connectT(8, add21);             // smoothed_parameter2 -> add21::Value
		smoothed_parameter2.getParameter().connectT(9, add22);             // smoothed_parameter2 -> add22::Value
		peak2.getParameter().connectT(0, snex_node);                       // peak2 -> snex_node::scrub
		peak2.getParameter().connectT(1, snex_node);                       // peak2 -> snex_node::loopStart
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		simple_ar_p.getParameterT(0).connectT(0, phasor1);                // simple_ar -> phasor1::Gate
		converter.getWrappedObject().getParameter().connectT(0, phasor1); // converter -> phasor1::Frequency
		tempo_sync.getParameter().connectT(0, sampleandhold1);            // tempo_sync -> sampleandhold1::Counter
		tempo_sync.getParameter().connectT(1, converter);                 // tempo_sync -> converter::Value
		cable_table3.getWrappedObject().getParameter().connectT(0, add);  // cable_table3 -> add::Value
		peak1.getParameter().connectT(0, cable_table3);                   // peak1 -> cable_table3::Value
		peak1.getParameter().connectT(1, add2);                           // peak1 -> add2::Value
		peak1.getParameter().connectT(2, add12);                          // peak1 -> add12::Value
		pma1.getWrappedObject().getParameter().connectT(0, gain9);        // pma1 -> gain9::Gain
		pma.getWrappedObject().getParameter().connectT(0, svf);           // pma -> svf::Frequency
		pma.getWrappedObject().getParameter().connectT(1, svf2);          // pma -> svf2::Frequency
		pma.getWrappedObject().getParameter().connectT(2, svf1);          // pma -> svf1::Frequency
		pma.getWrappedObject().getParameter().connectT(3, allpass);       // pma -> allpass::Frequency
		smoothed_parameter1.getParameter().connectT(0, pma);              // smoothed_parameter1 -> pma::Value
		peak.getParameter().connectT(0, pma1);                            // peak -> pma1::Value
		peak.getParameter().connectT(1, smoothed_parameter_unscaled);     // peak -> smoothed_parameter_unscaled::Value
		peak.getParameter().connectT(2, smoothed_parameter1);             // peak -> smoothed_parameter1::Value
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
		
		pma_unscaled.setParameterT(0, 1.); // control::pma_unscaled::Value
		;                                  // pma_unscaled::Multiply is automated
		;                                  // pma_unscaled::Add is automated
		
		;                                                 // smoothed_parameter_unscaled::Value is automated
		;                                                 // smoothed_parameter_unscaled::SmoothingTime is automated
		smoothed_parameter_unscaled.setParameterT(2, 1.); // control::smoothed_parameter_unscaled::Enabled
		
		; // pma_unscaled1::Value is automated
		; // pma_unscaled1::Multiply is automated
		; // pma_unscaled1::Add is automated
		
		; // pma_unscaled2::Value is automated
		; // pma_unscaled2::Multiply is automated
		; // pma_unscaled2::Add is automated
		
		; // branch::Index is automated
		
		; // branch3::Index is automated
		
		; // xfader2::Value is automated
		
		oscillator11.setParameterT(0, 2.);   // core::oscillator::Mode
		oscillator11.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                    // oscillator11::FreqRatio is automated
		oscillator11.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator11.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator11.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                               // gain26::Gain is automated
		gain26.setParameterT(1, 5.8);   // core::gain::Smoothing
		gain26.setParameterT(2, -100.); // core::gain::ResetValue
		
		oscillator12.setParameterT(0, 0.);       // core::oscillator::Mode
		oscillator12.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                        // oscillator12::FreqRatio is automated
		oscillator12.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator12.setParameterT(4, 0.533075); // core::oscillator::Phase
		oscillator12.setParameterT(5, 1.);       // core::oscillator::Gain
		
		;                               // gain27::Gain is automated
		gain27.setParameterT(1, 6.9);   // core::gain::Smoothing
		gain27.setParameterT(2, -100.); // core::gain::ResetValue
		
		oscillator9.setParameterT(0, 2.);   // core::oscillator::Mode
		oscillator9.setParameterT(1, 220.); // core::oscillator::Frequency
		;                                   // oscillator9::FreqRatio is automated
		oscillator9.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator9.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator9.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                                         // smoothed_parameter3::Value is automated
		smoothed_parameter3.setParameterT(1, 0.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // pi7::Value is automated
		
		sin1.setParameterT(0, 1.); // math::sin::Value
		
		phasor.setParameterT(0, 1.);   // core::phasor::Gate
		phasor.setParameterT(1, 110.); // core::phasor::Frequency
		;                              // phasor::FreqRatio is automated
		phasor.setParameterT(3, 0.);   // core::phasor::Phase
		
		;                             // gain4::Gain is automated
		gain4.setParameterT(1, 6.1);  // core::gain::Smoothing
		gain4.setParameterT(2, -10.); // core::gain::ResetValue
		
		fmod1.setParameterT(0, 1.); // math::fmod::Value
		
		oscillator14.setParameterT(0, 0.);    // core::oscillator::Mode
		oscillator14.setParameterT(1, 134.9); // core::oscillator::Frequency
		;                                     // oscillator14::FreqRatio is automated
		oscillator14.setParameterT(3, 1.);    // core::oscillator::Gate
		oscillator14.setParameterT(4, 0.);    // core::oscillator::Phase
		oscillator14.setParameterT(5, 1.);    // core::oscillator::Gain
		
		phasor_fm.setParameterT(0, 1.);       // core::phasor_fm::Gate
		phasor_fm.setParameterT(1, 110.);     // core::phasor_fm::Frequency
		;                                     // phasor_fm::FreqRatio is automated
		phasor_fm.setParameterT(3, 0.526439); // core::phasor_fm::Phase
		
		fm.setParameterT(0, 110.); // core::fm::Frequency
		;                          // fm::Modulator is automated
		;                          // fm::FreqMultiplier is automated
		fm.setParameterT(3, 1.);   // core::fm::Gate
		
		phasor4.setParameterT(0, 1.);   // core::phasor::Gate
		phasor4.setParameterT(1, 220.); // core::phasor::Frequency
		;                               // phasor4::FreqRatio is automated
		phasor4.setParameterT(3, 0.);   // core::phasor::Phase
		
		;                             // gain6::Gain is automated
		gain6.setParameterT(1, 89.5); // core::gain::Smoothing
		gain6.setParameterT(2, -13.); // core::gain::ResetValue
		
		pi1.setParameterT(0, 0.499955); // math::pi::Value
		
		rect1.setParameterT(0, 0.); // math::rect::Value
		
		; // chain45::harm is automated
		
		oscillator13.setParameterT(0, 4.);        // core::oscillator::Mode
		oscillator13.setParameterT(1, 220.);      // core::oscillator::Frequency
		oscillator13.setParameterT(2, 0.);        // core::oscillator::FreqRatio
		oscillator13.setParameterT(3, 1.);        // core::oscillator::Gate
		oscillator13.setParameterT(4, 0.0379688); // core::oscillator::Phase
		oscillator13.setParameterT(5, 1.);        // core::oscillator::Gain
		
		; // cable_table1::Value is automated
		
		; // cable_table2::Value is automated
		
		;                                   // tempo_sync2::Tempo is automated
		;                                   // tempo_sync2::Multiplier is automated
		tempo_sync2.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync2.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // sampleandhold2::Counter is automated
		
		file_player5.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player5.setParameterT(1, 1.);   // core::file_player::Gate
		file_player5.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player5::FreqRatio is automated
		
		fmod.setParameterT(0, 0.85461); // math::fmod::Value
		
		pi2.setParameterT(0, 0.61253); // math::pi::Value
		
		;                                   // tempo_sync1::Tempo is automated
		;                                   // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // branch5::Index is automated
		
		phasor5.setParameterT(0, 1.);   // core::phasor::Gate
		phasor5.setParameterT(1, 220.); // core::phasor::Frequency
		;                               // phasor5::FreqRatio is automated
		phasor5.setParameterT(3, 0.);   // core::phasor::Phase
		
		; // converter1::Value is automated
		
		phasor6.setParameterT(0, 1.); // core::phasor::Gate
		;                             // phasor6::Frequency is automated
		phasor6.setParameterT(2, 1.); // core::phasor::FreqRatio
		phasor6.setParameterT(3, 0.); // core::phasor::Phase
		
		;                              // gain11::Gain is automated
		gain11.setParameterT(1, 0.);   // core::gain::Smoothing
		gain11.setParameterT(2, -27.); // core::gain::ResetValue
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // branch4::Index is automated
		
		; // add1::Value is automated
		
		; // add4::Value is automated
		
		; // add11::Value is automated
		
		; // add3::Value is automated
		
		; // add10::Value is automated
		
		; // add5::Value is automated
		
		; // add6::Value is automated
		
		; // add7::Value is automated
		
		; // add8::Value is automated
		
		; // add9::Value is automated
		
		file_player6.setParameterT(0, 1.);   // core::file_player::PlaybackMode
		file_player6.setParameterT(1, 1.);   // core::file_player::Gate
		file_player6.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player6.setParameterT(3, 1.);   // core::file_player::FreqRatio
		
		;                                         // smoothed_parameter2::Value is automated
		;                                         // smoothed_parameter2::SmoothingTime is automated
		smoothed_parameter2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // branch6::Index is automated
		
		; // add13::Value is automated
		
		; // add14::Value is automated
		
		; // add15::Value is automated
		
		; // add16::Value is automated
		
		; // add17::Value is automated
		
		; // add18::Value is automated
		
		; // add19::Value is automated
		
		; // add20::Value is automated
		
		; // add21::Value is automated
		
		; // add22::Value is automated
		
		;                               // snex_node::FreqRatio is automated
		;                               // snex_node::Loop is automated
		;                               // snex_node::freeze is automated
		;                               // snex_node::scrub is automated
		;                               // snex_node::grainSize is automated
		;                               // snex_node::loopStart is automated
		;                               // snex_node::loopEnd is automated
		snex_node.setParameterT(7, 0.); // core::snex_node::scrubMode
		
		simple_ar.setParameterT(0, 0.);    // envelope::simple_ar::Attack
		simple_ar.setParameterT(1, 1000.); // envelope::simple_ar::Release
		simple_ar.setParameterT(2, 0.);    // envelope::simple_ar::Gate
		simple_ar.setParameterT(3, 0.);    // envelope::simple_ar::AttackCurve
		
		;                                // tempo_sync::Tempo is automated
		;                                // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.); // control::tempo_sync::Enabled
		;                                // tempo_sync::UnsyncedTime is automated
		
		; // converter::Value is automated
		
		;                             // phasor1::Gate is automated
		;                             // phasor1::Frequency is automated
		phasor1.setParameterT(2, 1.); // core::phasor::FreqRatio
		;                             // phasor1::Phase is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // branch1::Index is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		sig2mod2.setParameterT(0, 0.); // math::sig2mod::Value
		
		oscillator.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		;                                  // oscillator::Phase is automated
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		; // sampleandhold1::Counter is automated
		
		; // add12::Value is automated
		
		pi.setParameterT(0, 1.); // math::pi::Value
		
		sin2.setParameterT(0, 2.); // math::sin::Value
		
		; // add2::Value is automated
		
		mod_inv1.setParameterT(0, 0.); // math::mod_inv::Value
		
		; // cable_table3::Value is automated
		
		; // add::Value is automated
		
		; // xfader1::Value is automated
		
		;                             // gain2::Gain is automated
		gain2.setParameterT(1, 10.3); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                                         // smoothed_parameter1::Value is automated
		smoothed_parameter1.setParameterT(1, 0.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // branch2::Index is automated
		
		;                         // svf::Frequency is automated
		;                         // svf::Q is automated
		svf.setParameterT(2, 0.); // filters::svf::Gain
		svf.setParameterT(3, 0.); // filters::svf::Smoothing
		svf.setParameterT(4, 0.); // filters::svf::Mode
		svf.setParameterT(5, 1.); // filters::svf::Enabled
		
		;                          // svf2::Frequency is automated
		;                          // svf2::Q is automated
		svf2.setParameterT(2, 0.); // filters::svf::Gain
		svf2.setParameterT(3, 0.); // filters::svf::Smoothing
		svf2.setParameterT(4, 1.); // filters::svf::Mode
		svf2.setParameterT(5, 1.); // filters::svf::Enabled
		
		;                          // svf1::Frequency is automated
		;                          // svf1::Q is automated
		svf1.setParameterT(2, 0.); // filters::svf::Gain
		svf1.setParameterT(3, 0.); // filters::svf::Smoothing
		svf1.setParameterT(4, 2.); // filters::svf::Mode
		svf1.setParameterT(5, 1.); // filters::svf::Enabled
		
		;                             // allpass::Frequency is automated
		;                             // allpass::Q is automated
		allpass.setParameterT(2, 0.); // filters::allpass::Gain
		allpass.setParameterT(3, 0.); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.); // filters::allpass::Mode
		allpass.setParameterT(5, 1.); // filters::allpass::Enabled
		
		tanh1.setParameterT(0, 1.); // math::tanh::Value
		
		;                            // gain3::Gain is automated
		gain3.setParameterT(1, 9.5); // core::gain::Smoothing
		gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // cable_table::Value is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		;                             // gain9::Gain is automated
		gain9.setParameterT(1, 0.5);  // core::gain::Smoothing
		gain9.setParameterT(2, -11.); // core::gain::ResetValue
		
		gain5.setParameterT(0, -23.);  // core::gain::Gain
		gain5.setParameterT(1, 0.);    // core::gain::Smoothing
		gain5.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 16.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.335173);
		this->setParameterT(7, 15.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, -0.883152);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 3.);
		this->setParameterT(12, 0.3);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 0.00713315);
		this->setParameterT(15, 1.01002);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 4.);
		this->setParameterT(19, 1.);
		this->setParameterT(20, 0.156675);
		this->setParameterT(21, 0.0345231);
		this->setParameterT(22, 0.595958);
		this->setParameterT(23, 1.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 8.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 6.);
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
		
		this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index); // xnode_impl::oscillator11_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).setExternalData(b, index); // xnode_impl::oscillator12_t<NV>
		this->getT(1).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);                 // xnode_impl::oscillator9_t<NV>
		this->getT(1).getT(0).getT(0).getT(3).getT(0).setExternalData(b, index);                 // xnode_impl::oscillator14_t<NV>
		this->getT(1).getT(0).getT(0).getT(5).getT(0).getT(0).setExternalData(b, index);         // xnode_impl::oscillator13_t<NV>
		this->getT(1).getT(0).getT(0).getT(5).getT(1).setExternalData(b, index);                 // xnode_impl::cable_table1_t<NV>
		this->getT(1).getT(0).getT(0).getT(5).getT(2).setExternalData(b, index);                 // xnode_impl::cable_table2_t<NV>
		this->getT(1).getT(1).getT(0).getT(0).setExternalData(b, index);                         // xnode_impl::file_player5_t<NV>
		this->getT(1).getT(2).getT(1).getT(3).setExternalData(b, index);                         // xnode_impl::file_player6_t<NV>
		this->getT(1).getT(3).getT(0).getT(1).setExternalData(b, index);                         // xnode_impl::peak2_t<NV>
		this->getT(1).getT(3).getT(1).setExternalData(b, index);                                 // xnode_impl::snex_node_t<NV>
		this->getT(2).setExternalData(b, index);                                                 // xnode_impl::simple_ar_t<NV>
		this->getT(3).getT(1).setExternalData(b, index);                                         // xnode_impl::peak1_t<NV>
		this->getT(3).getT(3).getT(1).getT(2).setExternalData(b, index);                         // xnode_impl::oscillator_t<NV>
		this->getT(3).getT(3).getT(4).getT(0).getT(0).setExternalData(b, index);                 // xnode_impl::cable_table3_t<NV>
		this->getT(3).getT(4).setExternalData(b, index);                                         // xnode_impl::peak_t<NV>
		this->getT(4).getT(1).getT(0).getT(0).setExternalData(b, index);                         // xnode_impl::cable_table_t<NV>
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


