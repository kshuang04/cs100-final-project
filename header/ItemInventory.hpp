#ifndef ITEMINVENTORY_HPP
#define ITEMINVENTORY_HPP

#include <cmath>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "../header/Item.hpp"
#include "../header/Player.hpp"

class Item;
class HealingPot;
class Player;

using namespace std;

class ItemInventory {
    private:
        vector<Item*> itemIven;
        vector<HealingPot*> healingPotIven;
        int itemCount;
        int healingPotCount;
    public:
        ItemInventory();
        ~ItemInventory();
        void addItem(HealingPot* newHealingPotItem);
        void addItem(Item* newItem, Player* player);
        void consumeItem(Item* currentItem, Player* player);
        void consumeItem(int itemIndex, Player* player);
        void stackItemStats(Player* player);
        void removeItem(int itemIndex);
        //Accessors
        int getItemCount() {return this->itemCount;}
        int getHealingPotCount() {return this->healingPotCount;}
        vector<Item*>& getItemIven() {return this->itemIven;}
        vector<HealingPot*>& getHealingPotIven() {return this->healingPotIven;}
        //Mutators
        void setItemCount(int newCount) {this->itemCount = newCount;}
        void setHealingPotCount(int newHealingPotCount) {this->healingPotCount = newHealingPotCount;}
};

#endif