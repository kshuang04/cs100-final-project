#include "../header/Event.hpp"
#include "../header/Rock_Paper_Scissors.hpp"
#include "gtest/gtest.h"

TEST(RockPaperScissors, DetermineWinner) {
    RockPaperScissors game;

    EXPECT_EQ(game.determineWinner("R", 0), "tie");
    EXPECT_EQ(game.determineWinner("R", 2), "You win");
    EXPECT_EQ(game.determineWinner("R", 1), "You lose");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}