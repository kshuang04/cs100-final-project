#include "../header/Enemy/Enemy.hpp"

Enemy::Enemy(int maxHealth, int attackPower, int defense, int exp, int gold) :
    maxHealth(maxHealth), attackPower(attackPower), defense(defense), expAmount(exp),
    goldAmount(gold), alive(true)
{ 
    health = maxHealth;
}

void Enemy::gotAttack(int damage) {
    health -= damage;
    if (health <= 0) {
        alive = false;
    }
}

bool Enemy::isAlive() {
    return alive;
}

void Enemy::setDescription(string desc) {
    description = desc;
}