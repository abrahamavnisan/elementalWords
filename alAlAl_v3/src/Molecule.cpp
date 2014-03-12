//
//  Element.cpp
//  alAlAl
//
//  Created by Kayla Lewis on 2/26/14.
//
//

#include "Molecule.h"


Molecule::Molecule(const Element& _element,
                   int _subscript,
                   ofPtr<ofTrueTypeFont> _subScriptFont):
// I'm confused about this relationship and what's going on. And again with what ":" means
BaseParticle(ofVec2f()),
    element(_element),
    subscript(_subscript),
    subScriptFont(_subScriptFont),
    subscriptOffset(0, 12) //making the subscript low on Y axis
{
}


Molecule::Molecule(const ofVec2f& position,
                   const Element& _element,
                   int _subscript,
                   ofPtr<ofTrueTypeFont> _subScriptFont):
    //I'm confused about this relationship and what's going on. And again with what ":" means
    BaseParticle(position),
    element(_element),
    subscript(_subscript),
    subScriptFont(_subScriptFont),
    subscriptOffset(0, 12) //making the subscript low on Y axis
{
}

Molecule::~Molecule()
{
}

void Molecule::draw()
{
    ofSetColor(255, 0, 0);
    ofNoFill();
    ofRect(getBoundingBox());

    ofPushStyle();
    ofPushMatrix();
    ofTranslate(position);

    element.draw();
    ofRectangle rect = element.getBoundingBox();
    ofRectangle sRect = subScriptFont->getStringBoundingBox(ofToString(subscript), 0, 0);

    ofTranslate(rect.width, rect.height);
    ofTranslate(subscriptOffset.x, subscriptOffset.y + sRect.height);

    ofSetColor(0, 255, 0);
    ofNoFill();
    ofRect(sRect);

    ofFill();
    ofSetColor(0);
    subScriptFont->drawString(ofToString(subscript), 0, 0);
    // ofToString is making subscript into a string...but why wasn't it just a string initially?
    // We kept it as a number so we could use it to iterate through and add X number of
    // elements to the new particle system.

    ofPopMatrix();
    ofPopStyle();
}

ofRectangle Molecule::getBoundingBox() const
{
    ofRectangle rect = element.getBoundingBox();
    ofRectangle sRect = subScriptFont->getStringBoundingBox(ofToString(subscript), 0, 0);

    ofRectangle totalBoundingBox;

    totalBoundingBox.x = position.x;
    totalBoundingBox.y = position.y;

    totalBoundingBox.width = rect.width + sRect.width + subscriptOffset.x;
    totalBoundingBox.height = rect.height + sRect.height + subscriptOffset.y;

    return totalBoundingBox;
    
}