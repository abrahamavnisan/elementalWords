#pragma once

#include <string>
#include "ofVec2f.h"
#include "BaseParticle.h"
#include "Element.h"

class Molecule: public BaseParticle
{
public:
    // so we have a reference to Element class...
    // and then element and subscript are redefined below? why?
    Molecule(const Element& element,
             int subscript,
             ofPtr<ofTrueTypeFont> _subScriptFont);

    Molecule(const ofVec2f& position,
             const Element& element,
             int subscript,
             ofPtr<ofTrueTypeFont> _subScriptFont);

    virtual ~Molecule();

    virtual void draw();
    
    virtual ofRectangle getBoundingBox() const;

    Element element;

    int subscript;

    ofVec2f subscriptOffset;
    
    ofPtr<ofTrueTypeFont> subScriptFont;
    
};
