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
        throw logic_error("Not enough gold to make purchase");
    }
    else
    {
        player->setGold(player->getGold() - smallHealthItemPrice); //deduct gold from player
        HealingPot* newHealingItem = new HealingPot(5, 1, "TestSmallHealingPot", 1, "TestSmallHeal descrip"); //create and add new test item to player inventory
        player->getPlayerInven()->addItem(newHealingItem, player); 
    }
}

void Shop::purchaseMaxHealthItem()
{
    //check to see if player has enough gold to buy item
    if (player->getGold() < maxHealthItemPrice)
    {
        throw logic_error("Not enough gold to make purchase");
    }
    else
    {
        player->setGold(player->getGold() - maxHealthItemPrice); //deduct gold from player
        MaxHPPot* newHealingItem = new MaxHPPot(5, 1, "TestMaxHealingPot", 1, "TestMaxHeal descrip"); //create and add new test item to player inventory
        player->getPlayerInven()->addItem(newHealingItem, player); 
    }
}

void Shop::purchaseAttackItem()
{
    //check to see if player has enough gold to buy item
    if (player->getGold() < attackItemPrice)
    {
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
    //check to see if player has enough gold to buy item
    if (player->getGold() < attackItemPrice)
    {
        throw logic_error("Not enough gold to make purchase");
    }
    else
    {
        player->setGold(player->getGold() - defenseItemPrice); //deduct gold from player
        DefenseItem* newDefenseItem = new DefenseItem(4, 1, "TestDefenseItem", 2, "TestDefenseItem descrip"); //create and add new test item to player inventory
        player->getPlayerInven()->addItem(newDefenseItem, player);
    }
}

void Shop::sellSmallHealthItem()
{
    //check to see if player has this item to sell
    int currIndex;
    for (currIndex = 0; currIndex < player->getPlayerInven()->getItemInven().size(); currIndex++) //loop through player's inventory vector
    {
        if (typeid(HealingPot) == typeid(*(player->getPlayerInven()->getItemInven().at(currIndex))))
        {
            player->setGold(player->getGold() + smallHealthItemPrice); //increase players gold by item's price
            player->getPlayerInven()->removeItem(currIndex); //remove item from player's inventory
            return;
        }
    }
    //will throw error if no item of same type is found
    throw logic_error("Trying to sell an item player doesn't have");
}

void Shop::sellMaxHealthItem()
{
    //check to see if player has this item to sell
    int currIndex;
    for (currIndex = 0; currIndex < player->getPlayerInven()->getItemInven().size(); currIndex++) //loop through player's inventory vector
    {
        if (typeid(MaxHPPot) == typeid(*(player->getPlayerInven()->getItemInven().at(currIndex))))
        {
            player->setGold(player->getGold() + maxHealthItemPrice); //increase players gold by item's price
            player->getPlayerInven()->removeItem(currIndex); //remove item from player's inventory
            return;
        }
    }
    //will throw error if no item of same type is found
    throw logic_error("Trying to sell an item player doesn't have");

}

void Shop::sellAttackItem()
{
    //check to see if player has this item to sell
    int currIndex;
    for (currIndex = 0; currIndex < player->getPlayerInven()->getItemInven().size(); currIndex++) //loop through player's inventory vector
    {
        if (typeid(AttackItem) == typeid(*(player->getPlayerInven()->getItemInven().at(currIndex))))
        {
            player->setGold(player->getGold() + attackItemPrice); //increase players gold by item's price
            player->getPlayerInven()->removeItem(currIndex); //remove item from player's inventory
            return;
        }
    }
    //will throw error if no item of same type is found
    throw logic_error("Trying to sell an item player doesn't have");

}

void Shop::sellDefenseItem()
{
    //check to see if player has this item to sell
    int currIndex;
    for (currIndex = 0; currIndex < player->getPlayerInven()->getItemInven().size(); currIndex++) //loop through player's inventory vector
    {
        if (typeid(DefenseItem) == typeid(*(player->getPlayerInven()->getItemInven().at(currIndex))))
        {
            player->setGold(player->getGold() + defenseItemPrice); //increase players gold by item's price
            player->getPlayerInven()->removeItem(currIndex); //remove item from player's inventory
            return;
        }
    }
    //will throw error if no item of same type is found
    throw logic_error("Trying to sell an item player doesn't have");
}