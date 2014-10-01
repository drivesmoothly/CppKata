/*
 * Board.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: Marius
 */

#include "Board.h"
#include <algorithm>
#include <stdexcept>

using namespace reversi;

///////////////////////////////////////////////////////////////////////////////
//
Board::Board(unsigned int size)
: _size{ size }
, _matrix( size * size, '.' )
{
}

///////////////////////////////////////////////////////////////////////////////
//
int Board::GetBlackCount() const
{
	return std::count_if(_matrix.begin(), _matrix.end(), [](char c) { return c == 'B';} );
}

///////////////////////////////////////////////////////////////////////////////
//
int Board::GetWhiteCount() const
{
	return std::count_if(_matrix.begin(), _matrix.end(), [] (char c){ return c == 'W';} );
}

///////////////////////////////////////////////////////////////////////////////
//
int Board::FindOnColumn(int col, char value) const
{
	for (unsigned int i{0}; i != _size; ++i)
		if (GetValueAt(i, col) == value)
			return i;
	return -1;
}

///////////////////////////////////////////////////////////////////////////////
//
void Board::Reset(int size)
{
	_matrix.resize(size * size, '.');
	std::fill(_matrix.begin(), _matrix.end(), '.');
}

///////////////////////////////////////////////////////////////////////////////
//
void Board::Serialize(std::ostream& os) const
{
	auto it = _matrix.begin();
	for (unsigned int i{0}; i < _size; ++i)
	{
		std::for_each(it, it + _size, [&os](char c){ os << c; });
		it += _size;
		os << std::endl;
	}
}

///////////////////////////////////////////////////////////////////////////////
//
std::istream& reversi::operator >>(std::istream& is, Board& b)
{
	std::string line{};
	is >> line;
	unsigned int size = line.length();
	b.Reset(size);

	const std::string ALLOWED_CHARS{".WB"};
	unsigned int currentLine{0};
	while (currentLine < size)
	{
		int col{0};
		for (auto& c : line)
		{
			if (std::find(ALLOWED_CHARS.begin(), ALLOWED_CHARS.end(), c) == ALLOWED_CHARS.end())
				throw std::invalid_argument{"Invalid characters in input stream"};
			b.SetValueAt(currentLine, col++, c);
		}

		is >> line;
		if (line.length() != size)
			throw std::invalid_argument{"Invalid line size"};
		currentLine++;
	}

	return is;
}

///////////////////////////////////////////////////////////////////////////////
//
std::ostream& reversi::operator <<(std::ostream& os, const Board& b)
{
	b.Serialize(os);
	return os;
}
