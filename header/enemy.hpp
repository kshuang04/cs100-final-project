#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <stdlib.h>
#include "../header/Item.hpp"
#include <vector>

using namespace std;

class Enemy {
    private:
        int health;
        int maxHealth;
        int attackPower;
        int defense;
        string description;
        int expAmount;
        int goldAmount;
        bool alive;
        string name;
    public:
        //DONT USE THIS CONSTRUCTOR
        //this is only for enemy insertion in level class
        Enemy(int maxHealth, int defense, int attackPower, int exp, int gold, string enemyName);
        
        Enemy();

        // ~Enemy(); //?
        int attack();
        void gotAttack(int playerDamage);
        void heal(int healthIncrease); //?
        Item releaseDrops();
        bool isAlive();
        void setDescription(string);
        string getName();
        int getHealth();
        int getGold();
        
};

#endif