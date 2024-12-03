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
        int itemCount;
    public:
        ItemInventory();
        ~ItemInventory();
        void addItem(Item* newItem, Player* player);
        void consumeItem(Item* currentItem, Player* player);
        //void consumeItem(int itemIndex, Player* player);
        void stackItemStats(Player* player);
        void removeItem(int itemIndex);
        //Accessors
        int getItemCount() {return this->itemCount;}
        vector<Item*>& getItemInven() {return this->itemIven;}
        //Mutators
        void setItemCount(int newCount) {this->itemCount = newCount;}
};

#endif