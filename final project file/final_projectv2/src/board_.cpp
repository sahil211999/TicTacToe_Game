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
            something[i][j].upper_x_bound = kBOARD_ZERO_x + (something[i][j].width * (j + 1));
            something[i][j].upper_y_bound = kBOARD_ZERO_Y + (something[i][j].height * (i + 1));
            something[i][j].lower_x_bound = kBOARD_ZERO_x + (something[i][j].width * j);
            something[i][j].lower_y_bound = kBOARD_ZERO_Y + (something[i][j].height * j);
        }
    }
}

void board::mouseReleased(int mouse_x, int mouse_y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
                if (something[i][j].tile.inside(mouse_x, mouse_y)) {
                    std::cout<<"grid is updateted"<<endl;
                    k++;
                    std::cout<< k <<endl;
                    something[i][j].updateGrid(1);
                }
            
           }
        }
}
    








    

