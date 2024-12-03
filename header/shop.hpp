#ifndef SHOP_HPP
#define SHOP_HPP

#include "../header/Player.hpp"
#include "../header/ItemInventory.hpp"
#include "../header/Item.hpp"

#include <exception> //for custom exceptions used in shop class

class Shop
{
    private:
        Player* player;
        int smallHealthItemPrice = 10;
        int maxHealthItemPrice = 30;
        int attackItemPrice = 15;
        int defenseItemPrice = 20;
    public:
        Shop(Player* player);
        void purchaseSmallHealthItem();
        void purchaseMaxHealthItem();
        void purchaseAttackItem();
        void purchaseDefenseItem();
        void sellSmallHealthItem();
        void sellMaxHealthItem();
        void sellAttackItem();
        void sellDefenseItem();

        int getSmallHealthItemPrice() { return smallHealthItemPrice; }
        int getMaxHealthItemPrice() { return maxHealthItemPrice; }
        int getAttackItemPrice() { return attackItemPrice; }
        int getDefenseItemPrice() { return defenseItemPrice; }
};

class InsufficientFundsException : public exception
{
    private:
        string message;
    public:
        InsufficientFundsException(const char* message) { this->message = message; }
        const char* what() const throw() { return message.c_str(); }
};

class NonexistentItemException : public exception
{
    private:
        string message;
    public:
        NonexistentItemException(const char* message) { this->message = message; }
        const char* what() const throw() { return message.c_str(); }
};

#endif