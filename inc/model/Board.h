/*
 * Board.h
 *
 *  Created on: Sep 29, 2014
 *      Author: Marius
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <iostream>
#include <stdexcept>

namespace reversi
{

	/**
	 * Stores a board.
	 */
	class Board
	{
	private:
		/// Stores the board size
		unsigned int _size;
		/// A vector of values
		std::vector<char> _matrix;

	public:
		/**
		 * Constructor.
		 * @param size The size of the board. Defaults to 8.
		 */
		Board(unsigned int size = 8);

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
		inline char GetValueAt(unsigned int row, unsigned int col) const;

		/**
		 * Sets a value at a specific coordinate.
		 * @param row The row coordinate.
		 * @param col The column coordinate.
		 * @param val The value to set.
		 */
		inline void SetValueAt(unsigned int row, unsigned int col, char val);

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

		/**
		 * Resets the board to empty.
		 * @param size The new size of the board.
		 */
		void Reset(int size = 8);

		/**
		 * Serializes the board to the given output stream.
		 * @param os The output stream to serialize to.
		 */
		void Serialize(std::ostream& os) const;
	};

	/**
	 * Read a board from stream.
	 * @param is The input stream to read from.
	 * @param b The board to read to.
	 * @return A reference to the same istream for chaining operations.
	 */
	std::istream& operator >>(std::istream& is, Board& b);

	/**
	 * Writes a board to a stream.
	 * @param os The output stream to write to.
	 * @param b The board to write.
	 * @return A reference to the same ostream for chaining operations.
	 */
	std::ostream& operator <<(std::ostream& os, const Board& b);

	///////////////////////////////////////////////////////////////////////////////
	//
	inline char Board::GetValueAt(unsigned int row, unsigned int col) const
	{
		return _matrix.at(col + row * _size);
	}

	///////////////////////////////////////////////////////////////////////////////
	//
	inline void Board::SetValueAt(unsigned int row, unsigned int col, char val)
	{
		_matrix.at(col + row * _size) = val;
	}

	///////////////////////////////////////////////////////////////////////////////
	//
	inline int Board::GetSize() const
	{
		return _size;
	}
}

#endif /* BOARD_H_ */
