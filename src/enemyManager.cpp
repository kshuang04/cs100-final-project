#include <iostream>
#include <vector>

#include "../header/enemy.hpp"

using namespace std;

struct enemyManager
{
    vector<Enemy> enemies;
    enemyManager() {
    int hp;
    int def;
    int atk;
    int exp;
    int gold;
    string name;
    int stage;
    int region;

    ifstream file;
    file.open("src/Enemy.txt");

    if (!(file.is_open()))
    {
        throw runtime_error("File not open");
    }

    int index;

    while (file >> hp >> def >> atk >> exp >> gold >> name >> stage >> region)
    {

        // Enemy with name with 2 words
        // Replace "_" with " "
        index = name.find("_");
        if (index != string::npos)
        {
            name.replace(index, 1, " ");
        }

        Enemy newEnemy(hp, def, atk, exp, gold, name, stage, 1);
        enemies.push_back(newEnemy);
    }

    file.close();
    }

};