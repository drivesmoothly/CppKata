/*
 * StartPosition.h
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#ifndef STARTPOSITION_H_
#define STARTPOSITION_H_

namespace reversi
{
	// FORWARDS
	class Board;

	/**
	 * Interface for start position providers.
	 */
	class StartPosition
	{
	public:
		/**
		 * Virtual destructor.
		 */
		virtual ~StartPosition() {}
		/**
		 * Sets the start position to a given board.
		 * @param b The board to set the position to.
		 */
		virtual void Run(Board& b) = 0;

		virtual bool Foo() { return true; }
	};

}

#endif /* STARTPOSITION_H_ */
