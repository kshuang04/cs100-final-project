#include "gtest/gtest.h"
#include "../header/Item.hpp"
// #include "../src/itemGenerator.cpp"

TEST(itemTest, getDescription) {
    AttackItem itemAtk(0, 0, "test", 0);
    itemAtk.setDesc("atk");
    DefenseItem itemDef(0, 0, "test", 0);
    itemDef.setDesc("def");
    MaxHPPot itemHP(0, 0, "test", 0);
    itemHP.setDesc("Hp");
    HealingPot itemHeal(0, 0, "test", 0);
    itemHeal.setDesc("Heal");

    EXPECT_EQ(itemAtk.getDescription(), "atk");
    EXPECT_EQ(itemDef.getDescription(), "def");
    EXPECT_EQ(itemHP.getDescription(), "Hp");
    EXPECT_EQ(itemHeal.getDescription(), "Heal");
}

TEST(itemTEST, getName) {
    AttackItem itemAtk(0, 0, "atk", 0);
    DefenseItem itemDef(0, 0, "def", 0);
    MaxHPPot itemHP(0, 0, "hp", 0);
    HealingPot itemHeal(0, 0, "heal", 0);
    
    EXPECT_EQ(itemAtk.getItemName(), "atk");
    EXPECT_EQ(itemDef.getItemName(), "def");
    EXPECT_EQ(itemHP.getItemName(), "hp");
    EXPECT_EQ(itemHeal.getItemName(), "heal");
}

TEST(itemTest, getRarity) {
    AttackItem itemAtk(0, 0, "atk", 1);
    DefenseItem itemDef(0, 0, "def", 2);
    MaxHPPot itemHP(0, 0, "hp", 3);
    HealingPot itemHeal(0, 0, "heal", 2);
    
    EXPECT_EQ(itemAtk.getRarity(), 1);
    EXPECT_EQ(itemDef.getRarity(), 2);
    EXPECT_EQ(itemHP.getRarity(), 3);
    EXPECT_EQ(itemHeal.getRarity(), 2);
}

TEST(atkItem, getAtkPower) {
    AttackItem itemAtk(10, 0, "atk", 0);
    
    EXPECT_EQ(itemAtk.getAttackPower(), 10);
}

TEST(defItem, getDefPower) {
    DefenseItem itemDef(10, 0, "def", 0);
    
    EXPECT_EQ(itemDef.getDefensePower(), 10);
}

TEST(hpItem, getHpIncrease) {
    MaxHPPot itemHp(10, 0, "hp", 0);
    
    EXPECT_EQ(itemHp.getHealthIncrease(), 10);
}

TEST(healItem, getHealAmount) {
    HealingPot itemHeal(10, 0, "heal", 0);
    
    EXPECT_EQ(itemHeal.getHealthAmount(), 10);
}