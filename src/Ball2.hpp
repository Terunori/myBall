//
//  Ball2.hpp
//  myBall
//
//  Created by Hiroki Ihara on 7/6/18.
//
//

// include guard
#pragma once

#include "ofMain.h"

class Ball2 {
private:
    // property
    ofPoint pos;
    ofPoint speed;
    float radius;
    int dirX, dirY;
    float phase;
    float phaseSpeed;
    float strechedRadius;
    
public:
    // Constructor
    Ball2();
    // define method
    // draw circle
    void draw();
    // update
    void update();
    // setter,getter
    void setRadius(float radius);
    float getRadius();
    void setPos(ofPoint);
    ofPoint getPos();
    void setSpeed(ofPoint);
    ofPoint getSpeed();
};
