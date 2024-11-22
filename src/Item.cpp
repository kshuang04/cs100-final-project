#include "../header/Item.hpp"

Item::Item() : itemName("NULL"), description("NULL") {}

Item::~Item() {}

Item::Item(string newItemName, string newDescription, int newStageType, int newRarity)
    : itemName(newItemName), description(newDescription), stageType(newStageType), rarity(newRarity) {}

string Item::getItemName() {
    return this->itemName;
}

string Item::getDescription() {
    return description;
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


AttackItem::AttackItem(int attackPower, int stageType, string name, int rarity, string description) : attackPower(attackPower)
{ 
    this->stageType = stageType;
    this->itemName = name;
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

DefenseItem::DefenseItem(int defensePower, int stageType, string name, int rarity, string description) : defensePower(defensePower)
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

HealthItem::HealthItem() : healthIncrease(0), stageType(1), name("NULL"), rarity(1), description("NULL") {}

HealthItem::~HealthItem() {}

HealthItem::HealthItem(int healthIncrease, int stageType, string name, int rarity, string description)
    : healthIncrease(healthIncrease), stageType(stageType), name(name), rarity(rarity), description(description) {}

int HealthItem::getHealthIncrease() {
    return this->healthIncrease;
}
string HealthItem::getItemName() {
    return this->itemName;
}

string HealthItem::getDescription() {
    return this->description;
}

void HealthItem::printStat() {
    cout << "Item: " << this->getItemName() << ", Description: " << this->getDescription() << endl;
}

void HealthItem::useItem(Player* player) {}

MaxHPPot::MaxHPPot(int healthIncrease, int stageType, string name, int rarity, string description) : healthIncrease(healthIncrease)
{
    this->itemName = name;
    this->stageType = stageType;
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

void MaxHPPot::printStat() {
    if (this->getHealthIncrease() < 0) {throw logic_error("The Max HP Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Increases Max HP by " << this->getHealthIncrease() << "\n  Description: " << this->getDescription() << endl;
}

string MaxHPPot::getDescription() {
    return this->description;
}

void MaxHPPot::useItem(Player* player) {
    player->setMaxHPStat(player->getMaxHPStat() + this->getHealthIncrease());
}

HealingPot::HealingPot(int healthIncrease, int stageType, string name, int rarity, string description) : healthIncrease(healthIncrease)
{
    this->itemName = name;
    this->stageType = stageType;
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

void HealingPot::printStat() {
    if (this->getHealthIncrease() < 0) {throw logic_error("The Max HP Power is negative and invalid.");}
    cout << "Item: " << this->getItemName() << "\n  Increases Max HP by " << this->getHealthIncrease() << "\n  Description: " << this->getDescription() << endl;
}

string HealingPot::getDescription() {
    return this->description;
}

void HealingPot::useItem(Player* player) {
    player->setHP(min(player->getMaxHP(), (player->getHP() + this->getHealthIncrease())));
}

vector<Item*> generateItem() {
        
    vector<Item*> listOfItems;

    int stat;
    int stage;
    string name;
    int rarity;
    string desc;

    ifstream file;

    file.open("../data/Item.txt");

    int nameIndex;
    int descIndex;


    if (!(file.is_open())) {
        throw runtime_error("File not open");
    }

    while (file >> stat >> stage >> name >> rarity >> desc) {

        //Replace the "_" with " "
        nameIndex = name.find("_");
        descIndex = desc.find("_");

        if (nameIndex != string::npos) {
            name.replace(nameIndex, 1, " ");
        }

        //the desc has multiplie "_"
        while (descIndex != string::npos) {
            desc.replace(descIndex, 1, " ");
            descIndex = desc.find("_");
        }
        if (name.find("attack") != string::npos) 
            listOfItems.push_back(new AttackItem(stat, stage, name, rarity, desc));
        else if (name.find("defense") != string ::npos) 
            listOfItems.push_back(new DefenseItem(stat, stage, name, rarity, desc));
        else if (name.find("HP") != string::npos)
            listOfItems.push_back(new MaxHPPot(stat, stage, name, rarity, desc));
        else
            listOfItems.push_back(new HealingPot(stat, stage, name, rarity, desc));

    }
    return listOfItems;
}
