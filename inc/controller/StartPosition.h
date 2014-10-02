/*
 * StartPosition.h
 *
 *  Created on: Oct 2, 2014
 *      Author: Marius
 */

#ifndef STARTPOSITION_H_
#define STARTPOSITION_H_

namespace reversi
{
	// Forwards
	class Board;

	/**
	 * Interface for startup position providers.
	 */
	class StartPosition
	{
	public:
		/**
		 * Virtual destructor.
		 */
		virtual ~StartPosition() {}

		/**
		 * Initializes the board to a startup position.
		 * @param b The board.
		 */
		virtual void Run(Board& b) = 0;
	};

}



#endif /* STARTPOSITION_H_ */
