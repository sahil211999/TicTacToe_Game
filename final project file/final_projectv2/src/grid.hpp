//
//  grid.hpp
//  final_project
//
//  Created by sahil sashi on 4/19/19.
//

#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>
#include "player_.hpp"
#include "player_.hpp"
#include "ofApp.h"

struct grid {
    grid();
    grid(float, float);
    void drawGrid();
    void updateGrid(int);
    bool checkIfInsideGrid(int x, int y);
    
    // assigning values to marks
    enum Value {
        VAL_EMPTY = -1,
        VAL_O = 0, //capital o, and a zero
        VAL_X = 1
    };
    
    int value = -1;
    
    float x, y;
    
    float height;
    
    float width;
    
    //lower bound x bound of the grid
    int lower_x_bound;
    
    //lower bound x bound of the grid
    int upper_x_bound;
    
    //lower bound x bound of the grid
    int lower_y_bound;
    
    //lower bound x bound of the grid
    int upper_y_bound;
    
    //method to draw the X's and O's as the player clicks on the grid
    char drawField();
    
    //tile to store the value in.
    ofRectangle tile;
    
    
    
    
};

#endif /* grid_hpp */
