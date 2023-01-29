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

namespace harmonic_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;
template <int NV>
using input_toggle9_t = control::input_toggle<parameter::plain<file_player_t<NV>, 3>>;
template <int NV>
using input_toggle7_t = control::input_toggle<parameter::plain<input_toggle9_t<NV>, 1>>;
template <int NV>
using minmax3_t = control::minmax<NV, 
                                  parameter::plain<input_toggle7_t<NV>, 1>>;

template <int NV>
using minmax7_t = control::minmax<NV, 
                                  parameter::plain<input_toggle7_t<NV>, 2>>;

template <int NV>
using input_toggle8_t = control::input_toggle<parameter::plain<input_toggle9_t<NV>, 2>>;
template <int NV>
using minmax6_t = control::minmax<NV, 
                                  parameter::plain<input_toggle8_t<NV>, 1>>;

template <int NV>
using minmax5_t = control::minmax<NV, 
                                  parameter::plain<input_toggle8_t<NV>, 2>>;

template <int NV>
using input_toggle1_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<minmax3_t<NV>, 0>, 
                                           parameter::plain<minmax7_t<NV>, 0>, 
                                           parameter::plain<minmax6_t<NV>, 0>, 
                                           parameter::plain<minmax5_t<NV>, 0>>;

template <int NV>
using input_toggle1_t = control::input_toggle<input_toggle1_mod<NV>>;
template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<input_toggle1_t<NV>, 1>>;
template <int NV>
using clone_pack1_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<input_toggle_t<NV>, 1>>>, 
                                 data::external::sliderpack<0>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, clone_pack1_t<NV>>>;

template <int NV>
using clone_cable28_t = control::clone_cable<parameter::cloned<parameter::plain<input_toggle_t<NV>, 2>>, 
                                             duplilogic::spread>;

template <int NV>
using input_toggle3_t = control::input_toggle<parameter::plain<input_toggle1_t<NV>, 2>>;
template <int NV>
using clone_cable30_t = control::clone_cable<parameter::cloned<parameter::plain<input_toggle3_t<NV>, 1>>, 
                                             duplilogic::random>;

template <int NV>
using clone_cable33_t = control::clone_cable<parameter::cloned<parameter::plain<input_toggle3_t<NV>, 2>>, 
                                             duplilogic::nyquist>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain1_t<NV>>, 
                                  clone_cable28_t<NV>, 
                                  clone_cable30_t<NV>, 
                                  clone_cable33_t<NV>>;

template <int NV>
using pitchmods_t = container::chain<parameter::empty, 
                                     wrap::fix<2, split2_t<NV>>>;

DECLARE_PARAMETER_RANGE_SKEW(pma35_modRange, 
                             -100., 
                             0., 
                             5.42227);

using pma35_mod = parameter::from0To1<core::gain, 
                                      0, 
                                      pma35_modRange>;

template <int NV>
using pma35_t = control::pma<NV, pma35_mod>;
template <int NV>
using input_toggle108_t = control::input_toggle<parameter::plain<pma35_t<NV>, 0>>;
template <int NV>
using input_toggle106_t = control::input_toggle<parameter::plain<input_toggle108_t<NV>, 1>>;
template <int NV>
using clone_pack2_cable_mod = parameter::cloned<parameter::plain<input_toggle106_t<NV>, 1>>;
template <int NV>
using clone_pack2_t = wrap::data<control::clone_pack<clone_pack2_cable_mod<NV>>, 
                                 data::external::sliderpack<1>>;

template <int NV>
using clone_cable_cable_mod = parameter::cloned<parameter::plain<input_toggle106_t<NV>, 2>>;
template <int NV>
using clone_cable_t = control::clone_cable<clone_cable_cable_mod<NV>, 
                                           duplilogic::spread>;

template <int NV>
using input_toggle107_t = control::input_toggle<parameter::plain<input_toggle108_t<NV>, 2>>;
template <int NV>
using clone_cable7_cable_mod = parameter::cloned<parameter::plain<input_toggle107_t<NV>, 1>>;
template <int NV>
using clone_cable7_t = control::clone_cable<clone_cable7_cable_mod<NV>, 
                                            duplilogic::triangle>;

template <int NV>
using clone_cable1_cable_mod = parameter::cloned<parameter::plain<input_toggle107_t<NV>, 2>>;
template <int NV>
using clone_cable1_t = control::clone_cable<clone_cable1_cable_mod<NV>, 
                                            duplilogic::nyquist>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, clone_pack2_t<NV>>, 
                                  clone_cable_t<NV>, 
                                  clone_cable7_t<NV>, 
                                  clone_cable1_t<NV>>;

template <int NV>
using vol_t = container::chain<parameter::empty, 
                               wrap::fix<2, split1_t<NV>>>;

namespace chain8_t_parameters
{
DECLARE_PARAMETER_RANGE_SKEW(cutRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using cut = parameter::from0To1<filters::svf<NV>, 
                                0, 
                                cutRange>;

}

template <int NV>
using chain8_t = container::chain<chain8_t_parameters::cut<NV>, 
                                  wrap::fix<2, filters::svf<NV>>>;
template <int NV>
using input_toggle15_t = control::input_toggle<parameter::plain<chain8_t<NV>, 0>>;
template <int NV>
using input_toggle2_t = control::input_toggle<parameter::plain<input_toggle15_t<NV>, 1>>;
template <int NV>
using clone_pack3_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<input_toggle2_t<NV>, 1>>>, 
                                 data::external::sliderpack<2>>;

template <int NV>
using clone_cable9_t = control::clone_cable<parameter::cloned<parameter::plain<input_toggle2_t<NV>, 2>>, 
                                            duplilogic::spread>;

template <int NV>
using input_toggle4_t = control::input_toggle<parameter::plain<input_toggle15_t<NV>, 2>>;
template <int NV>
using clone_cable11_t = control::clone_cable<parameter::cloned<parameter::plain<input_toggle4_t<NV>, 1>>, 
                                             duplilogic::random>;

template <int NV>
using clone_cable10_t = control::clone_cable<parameter::cloned<parameter::plain<input_toggle4_t<NV>, 2>>, 
                                             duplilogic::triangle>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, clone_pack3_t<NV>>, 
                                  clone_cable9_t<NV>, 
                                  clone_cable11_t<NV>, 
                                  clone_cable10_t<NV>>;

template <int NV>
using cutmods_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split5_t<NV>>>;

DECLARE_PARAMETER_RANGE_SKEW(pma1_modRange, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using pma1_mod = parameter::from0To1<filters::svf<NV>, 
                                     1, 
                                     pma1_modRange>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using input_toggle10_t = control::input_toggle<parameter::plain<pma1_t<NV>, 0>>;
template <int NV>
using input_toggle6_t = control::input_toggle<parameter::plain<input_toggle10_t<NV>, 1>>;
template <int NV>
using clone_pack5_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<input_toggle6_t<NV>, 1>>>, 
                                 data::external::sliderpack<3>>;

template <int NV>
using clone_cable15_t = control::clone_cable<parameter::cloned<parameter::plain<input_toggle6_t<NV>, 2>>, 
                                             duplilogic::spread>;

template <int NV>
using input_toggle11_t = control::input_toggle<parameter::plain<input_toggle10_t<NV>, 2>>;
template <int NV>
using clone_cable16_cable_mod = parameter::cloned<parameter::plain<input_toggle11_t<NV>, 1>>;
template <int NV>
using clone_cable16_t = control::clone_cable<clone_cable16_cable_mod<NV>, 
                                             duplilogic::random>;

template <int NV>
using clone_cable17_cable_mod = parameter::cloned<parameter::plain<input_toggle11_t<NV>, 2>>;
template <int NV>
using clone_cable17_t = control::clone_cable<clone_cable17_cable_mod<NV>, 
                                             duplilogic::triangle>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<2, clone_pack5_t<NV>>, 
                                  clone_cable15_t<NV>, 
                                  clone_cable16_t<NV>, 
                                  clone_cable17_t<NV>>;

template <int NV>
using resmods_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split7_t<NV>>>;

struct cable_table12_t_data
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
		0.123287f, 0.624268f, 1.f, 1.f, 1.f, 1.f,
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
		1.f, 1.f
	};
};

template <int NV>
using cable_table12_t = wrap::data<control::cable_table<parameter::plain<input_toggle_t<NV>, 0>>, 
                                   data::embedded::table<cable_table12_t_data>>;

struct cable_table14_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.50293f,
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
using cable_table14_t = wrap::data<control::cable_table<parameter::plain<input_toggle1_t<NV>, 0>>, 
                                   data::embedded::table<cable_table14_t_data>>;

struct cable_table13_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.249837f,
		0.583822f, 0.917806f, 1.f, 1.f, 1.f, 1.f,
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
using cable_table13_t = wrap::data<control::cable_table<parameter::plain<input_toggle3_t<NV>, 0>>, 
                                   data::embedded::table<cable_table13_t_data>>;
template <int NV>
using pitchtype_cc = parameter::clonechain<parameter::cloned<parameter::plain<cable_table12_t<NV>, 0>>, 
                                           parameter::cloned<parameter::plain<cable_table14_t<NV>, 0>>, 
                                           parameter::cloned<parameter::plain<cable_table13_t<NV>, 0>>>;
template <int NV>
using pitchtype_t = control::clone_cable<pitchtype_cc<NV>, duplilogic::fixed>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, pitchtype_t<NV>>>;

struct cable_table6_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.00997126f,
		0.0576833f, 0.105396f, 0.153108f, 0.20082f, 0.248532f, 0.296245f,
		0.343957f, 0.391669f, 0.439381f, 0.487094f, 0.534806f, 0.582518f,
		0.63023f, 0.677943f, 0.725655f, 0.773367f, 0.821079f, 0.868792f,
		0.916504f, 0.964216f, 1.f, 1.f, 1.f, 1.f,
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
		1.f, 1.f
	};
};

template <int NV>
using cable_table6_t = wrap::data<control::cable_table<parameter::plain<input_toggle7_t<NV>, 0>>, 
                                  data::embedded::table<cable_table6_t_data>>;

struct cable_table8_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.041748f, 0.125244f,
		0.20874f, 0.292236f, 0.375735f, 0.459231f, 0.542727f, 0.626223f,
		0.709719f, 0.793215f, 0.876711f, 0.960208f, 1.f, 1.f,
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
using cable_table8_t = wrap::data<control::cable_table<parameter::plain<input_toggle9_t<NV>, 0>>, 
                                  data::embedded::table<cable_table8_t_data>>;

struct cable_table7_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.374756f,
		0.875732f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
using cable_table7_t = wrap::data<control::cable_table<parameter::plain<input_toggle8_t<NV>, 0>>, 
                                  data::embedded::table<cable_table7_t_data>>;
template <int NV>
using pitchscale_cc = parameter::clonechain<parameter::cloned<parameter::plain<cable_table6_t<NV>, 0>>, 
                                            parameter::cloned<parameter::plain<cable_table8_t<NV>, 0>>, 
                                            parameter::cloned<parameter::plain<cable_table7_t<NV>, 0>>>;
template <int NV>
using pitchscale_t = control::clone_cable<pitchscale_cc<NV>, duplilogic::fixed>;

struct cable_table105_t_data
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
		0.040634f, 0.205751f, 0.370867f, 0.535983f, 0.701101f, 0.866217f,
		0.988772f, 0.988801f, 0.988831f, 0.988861f, 0.98889f, 0.98892f,
		0.988949f, 0.988979f, 0.989009f, 0.989038f, 0.989068f, 0.989098f,
		0.989127f, 0.989157f, 0.989186f, 0.989216f, 0.989246f, 0.989275f,
		0.989305f, 0.989335f, 0.989364f, 0.989394f, 0.989423f, 0.989453f,
		0.989483f, 0.989512f, 0.989542f, 0.989572f, 0.989601f, 0.989631f,
		0.98966f, 0.98969f, 0.98972f, 0.989749f, 0.989779f, 0.989809f,
		0.989838f, 0.989868f, 0.989897f, 0.989927f, 0.989957f, 0.989986f,
		0.990016f, 0.990046f, 0.990075f, 0.990105f, 0.990134f, 0.990164f,
		0.990194f, 0.990223f, 0.990253f, 0.990283f, 0.990312f, 0.990342f,
		0.990372f, 0.990401f, 0.990431f, 0.99046f, 0.99049f, 0.99052f,
		0.990549f, 0.990579f, 0.990609f, 0.990638f, 0.990668f, 0.990697f,
		0.990727f, 0.990757f, 0.990786f, 0.990816f, 0.990846f, 0.990875f,
		0.990905f, 0.990934f, 0.990964f, 0.990994f, 0.991023f, 0.991053f,
		0.991083f, 0.991112f, 0.991142f, 0.991171f, 0.991201f, 0.991231f,
		0.99126f, 0.99129f, 0.99132f, 0.991349f, 0.991379f, 0.991408f,
		0.991438f, 0.991468f, 0.991497f, 0.991527f, 0.991557f, 0.991586f,
		0.991616f, 0.991645f, 0.991675f, 0.991705f, 0.991734f, 0.991764f,
		0.991794f, 0.991823f, 0.991853f, 0.991882f, 0.991912f, 0.991942f,
		0.991971f, 0.992001f, 0.992031f, 0.99206f, 0.99209f, 0.992119f,
		0.992149f, 0.992179f, 0.992208f, 0.992238f, 0.992268f, 0.992297f,
		0.992327f, 0.992356f, 0.992386f, 0.992416f, 0.992445f, 0.992475f,
		0.992505f, 0.992534f, 0.992564f, 0.992593f, 0.992623f, 0.992653f,
		0.992682f, 0.992712f, 0.992742f, 0.992771f, 0.992801f, 0.99283f,
		0.99286f, 0.99289f, 0.992919f, 0.992949f, 0.992979f, 0.993008f,
		0.993038f, 0.993068f, 0.993097f, 0.993127f, 0.993156f, 0.993186f,
		0.993216f, 0.993245f, 0.993275f, 0.993304f, 0.993334f, 0.993364f,
		0.993393f, 0.993423f, 0.993453f, 0.993482f, 0.993512f, 0.993541f,
		0.993571f, 0.993601f, 0.99363f, 0.99366f, 0.99369f, 0.993719f,
		0.993749f, 0.993779f, 0.993808f, 0.993838f, 0.993867f, 0.993897f,
		0.993927f, 0.993956f, 0.993986f, 0.994016f, 0.994045f, 0.994075f,
		0.994104f, 0.994134f, 0.994164f, 0.994193f, 0.994223f, 0.994253f,
		0.994282f, 0.994312f, 0.994341f, 0.994371f, 0.994401f, 0.99443f,
		0.99446f, 0.99449f, 0.994519f, 0.994549f, 0.994578f, 0.994608f,
		0.994638f, 0.994667f, 0.994697f, 0.994727f, 0.994756f, 0.994786f,
		0.994815f, 0.994845f, 0.994875f, 0.994904f, 0.994934f, 0.994964f,
		0.994993f, 0.995023f, 0.995052f, 0.995082f, 0.995112f, 0.995141f,
		0.995171f, 0.995201f, 0.99523f, 0.99526f, 0.995289f, 0.995319f,
		0.995349f, 0.995378f, 0.995408f, 0.995438f, 0.995467f, 0.995497f,
		0.995526f, 0.995556f, 0.995586f, 0.995615f, 0.995645f, 0.995675f,
		0.995704f, 0.995734f, 0.995763f, 0.995793f, 0.995823f, 0.995852f,
		0.995882f, 0.995912f, 0.995941f, 0.995971f, 0.996f, 0.99603f,
		0.99606f, 0.996089f, 0.996119f, 0.996149f, 0.996178f, 0.996208f,
		0.996237f, 0.996267f, 0.996297f, 0.996326f, 0.996356f, 0.996386f,
		0.996415f, 0.996445f, 0.996475f, 0.996504f, 0.996534f, 0.996563f,
		0.996593f, 0.996623f, 0.996652f, 0.996682f, 0.996711f, 0.996741f,
		0.996771f, 0.9968f, 0.99683f, 0.99686f, 0.996889f, 0.996919f,
		0.996948f, 0.996978f, 0.997008f, 0.997037f, 0.997067f, 0.997097f,
		0.997126f, 0.997156f, 0.997186f, 0.997215f, 0.997245f, 0.997274f,
		0.997304f, 0.997334f, 0.997363f, 0.997393f, 0.997423f, 0.997452f,
		0.997482f, 0.997511f, 0.997541f, 0.997571f, 0.9976f, 0.99763f,
		0.99766f, 0.997689f, 0.997719f, 0.997748f, 0.997778f, 0.997808f,
		0.997837f, 0.997867f, 0.997897f, 0.997926f, 0.997956f, 0.997985f,
		0.998015f, 0.998045f, 0.998074f, 0.998104f, 0.998134f, 0.998163f,
		0.998193f, 0.998222f, 0.998252f, 0.998282f, 0.998311f, 0.998341f,
		0.998371f, 0.9984f, 0.99843f, 0.998459f, 0.998489f, 0.998519f,
		0.998548f, 0.998578f, 0.998608f, 0.998637f, 0.998667f, 0.998696f,
		0.998726f, 0.998756f, 0.998785f, 0.998815f, 0.998845f, 0.998874f,
		0.998904f, 0.998933f, 0.998963f, 0.998993f, 0.999022f, 0.999052f,
		0.999082f, 0.999111f, 0.999141f, 0.99917f, 0.9992f, 0.99923f,
		0.999259f, 0.999289f, 0.999319f, 0.999348f, 0.999378f, 0.999407f,
		0.999437f, 0.999467f, 0.999496f, 0.999526f, 0.999556f, 0.999585f,
		0.999615f, 0.999644f, 0.999674f, 0.999704f, 0.999733f, 0.999763f,
		0.999793f, 0.999822f, 0.999852f, 0.999882f, 0.999911f, 0.999941f,
		0.99997f, 1.f
	};
};

template <int NV>
using cable_table105_t = wrap::data<control::cable_table<parameter::plain<input_toggle106_t<NV>, 0>>, 
                                    data::embedded::table<cable_table105_t_data>>;

struct cable_table107_t_data
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
		0.f, 0.123775f, 0.374268f, 0.624756f, 0.875244f, 1.f,
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
using cable_table107_t = wrap::data<control::cable_table<parameter::plain<input_toggle108_t<NV>, 0>>, 
                                    data::embedded::table<cable_table107_t_data>>;

struct cable_table106_t_data
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
		0.f, 0.247223f, 0.581217f, 0.915202f, 1.f, 1.f,
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
using cable_table106_t = wrap::data<control::cable_table<parameter::plain<input_toggle107_t<NV>, 0>>, 
                                    data::embedded::table<cable_table106_t_data>>;
template <int NV>
using volin_cc = parameter::clonechain<parameter::cloned<parameter::plain<cable_table105_t<NV>, 0>>, 
                                       parameter::cloned<parameter::plain<cable_table107_t<NV>, 0>>, 
                                       parameter::cloned<parameter::plain<cable_table106_t<NV>, 0>>>;
template <int NV>
using volin_t = control::clone_cable<volin_cc<NV>, duplilogic::fixed>;

struct cable_table3_t_data
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
		0.f, 0.f, 0.0626221f, 0.31311f, 0.563602f, 0.814091f,
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
		1.f, 1.f
	};
};

template <int NV>
using cable_table3_t = wrap::data<control::cable_table<parameter::plain<input_toggle2_t<NV>, 0>>, 
                                  data::embedded::table<cable_table3_t_data>>;

struct cable_table5_t_data
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
		0.f, 0.f, 0.f, 0.249512f, 0.750488f, 1.f,
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
using cable_table5_t = wrap::data<control::cable_table<parameter::plain<input_toggle15_t<NV>, 0>>, 
                                  data::embedded::table<cable_table5_t_data>>;

struct cable_table4_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.747559f, 1.f,
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
using cable_table4_t = wrap::data<control::cable_table<parameter::plain<input_toggle4_t<NV>, 0>>, 
                                  data::embedded::table<cable_table4_t_data>>;
template <int NV>
using cutin_cc = parameter::clonechain<parameter::cloned<parameter::plain<cable_table3_t<NV>, 0>>, 
                                       parameter::cloned<parameter::plain<cable_table5_t<NV>, 0>>, 
                                       parameter::cloned<parameter::plain<cable_table4_t<NV>, 0>>>;
template <int NV>
using cutin_t = control::clone_cable<cutin_cc<NV>, duplilogic::fixed>;

struct cable_table9_t_data
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
		0.f, 0.f, 0.0626221f, 0.31311f, 0.563602f, 0.814091f,
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
		1.f, 1.f
	};
};

template <int NV>
using cable_table9_t = wrap::data<control::cable_table<parameter::plain<input_toggle6_t<NV>, 0>>, 
                                  data::embedded::table<cable_table9_t_data>>;

struct cable_table10_t_data
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
		0.f, 0.f, 0.f, 0.249512f, 0.750488f, 1.f,
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
using cable_table10_t = wrap::data<control::cable_table<parameter::plain<input_toggle10_t<NV>, 0>>, 
                                   data::embedded::table<cable_table10_t_data>>;

struct cable_table11_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.747559f, 1.f,
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
using cable_table11_t = wrap::data<control::cable_table<parameter::plain<input_toggle11_t<NV>, 0>>, 
                                   data::embedded::table<cable_table11_t_data>>;
template <int NV>
using clone_cable2_cc = parameter::clonechain<parameter::cloned<parameter::plain<cable_table9_t<NV>, 0>>, 
                                              parameter::cloned<parameter::plain<cable_table10_t<NV>, 0>>, 
                                              parameter::cloned<parameter::plain<cable_table11_t<NV>, 0>>>;
template <int NV>
using clone_cable2_t = control::clone_cable<clone_cable2_cc<NV>, duplilogic::fixed>;

template <int NV>
using resin_t = container::chain<parameter::empty, 
                                 wrap::fix<2, clone_cable2_t<NV>>>;

template <int NV>
using split25_t = container::split<parameter::empty, 
                                   wrap::fix<2, pitchmods_t<NV>>, 
                                   vol_t<NV>, 
                                   cutmods_t<NV>, 
                                   resmods_t<NV>, 
                                   chain5_t<NV>, 
                                   pitchscale_t<NV>, 
                                   volin_t<NV>, 
                                   cutin_t<NV>, 
                                   resin_t<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, split25_t<NV>>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<2, chain6_t<NV>>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, file_player_t<NV>>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, input_toggle_t<NV>>, 
                                 input_toggle1_t<NV>, 
                                 input_toggle3_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, minmax3_t<NV>>, 
                                  minmax7_t<NV>, 
                                  minmax6_t<NV>, 
                                  minmax5_t<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, input_toggle7_t<NV>>, 
                                  input_toggle9_t<NV>, 
                                  input_toggle8_t<NV>>;

// Parameter list for harmonic_impl::pitch_t -------------------------------------------------------

using togglecontrol = parameter::empty;
using toggle_ptype = togglecontrol;
using Switch = togglecontrol;
using pitch_t_plist = parameter::list<togglecontrol, 
                                      toggle_ptype, 
                                      Switch>;
template <int NV>
using pitch_t = container::chain<pitch_t_plist, 
                                 wrap::fix<1, cable_table12_t<NV>>, 
                                 cable_table14_t<NV>, 
                                 cable_table13_t<NV>, 
                                 split_t<NV>, 
                                 split3_t<NV>, 
                                 cable_table6_t<NV>, 
                                 cable_table8_t<NV>, 
                                 cable_table7_t<NV>, 
                                 split4_t<NV>>;

template <int NV>
using split72_t = container::split<parameter::empty, 
                                   wrap::fix<1, input_toggle106_t<NV>>, 
                                   input_toggle108_t<NV>, 
                                   input_toggle107_t<NV>>;

template <int NV>
using _4_way_switch_t = container::chain<parameter::empty, 
                                         wrap::fix<1, cable_table105_t<NV>>, 
                                         cable_table107_t<NV>, 
                                         cable_table106_t<NV>, 
                                         split72_t<NV>, 
                                         pma35_t<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, input_toggle2_t<NV>>, 
                                  input_toggle15_t<NV>, 
                                  input_toggle4_t<NV>>;

template <int NV>
using cut_t = container::chain<parameter::empty, 
                               wrap::fix<1, cable_table3_t<NV>>, 
                               cable_table5_t<NV>, 
                               cable_table4_t<NV>, 
                               split8_t<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, input_toggle6_t<NV>>, 
                                  input_toggle10_t<NV>, 
                                  input_toggle11_t<NV>>;

template <int NV>
using reso_t = container::chain<parameter::empty, 
                                wrap::fix<1, cable_table9_t<NV>>, 
                                cable_table10_t<NV>, 
                                cable_table11_t<NV>, 
                                split9_t<NV>, 
                                pma1_t<NV>>;

template <int NV>
using split52_t = container::split<parameter::empty, 
                                   wrap::fix<1, pitch_t<NV>>, 
                                   _4_way_switch_t<NV>, 
                                   cut_t<NV>, 
                                   reso_t<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, split52_t<NV>>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, chain3_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, chain4_t<NV>>, 
                                       core::gain, 
                                       chain8_t<NV>, 
                                       modchain_t<NV>, 
                                       core::gain>;
template <int NV>
using clone_t = wrap::fix_clonesplit<clone_child_t<NV>, 16>;

namespace harmonic_t_parameters
{
// Parameter list for harmonic_impl::harmonic_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE(sprval1_0Range, 
                        -1., 
                        1.);

template <int NV>
using sprval1_0 = parameter::from0To1<harmonic_impl::clone_cable28_t<NV>, 
                                      1, 
                                      sprval1_0Range>;

template <int NV>
using sprval1 = parameter::chain<ranges::Identity, 
                                 sprval1_0<NV>, 
                                 parameter::plain<harmonic_impl::clone_cable30_t<NV>, 1>, 
                                 parameter::plain<harmonic_impl::clone_cable33_t<NV>, 1>, 
                                 parameter::plain<harmonic_impl::clone_pack1_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(clones_0Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using clones_0 = parameter::from0To1<harmonic_impl::clone_cable28_t<NV>, 
                                     0, 
                                     clones_0Range>;

template <int NV>
using clones_1 = parameter::from0To1<harmonic_impl::clone_cable30_t<NV>, 
                                     0, 
                                     clones_0Range>;

template <int NV>
using clones_2 = parameter::from0To1<harmonic_impl::clone_cable33_t<NV>, 
                                     0, 
                                     clones_0Range>;

template <int NV>
using clones_3 = parameter::from0To1<harmonic_impl::clone_pack1_t<NV>, 
                                     0, 
                                     clones_0Range>;

template <int NV>
using clones = parameter::chain<ranges::Identity, 
                                clones_0<NV>, 
                                clones_1<NV>, 
                                clones_2<NV>, 
                                clones_3<NV>>;

template <int NV>
using gamma = parameter::chain<ranges::Identity, 
                               parameter::plain<harmonic_impl::clone_cable28_t<NV>, 2>, 
                               parameter::plain<harmonic_impl::clone_cable30_t<NV>, 2>, 
                               parameter::plain<harmonic_impl::clone_cable33_t<NV>, 2>>;

template <int NV>
using volvalue_1 = parameter::from0To1<harmonic_impl::clone_cable_t<NV>, 
                                       1, 
                                       sprval1_0Range>;

template <int NV>
using volvalue = parameter::chain<ranges::Identity, 
                                  parameter::plain<harmonic_impl::clone_pack2_t<NV>, 1>, 
                                  volvalue_1<NV>, 
                                  parameter::plain<harmonic_impl::clone_cable7_t<NV>, 1>, 
                                  parameter::plain<harmonic_impl::clone_cable1_t<NV>, 1>>;

template <int NV>
using volclones_0 = parameter::from0To1<harmonic_impl::clone_pack2_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using volclones_1 = parameter::from0To1<harmonic_impl::clone_cable_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using volclones_2 = parameter::from0To1<harmonic_impl::clone_cable7_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using volclones_3 = parameter::from0To1<harmonic_impl::clone_cable1_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using volclones = parameter::chain<ranges::Identity, 
                                   volclones_0<NV>, 
                                   volclones_1<NV>, 
                                   volclones_2<NV>, 
                                   volclones_3<NV>>;

template <int NV>
using volgamma = parameter::chain<ranges::Identity, 
                                  parameter::plain<harmonic_impl::clone_cable_t<NV>, 2>, 
                                  parameter::plain<harmonic_impl::clone_cable7_t<NV>, 2>, 
                                  parameter::plain<harmonic_impl::clone_cable1_t<NV>, 2>>;

template <int NV>
using cutval_1 = parameter::from0To1<harmonic_impl::clone_cable9_t<NV>, 
                                     1, 
                                     sprval1_0Range>;

template <int NV>
using cutval = parameter::chain<ranges::Identity, 
                                parameter::plain<harmonic_impl::clone_pack3_t<NV>, 1>, 
                                cutval_1<NV>, 
                                parameter::plain<harmonic_impl::clone_cable11_t<NV>, 1>, 
                                parameter::plain<harmonic_impl::clone_cable10_t<NV>, 1>>;

template <int NV>
using cutclones_0 = parameter::from0To1<harmonic_impl::clone_pack3_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using cutclones_1 = parameter::from0To1<harmonic_impl::clone_cable9_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using cutclones_2 = parameter::from0To1<harmonic_impl::clone_cable11_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using cutclones_3 = parameter::from0To1<harmonic_impl::clone_cable10_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using cutclones = parameter::chain<ranges::Identity, 
                                   cutclones_0<NV>, 
                                   cutclones_1<NV>, 
                                   cutclones_2<NV>, 
                                   cutclones_3<NV>>;

template <int NV>
using cutgamma = parameter::chain<ranges::Identity, 
                                  parameter::plain<harmonic_impl::clone_cable10_t<NV>, 2>, 
                                  parameter::plain<harmonic_impl::clone_cable11_t<NV>, 2>, 
                                  parameter::plain<harmonic_impl::clone_cable9_t<NV>, 2>>;

template <int NV>
using resval_1 = parameter::from0To1<harmonic_impl::clone_cable15_t<NV>, 
                                     1, 
                                     sprval1_0Range>;

template <int NV>
using resval = parameter::chain<ranges::Identity, 
                                parameter::plain<harmonic_impl::clone_pack5_t<NV>, 1>, 
                                resval_1<NV>, 
                                parameter::plain<harmonic_impl::clone_cable16_t<NV>, 1>, 
                                parameter::plain<harmonic_impl::clone_cable17_t<NV>, 1>>;

template <int NV>
using resclones_0 = parameter::from0To1<harmonic_impl::clone_pack5_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using resclones_1 = parameter::from0To1<harmonic_impl::clone_cable15_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using resclones_2 = parameter::from0To1<harmonic_impl::clone_cable16_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using resclones_3 = parameter::from0To1<harmonic_impl::clone_cable17_t<NV>, 
                                        0, 
                                        clones_0Range>;

template <int NV>
using resclones = parameter::chain<ranges::Identity, 
                                   resclones_0<NV>, 
                                   resclones_1<NV>, 
                                   resclones_2<NV>, 
                                   resclones_3<NV>>;

template <int NV>
using resgamm = parameter::chain<ranges::Identity, 
                                 parameter::plain<harmonic_impl::clone_cable15_t<NV>, 2>, 
                                 parameter::plain<harmonic_impl::clone_cable16_t<NV>, 2>, 
                                 parameter::plain<harmonic_impl::clone_cable17_t<NV>, 2>>;

template <int NV>
using pitchmode_toggle = parameter::plain<harmonic_impl::pitchscale_t<NV>, 
                                          1>;
template <int NV>
using mode = parameter::plain<harmonic_impl::pitchtype_t<NV>, 
                              1>;
template <int NV>
using volmode = parameter::plain<harmonic_impl::volin_t<NV>, 
                                 1>;
template <int NV>
using cutmode = parameter::plain<harmonic_impl::cutin_t<NV>, 
                                 1>;
template <int NV>
using resmode = parameter::plain<harmonic_impl::clone_cable2_t<NV>, 
                                 1>;
template <int NV>
using harmonic_t_plist = parameter::list<pitchmode_toggle<NV>, 
                                         sprval1<NV>, 
                                         clones<NV>, 
                                         gamma<NV>, 
                                         mode<NV>, 
                                         volvalue<NV>, 
                                         volclones<NV>, 
                                         volgamma<NV>, 
                                         volmode<NV>, 
                                         cutval<NV>, 
                                         cutclones<NV>, 
                                         cutgamma<NV>, 
                                         cutmode<NV>, 
                                         resval<NV>, 
                                         resclones<NV>, 
                                         resgamm<NV>, 
                                         resmode<NV>>;
}

template <int NV>
using harmonic_t_ = container::chain<harmonic_t_parameters::harmonic_t_plist<NV>, 
                                     wrap::fix<2, no_midi_t<NV>>, 
                                     clone_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public harmonic_impl::harmonic_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 4;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(harmonic);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(286)
		{
			0x005B, 0x0000, 0x7000, 0x7469, 0x6863, 0x6F6D, 0x6564, 0x745F, 
            0x676F, 0x6C67, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x015B, 0x0000, 0x7300, 
            0x7270, 0x6176, 0x316C, 0x0000, 0x0000, 0x0000, 0x8000, 0xBC3F, 
            0x7109, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 0x0000, 
            0x6C63, 0x6E6F, 0x7365, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 0x0000, 
            0x6167, 0x6D6D, 0x0061, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 0x6D00, 
            0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 0x7600, 0x6C6F, 
            0x6176, 0x756C, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x3E35, 
            0x3E47, 0x0000, 0x3F80, 0x0000, 0x0000, 0x065B, 0x0000, 0x7600, 
            0x6C6F, 0x6C63, 0x6E6F, 0x7365, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 
            0x0000, 0x6F76, 0x676C, 0x6D61, 0x616D, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0008, 0x0000, 0x6F76, 0x6D6C, 0x646F, 0x0065, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x581B, 0x3F31, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x095B, 0x0000, 0x6300, 0x7475, 0x6176, 0x006C, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x3B07, 0x3F30, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0A5B, 0x0000, 0x6300, 0x7475, 0x6C63, 0x6E6F, 0x7365, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x273F, 0x4DA9, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000B, 0x0000, 0x7563, 0x6774, 0x6D61, 0x616D, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000C, 0x0000, 0x7563, 0x6D74, 0x646F, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0D5B, 0x0000, 0x7200, 0x7365, 0x6176, 
            0x006C, 0x0000, 0x0000, 0x0000, 0x3F80, 0xC148, 0x3DF5, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0E5B, 0x0000, 0x7200, 0x7365, 0x6C63, 
            0x6E6F, 0x7365, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000F, 0x0000, 0x6572, 
            0x6773, 0x6D61, 0x006D, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x105B, 0x0000, 0x7200, 
            0x7365, 0x6F6D, 0x6564, 0x0000, 0x0000, 0x0000, 0x8000, 0x683F, 
            0x3D7F, 0x003F, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& no_midi = this->getT(0);                                                        // harmonic_impl::no_midi_t<NV>
		auto& chain6 = this->getT(0).getT(0);                                                 // harmonic_impl::chain6_t<NV>
		auto& split25 = this->getT(0).getT(0).getT(0);                                        // harmonic_impl::split25_t<NV>
		auto& pitchmods = this->getT(0).getT(0).getT(0).getT(0);                              // harmonic_impl::pitchmods_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                         // harmonic_impl::split2_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);                 // harmonic_impl::chain1_t<NV>
		auto& clone_pack1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);    // harmonic_impl::clone_pack1_t<NV>
		auto& clone_cable28 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);          // harmonic_impl::clone_cable28_t<NV>
		auto& clone_cable30 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);          // harmonic_impl::clone_cable30_t<NV>
		auto& clone_cable33 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3);          // harmonic_impl::clone_cable33_t<NV>
		auto& vol = this->getT(0).getT(0).getT(0).getT(1);                                    // harmonic_impl::vol_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                         // harmonic_impl::split1_t<NV>
		auto& clone_pack2 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);            // harmonic_impl::clone_pack2_t<NV>
		auto& clone_cable = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);            // harmonic_impl::clone_cable_t<NV>
		auto& clone_cable7 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);           // harmonic_impl::clone_cable7_t<NV>
		auto& clone_cable1 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3);           // harmonic_impl::clone_cable1_t<NV>
		auto& cutmods = this->getT(0).getT(0).getT(0).getT(2);                                // harmonic_impl::cutmods_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                         // harmonic_impl::split5_t<NV>
		auto& clone_pack3 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0);            // harmonic_impl::clone_pack3_t<NV>
		auto& clone_cable9 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1);           // harmonic_impl::clone_cable9_t<NV>
		auto& clone_cable11 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2);          // harmonic_impl::clone_cable11_t<NV>
		auto& clone_cable10 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(3);          // harmonic_impl::clone_cable10_t<NV>
		auto& resmods = this->getT(0).getT(0).getT(0).getT(3);                                // harmonic_impl::resmods_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(0).getT(3).getT(0);                         // harmonic_impl::split7_t<NV>
		auto& clone_pack5 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0);            // harmonic_impl::clone_pack5_t<NV>
		auto& clone_cable15 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1);          // harmonic_impl::clone_cable15_t<NV>
		auto& clone_cable16 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2);          // harmonic_impl::clone_cable16_t<NV>
		auto& clone_cable17 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(3);          // harmonic_impl::clone_cable17_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(4);                                 // harmonic_impl::chain5_t<NV>
		auto& pitchtype = this->getT(0).getT(0).getT(0).getT(4).getT(0);                      // harmonic_impl::pitchtype_t<NV>
		auto& pitchscale = this->getT(0).getT(0).getT(0).getT(5);                             // harmonic_impl::pitchscale_t<NV>
		auto& volin = this->getT(0).getT(0).getT(0).getT(6);                                  // harmonic_impl::volin_t<NV>
		auto& cutin = this->getT(0).getT(0).getT(0).getT(7);                                  // harmonic_impl::cutin_t<NV>
		auto& resin = this->getT(0).getT(0).getT(0).getT(8);                                  // harmonic_impl::resin_t<NV>
		auto& clone_cable2 = this->getT(0).getT(0).getT(0).getT(8).getT(0);                   // harmonic_impl::clone_cable2_t<NV>
		auto& clone = this->getT(1);                                                          // harmonic_impl::clone_t<NV>                                                          // harmonic_impl::clone_child_t<NV>
		auto chain4 = this->getT(1).getT(0);                                                  // harmonic_impl::chain4_t<NV>
		auto file_player = this->getT(1).getT(0).getT(0);                                     // harmonic_impl::file_player_t<NV>
		auto gain = this->getT(1).getT(1);                                                    // core::gain
		auto chain8 = this->getT(1).getT(2);                                                  // harmonic_impl::chain8_t<NV>
		auto svf = this->getT(1).getT(2).getT(0);                                             // filters::svf<NV>
		auto modchain = this->getT(1).getT(3);                                                // harmonic_impl::modchain_t<NV>
		auto chain3 = this->getT(1).getT(3).getT(0);                                          // harmonic_impl::chain3_t<NV>
		auto split52 = this->getT(1).getT(3).getT(0).getT(0);                                 // harmonic_impl::split52_t<NV>
		auto pitch = this->getT(1).getT(3).getT(0).getT(0).getT(0);                           // harmonic_impl::pitch_t<NV>
		auto cable_table12 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(0);           // harmonic_impl::cable_table12_t<NV>
		auto cable_table14 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(1);           // harmonic_impl::cable_table14_t<NV>
		auto cable_table13 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(2);           // harmonic_impl::cable_table13_t<NV>
		auto split = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(3);                   // harmonic_impl::split_t<NV>
		auto input_toggle = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(3).getT(0);    // harmonic_impl::input_toggle_t<NV>
		auto input_toggle1 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(3).getT(1);   // harmonic_impl::input_toggle1_t<NV>
		auto input_toggle3 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(3).getT(2);   // harmonic_impl::input_toggle3_t<NV>
		auto split3 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(4);                  // harmonic_impl::split3_t<NV>
		auto minmax3 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(4).getT(0);         // harmonic_impl::minmax3_t<NV>
		auto minmax7 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(4).getT(1);         // harmonic_impl::minmax7_t<NV>
		auto minmax6 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(4).getT(2);         // harmonic_impl::minmax6_t<NV>
		auto minmax5 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(4).getT(3);         // harmonic_impl::minmax5_t<NV>
		auto cable_table6 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(5);            // harmonic_impl::cable_table6_t<NV>
		auto cable_table8 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(6);            // harmonic_impl::cable_table8_t<NV>
		auto cable_table7 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(7);            // harmonic_impl::cable_table7_t<NV>
		auto split4 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(8);                  // harmonic_impl::split4_t<NV>
		auto input_toggle7 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(8).getT(0);   // harmonic_impl::input_toggle7_t<NV>
		auto input_toggle9 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(8).getT(1);   // harmonic_impl::input_toggle9_t<NV>
		auto input_toggle8 = this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(8).getT(2);   // harmonic_impl::input_toggle8_t<NV>
		auto _4_way_switch = this->getT(1).getT(3).getT(0).getT(0).getT(1);                   // harmonic_impl::_4_way_switch_t<NV>
		auto cable_table105 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(0);          // harmonic_impl::cable_table105_t<NV>
		auto cable_table107 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(1);          // harmonic_impl::cable_table107_t<NV>
		auto cable_table106 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(2);          // harmonic_impl::cable_table106_t<NV>
		auto split72 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(3);                 // harmonic_impl::split72_t<NV>
		auto input_toggle106 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(3).getT(0); // harmonic_impl::input_toggle106_t<NV>
		auto input_toggle108 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(3).getT(1); // harmonic_impl::input_toggle108_t<NV>
		auto input_toggle107 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(3).getT(2); // harmonic_impl::input_toggle107_t<NV>
		auto pma35 = this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(4);                   // harmonic_impl::pma35_t<NV>
		auto cut = this->getT(1).getT(3).getT(0).getT(0).getT(2);                             // harmonic_impl::cut_t<NV>
		auto cable_table3 = this->getT(1).getT(3).getT(0).getT(0).getT(2).getT(0);            // harmonic_impl::cable_table3_t<NV>
		auto cable_table5 = this->getT(1).getT(3).getT(0).getT(0).getT(2).getT(1);            // harmonic_impl::cable_table5_t<NV>
		auto cable_table4 = this->getT(1).getT(3).getT(0).getT(0).getT(2).getT(2);            // harmonic_impl::cable_table4_t<NV>
		auto split8 = this->getT(1).getT(3).getT(0).getT(0).getT(2).getT(3);                  // harmonic_impl::split8_t<NV>
		auto input_toggle2 = this->getT(1).getT(3).getT(0).getT(0).getT(2).getT(3).getT(0);   // harmonic_impl::input_toggle2_t<NV>
		auto input_toggle15 = this->getT(1).getT(3).getT(0).getT(0).getT(2).getT(3).getT(1);  // harmonic_impl::input_toggle15_t<NV>
		auto input_toggle4 = this->getT(1).getT(3).getT(0).getT(0).getT(2).getT(3).getT(2);   // harmonic_impl::input_toggle4_t<NV>
		auto reso = this->getT(1).getT(3).getT(0).getT(0).getT(3);                            // harmonic_impl::reso_t<NV>
		auto cable_table9 = this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(0);            // harmonic_impl::cable_table9_t<NV>
		auto cable_table10 = this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(1);           // harmonic_impl::cable_table10_t<NV>
		auto cable_table11 = this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(2);           // harmonic_impl::cable_table11_t<NV>
		auto split9 = this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(3);                  // harmonic_impl::split9_t<NV>
		auto input_toggle6 = this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(3).getT(0);   // harmonic_impl::input_toggle6_t<NV>
		auto input_toggle10 = this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(3).getT(1);  // harmonic_impl::input_toggle10_t<NV>
		auto input_toggle11 = this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(3).getT(2);  // harmonic_impl::input_toggle11_t<NV>
		auto pma1 = this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(4);                    // harmonic_impl::pma1_t<NV>
		auto gain31 = this->getT(1).getT(4);                                                  // core::gain
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain8.getParameterT(0).connectT(0, svf);       // cut -> svf::Frequency
		chain8.getParameterT(0).connectT(0, svf);       // cut -> svf::Frequency
		this->getParameterT(0).connectT(0, pitchscale); // pitchmode_toggle -> pitchscale::Value
		
		auto& sprval1_p = this->getParameterT(1);
		sprval1_p.connectT(0, clone_cable28); // sprval1 -> clone_cable28::Value
		sprval1_p.connectT(1, clone_cable30); // sprval1 -> clone_cable30::Value
		sprval1_p.connectT(2, clone_cable33); // sprval1 -> clone_cable33::Value
		sprval1_p.connectT(3, clone_pack1);   // sprval1 -> clone_pack1::Value
		
		auto& clones_p = this->getParameterT(2);
		clones_p.connectT(0, clone_cable28); // clones -> clone_cable28::NumClones
		clones_p.connectT(1, clone_cable30); // clones -> clone_cable30::NumClones
		clones_p.connectT(2, clone_cable33); // clones -> clone_cable33::NumClones
		clones_p.connectT(3, clone_pack1);   // clones -> clone_pack1::NumClones
		
		auto& gamma_p = this->getParameterT(3);
		gamma_p.connectT(0, clone_cable28); // gamma -> clone_cable28::Gamma
		gamma_p.connectT(1, clone_cable30); // gamma -> clone_cable30::Gamma
		gamma_p.connectT(2, clone_cable33); // gamma -> clone_cable33::Gamma
		
		this->getParameterT(4).connectT(0, pitchtype); // mode -> pitchtype::Value
		
		auto& volvalue_p = this->getParameterT(5);
		volvalue_p.connectT(0, clone_pack2);  // volvalue -> clone_pack2::Value
		volvalue_p.connectT(1, clone_cable);  // volvalue -> clone_cable::Value
		volvalue_p.connectT(2, clone_cable7); // volvalue -> clone_cable7::Value
		volvalue_p.connectT(3, clone_cable1); // volvalue -> clone_cable1::Value
		
		auto& volclones_p = this->getParameterT(6);
		volclones_p.connectT(0, clone_pack2);  // volclones -> clone_pack2::NumClones
		volclones_p.connectT(1, clone_cable);  // volclones -> clone_cable::NumClones
		volclones_p.connectT(2, clone_cable7); // volclones -> clone_cable7::NumClones
		volclones_p.connectT(3, clone_cable1); // volclones -> clone_cable1::NumClones
		
		auto& volgamma_p = this->getParameterT(7);
		volgamma_p.connectT(0, clone_cable);  // volgamma -> clone_cable::Gamma
		volgamma_p.connectT(1, clone_cable7); // volgamma -> clone_cable7::Gamma
		volgamma_p.connectT(2, clone_cable1); // volgamma -> clone_cable1::Gamma
		
		this->getParameterT(8).connectT(0, volin); // volmode -> volin::Value
		
		auto& cutval_p = this->getParameterT(9);
		cutval_p.connectT(0, clone_pack3);   // cutval -> clone_pack3::Value
		cutval_p.connectT(1, clone_cable9);  // cutval -> clone_cable9::Value
		cutval_p.connectT(2, clone_cable11); // cutval -> clone_cable11::Value
		cutval_p.connectT(3, clone_cable10); // cutval -> clone_cable10::Value
		
		auto& cutclones_p = this->getParameterT(10);
		cutclones_p.connectT(0, clone_pack3);   // cutclones -> clone_pack3::NumClones
		cutclones_p.connectT(1, clone_cable9);  // cutclones -> clone_cable9::NumClones
		cutclones_p.connectT(2, clone_cable11); // cutclones -> clone_cable11::NumClones
		cutclones_p.connectT(3, clone_cable10); // cutclones -> clone_cable10::NumClones
		
		auto& cutgamma_p = this->getParameterT(11);
		cutgamma_p.connectT(0, clone_cable10); // cutgamma -> clone_cable10::Gamma
		cutgamma_p.connectT(1, clone_cable11); // cutgamma -> clone_cable11::Gamma
		cutgamma_p.connectT(2, clone_cable9);  // cutgamma -> clone_cable9::Gamma
		
		this->getParameterT(12).connectT(0, cutin); // cutmode -> cutin::Value
		
		auto& resval_p = this->getParameterT(13);
		resval_p.connectT(0, clone_pack5);   // resval -> clone_pack5::Value
		resval_p.connectT(1, clone_cable15); // resval -> clone_cable15::Value
		resval_p.connectT(2, clone_cable16); // resval -> clone_cable16::Value
		resval_p.connectT(3, clone_cable17); // resval -> clone_cable17::Value
		
		auto& resclones_p = this->getParameterT(14);
		resclones_p.connectT(0, clone_pack5);   // resclones -> clone_pack5::NumClones
		resclones_p.connectT(1, clone_cable15); // resclones -> clone_cable15::NumClones
		resclones_p.connectT(2, clone_cable16); // resclones -> clone_cable16::NumClones
		resclones_p.connectT(3, clone_cable17); // resclones -> clone_cable17::NumClones
		
		auto& resgamm_p = this->getParameterT(15);
		resgamm_p.connectT(0, clone_cable15); // resgamm -> clone_cable15::Gamma
		resgamm_p.connectT(1, clone_cable16); // resgamm -> clone_cable16::Gamma
		resgamm_p.connectT(2, clone_cable17); // resgamm -> clone_cable17::Gamma
		
		this->getParameterT(16).connectT(0, clone_cable2); // resmode -> clone_cable2::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		input_toggle9.getWrappedObject().getParameter().connectT(0, file_player);       // input_toggle9 -> file_player::FreqRatio
		input_toggle7.getWrappedObject().getParameter().connectT(0, input_toggle9);     // input_toggle7 -> input_toggle9::Value1
		minmax3.getWrappedObject().getParameter().connectT(0, input_toggle7);           // minmax3 -> input_toggle7::Value1
		minmax7.getWrappedObject().getParameter().connectT(0, input_toggle7);           // minmax7 -> input_toggle7::Value2
		input_toggle8.getWrappedObject().getParameter().connectT(0, input_toggle9);     // input_toggle8 -> input_toggle9::Value2
		minmax6.getWrappedObject().getParameter().connectT(0, input_toggle8);           // minmax6 -> input_toggle8::Value1
		minmax5.getWrappedObject().getParameter().connectT(0, input_toggle8);           // minmax5 -> input_toggle8::Value2
		input_toggle1.getWrappedObject().getParameter().connectT(0, minmax3);           // input_toggle1 -> minmax3::Value
		input_toggle1.getWrappedObject().getParameter().connectT(1, minmax7);           // input_toggle1 -> minmax7::Value
		input_toggle1.getWrappedObject().getParameter().connectT(2, minmax6);           // input_toggle1 -> minmax6::Value
		input_toggle1.getWrappedObject().getParameter().connectT(3, minmax5);           // input_toggle1 -> minmax5::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, input_toggle1);      // input_toggle -> input_toggle1::Value1
		clone_pack1.getWrappedObject().getParameter().connectT(0, input_toggle);        // clone_pack1 -> input_toggle::Value1
		clone_cable28.getWrappedObject().getParameter().connectT(0, input_toggle);      // clone_cable28 -> input_toggle::Value2
		input_toggle3.getWrappedObject().getParameter().connectT(0, input_toggle1);     // input_toggle3 -> input_toggle1::Value2
		clone_cable30.getWrappedObject().getParameter().connectT(0, input_toggle3);     // clone_cable30 -> input_toggle3::Value1
		clone_cable33.getWrappedObject().getParameter().connectT(0, input_toggle3);     // clone_cable33 -> input_toggle3::Value2
		pma35.getWrappedObject().getParameter().connectT(0, gain);                      // pma35 -> gain::Gain
		input_toggle108.getWrappedObject().getParameter().connectT(0, pma35);           // input_toggle108 -> pma35::Value
		input_toggle106.getWrappedObject().getParameter().connectT(0, input_toggle108); // input_toggle106 -> input_toggle108::Value1
		clone_pack2.getWrappedObject().getParameter().connectT(0, input_toggle106);     // clone_pack2 -> input_toggle106::Value1
		clone_cable.getWrappedObject().getParameter().connectT(0, input_toggle106);     // clone_cable -> input_toggle106::Value2
		input_toggle107.getWrappedObject().getParameter().connectT(0, input_toggle108); // input_toggle107 -> input_toggle108::Value2
		clone_cable7.getWrappedObject().getParameter().connectT(0, input_toggle107);    // clone_cable7 -> input_toggle107::Value1
		clone_cable1.getWrappedObject().getParameter().connectT(0, input_toggle107);    // clone_cable1 -> input_toggle107::Value2
		input_toggle15.getWrappedObject().getParameter().connectT(0, chain8);           // input_toggle15 -> chain8::cut
		input_toggle2.getWrappedObject().getParameter().connectT(0, input_toggle15);    // input_toggle2 -> input_toggle15::Value1
		clone_pack3.getWrappedObject().getParameter().connectT(0, input_toggle2);       // clone_pack3 -> input_toggle2::Value1
		clone_cable9.getWrappedObject().getParameter().connectT(0, input_toggle2);      // clone_cable9 -> input_toggle2::Value2
		input_toggle4.getWrappedObject().getParameter().connectT(0, input_toggle15);    // input_toggle4 -> input_toggle15::Value2
		clone_cable11.getWrappedObject().getParameter().connectT(0, input_toggle4);     // clone_cable11 -> input_toggle4::Value1
		clone_cable10.getWrappedObject().getParameter().connectT(0, input_toggle4);     // clone_cable10 -> input_toggle4::Value2
		pma1.getWrappedObject().getParameter().connectT(0, svf);                        // pma1 -> svf::Q
		input_toggle10.getWrappedObject().getParameter().connectT(0, pma1);             // input_toggle10 -> pma1::Value
		input_toggle6.getWrappedObject().getParameter().connectT(0, input_toggle10);    // input_toggle6 -> input_toggle10::Value1
		clone_pack5.getWrappedObject().getParameter().connectT(0, input_toggle6);       // clone_pack5 -> input_toggle6::Value1
		clone_cable15.getWrappedObject().getParameter().connectT(0, input_toggle6);     // clone_cable15 -> input_toggle6::Value2
		input_toggle11.getWrappedObject().getParameter().connectT(0, input_toggle10);   // input_toggle11 -> input_toggle10::Value2
		clone_cable16.getWrappedObject().getParameter().connectT(0, input_toggle11);    // clone_cable16 -> input_toggle11::Value1
		clone_cable17.getWrappedObject().getParameter().connectT(0, input_toggle11);    // clone_cable17 -> input_toggle11::Value2
		cable_table12.getWrappedObject().getParameter().connectT(0, input_toggle);      // cable_table12 -> input_toggle::Input
		cable_table14.getWrappedObject().getParameter().connectT(0, input_toggle1);     // cable_table14 -> input_toggle1::Input
		cable_table13.getWrappedObject().getParameter().connectT(0, input_toggle3);     // cable_table13 -> input_toggle3::Input
		pitchtype.getWrappedObject().getParameter().connectT(0, cable_table12);         // pitchtype -> cable_table12::Value
		pitchtype.getWrappedObject().getParameter().connectT(1, cable_table14);         // pitchtype -> cable_table14::Value
		pitchtype.getWrappedObject().getParameter().connectT(2, cable_table13);         // pitchtype -> cable_table13::Value
		cable_table6.getWrappedObject().getParameter().connectT(0, input_toggle7);      // cable_table6 -> input_toggle7::Input
		cable_table8.getWrappedObject().getParameter().connectT(0, input_toggle9);      // cable_table8 -> input_toggle9::Input
		cable_table7.getWrappedObject().getParameter().connectT(0, input_toggle8);      // cable_table7 -> input_toggle8::Input
		pitchscale.getWrappedObject().getParameter().connectT(0, cable_table6);         // pitchscale -> cable_table6::Value
		pitchscale.getWrappedObject().getParameter().connectT(1, cable_table8);         // pitchscale -> cable_table8::Value
		pitchscale.getWrappedObject().getParameter().connectT(2, cable_table7);         // pitchscale -> cable_table7::Value
		cable_table105.getWrappedObject().getParameter().connectT(0, input_toggle106);  // cable_table105 -> input_toggle106::Input
		cable_table107.getWrappedObject().getParameter().connectT(0, input_toggle108);  // cable_table107 -> input_toggle108::Input
		cable_table106.getWrappedObject().getParameter().connectT(0, input_toggle107);  // cable_table106 -> input_toggle107::Input
		volin.getWrappedObject().getParameter().connectT(0, cable_table105);            // volin -> cable_table105::Value
		volin.getWrappedObject().getParameter().connectT(1, cable_table107);            // volin -> cable_table107::Value
		volin.getWrappedObject().getParameter().connectT(2, cable_table106);            // volin -> cable_table106::Value
		cable_table3.getWrappedObject().getParameter().connectT(0, input_toggle2);      // cable_table3 -> input_toggle2::Input
		cable_table5.getWrappedObject().getParameter().connectT(0, input_toggle15);     // cable_table5 -> input_toggle15::Input
		cable_table4.getWrappedObject().getParameter().connectT(0, input_toggle4);      // cable_table4 -> input_toggle4::Input
		cutin.getWrappedObject().getParameter().connectT(0, cable_table3);              // cutin -> cable_table3::Value
		cutin.getWrappedObject().getParameter().connectT(1, cable_table5);              // cutin -> cable_table5::Value
		cutin.getWrappedObject().getParameter().connectT(2, cable_table4);              // cutin -> cable_table4::Value
		cable_table9.getWrappedObject().getParameter().connectT(0, input_toggle6);      // cable_table9 -> input_toggle6::Input
		cable_table10.getWrappedObject().getParameter().connectT(0, input_toggle10);    // cable_table10 -> input_toggle10::Input
		cable_table11.getWrappedObject().getParameter().connectT(0, input_toggle11);    // cable_table11 -> input_toggle11::Input
		clone_cable2.getWrappedObject().getParameter().connectT(0, cable_table9);       // clone_cable2 -> cable_table9::Value
		clone_cable2.getWrappedObject().getParameter().connectT(1, cable_table10);      // clone_cable2 -> cable_table10::Value
		clone_cable2.getWrappedObject().getParameter().connectT(2, cable_table11);      // clone_cable2 -> cable_table11::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // clone_pack1::NumClones is automated
		; // clone_pack1::Value is automated
		
		; // clone_cable28::NumClones is automated
		; // clone_cable28::Value is automated
		; // clone_cable28::Gamma is automated
		
		; // clone_cable30::NumClones is automated
		; // clone_cable30::Value is automated
		; // clone_cable30::Gamma is automated
		
		; // clone_cable33::NumClones is automated
		; // clone_cable33::Value is automated
		; // clone_cable33::Gamma is automated
		
		; // clone_pack2::NumClones is automated
		; // clone_pack2::Value is automated
		
		; // clone_cable::NumClones is automated
		; // clone_cable::Value is automated
		; // clone_cable::Gamma is automated
		
		; // clone_cable7::NumClones is automated
		; // clone_cable7::Value is automated
		; // clone_cable7::Gamma is automated
		
		; // clone_cable1::NumClones is automated
		; // clone_cable1::Value is automated
		; // clone_cable1::Gamma is automated
		
		; // clone_pack3::NumClones is automated
		; // clone_pack3::Value is automated
		
		; // clone_cable9::NumClones is automated
		; // clone_cable9::Value is automated
		; // clone_cable9::Gamma is automated
		
		; // clone_cable11::NumClones is automated
		; // clone_cable11::Value is automated
		; // clone_cable11::Gamma is automated
		
		; // clone_cable10::NumClones is automated
		; // clone_cable10::Value is automated
		; // clone_cable10::Gamma is automated
		
		; // clone_pack5::NumClones is automated
		; // clone_pack5::Value is automated
		
		; // clone_cable15::NumClones is automated
		; // clone_cable15::Value is automated
		; // clone_cable15::Gamma is automated
		
		; // clone_cable16::NumClones is automated
		; // clone_cable16::Value is automated
		; // clone_cable16::Gamma is automated
		
		; // clone_cable17::NumClones is automated
		; // clone_cable17::Value is automated
		; // clone_cable17::Gamma is automated
		
		;                               // pitchtype::NumClones is deactivated
		;                               // pitchtype::Value is automated
		pitchtype.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                // pitchscale::NumClones is deactivated
		;                                // pitchscale::Value is automated
		pitchscale.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                           // volin::NumClones is deactivated
		;                           // volin::Value is automated
		volin.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                           // cutin::NumClones is deactivated
		;                           // cutin::Value is automated
		cutin.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable2::NumClones is deactivated
		;                                  // clone_cable2::Value is automated
		clone_cable2.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone.setParameterT(0, 16.); // container::clone::NumClones
		clone.setParameterT(1, 1.);  // container::clone::SplitSignal
		
		file_player.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                   // file_player::FreqRatio is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // chain8::cut is automated
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);   // filters::svf::Mode
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		pitch.setParameterT(0, 0.467318); // container::chain::togglecontrol
		pitch.setParameterT(1, 0.);       // container::chain::toggle_ptype
		pitch.setParameterT(2, 1.);       // container::chain::Switch
		
		; // cable_table12::Value is automated
		
		; // cable_table14::Value is automated
		
		; // cable_table13::Value is automated
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		; // input_toggle1::Input is automated
		; // input_toggle1::Value1 is automated
		; // input_toggle1::Value2 is automated
		
		; // input_toggle3::Input is automated
		; // input_toggle3::Value1 is automated
		; // input_toggle3::Value2 is automated
		
		split3.setParameterT(0, 1.); // container::split::pitchtype
		
		;                              // minmax3::Value is automated
		minmax3.setParameterT(1, 1.);  // control::minmax::Minimum
		minmax3.setParameterT(2, 16.); // control::minmax::Maximum
		minmax3.setParameterT(3, 1.);  // control::minmax::Skew
		minmax3.setParameterT(4, 1.);  // control::minmax::Step
		minmax3.setParameterT(5, 0.);  // control::minmax::Polarity
		
		;                                  // minmax7::Value is automated
		minmax7.setParameterT(1, 0.5);     // control::minmax::Minimum
		minmax7.setParameterT(2, 2.);      // control::minmax::Maximum
		minmax7.setParameterT(3, 0.63093); // control::minmax::Skew
		minmax7.setParameterT(4, 0.);      // control::minmax::Step
		minmax7.setParameterT(5, 0.);      // control::minmax::Polarity
		
		;                                   // minmax6::Value is automated
		minmax6.setParameterT(1, 0.909091); // control::minmax::Minimum
		minmax6.setParameterT(2, 1.1);      // control::minmax::Maximum
		minmax6.setParameterT(3, 0.93424);  // control::minmax::Skew
		minmax6.setParameterT(4, 0.);       // control::minmax::Step
		minmax6.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                              // minmax5::Value is automated
		minmax5.setParameterT(1, 1.);  // control::minmax::Minimum
		minmax5.setParameterT(2, 16.); // control::minmax::Maximum
		minmax5.setParameterT(3, 1.);  // control::minmax::Skew
		minmax5.setParameterT(4, 1.);  // control::minmax::Step
		minmax5.setParameterT(5, 0.);  // control::minmax::Polarity
		
		; // cable_table6::Value is automated
		
		; // cable_table8::Value is automated
		
		; // cable_table7::Value is automated
		
		; // input_toggle7::Input is automated
		; // input_toggle7::Value1 is automated
		; // input_toggle7::Value2 is automated
		
		; // input_toggle9::Input is automated
		; // input_toggle9::Value1 is automated
		; // input_toggle9::Value2 is automated
		
		; // input_toggle8::Input is automated
		; // input_toggle8::Value1 is automated
		; // input_toggle8::Value2 is automated
		
		_4_way_switch.setParameterT(0, 0.); // container::chain::Switch
		
		; // cable_table105::Value is automated
		
		; // cable_table107::Value is automated
		
		; // cable_table106::Value is automated
		
		; // input_toggle106::Input is automated
		; // input_toggle106::Value1 is automated
		; // input_toggle106::Value2 is automated
		
		; // input_toggle108::Input is automated
		; // input_toggle108::Value1 is automated
		; // input_toggle108::Value2 is automated
		
		; // input_toggle107::Input is automated
		; // input_toggle107::Value1 is automated
		; // input_toggle107::Value2 is automated
		
		;                           // pma35::Value is automated
		pma35.setParameterT(1, 1.); // control::pma::Multiply
		pma35.setParameterT(2, 0.); // control::pma::Add
		
		cut.setParameterT(0, 0.); // container::chain::Switch
		
		; // cable_table3::Value is automated
		
		; // cable_table5::Value is automated
		
		; // cable_table4::Value is automated
		
		; // input_toggle2::Input is automated
		; // input_toggle2::Value1 is automated
		; // input_toggle2::Value2 is automated
		
		; // input_toggle15::Input is automated
		; // input_toggle15::Value1 is automated
		; // input_toggle15::Value2 is automated
		
		; // input_toggle4::Input is automated
		; // input_toggle4::Value1 is automated
		; // input_toggle4::Value2 is automated
		
		reso.setParameterT(0, 0.); // container::chain::Switch
		
		; // cable_table9::Value is automated
		
		; // cable_table10::Value is automated
		
		; // cable_table11::Value is automated
		
		; // input_toggle6::Input is automated
		; // input_toggle6::Value1 is automated
		; // input_toggle6::Value2 is automated
		
		; // input_toggle10::Input is automated
		; // input_toggle10::Value1 is automated
		; // input_toggle10::Value2 is automated
		
		; // input_toggle11::Input is automated
		; // input_toggle11::Value1 is automated
		; // input_toggle11::Value2 is automated
		
		;                          // pma1::Value is automated
		pma1.setParameterT(1, 1.); // control::pma::Multiply
		pma1.setParameterT(2, 0.); // control::pma::Add
		
		gain31.setParameterT(0, 0.);  // core::gain::Gain
		gain31.setParameterT(1, 20.); // core::gain::Smoothing
		gain31.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.941555);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 0.194573);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.692751);
		this->setParameterT(9, 0.688401);
		this->setParameterT(10, 0.803362);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 0.119998);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.740225);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // harmonic_impl::clone_pack1_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);         // harmonic_impl::clone_pack2_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0).setExternalData(b, index);         // harmonic_impl::clone_pack3_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0).setExternalData(b, index);         // harmonic_impl::clone_pack5_t<NV>
		this->getT(1).getT(0).getT(0).setExternalData(b, index);                                 // harmonic_impl::file_player_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);         // harmonic_impl::cable_table12_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);         // harmonic_impl::cable_table14_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index);         // harmonic_impl::cable_table13_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(5).setExternalData(b, index);         // harmonic_impl::cable_table6_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(6).setExternalData(b, index);         // harmonic_impl::cable_table8_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(0).getT(7).setExternalData(b, index);         // harmonic_impl::cable_table7_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);         // harmonic_impl::cable_table105_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);         // harmonic_impl::cable_table107_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index);         // harmonic_impl::cable_table106_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);         // harmonic_impl::cable_table3_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(2).getT(1).setExternalData(b, index);         // harmonic_impl::cable_table5_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(2).getT(2).setExternalData(b, index);         // harmonic_impl::cable_table4_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(0).setExternalData(b, index);         // harmonic_impl::cable_table9_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(1).setExternalData(b, index);         // harmonic_impl::cable_table10_t<NV>
		this->getT(1).getT(3).getT(0).getT(0).getT(3).getT(2).setExternalData(b, index);         // harmonic_impl::cable_table11_t<NV>
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
using harmonic = wrap::node<harmonic_impl::instance<NV>>;
}


