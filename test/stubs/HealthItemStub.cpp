#include "../stubs/HealthItemStub.hpp"

HealthItemStub::HealthItemStub() : healthPower(0), Item("NULL", "NULL", 1, 1) {}

HealthItemStub::~HealthItemStub() {}

HealthItemStub::HealthItemStub(int healthIncrease, int levelType, string name, int rarity, string description) : healthPower(healthIncrease)
{
    this->itemName = name;
    this->stageType = levelType;
    this->rarity = rarity;
    this->description = description;
}

int HealthItemStub::getHealthPower() {
    return this->healthPower;
}