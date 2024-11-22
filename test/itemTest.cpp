#include "gtest/gtest.h"
#include "../header/Item.hpp"
#include "../header/enemy.hpp"

TEST(itemTest, getDescription) {
    AttackItem itemAtk(0, 0, "test", 0, "Atk");
    DefenseItem itemDef(0, 0, "test", 0, "Def");
    MaxHPPot itemHP(0, 0, "test", 0, "Hp");
    HealingPot itemHeal(0, 0, "test", 0, "Heal");

    EXPECT_EQ(itemAtk.getDescription(), "Atk");
    EXPECT_EQ(itemDef.getDescription(), "Def");
    EXPECT_EQ(itemHP.getDescription(), "Hp");
    EXPECT_EQ(itemHeal.getDescription(), "Heal");
}

TEST(itemTEST, getName) {
    AttackItem itemAtk(0, 0, "atk", 0, "atk");
    DefenseItem itemDef(0, 0, "def", 0, "def");
    MaxHPPot itemHP(0, 0, "hp", 0, "hp");
    HealingPot itemHeal(0, 0, "heal", 0, "heal");
    
    EXPECT_EQ(itemAtk.getItemName(), "atk");
    EXPECT_EQ(itemDef.getItemName(), "def");
    EXPECT_EQ(itemHP.getItemName(), "hp");
    EXPECT_EQ(itemHeal.getItemName(), "heal");
}

TEST(itemTest, getRarity) {
    AttackItem itemAtk(0, 0, "atk", 1, "atk");
    DefenseItem itemDef(0, 0, "def", 2, "atk");
    MaxHPPot itemHP(0, 0, "hp", 3, "hp");
    HealingPot itemHeal(0, 0, "heal", 2, "heal");
    
    EXPECT_EQ(itemAtk.getRarity(), 1);
    EXPECT_EQ(itemDef.getRarity(), 2);
}

TEST(atkItem, getAtkPower) {
    AttackItem itemAtk(10, 0, "atk", 0, "atk");
    
    EXPECT_EQ(itemAtk.getAttackPower(), 10);
}

TEST(defItem, getDefPower) {
    DefenseItem itemDef(10, 0, "def", 0, "def");
    
    EXPECT_EQ(itemDef.getDefensePower(), 10);
}

TEST(hpItem, getHpIncrease) {
    MaxHPPot itemHp(10, 0, "hp", 0, "hp");
    
    EXPECT_EQ(itemHp.getHealthIncrease(), 10);
}

TEST(healItem, getHealAmount) {
    HealingPot itemHeal(10, 0, "heal", 0, "heal");
    
    EXPECT_EQ(itemHeal.getHealthIncrease(), 10);
}

TEST(generateItem, size) {
    vector<Item*> test = generateItem();

    EXPECT_EQ(test.size(), 12);

    for (unsigned i = 0; i < test.size(); i++) {
        delete test.at(i);
    }
}

TEST(generateItem, itemsInside) {
    vector<Item*> test = generateItem();

    EXPECT_EQ(test.at(0)->getItemName(), "Lesser attack");
    EXPECT_EQ(test.at(1)->getItemName(), "Medium attack");
    EXPECT_EQ(test.at(2)->getItemName(), "Strong attack");
    EXPECT_EQ(test.at(3)->getItemName(), "Lesser defense");

    for (unsigned i = 0; i < test.size(); i++) {
        delete test.at(i);
    }
}
