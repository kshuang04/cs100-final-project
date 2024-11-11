#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cmath>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

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
        int gold;
        //Item itemIven[15];
        //playerClass playerClass;
    public:
        Player();
        Player(int maxHP, int maxLevel, int attack, int defense, int gold);
        ~Player();
        //Functions
        int attack();
        //Attack getAttack();
        void printStats();
        void printInven();
        void useItem();
        void changeGold(int goldChange);
        void changeEXP(int expChange);
        int expToNextLevel();
        //Accessors
        int getHP() {return this->currHP;}
        int getMaxHP() {return this->maxHP;}
        int getLevel() {return this->level;}
        int getMaxLevel() {return this->maxLevel;}
        int getEXP() {return this->exp;}
        int getAttackStat() {return this->attackStat;}
        int getDefenseStat() {return this->defenseStat;}
        int getGold() {return this->gold;}
        //Mutators
        void setHP(int newHP) {this->currHP = newHP;}
        void setMaxHP(int newMaxHP) {this->maxHP = newMaxHP;}
        void setLevel(int newLevel) {this->level = newLevel;}
        void setMaxLevel(int newMaxLevel) {this->maxLevel = newMaxLevel;}
        void setEXP(int newEXP) {this->exp = newEXP;}
        void setAttackStat(int newAttackStat) {this->attackStat = newAttackStat;}
        void setDefenseStat(int newDefenseStat) {this->defenseStat = newDefenseStat;}
        void setGold(int newGoldAmount) {this->gold = newGoldAmount;}
};

#endif