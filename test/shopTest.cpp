#include "../header/shop.hpp"
#include "gtest/gtest.h"

TEST(PurchaseTest, InsufficientGold)
{
    Player* player = new Player();
    Shop shop(player);
    EXPECT_ANY_THROW(shop.purchaseAttackItem());
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 0);
    delete player;
}

TEST(PurchaseTest, PurchaseSmallHealthItem)
{
    Player* player = new Player();
    player->setGold(100);
    Shop shop(player);
    EXPECT_NO_THROW(shop.purchaseSmallHealthItem());
    EXPECT_TRUE(player->getGold() < 100);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 1);
    delete player;
}

TEST(PurchaseTest, PurchaseMaxHealthItem)
{
    Player* player = new Player();
    player->setGold(100);
    Shop shop(player);
    EXPECT_NO_THROW(shop.purchaseMaxHealthItem());
    EXPECT_TRUE(player->getGold() < 100);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 1);
    delete player;
}

TEST(PurchaseTest, PurchaseAttackItem)
{
    Player* player = new Player();
    player->setGold(100);
    Shop shop(player);
    EXPECT_NO_THROW(shop.purchaseAttackItem());
    EXPECT_TRUE(player->getGold() < 100);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 1);
    delete player;
}

TEST(PurchaseTest, PurchaseDefenseItem)
{
    Player* player = new Player();
    player->setGold(100);
    Shop shop(player);
    EXPECT_NO_THROW(shop.purchaseDefenseItem());
    EXPECT_TRUE(player->getGold() < 100);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 1);
    delete player;
}

TEST(PurchaseTest, PurchaseMultipleItems)
{
    Player* player = new Player();
    player->setGold(100);
    Shop shop(player);
    EXPECT_NO_THROW(shop.purchaseAttackItem());
    EXPECT_NO_THROW(shop.purchaseDefenseItem());
    EXPECT_NO_THROW(shop.purchaseAttackItem());
    EXPECT_TRUE(player->getGold() < 100);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 3);
    delete player;
}

TEST(PurchaseTest, PurchaseMultipleItemsGoingBroke)
{
    Player* player = new Player();
    player->setGold(5);
    Shop shop(player);
    EXPECT_NO_THROW(shop.purchaseAttackItem());
    EXPECT_ANY_THROW(shop.purchaseDefenseItem());
    EXPECT_ANY_THROW(shop.purchaseAttackItem());
    EXPECT_TRUE(player->getGold() < 100);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 1);
    delete player;
}

TEST(SellTest, SellSmallHealingItem)
{
    Player* player = new Player();
    HealingPot* newHealingPotItem = new HealingPot(2, 1, "TestSmallHealPot", 1, "SmallHealTest descrip");
    player->getPlayerInven()->addItem(newHealingPotItem, player);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 1);

    Shop shop(player);
    EXPECT_NO_THROW(shop.sellSmallHealthItem());
    EXPECT_TRUE(player->getGold() > 0);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 0);
    delete player;
}

TEST(SellTest, SellMaxHealingItem)
{
    Player* player = new Player();
    MaxHPPot* newHealingPotItem = new MaxHPPot(4, 1, "TestMaxHealthPotion", 1, "MaxHealTest descrip");
    player->getPlayerInven()->addItem(newHealingPotItem, player);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 1);

    Shop shop(player);
    EXPECT_NO_THROW(shop.sellMaxHealthItem());
    EXPECT_TRUE(player->getGold() > 0);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 0);
    delete player;
}

TEST(SellTest, SellAttackItem)
{
    Player* player = new Player();
    AttackItem* testAttackItem = new AttackItem(2, 1, "TestAttackItem", 1, "TestAttackItem descrip");
    player->getPlayerInven()->addItem(testAttackItem, player);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 1);

    Shop shop(player);
    EXPECT_NO_THROW(shop.sellAttackItem());
    EXPECT_TRUE(player->getGold() > 0);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 0);
    delete player;
}

TEST(SellTest, SellDefenseItem)
{
    Player* player = new Player();
    DefenseItem* newDefenseItem = new DefenseItem(4, 1, "TestDefenseItem", 1, "TestDefenseItem descrip");
    player->getPlayerInven()->addItem(newDefenseItem, player);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 1);

    Shop shop(player);
    EXPECT_NO_THROW(shop.sellDefenseItem());
    EXPECT_TRUE(player->getGold() > 0);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 0);
    delete player;
}

TEST(SellTest, SellOneItemInListOfItems)
{
    Player* player = new Player();
    DefenseItem* newDefenseItem = new DefenseItem(4, 1, "Defense Potion", 1, "Gives more defense");
    player->getPlayerInven()->addItem(newDefenseItem, player);
    AttackItem* testAttackItem = new AttackItem(2, 1, "TestAttackItem", 1, "TestAttackItem descrip");
    player->getPlayerInven()->addItem(testAttackItem, player);
    MaxHPPot* newHealingPotItem = new MaxHPPot(4, 1, "Health Potion", 1, "Gives more health");
    player->getPlayerInven()->addItem(newHealingPotItem, player);
    AttackItem* testAttackItem2 = new AttackItem(2, 1, "TestAttackItem", 1, "TestAttackItem descrip");
    player->getPlayerInven()->addItem(testAttackItem2, player);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 4);

    Shop shop(player);
    EXPECT_NO_THROW(shop.sellAttackItem());
    EXPECT_TRUE(player->getGold() > 0);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 3);
    EXPECT_TRUE(player->getPlayerInven()->getItemInven().size() == 3);
    delete player;
}

TEST(SellTest, SellNonexistentItem)
{
    Player* player = new Player();
    Shop shop(player);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 0);
    EXPECT_ANY_THROW(shop.sellSmallHealthItem());
    EXPECT_ANY_THROW(shop.sellMaxHealthItem());
    EXPECT_ANY_THROW(shop.sellAttackItem());
    EXPECT_ANY_THROW(shop.sellDefenseItem());
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 0);
    EXPECT_TRUE(player->getGold() == 0);
    delete player;
}

TEST(SellTest, SellNonexistentItemInListFullOfItems)
{
    Player* player = new Player();
    DefenseItem* newDefenseItem = new DefenseItem(4, 1, "Defense Potion", 1, "Gives more defense");
    player->getPlayerInven()->addItem(newDefenseItem, player);
    MaxHPPot* newHealingPotItem = new MaxHPPot(4, 1, "Health Potion", 1, "Gives more health");
    player->getPlayerInven()->addItem(newHealingPotItem, player);
    MaxHPPot* anotherHealingPotItem = new MaxHPPot(4, 1, "Health Potion", 1, "Gives more health");
    player->getPlayerInven()->addItem(anotherHealingPotItem, player);
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 3);
    Shop shop(player);
    EXPECT_ANY_THROW(shop.sellAttackItem());
    EXPECT_TRUE(player->getPlayerInven()->getItemCount() == 3);
    delete player;
}