//
//  grid.cpp
//  final_project
//
//  Created by sahil sashi on 4/19/19.
//

#include "grid.hpp"

bool grid::checkIfPlayerPlayedOutOfTurn() {
    if (currentPlayer.serial == 1 && chartype == 'x') {
        return false;
    }
    return true;
}
