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
    if (typeid(*currentItem) != typeid(HealingPot)) {throw logic_error("Did not consume a Healing Pot item.");}
    if (currentItem == nullptr) {throw logic_error("Using an item that does not exist.");}
    //Consumes the item and then remove it
    currentItem->useItem(player);
    delete currentItem; //delete object
    this->setItemCount(this->getItemCount() - 1); //decrement counter
}

void ItemInventory::stackItemStats(Player* player) {
    //Resets the attack, defense, and max HP stats to be able to recalculate those stats correctly.
    player->setAttackStat(0);
    player->setDefenseStat(0);
    player->setMaxHPStat(0);
    //Takes each item in the player's inventory and updates their respective stat.
    for (int i = 0; i < this->getItemInven().size(); i++) {
        if (typeid(*this->getItemInven().at(i)) != typeid(HealingPot)) {
            this->getItemInven().at(i)->useItem(player);
        }
    }
    player->setAttackStat(max(1, player->getAttackStat() + 1));
    player->setDefenseStat(max(1, player->getDefenseStat() + 1));
}

void ItemInventory::removeItem(int itemIndex) {
    delete this->getItemInven().at(itemIndex); //delete object at index
    this->getItemInven().erase(this->getItemInven().begin() + itemIndex); //delete element space at index
    this->setItemCount(this->getItemCount() - 1); //decrement item count
}

bool ItemInventory::healingPotExists() {
    if (this->getItemInven().size() == 0) {return false;}
    for (int i = 0; i < this->getItemInven().size(); i++) { //Loops through the entire inventory.
        if (typeid(*this->getItemInven().at(i)) == typeid(HealingPot)) { //Checks to see if the item is a healing pot.
            return true;
        }
    }
    return false;
}

void ItemInventory::consumeNextHealingPot(Player* player) {
    if (this->healingPotExists()) { //Checks to see if there is a healing pot in the inventory.
        for (int i = 0; i < this->getItemInven().size(); i++) { //Loops through the entire inventory.
            if (typeid(*this->getItemInven().at(i)) == typeid(HealingPot)) { //Checks to see if the item is a healing pot.
                this->consumeItem(this->getItemInven().at(i), player); //Consumes the next available healing pot.
                this->getItemInven().erase(this->getItemInven().begin() + i); //Remove item from inventory and then break out of loop.
                return;
            }
        }
    }
}