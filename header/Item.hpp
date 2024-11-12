#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

using namespace std;

class Item {
protected:
    string itemName;
    string description;

public:
    Item();  // Default constructor
    virtual ~Item();  // Virtual destructor for polymorphism if needed
    Item(string newItemName, string newDescription);  // Constructor with parameters
    virtual string getItemName();  // Virtual function
    virtual string getDescription();  // Virtual function
    virtual void printStat();  // Virtual function for subclass overrides
};

#endif // ITEM_HPP
