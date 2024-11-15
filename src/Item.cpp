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

vector<Item*> GenerateItems::generateItem() {
    vector<Item*> listOfItem;

    //just template names
    listOfItem.push_back(new AttackItem(2, 1, "+2 attack"));
    listOfItem.push_back(new DefenseItem(4, 1, "+4 defense"));
    listOfItem.push_back(new MaxHPPot(4, 1, "+4 health"));


    listOfItem.push_back(new AttackItem(4, 2, "+4 attack"));
    listOfItem.push_back(new DefenseItem(7, 2, "+7 defense"));
    listOfItem.push_back(new MaxHPPot(7, 2, "+7 health"));


    listOfItem.push_back(new AttackItem(7, 3, "+7 attack"));
    listOfItem.push_back(new DefenseItem(13, 3, "+13 defense"));
    listOfItem.push_back(new MaxHPPot(13, 3, "+13 health"));

    return listOfItem;

}

GenerateItems::~GenerateItems() {
    for (unsigned i = 0; i < deletor.size(); i++) {
        delete deletor.at(i);
    }
}

AttackItem::AttackItem(int attackPower, int levelType, string name) : attackPower(attackPower)
{ 
    this->levelType = levelType;
    itemName = name;
}

int AttackItem::getAttackPower() {
    return attackPower;
}

DefenseItem::DefenseItem(int defensePower, int levelType, string name) : defensePower(defensePower)
{
    itemName = name;
    this->levelType = levelType;
}

int DefenseItem::getDefensePower() {
    return defensePower;
}

MaxHPPot::MaxHPPot(int healthIncrease, int levelType, string name) : healthIncrease(healthIncrease) 
{
    itemName = name;
    this->levelType = levelType;
}

int MaxHPPot::getHealthIncrease() {
    return healthIncrease;
}
