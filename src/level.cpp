#include "../header/level.hpp"
#include "../src/enemyManager.cpp"
#include <ctime>   // For time-based random seed
#include <cstdlib> // For rand() and srand()

// Constructor for level, now it populates the list of enemies
level::level(int level, int region)
{
    numLevel = level;
    // Seed the random number generator (to ensure randomness on each program run)
    srand(static_cast<unsigned int>(time(0)));

    // Determine the number of enemies based on level range
    int enemyCount = (level % 10 == 0 || level % 10 <= 3) ? 1 : (level % 10 <= 6) ? 2
                                                                                  : 3;
    int stage = level % 10;

    for (int i = 0; i < enemyCount; i++)
    {
        insertEnemies(level, region, stage); // Insert enemies into list based on level and stage
    }
}

// Function to insert random enemies from the enemyManager
void level::insertEnemies(int level, int region, int stage)
{
    static enemyManager manager; // Make enemyManager static to avoid recreating it multiple times

    bool enemyFound = false; // Flag to check if a valid enemy has been found

    while (!enemyFound)
    {
        // Randomly pick an enemy from the manager's list
        int randomIndex = rand() % manager.enemies.size(); // Get random index in range of enemies vector
        Enemy randomEnemy = manager.enemies[randomIndex];

        // Check if the enemy's stage and region match
        if (randomEnemy.getStage() == stage && randomEnemy.getRegion() == region)
        {
            // If they match, add this enemy to the list
            listOfEnemies.push_back(randomEnemy);
            enemyFound = true; // Valid enemy found, stop the loop
        }
    }
}

int level::getTotalGold()
{
    int totalGold = 0;                       // Initialize the variable to store the total gold
    for (const Enemy &enemy : listOfEnemies) // Loop through all the enemies in the list
    {
        totalGold += enemy.getGold(); // Add the gold of the current enemy to the total
    }
    return totalGold; // Return the total gold
}

vector<Enemy> level::returnEnemyVector()
{
    return listOfEnemies;
}

vector<Enemy *> *level::getListOfEnemies()
{
    // Create a new vector to store pointers to the enemies in listOfEnemies
    vector<Enemy *> *enemyPointerList = new vector<Enemy *>;

    // Populate the vector with addresses of the enemies in listOfEnemies
    for (Enemy &enemy : listOfEnemies)
    {
        enemyPointerList->push_back(&enemy);
    }

    // Return the dynamically allocated vector of enemy pointers
    return enemyPointerList;
}

int level::getLevelNum()
{
    return numLevel;
}

int level::getStage()
{
    return numStage;
}

int level::getRegion()
{
    return numRegion;
}