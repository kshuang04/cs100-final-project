#include "../stubs/MaxHPPotStub.hpp"

MaxHPPotStub::MaxHPPotStub() : HealthItemStub(1, 1, "NULL", 1, "NULL") {}

MaxHPPotStub::~MaxHPPotStub() {}

MaxHPPotStub::MaxHPPotStub(int healthIncrease, int levelType, string name, int rarity, string description) : maxHPPower(healthIncrease)
{
    this->itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
    this->description = description;
}

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

    player->setMaxHPStat(player->getMaxHP() + this->getMaxHPPower());
}