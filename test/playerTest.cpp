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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}