#include "../header/enemy.hpp"
#include "gtest/gtest.h"
#include "../src/enemyManager.cpp"
#include <vector>
#include "../header/Item.hpp"
#include "../header/Player.hpp"

TEST(EnemyClass, gotAttack)
{
    Enemy test(10, 0, 10, 10, 10, "test", 1, 1);
    test.gotAttack(10);
    EXPECT_FALSE(test.isAlive());
    EXPECT_EQ(test.getHealth(), 0);
}


TEST(EnemyClass, healthWhenAttacked)
{
    Enemy test(100, 10, 10, 10, 10, "test", 1, 1);
    test.gotAttack(20);
    cout << test.getHealth() << endl;
    EXPECT_EQ(test.getHealth(), 82);
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
    EXPECT_EQ(test.enemies.size(), 60);
}

TEST(EnemyManager, name) {
    enemyManager test;
    EXPECT_EQ(test.enemies.at(0).getName(), "Slime");
    EXPECT_EQ(test.enemies.at(1).getName(), "CHANGE");
    EXPECT_EQ(test.enemies.at(2).getName(), "CHANGE");
    EXPECT_EQ(test.enemies.at(3).getName(), "CHANGE");
    EXPECT_EQ(test.enemies.at(4).getName(), "Harpy");
    EXPECT_EQ(test.enemies.at(5).getName(), "Hobgoblin");
    EXPECT_EQ(test.enemies.at(6).getName(), "Orc");
}

TEST(EnemyClass, attack) {
    Player* test = new Player(10, 10, 10, 5, 10);
    Enemy testEnemy(10, 0, 10, 0, 0, "test", 0, 0);
    testEnemy.attack(test);
    cout << test->getHP() << endl;
    EXPECT_EQ(test->getHP(), 5);
    delete test;
}