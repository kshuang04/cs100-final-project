#include "../header/ItemInventory.hpp"

ItemInventory::ItemInventory() : itemCount(0) {}

ItemInventory::~ItemInventory() {
    //Deletes every item in the item Inventory
    for (int i = 0; i < this->getItemInven().size(); i++) {
        delete this->getItemInven().at(i);
        this->getItemInven().at(i) = nullptr;
    }
}

void ItemInventory::addItem(Item* newItem, Player* player) {
    //Adds the item, increases the item count by 1, and update the player's stats.
    this->getItemInven().push_back(newItem);
    this->setItemCount(this->getItemCount() + 1);
    this->stackItemStats(player);
}

void ItemInventory::consumeItem(Item* currentItem, Player* player) {
    //Checks to see if the item is real and availabe
    if (currentItem == nullptr) {throw logic_error("Using an item that does not exist.");}
    //Consumes the item and then remove it
    currentItem->useItem(player);
    delete currentItem; //delete object 
    this->setItemCount(this->getItemCount() - 1); //decrement count
    //***********************************************NEED TO DELETE ELEMENT SPACE IN VECTOR TOO (USE VECTOR.ERASE()?)
}

void ItemInventory::stackItemStats(Player* player) {
    //Resets the attack, defense, and max HP stats to be able to recalculate those stats correctly.
    player->setAttackStat(0);
    player->setDefenseStat(0);
    player->setMaxHPStat(0);
    //Takes each item in the player's inventory and updates their respective stat.
    for (int i = 0; i < this->getItemInven().size(); i++) {
        this->getItemInven().at(i)->useItem(player);        
    }
    player->setAttackStat(max(1, player->getAttackStat()));
    player->setDefenseStat(max(1, player->getDefenseStat()));
}

void ItemInventory::removeItem(int itemIndex) {
    delete itemIven.at(itemIndex); //delete object at index
    itemIven.erase(itemIven.begin() + itemIndex); //delete element space at index
    this->setItemCount(this->getItemCount() - 1); //decrement item count
}