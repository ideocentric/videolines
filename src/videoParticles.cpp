//
//  videoParticles.cpp
//  videolines
//
//  Created by Matt Comeione on 12/24/22.
//

#include "videoParticles.hpp"


void videoParticles::setup() {
    ofBackground(0, 0, 0);
    webcam.setup(320, 180);
    webcam.setDesiredFrameRate(5);
    width = webcam.getWidth();
    height = webcam.getHeight();
}


void videoParticles::update() {
    webcam.update();
    if(webcam.isFrameNew()) {
        for(vector<lineParticle>::iterator it = particles.begin(); it != particles.end(); ++it) {
            if( (*it).dead ) {
                it = particles.erase(it);
            }
            (*it).update();
        }
    }
}

void videoParticles::draw() {

    float fw = ofGetWidth();
    float m = fw/width;
    ofBackground(0, 0, 0);
    //webcam.draw(0, 0, ofGetWidth(), ofGetHeight());
    for(int x=0; x<width; x++) {
        for(int y=0; y<height; y++) {
            if(ofRandom(0.0, 1.0) >= 0.999) {
                ofColor color = webcam.getPixels().getColor(x, y);
                int brightness = color.getBrightness();
                float size = ofMap(brightness, 0, 255, 5, 100);
                lineParticle particle(x*m, y*m, color, size);
                particles.push_back(particle);
            }
        }
    }
    for(vector<lineParticle>::iterator it = particles.begin(); it != particles.end(); ++it) {
        (*it).draw();
    }
}
