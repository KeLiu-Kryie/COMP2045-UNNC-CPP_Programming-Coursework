/**
 * @File ManualPlayer.h
 * @Brief A derived class ManualPlayer that inherits from base class Player.
 *
 * @Author Ke Liu(20217275)
 * @Email ssykl3@nottingham.edu.cn
 * @Date 2022/4/8
 */
#ifndef GOOFSPIEL_MANUALPLAYER_H
#define GOOFSPIEL_MANUALPLAYER_H
#include "Player.h"

/**
 * This class is a derived class as manual player that inherits from the class Player,
 * which contains the additional function bid that used for the selection of card to play.
 */
class ManualPlayer : public Player {
public:
    ManualPlayer();                                     // Constructor of class ManualPlayer.
    ~ManualPlayer();                                    // Destructor of class ManualPlayer.
    int Bid(vector<string> hand);                       // Bid of manual player in a round.
    void set_habit(int difference, int logical_round);  // Set the habit of picking cards of human player.
    float get_habit();                                  // Get the habit of picking cards of human player.
private:
    float habit;
};

#endif //GOOFSPIEL_MANUALPLAYER_H
