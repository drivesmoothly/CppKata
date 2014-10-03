/*
 * PossibilityMarker.cpp
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#include "PossibilityMarker.h"
#include "Board.h"

using namespace reversi;

///////////////////////////////////////////////////////////////////////////////
//
PossibilityMarker::PossibilityMarker(Board& board)
: _board{board}
{

}

///////////////////////////////////////////////////////////////////////////////
//
bool PossibilityMarker::MarkFor(int row, int col, int dr, int dc,
		Board::Counter c, int& index)
{
	int r2 = row + 2 * dr;
	int c2 = col + 2 * dc;
	if (r2 >= 0 && c2 >= 0 && r2 < _board.GetSize() && c2 < _board.GetSize() &&_board.GetValueAt(row + dr, col + dc) == GetOpposite(c))
	{
		int next_row{r2};
		int next_col{c2};
		while (next_row < _board.GetSize() && next_col < _board.GetSize() &&
				_board.GetValueAt(next_row, next_col) == GetOpposite(c))
		{
			next_row += dr;
			next_col += dc;
		}
		if (next_row < _board.GetSize() && next_col < _board.GetSize() &&
				_board.GetValueAt(next_row, next_col) == c)
		{
			_board.SetValueAt(row, col, index++);
			return true;
		}
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////
//
void PossibilityMarker::MarkForWhite()
{
	int index{};
	for (int row{}; row != _board.GetSize(); ++row)
		for (int col{}; col != _board.GetSize(); ++col)
		{
			if (_board.GetValueAt(row, col) == Board::Empty)
			{
				MarkFor(row, col, 1, 0, Board::White, index) ||
				MarkFor(row, col, 0, 1, Board::White, index) ||
				MarkFor(row, col, -1, 0, Board::White, index) ||
				MarkFor(row, col, 0, -1, Board::White, index) ||
				MarkFor(row, col, 1, 1, Board::White, index) ||
				MarkFor(row, col, -1, -1, Board::White, index) ||
				MarkFor(row, col, 1, -1, Board::White, index) ||
				MarkFor(row, col, -1, 1, Board::White, index);
			}
		}
}
