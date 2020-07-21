#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Paint : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);

	ofPolyline polyline;

	ofxPanel gui;
	ofxIntSlider size;
	ofxColorSlider color;
	ofxVec3Slider background;
	ofxButton btnClear;

	ofImage imgScreenshot;
	int count;

	ofFbo fbo;
	int width = 800;
	int height = 600;
};
