#include "../header/enemy.hpp"

Enemy::Enemy(int maxHealth, int defense, int attackPower, int exp, int gold, string enemyName) : maxHealth(maxHealth), defense(defense), attackPower(attackPower), expAmount(exp),
                                                                                                 goldAmount(gold), name(enemyName), alive(true)
{
    health = maxHealth;
}

Enemy::Enemy()
{
}

// Enemy::~Enemy() {
//     delete this;
// }

void Enemy::gotAttack(int playerDamage)
{
    int totalDamage = playerDamage - defense;
    if (totalDamage < 0)
    {
        totalDamage = 0;
    }
    health -= totalDamage;
    if (health <= 0)
    {
        alive = false;
    }
}

bool Enemy::isAlive()
{
    return alive;
}

void Enemy::setDescription(string desc)
{
    description = desc;
}

string Enemy::getName()
{
    return name;
}

int Enemy::getHealth()
{
    return health;
}

int Enemy::getStage()
{
    return stage;
}

int Enemy::getRegion()
{
    return region;
}