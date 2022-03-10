#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
	ofSetLineWidth(2);
	
	// 配色デザイン ソフトグリーン P114
	this->color_palette.push_back(ofColor(97, 157, 110));
	this->color_palette.push_back(ofColor(119, 180, 106));
	this->color_palette.push_back(ofColor(143, 173, 91));
	this->color_palette.push_back(ofColor(145, 195, 161));
	this->color_palette.push_back(ofColor(93, 169, 145));
	this->color_palette.push_back(ofColor(249, 229, 128));
	this->color_palette.push_back(ofColor(131, 193, 215));
	this->color_palette.push_back(ofColor(255, 255, 255));
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int i = 0; i < 1500; i++) {

		auto radius = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.008), 0, 1, 200, 300);
		auto deg = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0005), 0, 1, -360, 360);
		auto x = radius * cos(deg * DEG_TO_RAD);
		auto y = radius * sin(deg * DEG_TO_RAD);
		auto size = ofRandom(3, 15);
		int color_index = ofRandom(this->color_palette.size());
		int line_index = (color_index + 1) % this->color_palette.size();

		auto color = this->color_palette[color_index];
		color.setHsb(color.getHue(), color.getSaturation(), ofMap(i, 0, 1500, 0, 255));
		auto line_color = this->color_palette[line_index];
		line_color.setHsb(line_color.getHue(), line_color.getSaturation(), ofMap(i, 0, 1000, 0, 255));

		ofFill();
		ofSetColor(color);
		ofDrawCircle(glm::vec2(x, y), size);

		ofNoFill();
		ofSetColor(line_color);
		ofDrawCircle(glm::vec2(x, y), size);
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}