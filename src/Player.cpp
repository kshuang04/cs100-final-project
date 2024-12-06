#include "../header/Player.hpp"

//Default Player Constructor
Player::Player() : currHP(20), maxHP(20), level(1), maxLevel(20), exp(0), attackStat(1), defenseStat(1), maxHPStat(0), gold(0), isAlive(true), playerIven(new ItemInventory()) {}

//Specific Player Constructor
Player::Player(int maxHP, int maxLevel, int attack, int defense, int gold) : currHP(maxHP), maxHP(maxHP), level(1), maxLevel(maxLevel), exp(0), attackStat(attack), defenseStat(defense), maxHPStat(0), gold(gold), isAlive(true), playerIven(new ItemInventory()) {}

Player::~Player() {
    delete this->getPlayerInven();
}

int Player::attack() {
    //Sets a random seed everytime the function is called.
    srand(time(0));
    //Returns attack damage value from a specific formula.
    return (int)((this->getLevel() * 0.5 * ((rand() % 6) + 4)) + this->getAttackStat());
}

void Player::takeDamage(int damage) {
    if ((this->getHP() - max(0, damage - (this->getDefenseStat() + (3 * (this->getLevel() - 1))))) <= 0) { //Checks to see if the damage results in negative HP.
        //If it does result in negative HP, HP is set to 0 and the player is no longer alive.
        this->setHP(0);
        this->setIsAlive(false);
    } else {
        //If not, decrease the HP by the amount of damage taken (reduced by the defense stat) and the player is still alive.
        this->setHP((this->getHP() - max(0, damage - (this->getDefenseStat() + (3 * (this->getLevel() - 1))))));
        this->setIsAlive(true);
    }
}

void Player::changeGold(int goldChange) {
    if (goldChange < 0) { //Checks to see if there is a need to decease the amount of gold.
        if ((int)(this->getGold() - abs(goldChange)) < 0) { //Checks to see if lowering the amount of gold will result in a negative value.
            //Resulted in a negative value so gold is set to 0.
            this->setGold(0);
        } else {//There is a need to decrease the amount of gold so the change is subtracted from it.
           this->setGold((this->getGold() - abs(goldChange))); 
        }
    } else { //There is a need to increase the amount of gold so the change is added in.
        this->setGold((this->getGold() + abs(goldChange))); 
    }
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
        if (this->level >= this->maxLevel) { //Checks to see if the player reached MAX level
            //If true, then keep level at max level and EXP will remain 0.
            this->setLevel(maxLevel);
            this->setEXP(0);
            break;
        }
        this->setHP(this->getMaxHPFromLevel());
    }
}

int Player::expToNextLevel() {
    //Computes the remaining exp to the next level
    return (int)round((15 + 5 * (this->level - 1) + 2 * pow(1.25, this->level - 1) + 0.1 * pow(this->level - 1, 2)));
}

void Player::resetStats() {
    this->setAttackStat(1);
    this->setDefenseStat(1);
    this->setEXP(0);
    this->setGold(0);
    this->setIsAlive(true);
    this->setLevel(1);
    this->setMaxHPStat(20);
    this->setMaxLevel(20);
}