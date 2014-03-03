//
//  Element.cpp
//  alAlAl
//
//  Created by Kayla Lewis on 2/26/14.
//
//

#include "Element.h"


Element::Element(const ofVec2f& position, const std::string& _name, ofTrueTypeFont& _fontRef): //this setup is not clear to me
    BaseParticle(position),
    name(_name),
    fontRef(_fontRef)
{
}

Element::~Element()
{
}

void Element::draw()  //same as Base only we draw font 
{
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(position);
    ofFill();
    ofSetColor(0);
    fontRef.drawString(name, 0, 0);
    ofPopMatrix();
    ofPopStyle();
}

bool Element::isInside(int x, int y) const
{
//    cout << "here" << endl;
    return getBoundingBox().inside(x, y);
}

ofRectangle Element::getBoundingBox() const   //^why/how is this transitioning from string info to rect info
{
    return fontRef.getStringBoundingBox(name, position.x, position.y);
}

int Element::getWidth() const
{
    return fontRef.getStringBoundingBox(name, position.x, position.y).width;
}

int Element::getHeight() const
{
    return fontRef.getStringBoundingBox(name, position.x, position.y).height;
}
