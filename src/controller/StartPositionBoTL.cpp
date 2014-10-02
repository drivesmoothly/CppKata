/*
 * StartPositionBoTL.cpp
 *
 *  Created on: Oct 2, 2014
 *      Author: Marius
 */

#include "StartPositionBoTL.h"
#include "Board.h"

using namespace reversi;

///////////////////////////////////////////////////////////////////////////////
//
void StartPositionBoTL::Run(Board& b)
{
	int size{b.GetSize()};
	b.Reset();
	b.SetValueAt(size / 2 - 1, size / 2 - 1, Board::Black);
	b.SetValueAt(size / 2, size / 2, Board::Black);
	b.SetValueAt(size / 2 - 1, size / 2, Board::White);
	b.SetValueAt(size / 2, size / 2 - 1, Board::White);
}
