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
    myPlayer->changeEXP(5);
    EXPECT_EQ(myPlayer->getLevel(), 1);
    EXPECT_EQ(myPlayer->getEXP(), 5);
    delete myPlayer;
}

TEST(ChangeEXPTests, IncreaseEXPForOneLevel) {
    Player* myPlayer = new Player();
    myPlayer->changeEXP(15);
    EXPECT_EQ(myPlayer->getLevel(), 2);
    EXPECT_EQ(myPlayer->getEXP(), 5);
    delete myPlayer;
}

TEST(ChangeEXPTests, IncreaseEXPForTwoLevels) {
    Player* myPlayer = new Player();
    myPlayer->changeEXP(30);
    EXPECT_EQ(myPlayer->getLevel(), 3);
    EXPECT_EQ(myPlayer->getEXP(), 7);
    delete myPlayer;
}

TEST(ChangeEXPTests, IncreaseEXPStartingDifferentLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(5);
    myPlayer->changeEXP(165);
    EXPECT_EQ(myPlayer->getLevel(), 10);
    EXPECT_EQ(myPlayer->getEXP(), 18);
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
    EXPECT_EQ(myPlayer->getAttackStat(), 26);
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
    EXPECT_EQ(myPlayer->getDefenseStat(), 21);
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
    myPlayer->getPlayerInven()->consumeNextHealingPot(myPlayer);
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
    myPlayer->getPlayerInven()->consumeNextHealingPot(myPlayer);
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
    myPlayer->getPlayerInven()->consumeNextHealingPot(myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 26);
    EXPECT_EQ(myPlayer->getDefenseStat(), 21);
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
    myPlayer->getPlayerInven()->consumeNextHealingPot(myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 26);
    EXPECT_EQ(myPlayer->getDefenseStat(), 21);
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
    myPlayer->getPlayerInven()->consumeNextHealingPot(myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 26);
    EXPECT_EQ(myPlayer->getDefenseStat(), 21);
    EXPECT_EQ(myPlayer->getHP(), 32);
    EXPECT_EQ(myPlayer->getMaxHPStat(), 12);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 32);
    delete myPlayer;
}

TEST(UseItemTests, UseItemDirectly) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    AttackItem* newAttackItem = new AttackItem(25, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem, myPlayer);
    EXPECT_EQ(myPlayer->getAttackStat(), 26);
    EXPECT_EQ(myPlayer->getDefenseStat(), 1);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    delete myPlayer;
}

TEST(AttackValueTests, LevelOneAttack) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setAttackStat(0);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 5);
    EXPECT_LE(damage, 10);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTenAttack) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(10);
    myPlayer->setAttackStat(0);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 50);
    EXPECT_LE(damage, 100);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTwentyAttack) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(20);
    myPlayer->setAttackStat(0);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 100);
    EXPECT_LE(damage, 200);
    delete myPlayer;
}

TEST(AttackValueTests, LevelOneAttackWithAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setAttackStat(5);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 10);
    EXPECT_LE(damage, 15);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTenAttackWithAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(10);
    myPlayer->setAttackStat(75);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 125);
    EXPECT_LE(damage, 175);
    delete myPlayer;
}

TEST(AttackValueTests, LevelTwentyAttackWithAttackStat) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(20);
    myPlayer->setAttackStat(150);
    int damage = myPlayer->attack();
    EXPECT_GE(damage, 250);
    EXPECT_LE(damage, 350);
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
    EXPECT_EQ(myPlayer->getHP(), 11);
    EXPECT_EQ(myPlayer->getIsAlive(), true);
    delete myPlayer;
}

TEST(TakeDamageTests, DamageToZeroHP) {
    Player* myPlayer = new Player();
    myPlayer->setHP(20);
    myPlayer->takeDamage(21);
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

TEST(TakeDamageTests, DamageWithDefensePot) {
    Player* myPlayer = new Player();
    DefenseItem* newDefenseItem1 = new DefenseItem(5, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem1, myPlayer);
    myPlayer->setHP(20);
    myPlayer->takeDamage(15);
    EXPECT_EQ(myPlayer->getHP(), 11);
    EXPECT_EQ(myPlayer->getIsAlive(), true);
    delete myPlayer;
}

TEST(TakeDamageTests, DamageOnHigherLevel) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(5);
    myPlayer->setHP(myPlayer->getMaxHPFromLevel());
    myPlayer->takeDamage(35);
    EXPECT_EQ(myPlayer->getHP(), 18);
    EXPECT_EQ(myPlayer->getIsAlive(), true);
    delete myPlayer;
}

TEST(TakeDamageTests, DamageOnHigherLevelAndWithDefensePot) {
    Player* myPlayer = new Player();
    DefenseItem* newDefenseItem1 = new DefenseItem(7, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem1, myPlayer);
    myPlayer->setLevel(5);
    myPlayer->setHP(myPlayer->getMaxHPFromLevel());
    myPlayer->takeDamage(35);
    EXPECT_EQ(myPlayer->getHP(), 25);
    EXPECT_EQ(myPlayer->getIsAlive(), true);
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
    EXPECT_EQ(myPlayer->getAttackStat(), 151);
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
    EXPECT_EQ(myPlayer->getDefenseStat(), 111);
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
    //EXPECT_EQ(myPlayer->getPlayerInven()->getHealingPotInven().size(), 3);
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
    EXPECT_EQ(myPlayer->getAttackStat(), 151);
    EXPECT_EQ(myPlayer->getDefenseStat(), 111);
    EXPECT_EQ(myPlayer->getHP(), 20);
    EXPECT_EQ(myPlayer->getMaxHPFromLevel(), 116);
    EXPECT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 12);
    delete myPlayer;
}

TEST(consumeNextHealingPotInBattleTests, SingleHealingPotInInven) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(12);
    ASSERT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    HealingPot* newHealingPotItem = new HealingPot(5, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem, myPlayer);
    ASSERT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 1);
    myPlayer->getPlayerInven()->consumeNextHealingPot(myPlayer);
    EXPECT_EQ(myPlayer->getHP(), 17);
    EXPECT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 0);
    delete myPlayer;
}

TEST(consumeNextHealingPotInBattleTests, MultipleHealingPotInInven) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(12);
    ASSERT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    HealingPot* newHealingPotItem1 = new HealingPot(6, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem1, myPlayer);
    HealingPot* newHealingPotItem2 = new HealingPot(5, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem2, myPlayer);
    HealingPot* newHealingPotItem3 = new HealingPot(4, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem3, myPlayer);
    ASSERT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 3);
    myPlayer->getPlayerInven()->consumeNextHealingPot(myPlayer);
    EXPECT_EQ(myPlayer->getHP(), 18);
    EXPECT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 2);
    delete myPlayer;
}

TEST(consumeNextHealingPotInBattleTests, NoHealingPotInInven) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(12);
    ASSERT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    ASSERT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 0);
    myPlayer->getPlayerInven()->consumeNextHealingPot(myPlayer);
    EXPECT_EQ(myPlayer->getHP(), 12);
    EXPECT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 0);
    delete myPlayer;
}

TEST(consumeNextHealingPotInBattleTests, ItemVarietyInInven) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(12);
    ASSERT_EQ(myPlayer->getMaxHPFromLevel(), 20);
    AttackItem* newAttackItem1 = new AttackItem(25, 1, "Strength", 1, "Makes you stronger.");
    myPlayer->getPlayerInven()->addItem(newAttackItem1, myPlayer);
    DefenseItem* newDefenseItem1 = new DefenseItem(20, 1, "Shield", 1, "Creates a shield around you.");
    myPlayer->getPlayerInven()->addItem(newDefenseItem1, myPlayer);
    MaxHPPot* newMaxHPPotItem1 = new MaxHPPot(12, 1, "Max HP Pot Deluxe", 1, "Boosts your max health.");
    myPlayer->getPlayerInven()->addItem(newMaxHPPotItem1, myPlayer);
    HealingPot* newHealingPotItem1 = new HealingPot(12, 1, "Lucky Healing Potion", 1, "Heals up your health from damage taken.");
    myPlayer->getPlayerInven()->addItem(newHealingPotItem1, myPlayer);
    ASSERT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 4);
    myPlayer->getPlayerInven()->consumeNextHealingPot(myPlayer);
    EXPECT_EQ(myPlayer->getMaxHP(), 32);
    EXPECT_EQ(myPlayer->getHP(), 24);
    EXPECT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 3);
    delete myPlayer;
}

TEST(consumeNextHealingPotInBattleTests, MultiItemVarietyInInven) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(1);
    myPlayer->setHP(12);
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
    ASSERT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 12);
    myPlayer->getPlayerInven()->consumeNextHealingPot(myPlayer);
    EXPECT_EQ(myPlayer->getMaxHP(), 116);
    EXPECT_EQ(myPlayer->getHP(), 24);
    EXPECT_EQ(myPlayer->getPlayerInven()->getItemInven().size(), 11);
    delete myPlayer;
}

TEST(ResetPlayerStatTests, ResetStats) {
    Player* myPlayer = new Player();
    myPlayer->setLevel(20);
    myPlayer->setAttackStat(12);
    myPlayer->setDefenseStat(15);
    myPlayer->setEXP(25);
    myPlayer->setGold(75);
    myPlayer->setIsAlive(false);
    myPlayer->setMaxHPStat(35);
    myPlayer->setMaxLevel(30);
    myPlayer->resetStats();
    EXPECT_EQ(myPlayer->getLevel(), 1);
    EXPECT_EQ(myPlayer->getAttackStat(), 1);
    EXPECT_EQ(myPlayer->getDefenseStat(), 1);
    EXPECT_EQ(myPlayer->getEXP(), 0);
    EXPECT_EQ(myPlayer->getGold(), 0);
    EXPECT_EQ(myPlayer->getIsAlive(), true);
    EXPECT_EQ(myPlayer->getMaxHPStat(), 20);
    EXPECT_EQ(myPlayer->getMaxLevel(), 20);
    delete myPlayer;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}