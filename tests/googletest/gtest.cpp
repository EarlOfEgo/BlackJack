#include "gtest/gtest.h"
#include "CheckGame.h"


CheckGame cg;

TEST(CheckActualScoreWithBJ, equal)
{
    int cards[5] = {1, 10, 0, 0, 0};
    int result = cg.checkActualScore(cards);
    EXPECT_EQ(21,result);
}

TEST(CheckActualScoreWithAce, equal)
{
    int cards[5] = {1, 10, 10, 0, 0};
    int result = cg.checkActualScore(cards);
    EXPECT_EQ(21,result);
}

TEST(CheckActualScoreWithAce2, equal)
{
    int cards[5] = {1, 10, 0, 0, 0};
    int result = cg.checkActualScore(cards);
    EXPECT_EQ(21,result);
}

