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


void DefenseItem::useItem(Player* player) {
    player->setDefenseStat(player->getDefenseStat() + this->getDefensePower());
}


MaxHPPot::MaxHPPot(int healthIncrease, int stageType, string name, int rarity, string description) : healthIncrease(healthIncrease)
{
    this->itemName = name;
    this->stageType = stageType;
    this->rarity = rarity;
    this->description = description;
}

MaxHPPot::~MaxHPPot() {}



int MaxHPPot::getHealthIncrease() {
    return healthIncrease;
}




void MaxHPPot::useItem(Player* player) {
    player->setMaxHPStat(player->getMaxHPStat() + this->getHealthIncrease());
}

HealingPot::HealingPot(int healingAmount, int stageType, string name, int rarity, string description) : healingAmount(healingAmount)
{
    this->itemName = name;
    this->stageType = stageType;
    this->rarity = rarity;
    this->description = description;
}

HealingPot::~HealingPot() {}


int HealingPot::getHealthIncrease() {
    return healingAmount;
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
