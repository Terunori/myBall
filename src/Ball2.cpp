//
//  Ball2.cpp
//  myBall
//
//  Created by Hiroki Ihara on 7/6/18.
//
//

#include "Ball2.hpp"

// constructor
// set position, radius
Ball2::Ball2(){
    pos = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    radius = 100.0;
    speed = ofPoint(0,0);
    dirX = 0;
    dirY = 0;
    phaseSpeed = ofRandom(0.1,0.5);
    phase = 0;
}

void Ball2::draw(){
    //draw circle1
    ofSetColor(31,63,255, 100);
    ofCircle(pos.x, pos.y, strechedRadius);
    //draw circle2
    ofSetColor(255, 0, 0, 200);
    ofCircle(pos.x, pos.y, radius/15);
}

// update

void Ball2::update(){
    // update radius
    strechedRadius = radius + sin(phase)*radius/4;
    phase += phaseSpeed;
    if(phase > TWO_PI){
        phase -= TWO_PI;
    }
    // speed.x = ofRandom(5,15) * (1-dirX*2);
    // speed.y = ofRandom(5,15) * (1-dirY*2);
    speed.x = 8*radius/strechedRadius * (1-dirX*2);
    speed.y = 5*radius/strechedRadius * (1-dirY*2);
    // update pos by speed
    pos += speed;
    //boundary
//    if (pos.x <= strechedRadius || pos.x >= ofGetWidth()-strechedRadius){
    if (pos.x <= radius*1.25 || pos.x >= ofGetWidth()-radius*1.25){
        dirX+=1;
        dirX%=2;
    }
    if (pos.y <= radius*1.25 || pos.y >= ofGetHeight()-radius*1.25){
        dirY+=1;
        dirY%=2;
    }
}

// pos setter
void Ball2::setPos(ofPoint _pos) {
    pos = _pos;
}

// pos getter
ofPoint Ball2::getPos() {
    return pos;
}

// radius setter
void Ball2::setRadius(float _radius) {
    radius = _radius;
}

//radius getter
float Ball2::getRadius() {
    return radius;
}

//speed setter and getter
void Ball2::setSpeed(ofPoint _speed) {
    speed = _speed;
}
ofPoint Ball2::getSpeed() {
    return speed;
}
