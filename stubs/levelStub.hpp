#ifndef LEVELSTUB_HPP
#define LEVELSTUB_HPP

#include <vector>

#include "../header/enemy.hpp"

class Level
{
    private:
        vector<Enemy*> listOfEnemies;
    public:
        void addEnemy(Enemy* e);
        vector<Enemy*>* getListOfEnemies();
};

#endif