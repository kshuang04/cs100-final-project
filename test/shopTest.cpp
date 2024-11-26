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

TEST(SellTest, SellNonexistentItem)
{
    
}

TEST(SellTest, SellSmallHealingItem)
{
    
}
TEST(SellTest, SellMaxHealingItem)
{
    
}

TEST(SellTest, SellAttackItem)
{
    
}

TEST(SellTest, SellDefenseItem)
{
    
}