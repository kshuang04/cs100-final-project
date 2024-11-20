#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cmath>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "../header/ItemInventory.hpp"

class ItemInventory;

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
        ItemInventory* playerIven;
        unsigned int gold;
        bool isAlive;
    public:
        Player();
        Player(int maxHP, int maxLevel, int attack, int defense, int gold);
        ~Player();
        //Functions
        int attack();
        void takeDamage(int damage);
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
        ItemInventory* getPlayerInven() {return this->playerIven;}
        unsigned int getGold() {return this->gold;}
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
        void setIsAlive(bool newAliveStatus) {this->isAlive = newAliveStatus;}
};

#endif