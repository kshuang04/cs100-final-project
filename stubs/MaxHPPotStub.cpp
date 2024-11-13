#include "../stubs/MaxHPPotStub.hpp"

MaxHPPotStub::MaxHPPotStub() : HealthItemStub("NULL", 0, "NULL") {}

MaxHPPotStub::~MaxHPPotStub() {}

MaxHPPotStub::MaxHPPotStub(string newItemName, int newMAXHPPower, string newDescription)
    : maxHPPower(newMAXHPPower), HealthItemStub(newItemName, newMAXHPPower, newDescription) {}

int MaxHPPotStub::getMaxHPPower() {
    return this->maxHPPower;
}

string MaxHPPotStub::getItemName() {
    return this->itemName;
}

string MaxHPPotStub::getDescription() {
    return this->description;
}
void MaxHPPotStub::printStat() {
    if (this->getMaxHPPower() < 0) {throw logic_error("The Max HP Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Increases Max HP by " << this->getMaxHPPower() << "\n  Description: " << this->getDescription() << endl;
}

void MaxHPPotStub::useItem(Player* player) {
    player->setMaxHP(player->getMaxHP() + this->getMaxHPPower());
}