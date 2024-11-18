#include "../header/enemy.hpp"

Enemy::Enemy(int maxHealth, int defense, int attackPower, int exp, int gold, string enemyName) :
    maxHealth(maxHealth), defense(defense), attackPower(attackPower), expAmount(exp),
    goldAmount(gold), name(enemyName), alive(true)
{ 
    health = maxHealth;
}

Enemy::Enemy() {

}

// Enemy::~Enemy() {
//     delete this;
// }

void Enemy::gotAttack(int playerDamage) {
    int totalDamage = playerDamage - defense;
    if (totalDamage < 0) {
        totalDamage = 0;
    }
    health -= totalDamage;
    if (health <= 0) {
        alive = false;
        releaseDrops();
    }
}

bool Enemy::isAlive() {
    return alive;
}

Item Enemy::releaseDrops() {
    srand(time(0));
    GenerateItems item;
    vector<Item*> listOfItems = item.generateItem();
    int randomItem = rand() % 99;
    /*
    for (unsigned i = 0; i < listOfItems.size(); i ++) {
        if (randomItem < 32 && level == listOfItems.getLevel()) {
            return listOfItems.at(i);
        } 
        else if (randomItem < )
    }
    */
}

void Enemy::setDescription(string desc) {
    description = desc;
}

string Enemy::getName() {
    return name;
}

int Enemy::getHealth() {
    return health;
}
int Enemy::getGold() {
    return goldAmount;
}