/**
 * @File Game.cpp
 * @Brief Specific implementations of functions of class Game are in this file.
 *
 * @Author Ke Liu(20217275)
 * @Email ssykl3@nottingham.edu.cn
 * @Date 2022/4/8
 */

#include <iostream>
#include "Game.h"
#include "Prizes.h"

using namespace std;

/**
 * This function is the process of the game. The game consists of 13 rounds. In a round, both players should
 * bid for the prize and the bigger bidding could get the prize. When a round finished, the score board
 * will show the latest scores of both players. When the 13th round finished, it will claim the winner of the game.
 */
void Game::Start() {
    int manual_price, computer_price,prize_price, difference = 0, logical_round = 0;
    const int total_rounds = 13;
    cout << "----------Goofspiel Game----------" << endl;
    for(int i=0; i < total_rounds; i++){                            // 13 rounds game in total.
        cout <<  endl << "----------The No." << i+1 <<" round----------" << endl;
        prize_price = manual_player->TurnValue(prizes->top(prizes->get_hand()));
        cout <<"The prize is " << prizes->top(prizes->get_hand()) <<endl;

        // Computer and human player bid.
        computer_price = computer_player->Bid(computer_player->get_hand(), prizes->top(prizes->get_hand()),
                                              manual_player->get_max(manual_player->get_hand()), manual_player->get_habit() );
        manual_price = manual_player->Bid(manual_player->get_hand());

        // Get the habit of human player of picking card.
        difference = manual_price - prize_price;
        if((-4<=difference) && (difference<=4)){
            logical_round++;
        }
        manual_player->set_habit(difference,logical_round);

        // Compare which player's bidding is larger.
        if(manual_price > computer_price){
            manual_player->set_score(manual_player->TurnValue(prizes->top(prizes->get_hand())));
        }
        else if(manual_price < computer_price){
            computer_player->set_score(computer_player->TurnValue(prizes->top(prizes->get_hand())));
        }
        else{
            manual_player->set_score(manual_player->TurnValue(prizes->top(prizes->get_hand()))/2);
            computer_player->set_score(computer_player->TurnValue(prizes->top(prizes->get_hand()))/2);
        }

        // Deal with the prize and show scores of both players.
        prizes->set_hand(prizes->get_hand());
        cout << "The PC played " << computer_player->get_pick() << ". And you played " << manual_player->get_pick() << "." << endl << endl;
        cout << "The PC'score is " << computer_player->get_score() << " now." << endl << "Your score is " << manual_player->get_score() << " now.";

    }

    // Show the result and who is the winner.
    Result(computer_player->get_score(),manual_player->get_score());

    // Release the memory.
    delete prizes;
    delete manual_player;
    delete computer_player;
}

/**
 * This function shows the result of the game. Specifically, show the final scores of both players and have a comparison
 * and claim that who is the winner.
 *
 * @param computer_score        int type, the final score of computer player.
 * @param manual_score          int type, the final score of manual player.
 */
const void Game::Result(const int computer_score, const int manual_score) {
    cout << endl << "----------Result----------" << endl << endl << "Final score: " << computer_score << " for PC and " << manual_score << " for you." <<endl;
    if(manual_score > computer_score){
        cout << "You win! Congratulations!"<<endl;
    }
    else if(manual_score < computer_score){
        cout << "You lose. Try next time."<<endl;
    }
    else{
        cout << "A close match. It's a tie." <<endl;
    }
    cout << endl << "----------Game over----------" <<endl;
}

