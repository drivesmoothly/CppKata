/*
 * PossibilitiesFiller.h
 *
 *  Created on: Sep 30, 2014
 *      Author: Marius
 */

#ifndef POSSIBILITIESFILLER_H_
#define POSSIBILITIESFILLER_H_


namespace reversi
{

// FORWARDS
class Board;

/**
 * Responsible for filling the possibilities.
 */
class PossibilitiesFiller
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
	PossibilitiesFiller(Board& b);

	/**
	 * Fills the possibilities for white.
	 */
	void FillWhite();
};

}


#endif /* POSSIBILITIESFILLER_H_ */
