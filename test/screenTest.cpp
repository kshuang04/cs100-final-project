#include "gtest/gtest.h"
#include "../header/screen.hpp"

TEST(ScreenTest, LoseScreenTest)
{
    LoseScreen s;
    EXPECT_NO_THROW(s.printScreen());
}

TEST(ScreenTest, MainMenuScreenTest)
{
    MainMenuScreen s;
    EXPECT_NO_THROW(s.printScreen());
}

TEST(ScreenTest, WinScreenTest)
{
    WinScreen s;
    EXPECT_NO_THROW(s.printScreen());
}

TEST(ScreenTest, ShopScreenTest)
{
    Player* p = new Player();
    (*p).setGold(100);
    ShopScreen s = ShopScreen(p);
    EXPECT_NO_THROW(s.printScreen());
    delete p;
}

TEST(ScreenTest, InventoryScreenTest)
{
    Player* p = new Player();
    PlayerInventoryScreen s = PlayerInventoryScreen(p);
    Item* i1 = new Item("test item 1", "test desc 1");
    Item* i2 = new Item("test item 2", "test desc 2");
    (*p).addItem(i1);
    (*p).addItem(i2);
    EXPECT_NO_THROW(s.printScreen());
    delete p;
}