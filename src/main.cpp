#include <iostream>
#include <time.h>

#include "../src/enemyManager.cpp"
#include "../header/chest.hpp"
#include "../header/enemy.hpp"
#include "../header/Item.hpp"
#include "../header/ItemInventory.hpp"
#include "../header/level.hpp"
#include "../header/Player.hpp"
#include "../header/screen.hpp"
#include "../header/shop.hpp"

using namespace std;

int main()
{

    Player player;
    srand(time(NULL));

    int options = 0;
    int levelNum = 1;
    int region = rand() % 5 + 1;


    MainMenuScreen menu;
    menu.printScreen();

    while (options != 1 && options != 2)
    {
        cin >> options;
    }

    if (options == 2)
    {
        return 0;
    }

    options = 0;

    while (levelNum <= 30)
    {
        level currLevel(levelNum, region);
        BattleScreen battle(&player, &currLevel);
     
        while (player.getHP() > 0 && !currLevel.returnEnemyVector().empty())
        {
            cout << "Stage: " << currLevel.getLevelNum() << endl;
            battle.printScreen();

            while (options != 1 && options != 2)
            {
                cin >> options;
            }

            if (options == 1)
            {
                (*currLevel.returnEnemyVectorP()).back().gotAttack(player.attack());
                if (currLevel.returnEnemyVector().back().getHealth() <= 0)
                {
                    currLevel.returnEnemyVectorP()->pop_back();
                }
            }
            else if (options == 2)
            {
                cout << "no items yet" << endl;
            }

            (*currLevel.returnEnemyVectorP()).back().attack(&player);
            options = 0;
        }

        if (player.getHP() <= 0)
        {
            LoseScreen lose;
            lose.printScreen();
            return 0;
        }
        else if (currLevel.returnEnemyVector().empty())
        {
            cout << "You win!" << endl;
        }

        levelNum++;
    }




    return 0;
}