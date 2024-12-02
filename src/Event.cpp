#include "../header/Event.hpp"
#include <iostream>

MiniGame::MiniGame(const std::string& gameName) : name(gameName), rewardChest(nullptr) {}

MiniGame::~MiniGame() {
    delete rewardChest; // only need to delete the chest
}

std::string MiniGame::getName() const {
    return name;
}


void MiniGame::generateReward() {
    // generate random amount of gold
    GenerateItems ItemGenerated;


    int goldAmount = rand() % 100 + 1;
    std::vector<Item*> items = ItemGenerated.generateItem();

    rewardChest = new Chest(10, items, goldAmount);
}