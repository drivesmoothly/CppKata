/*
 * possibilitiesfiller.test.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: Marius
 */

#include "PossibilitiesMarker.h"
#include "Board.h"
#include "Game.h"
#include "gtest/gtest.h"

TEST(PossibilitiesFiller, TestCreateNewMarker)
{
	reversi::Board b;
	reversi::PossibilitiesMarker marker{b};
}

TEST(PossibilitiesFiller, TestMarkWhiteOnDefaultBoard)
{
	// ........
	// ........
	// ...1....
	// ..2BW...
	// ...WB3..
	// ....4...
	// ........
	// ........
	reversi::Board b;
	reversi::Game g{b};
	reversi::PossibilitiesMarker marker{b};

	g.NewGame();
	marker.MarkForWhite();

	ASSERT_EQ(1, b.GetValueAt(2, 3));
	ASSERT_EQ(2, b.GetValueAt(3, 2));
	ASSERT_EQ(3, b.GetValueAt(4, 5));
	ASSERT_EQ(4, b.GetValueAt(5, 4));
}

TEST(PossibilitiesFiller, TestMark2VerticalWhites)
{
	reversi::Board b;
	reversi::PossibilitiesMarker marker{b};

	std::string input{
		"........\n"
		"........\n"
		"........\n"
		"...BBB..\n"
		"...WWW..\n"
		"........\n"
		"........\n"
		"........\n"
	};
	std::stringstream ss{input};
	ss >> b;

	marker.MarkForWhite();

	ASSERT_EQ(2, b.GetValueAt(2, 4));
}
