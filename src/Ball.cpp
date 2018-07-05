//
//  myBall.cpp
//  myBall
//
//  Created by Hiroki Ihara on 6/26/18.
//
//

#include "Ball.hpp"

// constructor
// set position, radius
Ball::Ball(){
    pos = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    radius = 100.0;
    speed = ofPoint(0,0);
    dirX = 0;
    dirY = 0;
    phaseSpeed = ofRandom(0.1,0.5);
    phase = 0;
}

void Ball::draw(){
    //draw circle1
    ofSetColor(31,63,255, 100);
    ofCircle(pos.x, pos.y, strechedRadius);
    //draw circle2
    ofSetColor(255, 0, 0, 200);
    ofCircle(pos.x, pos.y, radius/10);
}

// update

//void Ball::update(){
//    speed.x = ofRandom(5,15) * (1-dirX*2);
//    speed.y = ofRandom(5,15) * (1-dirY*2);
//    // update pos by speed
//    pos += speed;
//    //boundary
//    if (pos.x < radius || pos.x > ofGetWidth()-radius){
//        dirX+=1;
//        dirX%=2;
//    }
//    if (pos.y < radius || pos.y > ofGetHeight()-radius){
//        dirY+=1;
//        dirY%=2;
//    }
//}

void Ball::update(){
    // update radius
    strechedRadius = radius + sin(phase)*radius/4;
    phase += phaseSpeed;
    if(phase > TWO_PI){
        phase -= TWO_PI;
    }
    // update pos by speed
    pos += speed;
    //boundary
    if (pos.x < radius || pos.x > ofGetWidth()-radius){
        speed.x*=-1;
    }
    if (pos.y < radius || pos.y > ofGetHeight()-radius){
        speed.y*=-1.095;
    }
}


// pos setter
void Ball::setPos(ofPoint _pos) {
    pos = _pos;
}

// pos getter
ofPoint Ball::getPos() {
    return pos;
}

// radius setter
void Ball::setRadius(float _radius) {
    radius = _radius;
}

//radius getter
float Ball::getRadius() {
    return radius;
}

//speed setter and getter
void Ball::setSpeed(ofPoint _speed) {
    speed = _speed;
}
ofPoint Ball::getSpeed() {
    return speed;
}
