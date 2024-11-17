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