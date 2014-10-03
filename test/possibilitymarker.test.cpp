/*
 * possibilitymarker.test.cpp
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#include "gtest/gtest.h"
#include "Board.h"
#include "PossibilityMarker.h"
#include "Game.h"

using namespace reversi;

TEST(PossibilityMarkerTest, TestPossibilitiesForWhiteOnDefaultBoard)
{
	Board b{};
	Game g{b};
	g.NewGame();
	PossibilityMarker m{b};

	m.MarkForWhite();
	ASSERT_EQ(0, b.GetValueAt(2, 3));
	ASSERT_EQ(1, b.GetValueAt(3, 2));
	ASSERT_EQ(2, b.GetValueAt(4, 5));
	ASSERT_EQ(3, b.GetValueAt(5, 4));
}

TEST(PossibilityMarkerTest, TestForWhiteAfter3Moves)
{
	Board b{};
	Game g{b};
	g.NewGame();
	PossibilityMarker m{b};

	b.SetValueAt(4, 2, Board::Black);
	b.SetValueAt(4, 3, Board::Black);
	b.SetValueAt(4, 4, Board::White);
	b.SetValueAt(5, 2, Board::White);
	b.SetValueAt(5, 3, Board::White);
	b.SetValueAt(5, 4, Board::White);


	m.MarkForWhite();
	ASSERT_EQ(0, b.GetValueAt(2, 2));
	ASSERT_EQ(1, b.GetValueAt(2, 3));
	ASSERT_EQ(2, b.GetValueAt(3, 1));
	ASSERT_EQ(3, b.GetValueAt(3, 2));
	ASSERT_EQ(4, b.GetValueAt(4, 1));
}
