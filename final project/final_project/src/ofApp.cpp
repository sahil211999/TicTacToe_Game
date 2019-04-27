#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    grid.load("/Users/sahil_21/Documents/final-project-sahil211999/final project/final_project/bin/data/image_for_tic_tac.png");
    
    first_player_Name = ofSystemTextBoxDialog("Enter the name of the first player", "  ");
    second_player_name = ofSystemTextBoxDialog("Enter the name of the second player", "  ");
    
    game_font.load("/Users/sahil_21/Documents/final-project-sahil211999/final project/final_project/bin/data/tetri.ttf", 30);
  
    
    
    start_game_f.load("/Users/sahil_21/Documents/final-project-sahil211999/final project/final_project/bin/data/tetri.ttf", 15);
    
    start_game.set(400, 400, 200, 100);
    
    grid.load("/Users/sahil_21/Desktop/image_for_tic_tac.png");
    
    intro_sequence.load("/Users/sahil_21/Documents/final-project-sahil211999/final project/final_project/bin/data/Zombie_Nation_Kernkraft_400-[AudioTrimmer.com].mp3");
    
    intro_sequence.setVolume(0.5);
    
    intro_sequence.play();
   

    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(130, 100, 70);
    ofDrawRectRounded(start_game, 200);

    ofSetColor(255, 255, 255);
    start_game_f.drawString("START GAME", 450, 450);









    ofPushMatrix();

    ofSetColor(158, 253, 159);
    string scaleA = "TIC TAC TOE";
    ofRectangle bounds = start_game_f.getStringBoundingBox(scaleA, 40, 40);

    ofTranslate(400 + bounds.width/2, 300 + bounds.height / 2, 0);
    ofScale(2.0 + cos(ofGetElapsedTimef()), 2.0 + cos(ofGetElapsedTimef()), 1.0);

    start_game_f.drawString(scaleA, -bounds.width/2, bounds.height/2 );
    ofPopMatrix();

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


//------------------------------------------------------
void ofApp::setUpinitialScreen() {
    ofSetColor(130, 100, 70);
    ofDrawRectRounded(start_game, 200);
    
    ofSetColor(255, 255, 255);
    start_game_f.drawString("START GAME", 450, 450);
    
    ofPushMatrix();
    
    ofSetColor(158, 253, 159);
    string scaleA = "TIC TAC TOE";
    ofRectangle bounds = start_game_f.getStringBoundingBox(scaleA, 40, 40);
    
    ofTranslate(400 + bounds.width/2, 300 + bounds.height / 2, 0);
    ofScale(2.0 + cos(ofGetElapsedTimef()), 2.0 + cos(ofGetElapsedTimef()), 1.0);
    
    start_game_f.drawString(scaleA, -bounds.width/2, bounds.height/2 );
    ofPopMatrix();
    

    
    
}

//-------------------------------------------------------------

void ofApp::drawGameScreen() {
    grid.draw(300,300);
    
    
}
