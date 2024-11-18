#include "../header/enemy.hpp"
#include "gtest/gtest.h"

TEST(EnemyClass, gotAttack)
{
    Enemy test(10, 0, 10, 10, 10, "test", 1, 1);
    test.gotAttack(10);
    EXPECT_FALSE(test.isAlive());
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
