#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

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
    public:
        Enemy(int maxHealth, int attackPower, int defense, int exp, int gold);
        Enemy();
        ~Enemy(); //?
        int attack();
        void gotAttack(int damage);
        void heal(int healthIncrease); //?
        void releaseDrops();
        bool isAlive();
        void setDescription(string);
};

#endif