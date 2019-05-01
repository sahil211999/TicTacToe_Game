//
//  Tests.cpp
//  final_projectv2
//
//  Created by sahil sashi on 5/1/19.
//


#include <stdio.h>
#include "catch.hpp"
#include "board_.hpp"

TEST_CASE("test to check the winner") {
    board Testboard;
    REQUIRE(Testboard.checkForHorizontalWinner('X', "XXX...OOO"));
}


