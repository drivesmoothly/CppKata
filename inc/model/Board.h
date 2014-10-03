/*
 * Board.h
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <stdexcept>

namespace reversi
{
	/**
	 * Stores the board.
	 */
	class Board
	{
	public:
		/**
		 * Type used to store the values in the matrix.
		 */
		using value_type = unsigned char;

		/**
		 * Defines constants for counters.
		 */
		enum Counter
		{
			White = 253,//!< White
			Black = 254,//!< Black
			Empty = 255//!< Empty
		};

	private:
		/**
		 * Stores the board size.
		 */
		int _size;

		/**
		 * Stores the matrix elements.
		 */
		std::vector<value_type> _matrix;

	public:
		/**
		 * Constructor for board. Takes the size argument.
		 * @param size The board size.
		 */
		Board(int size = 8);

		/**
		 * Retrieves the board size.
		 * @return The board size.
		 */
		inline int GetSize() const;

		/**
		 * Retrieves the value in the cell at given coordinates.
		 * @param row The row of the cell.
		 * @param col The column of the cell.
		 * @return The value.
		 */
		inline value_type GetValueAt(int row, int col) const;

		/**
		 * Sets a value to a cell at the given coordinates.
		 * @param row The row of the cell.
		 * @param col The column of the cell.
		 * @param val The new value.
		 */
		inline void SetValueAt(int row, int col, value_type val);
	};

	///////////////////////////////////////////////////////////////////////////
	//
	inline int Board::GetSize() const
	{
		return _size;
	}

	///////////////////////////////////////////////////////////////////////////
	//
	inline Board::value_type Board::GetValueAt(int row, int col) const
	{
		return _matrix.at(col + row * _size);
	}

	///////////////////////////////////////////////////////////////////////////
	//
	inline void Board::SetValueAt(int row, int col, value_type val)
	{
		_matrix.at(col + row * _size) = val;
	}

	///////////////////////////////////////////////////////////////////////////
	//
	inline Board::Counter GetOpposite(Board::Counter c)
	{
		switch (c)
		{
		case Board::Black:
			return Board::White;
		case Board::White:
			return Board::Black;
		default:
			throw std::invalid_argument{"Invalid counter"};
		}
	}
}

#endif /* BOARD_H_ */
