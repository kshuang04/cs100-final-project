#include "../header/Item.hpp"


Item::Item() {}


void Item::printStat() {
    cout << "Item: " << this->getItemName() << ", Description: " << this->getDescription() << endl;

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

AttackItem::AttackItem(int attackPower, int stageType, string name, int rarity) : attackPower(attackPower)
{ 
    this->stageType = stageType;
    itemName = name;
    this->rarity = rarity;
}

int AttackItem::getAttackPower() {
    return attackPower;
}

DefenseItem::DefenseItem(int defensePower, int stageType, string name, int rarity) : defensePower(defensePower)
{
    itemName = name;
    this->stageType = stageType;
    this->rarity = rarity;
}

int DefenseItem::getDefensePower() {
    return defensePower;
}

MaxHPPot::MaxHPPot(int healthIncrease, int stageType, string name, int rarity) : healthIncrease(healthIncrease)
{
    itemName = name;
    this->stageType = stageType;
    this->rarity = rarity;
}

int MaxHPPot::getHealthIncrease() {
    return healthIncrease;
}
HealingPot::HealingPot(int healingAmount, int stageType, string name, int rarity) : healingAmount(healingAmount)
{
    itemName = name;
    this->stageType = stageType;
    this->rarity = rarity;
}

int HealingPot::getHealthAmount() {
    return healingAmount;
}

void AttackItem::useItem(Player * player) {
    player->setAttackStat(player->getAttackStat() + attackPower);
}

void DefenseItem::useItem(Player * player) {
    player->setDefenseStat(player->getDefenseStat() + defensePower);
}

void MaxHPPot::useItem(Player * player) {
    player->setMaxHP(player->getMaxHP() + healthIncrease);
}

void HealingPot::useItem(Player * player) {
    player->setHP(player->getHP() + healingAmount);
}

string Item::getDescription() {
    return description;
}