#pragma once

#include <string>
#include "ofVec2f.h"
#include "BaseParticle.h"

//a lot of the same things are happening as in BaseParticle.h, but pos, vel, acc aren't reincluded. now we load a font reference so it doesn't have to reload the font every time, and we designate strings so we can see the letters.

class Element: public BaseParticle
    //I don't understand why these "publics" are nested this way with the BaseParticle reference
{
public:
    Element(const ofVec2f& position,
            const std::string& name,
            ofPtr<ofTrueTypeFont> font);

    Element(const std::string& name,
            ofPtr<ofTrueTypeFont> font);

    virtual ~Element();

    virtual void draw();

    virtual ofRectangle getBoundingBox() const;

    std::string name;
    
    ofPtr<ofTrueTypeFont> fontRef;
    
};