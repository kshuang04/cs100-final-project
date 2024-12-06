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
            Chest();    // default generate 
            Chest(int maxNum, std::vector<Item*> items, int goldNum);   // generate based on input
            Chest(int maxNum);  //auto filled item
            //destructor
            ~Chest();
            // getter function for testing 
            int getGoldAmount() const {return goldAmount;}
            size_t getItemCount() const {return itemInven.size();}
            void collectItems(Player* player);
            bool isEmpty() const;   // check if the chest is empty
            bool isFull() const;
            void fillChest();       // fill the chest with gold and item


    };

    #endif