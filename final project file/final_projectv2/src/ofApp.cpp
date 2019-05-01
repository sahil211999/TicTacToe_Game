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
    box2d.setGravity(0, 10);//change made
    box2d.createBounds();
    box2d.setFPS(60.0);
    box2d.registerGrabbing();
    
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
        }
        
        if (did_player_win == true) {
            player_won = true;
            ofSystemAlertDialog("winner is here");
            
        }
        
        
        
        gameBoard.stringCreation();
        cout << endl;
        
        
        if (gameBoard.checkForDiagonalWinner('X', gameBoard.values_on_board_as_str)) {
            cout<<"WINNNERRRRR for diag X"<<endl;
            did_player_win = true;
            ofColor(23,34,56);
            did_player_win = true;
        }
        if (gameBoard.checkForDiagonalWinner('O', gameBoard.values_on_board_as_str)) {
           ofColor(23,34,56);
            did_player_win = true;
           
            cout<<"WINNNERRRRR for diag O"<<endl;
        }
        if (gameBoard.checkForHorizontalWinner('O', gameBoard.values_on_board_as_str)) {
            ofColor(23,34,56);
            did_player_win = true;
            
            cout<<"WINNNERRRRR for hori O"<<endl;
        }
        if (gameBoard.checkForHorizontalWinner('X', gameBoard.values_on_board_as_str)) {
            ofColor(23,34,56);
            did_player_win = true;
           
            cout<<"WINNNERRRRR for hori X"<<endl;
        }

        if (gameBoard.checkForVerticalWinner('O', gameBoard.values_on_board_as_str)) {
            ofColor(23,34,56);
            did_player_win = true;
           
            cout<<"WINNNERRRRR for verti O"<<endl;
        }
        if (gameBoard.checkForVerticalWinner('X', gameBoard.values_on_board_as_str)) {
            ofColor(23,34,56);
            did_player_win = true;
            
            cout<<"WINNNERRRRR for verti X"<<endl;
        }
        
        
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
        
        ofDrawBitmapString("Player1 :" + first_player_Name, 10, 30);
        ofDrawBitmapString("Player2 :" + second_player_name, 900, 30);
        
        
        
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard.something[i][j].value == 0) {
                    if (i == 0 & j == 0) {
                        //std::cout<<"drawing image first grid circle"<<endl;
                        image_for_O.draw(347, 246);
                        
                    }
                    if (i == 0 & j == 1) {
                        //std::cout<<"drawing image second grid circle"<<endl;
                        image_for_O.draw(470, 256);
                        
                    }
                    if (i == 0 & j == 2) {
                        //std::cout<<"drawing image third grid circle"<<endl;
                        image_for_O.draw(605, 256);
                        
                    }
                    if (i == 1 & j == 0) {
                       // std::cout<<"drawing image fourth grid circle"<<endl;
                        image_for_O.draw(350, 375);
                        
                    }
                    if (i == 1 & j == 1) {
                       // std::cout<<"drawing image fifth grid circle"<<endl;
                        image_for_O.draw(470, 370);
                        
                    }
                    if (i == 1 & j == 2) {
                       // std::cout<<"drawing image sixth grid circle"<<endl;
                        image_for_O.draw(605, 375);
                        
                    }
                    if (i == 2 & j == 0) {
                       // std::cout<<"drawing image seventh grid circle"<<endl;
                        image_for_O.draw(343, 480);
                        
                    }
                    if (i == 2 & j == 1) {
                       // std::cout<<"drawing image eigth grid circle"<<endl;
                        image_for_O.draw(470, 480);
                        
                    }
                    if (i == 2 & j == 2) {
                      //  std::cout<<"drawing image ninth grid circle"<<endl;
                        image_for_O.draw(605, 480);
                        
                    }
                    
                }
                if (gameBoard.something[i][j].value == 1) {
                   // std::cout<<"drawing image"<<endl;
                    count_for_num_of_draws++;
                    //std::cout<<count_for_num_of_draws<<endl;
                    if (i == 0 & j == 0) {
                       // std::cout<<"drawing image first grid"<<endl;
                        image_for_x.draw(347, 246);
                        
                    }
                    if (i == 0 & j == 1) {
                       // std::cout<<"drawing image second grid"<<endl;
                        image_for_x.draw(470, 256);
                     
                    }
                    if (i == 0 & j == 2) {
                       // std::cout<<"drawing image third grid"<<endl;
                        image_for_x.draw(605, 256);
                        
                    }
                    if (i == 1 & j == 0) {
                       // std::cout<<"drawing image fourth grid"<<endl;
                        image_for_x.draw(350, 375);
                     
                    }
                    if (i == 1 & j == 1) {
                       // std::cout<<"drawing image fifth grid"<<endl;
                        image_for_x.draw(470, 370);
                      
                    }
                    if (i == 1 & j == 2) {
                       // std::cout<<"drawing image sixth grid"<<endl;
                        image_for_x.draw(605, 375);
                       
                    }
                    if (i == 2 & j == 0) {
                        //std::cout<<"drawing image seventh grid"<<endl;
                        image_for_x.draw(343, 480);
                      
                    }
                    if (i == 2 & j == 1) {
                       // std::cout<<"drawing image eigth grid"<<endl;
                        image_for_x.draw(470, 480);
                        
                    }
                    if (i == 2 & j == 2) {
                       // std::cout<<"drawing image ninth grid"<<endl;
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
    std::cout<<"This is to check player change"<<endl;
    std::cout<<m<<endl;
    if (currentState == ENTRY_SCREEN) {
        if (start_game.inside(x, y)) {
            //currentState = GAME_ON;
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
        //cout<<"This is the serial num of the player ";
       // cout<<current_player.serial<<endl;
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
    ofDrawRectRounded(start_game, 200);
    
    ofSetColor(255, 255, 255);
    start_game_f.drawString("START GAME", 450, 450);
    
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
            std::cout<<"creating rectangles"<<endl;
            
            if (i == 0 & j == 0) {
                something[i][j].tile.set(347, 246, something[i][j].width, something[i][j].height);
            }
            if (i == 0 & j == 1) {
                something[i][j].tile.set(470, 256, something[i][j].width, something[i][j].height);
            }
            if (i == 0 & j == 2) {
                something[i][j].tile.set(605, 256, something[i][j].width, something[i][j].height);
            }
            if (i == 1 & j == 0) {
                something[i][j].tile.set(350, 375, something[i][j].width, something[i][j].height);
               
            }
            if (i == 1 & j == 1) {
                something[i][j].tile.set(470, 370, something[i][j].width, something[i][j].height);
                
            }
            if (i == 1 & j == 2) {
                something[i][j].tile.set(605, 375, something[i][j].width, something[i][j].height);
                
            }
            if (i == 2 & j == 0) {
                something[i][j].tile.set(343, 480, something[i][j].width, something[i][j].height);
                
            }
            if (i == 2 & j == 1) {
                something[i][j].tile.set(470, 480, something[i][j].width, something[i][j].height);
                
            }
            if (i == 2 & j == 2) {
                something[i][j].tile.set(605, 480, something[i][j].width, something[i][j].height);
               
            }
            
        }
    }
    
}




    

    
        
        

    
 
    
    
    
    
    


