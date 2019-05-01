//
//  grid.cpp
//  final_project
//
//  Created by sahil sashi on 4/19/19.
//

#include "grid.hpp"
#include "ofMain.h"

grid::grid() {
    
}

grid::grid(float x, float y) {
    this->x = x;
    this->y = y;
    
    value = VAL_EMPTY;
}

void grid::updateGrid(int c) {
    value = c;
}

bool grid::checkIfInsideGrid(int x, int y) {
    if (x > upper_x_bound & x < lower_x_bound || y > upper_y_bound & y < lower_y_bound) {
        return false;
    }
    
    return true;
    
}

char grid::drawField() {
    
    float offset = 20;
    
    //    ofFill();
    //    ofSetColor(200, 200, 200); //fill color gray
//    
//    ofNoFill(); //stroke
//    ofSetColor(0, 0, 0);//stroke color BLACK
//    ofSetLineWidth(2);
    
    
    switch (value) {
        case -1: //update to empty
            // do nothing
            break;
        case 0: // update to O
            return  'O';
            break;
        case 1: //update to X
            return 'X';
            break;
    }
}



