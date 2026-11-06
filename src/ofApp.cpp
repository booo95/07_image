#include "ofApp.h"

ofColor ofApp::filter(ofColor color, int effectP, float p) {
	float r = color.r;
	float g = color.g;
	float b = color.b;
	float luminance = 0.299f * r + 0.587f * g + 0.114f * b;

	if (effectP == 1) {
		ofColor inversedColor = ofColor(255 - r, 255 - g, 255 - b);
		return inversedColor;
	}
	else if (effectP == 2){
		float grey = (r + g + b) / 3;
		ofColor greyColor = ofColor(grey, grey, grey);
		return greyColor;
	}
	else if (effectP == 3) {
		ofColor greyColor = ofColor(luminance, luminance, luminance);
		return greyColor;
	}
	else if (effectP == 4) {
		float k = (p - 0.5f) * 256;
		int newRed = ofClamp(r + k, 0, 255);
		int newGreen = ofClamp(g + k, 0, 255);
		int newBlue = ofClamp(b + k, 0, 255);
		ofColor brightNessColor = ofColor(newRed, newGreen, newBlue);
		return brightNessColor;
	}
	else if (effectP == 5) {
		float k = p * 3;
		int newRed = ofClamp((r - 128) * k + 128, 0, 255);
		int newGreen = ofClamp((g - 128) * k + 128, 0, 255);
		int newBlue = ofClamp((b - 128) * k + 128, 0, 255);
		ofColor contrastColor = ofColor(newRed, newGreen, newBlue);
		return contrastColor;
	}
	else if (effectP == 6) {
		int sepiaRed = ofClamp(r * 0.393 + g * 0.769 + b * 0.189, 0, 255);
		int sepiaGreen = ofClamp(g * 0.349 + g * 0.686 + b * 0.168, 0, 255);
		int sepiaBlue = ofClamp(b * 0.272 + g * 0.534 + b * 0.131, 0, 255);
		ofColor sepiaColor = ofColor(sepiaRed, sepiaGreen, sepiaBlue);
		return sepiaColor;
	}



	else {
		
		return color;
	}

}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(2560, 1440);
	bool loadingOk = imgSource.load("peroquet.png");
	if (!loadingOk) {
		ofLogError() << "image non trouvée";
	}
	imgResult.allocate(imgSource.getWidth(), imgSource.getHeight(), OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
	/*
	int px = ofClamp(mouseX, 0, imgSource.getWidth() - 1);
	int py = ofClamp(mouseY, 0, imgSource.getWidth() - 1);
	currentColor = imgSource.getColor(px, py);
	*/

	float power = mouseX / (float)ofGetWidth();

	for (int y = 0; y < imgSource.getHeight(); y++) {
		for (int x = 0; x < imgSource.getWidth(); x++) {
			ofColor transferColor = imgSource.getColor(x, y);
			ofColor modifiedColor = filter(transferColor, effect, power);
			imgResult.setColor(x, y, modifiedColor);
		}
	}
	imgResult.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255,255,255);
	imgSource.draw(0, 0);
	imgResult.draw(0, 0);

	//ofSetColor(currentColor);
	//ofDrawRectangle(mouseX + 10, mouseY + 10, 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_RIGHT) {
		effect++;
		
	}
	if (key == OF_KEY_LEFT) {
		effect--;
		effect = (effect % numberEffect) % numberEffect;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
