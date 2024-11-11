#include "gtest/gtest.h"
#include "../header/Player.hpp"

TEST(ChangeEXPTests, IncreaseEXPForButNoLevelIncrease) {
    Player myPlayer;
    myPlayer.changeEXP(50);
    EXPECT_EQ(myPlayer.getLevel(), 1);
    EXPECT_EQ(myPlayer.getEXP(), 50);
}

TEST(ChangeEXPTests, IncreaseEXPForOneLevel) {
    Player myPlayer;
    myPlayer.changeEXP(150);
    EXPECT_EQ(myPlayer.getLevel(), 2);
    EXPECT_EQ(myPlayer.getEXP(), 50);
}

TEST(ChangeEXPTests, IncreaseEXPForTwoLevels) {
    Player myPlayer;
    myPlayer.changeEXP(250);
    EXPECT_EQ(myPlayer.getLevel(), 3);
    EXPECT_EQ(myPlayer.getEXP(), 25);
}

TEST(ChangeEXPTests, IncreaseEXPStartingDifferentLevel) {
    Player myPlayer;
    myPlayer.setLevel(5);
    myPlayer.changeEXP(2500);
    EXPECT_EQ(myPlayer.getLevel(), 10);
    EXPECT_EQ(myPlayer.getEXP(), 550);
}

TEST(ChangeEXPTests, IncreaseEXPAtMaxLevel) {
    Player myPlayer;
    myPlayer.setLevel(20);
    myPlayer.changeEXP(10000);
    EXPECT_EQ(myPlayer.getLevel(), 20);
    EXPECT_EQ(myPlayer.getEXP(), 0);
}

TEST(ChangeEXPTests, IncreaseEXPBeyondMaxLevel) {
    Player myPlayer;
    myPlayer.setLevel(19);
    myPlayer.changeEXP(7500);
    EXPECT_EQ(myPlayer.getLevel(), 20);
    EXPECT_EQ(myPlayer.getEXP(), 0);
}

TEST(ChangeEXPTests, IncreaseNegativeEXP) {
    Player myPlayer;
    EXPECT_ANY_THROW(myPlayer.changeEXP(-50););
}

TEST(PrintStatsTests, normalPlayerStats) {
    Player myPlayer;
    myPlayer.setLevel(2);
    myPlayer.setMaxLevel(20);
    myPlayer.setEXP(50);
    myPlayer.setHP(15);
    myPlayer.setMaxHP(20);
    myPlayer.setAttackStat(25);
    myPlayer.setDefenseStat(20);
    EXPECT_NO_THROW(myPlayer.printStats(););
}

TEST(PrintStatsTests, negativeLevel) {
    Player myPlayer;
    myPlayer.setLevel(-5);
    myPlayer.setMaxLevel(20);
    myPlayer.setEXP(50);
    myPlayer.setHP(15);
    myPlayer.setMaxHP(20);
    myPlayer.setAttackStat(25);
    myPlayer.setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer.printStats(););
}

TEST(PrintStatsTests, pastMAXLevel) {
    Player myPlayer;
    myPlayer.setLevel(30);
    myPlayer.setMaxLevel(20);
    myPlayer.setEXP(50);
    myPlayer.setHP(15);
    myPlayer.setMaxHP(20);
    myPlayer.setAttackStat(25);
    myPlayer.setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer.printStats(););
}

TEST(PrintStatsTests, negativeEXP) {
    Player myPlayer;
    myPlayer.setLevel(2);
    myPlayer.setMaxLevel(20);
    myPlayer.setEXP(-30);
    myPlayer.setHP(15);
    myPlayer.setMaxHP(20);
    myPlayer.setAttackStat(25);
    myPlayer.setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer.printStats(););
}

TEST(PrintStatsTests, tooMuchEXPAndNotLeveledUp) {
    Player myPlayer;
    myPlayer.setLevel(2);
    myPlayer.setMaxLevel(20);
    myPlayer.setEXP(2000);
    myPlayer.setHP(15);
    myPlayer.setMaxHP(20);
    myPlayer.setAttackStat(25);
    myPlayer.setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer.printStats(););
}

TEST(PrintStatsTests, negativeHP) {
    Player myPlayer;
    myPlayer.setLevel(2);
    myPlayer.setMaxLevel(20);
    myPlayer.setEXP(50);
    myPlayer.setHP(-5);
    myPlayer.setMaxHP(20);
    myPlayer.setAttackStat(25);
    myPlayer.setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer.printStats(););
}

TEST(PrintStatsTests, extraHP) {
    Player myPlayer;
    myPlayer.setLevel(2);
    myPlayer.setMaxLevel(20);
    myPlayer.setEXP(50);
    myPlayer.setHP(30);
    myPlayer.setMaxHP(20);
    myPlayer.setAttackStat(25);
    myPlayer.setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer.printStats(););
}

TEST(PrintStatsTests, negativeAttackStat) {
    Player myPlayer;
    myPlayer.setLevel(2);
    myPlayer.setMaxLevel(20);
    myPlayer.setEXP(50);
    myPlayer.setHP(15);
    myPlayer.setMaxHP(20);
    myPlayer.setAttackStat(-100);
    myPlayer.setDefenseStat(20);
    EXPECT_ANY_THROW(myPlayer.printStats(););
}

TEST(PrintStatsTests, negativeDefenseStat) {
    Player myPlayer;
    myPlayer.setLevel(2);
    myPlayer.setMaxLevel(20);
    myPlayer.setEXP(50);
    myPlayer.setHP(15);
    myPlayer.setMaxHP(20);
    myPlayer.setAttackStat(25);
    myPlayer.setDefenseStat(-50);
    EXPECT_ANY_THROW(myPlayer.printStats(););
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}