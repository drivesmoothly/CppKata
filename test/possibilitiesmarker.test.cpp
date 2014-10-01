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

TEST(PossibilitiesFiller, TestMarkFirstWhiteOnDefaultBoard)
{
	// ........
	// ........
	// ...1....
	// ...BW...
	// ...WB...
	// ........
	// ........
	// ........
	reversi::Board b;
	reversi::Game g{b};
	reversi::PossibilitiesMarker marker{b};

	g.NewGame();
	marker.MarkForWhite();

	ASSERT_EQ(1, b.GetValueAt(2, 3));
}

TEST(PossibilitiesFiller, TestMarkSecondWhite)
{
	reversi::Board b;
	reversi::PossibilitiesMarker marker{b};

	std::string input{
		"........\n"
		"........\n"
		"........\n"
		"...BBB..\n"
		"...WWW..\n"
	};
	std::stringstream ss{input};
	ss >> b;

	marker.MarkForWhite();

	ASSERT_EQ(2, b.GetValueAt(2, 4));
}
