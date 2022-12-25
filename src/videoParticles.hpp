//
//  videoParticles.hpp
//  videolines
//
//  Created by Matt Comeione on 12/24/22.
//

#ifndef videoParticles_hpp
#define videoParticles_hpp

#include "ofMain.h"
#include "lineParticle.hpp"

class videoParticles {
public:
    void setup();
    void update();
    void draw();
    ofVideoGrabber webcam;
    vector<lineParticle> particles;
    int width;
    int height;
    ofImage frame;
};


#endif /* videoParticles_hpp */
