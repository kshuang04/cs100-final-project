#ifndef CHEST_HPP
#define CHEST_HPP

#include <vector>
#include <string>
#include "Item.hpp"
class Chest
{   
    private:
        const int maxItemCount;     // store the maximum number of item chest can hold
        std::vector<Item*> itemInven;   // Inventory of items in the chest
        int goldAmount;     // contain the ammount of gold
    public:
        //constructor
        Chest(int maxNum, std::vector<Item*> items, int goldNum);
        //destructor
        ~Chest();
        void collectItems(Player* player);
        bool isEmpty() const;   // check if the chest is empty


};

#endif