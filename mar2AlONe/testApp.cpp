#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    font.loadFont("BigCaslon.ttf", 40);
    subScriptFont.loadFont("BigCaslon.ttf", 20);
    
    
    for (int i = 0; i < 10; i++)
    {
        ofVec2f initialPosition = ofVec2f(ofRandomWidth() - 10, ofRandomHeight() - 10);
        
        Element element(initialPosition, "Al", font);
        
        particles.push_back(new Molecule(initialPosition, element, 2, subScriptFont)); //"new" allocates memory and then constructs object at new space
    }

    for (int i = 0; i < 10; i++)
    {
        ofVec2f initialPosition = ofVec2f(ofRandomWidth() - 10, ofRandomHeight() - 10);
        
        Element element(initialPosition, "O", font);
        
        particles.push_back(new Molecule(initialPosition, element, 5, subScriptFont));
    }


}

//--------------------------------------------------------------
void testApp::update(){
   
    for (int i = 0; i < particles.size(); i++)
    {
        particles[i]->update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(255);
    
    std::vector<BaseParticle*>::iterator iter = particles.begin();
    /* iterators...I'll have to read about those more. Pointers in general and when to call them still have me stumped. Those I have read about a lot. This is iterating through the particles vec but I don't know how to realize you'd need to name an iterator. */
    
    while (iter != particles.end())
    {
        BaseParticle* p = *iter; //creating a pointer for BP that equals *iter ?
        
        p->draw();

        if(p->isInside(mouseX, mouseY))
        {
            Molecule* molecule = dynamic_cast<Molecule*>(p); //cast<new type>expression...this is changing p's base to Molecule pointer instead of Element pointer?
            
            if (molecule != 0)
            {
                for (int i = 0; i < molecule->subscript; i++) //runs up to subscript number of molecule
                {
                    Element* element = new Element(molecule->position, molecule->element.name, font); //draws single elements
                    element->velocity= ofVec2f(ofRandom(-4,4),ofRandom(-4,4)); //designating velocity for single elements
                    particles.push_back(element);
                }
                
                delete *iter;
                iter = particles.erase(iter); // delete the original Molecule Particle
            }
            else
            {
                ++iter;   //if the mouse never hits then the molecules don't break apart...why ++iter though?
            }
            
        }
        else
        {
            ++iter;
        }
    }
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
