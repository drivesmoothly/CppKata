/*
 * PossibilitiesFiller.h
 *
 *  Created on: Sep 30, 2014
 *      Author: Marius
 */

#ifndef POSSIBILITIESMARKER_H_
#define POSSIBILITIESMARKER_H_


namespace reversi
{

// FORWARDS
class Board;

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
};

}


#endif /* POSSIBILITIESMARKER_H_ */
