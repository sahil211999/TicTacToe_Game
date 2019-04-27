//
//  board_.hpp
//  final_project
//
//  Created by sahil sashi on 4/27/19.
//

#ifndef board__hpp
#define board__hpp
#include "grid.hpp"


#include <stdio.h>
#include <vector>

class board {
    
 //default constructor
    board();
   
    //vector to store the from the board
    std::vector<std::vector<grid>> something;
    
    //method to set up the bounds of each grid.
    void setUpBounds();
    
    //method to draw the grids on the board
    void drawGrids();
    
    //board height and width
    
    //constant board width
    float kBOARD_WIDTH = 610;
    
    //constant board height
    float kBOARD_HEIGHT = 248;
    
    
    
    
    
};
//std::vector <grid()> board;

#endif /* board__hpp */
