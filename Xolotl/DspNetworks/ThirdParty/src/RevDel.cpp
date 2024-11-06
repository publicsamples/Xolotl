/* ------------------------------------------------------------
name: "RevDel"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _RevDel -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___RevDel_H__
#define  ___RevDel_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _RevDel
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

static float _RevDel_faustpower2_f(float value) {
	return value * value;
}

struct _RevDel final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fVslider0;
	int IOTA0;
	float fConst4;
	FAUSTFLOAT fHslider0;
	float fVec0[512];
	int iVec1[2];
	float fConst5;
	float fRec2[2];
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fConst16;
	int iRec6[2];
	float fConst17;
	float fConst18;
	float fRec5[3];
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec4[3];
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec3[3];
	float fConst25;
	float fConst26;
	float fRec7[2];
	float fConst27;
	float fConst28;
	float fConst29;
	float fConst30;
	float fConst31;
	float fConst32;
	float fConst33;
	float fConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	float fConst38;
	float fConst39;
	float fRec10[3];
	float fConst40;
	float fConst41;
	float fConst42;
	float fRec9[3];
	float fConst43;
	float fConst44;
	float fConst45;
	float fRec8[3];
	float fConst46;
	float fConst47;
	float fRec11[2];
	float fConst48;
	float fConst49;
	float fConst50;
	float fConst51;
	float fConst52;
	float fConst53;
	float fConst54;
	float fConst55;
	float fConst56;
	float fConst57;
	float fConst58;
	float fConst59;
	float fConst60;
	float fRec14[3];
	float fConst61;
	float fConst62;
	float fConst63;
	float fRec13[3];
	float fConst64;
	float fConst65;
	float fConst66;
	float fRec12[3];
	float fConst67;
	float fConst68;
	float fConst69;
	float fConst70;
	float fConst71;
	float fConst72;
	float fConst73;
	float fConst74;
	float fConst75;
	float fConst76;
	float fConst77;
	float fConst78;
	float fRec16[3];
	float fConst79;
	float fVec2[2];
	float fRec15[2];
	float fVec3[16384];
	float fConst80;
	float fConst81;
	float fConst82;
	float fConst83;
	float fRec18[2];
	float fRec17[2];
	float fRec1[65536];
	float fConst84;
	float fConst85;
	float fRec0[3];
	
	_RevDel() {
	}
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.2.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _RevDel -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("compressors.lib/compression_gain_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compression_gain_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compression_gain_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_lad_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_lad_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_lad_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/limiter_1176_R4_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/limiter_1176_R4_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/limiter_1176_R4_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "1.6.0");
		m->declare("filename", "RevDel.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass3e:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass3e:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass3e:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass6e:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass6e:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass6e:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "RevDel");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.4.1");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/saw1:author", "Bart Brouns");
		m->declare("oscillators.lib/saw1:licence", "STK-4.3");
		m->declare("oscillators.lib/version", "1.5.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "STK-4.3");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = std::tan(21991.148f / fConst0);
		fConst2 = 1.0f / fConst1;
		fConst3 = 1.0f / ((fConst2 + 1.4142135f) / fConst1 + 1.0f);
		fConst4 = 2e-06f * fConst0;
		fConst5 = 26.0f / fConst0;
		fConst6 = std::tan(314.15927f / fConst0);
		fConst7 = 1.0f / fConst6;
		fConst8 = 1.0f / ((fConst7 + 0.16840488f) / fConst6 + 1.0693583f);
		fConst9 = _RevDel_faustpower2_f(fConst6);
		fConst10 = 1.0f / fConst9;
		fConst11 = 2.0f * (53.53615f - fConst10);
		fConst12 = 1.0f / ((fConst7 + 0.51247865f) / fConst6 + 0.6896214f);
		fConst13 = fConst10 + 7.6217313f;
		fConst14 = 1.0f / ((fConst7 + 0.78241307f) / fConst6 + 0.2452915f);
		fConst15 = 0.0001f / fConst9;
		fConst16 = fConst15 + 0.0004332272f;
		fConst17 = (fConst7 + -0.78241307f) / fConst6 + 0.2452915f;
		fConst18 = 2.0f * (0.2452915f - fConst10);
		fConst19 = 2.0f * (0.0004332272f - fConst15);
		fConst20 = (fConst7 + -0.51247865f) / fConst6 + 0.6896214f;
		fConst21 = 2.0f * (0.6896214f - fConst10);
		fConst22 = 2.0f * (7.6217313f - fConst10);
		fConst23 = (fConst7 + -0.16840488f) / fConst6 + 1.0693583f;
		fConst24 = 2.0f * (1.0693583f - fConst10);
		fConst25 = fConst10 + 53.53615f;
		fConst26 = 2.5f / fConst0;
		fConst27 = std::tan(62.831852f / fConst0);
		fConst28 = 1.0f / fConst27;
		fConst29 = 1.0f / ((fConst28 + 0.16840488f) / fConst27 + 1.0693583f);
		fConst30 = _RevDel_faustpower2_f(fConst27);
		fConst31 = 1.0f / fConst30;
		fConst32 = 2.0f * (53.53615f - fConst31);
		fConst33 = 1.0f / ((fConst28 + 0.51247865f) / fConst27 + 0.6896214f);
		fConst34 = fConst31 + 7.6217313f;
		fConst35 = 1.0f / ((fConst28 + 0.78241307f) / fConst27 + 0.2452915f);
		fConst36 = 0.0001f / fConst30;
		fConst37 = fConst36 + 0.0004332272f;
		fConst38 = (fConst28 + -0.78241307f) / fConst27 + 0.2452915f;
		fConst39 = 2.0f * (0.2452915f - fConst31);
		fConst40 = 2.0f * (0.0004332272f - fConst36);
		fConst41 = (fConst28 + -0.51247865f) / fConst27 + 0.6896214f;
		fConst42 = 2.0f * (0.6896214f - fConst31);
		fConst43 = 2.0f * (7.6217313f - fConst31);
		fConst44 = (fConst28 + -0.16840488f) / fConst27 + 1.0693583f;
		fConst45 = 2.0f * (1.0693583f - fConst31);
		fConst46 = fConst31 + 53.53615f;
		fConst47 = 5.0f / fConst0;
		fConst48 = std::tan(109.95574f / fConst0);
		fConst49 = 1.0f / fConst48;
		fConst50 = 1.0f / ((fConst49 + 0.16840488f) / fConst48 + 1.0693583f);
		fConst51 = _RevDel_faustpower2_f(fConst48);
		fConst52 = 1.0f / fConst51;
		fConst53 = 2.0f * (53.53615f - fConst52);
		fConst54 = 1.0f / ((fConst49 + 0.51247865f) / fConst48 + 0.6896214f);
		fConst55 = fConst52 + 7.6217313f;
		fConst56 = 1.0f / ((fConst49 + 0.78241307f) / fConst48 + 0.2452915f);
		fConst57 = 0.0001f / fConst51;
		fConst58 = fConst57 + 0.0004332272f;
		fConst59 = (fConst49 + -0.78241307f) / fConst48 + 0.2452915f;
		fConst60 = 2.0f * (0.2452915f - fConst52);
		fConst61 = 2.0f * (0.0004332272f - fConst57);
		fConst62 = (fConst49 + -0.51247865f) / fConst48 + 0.6896214f;
		fConst63 = 2.0f * (0.6896214f - fConst52);
		fConst64 = 2.0f * (7.6217313f - fConst52);
		fConst65 = (fConst49 + -0.16840488f) / fConst48 + 1.0693583f;
		fConst66 = 2.0f * (1.0693583f - fConst52);
		fConst67 = fConst52 + 53.53615f;
		fConst68 = std::tan(219.91148f / fConst0);
		fConst69 = 1.0f / fConst68;
		fConst70 = 1.0f / (fConst69 + 0.8224459f);
		fConst71 = 0.8224459f - fConst69;
		fConst72 = 1.0f / ((fConst69 + 0.80263674f) / fConst68 + 1.4122709f);
		fConst73 = _RevDel_faustpower2_f(fConst68);
		fConst74 = 0.019809145f / fConst73;
		fConst75 = fConst74 + 1.1615164f;
		fConst76 = 3.4924598e-16f * fConst0;
		fConst77 = (fConst69 + -0.80263674f) / fConst68 + 1.4122709f;
		fConst78 = 2.0f * (1.4122709f - 1.0f / fConst73);
		fConst79 = 2.0f * (1.1615164f - fConst74);
		fConst80 = std::exp(-(2.5e+03f / fConst0));
		fConst81 = 0.75f * (1.0f - fConst80);
		fConst82 = std::exp(-(2.0f / fConst0));
		fConst83 = std::exp(-(1.25e+03f / fConst0));
		fConst84 = (fConst2 + -1.4142135f) / fConst1 + 1.0f;
		fConst85 = 2.0f * (1.0f - 1.0f / _RevDel_faustpower2_f(fConst1));
	}
	
	void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(0.5f);
		fHslider0 = FAUSTFLOAT(3e+02f);
	}
	
	void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 512; l0 = l0 + 1) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec6[l3] = 0;
		}
		for (int l4 = 0; l4 < 3; l4 = l4 + 1) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = l5 + 1) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = l6 + 1) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec7[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 3; l8 = l8 + 1) {
			fRec10[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = l9 + 1) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = l10 + 1) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = l12 + 1) {
			fRec14[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = l13 + 1) {
			fRec13[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = l14 + 1) {
			fRec12[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 3; l15 = l15 + 1) {
			fRec16[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fVec2[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 16384; l18 = l18 + 1) {
			fVec3[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec18[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec17[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 65536; l21 = l21 + 1) {
			fRec1[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 3; l22 = l22 + 1) {
			fRec0[l22] = 0.0f;
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
	
	_RevDel* clone() {
		return new _RevDel();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("RevDel");
		ui_interface->addHorizontalSlider("delay(ms)", &fHslider0, FAUSTFLOAT(3e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->addVerticalSlider("feedback", &fVslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(1.0f, float(fVslider0)));
		float fSlow1 = std::max<float>(1.0f, std::min<float>(1e+03f, float(fHslider0)));
		float fSlow2 = fConst76 * fSlow1;
		int iSlow3 = int(8.8f * fSlow1 + 3.2e+03f);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fVec0[IOTA0 & 511] = fSlow1;
			iVec1[0] = 1;
			float fTemp0 = fConst4 * (fSlow1 + fVec0[(IOTA0 - 413) & 511] + fVec0[(IOTA0 - 242) & 511] + fVec0[(IOTA0 - 241) & 511] + fVec0[(IOTA0 - 240) & 511] + fVec0[(IOTA0 - 239) & 511] + fVec0[(IOTA0 - 238) & 511] + fVec0[(IOTA0 - 237) & 511] + fVec0[(IOTA0 - 236) & 511] + fVec0[(IOTA0 - 235) & 511] + fVec0[(IOTA0 - 234) & 511] + fVec0[(IOTA0 - 233) & 511] + fVec0[(IOTA0 - 232) & 511] + fVec0[(IOTA0 - 231) & 511] + fVec0[(IOTA0 - 230) & 511] + fVec0[(IOTA0 - 229) & 511] + fVec0[(IOTA0 - 228) & 511] + fVec0[(IOTA0 - 227) & 511] + fVec0[(IOTA0 - 226) & 511] + fVec0[(IOTA0 - 225) & 511] + fVec0[(IOTA0 - 224) & 511] + fVec0[(IOTA0 - 223) & 511] + fVec0[(IOTA0 - 222) & 511] + fVec0[(IOTA0 - 221) & 511] + fVec0[(IOTA0 - 220) & 511] + fVec0[(IOTA0 - 219) & 511] + fVec0[(IOTA0 - 218) & 511] + fVec0[(IOTA0 - 217) & 511] + fVec0[(IOTA0 - 216) & 511] + fVec0[(IOTA0 - 215) & 511] + fVec0[(IOTA0 - 270) & 511] + fVec0[(IOTA0 - 269) & 511] + fVec0[(IOTA0 - 268) & 511] + fVec0[(IOTA0 - 267) & 511] + fVec0[(IOTA0 - 266) & 511] + fVec0[(IOTA0 - 265) & 511] + fVec0[(IOTA0 - 264) & 511] + fVec0[(IOTA0 - 263) & 511] + fVec0[(IOTA0 - 262) & 511] + fVec0[(IOTA0 - 261) & 511] + fVec0[(IOTA0 - 260) & 511] + fVec0[(IOTA0 - 259) & 511] + fVec0[(IOTA0 - 258) & 511] + fVec0[(IOTA0 - 257) & 511] + fVec0[(IOTA0 - 256) & 511] + fVec0[(IOTA0 - 255) & 511] + fVec0[(IOTA0 - 254) & 511] + fVec0[(IOTA0 - 253) & 511] + fVec0[(IOTA0 - 252) & 511] + fVec0[(IOTA0 - 251) & 511] + fVec0[(IOTA0 - 250) & 511] + fVec0[(IOTA0 - 249) & 511] + fVec0[(IOTA0 - 248) & 511] + fVec0[(IOTA0 - 247) & 511] + fVec0[(IOTA0 - 246) & 511] + fVec0[(IOTA0 - 245) & 511] + fVec0[(IOTA0 - 244) & 511] + fVec0[(IOTA0 - 243) & 511] + fVec0[(IOTA0 - 299) & 511] + fVec0[(IOTA0 - 298) & 511] + fVec0[(IOTA0 - 297) & 511] + fVec0[(IOTA0 - 296) & 511] + fVec0[(IOTA0 - 295) & 511] + fVec0[(IOTA0 - 294) & 511] + fVec0[(IOTA0 - 293) & 511] + fVec0[(IOTA0 - 292) & 511] + fVec0[(IOTA0 - 291) & 511] + fVec0[(IOTA0 - 290) & 511] + fVec0[(IOTA0 - 289) & 511] + fVec0[(IOTA0 - 288) & 511] + fVec0[(IOTA0 - 287) & 511] + fVec0[(IOTA0 - 286) & 511] + fVec0[(IOTA0 - 285) & 511] + fVec0[(IOTA0 - 284) & 511] + fVec0[(IOTA0 - 283) & 511] + fVec0[(IOTA0 - 282) & 511] + fVec0[(IOTA0 - 281) & 511] + fVec0[(IOTA0 - 280) & 511] + fVec0[(IOTA0 - 279) & 511] + fVec0[(IOTA0 - 278) & 511] + fVec0[(IOTA0 - 277) & 511] + fVec0[(IOTA0 - 276) & 511] + fVec0[(IOTA0 - 275) & 511] + fVec0[(IOTA0 - 274) & 511] + fVec0[(IOTA0 - 273) & 511] + fVec0[(IOTA0 - 272) & 511] + fVec0[(IOTA0 - 271) & 511] + fVec0[(IOTA0 - 327) & 511] + fVec0[(IOTA0 - 326) & 511] + fVec0[(IOTA0 - 325) & 511] + fVec0[(IOTA0 - 324) & 511] + fVec0[(IOTA0 - 323) & 511] + fVec0[(IOTA0 - 322) & 511] + fVec0[(IOTA0 - 321) & 511] + fVec0[(IOTA0 - 320) & 511] + fVec0[(IOTA0 - 319) & 511] + fVec0[(IOTA0 - 318) & 511] + fVec0[(IOTA0 - 317) & 511] + fVec0[(IOTA0 - 316) & 511] + fVec0[(IOTA0 - 315) & 511] + fVec0[(IOTA0 - 314) & 511] + fVec0[(IOTA0 - 313) & 511] + fVec0[(IOTA0 - 312) & 511] + fVec0[(IOTA0 - 311) & 511] + fVec0[(IOTA0 - 310) & 511] + fVec0[(IOTA0 - 309) & 511] + fVec0[(IOTA0 - 308) & 511] + fVec0[(IOTA0 - 307) & 511] + fVec0[(IOTA0 - 306) & 511] + fVec0[(IOTA0 - 305) & 511] + fVec0[(IOTA0 - 304) & 511] + fVec0[(IOTA0 - 303) & 511] + fVec0[(IOTA0 - 302) & 511] + fVec0[(IOTA0 - 301) & 511] + fVec0[(IOTA0 - 300) & 511] + fVec0[(IOTA0 - 129) & 511] + fVec0[(IOTA0 - 128) & 511] + fVec0[(IOTA0 - 127) & 511] + fVec0[(IOTA0 - 126) & 511] + fVec0[(IOTA0 - 125) & 511] + fVec0[(IOTA0 - 124) & 511] + fVec0[(IOTA0 - 123) & 511] + fVec0[(IOTA0 - 122) & 511] + fVec0[(IOTA0 - 121) & 511] + fVec0[(IOTA0 - 120) & 511] + fVec0[(IOTA0 - 119) & 511] + fVec0[(IOTA0 - 118) & 511] + fVec0[(IOTA0 - 117) & 511] + fVec0[(IOTA0 - 116) & 511] + fVec0[(IOTA0 - 115) & 511] + fVec0[(IOTA0 - 114) & 511] + fVec0[(IOTA0 - 113) & 511] + fVec0[(IOTA0 - 112) & 511] + fVec0[(IOTA0 - 111) & 511] + fVec0[(IOTA0 - 110) & 511] + fVec0[(IOTA0 - 109) & 511] + fVec0[(IOTA0 - 108) & 511] + fVec0[(IOTA0 - 107) & 511] + fVec0[(IOTA0 - 106) & 511] + fVec0[(IOTA0 - 105) & 511] + fVec0[(IOTA0 - 104) & 511] + fVec0[(IOTA0 - 103) & 511] + fVec0[(IOTA0 - 102) & 511] + fVec0[(IOTA0 - 157) & 511] + fVec0[(IOTA0 - 156) & 511] + fVec0[(IOTA0 - 155) & 511] + fVec0[(IOTA0 - 154) & 511] + fVec0[(IOTA0 - 153) & 511] + fVec0[(IOTA0 - 152) & 511] + fVec0[(IOTA0 - 151) & 511] + fVec0[(IOTA0 - 150) & 511] + fVec0[(IOTA0 - 149) & 511] + fVec0[(IOTA0 - 148) & 511] + fVec0[(IOTA0 - 147) & 511] + fVec0[(IOTA0 - 146) & 511] + fVec0[(IOTA0 - 145) & 511] + fVec0[(IOTA0 - 144) & 511] + fVec0[(IOTA0 - 143) & 511] + fVec0[(IOTA0 - 142) & 511] + fVec0[(IOTA0 - 141) & 511] + fVec0[(IOTA0 - 140) & 511] + fVec0[(IOTA0 - 139) & 511] + fVec0[(IOTA0 - 138) & 511] + fVec0[(IOTA0 - 137) & 511] + fVec0[(IOTA0 - 136) & 511] + fVec0[(IOTA0 - 135) & 511] + fVec0[(IOTA0 - 134) & 511] + fVec0[(IOTA0 - 133) & 511] + fVec0[(IOTA0 - 132) & 511] + fVec0[(IOTA0 - 131) & 511] + fVec0[(IOTA0 - 130) & 511] + fVec0[(IOTA0 - 186) & 511] + fVec0[(IOTA0 - 185) & 511] + fVec0[(IOTA0 - 184) & 511] + fVec0[(IOTA0 - 183) & 511] + fVec0[(IOTA0 - 182) & 511] + fVec0[(IOTA0 - 181) & 511] + fVec0[(IOTA0 - 180) & 511] + fVec0[(IOTA0 - 179) & 511] + fVec0[(IOTA0 - 178) & 511] + fVec0[(IOTA0 - 177) & 511] + fVec0[(IOTA0 - 176) & 511] + fVec0[(IOTA0 - 175) & 511] + fVec0[(IOTA0 - 174) & 511] + fVec0[(IOTA0 - 173) & 511] + fVec0[(IOTA0 - 172) & 511] + fVec0[(IOTA0 - 171) & 511] + fVec0[(IOTA0 - 170) & 511] + fVec0[(IOTA0 - 169) & 511] + fVec0[(IOTA0 - 168) & 511] + fVec0[(IOTA0 - 167) & 511] + fVec0[(IOTA0 - 166) & 511] + fVec0[(IOTA0 - 165) & 511] + fVec0[(IOTA0 - 164) & 511] + fVec0[(IOTA0 - 163) & 511] + fVec0[(IOTA0 - 162) & 511] + fVec0[(IOTA0 - 161) & 511] + fVec0[(IOTA0 - 160) & 511] + fVec0[(IOTA0 - 159) & 511] + fVec0[(IOTA0 - 158) & 511] + fVec0[(IOTA0 - 214) & 511] + fVec0[(IOTA0 - 213) & 511] + fVec0[(IOTA0 - 212) & 511] + fVec0[(IOTA0 - 211) & 511] + fVec0[(IOTA0 - 210) & 511] + fVec0[(IOTA0 - 209) & 511] + fVec0[(IOTA0 - 208) & 511] + fVec0[(IOTA0 - 207) & 511] + fVec0[(IOTA0 - 206) & 511] + fVec0[(IOTA0 - 205) & 511] + fVec0[(IOTA0 - 204) & 511] + fVec0[(IOTA0 - 203) & 511] + fVec0[(IOTA0 - 202) & 511] + fVec0[(IOTA0 - 201) & 511] + fVec0[(IOTA0 - 200) & 511] + fVec0[(IOTA0 - 199) & 511] + fVec0[(IOTA0 - 198) & 511] + fVec0[(IOTA0 - 197) & 511] + fVec0[(IOTA0 - 196) & 511] + fVec0[(IOTA0 - 195) & 511] + fVec0[(IOTA0 - 194) & 511] + fVec0[(IOTA0 - 193) & 511] + fVec0[(IOTA0 - 192) & 511] + fVec0[(IOTA0 - 191) & 511] + fVec0[(IOTA0 - 190) & 511] + fVec0[(IOTA0 - 189) & 511] + fVec0[(IOTA0 - 188) & 511] + fVec0[(IOTA0 - 187) & 511] + fVec0[(IOTA0 - 16) & 511] + fVec0[(IOTA0 - 15) & 511] + fVec0[(IOTA0 - 14) & 511] + fVec0[(IOTA0 - 13) & 511] + fVec0[(IOTA0 - 12) & 511] + fVec0[(IOTA0 - 11) & 511] + fVec0[(IOTA0 - 10) & 511] + fVec0[(IOTA0 - 9) & 511] + fVec0[(IOTA0 - 8) & 511] + fVec0[(IOTA0 - 7) & 511] + fVec0[(IOTA0 - 6) & 511] + fVec0[(IOTA0 - 5) & 511] + fVec0[(IOTA0 - 4) & 511] + fVec0[(IOTA0 - 3) & 511] + fVec0[(IOTA0 - 2) & 511] + fVec0[(IOTA0 - 1) & 511] + fVec0[(IOTA0 - 44) & 511] + fVec0[(IOTA0 - 43) & 511] + fVec0[(IOTA0 - 42) & 511] + fVec0[(IOTA0 - 41) & 511] + fVec0[(IOTA0 - 40) & 511] + fVec0[(IOTA0 - 39) & 511] + fVec0[(IOTA0 - 38) & 511] + fVec0[(IOTA0 - 37) & 511] + fVec0[(IOTA0 - 36) & 511] + fVec0[(IOTA0 - 35) & 511] + fVec0[(IOTA0 - 34) & 511] + fVec0[(IOTA0 - 33) & 511] + fVec0[(IOTA0 - 32) & 511] + fVec0[(IOTA0 - 31) & 511] + fVec0[(IOTA0 - 30) & 511] + fVec0[(IOTA0 - 29) & 511] + fVec0[(IOTA0 - 28) & 511] + fVec0[(IOTA0 - 27) & 511] + fVec0[(IOTA0 - 26) & 511] + fVec0[(IOTA0 - 25) & 511] + fVec0[(IOTA0 - 24) & 511] + fVec0[(IOTA0 - 23) & 511] + fVec0[(IOTA0 - 22) & 511] + fVec0[(IOTA0 - 21) & 511] + fVec0[(IOTA0 - 20) & 511] + fVec0[(IOTA0 - 19) & 511] + fVec0[(IOTA0 - 18) & 511] + fVec0[(IOTA0 - 17) & 511] + fVec0[(IOTA0 - 73) & 511] + fVec0[(IOTA0 - 72) & 511] + fVec0[(IOTA0 - 71) & 511] + fVec0[(IOTA0 - 70) & 511] + fVec0[(IOTA0 - 69) & 511] + fVec0[(IOTA0 - 68) & 511] + fVec0[(IOTA0 - 67) & 511] + fVec0[(IOTA0 - 66) & 511] + fVec0[(IOTA0 - 65) & 511] + fVec0[(IOTA0 - 64) & 511] + fVec0[(IOTA0 - 63) & 511] + fVec0[(IOTA0 - 62) & 511] + fVec0[(IOTA0 - 61) & 511] + fVec0[(IOTA0 - 60) & 511] + fVec0[(IOTA0 - 59) & 511] + fVec0[(IOTA0 - 58) & 511] + fVec0[(IOTA0 - 57) & 511] + fVec0[(IOTA0 - 56) & 511] + fVec0[(IOTA0 - 55) & 511] + fVec0[(IOTA0 - 54) & 511] + fVec0[(IOTA0 - 53) & 511] + fVec0[(IOTA0 - 52) & 511] + fVec0[(IOTA0 - 51) & 511] + fVec0[(IOTA0 - 50) & 511] + fVec0[(IOTA0 - 49) & 511] + fVec0[(IOTA0 - 48) & 511] + fVec0[(IOTA0 - 47) & 511] + fVec0[(IOTA0 - 46) & 511] + fVec0[(IOTA0 - 45) & 511] + fVec0[(IOTA0 - 101) & 511] + fVec0[(IOTA0 - 100) & 511] + fVec0[(IOTA0 - 99) & 511] + fVec0[(IOTA0 - 98) & 511] + fVec0[(IOTA0 - 97) & 511] + fVec0[(IOTA0 - 96) & 511] + fVec0[(IOTA0 - 95) & 511] + fVec0[(IOTA0 - 94) & 511] + fVec0[(IOTA0 - 93) & 511] + fVec0[(IOTA0 - 92) & 511] + fVec0[(IOTA0 - 91) & 511] + fVec0[(IOTA0 - 90) & 511] + fVec0[(IOTA0 - 89) & 511] + fVec0[(IOTA0 - 88) & 511] + fVec0[(IOTA0 - 87) & 511] + fVec0[(IOTA0 - 86) & 511] + fVec0[(IOTA0 - 85) & 511] + fVec0[(IOTA0 - 84) & 511] + fVec0[(IOTA0 - 83) & 511] + fVec0[(IOTA0 - 82) & 511] + fVec0[(IOTA0 - 81) & 511] + fVec0[(IOTA0 - 80) & 511] + fVec0[(IOTA0 - 79) & 511] + fVec0[(IOTA0 - 78) & 511] + fVec0[(IOTA0 - 77) & 511] + fVec0[(IOTA0 - 76) & 511] + fVec0[(IOTA0 - 74) & 511] + fVec0[(IOTA0 - 75) & 511] + fVec0[(IOTA0 - 414) & 511] + fVec0[(IOTA0 - 415) & 511] + fVec0[(IOTA0 - 416) & 511] + fVec0[(IOTA0 - 417) & 511] + fVec0[(IOTA0 - 418) & 511] + fVec0[(IOTA0 - 419) & 511] + fVec0[(IOTA0 - 420) & 511] + fVec0[(IOTA0 - 421) & 511] + fVec0[(IOTA0 - 422) & 511] + fVec0[(IOTA0 - 423) & 511] + fVec0[(IOTA0 - 424) & 511] + fVec0[(IOTA0 - 425) & 511] + fVec0[(IOTA0 - 426) & 511] + fVec0[(IOTA0 - 427) & 511] + fVec0[(IOTA0 - 428) & 511] + fVec0[(IOTA0 - 429) & 511] + fVec0[(IOTA0 - 430) & 511] + fVec0[(IOTA0 - 431) & 511] + fVec0[(IOTA0 - 432) & 511] + fVec0[(IOTA0 - 433) & 511] + fVec0[(IOTA0 - 434) & 511] + fVec0[(IOTA0 - 435) & 511] + fVec0[(IOTA0 - 436) & 511] + fVec0[(IOTA0 - 437) & 511] + fVec0[(IOTA0 - 438) & 511] + fVec0[(IOTA0 - 439) & 511] + fVec0[(IOTA0 - 440) & 511] + fVec0[(IOTA0 - 384) & 511] + fVec0[(IOTA0 - 385) & 511] + fVec0[(IOTA0 - 386) & 511] + fVec0[(IOTA0 - 387) & 511] + fVec0[(IOTA0 - 388) & 511] + fVec0[(IOTA0 - 389) & 511] + fVec0[(IOTA0 - 390) & 511] + fVec0[(IOTA0 - 391) & 511] + fVec0[(IOTA0 - 392) & 511] + fVec0[(IOTA0 - 393) & 511] + fVec0[(IOTA0 - 394) & 511] + fVec0[(IOTA0 - 395) & 511] + fVec0[(IOTA0 - 396) & 511] + fVec0[(IOTA0 - 397) & 511] + fVec0[(IOTA0 - 398) & 511] + fVec0[(IOTA0 - 399) & 511] + fVec0[(IOTA0 - 400) & 511] + fVec0[(IOTA0 - 401) & 511] + fVec0[(IOTA0 - 402) & 511] + fVec0[(IOTA0 - 403) & 511] + fVec0[(IOTA0 - 404) & 511] + fVec0[(IOTA0 - 405) & 511] + fVec0[(IOTA0 - 406) & 511] + fVec0[(IOTA0 - 407) & 511] + fVec0[(IOTA0 - 408) & 511] + fVec0[(IOTA0 - 409) & 511] + fVec0[(IOTA0 - 410) & 511] + fVec0[(IOTA0 - 411) & 511] + fVec0[(IOTA0 - 412) & 511] + fVec0[(IOTA0 - 356) & 511] + fVec0[(IOTA0 - 357) & 511] + fVec0[(IOTA0 - 358) & 511] + fVec0[(IOTA0 - 359) & 511] + fVec0[(IOTA0 - 360) & 511] + fVec0[(IOTA0 - 361) & 511] + fVec0[(IOTA0 - 362) & 511] + fVec0[(IOTA0 - 363) & 511] + fVec0[(IOTA0 - 364) & 511] + fVec0[(IOTA0 - 365) & 511] + fVec0[(IOTA0 - 366) & 511] + fVec0[(IOTA0 - 367) & 511] + fVec0[(IOTA0 - 368) & 511] + fVec0[(IOTA0 - 369) & 511] + fVec0[(IOTA0 - 370) & 511] + fVec0[(IOTA0 - 371) & 511] + fVec0[(IOTA0 - 372) & 511] + fVec0[(IOTA0 - 373) & 511] + fVec0[(IOTA0 - 374) & 511] + fVec0[(IOTA0 - 375) & 511] + fVec0[(IOTA0 - 376) & 511] + fVec0[(IOTA0 - 377) & 511] + fVec0[(IOTA0 - 378) & 511] + fVec0[(IOTA0 - 379) & 511] + fVec0[(IOTA0 - 380) & 511] + fVec0[(IOTA0 - 381) & 511] + fVec0[(IOTA0 - 382) & 511] + fVec0[(IOTA0 - 383) & 511] + fVec0[(IOTA0 - 328) & 511] + fVec0[(IOTA0 - 329) & 511] + fVec0[(IOTA0 - 330) & 511] + fVec0[(IOTA0 - 331) & 511] + fVec0[(IOTA0 - 332) & 511] + fVec0[(IOTA0 - 333) & 511] + fVec0[(IOTA0 - 334) & 511] + fVec0[(IOTA0 - 335) & 511] + fVec0[(IOTA0 - 336) & 511] + fVec0[(IOTA0 - 337) & 511] + fVec0[(IOTA0 - 338) & 511] + fVec0[(IOTA0 - 339) & 511] + fVec0[(IOTA0 - 340) & 511] + fVec0[(IOTA0 - 341) & 511] + fVec0[(IOTA0 - 342) & 511] + fVec0[(IOTA0 - 343) & 511] + fVec0[(IOTA0 - 344) & 511] + fVec0[(IOTA0 - 345) & 511] + fVec0[(IOTA0 - 346) & 511] + fVec0[(IOTA0 - 347) & 511] + fVec0[(IOTA0 - 348) & 511] + fVec0[(IOTA0 - 349) & 511] + fVec0[(IOTA0 - 350) & 511] + fVec0[(IOTA0 - 351) & 511] + fVec0[(IOTA0 - 352) & 511] + fVec0[(IOTA0 - 353) & 511] + fVec0[(IOTA0 - 354) & 511] + fVec0[(IOTA0 - 355) & 511] + fVec0[(IOTA0 - 497) & 511] + fVec0[(IOTA0 - 498) & 511] + fVec0[(IOTA0 - 499) & 511] + fVec0[(IOTA0 - 469) & 511] + fVec0[(IOTA0 - 470) & 511] + fVec0[(IOTA0 - 471) & 511] + fVec0[(IOTA0 - 472) & 511] + fVec0[(IOTA0 - 473) & 511] + fVec0[(IOTA0 - 474) & 511] + fVec0[(IOTA0 - 475) & 511] + fVec0[(IOTA0 - 476) & 511] + fVec0[(IOTA0 - 477) & 511] + fVec0[(IOTA0 - 478) & 511] + fVec0[(IOTA0 - 479) & 511] + fVec0[(IOTA0 - 480) & 511] + fVec0[(IOTA0 - 481) & 511] + fVec0[(IOTA0 - 482) & 511] + fVec0[(IOTA0 - 483) & 511] + fVec0[(IOTA0 - 484) & 511] + fVec0[(IOTA0 - 485) & 511] + fVec0[(IOTA0 - 486) & 511] + fVec0[(IOTA0 - 487) & 511] + fVec0[(IOTA0 - 488) & 511] + fVec0[(IOTA0 - 489) & 511] + fVec0[(IOTA0 - 490) & 511] + fVec0[(IOTA0 - 491) & 511] + fVec0[(IOTA0 - 492) & 511] + fVec0[(IOTA0 - 493) & 511] + fVec0[(IOTA0 - 494) & 511] + fVec0[(IOTA0 - 495) & 511] + fVec0[(IOTA0 - 496) & 511] + fVec0[(IOTA0 - 441) & 511] + fVec0[(IOTA0 - 442) & 511] + fVec0[(IOTA0 - 443) & 511] + fVec0[(IOTA0 - 444) & 511] + fVec0[(IOTA0 - 445) & 511] + fVec0[(IOTA0 - 446) & 511] + fVec0[(IOTA0 - 447) & 511] + fVec0[(IOTA0 - 448) & 511] + fVec0[(IOTA0 - 449) & 511] + fVec0[(IOTA0 - 450) & 511] + fVec0[(IOTA0 - 451) & 511] + fVec0[(IOTA0 - 452) & 511] + fVec0[(IOTA0 - 453) & 511] + fVec0[(IOTA0 - 454) & 511] + fVec0[(IOTA0 - 455) & 511] + fVec0[(IOTA0 - 456) & 511] + fVec0[(IOTA0 - 457) & 511] + fVec0[(IOTA0 - 458) & 511] + fVec0[(IOTA0 - 459) & 511] + fVec0[(IOTA0 - 460) & 511] + fVec0[(IOTA0 - 461) & 511] + fVec0[(IOTA0 - 462) & 511] + fVec0[(IOTA0 - 463) & 511] + fVec0[(IOTA0 - 464) & 511] + fVec0[(IOTA0 - 465) & 511] + fVec0[(IOTA0 - 466) & 511] + fVec0[(IOTA0 - 467) & 511] + fVec0[(IOTA0 - 468) & 511]);
			int iTemp1 = 1 - iVec1[1];
			float fTemp2 = ((iTemp1) ? 0.0f : fConst5 + fRec2[1]);
			fRec2[0] = fTemp2 - std::floor(fTemp2);
			iRec6[0] = 1103515245 * iRec6[1] + 12345;
			float fTemp3 = float(iRec6[0]);
			fRec5[0] = 2.3283064e-09f * fTemp3 - fConst14 * (fConst17 * fRec5[2] + fConst18 * fRec5[1]);
			fRec4[0] = fConst14 * (fConst16 * fRec5[0] + fConst19 * fRec5[1] + fConst16 * fRec5[2]) - fConst12 * (fConst20 * fRec4[2] + fConst21 * fRec4[1]);
			fRec3[0] = fConst12 * (fConst13 * fRec4[0] + fConst22 * fRec4[1] + fConst13 * fRec4[2]) - fConst8 * (fConst23 * fRec3[2] + fConst24 * fRec3[1]);
			float fTemp4 = ((iTemp1) ? 0.0f : fConst26 + fRec7[1]);
			fRec7[0] = fTemp4 - std::floor(fTemp4);
			fRec10[0] = 9.313226e-09f * fTemp3 - fConst35 * (fConst38 * fRec10[2] + fConst39 * fRec10[1]);
			fRec9[0] = fConst35 * (fConst37 * fRec10[0] + fConst40 * fRec10[1] + fConst37 * fRec10[2]) - fConst33 * (fConst41 * fRec9[2] + fConst42 * fRec9[1]);
			fRec8[0] = fConst33 * (fConst34 * fRec9[0] + fConst43 * fRec9[1] + fConst34 * fRec9[2]) - fConst29 * (fConst44 * fRec8[2] + fConst45 * fRec8[1]);
			float fTemp5 = ((iTemp1) ? 0.0f : fConst47 + fRec11[1]);
			fRec11[0] = fTemp5 - std::floor(fTemp5);
			fRec14[0] = 3.259629e-09f * fTemp3 - fConst56 * (fConst59 * fRec14[2] + fConst60 * fRec14[1]);
			fRec13[0] = fConst56 * (fConst58 * fRec14[0] + fConst61 * fRec14[1] + fConst58 * fRec14[2]) - fConst54 * (fConst62 * fRec13[2] + fConst63 * fRec13[1]);
			fRec12[0] = fConst54 * (fConst55 * fRec13[0] + fConst64 * fRec13[1] + fConst55 * fRec13[2]) - fConst50 * (fConst65 * fRec12[2] + fConst66 * fRec12[1]);
			fRec16[0] = fSlow2 * fTemp3 - fConst72 * (fConst77 * fRec16[2] + fConst78 * fRec16[1]);
			float fTemp6 = fConst75 * fRec16[0] + fConst79 * fRec16[1] + fConst75 * fRec16[2];
			fVec2[0] = fTemp6;
			fRec15[0] = -(fConst70 * (fConst71 * fRec15[1] - fConst72 * (fTemp6 + fVec2[1])));
			float fTemp7 = 0.75f * (fConst0 * (0.00015f * std::sin(3.1415927f * (2.0f * fRec2[0] + -1.0f) + fConst8 * (fConst11 * fRec3[1] + fConst25 * (fRec3[2] + fRec3[0])) + 4.712389f) + fSlow1 * (7.5e-07f * std::sin(3.1415927f * (2.0f * fRec7[0] + -1.0f) + fConst29 * (fConst32 * fRec8[1] + fConst46 * (fRec8[2] + fRec8[0])) + 2.3561945f) + 1e-07f * std::sin(3.1415927f * (2.0f * fRec11[0] + -1.0f) + fConst50 * (fConst53 * fRec12[1] + fConst67 * (fRec12[2] + fRec12[0]))))) + fRec15[0]);
			fVec3[IOTA0 & 16383] = fTemp0 + fTemp7;
			float fTemp8 = fRec1[(IOTA0 - (std::min<int>(50000, std::max<int>(0, int(0.5f * (fTemp0 + 0.9999f * fVec3[(IOTA0 - iSlow3) & 16383] + fTemp7)))) + 1)) & 65535];
			float fTemp9 = std::fabs(fSlow0 * fTemp8);
			float fTemp10 = ((fTemp9 > fRec18[1]) ? fConst83 : fConst82);
			fRec18[0] = fTemp9 * (1.0f - fTemp10) + fRec18[1] * fTemp10;
			fRec17[0] = fConst80 * fRec17[1] - fConst81 * std::max<float>(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec18[0])) + 6.0f, 0.0f);
			fRec1[IOTA0 & 65535] = fSlow0 * fTemp8 * std::pow(1e+01f, 0.05f * fRec17[0]) + float(input0[i0]);
			fRec0[0] = fRec1[IOTA0 & 65535] - fConst3 * (fConst84 * fRec0[2] + fConst85 * fRec0[1]);
			float fTemp11 = fConst3 * (fRec0[2] + 2.0f * fRec0[1] + fRec0[0]);
			output0[i0] = FAUSTFLOAT(fTemp11);
			output1[i0] = FAUSTFLOAT(fTemp11);
			IOTA0 = IOTA0 + 1;
			iVec1[1] = iVec1[0];
			fRec2[1] = fRec2[0];
			iRec6[1] = iRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec7[1] = fRec7[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fVec2[1] = fVec2[0];
			fRec15[1] = fRec15[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "RevDel.dsp"
	#define FAUST_CLASS_NAME "_RevDel"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _RevDel -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 1
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 2
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("delay(ms)", fHslider0, 3e+02f, 1.0f, 1e+03f, 1.0f);
	FAUST_ADDVERTICALSLIDER("feedback", fVslider0, 0.5f, 0.0f, 1.0f, 0.01f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, delay(ms), "delay(ms)", fHslider0, 3e+02f, 1.0f, 1e+03f, 1.0f) \
		p(VERTICALSLIDER, feedback, "feedback", fVslider0, 0.5f, 0.0f, 1.0f, 0.01f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
