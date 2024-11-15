#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

#include "../header/Player.hpp"
class Player;

using namespace std;

class Item {
protected:
    string itemName;
    string description;

public:
    Item();
    virtual ~Item();
    Item(string newItemName, string newDescription);
    virtual string getItemName();
    virtual string getDescription();
    virtual void printStat();
    virtual void useItem(Player* player);
};

#endif