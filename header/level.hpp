#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "../header/enemy.hpp"

class level {
    private:
        /*
        Check Enemy.txt
        There is currently 23
        can just hardcode the array size lol
        */
        void insertEnemies();
        Enemy listOfEnemies[23];

        /*
        When doing the actual enemy generation
        use modulo and base it off the current level

        Ex. if its level 5, can spawn an elite enemy
        Ex. 1-10 level should only have "early enemy"
            While 11-20 have "mid" enemy

        
        */
    public:
        level();

};

#endif