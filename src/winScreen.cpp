#include "../header/winScreen.hpp"
#include <iostream>
#include <string>

void WinScreen::printScreen()
{
    std::string message = "";

    std::cout << "-----------------------------------------" << std::endl;
    message = "YOU COMPLETED THE GAME. CONGRATULATIONS!";
    Screen::displayTextSlowly(message, 50, 900);
    message = "Choose an option:";
    Screen::displayTextSlowly(message, 50, 200);
	std::cout << "(1) Try Again" << std::endl
		<< "(2) Exit" << std::endl
		<< "-----------------------------------------" << std::endl;
}