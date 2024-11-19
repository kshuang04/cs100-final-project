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
    virtual ~Item();
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
        AttackItem(int attackPower, int levelType, string name, int rarity, string description);
        ~AttackItem();
        int getAttackPower();
        void printStat();
        void useItem(Player* player); 
};

class DefenseItem : public Item {
    private:
        int defensePower;
    public:
        DefenseItem(int defensePower, int levelType, string name, int rarity, string description);
        ~DefenseItem();
        int getDefensePower();
        void printStat();
        void useItem(Player* player); 
};

class MaxHPPot : public Item {
    private: 
        int healthIncrease;
    public:
        MaxHPPot(int healthIncrease, int levelType, string name, int rarity, string description);
        ~MaxHPPot();
        int getHealthIncrease();
        void printStat();
        void useItem(Player* player); 
};

class HealingPot : public Item {
    private: 
        int healthIncrease;
    public:
        HealingPot(int healthIncrease, int levelType, string name, int rarity, string description);
        ~HealingPot();
        int getHealthIncrease();
        void printStat();
        void useItem(Player* player); 
};

vector<Item*> generateItem();
        



#endif