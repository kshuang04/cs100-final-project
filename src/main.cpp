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
            CompleteStageScreen complete;
            complete.printScreen();
        }

        cin >> options;

        while (options != 4)
        {
            while (options < 1 || options > 4)
            {
                cin >> options;
            }

            //check stats
            if (options == 1)
            {
                PlayerStatsScreen stats(&player);
                stats.printScreen();
            }
            //check inven
            else if (options == 2)
            {
                PlayerInventoryScreen inventory(&player);
                inventory.printScreen();
                if (player.getPlayerInven()->getItemCount() == 0)
                {
                    cout << "You have no items." << endl;
                }
            }
            //visit shop
            else if (options == 3)
            {
                ShopScreen shop(&player);
                shop.printScreen();
                options = 0;

                while (options != 6)
                {
                    while (options < 1 || options > 6)
                    {
                        cin >> options;
                    }
                    //small heal
                    if (options == 1)
                    {

                    }
                    //max heal
                    else if (options == 2)
                    {

                    }
                    //attack pot
                    else if (options == 3)
                    {

                    }
                    //defense pot
                    else if (options == 4)
                    {

                    }
                    //sell item
                    else if (options == 5)
                    {
                        if (player.getPlayerInven()->getItemCount() == 0)
                        {
                            cout << "You have no items." << endl;
                        }
                    }
                }
            }
            options = 0;
        }

        levelNum++;
    }




    return 0;
}