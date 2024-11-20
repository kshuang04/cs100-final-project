#include "../header/Item.hpp"


Item::Item() {}

Item::~Item() {}

void Item::printStat() {
    cout << "Item: " << this->getItemName() << ", Description: " << this->getDescription() << endl;
}

string Item::getDescription() {
    return description;
}

string Item::getItemName() {
    return this->itemName;
}

void Item::useItem(Player* player) {}

int Item::getStage() {
    return stageType;
}

int Item::getRarity() {
    return rarity;
}


AttackItem::AttackItem(int attackPower, int levelType, string name, int rarity, string description) : attackPower(attackPower)
{ 
    this->stageType = stageType;
    itemName = name;
    this->rarity = rarity;
    this->description = description;
}

AttackItem::~AttackItem() {}

int AttackItem::getAttackPower() {
    return attackPower;
}


void AttackItem::printStat() {
    if (this->getAttackPower() < 0) {throw logic_error("The Attack Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Attack Power: " << this->getAttackPower() << "\n  Description: " << this->getDescription() << endl;
}

void AttackItem::useItem(Player* player) {
    player->setAttackStat(player->getAttackStat() + this->getAttackPower());
}

DefenseItem::DefenseItem(int defensePower, int levelType, string name, int rarity, string description) : defensePower(defensePower)
{
    itemName = name;
    this->stageType = stageType;
    this->rarity = rarity;
    this->description = description;
}

DefenseItem::~DefenseItem() {}

int DefenseItem::getDefensePower() {
    return defensePower;
}


void DefenseItem::printStat() {
    if (this->getDefensePower() < 0) {throw logic_error("The Defense Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Defense Power: " << this->getDefensePower() << "\n  Description: " << this->getDescription() << endl;
}

void DefenseItem::useItem(Player* player) {
    player->setDefenseStat(player->getDefenseStat() + this->getDefensePower());
}

MaxHPPot::MaxHPPot(int healthIncrease, int levelType, string name, int rarity, string description) : healthIncrease(healthIncrease)
{
    itemName = name;
    this->stageType = stageType;
    this->rarity = rarity;
    this->description = description;
}

MaxHPPot::~MaxHPPot() {}

int MaxHPPot::getHealthIncrease() {
    return healthIncrease;
}

void MaxHPPot::printStat() {
    if (this->getHealthIncrease() < 0) {throw logic_error("The Max HP Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Increases Max HP by " << this->getHealthIncrease() << "\n  Description: " << this->getDescription() << endl;
}

void MaxHPPot::useItem(Player* player) {
    player->setMaxHPStat(player->getMaxHPStat() + this->getHealthIncrease());
}

HealingPot::HealingPot(int healthIncrease, int levelType, string name, int rarity, string description) : healthIncrease(healthIncrease)
{
    itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
    this->description = description;
}

HealingPot::~HealingPot() {}

int HealingPot::getHealAmount() {
    return healthIncrease;
}

void HealingPot::printStat() {
    if (this->getHealAmount() < 0) {throw logic_error("The Max HP Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Increases Max HP by " << this->getHealAmount() << "\n  Description: " << this->getDescription() << endl;
}

void HealingPot::useItem(Player* player) {
    player->setHP(min(player->getMaxHP(), (player->getHP() + this->getHealAmount())));
}