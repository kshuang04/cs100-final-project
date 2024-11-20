#ifndef DEFENSE_ITEM_STUB_HPP
#define DEFENSE_ITEM_STUB_HPP

#include "../header/Item.hpp"

class Player;

class DefenseItemStub : public Item {
    int defensePower;
public:
    DefenseItemStub();
    ~DefenseItemStub();
    DefenseItemStub(string newItemName, int newDefensePower, string newDescription);
    int getDefensePower();
    string getItemName() override;
    string getDescription() override;
    void printStat() override;
    void useItem(Player* player) override;
};

#endif
