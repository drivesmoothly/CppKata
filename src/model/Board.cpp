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
, _matrix( size * size, Board::Empty )
{
}

///////////////////////////////////////////////////////////////////////////////
//
int Board::GetBlackCount() const
{
	return std::count_if(_matrix.begin(), _matrix.end(),
			[](value_type c) { return c == Board::Black;} );
}

///////////////////////////////////////////////////////////////////////////////
//
int Board::GetWhiteCount() const
{
	return std::count_if(_matrix.begin(), _matrix.end(),
			[] (value_type c){ return c == Board::White;} );
}

///////////////////////////////////////////////////////////////////////////////
//
int Board::FindOnColumn(int col, value_type value) const
{
	for (unsigned int i{0}; i != _size; ++i)
		if (GetValueAt(i, col) == value)
			return i;
	return -1;
}

///////////////////////////////////////////////////////////////////////////////
//
int Board::FindOnRow(int row, value_type value) const
{
	for (unsigned int i{0}; i != _size; ++i)
		if (GetValueAt(row, i) == value)
			return i;
	return -1;
}

///////////////////////////////////////////////////////////////////////////////
//
void Board::Reset(int size)
{
	_matrix.resize(size * size);
	std::fill(_matrix.begin(), _matrix.end(), Board::Empty);
}

///////////////////////////////////////////////////////////////////////////////
//
void Board::Serialize(std::ostream& os) const
{
	auto it = _matrix.begin();
	for (unsigned int i{0}; i < _size; ++i)
	{
		std::for_each(it, it + _size, [&os](value_type c)
			{
				switch (c)
				{
				case Board::Black:
					os << 'B';
					break;
				case Board::White:
					os << 'W';
					break;
				case Board::Empty:
					os << '.';
					break;
				default:
					{
						int val = c;
						os << val;
						break;
					}
				}
			});
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
	if (!is.good())
		throw std::invalid_argument("Invalid board");
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
			b.SetValueAt(currentLine, col++, c == '.' ? Board::Empty : c == 'W' ? Board::White : Board::Black);
		}

		currentLine++;
		if (currentLine < size)
		{
			is >> line;
			if (!is.good())
				throw std::invalid_argument("Invalid board");
			if (line.length() != size)
				throw std::invalid_argument{"Invalid line size"};
		}
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
