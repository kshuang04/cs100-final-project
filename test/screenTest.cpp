#include "gtest/gtest.h"
#include "../header/screen.hpp"

TEST(LoseScreenTest, Lose)
{
    LoseScreen s;
    EXPECT_NO_THROW(s.printScreen());
}

TEST(MainMenuScreenTest, MainMenu)
{
    MainMenuScreen s;
    EXPECT_NO_THROW(s.printScreen());
}

TEST(WinScreenTest, Win)
{
    WinScreen s;
    EXPECT_NO_THROW(s.printScreen());
}

TEST(ShopScreenTest, Shop)
{
    Player* p = new Player();
    (*p).setGold(100);
    ShopScreen s = ShopScreen(p);
    EXPECT_NO_THROW(s.printScreen());
    delete p;
}

TEST(StatsScreenTest, Normal) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHPStat(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(StatsScreenTest, NegLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(-5);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHPStat(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(StatsScreenTest, PastMAXLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(30);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHPStat(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(StatsScreenTest, NegativeEXP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(-30);
    myPlayer->setHP(15);
    myPlayer->setMaxHPStat(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(StatsScreenTest, TooMuchEXPAndNotLeveledUp) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(2000);
    myPlayer->setHP(15);
    myPlayer->setMaxHPStat(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(StatsScreenTest, NegativeHP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(-5);
    myPlayer->setMaxHPStat(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(StatsScreenTest, ExtraHP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(30);
    myPlayer->setMaxHPStat(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(StatsScreenTest, NegAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHPStat(20);
    myPlayer->setAttackStat(-100);
    myPlayer->setDefenseStat(20);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(StatsScreenTest, NegDefenseStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHPStat(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(-50);
    PlayerStatsScreen s = PlayerStatsScreen(myPlayer);
    EXPECT_ANY_THROW(s.printScreen());
    delete myPlayer;
}

TEST(InvenScreenTest, BasicInventory)
{
    Player* p = new Player();
    PlayerInventoryScreen s = PlayerInventoryScreen(p);
    Item* i1 = new Item("test item 1", "test desc 1", 1, 1);
    Item* i2 = new Item("test item 2", "test desc 2", 1, 1);
    (*p).addItem(i1);
    (*p).addItem(i2);
    EXPECT_NO_THROW(s.printScreen());
    delete p;
}

TEST(InvenScreenTest, OneAttackItem) {
    Player* myPlayer = new Player();
    AttackItem* newAttackItem = new AttackItem(2, 1, "Attack Potion", 1, "Gives more strength");
    myPlayer->addItem(newAttackItem);
    EXPECT_EQ(newAttackItem->getAttackPower(), 2);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(InvenScreenTest, OneDefenseItem) {
    Player* myPlayer = new Player();
    DefenseItem* newDefenseItem = new DefenseItem(4, 1, "Defense Potion", 1, "Gives more defense");
    myPlayer->addItem(newDefenseItem);
    EXPECT_EQ(newDefenseItem->getDefensePower(), 4);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(InvenScreenTest, OneHealingPotItem) {
    Player* myPlayer = new Player();
    MaxHPPot* newHealingPotItem = new MaxHPPot(4, 1, "Health Potion", 1, "Gives more health");
    myPlayer->addItem(newHealingPotItem);
    EXPECT_EQ(newHealingPotItem->getHealthIncrease(), 4);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(InvenScreenTest, MultipleItems) {
    Player* myPlayer = new Player();
    AttackItem* newAttackItem = new AttackItem(2, 1, "Attack Potion", 1, "Gives more strength");
    myPlayer->addItem(newAttackItem);
    DefenseItem* newDefenseItem = new DefenseItem(4, 1, "Defense Potion", 1, "Gives more defense");
    myPlayer->addItem(newDefenseItem);
    MaxHPPot* newHealingPotItem = new MaxHPPot(4, 1, "Health Potion", 1, "Gives more health");
    myPlayer->addItem(newHealingPotItem);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(BattleScreenTest, StartBattle)
{
    Player* p = new Player();
    Level* l = new Level();
    BattleScreen b = BattleScreen(p, l);
    Enemy* e1 = new Enemy(50, 0, 10, 10, 10, "Dummy", 1, 1);
    Enemy* e2 = new Enemy(100, 0, 10, 10, 10, "Dum Dum", 1, 1);
    l->addEnemy(e1);
    l->addEnemy(e2);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete e1;
    delete e2;
    delete p;
}

TEST(BattleScreenTest, DamageEnemy)
{
    Player* p = new Player();
    Level* l = new Level();
    BattleScreen b = BattleScreen(p, l);
    Enemy* e1 = new Enemy(50, 0, 10, 10, 10, "Dummy", 1, 1);
    Enemy* e2 = new Enemy(100, 0, 10, 10, 10, "Dum Dum", 1, 1);
    l->addEnemy(e1);
    l->addEnemy(e2);
    e1->gotAttack(20);
    e2->gotAttack(20);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete e1;
    delete e2;
    delete p;
}

TEST(BattleScreenTest, DamagePlayer)
{
    Player* p = new Player();
    Level* l = new Level();
    BattleScreen b = BattleScreen(p, l);
    Enemy* e1 = new Enemy(50, 0, 10, 10, 10, "Dummy", 1, 1);
    Enemy* e2 = new Enemy(100, 0, 10, 10, 10, "Dum Dum", 1, 1);
    l->addEnemy(e1);
    l->addEnemy(e2);
    p->takeDamage(10);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete e1;
    delete e2;
    delete p;
}