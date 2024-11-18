#include "../header/Player.hpp"

//Default Player Constructor
Player::Player() : currHP(20), maxHP(20), level(1), maxLevel(20), exp(0), attackStat(1), defenseStat(1), gold(0), itemCount(0), isAlive(true) {}

//Specific Player Constructor
Player::Player(int maxHP, int maxLevel, int attack, int defense, int gold) : currHP(maxHP), maxHP(maxHP), level(1), maxLevel(maxLevel), exp(0), attackStat(attack), defenseStat(defense), gold(gold), itemCount(0), isAlive(true) {}

Player::~Player() {
    //Deletes every item in the item Inventory
    for (int i = 0; i < this->getItemIven().size(); i++) {
        delete this->getItemIven().at(i);
        this->getItemIven().at(i) = nullptr;
    }
}

int Player::attack() {
    //Sets a random seed everytime the function is called.
    srand(time(0));
    //Returns attack damage value from a specific formula.
    return ((int)((this->getLevel() * ((rand() % 11) + (2 * this->getLevel()))) + this->getAttackStat()));
}

void Player::takeDamage(int damage) {
    if ((this->getHP() - damage) <= 0) { //Checks to see if the damage resilts in negative HP.
        //If it does result in negative HP, HP is set to 0 and the player is no longer alive.
        this->setHP(0);
        this->setIsAlive(false);
    } else {
        //If not, decrease the HP by the amount of damage taken and the player is still alive.
        this->setHP((this->getHP() - damage));
        this->setIsAlive(true);
    }
}

void Player::addItem(Item* newItem) {
    //Checks to see if the item iventory is full and throws an errors if it is full
    if ((this->getItemCount() + 1) > this->maxItem) {throw logic_error("You have reached the maximum amount of items.");}
    //Adds the item and increases the item count by 1
    this->getItemIven().push_back(newItem);
    this->setItemCount(this->getItemCount() + 1);
}

void Player::consumeItem(Item* currentItem) {
    //Checks to see if the item is real and availabe
    if (currentItem == nullptr) {throw logic_error("Using an item that does not exist.");}
    //Consumes the item and then remove it
    currentItem->useItem(this);
    delete currentItem;
}

void Player::consumeItem(int itemIndex) {
    //Check to see if the item index is within the range and throws an error if not.
    if (((itemIndex - 1) < 0) || ((itemIndex - 1) > this->getItemCount()) || (this->getItemCount() == 0)) {throw out_of_range("Access an index that is out of range of the item inventory.");}
    //Uses the item and then removes it from the item inventory.
    this->getItemIven().at((itemIndex - 1))->useItem(this);
    this->removeItem(itemIndex);
}

void Player::removeItem(int itemIndex) {
    //Check to see if the item index is within the range and throws an error if not.
    if (((itemIndex - 1) < 0) || ((itemIndex - 1) > this->getItemCount()) || (this->getItemCount() == 0)) {throw out_of_range("Access an index that is out of range of the item inventory.");}
    //Deletes the Item pointer and then removes it from the vector for item inventory, and decreases item count by 1
    delete this->getItemIven().at((itemIndex - 1));
    this->getItemIven().erase(this->getItemIven().begin() + (itemIndex - 1));
    this->setItemCount(this->getItemCount() - 1);
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