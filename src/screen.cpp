#include "../header/screen.hpp"

void Screen::displayTextSlowly(const std::string& text, int delayMilliseconds, int endDelayMilliseconds) 
{
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
    }
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(endDelayMilliseconds));
}

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

void LoseScreen::printScreen()
{
    std::string message = "";

    std::cout << "--------------------" << std::endl;
    message = "You lost. Game over!";
    Screen::displayTextSlowly(message, 50, 900);
    message = "Choose an option:";
    Screen::displayTextSlowly(message, 50, 400);
    std::cout << "(1) Try Again" << std::endl
		<< "(2) Exit" << std::endl
		<< "--------------------" << std::endl;
}

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

ShopScreen::ShopScreen(Player* player)
{
    this->player = player;
    dialogueOptions.push_back("Shopkeeper: \"Need to patch up? Need buffs? You've come to the right place!\"");
    dialogueOptions.push_back("Shopkeeper: \"Hello. Welcome to my shop.\"");
    dialogueOptions.push_back("Shopkeeper: \"Hello! You can buy items that can aid you in your battles here!\"");
}

void ShopScreen::printScreen()
{
    string message;

    srand(time(0));
    int optionChoice = rand() % dialogueOptions.size();
    message = dialogueOptions.at(optionChoice);

    cout << "------------------------------------------------------------------------------" << endl;
    displayTextSlowly(message, 50, 200);
    message = "Choose an option (Wallet: " + to_string(player->getGold()) + "g):";
    displayTextSlowly(message, 50, 200);
    cout << "(1) Small Health potion - 5g" << endl
        << "(2) Max Health Potion - 10g" << endl
		<< "(2) Attack potion - 7g" << endl
		<< "(3) Defense potion - 9g" << endl
		<< "(4) Sell items" << endl
		<< "(4) Leave" << endl
		<< "------------------------------------------------------------------------------" << endl;
}