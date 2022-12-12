/**
 * @File Prizes.h
 * @Brief: A Prizes class that used to stores information of the prizes.
 *
 * @Author Ke Liu(20217275)
 * @Email ssykl3@nottingham.edu.cn
 * @Date 2022/4/8
 */
#ifndef GOOFSPIEL_PRIZES_H
#define GOOFSPIEL_PRIZES_H
#include <string>
#include <vector>

using namespace std;

/**
 * This class is used to stand for prizes. This contains basic elements of the prizes like the hand and
 * some functions like show the top card and so forth.
 *
 * @param hand          vector<string>type, private field, records of the cards in prizes.
 */
class Prizes {
public:
    Prizes();                                               // Constructor of class Prizes.
    ~Prizes();                                              // Destructor of class Prizes.
    const string top(const vector<string> hand);            // Return the top card of the prize.
    void set_hand(vector<string> hand);                     // Set the hand of the prize.
    const vector<string> get_hand ();                       // Get the hand of the prize.


private:
    vector<string> hand;
};

#endif //GOOFSPIEL_PRIZES_H
