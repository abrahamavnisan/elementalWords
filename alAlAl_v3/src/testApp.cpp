#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

    font = ofPtr<ofTrueTypeFont>(new ofTrueTypeFont());
    subScriptFont = ofPtr<ofTrueTypeFont>(new ofTrueTypeFont());

    font->loadFont("BigCaslon.ttf", 40);
    subScriptFont->loadFont("BigCaslon.ttf", 20);

    Element hydrogen("H", font);
    Element oxygen("O", font);

    ofVec2f initialPosition;

    initialPosition = ofVec2f(ofRandomWidth(), ofRandomHeight());
    Molecule h2(initialPosition, hydrogen, 2, subScriptFont);
    molecules.push_back(h2);

    initialPosition = ofVec2f(ofRandomWidth(), ofRandomHeight());
    Molecule o1(initialPosition, oxygen, 1, subScriptFont);
    molecules.push_back(o1);

}

//--------------------------------------------------------------
void testApp::update(){
   
    for (int i = 0; i < elements.size(); i++)
    {
        elements[i].update();
    }

    for (int i = 0; i < molecules.size(); i++)
    {
        molecules[i].update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(255);

    /* iterators...I'll have to read about those more. Pointers in general and when to call them still have me stumped. Those I have read about a lot. This is iterating through the particles vec but I don't know how to realize you'd need to name an iterator. */

    std::vector<Molecule>::iterator moleculeIter = molecules.begin();

    while (moleculeIter != molecules.end())
    {
        Molecule& molecule = *moleculeIter;

        molecule.draw();

        if(molecule.isInside(mouseX, mouseY))
        {
            for (int i = 0; i < molecule.subscript; i++)             {
                Element element(molecule.position, molecule.element.name, font); //draws single elements
                element.velocity= ofVec2f(ofRandom(-4,4),ofRandom(-4,4)); //designating velocity for single elements
                elements.push_back(element);
            }

            moleculeIter = molecules.erase(moleculeIter); // delete the original Molecule Particle
        }
        else
        {
            ++moleculeIter;
            //if the mouse never hits then the molecules don't break apart...why ++iter though?
        }
    }




    std::vector<Element>::iterator elementIter = elements.begin();

    while (elementIter != elements.end())
    {
        Element& element = *elementIter;

        element.draw();

        if(element.isInside(mouseX, mouseY))
        {
            ofPushStyle();
            ofFill();
            ofSetColor(255, 255, 0);
            ofRect(element.getBoundingBox());
            ofPopStyle();
        }

        ++elementIter;
    }


//    for (int i = 0; i < elements.size(); ++i)
//    {
//        Element& element = elements[i];
//
//        element.draw();
//
//        if(element.isInside(mouseX, mouseY))
//        {
//            ofPushStyle();
//            ofFill();
//            ofSetColor(255, 255, 0);
//            ofRect(element.getBoundingBox());
//            ofPopStyle();
//        }
//    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){


}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
