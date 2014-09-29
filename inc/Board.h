/*
 * Board.h
 *
 *  Created on: Sep 29, 2014
 *      Author: Marius
 */

#ifndef BOARD_H_
#define BOARD_H_

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

public:
	/**
	 * Constructor.
	 * @param size The size of the board. Defaults to 8.
	 */
	Board(int size = 8);
};

}

#endif /* BOARD_H_ */
