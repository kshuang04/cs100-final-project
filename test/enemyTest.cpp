#include "../header/enemy.hpp"
#include "gtest/gtest.h"

TEST (EnemyClass, gotAttack) {
    Enemy test(10, 0, 10, 10, 10, "test");
    test.gotAttack(10);
    EXPECT_FALSE(test.isAlive());
}

TEST (EnemyClass, healthWhenAttacked) {
    Enemy test(10, 5, 10, 10, 10, "test");
    test.gotAttack(10);
    EXPECT_EQ(test.getHealth(), 5);
}