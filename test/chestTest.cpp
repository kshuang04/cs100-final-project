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



TEST(ChestTestTwo, EmptyChest) {
    Player player; // Assume player's maxItem = 3
    std::vector<Item*> items; // No items
    Chest* chest = new Chest(0, items, 0);
    chest->collectItems(player);

    EXPECT_TRUE(chest->isEmpty());

    delete player;
    delete chest;
}


TEST(ChestTestThree, GoldOnly) {
    Player player; // Assume player's maxItem = 3

    std::vector<Item*> items; // No items
    Chest* chest = new Chest(0, items, 200);
    chest->collectItems(player);

    EXPECT_TRUE(chest->isEmpty());

    delete player;
    delete chest;
}

TEST(ChestTestFour, fillChest) {
    Chest chesta(10);  // Create a Chest with a max capacity of 10
    EXPECT_EQ(chesta.getItemCount(), 9);

    chesta.fillChest();  // fill the Chest

    // Verify that the Chest is not empty
    EXPECT_FALSE(chesta.isEmpty());

    // Validate that items were added to the chest
    // Since the GenerateItems logic adds exactly 9 items in its implementation,
    // GenerateItems adds exactly 9 items based on its implementation
    EXPECT_EQ(chesta.getItemCount(), 10);
    delete chesta;
}

// Test that `fillChest` can be called multiple times
TEST(ChestTestFive, FillChestCanBeCalledMultipleTimes) {
    Chest chest(10);  // Create a Chest with max capacity 10

    chest.fillChest();  // Fill the chest the first time
    EXPECT_FALSE(chest.isEmpty());  // Ensure it is not empty

    int initialGold = chest.getGoldAmount();
    size_t initialItemCount = chest.getItemCount();

    chest.fillChest();  // Fill the chest again
    EXPECT_FALSE(chest.isEmpty());  // Ensure it is still not empty

    // Verify that gold and items have been reset
    EXPECT_NE(chest.getGoldAmount(), initialGold);
    EXPECT_NE(chest.getItemCount(), initialItemCount);
    delete chest;
}

TEST(ChestTestSix, fillEmpChest) {
    Chest chestb;  // Create a Chest with a max capacity of 10
    EXPECT_EQ(chestb.getItemCount(), 0);

    chestb.fillChest();  // fill the Chest

    // Verify that the Chest is not empty
    EXPECT_FALSE(chestb.isEmpty());

    // Validate that items were added to the chest
    // Since the GenerateItems logic adds exactly 9 items in its implementation,
    // GenerateItems adds exactly 9 items based on its implementation
    EXPECT_EQ(chestb.getItemCount(), 9);
    delete chestb;
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}