#pragma once

#include "ofMain.h"
#include "player_.hpp"

class ofApp : public ofBaseApp{

private:
    enum GameState {
        
        ENTRY_SCREEN = 0,
        GAME_ON,
        RESET_GRID,
        GAME_END,
        HOLD_GAME,
    };
    
    //vector to store the values from the grid
    //vector<grid> tic_tac_toe_grid();
    
    
    //buttons for entry screen
    ofRectangle start_game;
    float BUTTON_WIDTH = 10;
    float BUTTON_LENGTH = 20;
    bool start_pressed;
    
    
    
    std::string message_for_start_button;
    
    //taking input from the user for names of the players
    std::string first_player_Name;
    std::string second_player_name;
    
    
    //SOUND files
    std::string ksound_played_when_player_plays = "/Users/sahil_21/Desktop/battle_theme.mp3";
    std::string kwinning_music = "/Users/sahil_21/Desktop/battle_winner.mp3";
    std::string kmusic_when_draw = "/Users/sahil_21/Desktop/In_game_theme.mp3";
    
    
    
    
    std::string ktext_for_start = "Start Game";
    
    
    
    
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
    
    void createRectangles();
    
    int count_for_num_of_draws;
    
    bool start_game_pressed = false;
    
    ofMessage winning_message();
    
    bool did_player_win;
    
    bool player_won;
    
    
    
    
    
    ofRectangle first_bar;
    int width = 5;
    int length = 20;
    
    
    
    
    
    
		
};
