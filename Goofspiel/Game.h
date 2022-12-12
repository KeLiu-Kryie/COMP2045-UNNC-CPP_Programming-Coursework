/**
 * @File Game.h
 * @Brief A class with the game structure and process.
 *
 * @Author Ke Liu(20217275)
 * @Email ssykl3@nottingham.edu.cn
 * @Date 2022/4/8
 */

#ifndef GOOFSPIEL_GAME_H
#define GOOFSPIEL_GAME_H

#include "Prizes.h"
#include "ManualPlayer.h"
#include "ComputerPlayer.h"

/**
 * This class contains the game structure and process with two functions, one is to start the game,
 * and the other is show the result of the game.
 */
class Game {
public:
    void Start();
    const void Result(const int computer_score, const int manual_score);

private:
    Prizes* prizes = new Prizes();                                  // Create a Prizes class.
    ManualPlayer* manual_player = new ManualPlayer();               // Create a ManualPlayer class.
    ComputerPlayer* computer_player = new ComputerPlayer();         // Create a ComputerPlayer class.
};

#endif //GOOFSPIEL_GAME_H
