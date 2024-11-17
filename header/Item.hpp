#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
#include <vector>

#include "../header/Player.hpp"

using namespace std;

class Player;

class Item {
protected:
    string itemName;
    string description;
    int stageType;
    int rarity;

public:
    Item();
    ~Item();
    Item(string newItemName, string newDescription);
    virtual string getItemName();
    virtual string getDescription();
    virtual void printStat();
    virtual void useItem(Player* player);   
    int getStage();
    int getRarity();
};

class AttackItem : public Item {
    private:
        int attackPower;
    public:
        AttackItem(int attackPower, int levelType, string name, int rarity);
        int getAttackPower();

};

class DefenseItem : public Item {
    private:
        int defensePower;
    public:
        DefenseItem(int defensePower, int levelType, string name, int rarity);
        int getDefensePower();
};

class MaxHPPot : public Item {
    private: 
        int healthIncrease;
    public:
        MaxHPPot(int healthIncrease, int levelType, string name, int rarity);
        int getHealthIncrease();
};

struct GenerateItems {        
        vector<Item*> generateItem();
        
        vector<Item*> deletor = generateItem();
        ~GenerateItems();

};


#endif