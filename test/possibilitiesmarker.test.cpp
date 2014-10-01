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

TEST(PossibilitiesFiller, TestCreateNewFiller)
{
	reversi::Board b;
	reversi::PossibilitiesMarker filler(b);
}

TEST(PossibilitiesFiller, TestMarkFirstWhiteOnDefaultBoard)
{
	reversi::Board b;
	reversi::Game g{b};
	g.NewGame();
	reversi::PossibilitiesMarker filler(b);
	filler.MarkForWhite();

	ASSERT_EQ(1, b.GetValueAt(2, 3));
}
//
//TEST(PossibilitiesFiller, TestFillSecondWhiteOnDefaultBoard)
//{
//	reversi::Board b;
//	reversi::PossibilitiesFiller filler(b);
//
//	b.SetValueAt(3, 5, 'B');
//	filler.FillWhite();
//
//	ASSERT_EQ(2, b.GetValueAt(2, 5));
//}
