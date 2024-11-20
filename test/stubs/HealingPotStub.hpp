#ifndef HEALING_POT_STUB_HPP
#define HEALING_POT_STUB_HPP

#include <algorithm>

#include "../stubs/HealthItemStub.hpp"

class Player;

class HealingPotStub : public HealthItemStub {
    int HPPower;
public:
    HealingPotStub();
    ~HealingPotStub();
    HealingPotStub(string newItemName, int newHPPower, string newDescription);
    int getHPPower();
    string getItemName() override;
    string getDescription() override;
    void printStat() override;
    void useItem(Player* player) override;
};

#endif