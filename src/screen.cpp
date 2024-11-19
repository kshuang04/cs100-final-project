#include "../header/screen.hpp"

void Screen::displayTextSlowly(const std::string& text) 
{
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void MainMenuScreen::printScreen() 
{
    std::string message;

    std::cout << "-------------------------------" << std::endl;
    message = "Welcome to the Path of Pain.";
    displayTextSlowly(message);
    message = "I doubt you will make it far.";
    displayTextSlowly(message);
    message = "Let's test your skill.";
    displayTextSlowly(message);
    std::cout << "-------------------------------" << std::endl;
    message = "Choose an option:";
    displayTextSlowly(message);
	std::cout << "(1) Start Game" << std::endl
		<< "(2) Exit" << std::endl
		<< "-------------------------------" << std::endl;
}

void LoseScreen::printScreen()
{
    std::string message = "";

    std::cout << "--------------------" << std::endl;
    message = "You lost. Game over!";
    displayTextSlowly(message);
    message = "Choose an option:";
    displayTextSlowly(message);
    std::cout << "(1) Try Again" << std::endl
		<< "(2) Exit" << std::endl
		<< "--------------------" << std::endl;
}

void WinScreen::printScreen()
{
    std::string message = "";

    std::cout << "-----------------------------------------" << std::endl;
    message = "YOU COMPLETED THE GAME. CONGRATULATIONS!";
    displayTextSlowly(message);
    message = "Choose an option:";
    displayTextSlowly(message);
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
    displayTextSlowly(message);
    message = "Choose an option (Wallet: " + to_string(player->getGold()) + "g):";
    displayTextSlowly(message);
    cout << "(1) Health potion - 10g" << endl
		<< "(2) Attack potion - 15g" << endl
		<< "(3) Defense potion - 20g" << endl
		<< "(4) Sell items" << endl
		<< "(4) Leave" << endl
		<< "------------------------------------------------------------------------------" << endl;
}

PlayerInventoryScreen::PlayerInventoryScreen(Player* player)
{
    this->player = player;
}

void PlayerInventoryScreen::printScreen()
{
    //Prints every item and its contents from the player's item inventory
    string message;
    cout << "------------------------------------------------------------\n";
    message = "Player's Item Inventory:\n";
    displayTextSlowly(message);
    for (int i = 0; i < player->getItemIven().size(); i++) {
        cout << (i + 1) << ". ";
        player->getItemIven().at(i)->printStat();
        cout << endl;
    }
    cout << "------------------------------------------------------------\n";
}

PlayerStatsScreen::PlayerStatsScreen(Player* player)
{
    this->player = player;
}

void PlayerStatsScreen::printScreen()
{
    string message;
    cout << endl << "------------------------" << endl;
    message = "Player's Stats:";
    displayTextSlowly(message);
    cout << endl;
    //Checks to see if the level number is valid and prints it if valid or throws an error if not valid.
    if ((player->getLevel() < 1) || (player->getLevel() > player->getMaxLevel())) {throw logic_error("The current level is not within the specified range.");}
    cout << "Level: " << player->getLevel() << endl;
    //Checks to see if the HP value is valid and prints it if valid or throws an error if not valid.
    if ((player->getHP() < 0) || (player->getHP() > player->getMaxHPFromLevel())) {throw logic_error("The current HP is not within the specified range.");}
    cout << "Health Power: " << player->getHP() << " / " << player->getMaxHPFromLevel() << endl;
    //Checks to see if the attack stat value is valid and prints it if valid or throws an error if not valid.
    if (player->getAttackStat() < 0) {throw logic_error("The current Attack Power is negative and invalid.");}
    cout << "Attack Power: " << player->getAttackStat() << endl;
    //Checks to see if the defense stat  value is valid and prints it if valid or throws an error if not valid.
    if (player->getDefenseStat() < 0) {throw logic_error("The current Defense Power is negative and invalid.");}
    cout << "Defense Power: " << player->getDefenseStat() << endl;
    //Checks to see if the EXP value is valid and prints it if valid or throws an error if not valid.
    if ((player->getEXP() < 0) || (player->getEXP() >= player->expToNextLevel())) {throw logic_error("The current EXP is not within the specified range.");}
    cout << "Current EXP: " << player->getEXP() << endl;
    //Checks to see if the remaining EXP value is valid and prints it if valid or throws an error if not valid.
    if (((player->expToNextLevel() - player->getEXP()) < 0) || ((player->expToNextLevel() - player->getEXP()) > player->expToNextLevel())) {throw logic_error("The current EXP to Next Level is not within the specified range.");}
    cout << "EXP To Next Level: " << (player->expToNextLevel() - player->getEXP()) << endl;
    cout << "------------------------" << endl;
}

BattleScreen::BattleScreen(Player* player, level* l)
{
    this->player = player;
    //this->listOfEnemies = (*l).getListOfEnemies();
}

//Constructor for Level stub
BattleScreen::BattleScreen(Player* player, Level* l)
{
    this->player = player;
    //this->listOfEnemies = (*l).getListOfEnemies();
}

void BattleScreen::printScreen()
{
    string message;
    cout << "-------------------------" << endl;
    message = "Enemies this stage:";
    displayTextSlowly(message);
    for (int i = 0; i < (*listOfEnemies).size(); i++)
    {
        cout << (*(*listOfEnemies).at(i)).getName() << " (Health: " << (*(*listOfEnemies).at(i)).getHealth() << "/" << (*(*listOfEnemies).at(i)).getMaxHealth() << ")" << endl;
    }
    cout << endl << "Player (Health: " << player->getHP() << "/" << player->getMaxHP() << ")" << endl << endl;
    message = "Select an action:";
    displayTextSlowly(message);
    cout << "(1) Attack" << endl
        << "(2) Use Items" << endl
        << "-------------------------" << endl;
}