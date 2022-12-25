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
    webcam.setDesiredFrameRate(30);
    width = webcam.getWidth();
    height = webcam.getHeight();
}


void videoParticles::update() {
    webcam.update();
    if(webcam.isFrameNew()) {
        for(int i=0; i<particles.size(); i++) {
            particles[i].update();
        }
    }
}

void videoParticles::draw() {
    int grid = 16;
    float m = ofGetScreenWidth()/width;
    for(int x=0; x<width; x++) {
        for(int y=0; y<height; y++) {
            if(ofRandom(0.0, 1.0) >= 0.998) {
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
        if( (*it).dead ) {
            it = particles.erase(it);
        }
    }
}
