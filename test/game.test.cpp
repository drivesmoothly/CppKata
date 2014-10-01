
#include "Game.h"
#include "Board.h"
#include "gtest/gtest.h"

TEST(GameTest, TestNewGameBoard)
{
	reversi::Board b{8};
	reversi::Game g(b);
	g.NewGame();

	ASSERT_EQ(2, b.GetBlackCount());
	ASSERT_EQ('B', b.GetValueAt(3, 3));
	ASSERT_EQ('B', b.GetValueAt(4, 4));

	ASSERT_EQ(2, b.GetWhiteCount());
	ASSERT_EQ('W', b.GetValueAt(3, 4));
	ASSERT_EQ('W', b.GetValueAt(4, 3));
}
