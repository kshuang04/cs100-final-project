#include "../header/enemy.hpp"

Enemy::Enemy(int maxHealth, int defense, int attackPower, int exp, int gold, string enemyName, int stageNum, int regionNum) : 
maxHealth(maxHealth), defense(defense), attackPower(attackPower), expAmount(exp),
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

Item * Enemy::releaseDrops() {
    srand(time(0));

    int random = (rand() % 3) + 1;
    vector<Item*> listOfItems = generateItem();

    for (unsigned i = 0; i < listOfItems.size(); i++) {
        if (listOfItems.at(i)->getStage() == stage && random == listOfItems.at(i)->getRarity()) {
            return listOfItems.at(i);
        }
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

vector<Enemy> generateEnemy() {
    vector<Enemy> listOfEnemy;

    int hp;
    int def;
    int atk;
    int exp;
    int gold;
    string name;
    int stage;
    int region;

    ifstream file;
    file.open("src/Enemy.txt");

    if (!(file.is_open())) {
        throw runtime_error("File not open");
    }

    int index;

    while (file >> hp >> def >> atk >> exp >> gold >> name >> stage >> region) {
        
        //Enemy with name with 2 words
        //Replace "_" with " "
        index = name.find("_");
        if (index != string::npos) {
            name.replace(index, 1, " ");
        }

        Enemy newEnemy(hp, def, atk, exp, gold, name, stage, 1);
        listOfEnemy.push_back(newEnemy);
    }
    return listOfEnemy;
}
