
#include "Game.h"
#include "Board.h"
#include "MockStartPosition.h"
#include "gmock/gmock.h"

using namespace reversi;
using ::testing::_;

TEST(GameTest, TestNewGameBoard)
{
	Board b{8};
	Game g{b};

	g.NewGame();

	ASSERT_EQ(2, b.GetBlackCount());
	ASSERT_EQ(Board::Black, b.GetValueAt(3, 3));
	ASSERT_EQ(Board::Black, b.GetValueAt(4, 4));

	ASSERT_EQ(2, b.GetWhiteCount());
	ASSERT_EQ(Board::White, b.GetValueAt(3, 4));
	ASSERT_EQ(Board::White, b.GetValueAt(4, 3));
}

TEST(GameTest, TestStartPositionCalled)
{
	Board b{};
	MockStartPosition spm{};
	EXPECT_CALL(spm, Run(_));

	Game g{b, spm};
	g.NewGame();
}
