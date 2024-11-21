#ifndef MAX_HP_POT_STUB_HPP
#define MAX_HP_POT_STUB_HPP

#include "../stubs/HealthItemStub.hpp"

class MaxHPPotStub : public HealthItemStub {
    int maxHPPower;
public:
    MaxHPPotStub();
    ~MaxHPPotStub();
    MaxHPPotStub(int healthIncrease, int levelType, string name, int rarity, string description);
    int getMaxHPPower();
    string getItemName() override;
    string getDescription() override;
    void printStat() override;
    void useItem(Player* player) override;
};

#endif