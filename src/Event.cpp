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
    GenerateItems ItemGenerated;
    // generate random amount of gold
    int goldAmount = rand() % 100 + 1;
    // generate a vector of items directed copy from item
    std::vector<Item*> items = ItemGenerated.generateItem();

    rewardChest = new Chest(10, items, goldAmount);
}