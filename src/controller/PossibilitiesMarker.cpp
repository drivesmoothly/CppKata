/*
 * possibilitiesfiller.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: Marius
 */

#include "PossibilitiesMarker.h"
#include "Board.h"

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
	char possibility{1};
	for (int i{ 0 }; i != _board.GetSize(); ++i)
		for (int j{ 0 }; j != _board.GetSize(); ++j)
			if (_board.GetValueAt(i, j) == '.')
			{
				// Case 1, we have a Black below.
				if ((i < _board.GetSize() - 1) && (_board.GetValueAt(i + 1, j) == 'B'))
				{
					if (_board.FindOnColumn(j, 'W') > i + 1)
						_board.SetValueAt(i, j, possibility++);
				}
			}
}
