//
//  Element.cpp
//  alAlAl
//
//  Created by Kayla Lewis on 2/26/14.
//
//

#include "Molecule.h"


Molecule::Molecule(const ofVec2f& position,
                   const Element& _element,
                   int _subscript,
                   ofTrueTypeFont& _subScriptFont): //I'm confused about this relationship and what's going on. And again with what ":" means
    BaseParticle(position),
    element(_element),
    subscript(_subscript),
    subScriptFont(_subScriptFont),
    subscriptOffset(0,12) //making the subscript low on Y axis
{
}

Molecule::~Molecule()
{
}

void Molecule::draw()
{
    element.draw();
    ofRectangle rect = element.getBoundingBox();

    ofPushStyle();
    ofPushMatrix();
    ofTranslate(position);
    ofTranslate(rect.width, 0);
    ofTranslate(subscriptOffset);
    ofFill();
    ofSetColor(0);
    
    subScriptFont.drawString(ofToString(subscript), 0, 0); //ofToString is making subscript into a string...but why wasn't it just a string initially?   
    
    ofPopMatrix();
    ofPopStyle();
}

ofRectangle Molecule::getBoundingBox() const
{
    ofRectangle rect = element.getBoundingBox();
    
    ofRectangle sRect = subScriptFont.getStringBoundingBox(ofToString(subscript), 0, 0);
    
    rect.width += (sRect.width + subscriptOffset.x);
    rect.height += (sRect.height + subscriptOffset.y);
    
    return rect;
    
}