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
