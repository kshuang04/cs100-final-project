#include "../header/chest.hpp"
//#include "../header/Item.hpp"
#include "../header/Player.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib> 

//default constructor
Chest::Chest(int maxNum, std::vector<Item*> items, int goldNum)
    : maxItemCount(maxNum), itemInven(items), goldAmount(goldNum) {}

Chest::Chest()
    : maxItemCount(10), goldAmount(0) {}

// constructor with auto filledd item
Chest::Chest(int maxNum)
    : maxItemCount(maxNum), goldAmount(0) {
    fillChest();
}

// Destructor: Cleans up dynamically allocated items
Chest::~Chest() {
    for (Item* item : itemInven) {
        delete item;
    }
    itemInven.clear();
}

void Chest::collectItems(Player* player) {
    // check for empty chest
    if (isEmpty()){
        std::cout << "The chest is empty." << std::endl;
        return;
    }

    //handle the gold
    if (!goldAmount <= 0){  // if amount of gold in chest is > 0
        std:: cout << "You have collected " << goldAmount << " gold from the chest!" << std::endl;
        player->setGold(goldAmount + player->getGold());
        goldAmount = 0;
    }

    // handle item
    for (Item* item : itemInven){
            // since there is no upper limit for number of item a player can hold
            // just load everything into it
            player->getPlayerInven()->addItem(item, player);  // add item to player's inventory
            std:: cout << "You have obtained" << item->getItemName() << std::endl;
        
    }
    // after loading everything, the chest is empty.
    itemInven.clear();
}


// Checks if the chest is empty
bool Chest::isEmpty() const {
    return itemInven.empty() && goldAmount == 0;
}

// Check if the chest is full
bool Chest::isFull() const {
    return itemInven.size() >= maxItemCount;
}

void Chest::fillChest(){
    std::vector<Item*> newItems = generateItem();
    // Add items to the chest until it reaches max capacity
    for (Item* item : newItems) {
        if (isFull()) {
            delete item;  // Prevent memory leaks for unused items
            item = nullptr;
            continue;
        }
        itemInven.push_back(item);
    }
    newItems.clear();
    std::cerr << "Number of items " << getItemCount() << std::endl;
    goldAmount = std::rand() % 51;
}