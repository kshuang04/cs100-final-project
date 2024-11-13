CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

add_executable(runPlayerTests
    playerTest.cpp
    ../src/Player.cpp
    ../src/Item.cpp
    ../stubs/AttackItemStub.cpp
    ../stubs/DefenseItemStub.cpp
    ../stubs/HealthItemStub.cpp
    ../stubs/HealingPotStub.cpp
    ../stubs/MaxHPPotStub.cpp

    ../src/enemy.cpp
    enemyTest.cpp
)

TARGET_LINK_LIBRARIES(runPlayerTests gtest)
TARGET_COMPILE_DEFINITIONS(runPlayerTests PRIVATE gtest_disable_pthreads=ON)