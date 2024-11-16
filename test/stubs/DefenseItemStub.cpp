#include "../../test/stubs/DefenseItemStub.hpp"

DefenseItemStub::DefenseItemStub() : defensePower(0), Item("NULL", "NULL") {}

DefenseItemStub::~DefenseItemStub() {}

DefenseItemStub::DefenseItemStub(string newItemName, int newDefensePower, string newDescription)
    : defensePower(newDefensePower), Item(newItemName, newDescription) {}

int DefenseItemStub::getDefensePower() {
    return this->defensePower;
}

string DefenseItemStub::getItemName() {
    return this->itemName;
}

string DefenseItemStub::getDescription() {
    return this->description;
}

void DefenseItemStub::printStat() {
    if (this->getDefensePower() < 0) {throw logic_error("The Defense Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Defense Power: " << this->getDefensePower() << "\n  Description: " << this->getDescription() << endl;
}

void DefenseItemStub::useItem(Player* player) {
    player->setDefenseStat(player->getDefenseStat() + this->getDefensePower());
}