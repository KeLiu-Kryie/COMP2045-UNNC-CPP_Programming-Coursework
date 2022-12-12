/**
 * @File Player.cpp
 * @Brief: Specific implementations of functions of class Player are in this file.
 *
 * @Author Ke Liu(20217275)
 * @Email ssykl3@nottingham.edu.cn
 * @Date 2022/4/8
 */
#include "Player.h"

/**
 * Constructor of class Player.
 * Initialize the player.
 * Set the total score to be 0, the max card is K, and a full of hand.
 */
Player::Player()
    : score(0.0),
      pick(""),
      max(13),
      hand({ {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}})
{}

/**
 * Destructor of class Player.
 * Do nothing.
 */
Player::~Player(){}

/**
 * Transfer the card from string type to int type or get the value of the card.
 *
 * @param pick      string type, the chosen card.
 * @return          int type, the value of the chose card.
 */
const float Player::TurnValue(const string pick) {
    int value;
    if(pick.compare("A") == 0){
        value = 1;
    }
    else if(pick.compare("J") == 0){
        value = 11;
    }
    else if(pick.compare("Q") == 0){
        value = 12;
    }
    else if(pick.compare("K") == 0){
        value = 13;
    }
    else{
        value = atoi(pick.c_str());
    }
    return value;
}

/**
 * Get the max value of the card in hand.
 *
 * @param hand      vector<string> type, records the hand of players.
 * @return          int type, the max value of the hand.
 */
 int Player::get_max(const vector<string> hand) {
    if(hand.size() >= 1){
        this->max = TurnValue(hand[hand.size() - 1]);
    }
    else{
        this->max = 0;
    }
    return this->max;
}

/**
 * Add scores to players.
 *
 * @param value     int type, the scores that should be added and the marks equal to the shown prize.
 */
void Player::set_score(const float value) {
    this->score += value;
}

/**
 *
 * Get the total scores of a player.
 *
 * @return          int type, return the total scores.
 */
const float Player::get_score() {
    return this->score;
}

/**
 * Set what the player to pick.
 *
 * @param pick      string type, the card that the player want to pick in the round.
 */
void Player::set_pick(const string pick) {
    this->pick = pick;
}

/**
 * Get the card that the player chose in the round.
 *
 * @return          string type, the card that the player played in the round.
 */
const string Player::get_pick(){
    return this->pick;
}

/**
 * Set the new hand of a player.
 *
 * @param hand      vector<string>type, hand of a player.
 */
void Player::set_hand(const vector<string> hand) {
    this->hand = hand;
}

/**
 * Get the hand of a player.
 *
 * @return          vector<string>type, hand of a player.
 */
const vector<string> Player::get_hand (){
    return this->hand;
}


