/**
 * @File Prizes.h
 * @Brief: Specific implementations of functions of class Prizes are in this file.
 *
 * @Author Ke Liu(20217275)
 * @Email ssykl3@nottingham.edu.cn
 * @Date 2022/4/8
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "Prizes.h"
using namespace std;

/**
 * Constructor of class Prizes.
 * Initialize the prizes.
 * Set the prizes is from A to K and shuffle.
 */
Prizes::Prizes()
    :hand({ {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}}){
    srand(time(NULL));
    random_shuffle(hand.begin(),hand.end());

}

/**
 * Destructor of class Prizes.
 * Do nothing.
 */
Prizes::~Prizes() {}

/**
 * This function returns the prize of this round.
 *
 * @param hand          vector<string> type, the remaining prizes.
 * @return              string type, the top card.
 */
const string Prizes::top(const vector<string> hand) {
    return hand[0];
}

/**
 * Get the prizes.
 *
 * @return              vector<string> type, the prizes.
 */
const vector<string> Prizes::get_hand (){
    return this->hand;
}

/**
 * Remove the discarded prize.
 *
 * @param hand          vector<string> type, the prizes.
 */
void Prizes::set_hand(vector<string> hand) {
    hand.erase(hand.begin());
    this->hand = hand;
}
