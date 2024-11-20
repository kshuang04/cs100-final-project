#include "../header/enemy.hpp"
#include "gtest/gtest.h"
#include "../src/enemyManager.cpp"
#include <vector>
#include "../header/Item.hpp"

TEST(EnemyClass, gotAttack)
{
    Enemy test(10, 0, 10, 10, 10, "test", 1, 1);
    test.gotAttack(10);
    EXPECT_FALSE(test.isAlive());
    EXPECT_EQ(test.getHealth(), 0);
}


TEST(EnemyClass, healthWhenAttacked)
{
    Enemy test(10, 5, 10, 10, 10, "test", 1, 1);
    test.gotAttack(10);
    EXPECT_EQ(test.getHealth(), 5);
}

TEST(EnemyClass, getName)
{
    Enemy test(0, 0, 0, 0, 0, "test", 1, 1);
    EXPECT_EQ(test.getName(), "test");
}

TEST(EnemyClass, getStage)
{
    Enemy test(0, 0, 0, 0, 0, "test", 1, 1);
    EXPECT_EQ(test.getStage(), 1);
}

TEST(EnemyClass, getRegion)
{
    Enemy test(0, 0, 0, 0, 0, "test", 1, 1);
    EXPECT_EQ(test.getRegion(), 1);
}

TEST(EnemyManager, size) {
    enemyManager test;
    EXPECT_EQ(test.enemies.size(), 28);
}

TEST(EnemyManager, name) {
    enemyManager test;
    EXPECT_EQ(test.enemies.at(0).getName(), "Slime");
    EXPECT_EQ(test.enemies.at(1).getName(), "Goblin");
    EXPECT_EQ(test.enemies.at(2).getName(), "Bat");
    EXPECT_EQ(test.enemies.at(3).getName(), "Wolf Pup");
    EXPECT_EQ(test.enemies.at(4).getName(), "Skeleton");
    EXPECT_EQ(test.enemies.at(5).getName(), "Zombie");
    EXPECT_EQ(test.enemies.at(6).getName(), "Bandit");
}