/* ------------------------------------------------------------
name: "OBLP"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _OBLP -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___OBLP_H__
#define  ___OBLP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _OBLP
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


struct _OBLP final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fConst3;
	float fRec4[2];
	FAUSTFLOAT fHslider1;
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	float fRec6[2];
	float fRec7[2];
	float fRec8[2];
	
	_OBLP() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _OBLP -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "OBLP.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "OBLP");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("vaeffects.lib/korg35LPF:author", "Eric Tarr");
		m->declare("vaeffects.lib/korg35LPF:license", "MIT-style STK-4.3 license");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
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
			fRec4[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec6[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec7[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec8[l6] = 0.0f;
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
	
	_OBLP* clone() {
		return new _OBLP();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("OBLP");
		ui_interface->addHorizontalSlider("Q", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst2 * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0)));
		float fSlow1 = 0.21521823f * (std::max<float>(1.0f, std::min<float>(1e+01f, float(fHslider1))) + -0.70710677f);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec4[0] = fSlow0 + fConst3 * fRec4[1];
			float fTemp0 = std::tan(fConst1 * std::pow(1e+01f, 3.0f * fRec4[0] + 1.0f));
			float fTemp1 = fTemp0 * (float(input0[i0]) - fRec3[1]);
			float fTemp2 = fTemp0 + 1.0f;
			float fTemp3 = 1.0f - fTemp0 / fTemp2;
			float fTemp4 = 1.0f - fSlow1 * (fTemp0 * fTemp3 / fTemp2);
			float fTemp5 = fTemp0 * (((fTemp1 + fSlow1 * fRec1[1] * fTemp3 - fRec2[1]) / fTemp2 + fRec3[1]) / fTemp4 - fRec1[1]) / fTemp2;
			float fTemp6 = fRec1[1] + fTemp5;
			float fRec0 = fTemp6;
			fRec1[0] = fRec1[1] + 2.0f * fTemp5;
			fRec2[0] = fRec2[1] + 2.0f * (fTemp0 * (fSlow1 * fTemp6 - fRec2[1]) / fTemp2);
			fRec3[0] = 2.0f * (fTemp1 / fTemp2) + fRec3[1];
			output0[i0] = FAUSTFLOAT(fRec0);
			float fTemp7 = fTemp0 * (float(input1[i0]) - fRec8[1]);
			float fTemp8 = fTemp0 * ((fRec8[1] + (fTemp7 + fSlow1 * fTemp3 * fRec6[1] - fRec7[1]) / fTemp2) / fTemp4 - fRec6[1]) / fTemp2;
			float fTemp9 = fRec6[1] + fTemp8;
			float fRec5 = fTemp9;
			fRec6[0] = fRec6[1] + 2.0f * fTemp8;
			fRec7[0] = fRec7[1] + 2.0f * (fTemp0 * (fSlow1 * fTemp9 - fRec7[1]) / fTemp2);
			fRec8[0] = fRec8[1] + 2.0f * (fTemp7 / fTemp2);
			output1[i0] = FAUSTFLOAT(fRec5);
			fRec4[1] = fRec4[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "OBLP.dsp"
	#define FAUST_CLASS_NAME "_OBLP"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _OBLP -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 2
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Q", fHslider1, 1.0f, 1.0f, 1e+01f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("freq", fHslider0, 0.5f, 0.0f, 1.0f, 0.001f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, Q, "Q", fHslider1, 1.0f, 1.0f, 1e+01f, 0.01f) \
		p(HORIZONTALSLIDER, freq, "freq", fHslider0, 0.5f, 0.0f, 1.0f, 0.001f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
