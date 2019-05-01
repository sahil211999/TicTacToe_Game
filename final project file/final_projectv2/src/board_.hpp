//
//  board_.hpp
//  final_project
//
//  Created by sahil sashi on 4/27/19.
//

#ifndef board__hpp
#define board__hpp
#include "grid.hpp"

#include "player_.hpp"


#include <stdio.h>
#include <vector>

class board {
    
 //default constructor
public:
    board();
   
    //vector to store the from the board
    std::vector<std::vector<grid>> something;
    
    //method to set up the bounds of each grid.
    void setUpBounds();
    
    //method to draw the grids on the board
    void drawGrids();
    
   //constant board width
    float kBOARD_WIDTH = 443;
    
    //constant board height
    float kBOARD_HEIGHT = 440;
    
    //constant for the co-ordinate system on the board
    float kBOARD_ZERO_x = 300;
    
    //constant for the co-ordinate system on the board
    float kBOARD_ZERO_Y = 200;
    
    //method to update field of the value
   void mouseReleased(int mouse_x, int mouse_y, Player currentplayer);
    
    
    //method to create grids
    void createRectangles();
    
    //method to check for horizontal winners.
    bool checkForHorizontalWinner(char ch, string input_string);
    
    //method to check for vertical winners.
    bool checkForVerticalWinner(char ch, string input_string);
    
    //method to check for diagonal winners.
    bool checkForDiagonalWinner(char ch, string input_string);
    
    //method create string reading the board
    void stringCreation();
    
    //string converted from the values in each grid
    string values_on_board_as_str;
    
    
    
    int k = 0;
};


#endif /* board__hpp */
