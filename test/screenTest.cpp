#include "../header/screen.hpp"
#include "gtest/gtest.h"

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

TEST(ShopScreenTest, PrintShop)
{
    Player* p = new Player();
    (*p).setGold(100);
    ShopScreen s = ShopScreen(p);
    EXPECT_NO_THROW(s.printScreen());
    delete p;
}

TEST(ShopScreenTest, PrintInsufficientFunds)
{
    Player* p = new Player();
    ShopScreen s = ShopScreen(p);
    EXPECT_NO_THROW(s.printInsufficientFunds());
    delete p;
}

TEST(ShopScreenTest, PrintNonexistentItem)
{
    Player* p = new Player();
    ShopScreen s = ShopScreen(p);
    EXPECT_NO_THROW(s.printNonexistentItem());
    delete p;
}

TEST(ShopScreenTest, PrintSellScreen)
{
    Player* p = new Player();
    ShopScreen s = ShopScreen(p);
    EXPECT_NO_THROW(s.printSellScreen());
    delete p;
}

TEST(StatsScreenTest, Normal) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(5);
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
    myPlayer->setHP(50);
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

TEST(InvenScreenTest, OneAttackItem) {
    Player* myPlayer = new Player();
    AttackItem* newAttackItem = new AttackItem(2, 1, "Attack Potion", 1, "Gives more strength");
    myPlayer->getPlayerInven()->addItem(newAttackItem, myPlayer);
    EXPECT_EQ(newAttackItem->getAttackPower(), 2);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(InvenScreenTest, OneDefenseItem) {
    Player* myPlayer = new Player();
    DefenseItem* newDefenseItem = new DefenseItem(4, 1, "Defense Potion", 1, "Gives more defense");
    myPlayer->getPlayerInven()->addItem(newDefenseItem, myPlayer);
    EXPECT_EQ(newDefenseItem->getDefensePower(), 4);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(InvenScreenTest, OneHealingPotItem) {
    Player* myPlayer = new Player();
    MaxHPPot* newHealingPotItem = new MaxHPPot(4, 1, "Health Potion", 1, "Gives more health");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem, myPlayer);
    EXPECT_EQ(newHealingPotItem->getHealthIncrease(), 4);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(InvenScreenTest, MultipleItems) {
    Player* myPlayer = new Player();
    AttackItem* newAttackItem = new AttackItem(2, 1, "Attack Potion", 1, "Gives more strength");
    myPlayer->getPlayerInven()->addItem(newAttackItem, myPlayer);
    DefenseItem* newDefenseItem = new DefenseItem(4, 1, "Defense Potion", 1, "Gives more defense");
    myPlayer->getPlayerInven()->addItem(newDefenseItem, myPlayer);
    MaxHPPot* newHealingPotItem = new MaxHPPot(4, 1, "Health Potion", 1, "Gives more health");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem, myPlayer);
    PlayerInventoryScreen s = PlayerInventoryScreen(myPlayer);
    EXPECT_NO_THROW(s.printScreen());
    delete myPlayer;
}

TEST(BattleScreenTest, OneEnemy)
{
    Player* p = new Player();
    level* l = new level(1, 1);
    BattleScreen b = BattleScreen(p, l);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete p;
}

TEST(BattleScreenTest, TwoEnemies)
{
    Player* p = new Player();
    level* l = new level(4, 1);
    BattleScreen b = BattleScreen(p, l);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete p;
}

TEST(BattleScreenTest, ThreeEnemies)
{
    Player* p = new Player();
    level* l = new level(7, 1);
    BattleScreen b = BattleScreen(p, l);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete p;
}

TEST(BattleScreenTest, OneEnemyHighLvl)
{
    Player* p = new Player();
    level* l = new level(10, 1);
    BattleScreen b = BattleScreen(p, l);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete p;
}

TEST(BattleScreenTest, DamageOneEnemy)
{
    Player* p = new Player();
    level* l = new level(1, 1);
    BattleScreen b = BattleScreen(p, l);
    vector<Enemy>* list = l->returnEnemyVectorP();
    //Damage first enemy in vector
    list->at(0).gotAttack(100);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete p;
}

TEST(BattleScreenTest, DamageAllEnemies)
{
    Player* p = new Player();
    level* l = new level(7, 1);
    BattleScreen b = BattleScreen(p, l);
    vector<Enemy>* list = l->returnEnemyVectorP();
    //Damage all enemies in vector
    for (int i = 0; i < list->size(); i++)
    {
        list->at(i).gotAttack(100);
    }
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete p;
}

TEST(BattleScreenTest, DamagePlayer)
{
    Player* p = new Player();
    level* l = new level(1, 1);
    BattleScreen b = BattleScreen(p, l);
    //Damage player
    p->takeDamage(10);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete p;
}

TEST(BattleScreenTest, DamageEveryone)
{
    Player* p = new Player();
    level* l = new level(17, 1);
    BattleScreen b = BattleScreen(p, l);
    vector<Enemy>* list = l->returnEnemyVectorP();
    //Damage all enemies in vector
    for (int i = 0; i < list->size(); i++)
    {
        list->at(i).gotAttack(100);
    }
    //Damage player
    p->takeDamage(10);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete p;
}

TEST(BattleScreenTest, DamageEveryoneAfterPrinting)
{
    Player* p = new Player();
    level* l = new level(17, 1);
    BattleScreen b = BattleScreen(p, l);
    vector<Enemy>* list = l->returnEnemyVectorP();
    EXPECT_NO_THROW(b.printScreen());
    //Damage all enemies in vector
    for (int i = 0; i < list->size(); i++)
    {
        list->at(i).gotAttack(100);
    }
    //Damage player
    p->takeDamage(10);
    EXPECT_NO_THROW(b.printScreen());
    delete l;
    delete p;
}

TEST(PlayerMoveScreenTest, PlayerMoveAction)
{
    Player* p = new Player();
    level* l = new level(4, 1);
    BattleScreen b = BattleScreen(p, l);
    EXPECT_NO_THROW(b.printScreen());
    PlayerMoveScreen playerMove = PlayerMoveScreen(p, l);
    EXPECT_NO_THROW(playerMove.printScreen());
    delete l;
    delete p;
}

TEST(EnemyMoveScreenTest, EnemyMoveAction)
{
    Player* p = new Player();
    level* l = new level(4, 1);
    BattleScreen b = BattleScreen(p, l);
    EXPECT_NO_THROW(b.printScreen());
    EnemyMoveScreen enemyMove = EnemyMoveScreen(p, l);
    EXPECT_NO_THROW(enemyMove.printScreen());
    delete l;
    delete p;
}

TEST(CompleteStageScreenTest, Print)
{
    Player* p = new Player();
    CompleteStageScreen s;
    EXPECT_NO_THROW(s.printScreen());
    delete p;  
}