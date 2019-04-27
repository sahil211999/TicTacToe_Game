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
    if (x > upper_x_bound & x < lower_x_bound) {
        return false;
    }
    if (y > upper_y_bound & y < lower_y_bound) {
        return false;
    }
    return true;

}



