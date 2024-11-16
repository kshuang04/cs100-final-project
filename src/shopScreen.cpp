#include "../header/shopScreen.hpp"
#include <iostream>

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
    cout << "(1) Health potion - 20g" << endl
		<< "(2) Attack potion - 30g" << endl
		<< "(3) Defense potion - 40g" << endl
		<< "(4) Sell items" << endl
		<< "(4) Leave" << endl
		<< "------------------------------------------------------------------------------" << endl;
}