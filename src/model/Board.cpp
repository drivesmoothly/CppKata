/*
 * Board.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: Marius
 */

#include "Board.h"
#include <algorithm>

using namespace reversi;

///////////////////////////////////////////////////////////////////////////////
//
Board::Board(int size)
: _size{ size }
, _matrix( size * size, '.' )
{
	SetValueAt(size / 2 - 1, size / 2 - 1, 'B');
	SetValueAt(size / 2, size / 2, 'B');
	SetValueAt(size / 2 - 1, size / 2, 'W');
	SetValueAt(size / 2, size / 2 - 1, 'W');
}

///////////////////////////////////////////////////////////////////////////////
//
int Board::GetBlackCount() const
{
	return std::count_if(_matrix.begin(), _matrix.end(), [](char c){ return (c == 'B');} );
}

///////////////////////////////////////////////////////////////////////////////
//
int Board::GetWhiteCount() const
{
	return std::count_if(_matrix.begin(), _matrix.end(), [](char c){ return (c == 'W');} );
}

///////////////////////////////////////////////////////////////////////////////
//
int Board::FindOnColumn(int col, char value) const
{
	for (int i{0}; i != _size; ++i)
		if (GetValueAt(i, col) == value)
			return i;
	return -1;
}
