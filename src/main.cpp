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
    bool gameIsOn = true;

    double options = 0.0;

    MainMenuScreen menu;
    menu.printScreen();

    cin >> options;

    while ((options != 1.0 && options != 2.0) || cin.fail())
    {
        cout << "That is an invalid choice. Please try again.\n";
        cin.clear();
        cin.ignore(2147483647, '\n');
        cin >> options;
    }

    while (true) {
        Player player;

        srand(time(NULL));

        int levelNum = 1;
        int region = rand() % 5 + 1;

        if (options == 2.0)
        {
            return 0;
        }

        cin.clear();
        cin.ignore(2147483647, '\n');
        options = 0;

        while (levelNum <= 30)
        {
            level currLevel(levelNum, region);
            BattleScreen battle(&player, &currLevel);

            int goldGain = currLevel.getTotalGold();
            int expGain = currLevel.getTotalEXP();
        
            while (player.getHP() > 0 && !currLevel.returnEnemyVector().empty())
            {
                cout << "Stage: " << currLevel.getLevelNum() << endl;
                battle.printScreen();

                cin >> options;

                while ((options != 1.0 && options != 2.0) || cin.fail())
                {
                    cout << "That is an invalid choice. Please try again.\n";
                    cin.clear();
                    cin.ignore(2147483647, '\n');
                    cin >> options;
                }

                if (options == 1.0)
                {
                    (*currLevel.returnEnemyVectorP()).back().gotAttack(player.attack());
                    if (currLevel.returnEnemyVector().back().getHealth() <= 0)
                    {
                        currLevel.returnEnemyVectorP()->pop_back();
                    }
                }
                else if (options == 2.0)
                {
                    if (player.getPlayerInven()->healingPotExists()) {
                        if ((player.getHP() + player.getPlayerInven()->getNextHealingPot()->getHealthIncrease()) >= player.getMaxHP()) {
                            cout << "You consumed " << player.getPlayerInven()->getNextHealingPot()->getItemName() << ". HP maxed out." << endl;
                        } else {
                            cout << "You consumed " << player.getPlayerInven()->getNextHealingPot()->getItemName() << ". Gained " << player.getPlayerInven()->getNextHealingPot()->getHealthIncrease() << " HP." << endl;
                        }
                        player.getPlayerInven()->consumeNextHealingPot(&player);
                    } else {
                        cout << "No items to consume yet." << endl;
                    }
                }

                if ((*currLevel.returnEnemyVectorP()).size() > 0)
                {
                    (*currLevel.returnEnemyVectorP()).back().attack(&player);
                
                }
                options = 0;
            }

            if (player.getHP() <= 0)
            {
                LoseScreen lose;
                lose.printScreen();
                cin >> options;
                while ((options != 1.0 && options != 2.0) || cin.fail())
                {
                    cout << "That is an invalid choice. Please try again.\n";
                    cin.clear();
                    cin.ignore(2147483647, '\n');
                    cin >> options;
                }
                if (options == 2.0)
                {
                    gameIsOn = false;
                    return 0;
                } else {
                    player.resetStats();
                    break;
                }
            }
            else if (currLevel.returnEnemyVector().empty())
            {
                if (currLevel.getLevelNum() == 30) {break;}
                CompleteStageScreen complete;
                complete.printScreen();
                player.changeGold(goldGain);
                player.changeEXP(expGain);
            }

            cin.clear();
            cin.ignore(2147483647, '\n');
            options = 0;

            while (options != 4)
            {
                
                cin >> options;

                while ((options != 1.0 && options != 2.0 && options != 3.0 && options != 4.0) || cin.fail())
                {
                    cout << "That is an invalid choice. Please try again.\n";
                    cin.clear();
                    cin.ignore(2147483647, '\n');
                    cin >> options;
                }

                //check stats
                if (options == 1.0)
                {
                    PlayerStatsScreen stats(&player);
                    stats.printScreen();
                }
                //check inven
                else if (options == 2.0)
                {
                    PlayerInventoryScreen inventory(&player);
                    inventory.printScreen();
                    if (player.getPlayerInven()->getItemCount() == 0)
                    {
                        cout << "You have no items." << endl;
                    }
                }
                //visit shop
                else if (options == 3.0)
                {
                    ShopScreen shopScreen(&player);
                    shopScreen.printScreen();
                    options = 0.0;

                    while (options != 6.0)
                    {
                        Shop shop(&player);
                        options = 0;
                        cin >> options;
                        while ((options != 1.0 && options != 2.0 && options != 3.0 && options != 4.0 && options != 5.0 && options != 6.0) || cin.fail())
                        {
                            cout << "That is an invalid choice. Please try again.\n";
                            cin.clear();
                            cin.ignore(2147483647, '\n');
                            cin >> options;
                        }
                        if (options == 6.0)
                        {
                            break;
                        }
                        try
                        {
                            //buy small heal
                            if (options == 1.0)
                            {
                                shop.purchaseSmallHealthItem();
                            }
                            //buy max heal
                            else if (options == 2.0)
                            {
                                shop.purchaseMaxHealthItem();
                                
                            }
                            //buy attack pot
                            else if (options == 3.0)
                            {
                                shop.purchaseAttackItem();
                            }
                            //buy defense pot
                            else if (options == 4.0)
                            {
                                shop.purchaseDefenseItem();
                            }
                            //sell item
                            else if (options == 5.0)
                            {
                                shopScreen.printSellScreen(); //print screen to show player what options they have to sell

                                options = 0;

                                while (options != 5.0)
                                {
                                    options = 0;

                                    while (options != 1.0 && options != 2.0 && options != 3.0 && options != 4.0 && options != 5.0)
                                    {
                                        cin.clear();
                                        cin.ignore(2147483647, '\n');
                                        cin >> options;
                                    }
                                    //sell small heal
                                    if (options == 1.0)
                                    {
                                        shop.sellSmallHealthItem();
                                        break;
                                    }
                                    //sell max heal
                                    else if (options == 2.0)
                                    {
                                        shop.sellMaxHealthItem();
                                        break;
                                    }
                                    //sell attack pot
                                    else if (options == 3.0)
                                    {
                                        shop.sellAttackItem();
                                        break;
                                    }
                                    //sell defense pot
                                    else if (options == 4.0)
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
                } else {
                    break;
                }

                PlayerMenuScreen playermenu;
                playermenu.printScreen();
            }

            levelNum++;
        }

        if (!gameIsOn) {
            break;
        }

        if (levelNum > 30) {

            options = 0.0;

            WinScreen win;
            win.printScreen();

            cin >> options;

            while ((options != 1.0 && options != 2.0) || cin.fail())
            {
                cout << "That is an invalid choice. Please try again.\n";
                cin.clear();
                cin.ignore(2147483647, '\n');
                cin >> options;
            }

            player.resetStats();

            if (options == 2.0) {
                break;
            }
        }

        options = 0.0;

    }

    return 0;
}