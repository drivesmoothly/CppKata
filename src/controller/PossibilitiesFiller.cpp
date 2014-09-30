/*
 * possibilitiesfiller.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: Marius
 */

#include "PossibilitiesFiller.h"
#include "Board.h"

using namespace reversi;

///////////////////////////////////////////////////////////////////////////////
//
PossibilitiesFiller::PossibilitiesFiller(Board& b)
: _board{b}
{
}

///////////////////////////////////////////////////////////////////////////////
//
void PossibilitiesFiller::FillWhite()
{
	char possibility{1};
	for (int i{ 0 }; i != _board.GetSize(); ++i)
		for (int j{ 0 }; j != _board.GetSize(); ++j)
			if (_board.GetValueAt(i, j) == '.')
			{
				// Case 1, we have a Black below.
				if ((j < _board.GetSize() - 1) && (_board.GetValueAt(i, j + 1) == 'B'))
				{
					if (_board.FindOnColumn(i, 'W') > j + 1)
						_board.SetValueAt(i, j, possibility++);
				}
			}
}
