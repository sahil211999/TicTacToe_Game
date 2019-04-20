#pragma once


//#inlcude "grid.hpp"
#include "ofMain.h"


class ofApp : public ofBaseApp {
    
    
private:
    enum GameState {
        NOT_STARTED = 0,
        ENTRY_SCREEN,
        RESET_GRID,
        GAME_END,
        HOLD_GAME,
    };
    
    //buttons for entry screen
    ofRectangle start_game;
    float BUTTON_WIDTH = 10;
    float BUTTON_LENGTH = 20;
    
    
    
    std::string message_for_start_button;
    
    //taking input from the user for names of the players
    std::string first_player_Name;
    
    
    
    std::string second_player_name;
    
    
    //SOUND files
    std::string kIntroMusicPath_ = "";
    std::string ksound_played_when_player_plays = "/Users/sahil_21/Desktop/battle_theme.mp3";
    std::string kwinning_music = "/Users/sahil_21/Desktop/battle_winner.mp3";
    std::string kmusic_when_draw = "/Users/sahil_21/Desktop/In_game_theme.mp3";
    
    
    
   
    
    

    
    
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
    
        
    
    
    
    
    
		
};
