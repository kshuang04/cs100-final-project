#include "../header/chest.hpp"
#include "../header/Player.hpp"
#include "../header/Item.hpp"
#include "../header/ItemInventory.hpp"
#include "gtest/gtest.h"


TEST(ChestTest, FewerItemsThanCapacity) {
    Player* player = new Player(); // Assume player's maxItem = 3
    std::vector<Item*> items = {
        new AttackItem(10, 1, "Sword", 1, "Has a sharpe blade."),
        new DefenseItem(5, 1, "Shield", 1, "Has protective material.")
    };
    Chest* chest = new Chest(2, items, 100);
    chest->collectItems(player);

    EXPECT_TRUE(chest->isEmpty());
    // Clean up
    for (auto item : player->getPlayerInven()->getItemInven()) {
        delete item;
    }
    player->getPlayerInven()->getItemInven().clear();
    delete player;
    delete chest;
}


TEST(ChestTest, EmptyChest) {
    Player* player = new Player();  // Assume player's maxItem = 3
    std::vector<Item*> items; // No items
    Chest* chest = new Chest(0, items, 0);
    chest->collectItems(player);

    EXPECT_TRUE(chest->isEmpty());

    delete player;
    delete chest;
}

TEST(ChestTest, GoldOnly) {
    Player* player = new Player();  // Assume player's maxItem = 3
    std::vector<Item*> items; // No items
    Chest* chest = new Chest(0, items, 200);
    chest->collectItems(player);

    EXPECT_TRUE(chest->isEmpty());

    delete player;
    delete chest;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}