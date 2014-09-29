/*
 * board.test.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: Marius
 */

#include "Board.h"
#include "gtest/gtest.h"

TEST(BoardTest, TestEmptyBoard)
{
	reversi::Board b(8);
}
