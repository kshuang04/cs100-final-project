#include "../header/enemy.hpp"

Enemy::Enemy(int maxHealth, int defense, int attackPower, int exp, int gold, string enemyName, int stageNum, int regionNum) : maxHealth(maxHealth), defense(defense), attackPower(attackPower), expAmount(exp),
                                                                                                                              goldAmount(gold), name(enemyName), stage(stageNum), region(regionNum), alive(true)
{
    health = maxHealth;
}

Enemy::Enemy()
{
}

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

Item *Enemy::releaseDrops()
{
    srand(time(0));

    int random = (rand() % 3) + 1;
    vector<Item *> listOfItems = generateItem();
    Item *drop;

    for (unsigned i = 0; i < listOfItems.size(); i++)
    {
        if (listOfItems.at(i)->getStage() == stage && random == listOfItems.at(i)->getRarity())
        {
            drop = listOfItems.at(i);
        }
    }
    return drop;
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

int Enemy::getMaxHealth()
{
    return maxHealth;
}

int Enemy::getStage()
{
    return stage;
}

int Enemy::getRegion()
{
    return region;
}

int Enemy::getGold() const
{
    return goldAmount;
}



