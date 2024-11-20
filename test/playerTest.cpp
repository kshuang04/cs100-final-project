#include "gtest/gtest.h"
#include "../header/Player.hpp"
#include "../header/Item.hpp"
#include "../header/ItemInventory.hpp"
#include "../test/stubs/AttackItemStub.hpp"
#include "../test/stubs/DefenseItemStub.hpp"
#include "../test/stubs/HealthItemStub.hpp"
#include "../test/stubs/HealingPotStub.hpp"
#include "../test/stubs/MaxHPPotStub.hpp"

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

TEST(UseItemTests, UseAttackItem) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(20);
    AttackItem* newAttackItem = new AttackItem(25, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 25);
    EXPECT_EQ(myPlayer->getDefenseStat(), 1);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    delete myPlayer;
}

TEST(UseItemTests, UseDefenseItem) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(20);
    DefenseItem* newDefenseItem = new DefenseItem(20, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 1);
    EXPECT_EQ(myPlayer->getDefenseStat(), 20);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    delete myPlayer;
}

TEST(UseItemTests, UseHealingPotItemButHPExceedsMaxHP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(20);
    HealingPot* newHealingPotItem = new HealingPot(18, 1, "Green Hot Chocolate", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem, myPlayer);
    myPlayer->getPlayerInven()->consumeItem(1, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 1);
    EXPECT_EQ(myPlayer->getDefenseStat(), 1);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    delete myPlayer;
}

TEST(UseItemTests, UseHealingPotItemButHPDoesNotExceedsMaxHP) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(5);
    myPlayer->setMaxHPStat(0);
    HealingPot* newHealingPotItem = new HealingPot(12, 1, "Green Hot Chocolate", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem, myPlayer);
    myPlayer->getPlayerInven()->consumeItem(1, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 1);
    EXPECT_EQ(myPlayer->getDefenseStat(), 1);
    EXPECT_EQ(myPlayer->getHP(), 17);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    delete myPlayer;
}

TEST(UseItemTests, UsingMaxHPPotItem) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(5);
    myPlayer->setMaxHPStat(0);
    MaxHPPot* newMaxHPPotItem = new MaxHPPot(12, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 1);
    EXPECT_EQ(myPlayer->getDefenseStat(), 1);
    EXPECT_EQ(myPlayer->getHP(), 5);
    EXPECT_EQ(myPlayer->getMaxHPStat(), 12);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 32);
    delete myPlayer;
}

TEST(UseItemTests, UsingMultipleItemsCase1) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(20);
    myPlayer->setMaxHPStat(0);
    AttackItem* newAttackItem = new AttackItem(25, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem, myPlayer);
    DefenseItem* newDefenseItem = new DefenseItem(20, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem, myPlayer);
    HealingPot* newHealingPotItem = new HealingPot(18, 1, "Green Hot Chocolate", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem, myPlayer);
    MaxHPPot* newMaxHPPotItem = new MaxHPPot(12, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem, myPlayer);
    myPlayer->getPlayerInven()->consumeItem(1, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 25);
    EXPECT_EQ(myPlayer->getDefenseStat(), 20);
    EXPECT_EQ(myPlayer->getHP(), 32);
    EXPECT_EQ(myPlayer->getMaxHPStat(), 12);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 32);
    delete myPlayer;
}

TEST(UseItemTests, UsingMultipleItemsCase2) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(20);
    myPlayer->setMaxHPStat(0);
    AttackItem* newAttackItem = new AttackItem(25, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem, myPlayer);
    DefenseItem* newDefenseItem = new DefenseItem(20, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem, myPlayer);
    HealingPot* newHealingPotItem = new HealingPot(18, 1, "Green Hot Chocolate", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem, myPlayer);
    MaxHPPot* newMaxHPPotItem = new MaxHPPot(12, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem, myPlayer);
    myPlayer->getPlayerInven()->consumeItem(1, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 25);
    EXPECT_EQ(myPlayer->getDefenseStat(), 20);
    EXPECT_EQ(myPlayer->getHP(), 32);
    EXPECT_EQ(myPlayer->getMaxHPStat(), 12);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 32);
    delete myPlayer;
}

TEST(UseItemTests, UsingMultipleItemsCase3) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(20);
    myPlayer->setMaxHPStat(0);
    AttackItem* newAttackItem = new AttackItem(25, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem, myPlayer);
    DefenseItem* newDefenseItem = new DefenseItem(20, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem, myPlayer);
    HealingPot* newHealingPotItem = new HealingPot(18, 1, "Green Hot Chocolate", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem, myPlayer);
    MaxHPPot* newMaxHPPotItem = new MaxHPPot(12, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem, myPlayer);
    myPlayer->getPlayerInven()->consumeItem(1, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 25);
    EXPECT_EQ(myPlayer->getDefenseStat(), 20);
    EXPECT_EQ(myPlayer->getHP(), 32);
    EXPECT_EQ(myPlayer->getMaxHPStat(), 12);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 32);
    delete myPlayer;
}

TEST(UseItemTests, UseItemDirectly) {
    Player* myPlayer = new Player();
    myPlayer->setAttackStat(15);
    myPlayer->setDefenseStat(15);
    myPlayer->setHP(20);
    AttackItem* newAttackItem = new AttackItem(25, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->consumeItem(newAttackItem, myPlayer);
    EXPECT_EQ(myPlayer->getDefenseStat(), 15);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    delete myPlayer;
}

TEST(AttackValueTests, LevelOneAttack) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setAttackStat(0);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 2);
    EXPECT_LE(damage, 12);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTenAttack) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(10);
    myPlayer->setAttackStat(0);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 200);
    EXPECT_LE(damage, 300);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTwentyAttack) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(20);
    myPlayer->setAttackStat(0);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 800);
    EXPECT_LE(damage, 1000);
    delete myPlayer;
}

TEST(AttackValueTests, LevelOneAttackWithAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setAttackStat(5);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 7);
    EXPECT_LE(damage, 17);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTenAttackWithAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(10);
    myPlayer->setAttackStat(100);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 300);
    EXPECT_LE(damage, 400);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTwentyAttackWithAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(20);
    myPlayer->setAttackStat(250);
    int damage = myPlayer->attack();
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

TEST(TakeDamageTests, DamageButStillAlive) {
    Player* myPlayer = new Player();
    myPlayer->setHP(20);
    myPlayer->takeDamage(10);
    EXPECT_EQ(myPlayer->getHP(), 10);
    EXPECT_EQ(myPlayer->getIsAlive(), true);
    delete myPlayer;
}

TEST(TakeDamageTests, DamageToZeroHP) {
    Player* myPlayer = new Player();
    myPlayer->setHP(20);
    myPlayer->takeDamage(20);
    EXPECT_EQ(myPlayer->getHP(), 0);
    EXPECT_EQ(myPlayer->getIsAlive(), false);
    delete myPlayer;
}

TEST(TakeDamageTests, DamageToNegativeHP) {
    Player* myPlayer = new Player();
    myPlayer->setHP(20);
    myPlayer->takeDamage(30);
    EXPECT_EQ(myPlayer->getHP(), 0);
    EXPECT_EQ(myPlayer->getIsAlive(), false);
    delete myPlayer;
}

TEST(StackItemTests, StackAttackItems) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    AttackItem* newAttackItem1 = new AttackItem(25, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem1, myPlayer);
    AttackItem* newAttackItem2 = new AttackItem(50, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem2, myPlayer);
    AttackItem* newAttackItem3 = new AttackItem(75, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem3, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 150);
    EXPECT_EQ(myPlayer->getDefenseStat(), 1);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    delete myPlayer;
}

TEST(StackItemTests, StackDefensetems) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    DefenseItem* newDefenseItem1 = new DefenseItem(20, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem1, myPlayer);
    DefenseItem* newDefenseItem2 = new DefenseItem(35, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem2, myPlayer);
    DefenseItem* newDefenseItem3 = new DefenseItem(55, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem3, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 1);
    EXPECT_EQ(myPlayer->getDefenseStat(), 110);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    delete myPlayer;
}

TEST(StackItemTests, StackMaxHPtems) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    ASSERT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    MaxHPPot* newMaxHPPotItem1 = new MaxHPPot(12, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem1, myPlayer);
    MaxHPPot* newMaxHPPotItem2 = new MaxHPPot(53, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem2, myPlayer);
    MaxHPPot* newMaxHPPotItem3 = new MaxHPPot(31, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem3, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 1);
    EXPECT_EQ(myPlayer->getDefenseStat(), 1);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 116);
    delete myPlayer;
}

TEST(StackItemTests, StackHealingPotItems) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    HealingPot* newHealingPotItem1 = new HealingPot(12, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem1, myPlayer);
    HealingPot* newHealingPotItem2 = new HealingPot(25, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem2, myPlayer);
    HealingPot* newHealingPotItem3 = new HealingPot(69, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem3, myPlayer);
    myPlayer->getPlayerInven()->stackItemStats(myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 1);
    EXPECT_EQ(myPlayer->getDefenseStat(), 1);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    EXPECT_EQ(myPlayer->getPlayerInven()->getHealingPotInven().size(), 3);
    delete myPlayer;
}

TEST(StackItemTests, StackMultipleTypeItems) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    ASSERT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    AttackItem* newAttackItem1 = new AttackItem(25, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem1, myPlayer);
    DefenseItem* newDefenseItem1 = new DefenseItem(20, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem1, myPlayer);
    MaxHPPot* newMaxHPPotItem1 = new MaxHPPot(12, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem1, myPlayer);
    HealingPot* newHealingPotItem1 = new HealingPot(12, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem1, myPlayer);
    AttackItem* newAttackItem2 = new AttackItem(50, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem2, myPlayer);
    DefenseItem* newDefenseItem2 = new DefenseItem(35, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem2, myPlayer);
    MaxHPPot* newMaxHPPotItem2 = new MaxHPPot(53, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem2, myPlayer);
    HealingPot* newHealingPotItem2 = new HealingPot(25, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem2, myPlayer);
    AttackItem* newAttackItem3 = new AttackItem(75, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem3, myPlayer);
    DefenseItem* newDefenseItem3 = new DefenseItem(55, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem3, myPlayer);
    MaxHPPot* newMaxHPPotItem3 = new MaxHPPot(31, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem3, myPlayer);
    HealingPot* newHealingPotItem3 = new HealingPot(69, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem3, myPlayer);
    myPlayer->getPlayerInven()->stackItemStats(myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 150);
    EXPECT_EQ(myPlayer->getDefenseStat(), 110);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 116);
    EXPECT_EQ(myPlayer->getPlayerInven()->getHealingPotInven().size(), 3);
    delete myPlayer;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}