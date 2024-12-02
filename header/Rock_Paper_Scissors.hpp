#ifndef ROCK_PAPER_SCISSORS_HPP
#define ROCK_PAPER_SCISSORS_HPP

#include "../header/Event.hpp"
using namespace std;

class RockPaperScissors : public MiniGame {
public:
    RockPaperScissors();

    void play(Player* player) override;
    // overwrite play to return success or not
    string choiceToString(string choice);
    string intToString(int num);
    string determineWinner(string user, int comInput);
};

#endif // ROCK_PAPER_SCISSORS_HPP