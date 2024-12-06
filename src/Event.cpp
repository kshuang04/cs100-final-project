#include "../header/Event.hpp"
#include <iostream>

//constructor
MiniGame::MiniGame(const std::string& gameName) : name(gameName), rewardChest(nullptr) {}

//destructor
MiniGame::~MiniGame() {
    delete rewardChest; // only need to delete the chest
}

//get the name of the game
std::string MiniGame::getName() const {
    return name;
}

// generate the reward : item + gold
// basically what it does is creating a chest pointed by rewardChest
void MiniGame::generateReward() {

    rewardChest = new Chest(10);
    // fill the chest with random item and gold  <-- newly updated function in Chest.cpp
    // no need to fill if called Chest(10) then it is auto load. 
    // if called Chest bala, it need to fill chest
    
}