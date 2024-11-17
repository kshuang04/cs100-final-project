#include "gtest/gtest.h"
#include "../header/screen.hpp"

TEST(ScreenTest, Lose)
{
    LoseScreen s;
    EXPECT_NO_THROW(s.printScreen());
}

TEST(ScreenTest, MainMenu)
{
    MainMenuScreen s;
    EXPECT_NO_THROW(s.printScreen());
}

TEST(ScreenTest, Win)
{
    WinScreen s;
    EXPECT_NO_THROW(s.printScreen());
}

TEST(ScreenTest, Shop)
{
    Player* p = new Player();
    (*p).setGold(100);
    ShopScreen s = ShopScreen(p);
    EXPECT_NO_THROW(s.printScreen());
    delete p;
}

TEST(ScreenTest, Inventory)
{
    Player* p = new Player();
    PlayerInventoryScreen s = PlayerInventoryScreen(p);
    Item* i1 = new Item("test item 1", "test desc 1");
    Item* i2 = new Item("test item 2", "test desc 2");
    (*p).addItem(i1);
    (*p).addItem(i2);
    EXPECT_NO_THROW(s.printScreen());
    delete p;
}

TEST(ScreenTest, StatsNormal) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, StatsNegativeLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(-5);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, StatsPastMAXLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(30);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, StatsNegativeEXP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(-30);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, StatsTooMuchEXPAndNotLeveledUp) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(2000);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, StatsNegativeHP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(-5);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, StatsExtraHP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, StatsNegativeAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(-100);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, StatsNegativeDefenseStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(-50);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, InvenPrintAttackItem) {
    Player* myPlayer = new Player();
    AttackItem* newAttackItem = new AttackItem(2, 1, "+2 attack");
    myPlayer->addItem(newAttackItem);
    EXPECT_EQ(newAttackItem->getAttackPower(), 2);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, InvenPrintDefenseItem) {
    Player* myPlayer = new Player();
    DefenseItem* newDefenseItem = new DefenseItem(4, 1, "+4 defense");
    myPlayer->addItem(newDefenseItem);
    EXPECT_EQ(newDefenseItem->getDefensePower(), 4);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, InvenPrintHealingPotItem) {
    Player* myPlayer = new Player();
    MaxHPPot* newHealingPotItem = new MaxHPPot(4, 1, "+4 health");
    myPlayer->addItem(newHealingPotItem);
    EXPECT_EQ(newHealingPotItem->getHealthIncrease(), 4);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(ScreenTest, InvenPrintMultipleItems) {
    Player* myPlayer = new Player();
    AttackItem* newAttackItem = new AttackItem(2, 1, "+2 attack");
    myPlayer->addItem(newAttackItem);
    DefenseItem* newDefenseItem = new DefenseItem(4, 1, "+4 defense");
    myPlayer->addItem(newDefenseItem);
    MaxHPPot* newHealingPotItem = new MaxHPPot(4, 1, "+4 health");
    myPlayer->addItem(newHealingPotItem);
    EXPECT_EQ(newAttackItem->getAttackPower(), 2);
    EXPECT_EQ(newDefenseItem->getDefensePower(), 4);
    EXPECT_EQ(newHealingPotItem->getHealthIncrease(), 4);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}