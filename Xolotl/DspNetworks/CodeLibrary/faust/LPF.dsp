import("stdfaust.lib");

Q = hslider("Q",1,1,9.9,0.01);
normFreq = hslider("freq",0.5,0,1,0.001):si.smoo;


process = ve.sallenKey2ndOrderLPF(normFreq,Q), ve.sallenKey2ndOrderLPF(normFreq,Q);
