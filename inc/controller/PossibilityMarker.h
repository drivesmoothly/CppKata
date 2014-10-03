/*
 * PossibilityMarker.h
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#ifndef POSSIBILITYMARKER_H_
#define POSSIBILITYMARKER_H_

#include "Board.h"

namespace reversi
{
	/**
	 * Marks possibilities on a board.
	 */
	class PossibilityMarker
	{
	private:
		/**
		 * Stores the board.
		 */
		Board& _board;

	public:
		/**
		 * Constructor, takes a board.
		 * @param board The board to work on.
		 */
		PossibilityMarker(Board& board);

		/**
		 * Marks possibilities for the white player.
		 */
		void MarkForWhite();

	private:
		bool MarkFor(int row, int col, int dr, int dc, Board::Counter c,
				int& index);
	};

}

#endif /* POSSIBILITYMARKER_H_ */
