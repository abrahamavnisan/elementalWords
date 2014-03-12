//
//  baseParticle.cpp
//  alAlAl
//
//  Created by Kayla Lewis on 2/23/14.
//
//

#include "baseParticle.h"


// what does one ":" do? this line is confusing in general.
// http://www.cprogramming.com/tutorial/initialization-lists-c++.html

BaseParticle::BaseParticle(const ofVec2f& _position):
    age(0),
    position(_position),
    drag(0.95)
{
}


BaseParticle::~BaseParticle()
{
}


void BaseParticle::update()
{
    age++;
    velocity += acceleration;
    position += velocity;

    velocity *= drag;
}


void BaseParticle::draw()
{
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(position);
    ofFill();
    ofSetColor(0);
    ofCircle(0, 0, 20);
    ofPopMatrix();
    ofPopStyle();
}

bool BaseParticle::isInside(int x, int y) const
{
    // for this ofRect getBoundingBox() if x,y is inside, return True
    return getBoundingBox().inside(x, y);
}


ofRectangle BaseParticle::getBoundingBox() const
{
    return ofRectangle(0, 0, 0, 0);
}


int BaseParticle::getWidth() const
{
    return getBoundingBox().width;
}


int BaseParticle::getHeight() const
{
    return getBoundingBox().height;
}
