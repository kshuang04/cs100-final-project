#include "../../test/stubs/HealingPotStub.hpp"

HealingPotStub::HealingPotStub() : HealthItemStub("NULL", 0, "NULL") {}

HealingPotStub::~HealingPotStub() {}

HealingPotStub::HealingPotStub(string newItemName, int newHPPower, string newDescription)
    : HPPower(newHPPower), HealthItemStub(newItemName, newHPPower, newDescription) {}

int HealingPotStub::getHPPower() {
    return this->HPPower;
}

string HealingPotStub::getItemName() {
    return this->itemName;
}

string HealingPotStub::getDescription() {
    return this->description;
}

void HealingPotStub::printStat() {
    if (this->getHPPower() < 0) {throw logic_error("The HP Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Heals " << this->getHPPower() << " HP\n  Description: " << this->getDescription() << endl;
}

void HealingPotStub::useItem(Player* player) {
    player->setHP(min((player->getHP() + this->getHPPower()), player->getMaxHPFromLevel()));
}