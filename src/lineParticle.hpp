//
//  lineParticle.hpp
//  videolines
//
//  Created by Matt Comeione on 12/24/22.
//

#ifndef lineParticle_hpp
#define lineParticle_hpp

const int PARTICLE_ALPHA = 200;

#include "ofMain.h"

class lineParticle {
public:
    ofColor color;
    bool dead;
    bool growing;
    float size;
    float length;
    float growth;
    float decay;
    float width;
    glm::vec2 force;
    glm::vec2 direction;
    glm::vec2 position;
    
    void setup();
    void update();
    void draw();
    
    lineParticle(int x, int y, ofColor c);
    lineParticle(int x, int y, ofColor c, float size);
    ~lineParticle();
};

#endif /* lineParticle_hpp */
