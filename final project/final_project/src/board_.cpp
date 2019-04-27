//
//  board_.cpp
//  final_project
//
//  Created by sahil sashi on 4/27/19.
//

#include "board_.hpp"

board::board() {
    std::vector<std::vector<grid>> temp(3, std::vector<grid> (3));
    
    something = temp;
    
    
    
    
}



void board::drawGrids() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            something[i][j].width = (kBOARD_WIDTH/3 * 0.75);
            something[i][j].height = (kBOARD_HEIGHT/3 * 0.75);
        }
    }
}


void board::setUpBounds() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            if (j == 0)
            something[i][j].upper_x_bound = ;
            something[i][j].upper_y_bound = ;
            something[i][j].lower_x_bound = ;
            something[i][j].lower_y_bound = ;
        }
    }
}


    

