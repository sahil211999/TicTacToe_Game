//
//  compute_the_winner.cpp
//  final_project
//
//  Created by sahil sashi on 4/19/19.
//

#include <string>
using namespace std;

class computeWinner {
public:
    bool static CheckForHoriWinner(char ch, string input_string ) {
        for (int i = 0; i < input_string.size(); i+=3) {
            if ((input_string[i] == ch) && (input_string[i + 1] == ch) &&(input_string[i + 2] == ch)) {
                return true ;
            }
        }
        return false;
    }
public:
    bool static CheckForVertiWinner(char ch, string input_string) {
        for (int i = 0; i <= 3; i++) {
            if ((input_string[i] == ch) && (input_string[i + 3] == ch) &&(input_string[i + 6] == ch)) {
                return true ;
            }
        }
        return false;
    }
public:
    bool static CheckForDiagWinner(char ch, string input_string) {
        for (int i = 0; i <= 2; i=+2) {
            if ((input_string[i] == ch) && (input_string[i + 4] == ch) &&(input_string[i + 4] == ch)) {
                return true ;
            }
        }
        return false;
    }
};
