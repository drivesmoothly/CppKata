/*
 * StartPositionBoTL.cpp
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */


#include "StartPositionBoTL.h"
#include "Board.h"

using namespace reversi;

///////////////////////////////////////////////////////////////////////////////
//
void StartPositionBoTL::Run(Board& b)
{
	int size = b.GetSize();
	b.SetValueAt(size / 2 - 1, size / 2 - 1, Board::Black);
	b.SetValueAt(size / 2, size / 2, Board::Black);
	b.SetValueAt(size / 2 - 1, size / 2, Board::White);
	b.SetValueAt(size / 2, size / 2 - 1, Board::White);
}



