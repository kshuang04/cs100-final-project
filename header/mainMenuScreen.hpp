#ifndef MAINMENUSCREEN_HPP
#define MAINMENUSCREEN_HPP
#include "../header/screen.hpp"
#include <string>

class MainMenuScreen : public Screen
{
    private:
        void displayTextSlowly(const std::string& text, int delayMilliseconds, int endDelayMilliseconds);

    public:
        void printScreen() override;
};

#endif