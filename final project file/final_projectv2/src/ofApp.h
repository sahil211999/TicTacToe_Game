#pragma once

#include "ofMain.h"
#include "player_.hpp"
#include "ofxBox2d.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

private:
    enum GameState {
        
        ENTRY_SCREEN = 0,
        GAME_ON,
    };
    
    //buttons for entry screen
    ofRectangle start_game;
    float BUTTON_LENGTH_START = 200;
    bool start_pressed = false;
    
    
    
    
    std::string message_for_start_button;
    
    //taking input from the user for names of the players
    std::string first_player_Name;
    std::string second_player_name;

    
    std::string ktext_for_start = "START GAME";
    
    
    
    
public:
    
    void setup();
    void update();
    void draw();
    void setUpinitialScreen();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //method to draw the X's and O's on screen.
    void drawXandO();
    
    //method to set up the initial screen with the start button.
    void setUpInitialScreen();
    
    //method  to set up the game.
    void setUpGame();
    
    //method to take the name of the players from the user.
    void takeUserInput();
    
    //method to draw the game screen.
    void drawGameScreen();
    
    //font for intro screen.
    ofTrueTypeFont game_font;
    
    //music  to be played in background on intro screen.
    ofSoundPlayer intro_sequence;
    
    //ofxButton startButton;
    ofTrueTypeFont start_game_f;
    
    //image for the grid.
    ofImage grid;
    
    //image for the X.
    ofImage image_for_x;
    
    //image for the O.
    ofImage image_for_O;
    
    //to determine the current state of the game
    GameState currentState = ENTRY_SCREEN;
    
    //counter to switch turns
    int m = - 1;
    
    //method to create rectangles to store the  values.
    void createRectangles();
    
    //boolean  to trigger when button is clicked.
    bool start_game_pressed = false;
    
    //boolean to trigger when a player wins.
    bool did_player_win;
    
    //boolean to trigger when a player has won and message has been displayed.
    bool player_won;
    
    ofxBox2d                               box2d;   // the box2d world
    vector   <shared_ptr<ofxBox2dCircle> > circles; // default box2d circles
    vector   <shared_ptr<ofxBox2dRect> >   boxes;   // defalut box2d rects
    
    //method called to reset the board.
    void clearBoard();
    
    //check for winner
    void checkForWinner();
    
    //panel for volume rocked
    ofxPanel gui;
    ofxFloatSlider volume;
    
    //method draw circles and cross's.
    void createOsandXs();
    
    
    
    
    
    
    
		
};
