/*
 * Board.cpp
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#include "Board.h"
#include <stdexcept>

using namespace reversi;

Board::Board(int size)
: _size{size}, _matrix(size * size, Empty)
{
	if (_size < 6)
		throw std::invalid_argument{"Board size cannot be smaller than 6"};
	if (_size % 2)
		throw std::invalid_argument{"Odd size"};
}
