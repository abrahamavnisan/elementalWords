//
//  Element.cpp
//  alAlAl
//
//  Created by Kayla Lewis on 2/26/14.
//
//

#include "Element.h"


Element::Element(const std::string& _name,
                 ofPtr<ofTrueTypeFont> font):
    BaseParticle(ofVec2f()),
    name(_name),
    fontRef(font)
{
}


Element::Element(const ofVec2f& position,
                 const std::string& _name,
                 ofPtr<ofTrueTypeFont> font): //this setup is not clear to me
    BaseParticle(position),
    name(_name),
    fontRef(font)
{
}


Element::~Element()
{
}


void Element::draw()  // same as Base only we draw font
{
    ofRectangle rect = getBoundingBox();

    ofSetColor(0,255,255);
    ofFill();

    ofRect(rect);

    ofPushStyle();
    ofPushMatrix();
    ofTranslate(position.x, position.y + rect.height);
    ofFill();
    ofSetColor(0);
    fontRef->drawString(name, 0, 0);
    ofPopMatrix();
    ofPopStyle();
}


ofRectangle Element::getBoundingBox() const   //^why/how is this transitioning from string info to rect info
{
    ofRectangle rect = fontRef->getStringBoundingBox(name, 0, 0);
    rect.x = position.x;
    rect.y = position.y;
    return rect;
}

