/**
 * @File ManualPlayer.cpp
 * @Brief Specific implementations of functions of class ManualPlayer are in this file.
 *
 * @Author Ke Liu(20217275)
 * @Email ssykl3@nottingham.edu.cn
 * @Date 2022/4/8
 */

#include <iostream>
#include "ManualPlayer.h"

using namespace std;

/**
* Constructor of class ManualPlayer.
*/
ManualPlayer::ManualPlayer()
    :habit(0.0)
{}

/**
* Destructor of class ManualPlayer.
* Do nothing.
*/
ManualPlayer::~ManualPlayer(){}

/**
 * It is the whole process of bid for the manual player. It shows what the manual player has first.
 * Then it will keep asking the player to choose a card until the manual player choose a valid card for bid.
 *
 * @param hand          vector<string> type, the hand of the manual player now.
 * @return              int type, the value of the card that the manual player played.
 */
int ManualPlayer::Bid(vector<string> hand) {
    string input;
    cout << "Now your hand: ";
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i] << " ";
    }
    cout << endl;
    cout << "Please select a card from your hand as your bidding:";
    cin >> input;
    set_pick(input);
    while (true) {                                                    // Invalid input and played card are not accepted
        for (int i = 0; i < hand.size(); i++) {
            if (get_pick().compare(hand[i]) == 0) {               // Valid card is selected and remove it out of the hand
                hand.erase(hand.begin() + i);
                set_hand(hand);
                int value = TurnValue(get_pick());
                return value;
            }
        }
        cout << "Invalid input. Please input again:";
        cin >> input;
        set_pick(input);
    }
}

/**
 * Calculate the average human's habit of picking cards.
 *
 * @param difference         int type, the difference between the prize and the card picked by the human player.
 * @param logical_round      int type, the total rounds that have valid differences.
 */
void ManualPlayer::set_habit(int difference, int logical_round ) {
    if((-3 <= difference)&& (difference <= 3)){
        this->habit = (this->habit * (logical_round -1) + difference)/logical_round;
    }

/**
 * Get the average human's habit of picking cards.
 *
 * @return             float type, the average difference of the human's picking and the prizes.
 */
}
float ManualPlayer::get_habit() {
    return this->habit;
}

