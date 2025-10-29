import("stdfaust.lib");

intdel = hslider("del",0,0,100,0.01);
maxdel = 128;

b0 = 1;
aN = hslider("aN",0,0,1,0.01);


process = fi.fb_fcomb(maxdel,intdel,b0,aN), fi.fb_fcomb(maxdel,intdel,b0,aN);
