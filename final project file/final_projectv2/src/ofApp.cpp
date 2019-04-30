#include "ofApp.h"
#include "grid.hpp"
#include "board_.hpp"

//--------------------------------------------------------------



board gameBoard;

Player player1;

bool take_user_input = false;



void ofApp::setup(){
    grid.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/image_for_tic_tac.png");
    
    
    
    game_font.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/tetri.ttf", 30);
    
    
    
    start_game_f.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/tetri.ttf", 15);
    
    start_game.set(400, 400, 200, 100);
    
   // grid.load("/Users/sahil_21/Desktop/image_for_tic_tac.png");
    
    intro_sequence.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/Zombie_Nation_Kernkraft_400-[AudioTrimmer.com].mp3");
    
    intro_sequence.setVolume(0.5);
    
    intro_sequence.play();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (currentState == ENTRY_SCREEN) {
        setUpInitialScreen();
    }
    if (currentState == GAME_ON) {
        drawGameScreen();
    }
    

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
    if (currentState == ENTRY_SCREEN) {
        if (start_game.inside(x, y)) {
            currentState = GAME_ON;
        }
    }

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
//-------------------------------------------------------------
void ofApp::setUpInitialScreen() {
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
    
    
    if (!take_user_input) {
        first_player_Name = ofSystemTextBoxDialog("Enter the name of the first player", "  ");
        second_player_name = ofSystemTextBoxDialog("Enter the name of the second player", "  ");
        take_user_input = true;
    }
    
    grid.draw(300,300);
    gameBoard.drawGrids();
    
    
 
    
    
    
    
    
}

