#include "../header/Item.hpp"

Item::Item() : itemName("NULL"), description("NULL") {}

Item::~Item() {}

Item::Item(string newItemName, string newDescription)
    : itemName(newItemName), description(newDescription) {}

string Item::getItemName() {
    return this->itemName;
}

string Item::getDescription() {
    return this->description;
}

void Item::printStat() {
    cout << "Item: " << this->getItemName() << ", Description: " << this->getDescription() << endl;
}

void Item::useItem(Player* player) {}

int Item::getStage() {
    return stageType;
}

int Item::getRarity() {
    return rarity;
}

vector<Item*> generateItem() {
    vector<Item*> listOfItem;

    //just template names
    listOfItem.push_back(new AttackItem(2, 1, "+2 attack", 1));
    listOfItem.push_back(new DefenseItem(4, 1, "+4 defense", 2));
    listOfItem.push_back(new MaxHPPot(4, 1, "+4 health", 3));


    listOfItem.push_back(new AttackItem(4, 2, "+4 attack", 1));
    listOfItem.push_back(new DefenseItem(7, 2, "+7 defense", 2));
    listOfItem.push_back(new MaxHPPot(7, 2, "+7 health", 3));


    listOfItem.push_back(new AttackItem(7, 3, "+7 attack", 1));
    listOfItem.push_back(new DefenseItem(13, 3, "+13 defense", 2));
    listOfItem.push_back(new MaxHPPot(13, 3, "+13 health", 3));

    return listOfItem;

}

AttackItem::AttackItem(int attackPower, int levelType, string name, int rarity) : attackPower(attackPower)
{ 
    this->stageType = levelType;
    itemName = name;
    this->rarity = rarity;
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

DefenseItem::DefenseItem(int defensePower, int levelType, string name, int rarity) : defensePower(defensePower)
{
    itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
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

MaxHPPot::MaxHPPot(int healthIncrease, int levelType, string name, int rarity) : healthIncrease(healthIncrease)
{
    itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
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

HealingPot::HealingPot(int healthIncrease, int levelType, string name, int rarity) : healthIncrease(healthIncrease)
{
    itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
}

HealingPot::~HealingPot() {}

int HealingPot::getHealthIncrease() {
    return healthIncrease;
}

void HealingPot::printStat() {
    if (this->getHealthIncrease() < 0) {throw logic_error("The Max HP Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Increases Max HP by " << this->getHealthIncrease() << "\n  Description: " << this->getDescription() << endl;
}

void HealingPot::useItem(Player* player) {
    player->setHP(min(player->getMaxHP(), (player->getHP() + this->getHealthIncrease())));
}