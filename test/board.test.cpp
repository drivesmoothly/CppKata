/*
 * board.test.cpp
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#include "gtest/gtest.h"
#include "Board.h"

using namespace reversi;

TEST(BoardTest, TestBoardCanBeCreated)
{
	Board b;
}

TEST(BoardTest, TestCreateBoardWithGivenDimension)
{
	Board b{6};
	ASSERT_EQ(6, b.GetSize());
}

TEST(BoardTest, TestDefaultSizeIs8)
{
	Board b{};
	ASSERT_EQ(8, b.GetSize());
}

TEST(BoardTest, TestMinimumBoardSizeIs6)
{
	ASSERT_THROW(Board b{5}, std::invalid_argument);
}

TEST(BoardTest, TestGetValueAtOutOfRange)
{
	Board b{};
	ASSERT_THROW(b.GetValueAt(-1, -1), std::out_of_range);
}

TEST(BoardTest, TestBoardWithOddSize)
{
	ASSERT_THROW(Board b{7}, std::invalid_argument);
}
