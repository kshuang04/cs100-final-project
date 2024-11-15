#include "gtest/gtest.h"
#include "../header/Player.hpp"
#include "../stubs/AttackItemStub.hpp"
#include "../stubs/DefenseItemStub.hpp"
#include "../stubs/HealthItemStub.hpp"
#include "../stubs/HealingPotStub.hpp"
#include "../stubs/MaxHPPotStub.hpp"

TEST(ChangeEXPTests, IncreaseEXPForButNoLevelIncrease) {
    Player* myPlayer = new Player();
    myPlayer->changeEXP(50);
    EXPECT_EQ(myPlayer->getLevel(), 1);
    EXPECT_EQ(myPlayer->getEXP(), 50);
    delete myPlayer;
}

TEST(ChangeEXPTests, IncreaseEXPForOneLevel) {
    Player* myPlayer = new Player();
    myPlayer->changeEXP(150);
    EXPECT_EQ(myPlayer->getLevel(), 2);
    EXPECT_EQ(myPlayer->getEXP(), 50);
    delete myPlayer;
}

TEST(ChangeEXPTests, IncreaseEXPForTwoLevels) {
    Player* myPlayer = new Player();
    myPlayer->changeEXP(250);
    EXPECT_EQ(myPlayer->getLevel(), 3);
    EXPECT_EQ(myPlayer->getEXP(), 25);
    delete myPlayer;
}

TEST(ChangeEXPTests, IncreaseEXPStartingDifferentLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(5);
    myPlayer->changeEXP(2500);
    EXPECT_EQ(myPlayer->getLevel(), 10);
    EXPECT_EQ(myPlayer->getEXP(), 550);
    delete myPlayer;
}

TEST(ChangeEXPTests, IncreaseEXPAtMaxLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(20);
    myPlayer->changeEXP(10000);
    EXPECT_EQ(myPlayer->getLevel(), 20);
    EXPECT_EQ(myPlayer->getEXP(), 0);
    delete myPlayer;
}

TEST(ChangeEXPTests, IncreaseEXPBeyondMaxLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(19);
    myPlayer->changeEXP(7500);
    EXPECT_EQ(myPlayer->getLevel(), 20);
    EXPECT_EQ(myPlayer->getEXP(), 0);
    delete myPlayer;
}

TEST(ChangeEXPTests, IncreaseNegativeEXP) {
    Player* myPlayer = new Player();
    EXPECT_ANY_THROW(myPlayer->changeEXP(-50););
    delete myPlayer;
}

TEST(PrintStatsTests, normalPlayerStats) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    EXPECT_NO_THROW(myPlayer->printStats(););
    delete myPlayer;
}

TEST(PrintStatsTests, negativeLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(-5);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer->printStats(););
    delete myPlayer;
}

TEST(PrintStatsTests, pastMAXLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(30);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer->printStats(););
    delete myPlayer;
}

TEST(PrintStatsTests, negativeEXP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(-30);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer->printStats(););
    delete myPlayer;
}

TEST(PrintStatsTests, tooMuchEXPAndNotLeveledUp) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(2000);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer->printStats(););
    delete myPlayer;
}

TEST(PrintStatsTests, negativeHP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(-5);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer->printStats(););
    delete myPlayer;
}

TEST(PrintStatsTests, extraHP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer->printStats(););
    delete myPlayer;
}

TEST(PrintStatsTests, negativeAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(-100);
    myPlayer->setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer->printStats(););
    delete myPlayer;
}

TEST(PrintStatsTests, negativeDefenseStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(2);
    myPlayer->setMaxLevel(20);
    myPlayer->setEXP(50);
    myPlayer->setHP(15);
    myPlayer->setMaxHP(20);
    myPlayer->setAttackStat(25);
    myPlayer->setDefenseStat(-50);
    EXPECT_ANY_THROW(myPlayer->printStats(););
    delete myPlayer;
}

TEST(PrintItemIvenTests, PrintAttackItem) {
    Player* myPlayer = new Player();
    AttackItemStub* newAttackItem = new AttackItemStub("Strength", 25, "Makes you muscular.");
    myPlayer->addItem(newAttackItem);
    EXPECT_EQ(newAttackItem->getAttackPower(), 25);
    EXPECT_NO_THROW(myPlayer->printInven(););
    delete myPlayer;
}

TEST(PrintItemIvenTests, PrintDefenseItem) {
    Player* myPlayer = new Player();
    DefenseItemStub* newDefenseItem = new DefenseItemStub("Shield", 20, "Creates a shield around you.");
    myPlayer->addItem(newDefenseItem);
    EXPECT_EQ(newDefenseItem->getDefensePower(), 20);
    EXPECT_NO_THROW(myPlayer->printInven(););
    delete myPlayer;
}

TEST(PrintItemIvenTests, PrintHealingPotItem) {
    Player* myPlayer = new Player();
    HealingPotStub* newHealingPotItem = new HealingPotStub("Healing Pot", 18, "Looks like green hot chocolate.");
    myPlayer->addItem(newHealingPotItem);
    EXPECT_EQ(newHealingPotItem->getHPPower(), 18);
    EXPECT_NO_THROW(myPlayer->printInven(););
    delete myPlayer;
}

TEST(PrintItemIvenTests, PrintMaxHPPotItem) {
    Player* myPlayer = new Player();
    MaxHPPotStub* newMaxHPPotItem = new MaxHPPotStub("Max HP Pot Deluxe", 12, "Looks like strawberry jam.");
    myPlayer->addItem(newMaxHPPotItem);
    EXPECT_EQ(newMaxHPPotItem->getMaxHPPower(), 12);
    EXPECT_NO_THROW(myPlayer->printInven(););
    delete myPlayer;
}

TEST(PrintItemIvenTests, PrintMultipleItems) {
    Player* myPlayer = new Player();
    AttackItemStub* newAttackItem = new AttackItemStub("Strength", 25, "Makes you muscular.");
    myPlayer->addItem(newAttackItem);
    DefenseItemStub* newDefenseItem = new DefenseItemStub("Shield", 20, "Creates a shield around you.");
    myPlayer->addItem(newDefenseItem);
    HealingPotStub* newHealingPotItem = new HealingPotStub("Healing Pot", 18, "Looks like green hot chocolate.");
    myPlayer->addItem(newHealingPotItem);
    MaxHPPotStub* newMaxHPPotItem = new MaxHPPotStub("Max HP Pot Deluxe", 12, "Looks like strawberry jam.");
    myPlayer->addItem(newMaxHPPotItem);
    EXPECT_EQ(newAttackItem->getAttackPower(), 25);
    EXPECT_EQ(newDefenseItem->getDefensePower(), 20);
    EXPECT_EQ(newHealingPotItem->getHPPower(), 18);
    EXPECT_EQ(newMaxHPPotItem->getMaxHPPower(), 12);
    EXPECT_NO_THROW(myPlayer->printInven(););
    delete myPlayer;
}

TEST(UseItemTests, UseAttackItem) {
    Player* myPlayer = new Player();
    myPlayer->setAttackStat(15);
    myPlayer->setDefenseStat(15);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(45);
    AttackItemStub* newAttackItem = new AttackItemStub("Strength", 25, "Makes you muscular.");
    myPlayer->addItem(newAttackItem);
    myPlayer->consumeItem(1);
    EXPECT_EQ(myPlayer->getAttackStat(), 40);
    EXPECT_EQ(myPlayer->getDefenseStat(), 15);
    EXPECT_EQ(myPlayer->getHP(), 30);
    EXPECT_EQ(myPlayer->getMaxHP(), 45);
    delete myPlayer;
}

TEST(UseItemTests, UseDefenseItem) {
    Player* myPlayer = new Player();
    myPlayer->setAttackStat(15);
    myPlayer->setDefenseStat(15);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(45);
    DefenseItemStub* newDefenseItem = new DefenseItemStub("Shield", 20, "Creates a shield around you.");
    myPlayer->addItem(newDefenseItem);
    myPlayer->consumeItem(1);
    EXPECT_EQ(myPlayer->getAttackStat(), 15);
    EXPECT_EQ(myPlayer->getDefenseStat(), 35);
    EXPECT_EQ(myPlayer->getHP(), 30);
    EXPECT_EQ(myPlayer->getMaxHP(), 45);
    delete myPlayer;
}

TEST(UseItemTests, UseHealingPotItemButHPExceedsMaxHP) {
    Player* myPlayer = new Player();
    myPlayer->setAttackStat(15);
    myPlayer->setDefenseStat(15);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(45);
    HealingPotStub* newHealingPotItem = new HealingPotStub("Healing Pot", 18, "Looks like green hot chocolate.");
    myPlayer->addItem(newHealingPotItem);
    myPlayer->consumeItem(1);
    EXPECT_EQ(myPlayer->getAttackStat(), 15);
    EXPECT_EQ(myPlayer->getDefenseStat(), 15);
    EXPECT_EQ(myPlayer->getHP(), 45);
    EXPECT_EQ(myPlayer->getMaxHP(), 45);
    delete myPlayer;
}

TEST(UseItemTests, UseHealingPotItemButHPDoesNotExceedsMaxHP) {
    Player* myPlayer = new Player();
    myPlayer->setAttackStat(15);
    myPlayer->setDefenseStat(15);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(45);
    HealingPotStub* newHealingPotItem = new HealingPotStub("Healing Pot", 12, "Looks like green hot chocolate.");
    myPlayer->addItem(newHealingPotItem);
    myPlayer->consumeItem(1);
    EXPECT_EQ(myPlayer->getAttackStat(), 15);
    EXPECT_EQ(myPlayer->getDefenseStat(), 15);
    EXPECT_EQ(myPlayer->getHP(), 42);
    EXPECT_EQ(myPlayer->getMaxHP(), 45);
    delete myPlayer;
}

TEST(UseItemTests, UsingMaxHPPotItem) {
    Player* myPlayer = new Player();
    myPlayer->setAttackStat(15);
    myPlayer->setDefenseStat(15);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(45);
    MaxHPPotStub* newMaxHPPotItem = new MaxHPPotStub("Max HP Pot Deluxe", 12, "Looks like strawberry jam.");
    myPlayer->addItem(newMaxHPPotItem);
    myPlayer->consumeItem(1);
    EXPECT_EQ(myPlayer->getAttackStat(), 15);
    EXPECT_EQ(myPlayer->getDefenseStat(), 15);
    EXPECT_EQ(myPlayer->getHP(), 30);
    EXPECT_EQ(myPlayer->getMaxHP(), 57);
    delete myPlayer;
}

TEST(UseItemTests, UsingMultipleItemsCase1) {
    Player* myPlayer = new Player();
    myPlayer->setAttackStat(15);
    myPlayer->setDefenseStat(15);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(45);
    AttackItemStub* newAttackItem = new AttackItemStub("Strength", 25, "Makes you muscular.");
    myPlayer->addItem(newAttackItem);
    DefenseItemStub* newDefenseItem = new DefenseItemStub("Shield", 20, "Creates a shield around you.");
    myPlayer->addItem(newDefenseItem);
    HealingPotStub* newHealingPotItem = new HealingPotStub("Healing Pot", 18, "Looks like green hot chocolate.");
    myPlayer->addItem(newHealingPotItem);
    MaxHPPotStub* newMaxHPPotItem = new MaxHPPotStub("Max HP Pot Deluxe", 12, "Looks like strawberry jam.");
    myPlayer->addItem(newMaxHPPotItem);
    myPlayer->consumeItem(3);
    myPlayer->consumeItem(3);
    myPlayer->consumeItem(2);
    myPlayer->consumeItem(1);
    EXPECT_EQ(myPlayer->getAttackStat(), 40);
    EXPECT_EQ(myPlayer->getDefenseStat(), 35);
    EXPECT_EQ(myPlayer->getHP(), 45);
    EXPECT_EQ(myPlayer->getMaxHP(), 57);
    delete myPlayer;
}

TEST(UseItemTests, UsingMultipleItemsCase2) {
    Player* myPlayer = new Player();
    myPlayer->setAttackStat(15);
    myPlayer->setDefenseStat(15);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(45);
    AttackItemStub* newAttackItem = new AttackItemStub("Strength", 25, "Makes you muscular.");
    myPlayer->addItem(newAttackItem);
    DefenseItemStub* newDefenseItem = new DefenseItemStub("Shield", 20, "Creates a shield around you.");
    myPlayer->addItem(newDefenseItem);
    HealingPotStub* newHealingPotItem = new HealingPotStub("Healing Pot", 18, "Looks like green hot chocolate.");
    myPlayer->addItem(newHealingPotItem);
    MaxHPPotStub* newMaxHPPotItem = new MaxHPPotStub("Max HP Pot Deluxe", 12, "Looks like strawberry jam.");
    myPlayer->addItem(newMaxHPPotItem);
    myPlayer->consumeItem(4);
    myPlayer->consumeItem(3);
    myPlayer->consumeItem(2);
    myPlayer->consumeItem(1);
    EXPECT_EQ(myPlayer->getAttackStat(), 40);
    EXPECT_EQ(myPlayer->getDefenseStat(), 35);
    EXPECT_EQ(myPlayer->getHP(), 48);
    EXPECT_EQ(myPlayer->getMaxHP(), 57);
    delete myPlayer;
}

TEST(UseItemTests, UsingMultipleItemsCase3) {
    Player* myPlayer = new Player();
    myPlayer->setAttackStat(15);
    myPlayer->setDefenseStat(15);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(45);
    AttackItemStub* newAttackItem = new AttackItemStub("Strength", 25, "Makes you muscular.");
    myPlayer->addItem(newAttackItem);
    DefenseItemStub* newDefenseItem = new DefenseItemStub("Shield", 20, "Creates a shield around you.");
    myPlayer->addItem(newDefenseItem);
    HealingPotStub* newHealingPotItem = new HealingPotStub("Healing Pot", 12, "Looks like green hot chocolate.");
    myPlayer->addItem(newHealingPotItem);
    MaxHPPotStub* newMaxHPPotItem = new MaxHPPotStub("Max HP Pot Deluxe", 12, "Looks like strawberry jam.");
    myPlayer->addItem(newMaxHPPotItem);
    myPlayer->consumeItem(3);
    myPlayer->consumeItem(3);
    myPlayer->consumeItem(2);
    myPlayer->consumeItem(1);
    EXPECT_EQ(myPlayer->getAttackStat(), 40);
    EXPECT_EQ(myPlayer->getDefenseStat(), 35);
    EXPECT_EQ(myPlayer->getHP(), 42);
    EXPECT_EQ(myPlayer->getMaxHP(), 57);
    delete myPlayer;
}

TEST(UseItemTests, UseItemDirectly) {
    Player* myPlayer = new Player();
    myPlayer->setAttackStat(15);
    myPlayer->setDefenseStat(15);
    myPlayer->setHP(30);
    myPlayer->setMaxHP(45);
    AttackItemStub* newAttackItem = new AttackItemStub("Strength", 25, "Makes you muscular.");
    myPlayer->consumeItem(newAttackItem);
    EXPECT_EQ(myPlayer->getAttackStat(), 40);
    EXPECT_EQ(myPlayer->getDefenseStat(), 15);
    EXPECT_EQ(myPlayer->getHP(), 30);
    EXPECT_EQ(myPlayer->getMaxHP(), 45);
    delete myPlayer;
}

TEST(AttackValueTests, LevelOneAttack) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setAttackStat(0);
    int damage = myPlayer->attack();
    cout << damage << endl;
    EXPECT_GE(damage, 2);
    EXPECT_LE(damage, 12);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTenAttack) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(10);
    myPlayer->setAttackStat(0);
    int damage = myPlayer->attack();
    cout << damage << endl;
    EXPECT_GE(damage, 200);
    EXPECT_LE(damage, 300);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTwentyAttack) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(20);
    myPlayer->setAttackStat(0);
    int damage = myPlayer->attack();
    cout << damage << endl;
    EXPECT_GE(damage, 800);
    EXPECT_LE(damage, 1000);
    delete myPlayer;
}

TEST(AttackValueTests, LevelOneAttackWithAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setAttackStat(5);
    int damage = myPlayer->attack();
    cout << damage << endl;
    EXPECT_GE(damage, 7);
    EXPECT_LE(damage, 17);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTenAttackWithAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(10);
    myPlayer->setAttackStat(100);
    int damage = myPlayer->attack();
    cout << damage << endl;
    EXPECT_GE(damage, 300);
    EXPECT_LE(damage, 400);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTwentyAttackWithAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(20);
    myPlayer->setAttackStat(250);
    int damage = myPlayer->attack();
    cout << damage << endl;
    EXPECT_GE(damage, 1050);
    EXPECT_LE(damage, 1250);
    delete myPlayer;
}

TEST(ChangeGoldTests, AddMoreGOld) {
    Player* myPlayer = new Player();
    myPlayer->setGold(20);
    myPlayer->changeGold(30);
    EXPECT_EQ(myPlayer->getGold(), 50);
    delete myPlayer;
}

TEST(ChangeGoldTests, AddOrSubtractZeroGold) {
    Player* myPlayer = new Player();
    myPlayer->setGold(20);
    myPlayer->changeGold(0);
    EXPECT_EQ(myPlayer->getGold(), 20);
    delete myPlayer;
}

TEST(ChangeGoldTests, SubtractGoldButResultsPositive) {
    Player* myPlayer = new Player();
    myPlayer->setGold(20);
    myPlayer->changeGold(-10);
    EXPECT_EQ(myPlayer->getGold(), 10);
    delete myPlayer;
}

TEST(ChangeGoldTests, SubtractGoldButResultsNegative) {
    Player* myPlayer = new Player();
    myPlayer->setGold(20);
    myPlayer->changeGold(-30);
    EXPECT_EQ(myPlayer->getGold(), 0);
    delete myPlayer;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}