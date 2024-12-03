#ifndef EVENT_HPP
#define EVENT_HPP

#include "../header/chest.hpp"
#include "../header/Player.hpp"
#include <string>
#include <cstdlib>

using namespace std;

class MiniGame {
protected:
    string name; // name of the game
    Chest* rewardChest; // the reward

public:
    MiniGame(const string& gameName); // constructor

    virtual ~MiniGame(); // make it virtual to overwrite

    // logic of the game
    virtual void play(Player* player) = 0;

    // game name
    string getName() const;

    // generate reward
    void generateReward();
};

#endif