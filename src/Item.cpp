#include "../header/Item.hpp"

Item::Item() : itemName("NULL"), description("NULL") {}

Item::~Item() {}

Item::Item(string newItemName, string newDescription, int newStageType, int newRarity)
    : itemName(newItemName), description(newDescription), stageType(newStageType), rarity(newRarity) {}

string Item::getItemName() {
    return this->itemName;
}

string Item::getDescription() {
    return this->description;
}

// void Item::printStat() {
//     cout << "Item: " << this->getItemName() << ", Description: " << this->getDescription() << endl;
// }

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
    listOfItem.push_back(new AttackItem(2, 1, "+2 attack", 1, "Makes you stronger."));
    listOfItem.push_back(new DefenseItem(4, 1, "+4 defense", 2, "Creates a shield around you."));
    listOfItem.push_back(new MaxHPPot(4, 1, "+4 health", 3, "Boosts your max health."));


    listOfItem.push_back(new AttackItem(4, 2, "+4 attack", 1, "Makes you stronger."));
    listOfItem.push_back(new DefenseItem(7, 2, "+7 defense", 2, "Creates a shield around you."));
    listOfItem.push_back(new MaxHPPot(7, 2, "+7 health", 3, "Boosts your max health."));


    listOfItem.push_back(new AttackItem(7, 3, "+7 attack", 1, "Makes you stronger."));
    listOfItem.push_back(new DefenseItem(13, 3, "+13 defense", 2, "Creates a shield around you."));
    listOfItem.push_back(new MaxHPPot(13, 3, "+13 health", 3, "Boosts your max health."));

    return listOfItem;

}

AttackItem::AttackItem(int attackPower, int levelType, string name, int rarity, string description) : attackPower(attackPower)
{ 
    this->stageType = levelType;
    this->itemName = name;
    this->rarity = rarity;
    this->description = description;
}

AttackItem::~AttackItem() {}

int AttackItem::getAttackPower() {
    return attackPower;
}

// void AttackItem::printStat() {
//     if (this->getAttackPower() < 0) {throw logic_error("The Attack Power is negative and invalid.");}
//     cout << "Item: " << this->getItemName() << "\n  Attack Power: " << this->getAttackPower() << "\n  Description: " << this->getDescription() << endl;
// }

void AttackItem::useItem(Player* player) {
    player->setAttackStat(player->getAttackStat() + this->getAttackPower());
}

DefenseItem::DefenseItem(int defensePower, int levelType, string name, int rarity, string description) : defensePower(defensePower)
{
    itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
    this->description = description;
}

DefenseItem::~DefenseItem() {}

int DefenseItem::getDefensePower() {
    return defensePower;
}

// void DefenseItem::printStat() {
//     if (this->getDefensePower() < 0) {throw logic_error("The Defense Power is negative and invalid.");}
//     cout << "Item: " << this->getItemName() << "\n  Defense Power: " << this->getDefensePower() << "\n  Description: " << this->getDescription() << endl;
// }

void DefenseItem::useItem(Player* player) {
    player->setDefenseStat(player->getDefenseStat() + this->getDefensePower());
}

HealthItem::HealthItem() : healthIncrease(0), levelType(1), name("NULL"), rarity(1), description("NULL") {}

HealthItem::~HealthItem() {}

HealthItem::HealthItem(int healthIncrease, int levelType, string name, int rarity, string description)
    : healthIncrease(healthIncrease), levelType(levelType), name(name), rarity(rarity), description(description) {}

int HealthItem::getHealthIncrease() {
    return this->healthIncrease;
}
string HealthItem::getItemName() {
    return this->itemName;
}

string HealthItem::getDescription() {
    return this->description;
}

// void HealthItem::printStat() { //DELETE
//     cout << "Item: " << this->getItemName() << ", Description: " << this->getDescription() << endl;
// }

void HealthItem::useItem(Player* player) {}

MaxHPPot::MaxHPPot(int healthIncrease, int levelType, string name, int rarity, string description) : healthIncrease(healthIncrease)
{
    this->itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
    this->description = description;
}

MaxHPPot::~MaxHPPot() {}

string MaxHPPot::getItemName() {
    return this->itemName;
}

int MaxHPPot::getHealthIncrease() {
    return healthIncrease;
}

// void MaxHPPot::printStat() {
//     if (this->getHealthIncrease() < 0) {throw logic_error("The Max HP Power is negative and invalid.");}
//     cout << "Item: " << this->getItemName() << "\n  Increases Max HP by " << this->getHealthIncrease() << "\n  Description: " << this->getDescription() << endl;
// }

string MaxHPPot::getDescription() {
    return this->description;
}

void MaxHPPot::useItem(Player* player) {
    player->setMaxHPStat(player->getMaxHPStat() + this->getHealthIncrease());
}

HealingPot::HealingPot(int healthIncrease, int levelType, string name, int rarity, string description) : healthIncrease(healthIncrease)
{
    this->itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
    this->description = description;
}

HealingPot::~HealingPot() {}

string HealingPot::getItemName() {
    return this->itemName;
}

int HealingPot::getHealthIncrease() {
    return healthIncrease;
}

// void HealingPot::printStat() {
//     if (this->getHealthIncrease() < 0) {throw logic_error("The Max HP Power is negative and invalid.");}
//     cout << "Item: " << this->getItemName() << "\n  Increases Max HP by " << this->getHealthIncrease() << "\n  Description: " << this->getDescription() << endl;
// }

string HealingPot::getDescription() {
    return this->description;
}

void HealingPot::useItem(Player* player) {
    player->setHP(min(player->getMaxHP(), (player->getHP() + this->getHealthIncrease())));
}