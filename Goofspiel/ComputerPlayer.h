/**
 * @File ComputerPlayer.h
 * @Brief A derived class ComputerPlayer that inherits from base class Player.
 *
 * @Author Ke Liu(20217275)
 * @Email ssykl3@nottingham.edu.cn
 * @Date 2022/4/8
 */
#ifndef GOOFSPIEL_COMPUTERPLAYER_H
#define GOOFSPIEL_COMPUTERPLAYER_H
#include "Player.h"

/**
 * This class is a derived class as computer player that inherits from the class Player,
 * which contains the additional function bid that used for the selection of card to play.
 */
class ComputerPlayer : public Player {
public:
    ComputerPlayer();                                                   // Constructor of class ComputerPlayer.
    ~ComputerPlayer();                                                  // Destructor of class ComputerPlayer.
    int Bid(vector<string> hand, string pick, int max, float habit);    // Bid of computer player in a round.
    const void ChooseCertain(vector<string> hand, int k);               // Choose a card then deal with the hand.
};

#endif //GOOFSPIEL_COMPUTERPLAYER_H
