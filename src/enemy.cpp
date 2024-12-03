#include "../header/enemy.hpp"

Enemy::Enemy(int maxHealth, int defense, int attackPower, int exp, int gold, string enemyName, int stageNum, int regionNum) : maxHealth(maxHealth), defense(defense), attackPower(attackPower), expAmount(exp),
                                                                                                                              goldAmount(gold), name(enemyName), stage(stageNum), region(regionNum), alive(true)
{
    health = maxHealth;
}

Enemy::Enemy()
{
}


int Enemy::attack(Player* target) {
    int calcuTargetDefense = attackPower - target->getDefenseStat();
    if (calcuTargetDefense < 0) 
        calcuTargetDefense = 0;
    target->setHP(target->getHP() - calcuTargetDefense);
    return calcuTargetDefense;
}

void Enemy::gotAttack(int playerDamage)
{
    double defensePercent = defense / 100.0;
    double totalDamage = playerDamage - (playerDamage * defensePercent);
    health -= totalDamage;
    if (health <= 0)
    {
        health = 0;
        alive = false;
    }
}

Item *Enemy::releaseDrops()
{
    srand(time(0));

    int random = (rand() % 3) + 1;

    vector<Item*> listOfItems = generateItem();

    Item *drop;

    for (unsigned i = 0; i < listOfItems.size(); i++)
    {
        if (listOfItems.at(i)->getStage() == stage && random == listOfItems.at(i)->getRarity())
        {
            drop = listOfItems.at(i);
        }
        else
            delete listOfItems.at(i);
    }
    return drop;
}

bool Enemy::isAlive()
{
    return alive;
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

int Enemy::getAttackPower()
{
    return attackPower;
}