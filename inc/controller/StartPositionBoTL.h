/*
 * StartPositionBoTL.h
 *
 *  Created on: Oct 2, 2014
 *      Author: Marius
 */

#ifndef STARTPOSITIONBOTL_H_
#define STARTPOSITIONBOTL_H_

#include "StartPosition.h"

namespace reversi
{
	/**
	 * Startup position provider that sets the black on top left of
	 * the center group.
	 */
	class StartPositionBoTL : public StartPosition
	{
	public:
		/**
		 * From StartPosition, Run.
		 * Initializes the board to the default position version with black on
		 * top left and bottom right.
		 * @param b The board to initialize.
		 */
		void Run(Board& b) override;
	};
}


#endif /* STARTPOSITIONBOTL_H_ */
