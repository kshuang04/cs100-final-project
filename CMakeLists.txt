CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(test/googletest)

add_executable(runPlayerTests
    test/playerTest.cpp
    src/Player.cpp
    src/Item.cpp
    stubs/AttackItemStub.cpp
    stubs/DefenseItemStub.cpp
    stubs/HealthItemStub.cpp
    stubs/HealingPotStub.cpp
    stubs/MaxHPPotStub.cpp
)

TARGET_LINK_LIBRARIES(runPlayerTests gtest)
TARGET_COMPILE_DEFINITIONS(runPlayerTests PRIVATE gtest_disable_pthreads=ON)