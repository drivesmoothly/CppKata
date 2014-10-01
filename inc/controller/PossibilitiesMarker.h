/*
 * PossibilitiesFiller.h
 *
 *  Created on: Sep 30, 2014
 *      Author: Marius
 */

#ifndef POSSIBILITIESMARKER_H_
#define POSSIBILITIESMARKER_H_

#include "Board.h"
#include <functional>

namespace reversi
{
	/**
	 * Responsible for filling the possibilities.
	 */
	class PossibilitiesMarker
	{
	private:
		/**
		 * Stores a reference to the board.
		 */
		Board& _board;

	public:
		/**
		 * Constructor. Takes the board as an argument.
		 * @param b The board.
		 */
		PossibilitiesMarker(Board& b);

		/**
		 * Fills the possibilities for white.
		 */
		void MarkForWhite();

	private:

		/**
		 * Stores a direction to move the cursor to.
		 */
		struct Point
		{
			int r;
			int c;
		};

		/**
		 * Checks if the cell to the left of the given coordinates has the given value.
		 * @param row The row of the cell to check on the left.
		 * @param col The column of the cell to check on the left.
		 * @param v The value to look for.
		 * @return true if it matches, false otherwise.
		 */

		inline bool NextIs(int row, int col, Board::Counter v, Point direction);

		/**
		 * Checks if there is a "v" below the given coordinates in a contiguous column.
		 * @param row The row coordinate.
		 * @param col The column coordinate.
		 * @param v The value to find.
		 * @return true if found, false if not.
		 */
		bool FindNextContiguous(int row, int col, Board::Counter v,
				std::function<void(int&, int&)> moveToNext);

	};

	///////////////////////////////////////////////////////////////////////////////
	//
	inline bool PossibilitiesMarker::NextIs(int row, int col, Board::Counter v, Point direction)
	{
		direction.c += col;
		direction.r += row;
		return (direction.r >= 0) && (direction.c >= 0) &&
				(direction.r < _board.GetSize()) && (direction.c < _board.GetSize()) &&
				(_board.GetValueAt(direction.r, direction.c) == v);
	}
}


#endif /* POSSIBILITIESMARKER_H_ */
