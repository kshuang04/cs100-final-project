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
    int stageType;
    int rarity;

public:
    Item();
    string getItemName();
    virtual void useItem(Player* player) = 0;   

    int getStage();
    int getRarity();
};

class AttackItem : public Item {
    private:
        int attackPower;
    public:
        AttackItem(int attackPower, int stageType, string name, int rarity);
        int getAttackPower();
        void useItem(Player* player);

};

class DefenseItem : public Item {
    private:
        int defensePower;
    public:
        DefenseItem(int defensePower, int stageType, string name, int rarity);
        int getDefensePower();
        void useItem(Player* player);
};

class MaxHPPot : public Item {
    private: 
        int healthIncrease;
    public:
        MaxHPPot(int healthIncrease, int stageType, string name, int rarity);
        int getHealthIncrease();
        void useItem(Player* player);
};

class HealingPot : public Item {
    private:
        int healingAmount;
    public:
        HealingPot(int healingAmount, int stageType, string name, int rarity);
        int getHealthAmount();
        void useItem(Player* player);
};

        



#endif