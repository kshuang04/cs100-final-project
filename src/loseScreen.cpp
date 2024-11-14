#include "../header/loseScreen.hpp"
#include <iostream>
#include <string>

void LoseScreen::printScreen()
{
    std::string message = "";

    std::cout << "--------------------" << std::endl;
    message = "You lost.";
    Screen::displayTextSlowly(message, 50, 900);
    message = "Game over!";
    Screen::displayTextSlowly(message, 50, 500);
    message = "Choose an option:";
    Screen::displayTextSlowly(message, 50, 200);
    std::cout << "(1) Try Again" << std::endl
		<< "(2) Exit" << std::endl
		<< "--------------------" << std::endl;
}