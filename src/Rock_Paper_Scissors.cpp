#include "../header/Rock_Paper_Scissors.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

RockPaperScissors::RockPaperScissors() : MiniGame("Rock Paper Scissor") {}

void RockPaperScissors::play(Player* player) {
    // introduction 
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "Welcome to play Rock Paper Scissors" << endl;
    cout << "The Rule: You are going to play rock paper and scissors with the computer." << endl;
    cout << "It is one round based. If you win, you will earn a chest. If you lose, you will earn nothing" << endl;
    cout << "-------------------------------------------------------------------------------------------------"<< endl;
    // allow user to input
    string userInput;
    cout << "Please enter the choice (R for rock; P for paper, S for scissors) : " ;
    cin >> userInput;
    cout << endl;
    //validation
    while (userInput != "R" and userInput != "P" and userInput != "S"){
        cout << "Invalid input. Please enter R for rock; P for paper, S for scissors : ";
        cin >> userInput;
        cout << endl;
    }
    // computer input
    int computerChoice = rand() % 3;
    //output meg
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "You choose: " << choiceToString(userInput) << endl;
    cout << "Computer choose: " << intToString(computerChoice) << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;

    string result = determineWinner(userInput, computerChoice);
    cout << result << endl;

    if (result == "You win") {
        // generate Reward if win
        cout << "Congratulations, you win. Now you have won a chest." << endl;
        generateReward();

        if (rewardChest) {
            rewardChest->collectItems(player);
            delete rewardChest;
            rewardChest = nullptr; 
        }

    }
    if (result == "tie") {
        cout << "A tie. You have earned nothing" << endl;
    }
    if (result == "You lose") {
        cout << "Bad, You have lost." << endl;
    }
}

string RockPaperScissors::choiceToString(string choice){
    if (choice == "R") {return "Rock";}
    if (choice == "P") {return "Paper";}
    if (choice == "S") {return "Scissors";}
    return "";
}

string RockPaperScissors::intToString(int num){
    if (num == 0) {return "Rock";}
    if (num == 1) {return "Paper";}
    if (num == 2) {return "Scissors";}
    return "";  
}

string RockPaperScissors::determineWinner(string user, int comInput){
    if ((user == "R" and comInput == 0) || (user == "P" and comInput == 1) || (user == "S" and comInput == 2)) {return "tie";}
    if ((user == "R" and comInput == 2) || (user == "P" and comInput == 0) || (user == "S" and comInput == 1)){return "You win";}
    return "You lose";
}