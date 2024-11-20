#ifndef HEALTH_ITEM_STUB_HPP
#define HEALTH_ITEM_STUB_HPP

#include "../../header/Item.hpp"

class Player;

class HealthItemStub : public Item {
    int healthPower;
public:
    HealthItemStub();
    ~HealthItemStub();
    HealthItemStub(string newItemName, int newDefensePower, string newDescription);
    int getHealthPower();
    virtual string getItemName() = 0;
    virtual string getDescription() = 0;
    virtual void printStat() = 0;
    virtual void useItem(Player* player) = 0;
};

#endif
