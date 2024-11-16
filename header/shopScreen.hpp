#ifndef SHOPSCREEN_HPP
#define SHOPSCREEN_HPP
#include "../header/screen.hpp"
#include "../header/Player.hpp"
#include <string>
#include <vector>

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