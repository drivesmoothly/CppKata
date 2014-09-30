/*
 * Board.h
 *
 *  Created on: Sep 29, 2014
 *      Author: Marius
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>

namespace reversi
{

	/**
	 * Stores a board.
	 */
	class Board
	{
	private:
		/// Stores the board size
		int _size;
		/// A vector of values
		std::vector<char> _matrix;

	public:
		/**
		 * Constructor.
		 * @param size The size of the board. Defaults to 8.
		 */
		Board(int size = 8);

		/**
		 * Retrieves the number of black counters in the board.
		 * @return The number of black counters.
		 */
		int GetBlackCount() const;

		/**
		 * Retrieves the number of white counters in the board.
		 * @return The number of white counters.
		 */
		int GetWhiteCount() const;

		/**
		 * Retrieves a value at a specific coordinate.
		 * @param row The row coordinate.
		 * @param col The column coordinate.
		 * @return The value at the coordinates.
		 */
		inline char GetValueAt(int row, int col) const;

		/**
		 * Sets a value at a specific coordinate.
		 * @param row The row coordinate.
		 * @param col The column coordinate.
		 * @param val The value to set.
		 */
		inline void SetValueAt(int row, int col, char val);

		/**
		 * Retrieves the board size.
		 * @return The size.
		 */
		inline int GetSize() const;

		/**
		 * Finds a value on a given column.
		 * @param col The column to find the value in.
		 * @param value The value to find.
		 * @return -1 if not found. The row index if we found it.
		 */
		int FindOnColumn(int col, char value) const;
	};

	///////////////////////////////////////////////////////////////////////////////
	//
	inline char Board::GetValueAt(int row, int col) const
	{
		return _matrix[col + row * _size];
	}

	///////////////////////////////////////////////////////////////////////////////
	//
	inline void Board::SetValueAt(int row, int col, char val)
	{
		_matrix[col + row * _size] = val;
	}

	///////////////////////////////////////////////////////////////////////////////
	//
	inline int Board::GetSize() const
	{
		return _size;
	}

}


#endif /* BOARD_H_ */
