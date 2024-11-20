CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(test/googletest)

add_executable(runPlayerTests
    test/playerTest.cpp
    src/Player.cpp
    src/Item.cpp
    test/stubs/AttackItemStub.cpp
    test/stubs/DefenseItemStub.cpp
    test/stubs/HealthItemStub.cpp
    test/stubs/HealingPotStub.cpp
    test/stubs/MaxHPPotStub.cpp
    src/enemy.cpp
    test/enemyTest.cpp
)

add_executable(playGame
    src/main.cpp
    src/Player.cpp
    src/Item.cpp
    src/screen.cpp
    src/enemy.cpp
    src/level.cpp

    test/stubs/levelStub.cpp
)

add_executable(runChestTest
    src/chest.cpp
    src/Player.cpp
    src/Item.cpp
    test/chestTest.cpp
)

TARGET_LINK_LIBRARIES(runPlayerTests gtest)
TARGET_COMPILE_DEFINITIONS(runPlayerTests PRIVATE gtest_disable_pthreads=ON)

target_link_libraries(runChestTest gtest)