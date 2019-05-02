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
    
    ofSetVerticalSync(true);
    ofBackgroundHex(0xfdefc2);
    ofSetLogLevel(OF_LOG_NOTICE);
    
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createBounds();
    box2d.setFPS(60.0);
    box2d.registerGrabbing();
    
    gameBoard.drawGrids();
    
    gameBoard.createRectangles();
    
    gameBoard.setUpBounds();
    
    player_one.serial = 1;
    
    player_one.serial = 2;
    
    grid.load("image_for_tic_tac.png");
    
    image_for_x.load("OforTicTacToe.png");
    
    image_for_O.load("XforTicTacToe.png");
    
    game_font.load("tetri.ttf", 30);
    
    start_game_f.load("tetri.ttf", 15);
    
    start_game.set(400, 400, 200, 100);
    
    intro_sequence.load("Zombie_Nation_Kernkraft_400-[AudioTrimmer.com].mp3");
    
    intro_sequence.setVolume(0.5);
    
    gui.setup();
    gui.add(volume.setup("Volume", 1.0, 0.0, 1.0));
    intro_sequence.play();



}

//--------------------------------------------------------------
void ofApp::update(){
    if (start_pressed == true) {
        currentState = GAME_ON;
    }
    if (currentState == GAME_ON) {
        box2d.update();
        if (player_won == true) {
            did_player_win = false;
            clearBoard();
            player_won = false;
        }
        if (did_player_win == true) {
            player_won = true;
            if (current_player.serial == 1) {
                player_one.number_of_wins++;
            }
            if (current_player.serial == 1) {
                player_one.number_of_wins++;
            }
            ofSystemAlertDialog("winner is here");
            
        }
        checkForWinner();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    intro_sequence.setVolume(volume);
    
    if (currentState == ENTRY_SCREEN) {
        setUpInitialScreen();
    }
    if (currentState == GAME_ON) {
        for(int i= 0; i<circles.size(); i++) {
            ofFill();
            ofSetHexColor(0xf6c738);
            if (i % 3 == 0) {
                circles[i].get()->draw();
            }
        }
        for(int i=0; i<boxes.size(); i++) {
            ofFill();
            ofSetHexColor(0xBF2545);
            if (i % 3 == 0) {
                boxes[i].get()->draw();
            }
        }
        
        
        box2d.drawGround();
        drawGameScreen();
        
        ofDrawBitmapString("Player1: " + first_player_Name, 10, 30);
        ofDrawBitmapString("Score: " + to_string(player_one.number_of_wins), 10, 40);
        ofDrawBitmapString("Player2 :" + second_player_name, 900, 30);
        ofDrawBitmapString("Score: " + to_string(player_two.number_of_wins), 900, 40);
        
        createOsandXs();
        
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
    if  (currentState == GAME_ON) {
        
        if (current_player.serial == 0) {
            float r = ofRandom(4, 20);
            circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
            circles.back().get()->setPhysics(1.0, 0.43, 0.1);// change made in this
            circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r);
        }
        
        if (current_player.serial == 2) {
            float w = ofRandom(4, 20);
                    float h = ofRandom(4, 20);
                    boxes.push_back(shared_ptr<ofxBox2dRect>(new ofxBox2dRect));
                    boxes.back().get()->setPhysics(3.0, 0.53, 0.1);
                    boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
        }
    }

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    
    if (currentState == ENTRY_SCREEN) {
        if (start_game.inside(x, y)) {
            start_pressed = true;
        }
    }
    if (currentState == GAME_ON) {
        std::cout<<"This is check change "<<endl;
        if (m % 2 == 0) {
            current_player = player_one;
        } else {
            current_player = player_two;
        }
        gameBoard.mouseReleased(x, y, current_player);
    }
    m++;
    
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
    ofDrawRectRounded(start_game, BUTTON_LENGTH_START);
    
    ofSetColor(255, 255, 255);
    start_game_f.drawString(ktext_for_start, 450, 450);
    
    ofPushMatrix();
    
    ofSetColor(158, 253, 159);
    string scaleA = "TIC TAC HOE";
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
           
            if (i == 0 & j == 0) {
                board_matrix[i][j].tile.set(347, 246, board_matrix[i][j].width, board_matrix[i][j].height);
            }
            if (i == 0 & j == 1) {
                board_matrix[i][j].tile.set(470, 256, board_matrix[i][j].width, board_matrix[i][j].height);
            }
            if (i == 0 & j == 2) {
                board_matrix[i][j].tile.set(605, 256, board_matrix[i][j].width, board_matrix[i][j].height);
            }
            if (i == 1 & j == 0) {
                board_matrix[i][j].tile.set(350, 375, board_matrix[i][j].width, board_matrix[i][j].height);
            }
            if (i == 1 & j == 1) {
                board_matrix[i][j].tile.set(470, 370, board_matrix[i][j].width, board_matrix[i][j].height);
            }
            if (i == 1 & j == 2) {
                board_matrix[i][j].tile.set(605, 375, board_matrix[i][j].width, board_matrix[i][j].height);
            }
            if (i == 2 & j == 0) {
                board_matrix[i][j].tile.set(343, 480, board_matrix[i][j].width, board_matrix[i][j].height);
            }
            if (i == 2 & j == 1) {
                board_matrix[i][j].tile.set(470, 480, board_matrix[i][j].width, board_matrix[i][j].height);
            }
            if (i == 2 & j == 2) {
                board_matrix[i][j].tile.set(605, 480, board_matrix[i][j].width, board_matrix[i][j].height);
            }
            
        }
    }
    
}

//-------------------------------------------------------------------------------

void ofApp::clearBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gameBoard.board_matrix[i][j].value = -1;
        }
    }
}

//-----------------------------------------------

void ofApp::checkForWinner() {
    gameBoard.stringCreation();
    
    
    
    if (gameBoard.checkForDiagonalWinner('X', gameBoard.values_on_board_as_str)) {
        did_player_win = true;
        ofColor(23,34,56);
        did_player_win = true;
    }
    if (gameBoard.checkForDiagonalWinner('O', gameBoard.values_on_board_as_str)) {
        ofColor(23,34,56);
        did_player_win = true;
    }
    if (gameBoard.checkForHorizontalWinner('O', gameBoard.values_on_board_as_str)) {
        ofColor(23,34,56);
        did_player_win = true;
    }
    if (gameBoard.checkForHorizontalWinner('X', gameBoard.values_on_board_as_str)) {
        ofColor(23,34,56);
        did_player_win = true;
    }
    
    if (gameBoard.checkForVerticalWinner('O', gameBoard.values_on_board_as_str)) {
        ofColor(23,34,56);
        did_player_win = true;
    }
    if (gameBoard.checkForVerticalWinner('X', gameBoard.values_on_board_as_str)) {
        ofColor(23,34,56);
        did_player_win = true;
    }
    
}

//--------------------------------------------------

void ofApp::createOsandXs() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard.board_matrix[i][j].value == 0) {
                if (i == 0 & j == 0) {
                    image_for_O.draw(347, 246);
                }
                if (i == 0 & j == 1) {
                    image_for_O.draw(470, 256);
                }
                if (i == 0 & j == 2) {
                    image_for_O.draw(605, 256);
                }
                if (i == 1 & j == 0) {
                    image_for_O.draw(350, 375);
                }
                if (i == 1 & j == 1) {
                    image_for_O.draw(470, 370);
                }
                if (i == 1 & j == 2) {
                    image_for_O.draw(605, 375);
                }
                if (i == 2 & j == 0) {
                    image_for_O.draw(343, 480);
                }
                if (i == 2 & j == 1) {
                    image_for_O.draw(470, 480);
                }
                if (i == 2 & j == 2) {
                    image_for_O.draw(605, 480);
                }
                
            }
            
            if (gameBoard.board_matrix[i][j].value == 1) {
                if (i == 0 & j == 0) {
                    image_for_x.draw(347, 246);
                }
                if (i == 0 & j == 1) {
                    image_for_x.draw(470, 256);
                }
                if (i == 0 & j == 2) {
                    image_for_x.draw(605, 256);
                }
                if (i == 1 & j == 0) {
                    image_for_x.draw(350, 375);
                }
                if (i == 1 & j == 1) {
                    image_for_x.draw(470, 370);
                }
                if (i == 1 & j == 2) {
                    image_for_x.draw(605, 375);
                    
                }
                if (i == 2 & j == 0) {
                    image_for_x.draw(343, 480);
                }
                if (i == 2 & j == 1) {
                    image_for_x.draw(470, 480);
                }
                if (i == 2 & j == 2) {
                    image_for_x.draw(605, 480);
                }
            }
        }
    }
    
}




    

    
        
        

    
 
    
    
    
    
    


