#include "../stubs/HealingPotStub.hpp"

HealingPotStub::HealingPotStub() : HealthItemStub(1, 1, "NULL", 1, "NULL") {}

HealingPotStub::~HealingPotStub() {}

HealingPotStub::HealingPotStub(int healthIncrease, int levelType, string name, int rarity, string description) : HPPower(healthIncrease)
{
    this->itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
    this->description = description;
}
int HealingPotStub::getHPPower() {
    return this->HPPower;
}

string HealingPotStub::getItemName() {
    return this->itemName;
}

string HealingPotStub::getDescription() {
    return this->description;
}

// void HealingPotStub::printStat() {
//     if (this->getHPPower() < 0) {throw logic_error("The HP Power is negative and invalid.");}
//     cout << "Item: " << this->getItemName() << "\n  Heals " << this->getHPPower() << " HP\n  Description: " << this->getDescription() << endl;
// }

void HealingPotStub::useItem(Player* player) {
    player->setHP(min((player->getHP() + this->getHPPower()), player->getMaxHP()));
}