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
using global_cable_t_index = runtime_target::indexers::fix_hash<3318940>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable_t<NV>>, 
                                   math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<3318941>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<3318942>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable2_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch28_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain47_t<NV>>, 
                                     chain50_t<NV>, 
                                     chain49_t<NV>>;

template <int NV>
using smoothed_parameter_unscaled7_t = wrap::mod<parameter::plain<jdsp::jdelay_thiran<NV>, 1>, 
                                                 control::smoothed_parameter_unscaled<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter_unscaled9_t = smoothed_parameter_unscaled7_t<NV>;

template <int NV>
using tempo_sync3_mod = parameter::chain<ranges::Identity, 
                                         parameter::plain<smoothed_parameter_unscaled7_t<NV>, 0>, 
                                         parameter::plain<smoothed_parameter_unscaled9_t<NV>, 0>>;

template <int NV>
using tempo_sync3_t = wrap::mod<tempo_sync3_mod<NV>, 
                                control::tempo_sync<NV>>;
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

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 pma_mod_0<NV>, 
                                 pma_mod_1<NV>, 
                                 parameter::plain<control::minmax<NV, parameter::empty>, 0>>;

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
                                  parameter::plain<control::minmax<NV, parameter::empty>, 0>, 
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
                                   control::minmax<NV, parameter::empty>, 
                                   tempo_sync3_t<NV>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma1_t<NV>>, 
                                   control::minmax<NV, parameter::empty>, 
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
template <int NV>
using stereo_cable = cable::block<NV, 2>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                   smoothed_parameter_unscaled7_t<NV>, 
                                   jdsp::jdelay_thiran<NV>, 
                                   filters::one_pole<NV>, 
                                   routing::send<NV, stereo_cable<NV>>, 
                                   jdsp::jpanner<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                   smoothed_parameter_unscaled10_t<NV>, 
                                   jdsp::jdelay_thiran<NV>, 
                                   filters::one_pole<NV>, 
                                   routing::send<NV, stereo_cable<NV>>, 
                                   jdsp::jpanner<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain22_t<NV>>, 
                                  chain15_t<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                   smoothed_parameter_unscaled9_t<NV>, 
                                   jdsp::jdelay_thiran<NV>, 
                                   filters::one_pole<NV>, 
                                   routing::send<NV, stereo_cable<NV>>, 
                                   jdsp::jpanner<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                   smoothed_parameter_unscaled11_t<NV>, 
                                   jdsp::jdelay_thiran<NV>, 
                                   filters::one_pole<NV>, 
                                   routing::send<NV, stereo_cable<NV>>, 
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
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, chain13_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, modchain1_t<NV>>, 
                                  fix8_block_t<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain2_t<NV>>, 
                                 chain3_t<NV>>;

namespace dlay_t_parameters
{
// Parameter list for dlay_impl::dlay_t ------------------------------------------------------------

template <int NV>
using Feedback = parameter::chain<ranges::Identity, 
                                  parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>, 
                                  parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>, 
                                  parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>, 
                                  parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>>;

DECLARE_PARAMETER_RANGE(DtimeRRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using DtimeR = parameter::from0To1<dlay_impl::pma1_t<NV>, 
                                   2, 
                                   DtimeRRange>;

DECLARE_PARAMETER_RANGE_SKEW(Tone_InputRange, 
                             0., 
                             1., 
                             0.277381);
DECLARE_PARAMETER_RANGE_SKEW(Tone_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using Tone_0 = parameter::from0To1<filters::one_pole<NV>, 
                                   0, 
                                   Tone_0Range>;

template <int NV> using Tone_1 = Tone_0<NV>;

template <int NV> using Tone_2 = Tone_0<NV>;

template <int NV> using Tone_3 = Tone_0<NV>;

template <int NV>
using Tone = parameter::chain<Tone_InputRange, 
                              Tone_0<NV>, 
                              Tone_1<NV>, 
                              Tone_2<NV>, 
                              Tone_3<NV>>;

template <int NV>
using mod = parameter::chain<ranges::Identity, 
                             parameter::plain<dlay_impl::pma_t<NV>, 1>, 
                             parameter::plain<dlay_impl::pma1_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(MODSRC_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(MODSRC_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using MODSRC_0 = parameter::from0To1<dlay_impl::branch28_t<NV>, 
                                     0, 
                                     MODSRC_0Range>;

template <int NV>
using MODSRC = parameter::chain<MODSRC_InputRange, MODSRC_0<NV>>;

template <int NV>
using Divide = parameter::chain<ranges::Identity, 
                                parameter::plain<dlay_impl::tempo_sync3_t<NV>, 1>, 
                                parameter::plain<dlay_impl::tempo_sync_t<NV>, 1>>;

template <int NV>
using Mix = parameter::plain<dlay_impl::xfader_t<NV>, 
                             0>;
using Mode = parameter::empty;
template <int NV>
using Sync = parameter::plain<dlay_impl::tempo_sync3_t<NV>, 
                              2>;
template <int NV>
using DTime = parameter::plain<dlay_impl::pma_t<NV>, 2>;
template <int NV>
using PingPong = parameter::plain<dlay_impl::branch9_t<NV>, 
                                  0>;
template <int NV>
using dlay_t_plist = parameter::list<Mix<NV>, 
                                     Feedback<NV>, 
                                     Mode, 
                                     Sync<NV>, 
                                     DTime<NV>, 
                                     DtimeR<NV>, 
                                     PingPong<NV>, 
                                     Tone<NV>, 
                                     mod<NV>, 
                                     MODSRC<NV>, 
                                     Divide<NV>>;
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
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(dlay);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(184)
		{
			0x005C, 0x0000, 0x0000, 0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x0A3F, 0x23D7, 0x003E, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0100, 0x0000, 0x4600, 0x6565, 0x6264, 0x6361, 0x006B, 0x0000, 
            0x0000, 0x0000, 0x8000, 0xAE3F, 0x6147, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x0200, 0x0000, 0x4D00, 0x646F, 0x0065, 0x0000, 
            0x0000, 0x0000, 0xA000, 0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x0300, 0x0000, 0x5300, 0x6E79, 0x0063, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x0400, 0x0000, 0x4400, 0x6954, 0x656D, 0x0000, 
            0x0000, 0x2480, 0x0000, 0x3F80, 0x147B, 0x3F2E, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0005, 0x0000, 0x7444, 0x6D69, 0x5265, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0xD70A, 0x3F23, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0006, 0x0000, 0x6950, 0x676E, 
            0x6F50, 0x676E, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0007, 0x0000, 
            0x6F54, 0x656E, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x851F, 
            0x3EEB, 0x04DF, 0x3E8E, 0x0000, 0x0000, 0x005C, 0x0008, 0x0000, 
            0x6F6D, 0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0900, 0x0000, 0x4D00, 
            0x444F, 0x5253, 0x0043, 0x0000, 0x8000, 0x003F, 0x4000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0A00, 0x0000, 
            0x4400, 0x7669, 0x6469, 0x0065, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0041, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
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
		auto& peak1 = this->getT(1).getT(1).getT(0).getT(0).getT(1);                         // dlay_impl::peak1_t<NV>
		auto& split3 = this->getT(1).getT(1).getT(0).getT(1);                                // dlay_impl::split3_t<NV>
		auto& chain34 = this->getT(1).getT(1).getT(0).getT(1).getT(0);                       // dlay_impl::chain34_t<NV>
		auto& pma = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(0);                   // dlay_impl::pma_t<NV>
		auto& minmax = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(1);                // control::minmax<NV, parameter::empty>
		auto& tempo_sync3 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(2);           // dlay_impl::tempo_sync3_t<NV>
		auto& chain35 = this->getT(1).getT(1).getT(0).getT(1).getT(1);                       // dlay_impl::chain35_t<NV>
		auto& pma1 = this->getT(1).getT(1).getT(0).getT(1).getT(1).getT(0);                  // dlay_impl::pma1_t<NV>
		auto& minmax2 = this->getT(1).getT(1).getT(0).getT(1).getT(1).getT(1);               // control::minmax<NV, parameter::empty>
		auto& tempo_sync = this->getT(1).getT(1).getT(0).getT(1).getT(1).getT(2);            // dlay_impl::tempo_sync_t<NV>
		auto& fix8_block = this->getT(1).getT(1).getT(1);                                    // dlay_impl::fix8_block_t<NV>
		auto& chain13 = this->getT(1).getT(1).getT(1).getT(0);                               // dlay_impl::chain13_t<NV>
		auto& branch9 = this->getT(1).getT(1).getT(1).getT(0).getT(0);                       // dlay_impl::branch9_t<NV>
		auto& split1 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(0);                // dlay_impl::split1_t<NV>
		auto& chain22 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(0).getT(0);       // dlay_impl::chain22_t<NV>
		auto& receive1 = this->getT(1).getT(1).getT(1).getT(0).                              // routing::receive<NV, stereo_cable<NV>>
                         getT(0).getT(0).getT(0).getT(0);
		auto& smoothed_parameter_unscaled7 = this->getT(1).getT(1).getT(1).getT(0).    // dlay_impl::smoothed_parameter_unscaled7_t<NV>
                                             getT(0).getT(0).getT(0).getT(1);
		auto& jdelay_thiran1 = this->getT(1).getT(1).getT(1).getT(0).                  // jdsp::jdelay_thiran<NV>
                               getT(0).getT(0).getT(0).getT(2);
		auto& one_pole3 = this->getT(1).getT(1).getT(1).getT(0).                       // filters::one_pole<NV>
                          getT(0).getT(0).getT(0).getT(3);
		auto& send1 = this->getT(1).getT(1).getT(1).getT(0).                           // routing::send<NV, stereo_cable<NV>>
                      getT(0).getT(0).getT(0).getT(4);
		auto& jpanner = this->getT(1).getT(1).getT(1).getT(0).                         // jdsp::jpanner<NV>
                        getT(0).getT(0).getT(0).getT(5);
		auto& chain15 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(0).getT(1); // dlay_impl::chain15_t<NV>
		auto& receive2 = this->getT(1).getT(1).getT(1).getT(0).                        // routing::receive<NV, stereo_cable<NV>>
                         getT(0).getT(0).getT(1).getT(0);
		auto& smoothed_parameter_unscaled10 = this->getT(1).getT(1).getT(1).getT(0).   // dlay_impl::smoothed_parameter_unscaled10_t<NV>
                                              getT(0).getT(0).getT(1).getT(1);
		auto& jdelay_thiran4 = this->getT(1).getT(1).getT(1).getT(0).                  // jdsp::jdelay_thiran<NV>
                               getT(0).getT(0).getT(1).getT(2);
		auto& one_pole4 = this->getT(1).getT(1).getT(1).getT(0).                       // filters::one_pole<NV>
                          getT(0).getT(0).getT(1).getT(3);
		auto& send2 = this->getT(1).getT(1).getT(1).getT(0).                           // routing::send<NV, stereo_cable<NV>>
                      getT(0).getT(0).getT(1).getT(4);
		auto& jpanner1 = this->getT(1).getT(1).getT(1).getT(0).                        // jdsp::jpanner<NV>
                         getT(0).getT(0).getT(1).getT(5);
		auto& split2 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(1);          // dlay_impl::split2_t<NV>
		auto& chain23 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(1).getT(0); // dlay_impl::chain23_t<NV>
		auto& receive3 = this->getT(1).getT(1).getT(1).getT(0).                        // routing::receive<NV, stereo_cable<NV>>
                         getT(0).getT(1).getT(0).getT(0);
		auto& smoothed_parameter_unscaled9 = this->getT(1).getT(1).getT(1).getT(0).    // dlay_impl::smoothed_parameter_unscaled9_t<NV>
                                             getT(0).getT(1).getT(0).getT(1);
		auto& jdelay_thiran3 = this->getT(1).getT(1).getT(1).getT(0).                  // jdsp::jdelay_thiran<NV>
                               getT(0).getT(1).getT(0).getT(2);
		auto& one_pole5 = this->getT(1).getT(1).getT(1).getT(0).                       // filters::one_pole<NV>
                          getT(0).getT(1).getT(0).getT(3);
		auto& send3 = this->getT(1).getT(1).getT(1).getT(0).                           // routing::send<NV, stereo_cable<NV>>
                      getT(0).getT(1).getT(0).getT(4);
		auto& jpanner2 = this->getT(1).getT(1).getT(1).getT(0).                        // jdsp::jpanner<NV>
                         getT(0).getT(1).getT(0).getT(5);
		auto& chain24 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(1).getT(1); // dlay_impl::chain24_t<NV>
		auto& receive4 = this->getT(1).getT(1).getT(1).getT(0).                        // routing::receive<NV, stereo_cable<NV>>
                         getT(0).getT(1).getT(1).getT(0);
		auto& smoothed_parameter_unscaled11 = this->getT(1).getT(1).getT(1).getT(0).  // dlay_impl::smoothed_parameter_unscaled11_t<NV>
                                              getT(0).getT(1).getT(1).getT(1);
		auto& jdelay_thiran2 = this->getT(1).getT(1).getT(1).getT(0).  // jdsp::jdelay_thiran<NV>
                               getT(0).getT(1).getT(1).getT(2);
		auto& one_pole6 = this->getT(1).getT(1).getT(1).getT(0).  // filters::one_pole<NV>
                          getT(0).getT(1).getT(1).getT(3);
		auto& send4 = this->getT(1).getT(1).getT(1).getT(0).     // routing::send<NV, stereo_cable<NV>>
                      getT(0).getT(1).getT(1).getT(4);
		auto& jpanner3 = this->getT(1).getT(1).getT(1).getT(0).  // jdsp::jpanner<NV>
                         getT(0).getT(1).getT(1).getT(5);
		auto& gain1 = this->getT(1).getT(1).getT(2); // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader); // Mix -> xfader::Value
		
		auto& Feedback_p = this->getParameterT(1);
		Feedback_p.connectT(0, receive1); // Feedback -> receive1::Feedback
		Feedback_p.connectT(1, receive2); // Feedback -> receive2::Feedback
		Feedback_p.connectT(2, receive3); // Feedback -> receive3::Feedback
		Feedback_p.connectT(3, receive4); // Feedback -> receive4::Feedback
		
		this->getParameterT(3).connectT(0, tempo_sync3); // Sync -> tempo_sync3::Enabled
		
		this->getParameterT(4).connectT(0, pma); // DTime -> pma::Add
		
		this->getParameterT(5).connectT(0, pma1); // DtimeR -> pma1::Add
		
		this->getParameterT(6).connectT(0, branch9); // PingPong -> branch9::Index
		
		auto& Tone_p = this->getParameterT(7);
		Tone_p.connectT(0, one_pole3); // Tone -> one_pole3::Frequency
		Tone_p.connectT(1, one_pole4); // Tone -> one_pole4::Frequency
		Tone_p.connectT(2, one_pole5); // Tone -> one_pole5::Frequency
		Tone_p.connectT(3, one_pole6); // Tone -> one_pole6::Frequency
		
		auto& mod_p = this->getParameterT(8);
		mod_p.connectT(0, pma);  // mod -> pma::Multiply
		mod_p.connectT(1, pma1); // mod -> pma1::Multiply
		
		this->getParameterT(9).connectT(0, branch28); // MODSRC -> branch28::Index
		
		auto& Divide_p = this->getParameterT(10);
		Divide_p.connectT(0, tempo_sync3); // Divide -> tempo_sync3::Multiplier
		Divide_p.connectT(1, tempo_sync);  // Divide -> tempo_sync::Multiplier
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                              // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);                             // xfader -> gain1::Gain
		global_cable.getWrappedObject().getParameter().connectT(0, add);          // global_cable -> add::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add3);        // global_cable3 -> add3::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2);        // global_cable2 -> add2::Value
		smoothed_parameter_unscaled7.getParameter().connectT(0, jdelay_thiran1);  // smoothed_parameter_unscaled7 -> jdelay_thiran1::DelayTime
		smoothed_parameter_unscaled9.getParameter().connectT(0, jdelay_thiran3);  // smoothed_parameter_unscaled9 -> jdelay_thiran3::DelayTime
		tempo_sync3.getParameter().connectT(0, smoothed_parameter_unscaled7);     // tempo_sync3 -> smoothed_parameter_unscaled7::Value
		tempo_sync3.getParameter().connectT(1, smoothed_parameter_unscaled9);     // tempo_sync3 -> smoothed_parameter_unscaled9::Value
		pma.getWrappedObject().getParameter().connectT(0, tempo_sync3);           // pma -> tempo_sync3::UnsyncedTime
		pma.getWrappedObject().getParameter().connectT(1, tempo_sync3);           // pma -> tempo_sync3::Tempo
		pma.getWrappedObject().getParameter().connectT(2, minmax);                // pma -> minmax::Value
		smoothed_parameter_unscaled10.getParameter().connectT(0, jdelay_thiran4); // smoothed_parameter_unscaled10 -> jdelay_thiran4::DelayTime
		smoothed_parameter_unscaled11.getParameter().connectT(0, jdelay_thiran2); // smoothed_parameter_unscaled11 -> jdelay_thiran2::DelayTime
		tempo_sync.getParameter().connectT(0, smoothed_parameter_unscaled10);     // tempo_sync -> smoothed_parameter_unscaled10::Value
		tempo_sync.getParameter().connectT(1, smoothed_parameter_unscaled11);     // tempo_sync -> smoothed_parameter_unscaled11::Value
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync);           // pma1 -> tempo_sync::Tempo
		pma1.getWrappedObject().getParameter().connectT(1, minmax2);              // pma1 -> minmax2::Value
		pma1.getWrappedObject().getParameter().connectT(2, tempo_sync);           // pma1 -> tempo_sync::UnsyncedTime
		peak1.getParameter().connectT(0, pma);                                    // peak1 -> pma::Value
		peak1.getParameter().connectT(1, pma1);                                   // peak1 -> pma1::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send1.connect(receive1);
		send2.connect(receive2);
		send3.connect(receive4);
		send4.connect(receive3);
		
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
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                             // minmax::Value is automated
		minmax.setParameterT(1, 12.); // control::minmax::Minimum
		minmax.setParameterT(2, 16.); // control::minmax::Maximum
		minmax.setParameterT(3, 1.);  // control::minmax::Skew
		minmax.setParameterT(4, 0.);  // control::minmax::Step
		minmax.setParameterT(5, 1.);  // control::minmax::Polarity
		
		; // tempo_sync3::Tempo is automated
		; // tempo_sync3::Multiplier is automated
		; // tempo_sync3::Enabled is automated
		; // tempo_sync3::UnsyncedTime is automated
		
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
		;                                // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.); // control::tempo_sync::Enabled
		;                                // tempo_sync::UnsyncedTime is automated
		
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
		
		jpanner3.setParameterT(0, 1.); // jdsp::jpanner::Pan
		jpanner3.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.16);
		this->setParameterT(1, 0.88);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.68);
		this->setParameterT(5, 0.64);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.46);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 2.);
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
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // dlay_impl::global_cable_t<NV>
		this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // dlay_impl::global_cable3_t<NV>
		this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // dlay_impl::global_cable2_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(1).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index); // dlay_impl::peak1_t<NV>
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


