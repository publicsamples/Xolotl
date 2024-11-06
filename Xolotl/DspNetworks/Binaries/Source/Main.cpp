/** Autogenerated Main.cpp. */

// =============================| Include only the DSP files  |=============================

#include <AppConfig.h>
#include <hi_dsp_library/hi_dsp_library.h>
#include <hi_faust/hi_faust.h>
#include "includes.h"
// =======================| Now we can add the rest of the codebase |=======================

#include <JuceHeader.h>

#if !JUCE_WINDOWS
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
#endif

// ===================================| Project Factory |===================================

namespace project
{

struct Factory: public scriptnode::dll::StaticLibraryHostFactory
{
	Factory()
	{
		TempoSyncer::initTempoData();
		// Node registrations -------------------------------------------------------------
		
		registerPolyNode<project::RevDel<1>, wrap::illegal_poly<project::RevDel<1>>>();
		registerPolyNode<project::OBLP<1>, wrap::illegal_poly<project::OBLP<1>>>();
		registerPolyNode<project::LPF<1>, wrap::illegal_poly<project::LPF<1>>>();
		registerPolyNode<project::klp2<1>, wrap::illegal_poly<project::klp2<1>>>();
		registerPolyNode<project::HPF<1>, wrap::illegal_poly<project::HPF<1>>>();
		registerPolyNode<project::granular<1>, wrap::illegal_poly<project::granular<1>>>();
		registerPolyNode<project::Comb<1>, project::Comb<NUM_POLYPHONIC_VOICES>>();
		registerPolyNode<project::BPF<1>, wrap::illegal_poly<project::BPF<1>>>();
		registerPolyNode<project::dlay<1>, wrap::illegal_poly<project::dlay<1>>>();
		registerPolyNode<project::modtest1<1>, wrap::illegal_poly<project::modtest1<1>>>();
		registerPolyNode<project::Xarrange<1>, project::Xarrange<NUM_POLYPHONIC_VOICES>>();
		registerPolyNode<project::xnode<1>, project::xnode<NUM_POLYPHONIC_VOICES>>();
	}
};
}

project::Factory f;

// ===============================| Exported DLL functions |===============================

DLL_EXPORT int getNumNodes()
{
	return f.getNumNodes();
}

DLL_EXPORT size_t getNodeId(int index, char* t)
{
	return HelperFunctions::writeString(t, f.getId(index).getCharPointer());
}

DLL_EXPORT bool isThirdPartyNode(int index)
{
	return index < 8;
}

DLL_EXPORT int getNumDataObjects(int nodeIndex, int dataTypeAsInt)
{
	return f.getNumDataObjects(nodeIndex, dataTypeAsInt);
}

DLL_EXPORT void deInitOpaqueNode(scriptnode::OpaqueNode* n)
{
	n->callDestructor();
}

DLL_EXPORT void initOpaqueNode(scriptnode::OpaqueNode* n, int index, bool polyIfPossible)
{
	f.initOpaqueNode(n, index, polyIfPossible);
}
DLL_EXPORT int getHash(int index)
{
	static const int thirdPartyOffset = 8;
	static const int hashIndexes[4] =
	{
		-1505652257,
		2099108141,
		177662692,
		-705438000
	};
	return (index >= thirdPartyOffset) ? hashIndexes[index - thirdPartyOffset] : 0;
}
DLL_EXPORT int getWrapperType(int index)
{
	return f.getWrapperType(index);
}
DLL_EXPORT ErrorC getError()
{
	return f.getError();
}
DLL_EXPORT void clearError()
{
	f.clearError();
}
DLL_EXPORT int getDllVersionCounter()
{
	return scriptnode::dll::ProjectDll::DllUpdateCounter;
}

#if !JUCE_WINDOWS
#pragma clang diagnostic pop
#endif


