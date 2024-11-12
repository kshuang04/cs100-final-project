#include "../header/Player.hpp"

//Default Player Constructor
Player::Player() : currHP(20), maxHP(20), level(1), maxLevel(20), exp(0), attackStat(1), defenseStat(1), gold(0), itemCount(0) {}

//Specific Player Constructor
Player::Player(int maxHP, int maxLevel, int attack, int defense, int gold) : currHP(maxHP), maxHP(maxHP), level(1), maxLevel(maxLevel), exp(0), attackStat(attack), defenseStat(defense), gold(gold), itemCount(0) {}

Player::~Player() {
    for (int i = 0; i < this->getItemIven().size(); i++) {
        delete this->getItemIven().at(i);
        this->getItemIven().at(i) = nullptr;
    }
}

int Player::attack() {
    return 1;
}

// Attack Player::getAttack() {

// }

void Player::addItem(Item* newItem) {
    if ((this->getItemCount() + 1) > this->maxItem) {throw logic_error("You have reached the maximum amount of items.");}
    this->getItemIven().push_back(newItem);
}

void Player::printStats() {
    cout << endl << "------------------------" << endl;
    if ((this->getLevel() < 1) || (this->getLevel() > this->getMaxLevel())) {throw logic_error("The current level is not within the specified range.");}
    cout << "Level: " << this->getLevel() << endl;
    if ((this->getHP() < 0) || (this->getHP() > this->getMaxHP())) {throw logic_error("The current HP is not within the specified range.");}
    cout << "Health Power: " << this->getHP() << " / " << this->getMaxHP() << endl;
    if (this->getAttackStat() < 0) {throw logic_error("The current Attack Power is negative and invalid.");}
    cout << "Attack Power: " << this->getAttackStat() << endl;
    if (this->getDefenseStat() < 0) {throw logic_error("The current Defense Power is negative and invalid.");}
    cout << "Defense Power: " << this->getDefenseStat() << endl;
    if ((this->getEXP() < 0) || (this->getEXP() >= this->expToNextLevel())) {throw logic_error("The current EXP is not within the specified range.");}
    cout << "Current EXP: " << this->getEXP() << endl;
    if (((this->expToNextLevel() - this->getEXP()) < 0) || ((this->expToNextLevel() - this->getEXP()) > this->expToNextLevel())) {throw logic_error("The current EXP to Next Level is not within the specified range.");}
    cout << "EXP To Next Level: " << (this->expToNextLevel() - this->getEXP()) << endl;
    cout << "------------------------" << endl;
}

void Player::printInven() {
    cout << "------------------------\n" << "Player's Item Inventory\n\n";
    for (int i = 0; i < this->getItemIven().size(); i++) {
        cout << (i + 1) << ". ";
        this->getItemIven().at(i)->printStat();
        cout << endl;
    }
    cout << "------------------------\n";
}

void Player::useItem() {

}

void Player::changeGold(int goldChange) {

}

void Player::changeEXP(int expChange) {
    if (expChange < 0) { //Checks to see if the EXP change is negative.
        throw logic_error("Can not change EXP by a negative amount."); //Throws error if the exp change is negative.
    }
    this->exp += expChange; //Add the EXP change to the Player's EXP.
    while (this->exp >= this->expToNextLevel()) { //Repeats until the remaining EXP can reach the amount of EXP for next level.
        //Subtract the EXP that is required for the next level and increase the Player's level by 1.
        this->exp -= this->expToNextLevel();
        this->level++;
        if (this->level >= this->maxLevel) { //Checks to see it payer reaches MAX level
            //If true, then keep level at max level and EXP will remain 0.
            this->setLevel(maxLevel);
            this->setEXP(0);
            break;
        }
    }
}

int Player::expToNextLevel() {
    //Computes the remaining exp to the next level
    return ((int)(100 * pow(1.25, this->level - 1)) - (int)(100 * pow(1.25, this->level - 1)) % 25);
}