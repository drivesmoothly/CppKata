/*
 * game.test.cpp
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Game.h"
#include "Board.h"
#include "StartPositionWoTL.h"
#include "MockStartPosition.h"

using namespace reversi;

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

TEST(GameTest, TestNewGame)
{
	Board b{};
	Game g{b};
}

TEST(GameTest, TestNewGameDefaultBoardConfiguration)
{
	Board b{};
	Game g{b};

	g.NewGame();

	ASSERT_EQ(Board::Black, b.GetValueAt(3, 3));
	ASSERT_EQ(Board::Black, b.GetValueAt(4, 4));
	ASSERT_EQ(Board::White, b.GetValueAt(3, 4));
	ASSERT_EQ(Board::White, b.GetValueAt(4, 3));
}

TEST(GameTest, TestDefaultBoardConfigurationWithSize6)
{
	Board b{6};
	Game g{b};
	g.NewGame();

	ASSERT_EQ(Board::Black, b.GetValueAt(2, 2));
	ASSERT_EQ(Board::Black, b.GetValueAt(3, 3));
	ASSERT_EQ(Board::White, b.GetValueAt(2, 3));
	ASSERT_EQ(Board::White, b.GetValueAt(3, 2));
}

TEST(GameTest, TestNewGameWithStartPositionWoTL)
{
	Board b{};
	StartPositionWoTL sp;
	Game g{b, sp};

	g.NewGame();

	ASSERT_EQ(Board::White, b.GetValueAt(3, 3));
	ASSERT_EQ(Board::White, b.GetValueAt(4, 4));
	ASSERT_EQ(Board::Black, b.GetValueAt(3, 4));
	ASSERT_EQ(Board::Black, b.GetValueAt(4, 3));
}

TEST(GameTest, TestNewGameCallsStartPositionRun)
{
	MockStartPosition sp{};
	sp.SetUp();

	EXPECT_CALL(sp, Run(_)).Times(AtLeast(1));
	ASSERT_EQ(true, sp.Foo());

	Board b{};
	Game g{b, sp};

	g.NewGame();
}
