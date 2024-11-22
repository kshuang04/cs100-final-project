#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
    Item(string newItemName, string newDescription, int newStageType, int newRarity);
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

        AttackItem(int attackPower, int stageType, string name, int rarity, string description);
        ~AttackItem();
        int getAttackPower();
        void printStat();
        void useItem(Player* player); 
};

class DefenseItem : public Item {
    private:
        int defensePower;
    public:
        DefenseItem(int defensePower, int stageType, string name, int rarity, string description);
        ~DefenseItem();
        int getDefensePower();
        void printStat();
        void useItem(Player* player); 
};

class HealthItem : public Item {
protected:
    int healthIncrease;
    int stageType;
    string name;
    int rarity;
    string description;
public:
    HealthItem();
    virtual ~HealthItem();
    HealthItem(int healthIncrease, int stageType, string name, int rarity, string description);
    virtual int getHealthIncrease();
    string getItemName();
    virtual string getDescription();
    virtual void printStat();
    virtual void useItem(Player* player);   
};

class MaxHPPot : public HealthItem {
    private: 
        int healthIncrease;
    public:

        MaxHPPot(int healthIncrease, int stageType, string name, int rarity, string description);
        ~MaxHPPot();
        string getItemName();
        int getHealthIncrease();
        void printStat();
        string getDescription();
        void useItem(Player* player); 
};

class HealingPot : public HealthItem {
    private: 
        int healthIncrease;
    public:
        HealingPot(int healthIncrease, int stageType, string name, int rarity, string description);
        ~HealingPot();
        string getItemName();
        int getHealthIncrease();
        void printStat();
        string getDescription();
        void useItem(Player* player); 
};

vector<Item*> generateItem();
        



#endif