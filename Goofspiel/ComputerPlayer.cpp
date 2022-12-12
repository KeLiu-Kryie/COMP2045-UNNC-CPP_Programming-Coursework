/**
 * @File ComputerPlayer.cpp
 * @Brief Specific implementations of functions of class ComputerPlayer are in this file.
 *
 * @Author Ke Liu(20217275)
 * @Email ssykl3@nottingham.edu.cn
 * @Date 2022/4/8
 */

#include "ComputerPlayer.h"
#include "Prizes.h"
#include <cmath>

using namespace std;

/**
 * Constructor of class ComputerPlayer.
 */
ComputerPlayer::ComputerPlayer() {}

/**
 * Destructor of class ComputerPlayer.
 * Do nothing.
 */
ComputerPlayer::~ComputerPlayer() {}

/**------------------------------------------------------------------------------------------------------------------------------------
 * It is the whole process of bid for the computer player. The strategy of the computer can be summarized as hybrid strategy
 * consists of learning algorithm and semi-deterministic algorithm. In the first round and sometimes when the algorithm can't
 * predict the opponent's choice the computer player will use semi-deterministic algorithm.
 * ------------------------------------------------------------------------------------------------------------------------------------
 * The logic of the semi-deterministic for computer player is:
 * 1.1 If the prize is 10 J Q K and the max of computer's is smaller than human's, then computer will pick the minimum card.(if not 1.1, go 1.2)
 * 1.2 If the prize is 9 10 J Q K and the max of computer's is larger than human's, then the computer will pick the smallest card that bigger
 * than the human's max.(if not 1.2, go 2.1)
 * 2.1 If the prize is less than 4, it always picks the minimum card. (if not 2.1, go 2.2)
 * 2.2 If the prize is bigger than 4, it picks the card with 2 bigger than the prize, if this card doesn't exist,
 * then picks the card with 1 bigger than the prize, if this card doesn't exist either, then it picks the card with the same
 * value, if this card still doesn't exist, then picks the minimum card.
 * ------------------------------------------------------------------------------------------------------------------------------------
 * After a several rounds of play, the program has a sufficient observation and try to predict what will the human pick at the next round.
 * And the computer will pick the smallest card that bigger than the prediction. The prediction is according to observation of the habit
 * of the human's picking by comparison with the prize card. The learning algorithm is:
 * 1.1 If the prize is 10 J Q K and the max of computer's is smaller than human's, then computer will pick the minimum card.(if not 1.1, go 1.2)
 * 1.2 If the prize is 9 10 J Q K and the max of computer's is larger than human's, then the computer will pick the smallest card that bigger
 * than the human's max.(if not 1.2, go 2.1)
 * 2.1 If the prize is less than 4, it always picks the minimum card. (if not 2.1, go 2.2)
 * 2.2 Computer will pick the smallest card that bigger than the prediction.
 *
 *
 * @param hand          vector<string> type, the hand of the computer player now.
 * @param pick          string type, the prize card of the round.
 * @param max           int type, the maximum card of the manual player.
 * @param habit         float type, the average difference between human's pick and the prize card.
 *
 * @return              int type, the value of the card that the computer player played.
 */


int ComputerPlayer::Bid(vector<string>hand, string pick, int max, float habit) {
    int value;
    // If the prize is 10 J Q K and the max of computer is smaller than human's, then computer will pick the minimum card.
    if ((get_max(hand) < max) && (TurnValue(pick) > 9)) {
        value = TurnValue(hand[0]);
        ChooseCertain(hand, 0);
        return value;
    }

    /**
     * If the prize is 9 10 J Q K and the computer has several cards bigger than the max of human, then the computer will pick the smallest
     * card from the cards that are larger than the max of human.
     */
    if ((get_max(hand) > max) && (TurnValue(pick) > 8)) {
        for (int i = 0; i < hand.size(); i++) {
            if (i == hand.size() - 1) {
                value = TurnValue(hand[i]);
                ChooseCertain(hand, i);
                return value;
            }
            if (((TurnValue(hand[i])) <= max) && ((TurnValue(hand[i + 1])) > max)) {
                value = TurnValue(hand[i + 1]);
                ChooseCertain(hand, i + 1);
                return value;
            }
        }
    }

    // If the prize is less than 4, it always picks the minimum card.
    if (pick.compare("A") == 0 || pick.compare("2") == 0 || pick.compare("3") == 0) {
        value = TurnValue(hand[0]);
        ChooseCertain(hand, 0);
        return value;
    }
    /**
     * If the average habit of human is to pick the card bigger within 4 than the prize card, then the computer will
     * make a prediction and pick a card bigger than the prediction with the least price. Other times, the computer will
     * think the human is playing randomly.
     */
    if((0 < habit) && (habit<= 4)){
        for (int i = 0; i < hand.size(); i++) {
            if (i == hand.size() - 1) {
            // If computer's max is less than the predication, then pick the smallest card. Otherwise pick the max.
                if ((TurnValue(hand[i])) < ((int) (TurnValue(pick)) + ceil (habit))) {
                    if(get_max(hand) == max){
                        value = TurnValue(hand[i]);
                        ChooseCertain(hand, i);
                    }
                    else{
                        value = TurnValue(hand[0]);
                        ChooseCertain(hand, 0);
                    }
                } else {
                    value = TurnValue(hand[i]);
                    ChooseCertain(hand, i);
                }
                return value;
            }
            // Pick a card bigger than the prediction with the least price
            if (((TurnValue(hand[i])) <= ((int) (TurnValue(pick)) + ceil (habit))) &&
                ((TurnValue(hand[i + 1])) > ((int) (TurnValue(pick)) + ceil (habit)))) {
                value = TurnValue(hand[i + 1]);
                ChooseCertain(hand, i + 1);
                return value;
            }
        }
        return 0;
    }
    else{
        /**
         * If the programme thinks the human player is picking randomly. It will pick in this logic:
         * It picks the card with 2 bigger than the prize, if this card doesn't exist,
         * then picks the card with 1 bigger than the prize, if this card doesn't exist either, then it picks the card with the same
         * value, if this card still doesn't exist, then pick the minimum card.
         */
        for(int k = 0; k < hand.size(); k++){
            if((TurnValue(hand[k]) == TurnValue(pick) + 2)){        // Search for +2 value card.
                value = TurnValue(hand[k]);
                ChooseCertain(hand,k);
                return value;
            }
        }
        for(int k = 0; k < hand.size(); k++){
            if((TurnValue(hand[k]) == TurnValue(pick) + 1)){        // Search for +1 value card.
                value = TurnValue(hand[k]);
                ChooseCertain(hand,k);
                return value;
            }
        }
        for(int k = 0; k < hand.size(); k++){
            if((TurnValue(hand[k]) == TurnValue(pick))){            // Search for the same value card.
                value = TurnValue(hand[k]);
                ChooseCertain(hand,k);
                return value;
            }
        }
        value = TurnValue(hand[hand.size() - 1]);                   // If all failed before, then pick the minimum card
        ChooseCertain(hand,hand.size()-1);
        return value;
    }
}

/**
 * It is the process of dealing with the hand after choosing the card.
 *
 * @param hand          vector<string> type, the hand of the computer player now.
 * @param k             int type, 0,1,2 stands for different search pattern.
 */
const void ComputerPlayer::ChooseCertain(vector<string> hand, int k){
    set_pick(hand[k]);
    hand.erase(hand.begin() + k);
    set_hand(hand);
}
