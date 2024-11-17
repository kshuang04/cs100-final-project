#include "../header/chest.hpp"
#include "../header/Player.hpp"
#include <iostream>
#include <stdexcept>

//default constructor
Chest::Chest(int maxNum, std::vector<Item*> items, int goldNum) : maxItemCount(maxNum), itemInven(items), goldAmount(goldNum) {

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
            player->addItem(item);  // add item to player's inventory
            std:: cout << "You have obtained" << item->getItemName() << std::endl;
        
    }
    // after loading everything, the chest is empty.
    itemInven.clear();
}


// Checks if the chest is empty
bool Chest::isEmpty() const {
    return itemInven.empty() && goldAmount == 0;
}
