#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "../header/enemy.hpp"
#include <iostream>
#include <vector>

using namespace std;

class level
{
private:
    vector<Enemy> listOfEnemies; // Vector to store enemies for this level

    // Private helper function to insert enemies based on the level and stage
    void insertEnemies(int level, int region, int stage);
    int numLevel;
    int numStage;
    int numRegion;

public:
    level(int level, int region); // Default constructor
    int getTotalGold();
    vector<Enemy>* returnEnemyVectorP();

    vector<Enemy> returnEnemyVector();

    int getLevelNum();
    int getStage();
    int getRegion();
};

#endif
