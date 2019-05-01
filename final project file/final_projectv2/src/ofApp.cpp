#include "ofApp.h"
#include "grid.hpp"
#include "board_.hpp"

//--------------------------------------------------------------



board gameBoard;

Player player_one;

Player player_two;


Player current_player = player_one;



bool take_user_input = false;





void ofApp::setup() {
    
    gameBoard.drawGrids();
    
    gameBoard.createRectangles();
    
    gameBoard.setUpBounds();
    
    player_one.serial = 1;
    
    player_one.serial = 2;
    
    grid.load("/Users/sahil_21/Desktop/image_with_transparent.png");
    
    image_for_x.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/OforTicTacToe.png");
    
    image_for_O.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/XforTicTacToe.png");
    
    
    
    game_font.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/tetri.ttf", 30);
    
    
    
    start_game_f.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/tetri.ttf", 15);
    
    start_game.set(400, 400, 200, 100);
    
   
    
    intro_sequence.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/Zombie_Nation_Kernkraft_400-[AudioTrimmer.com].mp3");
    
    intro_sequence.setVolume(0.5);
    
    
    image_for_O.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/XforTicTacToe.png");
    
    image_for_x.load("/Users/sahil_21/Documents/final-project-sahil211999/final project file/final_projectv2/bin/data/OforTicTacToe.png");
    
   // intro_sequence.play();

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
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard.something[i][j].value == 0) {
                    if (i == 0 & j == 0) {
                        image_for_O.draw(357, 256);
                        break;
                    }
                    if (i == 0 & j == 1) {
                        image_for_O.draw(503, 266);
                        break;
                    }
                    if (i == 0 & j == 2) {
                        image_for_O.draw(632, 270);
                        break;
                    }
                    if (i == 1 & j == 0) {
                        image_for_O.draw(366, 391);
                        break;
                    }
                    if (i == 1 & j == 1) {
                        image_for_O.draw(502, 394);
                        break;
                    }
                    if (i == 1 & j == 2) {
                        image_for_O.draw(641, 391);
                        break;
                    }
                    if (i == 2 & j == 0) {
                        image_for_O.draw(353, 541);
                        break;
                    }
                    if (i == 2 & j == 1) {
                        image_for_O.draw(502, 527);
                        break;
                    }
                    if (i == 2 & j == 2) {
                        image_for_O.draw(640, 520);
                        break;
                    }
                    
                }
                if (gameBoard.something[i][j].value == 1) {
                    std::cout<<"drawing image"<<endl;
                    count_for_num_of_draws++;
                    std::cout<<count_for_num_of_draws<<endl;
                    if (i == 0 & j == 0) {
                        std::cout<<"drawing image first grid"<<endl;
                        image_for_x.draw(347, 246);
                        
                    }
                    if (i == 0 & j == 1) {
                        std::cout<<"drawing image second grid"<<endl;
                        image_for_x.draw(470, 256);
                     
                    }
                    if (i == 0 & j == 2) {
                        std::cout<<"drawing image third grid"<<endl;
                        image_for_x.draw(605, 256);
                        
                    }
                    if (i == 1 & j == 0) {
                        std::cout<<"drawing image fourth grid"<<endl;
                        image_for_x.draw(350, 375);
                     
                    }
                    if (i == 1 & j == 1) {
                        std::cout<<"drawing image fifth grid"<<endl;
                        image_for_x.draw(470, 370);
                      
                    }
                    if (i == 1 & j == 2) {
                        std::cout<<"drawing image sixth grid"<<endl;
                        image_for_x.draw(605, 375);
                       
                    }
                    if (i == 2 & j == 0) {
                        std::cout<<"drawing image seventh grid"<<endl;
                        image_for_x.draw(343, 480);
                      
                    }
                    if (i == 2 & j == 1) {
                        std::cout<<"drawing image eigth grid"<<endl;
                        image_for_x.draw(470, 480);
                        
                    }
                    if (i == 2 & j == 2) {
                        std::cout<<"drawing image ninth grid"<<endl;
                        image_for_x.draw(605, 480);
                     
                    }
                    
                    
                }
            }
        }
        
        
    }
//    m++;
    
    
    

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
    if (currentState == ENTRY_SCREEN) {
        if (start_game.inside(x, y)) {
            currentState = GAME_ON;
        }
    }
    if (currentState == GAME_ON) {
//        if (m % 2 == 0) {
//            current_player = player_one;
//        } else {
//            current_player = player_two;
//       }
        gameBoard.mouseReleased(x, y);
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    
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
    
    
   
    grid.draw(180, 100);
    gameBoard.drawGrids();
    
    ofDrawBitmapString(ofGetMouseX(), 10, 10);
    ofDrawBitmapString(ofGetMouseY(), 20, 20);
    
    if (!take_user_input) {
        first_player_Name = ofSystemTextBoxDialog("Enter the name of the first player", "  ");
        second_player_name = ofSystemTextBoxDialog("Enter the name of the second player", "  ");
        take_user_input = true;
    }

}

//---------------------------------------------------------------


void board::createRectangles() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout<<"creating rectangles"<<endl;
            
            if (i == 0 & j == 0) {
                
                something[i][j].tile.set(357, 256, something[i][j].width, something[i][j].height);
                
            }
            if (i == 0 & j == 1) {
                something[i][j].tile.set(503, 266, something[i][j].width, something[i][j].height);
                
            }
            if (i == 0 & j == 2) {
                something[i][j].tile.set(632, 270, something[i][j].width, something[i][j].height);
                
            }
            if (i == 1 & j == 0) {
                something[i][j].tile.set(366, 391, something[i][j].width, something[i][j].height);
               
            }
            if (i == 1 & j == 1) {
                something[i][j].tile.set(502, 394, something[i][j].width, something[i][j].height);
                
            }
            if (i == 1 & j == 2) {
                something[i][j].tile.set(641, 391, something[i][j].width, something[i][j].height);
                
            }
            if (i == 2 & j == 0) {
                something[i][j].tile.set(353, 541, something[i][j].width, something[i][j].height);
                
            }
            if (i == 2 & j == 1) {
                something[i][j].tile.set(502, 527, something[i][j].width, something[i][j].height);
                
            }
            if (i == 2 & j == 2) {
                something[i][j].tile.set(640, 520, something[i][j].width, something[i][j].height);
               
            }
            
        }
    }
    
}




    

    
        
        

    
 
    
    
    
    
    


