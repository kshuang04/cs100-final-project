#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

#include "../header/Player.hpp"

class Screen
{
    protected:
    void displayTextSlowly(const std::string& text, int delayMilliseconds, int endDelayMilliseconds);

    public:
    virtual void printScreen() = 0;
};

class MainMenuScreen : public Screen
{
    public:
        void printScreen() override;
};

class LoseScreen : public Screen
{
    public:
    void printScreen() override;
};

class WinScreen : public Screen
{
    public:
        void printScreen();
};

class ShopScreen : public Screen
{
    private:
        std::vector<std::string> dialogueOptions;
        Player* player;
    public:
        ShopScreen(Player* player);
        void printScreen() override;
};

#endif