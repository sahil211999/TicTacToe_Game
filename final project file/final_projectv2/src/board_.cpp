//
//  board_.cpp
//  final_project
//
//  Created by sahil sashi on 4/27/19.
//

#include "board_.hpp"

board::board() {
    std::vector<std::vector<grid>> temp(number_of_rows_colums, std::vector<grid> (number_of_rows_colums));
    
    board_matrix = temp;
}



void board::drawGrids() {
    for (int i = 0; i < number_of_rows_colums; i++) {
        for (int j = 0; j < number_of_rows_colums; j++) {
            board_matrix[i][j].width = (kBOARD_WIDTH/3 * 0.75);
            board_matrix[i][j].height = (kBOARD_HEIGHT/3 * 0.75);
        }
    }
}


void board::setUpBounds() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board_matrix[i][j].upper_x_bound = kBOARD_ZERO_x + (board_matrix[i][j].width * (j + 1));
            board_matrix[i][j].upper_y_bound = kBOARD_ZERO_Y + (board_matrix[i][j].height * (i + 1));
            board_matrix[i][j].lower_x_bound = kBOARD_ZERO_x + (board_matrix[i][j].width * j);
            board_matrix[i][j].lower_y_bound = kBOARD_ZERO_Y + (board_matrix[i][j].height * j);
        }
    }
}

void board::mouseReleased(int mouse_x, int mouse_y, Player currentplayer) {
    for (int i = 0; i < number_of_rows_colums; i++) {
        for (int j = 0; j < number_of_rows_colums; j++) {
                if (board_matrix[i][j].tile.inside(mouse_x, mouse_y)) {
                    std::cout<<"grid is updateted"<<endl;
                    k++;
                    std::cout<<"CURRENT PLAYER"<<endl;
                    std::cout<<currentplayer.serial<<endl;
                    
                    if (currentplayer.serial == 0) {
                        board_matrix[i][j].updateGrid(0);
                    }
                    
                    if (currentplayer.serial == 2) {
                        board_matrix[i][j].updateGrid(1);
                    }
                        
                }
            
           }
        }
}


bool board::checkForHorizontalWinner(char ch, string input_string ) {
    if ( (input_string[0] == ch && input_string[1] == ch && input_string[2] == ch)
        || (input_string[2] == ch && input_string[3] == ch && input_string[4] == ch)
        || (input_string[5] == ch && input_string[6] == ch && input_string[7] == ch)) {
        return true;
    }
    return false;
}

bool  board::checkForVerticalWinner(char ch, string input_string) {
    if ( (input_string[0] == ch && input_string[3] == ch && input_string[6] == ch)
        || (input_string[1] == ch && input_string[4] == ch && input_string[7] == ch)
        || (input_string[2] == ch && input_string[5] == ch && input_string[8] == ch)) {
        return true;
    }
    return false;
    
}

bool board::checkForDiagonalWinner(char ch, string input_string) {
    if ( (input_string[0] == ch && input_string[4] == ch && input_string[8] == ch)
        || (input_string[2] == ch && input_string[4] == ch && input_string[6] == ch)) {
        return true;
    }
    return false;
    
}

void board::stringCreation() {
    int o = 0;
    for (int i = 0; i < number_of_rows_colums; i++) {
        for (int j = 0; j < number_of_rows_colums; j++) {
            if (board_matrix[i][j].value == 1) {
                cout<<"control reached here to make it this";
                cout<<endl;
                values_on_board_as_str[o] = 'X';
            }
            else if (board_matrix[i][j].value == 0) {
                values_on_board_as_str[o] = 'O';
            }
            else {
                values_on_board_as_str[o] = '.';
            }
            o++;
        }
    }
}



    








    

