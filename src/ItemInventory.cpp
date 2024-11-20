#include "../header/ItemInventory.hpp"

ItemInventory::ItemInventory() : itemCount(0), healingPotCount(0) {}

ItemInventory::~ItemInventory() {
    //Deletes every item in the item Inventory
    for (int i = 0; i < this->getItemInven().size(); i++) {
        delete this->getItemInven().at(i);
        this->getItemInven().at(i) = nullptr;
    }
    for (int i = 0; i < this->getHealingPotInven().size(); i++) {
        delete this->getHealingPotInven().at(i);
        this->getHealingPotInven().at(i) = nullptr;
    }
}

void ItemInventory::addItem(HealingPot* newHealingPotItem, Player* player) {
    //Adds the new Healing Pot Item to a separate inventory
    this->getHealingPotInven().push_back(newHealingPotItem);
    this->setHealingPotCount(this->getHealingPotCount() + 1);
    this->stackItemStats(player);
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
    delete currentItem;
}

void ItemInventory::consumeItem(int itemIndex, Player* player) {
    //Check to see if the item index is within the range and throws an error if not.
    if (((itemIndex - 1) < 0) || ((itemIndex - 1) >= this->getHealingPotCount()) || (this->getHealingPotCount() == 0)) {throw out_of_range("Access an index that is out of range of the item inventory.");}
    //Uses the item and then removes it from the item inventory.
    this->getHealingPotInven().at((itemIndex - 1))->useItem(player);
    this->removeItem(itemIndex);
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
    //Check to see if the item index is within the range and throws an error if not.
    if (((itemIndex - 1) < 0) || ((itemIndex - 1) > this->getHealingPotCount()) || (this->getHealingPotCount() == 0)) {throw out_of_range("Access an index that is out of range of the item inventory.");}
    //Deletes the Item pointer and then removes it from the vector for item inventory, and decreases item count by 1
    delete this->getHealingPotInven().at((itemIndex - 1));
    this->getHealingPotInven().erase(this->getHealingPotInven().begin() + (itemIndex - 1));
    this->setHealingPotCount(this->getHealingPotCount() - 1);
}