#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include "../header/Item.hpp"
#include <stdlib.h>
#include "../header/Player.hpp"

using namespace std;

class Enemy
{
private:
    int health;
    int maxHealth;
    int attackPower;
    int defense;
    int expAmount;
    int goldAmount;
    bool alive;
    string name;
    // 1 = early, 2 = mid, 3 = late
    int stage;
    // 1 = plains, 2 = forest, 3 = castle, 4 = grave, 5 = lake
    int region;


public:
    Enemy(int maxHealth, int defense, int attackPower, int exp, int gold, string enemyName, int stageNum, int regionNum);

    Enemy();

    int attack(Player* target);
    void gotAttack(int playerDamage);
    Item * releaseDrops();
    bool isAlive();
    string getName();
    int getHealth();
    int getMaxHealth();
    int getGold() const;
    int getStage();
    int getRegion();
    int getAttackPower();
    int getEXP() const;
};




#endif