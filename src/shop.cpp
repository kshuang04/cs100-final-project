#include "../header/shop.hpp"

Shop::Shop(Player* player)
{
    this->player = player;
}

void Shop::purchaseSmallHealthItem()
{
    //check to see if player has enough gold to buy item
    if (player->getGold() < smallHealthItemPrice)
    {
        //cout << "Not enough gold to make purchase! Please select another option:" << endl;
        throw logic_error("Not enough gold to make purchase");
    }
    else
    {
        player->setGold(player->getGold() - smallHealthItemPrice); //deduct gold from player
        HealingPot* newHealingItem = new HealingPot(5, 1, "TestSmallHealingPot", 1, "Test descrip"); //create and add new test item to player inventory
        player->getPlayerInven()->addItem(newHealingItem, player); 
    }
}

void Shop::purchaseMaxHealthItem()
{

}

void Shop::purchaseAttackItem()
{
    //check to see if player has enough gold to buy item
    if (player->getGold() < attackItemPrice)
    {
        //cout << "Not enough gold to make purchase! Please select another option:" << endl;
        throw logic_error("Not enough gold to make purchase");
    }
    else
    {
        player->setGold(player->getGold() - attackItemPrice); //deduct gold from player
        AttackItem* newAttackItem = new AttackItem(2, 1, "TestAttackItem", 1, "TestAttackItem descrip"); //create and add new test item to player inventory
        player->getPlayerInven()->addItem(newAttackItem, player);
    }
}

void Shop::purchaseDefenseItem()
{

}

void Shop::sellSmallHealthItem()
{

}

void Shop::sellMaxHealthItem()
{

}

void Shop::sellAttackItem()
{

}

void Shop::sellDefenseItem()
{

}