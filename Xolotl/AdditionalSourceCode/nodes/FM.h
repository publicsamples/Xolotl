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

namespace FM_impl
{
// =====================| Node & Parameter type declarations |=====================

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

using xfader_c0 = parameter::from0To1<core::gain, 
                                      0, 
                                      xfader_c0Range>;

using xfader_c1 = xfader_c0;

using xfader_multimod = parameter::list<xfader_c0, xfader_c1>;

using xfader_t = control::xfader<xfader_multimod, faders::linear>;

using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain>>;

using midichain_t_ = container::chain<parameter::empty, wrap::fix<2, core::fm>>;

using midichain_t = wrap::event<midichain_t_>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, midichain_t>, 
                                  core::mono2stereo, 
                                  core::gain>;

using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t>, 
                                 chain1_t>;

namespace FM_t_parameters
{
// Parameter list for FM_impl::FM_t ----------------------------------------------

using fmmix = parameter::plain<FM_impl::xfader_t, 0>;
using freq = parameter::plain<core::fm, 0>;
using modulator = parameter::plain<core::fm, 1>;
using mul = parameter::plain<core::fm, 2>;
using FM_t_plist = parameter::list<fmmix, 
                                   freq, 
                                   modulator, 
                                   mul>;
}

using FM_t_ = container::chain<FM_t_parameters::FM_t_plist, 
                               wrap::fix<2, xfader_t>, 
                               split_t>;

// ========================| Root node initialiser class |========================

struct instance: public FM_impl::FM_t_
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(FM);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(64)
		{
			0x005B, 0x0000, 0x6600, 0x6D6D, 0x7869, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x7266, 0x7165, 0x0000, 0xA000, 0x0041, 0x9C40, 
            0x0046, 0x9C40, 0x1A46, 0x6B6C, 0xCD3E, 0xCCCC, 0x5B3D, 0x0002, 
            0x0000, 0x6F6D, 0x7564, 0x616C, 0x6F74, 0x0072, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x035B, 0x0000, 0x6D00, 0x6C75, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0041, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------
		
		auto& xfader = this->getT(0);                      // FM_impl::xfader_t
		auto& split = this->getT(1);                       // FM_impl::split_t
		auto& chain = this->getT(1).getT(0);               // FM_impl::chain_t
		auto& gain = this->getT(1).getT(0).getT(0);        // core::gain
		auto& chain1 = this->getT(1).getT(1);              // FM_impl::chain1_t
		auto& midichain = this->getT(1).getT(1).getT(0);   // FM_impl::midichain_t
		auto& fm = this->getT(1).getT(1).getT(0).getT(0);  // core::fm
		auto& mono2stereo = this->getT(1).getT(1).getT(1); // core::mono2stereo
		auto& gain1 = this->getT(1).getT(1).getT(2);       // core::gain
		
		// Parameter Connections -------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader); // fmmix -> xfader::Value
		
		this->getParameterT(1).connectT(0, fm); // freq -> fm::Frequency
		
		this->getParameterT(2).connectT(0, fm); // modulator -> fm::Modulator
		
		this->getParameterT(3).connectT(0, fm); // mul -> fm::FreqMultiplier
		
		// Modulation Connections ------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);  // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1); // xfader -> gain1::Gain
		
		// Default Values --------------------------------------------------------
		
		; // xfader::Value is automated
		
		;                            // gain::Gain is automated
		gain.setParameterT(1, 20.);  // core::gain::Smoothing
		gain.setParameterT(2, -21.); // core::gain::ResetValue
		
		;                        // fm::Frequency is automated
		;                        // fm::Modulator is automated
		;                        // fm::FreqMultiplier is automated
		fm.setParameterT(3, 1.); // core::fm::Gate
		
		;                             // gain1::Gain is automated
		gain1.setParameterT(1, 20.);  // core::gain::Smoothing
		gain1.setParameterT(2, -21.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 20000.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 2.);
	}
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return true; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// =============================| Public Definition |=============================

namespace project
{
using FM = wrap::node<FM_impl::instance>;
}


