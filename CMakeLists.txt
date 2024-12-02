CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(test/googletest)

add_executable(game
    src/main.cpp
    src/enemy.cpp
    src/enemyManager.cpp
    src/Item.cpp
    src/ItemInventory.cpp
    src/level.cpp
    src/Player.cpp
    src/screen.cpp
    src/shop.cpp
)


# add_executable(runPlayerTests
#     test/playerTest.cpp
#     src/Player.cpp
#     src/Item.cpp
#     src/ItemInventory.cpp
#     test/stubs/AttackItemStub.cpp
#     test/stubs/DefenseItemStub.cpp
#     test/stubs/HealthItemStub.cpp
#     test/stubs/HealingPotStub.cpp
#     test/stubs/MaxHPPotStub.cpp
#     src/enemy.cpp
#     test/enemyTest.cpp
# )

# add_executable(playGame
#     src/main.cpp
#     src/Player.cpp
#     src/Item.cpp
#     src/screen.cpp
#     src/enemy.cpp
#     src/level.cpp
#     src/ItemInventory.cpp
#     src/shop.cpp
#     test/stubs/levelStub.cpp
# )

add_executable(runScreenTests
    test/screenTest.cpp
    src/screen.cpp
    src/Player.cpp
    src/Item.cpp
    src/enemy.cpp
    src/level.cpp
    src/ItemInventory.cpp
    src/shop.cpp
)

# add_executable(runChestTest
#     src/chest.cpp
#     src/Player.cpp
#     src/Item.cpp
#     test/chestTest.cpp
#     src/ItemInventory.cpp
# )

add_executable(runShopTests
    test/shopTest.cpp
    src/shop.cpp
    src/Player.cpp
    src/Item.cpp
    src/ItemInventory.cpp
)

# TARGET_LINK_LIBRARIES(runPlayerTests gtest)
# TARGET_COMPILE_DEFINITIONS(runPlayerTests PRIVATE gtest_disable_pthreads=ON)

# TARGET_LINK_LIBRARIES(playGame gtest)

TARGET_LINK_LIBRARIES(runScreenTests gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(runScreenTests PRIVATE gtest_disable_pthreads=ON)

# target_link_libraries(runChestTest gtest)

TARGET_LINK_LIBRARIES(runShopTests gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(runShopTests PRIVATE gtest_disable_pthreads=ON)