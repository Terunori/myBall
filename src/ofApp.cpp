#include "ofApp.h"

int red, green, blue;
float loc_x, loc_y;

//--------------------------------------------------------------
void ofApp::setup(){
//    setting background
    ofBackground(0,0,0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    // set
    // myBall.setSpeed(ofPoint(15,10));
    red = 31;
    green = 63;
    blue = 255;
    //loc_x = ofGetWidth()/2;
    //loc_y = ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<balls.size(); i++) {
        balls[i].setSpeed(balls[i].getSpeed()+ofPoint(0,5));
        balls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<balls.size(); i++) {
        balls[i].draw();
    }
    ofSetColor(red,green,blue);
    ofDrawTriangle(loc_x, loc_y, loc_x, loc_y+50, loc_x+20, loc_y+40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
            case 'f':
                ofToggleFullscreen();
                break;
            case 'r':
                balls.clear();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    loc_x=x;
    loc_y=y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    loc_x=x;
    loc_y=y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    red = 127;
    green = 127;
    blue = 127;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    int bSize = balls.size();
    
    if(bSize < 1) {
        // when mouse clicking, make new Ball instance
        Ball2 b;
        // set pos
        b.setPos(ofPoint(mouseX,mouseY));
        b.setRadius(ofRandom(100,200));
        b.setSpeed((ofPoint(ofRandom(5,15),0)));
        // add instance made into vector balls
        balls.push_back(b);
    } else {
        for (int i=0; i<bSize; i++) {
            ofPoint pos = balls[i].getPos();
            float radius = balls[i].getRadius();
            float dist = ofDist(pos.x, pos.y, mouseX, mouseY);
            // click inside the circle
            if(dist < radius) {
                balls[i].setRadius(radius*0.6);
                balls[i].setPos(ofPoint(pos.x-radius*0.7,pos.y));
                balls[i].setSpeed(ofPoint(ofRandom(-radius/150,0),ofRandom(-radius/150,0)));
                // make other 3 circles
                Ball2 b1 = Ball2();
                b1.setRadius(radius*0.6);
                b1.setPos(ofPoint(pos.x,pos.y-radius*0.7));
                b1.setSpeed(ofPoint(ofRandom(0,radius/150),ofRandom(-radius/150,0)));
                balls.push_back(b1);
                Ball2 b2 = Ball2();
                b2.setRadius(radius*0.6);
                b2.setPos(ofPoint(pos.x+radius*0.7,pos.y));
                b2.setSpeed(ofPoint(ofRandom(0,radius/150),ofRandom(0,radius/150)));
                balls.push_back(b2);
                Ball2 b3 = Ball2();
                b3.setRadius(radius*0.6);
                b3.setPos(ofPoint(pos.x,pos.y+radius*0.7));
                b3.setSpeed(ofPoint(ofRandom(0,radius/150),ofRandom(0,radius/150)));
                balls.push_back(b3);
            }
        }
    }
    
    red = 31;
    green = 63;
    blue = 255;

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
