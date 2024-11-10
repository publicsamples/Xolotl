/* ------------------------------------------------------------
name: "LPF"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _LPF -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___LPF_H__
#define  ___LPF_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _LPF
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


struct _LPF final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fConst3;
	float fRec3[2];
	FAUSTFLOAT fHslider1;
	float fRec0[2];
	float fRec1[2];
	float fRec4[2];
	float fRec5[2];
	
	_LPF() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _LPF -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "LPF.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "LPF");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/sallenKey2ndOrder:author", "Eric Tarr");
		m->declare("vaeffects.lib/sallenKey2ndOrder:license", "MIT-style STK-4.3 license");
		m->declare("vaeffects.lib/sallenKey2ndOrderLPF:author", "Eric Tarr");
		m->declare("vaeffects.lib/sallenKey2ndOrderLPF:license", "MIT-style STK-4.3 license");
		m->declare("vaeffects.lib/version", "1.2.1");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 6.2831855f / fConst0;
		fConst2 = 44.1f / fConst0;
		fConst3 = 1.0f - fConst2;
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(1.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec3[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec5[l4] = 0.0f;
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
	
	_LPF* clone() {
		return new _LPF();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("LPF");
		ui_interface->addHorizontalSlider("Q", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.9f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst2 * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0)));
		float fSlow1 = 1.0f / std::max<float>(1.0f, std::min<float>(9.9f, float(fHslider1)));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec3[0] = fSlow0 + fConst3 * fRec3[1];
			float fTemp0 = std::tan(fConst1 * std::pow(1e+01f, 3.0f * fRec3[0] + 1.0f));
			float fTemp1 = fSlow1 + fTemp0;
			float fTemp2 = float(input0[i0]) - (fTemp1 * fRec1[1] + fRec0[1]);
			float fTemp3 = fTemp0 * fTemp1 + 1.0f;
			float fTemp4 = fTemp0 * fTemp2 / fTemp3;
			float fTemp5 = fTemp4 + fRec1[1];
			fRec0[0] = 2.0f * fTemp0 * fTemp5 + fRec0[1];
			float fTemp6 = 2.0f * fTemp4 + fRec1[1];
			fRec1[0] = fTemp6;
			float fRec2 = fTemp0 * fTemp6 + fRec0[1];
			output0[i0] = FAUSTFLOAT(fRec2);
			float fTemp7 = float(input1[i0]) - (fRec4[1] + fTemp1 * fRec5[1]);
			float fTemp8 = fTemp0 * fTemp7 / fTemp3;
			float fTemp9 = fRec5[1] + fTemp8;
			fRec4[0] = fRec4[1] + 2.0f * fTemp0 * fTemp9;
			float fTemp10 = fRec5[1] + 2.0f * fTemp8;
			fRec5[0] = fTemp10;
			float fRec6 = fRec4[1] + fTemp0 * fTemp10;
			output1[i0] = FAUSTFLOAT(fRec6);
			fRec3[1] = fRec3[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "LPF.dsp"
	#define FAUST_CLASS_NAME "_LPF"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _LPF -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 2
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Q", fHslider1, 1.0f, 1.0f, 9.9f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("freq", fHslider0, 0.5f, 0.0f, 1.0f, 0.001f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, Q, "Q", fHslider1, 1.0f, 1.0f, 9.9f, 0.01f) \
		p(HORIZONTALSLIDER, freq, "freq", fHslider0, 0.5f, 0.0f, 1.0f, 0.001f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
