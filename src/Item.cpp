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