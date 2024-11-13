#include "../header/level.hpp"

level::level() {
    insertEnemies();
}

//Check Enemy.txt
void level::insertEnemies() {

    //Basic (0 - 13)
    Enemy Goblin(3, 0, 2, 15, 20, "Goblin");
    Enemy Zombie(5, 2, 3, 30, 10, "Zombie");
    Enemy Imp(3, 0, 4, 30, 5, "Imp");
    Enemy Rat(5, 0, 3, 25, 5, "Rat");
    Enemy Slime(10, 0, 1, 20, 5, "Slime");
    Enemy Skeleton(2, 0, 5, 30, 5, "Skeleton");
    Enemy Bats(3, 0, 3, 15, 15, "Bat");

    Enemy Bandit(15, 5, 5, 50, 40, "Bandit");
    Enemy Mud_Golem(5, 10, 3, 30, 10, "Mud Golem");
    Enemy Flesh_Eating_Plant(10, 3, 10, 50, 25, "Flesh-Eating Plant");
    Enemy Float_Skull(5, 1, 12, 50, 40, "Floating Skull");

    Enemy Werewolf(20, 10, 10, 100, 45, "Werewolf");
    Enemy Fire_Elemental(20, 5, 15, 125, 40, "Fire Elemental");
    Enemy Dragonlings(40, 15, 20, 200, 60, "Dragonlings");


    //Elite (14 - 18)
    Enemy Troll(30, 9, 8, 100, 55, "Troll");
    Enemy Giant_Rat(30, 0, 8, 100, 35, "Giant Rat");
    Enemy Stone_Golem(20, 38, 7, 150, 50, "Stone_Golem");
    Enemy Witch(40, 3, 10, 200, 60, "Witch");
    Enemy Bandit_Leader(60, 20, 10, 200, 100, "Bandit Leader");
    Enemy Mimic(100, 10, 40, 1000, 500, "Mimic");

    //Boss (19 - 22)
    Enemy Dragon(150, 50, 37, 1000, 500, "Dragon");
    Enemy Phoenix(200, 10, 26, 1500, 350, "Phoenix");
    Enemy Lich(150, 2, 45, 1500, 200, "Lich");

    listOfEnemies[0] = Goblin;
    listOfEnemies[1] = Zombie;
    listOfEnemies[2] = Imp;
    listOfEnemies[3] = Rat;
    listOfEnemies[4] = Slime;
    listOfEnemies[5] = Skeleton;
    listOfEnemies[6] = Bats;
    listOfEnemies[7] = Bandit;
    listOfEnemies[8] = Mud_Golem;
    listOfEnemies[9] = Flesh_Eating_Plant;
    listOfEnemies[10] = Float_Skull;
    listOfEnemies[11] = Werewolf;
    listOfEnemies[12] = Fire_Elemental;
    listOfEnemies[13] = Dragonlings;
    listOfEnemies[14] = Troll;
    listOfEnemies[15] = Giant_Rat;
    listOfEnemies[16] = Stone_Golem;
    listOfEnemies[17] = Witch;
    listOfEnemies[18] = Bandit_Leader;
    listOfEnemies[19] = Mimic;
    listOfEnemies[20] = Dragon;
    listOfEnemies[21] = Phoenix;
}