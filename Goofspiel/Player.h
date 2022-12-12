/**
 * @File Player.h
 * @Brief: A base player class is defined in this file.
 *
 * @Author Ke Liu(20217275)
 * @Email ssykl3@nottingham.edu.cn
 * @Date 2022/4/8
 */
#ifndef GOOFSPIEL_PLAYER_H
#define GOOFSPIEL_PLAYER_H
#include <vector>
#include <string>

using namespace std;

/**
 * This class is used to as a base class for computer player and human player, which contains some basic elements
 * of a player like hand,pick and score and some functions like add score and get the pick.
 *
 * @param max       int type, private field, the max card of a hand.
 * @param score     int type, private field, the total scores of players.
 * @param pick      string type, private field, the card picked in a round.
 * @param hand      vector<string> type, private field, records of the hand of players.
 */
class Player{
public:
    Player();                                       // Constructor of class Player.
    ~Player();                                      // Destructor of class Player.
    const float TurnValue(const string pick);       // Turn the string to int number.
    int get_max(const vector<string> hand);         // Get the max value of a hand.
    void set_score(const float price);              // Add scores to players.
    const float get_score();                        // Get the scores.
    void set_pick(const string pick);               // Set what the player to pick.
    const string get_pick();                        // Get what a player picked to play.
    void set_hand(const vector<string> hand);       // Set the hand of a player.
    const vector<string> get_hand ();               // Get the hand of a player.

private:
    int max;
    float score;
    string pick;
    vector<string> hand;
};

#endif //GOOFSPIEL_PLAYER_H
