/*
 * possibilitiesfiller.test.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: Marius
 */

#include "PossibilitiesFiller.h"
#include "Board.h"
#include "gtest/gtest.h"

TEST(PossibilitiesFiller, TestCreateNewFiller)
{
	reversi::Board b;
	reversi::PossibilitiesFiller filler(b);
}

TEST(PossibilitiesFiller, TestFillWhiteOnDefaultBoard)
{
	reversi::Board b;
	reversi::PossibilitiesFiller filler(b);
	filler.FillWhite();

	ASSERT_EQ(1, b.GetValueAt(3, 2));
}
