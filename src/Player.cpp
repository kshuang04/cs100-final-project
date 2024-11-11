#include "../header/Player.hpp"

//Default Player Constructor
Player::Player() : currHP(20), maxHP(20), level(1), maxLevel(20), exp(0), attackStat(1), defenseStat(1), gold(0) {}

//Specific Player Constructor
Player::Player(int maxHP, int maxLevel, int attack, int defense, int gold) : currHP(maxHP), maxHP(maxHP), level(1), maxLevel(maxLevel), exp(0), attackStat(attack), defenseStat(defense), gold(gold) {}

Player::~Player() {
    //delete[] itemIven;
}

int Player::attack() {

}

// Attack Player::getAttack() {

// }

void Player::printStats() {

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
    while (this->exp >= ((int)(100 * pow(1.25, this->level - 1)) - (int)(100 * pow(1.25, this->level - 1)) % 25)) { //Repeats until the remaining EXP can reach the amount of EXP for next level.
        //Subtract the EXP that is required for the next level and increase the Player's level by 1.
        this->exp -= ((int)(100 * pow(1.25, this->level - 1)) - (int)(100 * pow(1.25, this->level - 1)) % 25);
        this->level++;
        if (this->level >= this->maxLevel) { //Checks to see it payer reaches MAX level
            //If true, then keep level at max level and EXP will remain 0.
            this->setLevel(maxLevel);
            this->setEXP(0);
            break;
        }
    }
}