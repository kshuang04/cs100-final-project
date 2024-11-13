#include "../stubs/AttackItemStub.hpp"

AttackItemStub::AttackItemStub() : attackPower(0), Item("NULL", "NULL") {}

AttackItemStub::~AttackItemStub() {}

AttackItemStub::AttackItemStub(string newItemName, int newAttackPower, string newDescription)
    : attackPower(newAttackPower), Item(newItemName, newDescription) {}

int AttackItemStub::getAttackPower() {
    return this->attackPower;
}

string AttackItemStub::getItemName() {
    return this->itemName;
}

string AttackItemStub::getDescription() {
    return this->description;
}

void AttackItemStub::printStat() {
    if (this->getAttackPower() < 0) {throw logic_error("The Attack Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Attack Power: " << this->getAttackPower() << "\n  Description: " << this->getDescription() << endl;
}

void AttackItemStub::useItem(Player* player) {
    player->setAttackStat(player->getAttackStat() + this->getAttackPower());
}