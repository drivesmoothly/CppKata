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

TEST(BoardTest, Test2BlacksOnNewBoard)
{
	reversi::Board b{};
	ASSERT_EQ(2, b.GetBlackCount());
	ASSERT_EQ('B', b.GetValueAt(3, 3));
	ASSERT_EQ('B', b.GetValueAt(4, 4));
}

TEST(BoardTest, Test2WhitesOnNewBoard)
{
	reversi::Board b{};
	ASSERT_EQ(2, b.GetWhiteCount());
	ASSERT_EQ('W', b.GetValueAt(3, 4));
	ASSERT_EQ('W', b.GetValueAt(4, 3));
}

TEST(BoardTest, TestInitialSize)
{
	reversi::Board b{};
	ASSERT_EQ(8, b.GetSize());
}
