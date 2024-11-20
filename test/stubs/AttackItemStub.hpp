#ifndef ATTACK_ITEM_STUB_HPP
#define ATTACK_ITEM_STUB_HPP

#include "../../header/Item.hpp"

class Player;

class AttackItemStub : public Item {
    int attackPower;
public:
    Player* player;
    AttackItemStub();
    ~AttackItemStub();
    AttackItemStub(int newAttackPower, int levelType, string name, int rarity, string description);
    int getAttackPower();
    string getItemName() override;
    string getDescription() override;
    void printStat() override;
    void useItem(Player* player) override;
};

#endif