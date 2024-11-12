#pragma once

#include "ofMain.h"
#include "ofxEvm.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
  ofVideoGrabber video;
  ofxEvm         evm;

  ofxPanel       gui;
  ofxFloatSlider alpha;
  ofxFloatSlider cutoff;
  ofxFloatSlider min_freq;
  ofxFloatSlider max_freq;
  ofxFloatSlider chrome;

 public:
  void setup();
  void update();
  void draw();
  void updateParams();
};
