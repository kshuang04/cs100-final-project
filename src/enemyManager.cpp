#include <iostream>
#include <vector>

#include "../header/enemy.hpp"

using namespace std;

class enemyManager
{
public:
    vector<Enemy> enemies = {
        Enemy(10, 0, 5, 5, 10, "Goblin", 1, 1),
        Enemy(10, 0, 5, 5, 5, "Slime", 1, 1),
        Enemy(10, 0, 5, 5, 5, "Rat", 1, 1),
        Enemy(10, 0, 5, 5, 5, "Lizard", 1, 1),

        Enemy(10, 0, 5, 5, 10, "Wolf", 2, 1),
        Enemy(10, 0, 5, 5, 5, "Harpy", 2, 1),
        Enemy(10, 0, 5, 5, 5, "Raven", 2, 1),
        Enemy(10, 0, 5, 5, 5, "Boar", 2, 1),

        Enemy(10, 0, 5, 5, 10, "Troll", 3, 1),
        Enemy(10, 0, 5, 5, 5, "Cyclops", 3, 1),
        Enemy(10, 0, 5, 5, 5, "Hellhound", 3, 1),
        Enemy(10, 0, 5, 5, 5, "Giant", 3, 1),

        Enemy(10, 0, 5, 5, 10, "Pixie", 1, 2),
        Enemy(10, 0, 5, 5, 5, "Slug", 1, 2),
        Enemy(10, 0, 5, 5, 5, "Fairy", 1, 2),
        Enemy(10, 0, 5, 5, 5, "Beetle", 1, 2),

        Enemy(10, 0, 5, 5, 10, "Elf", 2, 2),
        Enemy(10, 0, 5, 5, 5, "Harpy", 2, 2),
        Enemy(10, 0, 5, 5, 5, "Snake", 2, 2),
        Enemy(10, 0, 5, 5, 5, "Eagle", 2, 2),

        Enemy(10, 0, 5, 5, 10, "Golem", 3, 2),
        Enemy(10, 0, 5, 5, 5, "Corpse Flower", 3, 2),
        Enemy(10, 0, 5, 5, 5, "Dryad", 3, 2),
        Enemy(10, 0, 5, 5, 5, "Wyrm", 3, 2),

        Enemy(10, 0, 5, 5, 10, "Bats", 1, 3),
        Enemy(10, 0, 5, 5, 5, "Skeleton", 1, 3),
        Enemy(10, 0, 5, 5, 5, "Guard", 1, 3),
        Enemy(10, 0, 5, 5, 5, "Archer", 1, 3),

        Enemy(10, 0, 5, 5, 10, "Knight", 2, 3),
        Enemy(10, 0, 5, 5, 5, "Guard Dog", 2, 3),
        Enemy(10, 0, 5, 5, 5, "Gargoyle", 2, 3),
        Enemy(10, 0, 5, 5, 5, "Mage", 2, 3),

        Enemy(10, 0, 5, 5, 10, "Kingsman", 3, 3),
        Enemy(10, 0, 5, 5, 5, "Dragon", 3, 3),
        Enemy(10, 0, 5, 5, 5, "Royal Mage", 3, 3),
        Enemy(10, 0, 5, 5, 5, "Great Shield", 3, 3),

        Enemy(10, 0, 5, 5, 10, "Bats", 1, 4),
        Enemy(10, 0, 5, 5, 5, "Skeleton", 1, 4),
        Enemy(10, 0, 5, 5, 5, "Guard", 1, 4),
        Enemy(10, 0, 5, 5, 5, "Archer", 1, 4),

        Enemy(10, 0, 5, 5, 10, "Knight", 2, 4),
        Enemy(10, 0, 5, 5, 5, "Guard Dog", 2, 4),
        Enemy(10, 0, 5, 5, 5, "Gargoyle", 2, 4),
        Enemy(10, 0, 5, 5, 5, "Mage", 2, 4),

        Enemy(10, 0, 5, 5, 10, "Kingsman", 3, 4),
        Enemy(10, 0, 5, 5, 5, "Dragon", 3, 4),
        Enemy(10, 0, 5, 5, 5, "Royal Mage", 3, 4),
        Enemy(10, 0, 5, 5, 5, "Great Shield", 3, 4),

        Enemy(10, 0, 5, 5, 10, "Bats", 1, 5),
        Enemy(10, 0, 5, 5, 5, "Skeleton", 1, 5),
        Enemy(10, 0, 5, 5, 5, "Guard", 1, 5),
        Enemy(10, 0, 5, 5, 5, "Archer", 1, 5),

        Enemy(10, 0, 5, 5, 10, "Knight", 2, 5),
        Enemy(10, 0, 5, 5, 5, "Guard Dog", 2, 5),
        Enemy(10, 0, 5, 5, 5, "Gargoyle", 2, 5),
        Enemy(10, 0, 5, 5, 5, "Mage", 2, 5),

        Enemy(10, 0, 5, 5, 10, "Kingsman", 3, 5),
        Enemy(10, 0, 5, 5, 5, "Dragon", 3, 5),
        Enemy(10, 0, 5, 5, 5, "Royal Mage", 3, 5),
        Enemy(10, 0, 5, 5, 5, "Great Shield", 3, 5)

    };
};
