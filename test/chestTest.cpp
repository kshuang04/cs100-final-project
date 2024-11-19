#include "../header/chest.hpp"
#include "../header/Player.hpp"
#include "../header/Item.hpp"
#include "gtest/gtest.h"


TEST(ChestTest, FewerItemsThanCapacity) {
    Player player; // Assume player's maxItem = 3
    std::vector<Item*> items = {
        new AttackItem(10, 1, "Sword", 1),
        new DefenseItem(5, 1, "Shield", 1)
    };
    Chest chest(2, items, 100);
    chest.collectItems(&player);

    EXPECT_TRUE(chest.isEmpty());
    // Clean up
    for (auto item : player.getItemIven()) {
        delete item;
    }
    player.getItemIven().clear();
}


TEST(ChestTest, EmptyChest) {
    Player player; // Assume player's maxItem = 3
    std::vector<Item*> items; // No items
    Chest chest(0, items, 0);
    chest.collectItems(&player);

    EXPECT_TRUE(chest.isEmpty());
}

TEST(ChestTest, GoldOnly) {
    Player player; // Assume player's maxItem = 3
    std::vector<Item*> items; // No items
    Chest chest(0, items, 200);
    chest.collectItems(&player);

    EXPECT_TRUE(chest.isEmpty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}