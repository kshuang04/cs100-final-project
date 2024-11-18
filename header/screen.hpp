#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

#include "../header/Player.hpp"
#include "../header/enemy.hpp"

//DELETE LATER AND ADD REAL LEVEL CLASS
#include "../stubs/levelStub.hpp"

class Screen
{
    protected:
    void displayTextSlowly(const std::string& text);

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
        void printScreen() override;
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

class PlayerInventoryScreen : public Screen
{
    private:
        Player* player;
    public:
        PlayerInventoryScreen(Player* player);
        void printScreen() override;
};

class PlayerStatsScreen : public Screen
{
    private:
        Player* player;
    public:
        PlayerStatsScreen(Player* player);  
        void printScreen() override;
};

class BattleScreen : public Screen
{
    private:
        Player* player;
        Level level;
        vector<Enemy*>* listOfEnemies;
    public:
        BattleScreen(Player* player, Level* level);
        void printScreen() override;
};

#endif