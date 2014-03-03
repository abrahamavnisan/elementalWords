#pragma once

#include <string>
#include "ofVec2f.h"
#include "BaseParticle.h"
#include "Element.h"

class Molecule: public BaseParticle
{
public:
    Molecule(const ofVec2f& position,
            const Element& element,  //so we have a reference to Element class... and then element and subscript are redefined below? why?
            int subscript,
            ofTrueTypeFont& _subScriptFont);
    virtual ~Molecule();

    virtual void draw();
    
    virtual ofRectangle getBoundingBox() const;

    Element element;
    int subscript;
    ofVec2f subscriptOffset;
    
    ofTrueTypeFont& subScriptFont;
    
};
