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

namespace minmax_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, control::minmax<NV, parameter::empty>>>;
template <int NV>
using clone_t = wrap::fix_clonecopy<clone_child_t<NV>, 4>;

template <int NV>
using minmax_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, clone_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public minmax_impl::minmax_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(minmax);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(2)
		{
			0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& clone = this->getT(0);          // minmax_impl::clone_t<NV>          // minmax_impl::clone_child_t<NV>
		auto minmax1 = this->getT(0).getT(0); // control::minmax<NV, parameter::empty>
		
		// Default Values --------------------------------------------------------------------------
		
		clone.setParameterT(0, 4.); // container::clone::NumClones
		clone.setParameterT(1, 2.); // container::clone::SplitSignal
		
		minmax1.setParameterT(0, 0.); // control::minmax::Value
		minmax1.setParameterT(1, 0.); // control::minmax::Minimum
		minmax1.setParameterT(2, 1.); // control::minmax::Maximum
		minmax1.setParameterT(3, 1.); // control::minmax::Skew
		minmax1.setParameterT(4, 0.); // control::minmax::Step
		minmax1.setParameterT(5, 0.); // control::minmax::Polarity
		
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
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
using minmax = wrap::node<minmax_impl::instance<NV>>;
}


