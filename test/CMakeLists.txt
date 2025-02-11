CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

add_executable(runPlayerTests
    playerTest.cpp
    ../src/Player.cpp
    ../src/Item.cpp
    ../src/ItemInventory.cpp
    ../src/enemy.cpp
    enemyTest.cpp
    itemTest.cpp
)

add_executable(runChestTest
    ../src/chest.cpp
    ../src/Player.cpp
    ../src/Item.cpp
    ../src/ItemInventory.cpp
    chestTest.cpp
)

TARGET_LINK_LIBRARIES(runPlayerTests gtest)
TARGET_COMPILE_DEFINITIONS(runPlayerTests PRIVATE gtest_disable_pthreads=ON)

target_link_libraries(runChestTest gtest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS --coverage)