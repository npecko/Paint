#include "Paint.h"

void Paint::setup() {
	ofEnableSmoothing();
	gui.setup();
	gui.add(size.setup("size", 3, 1, 8));
	gui.add(color.setup("color", ofColor(255, 255, 255, 255), ofColor(0, 0, 0, 0), ofColor(255, 255, 255, 255)));
	gui.add(background.setup("background", ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), ofVec3f(255, 255, 255)));
	gui.add(btnClear.setup("clear"));
	gui.setPosition(815.0f, 0.0f);

	fbo.allocate(width, height);
	fbo.begin();
	ofClear(255);
	fbo.end();
}

void Paint::update() {
	ofBackground(background->x, background->y, background->z);

	if (btnClear) {
		fbo.begin();
		ofClear(255);
		fbo.end();
	}
}

void Paint::draw() {
	fbo.draw(0, 0);
	ofNoFill();
	ofDrawRectangle(0, 0, width, height);
	gui.draw();
}

void Paint::keyPressed(int key) {
	if (key == ' ') {
		imgScreenshot.grabScreen(0, 0, fbo.getWidth(), fbo.getHeight());
		string filename = "screenshot_" + ofToString(count, 3, '0') + ".png";
		imgScreenshot.save(filename);
		count++;
	}
}

void Paint::mouseDragged(int x, int y, int button) {
	fbo.begin();
	ofSetLineWidth(size);
	ofSetColor(color);
	polyline.addVertex(ofPoint(x, y));
	polyline.draw();
	fbo.end();
}

void Paint::mousePressed(int x, int y, int button) {
	fbo.begin();
	polyline.clear();
	fbo.end();
}