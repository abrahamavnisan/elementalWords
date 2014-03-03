//
//  baseParticle.cpp
//  alAlAl
//
//  Created by Kayla Lewis on 2/23/14.
//
//

#include "baseParticle.h"


BaseParticle::BaseParticle(const ofVec2f& _position): age(0), position(_position) //what does one ":" do? this line is confusing in general. 
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
    return getBoundingBox().inside(x, y); //for this ofRect getBoundingBox() if x,y is inside, return True
}

ofRectangle BaseParticle::getBoundingBox() const
{
    return ofRectangle(0,0,0,0);    
}

int BaseParticle::getWidth() const
{
    return getBoundingBox().width;
}

int BaseParticle::getHeight() const
{
    return getBoundingBox().height;
}
