//
//  lineParticle.cpp
//  videolines
//
//  Created by Matt Comeione on 12/24/22.
//

#include "lineParticle.hpp"


//--------------------------------------------------------------
lineParticle::lineParticle(int x, int y, ofColor c) {
    position = glm::vec2(x, y);
    size = ofRandom(50, 400);
    growth = size/60*2;
    decay = size/60/5;
    length = 1;
    width = ofRandom(0.5, 4.0);
    color.setHsb(c.getHue(), c.getSaturation(), c.getBrightness(), PARTICLE_ALPHA);
    dead = false;
    growing = true;
    force = glm::vec2(0, 0.02);
    direction = glm::vec2(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0));
}


//--------------------------------------------------------------
lineParticle::lineParticle(int x, int y, ofColor c, float s) {
    position = glm::vec2(x, y);
    size = s;
    growth = size/60*2;
    decay = size/60/5;
    length = 1;
    width = ofRandom(0.5, 8.0);
    color.setHsb(c.getHue(), c.getSaturation(), c.getBrightness(), PARTICLE_ALPHA);
    dead = false;
    growing = true;
    force = glm::vec2(0, 0.02);
    direction = glm::vec2(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0));
}


//--------------------------------------------------------------
lineParticle::~lineParticle() {
    
}


//--------------------------------------------------------------
void lineParticle::update() {
    position += direction;
    direction += force;
    
    if(growing) {
        length += growth;
        if(length>= size) {
            growing = false;
        }
    }
    else {
        length -= decay;
        if(length<1) {
            length = 1;
        }
    }
    
    float brightness = color.getBrightness();
    if(brightness > 1) {
        color.setBrightness(brightness -= 1.1); // (-0.5 -> -1.2)
    }
    else {
        color.setBrightness(0);
        dead = true;
    }
    
    if(position.x < 0 || position.x > ofGetWidth() || position.y > ofGetHeight())
    {
        dead = true;
    }
}


//--------------------------------------------------------------
void lineParticle::draw() {
    ofSetColor(color);
    ofSetLineWidth(width);
    glm::vec2 diff = glm::vec2(0, length);
    glm::vec2 end = position + diff;
    ofDrawLine(position, end);
}
