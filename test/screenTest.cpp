#include "gtest/gtest.h"
#include "../header/screen.hpp"
#include "../header/loseScreen.hpp"
#include "../header/mainMenuScreen.hpp"
#include "../header/shopScreen.hpp"
#include "../header/winScreen.hpp"

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