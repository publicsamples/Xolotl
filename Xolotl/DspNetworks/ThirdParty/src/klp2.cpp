/* ------------------------------------------------------------
name: "klp2"
Code generated with Faust 2.81.2 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _klp2 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___klp2_H__
#define  ___klp2_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _klp2
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif


struct _klp2 final : public ::faust::dsp {
	
	FAUSTFLOAT fEntry0;
	int iVec0[2];
	int iRec0[2];
	int IOTA0;
	float fVec1[65536];
	int iRec1[2];
	int fSampleRate;
	
	_klp2() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _klp2 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("demos.lib/name", "Faust Demos Library");
		m->declare("demos.lib/reverse_echo_demo:author", "Julius O. Smith III");
		m->declare("demos.lib/reverse_echo_demo:licence", "MIT");
		m->declare("demos.lib/version", "1.2.0");
		m->declare("filename", "klp2.dsp");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/reverseDelayRamped:author", "Julius O. Smith III");
		m->declare("misceffects.lib/reverseDelayRamped:license", "STK-4.3");
		m->declare("misceffects.lib/reverseEchoN:author", "Julius O. Smith III");
		m->declare("misceffects.lib/reverseEchoN:license", "STK-4.3");
		m->declare("misceffects.lib/uniformPanToStereo:author", "Julius O. Smith III");
		m->declare("misceffects.lib/uniformPanToStereo:license", "STK-4.3");
		m->declare("misceffects.lib/version", "2.5.1");
		m->declare("name", "klp2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
	}

	static constexpr int getStaticNumInputs() {
		return 1;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 1;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
	}
	
	void instanceResetUserInterface() {
		fEntry0 = FAUSTFLOAT(15.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec0[l1] = 0;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 65536; l2 = l2 + 1) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec1[l3] = 0;
		}
	}
	
	void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	_klp2* clone() {
		return new _klp2();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("klp2");
		ui_interface->addNumEntry("Log2(Delay)", &fEntry0, FAUSTFLOAT(15.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(16.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		int iSlow0 = int(std::pow(float(2), float(int(std::max<float>(5.0f, std::min<float>(16.0f, float(fEntry0)))))));
		float fSlow1 = float(iSlow0);
		float fSlow2 = 4.0f / fSlow1;
		int iSlow3 = int(std::floor(0.5f * (fSlow1 + 1.0f)));
		int iSlow4 = iSlow0 + -1;
		float fSlow5 = 1.0f / fSlow1;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			iRec0[0] = iRec0[1] + iSlow3 * (1 - iVec0[1]) + 2;
			int iTemp0 = iRec0[0] & iSlow4;
			float fTemp1 = float(iTemp0);
			float fTemp2 = float(input0[i0]);
			fVec1[IOTA0 & 65535] = fTemp2;
			output0[i0] = FAUSTFLOAT(fSlow2 * fTemp1 * (1.0f - fSlow5 * fTemp1) * fVec1[(IOTA0 - std::min<int>(iSlow0, std::max<int>(0, iTemp0))) & 65535]);
			iRec1[0] = iRec1[1] + 2;
			int iTemp3 = iRec1[0] & iSlow4;
			float fTemp4 = float(iTemp3);
			output1[i0] = FAUSTFLOAT(fSlow2 * fTemp4 * (1.0f - fSlow5 * fTemp4) * fVec1[(IOTA0 - std::min<int>(iSlow0, std::max<int>(0, iTemp3))) & 65535]);
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
			IOTA0 = IOTA0 + 1;
			iRec1[1] = iRec1[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "klp2.dsp"
	#define FAUST_CLASS_NAME "_klp2"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _klp2 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 1
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 1
	#define FAUST_PASSIVES 0

	FAUST_ADDNUMENTRY("Log2(Delay)", fEntry0, 15.0f, 5.0f, 16.0f, 1.0f);

	#define FAUST_LIST_ACTIVES(p) \
		p(NUMENTRY, Log2(Delay), "Log2(Delay)", fEntry0, 15.0f, 5.0f, 16.0f, 1.0f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
