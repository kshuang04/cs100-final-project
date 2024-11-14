#include "../header/mainMenuScreen.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

void MainMenuScreen::printScreen() 
{
    std::string message;

    std::cout << "-------------------------------" << std::endl;
    message = "Welcome to the Path of Pain.";
    Screen::displayTextSlowly(message, 50, 200);
    message = "I doubt you will make it far.";
    Screen::displayTextSlowly(message, 50, 200);
    message = "Let's test your skill.";
    Screen::displayTextSlowly(message, 50, 400);
    std::cout << "-------------------------------" << std::endl;
    message = "Choose an option:";
    Screen::displayTextSlowly(message, 50, 400);
	std::cout << "(1) Start Game" << std::endl
		<< "(2) Exit" << std::endl
		<< "-------------------------------" << std::endl;
}