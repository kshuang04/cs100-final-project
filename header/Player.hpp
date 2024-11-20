#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cmath>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "../header/Item.hpp"

class Item;
class HealingPot;

using namespace std;

class Player {
    private:
        int currHP;
        int maxHP;
        int level;
        int maxLevel;
        int exp;
        int attackStat;
        int defenseStat;
        int maxHPStat;
        unsigned int gold;
        vector<Item*> itemIven;
        vector<HealingPot*> healingPotIven;
        int itemCount;
        int healingPotCount;
        bool isAlive;
    public:
        Player();
        Player(int maxHP, int maxLevel, int attack, int defense, int gold);
        ~Player();
        //Functions
        int attack();
        void takeDamage(int damage);
        void addItem(HealingPot* newHealingPotItem);
        void addItem(Item* newItem);
        void consumeItem(Item* currentItem);
        void consumeItem(int itemIndex);
        void stackItemStats();
        void removeItem(int itemIndex);
        void changeGold(int goldChange);
        void changeEXP(int expChange);
        int expToNextLevel();
        //Accessors
        int getHP() {return this->currHP;}
        int getMaxHPFromLevel() {return (this->getMaxHPStat() + 20 + 5 * (this->getLevel() - 1));}
        int getMaxHP() {return this->maxHP;}
        int getLevel() {return this->level;}
        int getMaxLevel() {return this->maxLevel;}
        int getEXP() {return this->exp;}
        int getAttackStat() {return this->attackStat;}
        int getDefenseStat() {return this->defenseStat;}
        int getMaxHPStat() {return this->maxHPStat;}
        unsigned int getGold() {return this->gold;}
        int getItemCount() {return this->itemCount;}
        int getHealingPotCount() {return this->healingPotCount;}
        vector<Item*>& getItemIven() {return this->itemIven;}
        vector<HealingPot*>& getHealingPotIven() {return this->healingPotIven;}
        bool getIsAlive() {return this->isAlive;}
        //Mutators
        void setHP(int newHP) {this->currHP = newHP;}
        void setLevel(int newLevel) {this->level = newLevel;}
        void setMaxLevel(int newMaxLevel) {this->maxLevel = newMaxLevel;}
        void setEXP(int newEXP) {this->exp = newEXP;}
        void setAttackStat(int newAttackStat) {this->attackStat = newAttackStat;}
        void setDefenseStat(int newDefenseStat) {this->defenseStat = newDefenseStat;}
        void setMaxHPStat(int newMaxHPStat) {
            this->maxHPStat = newMaxHPStat;
            this->maxHP = (this->getMaxHPStat() + 20 + 5 * (this->getLevel() - 1));
        }
        void setGold(unsigned int newGoldAmount) {this->gold = newGoldAmount;}
        void setItemCount(int newCount) {this->itemCount = newCount;}
        void setHealingPotCount(int newHealingPotCount) {this->healingPotCount = newHealingPotCount;}
        void setIsAlive(bool newAliveStatus) {this->isAlive = newAliveStatus;}
};

#endif