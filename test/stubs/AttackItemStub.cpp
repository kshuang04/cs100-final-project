#include "../stubs/AttackItemStub.hpp"

AttackItemStub::AttackItemStub() : attackPower(0), Item("NULL", "NULL", 1, 1) {}

AttackItemStub::~AttackItemStub() {}

AttackItemStub::AttackItemStub(int newAttackPower, int levelType, string name, int rarity, string description) : attackPower(newAttackPower)
{
    this->itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
    this->description = description;
}

int AttackItemStub::getAttackPower() {
    return this->attackPower;
}

string AttackItemStub::getItemName() {
    return this->itemName;
}

string AttackItemStub::getDescription() {
    return this->description;
}

// void AttackItemStub::printStat() {
//     if (this->getAttackPower() < 0) {throw logic_error("The Attack Power is negative and invalid.");}
//     cout << "Item: " << this->getItemName() << "\n  Attack Power: " << this->getAttackPower() << "\n  Description: " << this->getDescription() << endl;
// }

void AttackItemStub::useItem(Player* player) {
    player->setAttackStat(player->getAttackStat() + this->getAttackPower());
}