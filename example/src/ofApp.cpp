#include "ofApp.h"

void ofApp::setup() {
  ofSetFrameRate(60);
  ofSetVerticalSync(true);
  ofBackground(0);

  video.setup(640, 480);

  gui.setup();
  gui.add(alpha.setup("alpha", 10, 0, 20));
  gui.add(cutoff.setup("cutoff", 16, 0, 20));
  gui.add(min_freq.setup("min_freq", 0.05, 0, 2));
  gui.add(max_freq.setup("max_freq", 0.4, 0, 2));
  gui.add(chrome.setup("chrome", 0.1, 0, 2));
}
void ofApp::update() {
  video.update();

  updateParams();
  if (video.isFrameNew()) {
    evm.update(video);
  }
}
void ofApp::draw() {
  video.draw(0, 0);
  gui.draw();
  ofTranslate(video.getWidth(), 0);
  evm.draw();
}
void ofApp::updateParams() {
  evm.amplification(alpha);
  evm.cutoff(cutoff);
  evm.freqMin(min_freq);
  evm.freqMax(max_freq);
  evm.chromeAttenuation(chrome);
}
