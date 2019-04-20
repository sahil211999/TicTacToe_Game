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

struct grid {
//Character types of the current 
char chartype;

//Character type allowed in the turn.
char chartype_allowed;

//Player who is playing in the current turn.
Player currentPlayer;

//method to check if the current player inputted wrong value.
bool checkIfPlayerInputIncorrect();

//List of animation methods to be possibly used.
bool checkIfPlayerPlayedOutOfTurn();


};

#endif /* grid_hpp */
