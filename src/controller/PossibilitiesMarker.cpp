/*
 * possibilitiesfiller.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: Marius
 */

#include "PossibilitiesMarker.h"

using namespace reversi;

///////////////////////////////////////////////////////////////////////////////
//
PossibilitiesMarker::PossibilitiesMarker(Board& b)
: _board{b}
{
}

///////////////////////////////////////////////////////////////////////////////
//
void PossibilitiesMarker::MarkFor(Board::Counter counter)
{
	Board::value_type index{1};
	for (int row{ 0 }; row != _board.GetSize(); ++row)
		for (int col{ 0 }; col != _board.GetSize(); ++col)
			if (_board.GetValueAt(row, col) == Board::Empty)
			{
				MarkFor(row, col, counter, Point{1, 0}, index) ||
				MarkFor(row, col, counter, Point{-1, 0}, index) ||
				MarkFor(row, col, counter, Point{0, 1}, index) ||
				MarkFor(row, col, counter, Point{0, -1}, index) ||

				MarkFor(row, col, counter, Point{1, 1}, index) ||
				MarkFor(row, col, counter, Point{1, -1}, index) ||
				MarkFor(row, col, counter, Point{-1, 1}, index) ||
				MarkFor(row, col, counter, Point{-1, -1}, index);
			}
}

///////////////////////////////////////////////////////////////////////////////
//
bool PossibilitiesMarker::MarkFor(int row, int col, Board::Counter val, Point dir, Board::value_type& index)
{
	Board::Counter opposite = static_cast<Board::Counter>(GetOpposite(val));
	if (NextIs(row, col, opposite, dir) && FindNextContiguous(row, col, val, dir))
	{
		_board.SetValueAt(row, col, index++);
		return true;
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////
//
bool PossibilitiesMarker::FindNextContiguous(int row, int col, Board::Counter v, Point direction)
{
	Point position = direction;
	position.r += row;
	position.c += col;
	while (position.r >= 0 && position.r < _board.GetSize() &&
			position.c >= 0 && position.c < _board.GetSize())
	{
		Board::value_type currentValue = _board.GetValueAt(position.r, position.c);
		if (currentValue == v)
		{
			return true;
		}
		else if (currentValue == GetOpposite(v))
		{
			position.r += direction.r;
			position.c += direction.c;
		}
		else
		{
			return false;
		}
	}
	return false;
}
