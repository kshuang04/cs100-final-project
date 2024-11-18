#include "../stubs/levelStub.hpp"

void Level::addEnemy(Enemy* e)
{
    listOfEnemies.push_back(e);
}

vector<Enemy*>* Level::getListOfEnemies()
{
    return &listOfEnemies;
}