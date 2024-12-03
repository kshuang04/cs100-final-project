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
                if (player.getPlayerInven()->healingPotExists()) {
                    player.getPlayerInven()->consumeNextHealingPot(&player);
                } else {
                    cout << "no items to consume yet" << endl;
                }
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
                ShopScreen shopScreen(&player);
                shopScreen.printScreen();
                options = 0;

                while (options != 6)
                {
                    Shop shop(&player);
                    options = 0;
                    while (options < 1 || options > 6)
                    {
                        cin >> options;
                    }
                    if (options == 6)
                    {
                        break;
                    }
                    try
                    {
                        //buy small heal
                        if (options == 1)
                        {
                            shop.purchaseSmallHealthItem();
                        }
                        //buy max heal
                        else if (options == 2)
                        {
                            shop.purchaseMaxHealthItem();
                            
                        }
                        //buy attack pot
                        else if (options == 3)
                        {
                            shop.purchaseAttackItem();
                        }
                        //buy defense pot
                        else if (options == 4)
                        {
                            shop.purchaseDefenseItem();
                        }
                        //sell item
                        else if (options == 5)
                        {
                            shopScreen.printSellScreen(); //print screen to show player what options they have to sell

                            options = 0;

                            while (options != 5)
                            {
                                options = 0;

                                while (options < 1 || options > 5)
                                {
                                    cin >> options;
                                }
                                //sell small heal
                                if (options == 1)
                                {
                                    shop.sellSmallHealthItem();
                                    break;
                                }
                                //sell max heal
                                else if (options == 2)
                                {
                                    shop.sellMaxHealthItem();
                                    break;
                                }
                                //sell attack pot
                                else if (options == 3)
                                {
                                    shop.sellAttackItem();
                                    break;
                                }
                                //sell defense pot
                                else if (options == 4)
                                {
                                    shop.sellDefenseItem();
                                    break;
                                }
                            }
                        }
                    }
                    catch(const InsufficientFundsException& e)
                    {
                        shopScreen.printInsufficientFunds();
                    }
                    catch(const NonexistentItemException& e)
                    {
                        shopScreen.printNonexistentItem();
                    }
                    shopScreen.printScreen();
                }
            }
            options = 0;
        }

        levelNum++;
    }




    return 0;
}