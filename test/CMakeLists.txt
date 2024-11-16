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

add_executable(runScreenTests
    screenTest.cpp
    ../src/screen.cpp
    ../src/mainMenuScreen.cpp
    ../src/loseScreen.cpp
    ../src/winScreen.cpp
    ../src/shopScreen.cpp
    ../src/Player.cpp
)

TARGET_LINK_LIBRARIES(runPlayerTests gtest)
TARGET_COMPILE_DEFINITIONS(runPlayerTests PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(runScreenTests gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(runScreenTests PRIVATE gtest_disable_pthreads=ON)