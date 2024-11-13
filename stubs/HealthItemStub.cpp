#include "../stubs/HealthItemStub.hpp"

HealthItemStub::HealthItemStub() : healthPower(0), Item("NULL", "NULL") {}

HealthItemStub::~HealthItemStub() {}

HealthItemStub::HealthItemStub(string newItemName, int newHealthPower, string newDescription)
    : healthPower(newHealthPower), Item(newItemName, newDescription) {}

int HealthItemStub::getHealthPower() {
    return this->healthPower;
}