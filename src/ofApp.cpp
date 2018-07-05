#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    setting background
    ofBackground(0,0,0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    // set
    myBall.setSpeed(ofPoint(15,10));
}

//--------------------------------------------------------------
void ofApp::update(){
    myBall.setSpeed(myBall.getSpeed()+ofPoint(0,5));
    myBall.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    myBall.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
