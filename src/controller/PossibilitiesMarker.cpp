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
void PossibilitiesMarker::MarkForWhite()
{
	Board::value_type possibility{1};
	for (int row{ 0 }; row != _board.GetSize(); ++row)
		for (int col{ 0 }; col != _board.GetSize(); ++col)
			if (_board.GetValueAt(row, col) == Board::Empty)
			{
				// Case 1, we have a Black below.
				if (NextIs(row, col, Board::Black, Point{1, 0}) &&
						FindNextContiguous(row, col, Board::White, [](int& row, int& col){++row;}))
					_board.SetValueAt(row, col, possibility++);
				// Case 2, we have a Black on the right
				else if (NextIs(row, col, Board::Black, Point{0, 1}) &&
						FindNextContiguous(row, col, Board::White, [](int& row, int& col){++col;}))
					_board.SetValueAt(row, col, possibility++);
				// Case 3, we have a Black on the left
				else if (NextIs(row, col, Board::Black, Point{0, -1}) &&
						FindNextContiguous(row, col, Board::White, [](int& row, int& col){--col;}))
					_board.SetValueAt(row, col, possibility++);
				// Case 4, we have a Black on top
				else if (NextIs(row, col, Board::Black, Point{-1, 0}) &&
						FindNextContiguous(row, col, Board::White, [](int& row, int& col){--row;}))
					_board.SetValueAt(row, col, possibility++);
			}
}

///////////////////////////////////////////////////////////////////////////////
//
bool PossibilitiesMarker::FindNextContiguous(int row, int col, Board::Counter v,
		std::function<void(int&, int&)> moveToNext)
{
	moveToNext(row, col);
	while (row < _board.GetSize())
	{
		Board::value_type currentValue = _board.GetValueAt(row, col);
		if (currentValue == v)
			return true;
		else if (currentValue == GetOpposite(v))
			moveToNext(row, col);
		else
			return false;
	}
	return false;
}
