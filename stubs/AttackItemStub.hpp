#ifndef ATTACK_ITEM_STUB_HPP
#define ATTACK_ITEM_STUB_HPP

#include "../header/Item.hpp"

class AttackItemStub : public Item {
    int attackPower;
public:
    AttackItemStub();  // Default constructor
    ~AttackItemStub();  // Destructor
    AttackItemStub(string newItemName, int newAttackPower, string newDescription);
    int getAttackPower();  // Getter function for attack power
    string getItemName() override;  // Override for item name
    string getDescription() override;  // Override for description
    void printStat() override;  // Override for printStat
};

#endif // ATTACK_ITEM_STUB_HPP
