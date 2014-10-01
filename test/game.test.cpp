
#include "Game.h"
#include "Board.h"
#include "gtest/gtest.h"

using namespace reversi;

TEST(GameTest, TestNewGameBoard)
{
	Board b{8};
	Game g(b);

	g.NewGame();

	ASSERT_EQ(2, b.GetBlackCount());
	ASSERT_EQ(Board::Black, b.GetValueAt(3, 3));
	ASSERT_EQ(Board::Black, b.GetValueAt(4, 4));

	ASSERT_EQ(2, b.GetWhiteCount());
	ASSERT_EQ(Board::White, b.GetValueAt(3, 4));
	ASSERT_EQ(Board::White, b.GetValueAt(4, 3));
}
