//
//  myBall.cpp
//  myBall
//
//  Created by Hiroki Ihara on 6/26/18.
//
//

#include "Ball.hpp"

void Ball::draw(){
    ofSetColor(31,63,255);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
}
