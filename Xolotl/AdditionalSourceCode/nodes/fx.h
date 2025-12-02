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

namespace fx_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(clone_pack_modRange, 
                             0., 
                             1000., 
                             0.30103);

using clone_pack_mod = parameter::from0To1<core::fix_delay, 
                                           0, 
                                           clone_pack_modRange>;

using clone_pack_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack_mod>>, 
                                data::external::sliderpack<0>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_cable3_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using clone_cable3_mod = parameter::from0To1<filters::one_pole<NV>, 
                                             0, 
                                             clone_cable3_modRange>;

template <int NV>
using clone_cable3_t = control::clone_cable<parameter::cloned<clone_cable3_mod<NV>>, 
                                            duplilogic::fixed>;
using global_cable_t_index = runtime_target::indexers::fix_hash<3357039>;

template <int NV>
using smoothed_parameter_t = wrap::mod<parameter::plain<clone_pack_t, 1>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<smoothed_parameter_t<NV>, 0>>;
template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<pma_t<NV>, 0>>;

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
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, clone_pack_t>, 
                                  clone_cable3_t<NV>, 
                                  global_cable_t<NV>, 
                                  pma_t<NV>, 
                                  smoothed_parameter_t<NV>, 
                                  xfader_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split2_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain<NV>>>;
template <int NV>
using stereo_cable = cable::block<NV, 2>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::fix_delay>, 
                                  filters::one_pole<NV>>;

template <int NV>
using clone2_child_t = container::chain<parameter::empty, 
                                        wrap::fix<2, chain5_t<NV>>>;
template <int NV>
using clone2_t = wrap::fix_clonesplit<clone2_child_t<NV>, 4>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                       clone2_t<NV>, 
                                       routing::send<NV, stereo_cable<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, fix8_block_t<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain1_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  split_t<NV>>;

namespace fx_t_parameters
{
// Parameter list for fx_impl::fx_t ----------------------------------------------------------------

DECLARE_PARAMETER_RANGE(OffsetRange, 
                        -1., 
                        1.);

template <int NV>
using Offset = parameter::from0To1<fx_impl::pma_t<NV>, 
                                   2, 
                                   OffsetRange>;

template <int NV>
using Feeback = parameter::plain<routing::receive<NV, stereo_cable<NV>>, 
                                 0>;
template <int NV>
using LP = parameter::plain<fx_impl::clone_cable3_t<NV>, 
                            1>;
template <int NV>
using Mod = parameter::plain<fx_impl::pma_t<NV>, 1>;
template <int NV>
using Mix = parameter::plain<fx_impl::xfader_t<NV>, 0>;
template <int NV>
using fx_t_plist = parameter::list<Offset<NV>, 
                                   Feeback<NV>, 
                                   LP<NV>, 
                                   Mod<NV>, 
                                   Mix<NV>>;
}

template <int NV>
using fx_t_ = container::chain<fx_t_parameters::fx_t_plist<NV>, 
                               wrap::fix<2, chain4_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public fx_impl::fx_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(fx);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(82)
		{
			0x005C, 0x0000, 0x0000, 0x664F, 0x7366, 0x7465, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0001, 0x0000, 0x6546, 0x6265, 0x6361, 0x006B, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x0200, 0x0000, 0x4C00, 0x0050, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x0300, 0x0000, 0x4D00, 0x646F, 0x0000, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0xCCCD, 0x3D4C, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0004, 0x0000, 0x694D, 0x0078, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x213F, 0x678B, 0x003F, 0x8000, 0x003F, 0x0000, 
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
		
		auto& chain4 = this->getT(0);                                                   // fx_impl::chain4_t<NV>
		auto& modchain = this->getT(0).getT(0);                                         // fx_impl::modchain_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(0);                                   // fx_impl::split2_t<NV>
		auto& clone_pack = this->getT(0).getT(0).getT(0).getT(0);                       // fx_impl::clone_pack_t
		auto& clone_cable3 = this->getT(0).getT(0).getT(0).getT(1);                     // fx_impl::clone_cable3_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(2);                     // fx_impl::global_cable_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0).getT(3);                              // fx_impl::pma_t<NV>
		auto& smoothed_parameter = this->getT(0).getT(0).getT(0).getT(4);               // fx_impl::smoothed_parameter_t<NV>
		auto& xfader = this->getT(0).getT(0).getT(0).getT(5);                           // fx_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(1);                                            // fx_impl::split_t<NV>
		auto& chain = this->getT(0).getT(1).getT(0);                                    // fx_impl::chain_t<NV>
		auto& gain = this->getT(0).getT(1).getT(0).getT(0);                             // core::gain<NV>
		auto& chain1 = this->getT(0).getT(1).getT(1);                                   // fx_impl::chain1_t<NV>
		auto& fix8_block = this->getT(0).getT(1).getT(1).getT(0);                       // fx_impl::fix8_block_t<NV>
		auto& receive = this->getT(0).getT(1).getT(1).getT(0).getT(0);                  // routing::receive<NV, stereo_cable<NV>>
		auto& clone2 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                   // fx_impl::clone2_t<NV>                   // fx_impl::clone2_child_t<NV>
		auto chain5 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0);            // fx_impl::chain5_t<NV>
		auto fix_delay = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(0); // core::fix_delay
		auto one_pole = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(1);  // filters::one_pole<NV>
		auto& send = this->getT(0).getT(1).getT(1).getT(0).getT(2);                     // routing::send<NV, stereo_cable<NV>>
		auto& gain1 = this->getT(0).getT(1).getT(1).getT(1);                            // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma); // Offset -> pma::Add
		
		this->getParameterT(1).connectT(0, receive); // Feeback -> receive::Feedback
		
		this->getParameterT(2).connectT(0, clone_cable3); // LP -> clone_cable3::Value
		
		this->getParameterT(3).connectT(0, pma); // Mod -> pma::Multiply
		
		this->getParameterT(4).connectT(0, xfader); // Mix -> xfader::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		clone_pack.getWrappedObject().getParameter().connectT(0, fix_delay);   // clone_pack -> fix_delay::DelayTime
		clone_cable3.getWrappedObject().getParameter().connectT(0, one_pole);  // clone_cable3 -> one_pole::Frequency
		smoothed_parameter.getParameter().connectT(0, clone_pack);             // smoothed_parameter -> clone_pack::Value
		pma.getWrappedObject().getParameter().connectT(0, smoothed_parameter); // pma -> smoothed_parameter::Value
		global_cable.getWrappedObject().getParameter().connectT(0, pma);       // global_cable -> pma::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);  // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1); // xfader -> gain1::Gain
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values --------------------------------------------------------------------------
		
		clone_pack.setParameterT(0, 4.); // control::clone_pack::NumClones
		;                                // clone_pack::Value is automated
		
		;                                  // clone_cable3::NumClones is deactivated
		;                                  // clone_cable3::Value is automated
		clone_cable3.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                                          // smoothed_parameter::Value is automated
		smoothed_parameter.setParameterT(1, 98.1); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // receive::Feedback is automated
		
		clone2.setParameterT(0, 4.); // container::clone::NumClones
		clone2.setParameterT(1, 1.); // container::clone::SplitSignal
		
		;                                  // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 1024.); // core::fix_delay::FadeTime
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.05);
		this->setParameterT(4, 0.904467);
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
		
		this->getT(0).getT(0).getT(0).getT(2).connectToRuntimeTarget(addConnection, c); // fx_impl::global_cable_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // fx_impl::clone_pack_t
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
using fx = wrap::node<fx_impl::instance<NV>>;
}


