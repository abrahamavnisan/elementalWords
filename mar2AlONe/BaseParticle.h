//
//  baseParticle.h
//  alAlAl
//
//  Created by Kayla Lewis on 2/23/14.
//virtual means heirarchies don't repeat shared class relationships
//constructor/destructor, const, virtual, dynamic cast
//const read from right to left i.e. "int getWidth() const;" means the getWidth function remains the same throughout

#pragma once

#include "ofMain.h"

class BaseParticle
{
public:
    BaseParticle(const ofVec2f& position);
    virtual ~BaseParticle(); //destructor..deallocates memory, called when obkect passes out of scope and can be deleted
    
    virtual void update(); //virtual classes deal with inheritance with various classes, so it's only shared as much as it's needed.
    virtual void draw();
    
    virtual bool isInside(int x, int y) const; //must be inside x & y to react
    
    virtual ofRectangle getBoundingBox() const; //getBoundingBox is a name you've given virtual rect function
    
    virtual int getWidth() const;
    virtual int getHeight() const;

    int age;
    
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;

};
