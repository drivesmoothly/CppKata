/*
 * board.test.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: Marius
 */

#include "Board.h"
#include "gtest/gtest.h"

TEST(BoardTest, TestCreateNewBoard)
{
	reversi::Board b{8};
}

TEST(BoardTest, TestDefaultSize)
{
	reversi::Board b{};
	ASSERT_EQ(8, b.GetSize());
}
