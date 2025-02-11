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
    std::string message;

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
    std::string message;

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
    // seed random number to ensure randomness
    srand(time(0));

    //choose random element in dialogueOptions vector and display
    int optionChoice = rand() % dialogueOptions.size();
    string message = dialogueOptions.at(optionChoice);

    cout << "------------------------------------------------------------------------------" << endl;
    displayTextSlowly(message);
    message = "Choose an option (Wallet: " + to_string(player->getGold()) + "g):";
    displayTextSlowly(message);

    Shop shop(player); //Have shop object to get and display prices of items

    cout << "(1) Small Health potion - " << to_string(shop.getSmallHealthItemPrice()) << "g" << endl
        << "(2) Max Health potion - " << to_string(shop.getMaxHealthItemPrice()) << "g" << endl
		<< "(3) Attack potion - " << to_string(shop.getAttackItemPrice()) << "g" << endl
		<< "(4) Defense potion - " << to_string(shop.getDefenseItemPrice()) << "g" << endl
		<< "(5) Sell items" << endl
		<< "(6) Leave" << endl
		<< "------------------------------------------------------------------------------" << endl;
}

void ShopScreen::printInsufficientFunds()
{
    cout << "-----------------------------------------------------------------" << endl;
    string message = "Not enough gold to make purchase. Please choose another option.";
    displayTextSlowly(message);
    cout << "-----------------------------------------------------------------" << endl;
}

void ShopScreen::printNonexistentItem()
{
    cout << "------------------------------------------------------------------" << endl;
    string message = "You do not have an item to sell. Please choose another option.";
    displayTextSlowly(message);
    cout << "------------------------------------------------------------------" << endl;
}

void ShopScreen::printSellScreen()
{
    cout << "------------------------------------------------------------------------------" << endl;
    string message = "Choose an item to sell:";
    displayTextSlowly(message);

    Shop shop(player); //Have shop object to get and display prices of items

    cout << "(1) Small Health potion - Value " << to_string(shop.getSmallHealthItemPrice()) << "g" << endl
        << "(2) Max Health potion - Value " << to_string(shop.getMaxHealthItemPrice()) << "g" << endl
		<< "(3) Attack potion - Value " << to_string(shop.getAttackItemPrice()) << "g" << endl
		<< "(4) Defense potion - Value " << to_string(shop.getDefenseItemPrice()) << "g" << endl
        << "(5) Back" << endl
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
    for (int i = 0; i < player->getPlayerInven()->getItemInven().size(); i++) {
        cout << (i + 1) << ". ";
        cout << "Item: " << player->getPlayerInven()->getItemInven().at(i)->getItemName() << ", Description: " 
             << player->getPlayerInven()->getItemInven().at(i)->getDescription() << endl;
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
    this->listOfEnemies = l->returnEnemyVectorP();
}

void BattleScreen::printScreen()
{
    string message;
    cout << "-------------------------" << endl;
    message = "Enemies this stage:";
    displayTextSlowly(message);

    // get and display current health of all enemies in enemies vector
    for (int i = 0; i < listOfEnemies->size(); i++)
    {
        cout << listOfEnemies->at(i).getName() << " (Health: " << listOfEnemies->at(i).getHealth() << "/" << listOfEnemies->at(i).getMaxHealth() << ")" << endl;
    }

    //display player's current health
    cout << endl << "Player (Health: " << player->getHP() << "/" << player->getMaxHPFromLevel() << ")" << endl << endl;

    message = "Select an action:";
    displayTextSlowly(message);
    cout << "(1) Attack" << endl
        << "(2) Use Items" << endl
        << "-------------------------" << endl;
}

PlayerMoveScreen::PlayerMoveScreen(Player* player, level* l)
{
    this->player = player;
    this->listOfEnemies = l->returnEnemyVectorP();
}

void PlayerMoveScreen::printScreen()
{
    cout << "---------------------------" << endl;
    string message = "Player attacked " + listOfEnemies->at(0).getName() + ".";
    displayTextSlowly(message);
    message = listOfEnemies->at(0).getName() + " lost " + to_string(player->getAttackStat()) + " health!";
    displayTextSlowly(message); 
    cout << "---------------------------" << endl;
}

EnemyMoveScreen::EnemyMoveScreen(Player* player, level* l)
{
    this->player = player;
    this->listOfEnemies = l->returnEnemyVectorP();
}

void EnemyMoveScreen::printScreen()
{
    cout << "---------------------------" << endl;
    int totalHPLost = 0;
    string message;
    for (int i = 0; i < listOfEnemies->size(); i++)
    {
        message = listOfEnemies->at(i).getName() + " attacked Player for " + to_string(listOfEnemies->at(i).getAttackPower()) + " points.";
        displayTextSlowly(message);
        totalHPLost += listOfEnemies->at(i).getAttackPower();
    }
    cout << endl;
    message = "Player lost a total of " + to_string(totalHPLost) + " HP!";
    displayTextSlowly(message);
    cout << "---------------------------" << endl;
}

CompleteStageScreen::CompleteStageScreen()
{
    congratsOptions.push_back("Nice job!");
    congratsOptions.push_back("Well done!");
    congratsOptions.push_back("Impressive!");
}

void CompleteStageScreen::printScreen()
{
    // seed random number to ensure randomness
    srand(time(0));

    cout << "-------------------------------------" << endl;
    
    // choose random element in congratsOptions vector and display
    int optionChoice = rand() % congratsOptions.size();
    string message = congratsOptions.at(optionChoice) + " You completed this stage!";
    displayTextSlowly(message);
    
    message = "Please choose an option:";
    displayTextSlowly(message);
    cout << "(1) Check player stats" << endl
        << "(2) Check inventory" << endl
        << "(3) Visit shop" << endl
        << "(4) Next stage" << endl;

    cout << "-------------------------------------" << endl;
}

PlayerMenuScreen::PlayerMenuScreen() {}

void PlayerMenuScreen::printScreen()
{
    string message = "Please choose an option:";
    displayTextSlowly(message);
    cout << "(1) Check player stats" << endl
        << "(2) Check inventory" << endl
        << "(3) Visit shop" << endl
        << "(4) Next stage" << endl;

    cout << "-------------------------------------" << endl;
}