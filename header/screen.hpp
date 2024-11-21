#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

#include "../header/Player.hpp"
#include "../header/enemy.hpp"
#include "../header/level.hpp"

class Screen
{
    protected:
    // function that displays text in terminal as "running text", all subclasses use it
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
        std::vector<std::string> dialogueOptions; // vector to store all possible dialogue variants
        Player* player; // store pointer to player object so can access player's gold
    public:
        ShopScreen(Player* player);
        void printScreen() override;
};

class PlayerInventoryScreen : public Screen
{
    private:
        Player* player; // store pointer to player object so can access player's inventory member
    public:
        PlayerInventoryScreen(Player* player);
        void printScreen() override;
        void printHealingItemsScreen();
};

class PlayerStatsScreen : public Screen
{
    private:
        Player* player; // store pointer to player object so can access player's stats
    public:
        PlayerStatsScreen(Player* player);  
        void printScreen() override;
};

class BattleScreen : public Screen
{
    private:
        Player* player; // store pointer to player object so can access player's health
        level* l; // store pointer to level so can get what enemies are on the current level
        vector<Enemy*>* listOfEnemies; //store pointer to vector that contains the list of Enemies on the current level so can access enemies health
        vector<Enemy>* testList;
    public:
        BattleScreen(Player* player, level* l);
        void printScreen() override;
};

#endif