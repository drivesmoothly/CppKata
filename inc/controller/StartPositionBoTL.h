/*
 * StartPositionBoTL.h
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#ifndef STARTPOSITIONBOTL_H_
#define STARTPOSITIONBOTL_H_


#include "StartPosition.h"

namespace reversi
{
	/**
	 * Start position with black on top left.
	 */
	class StartPositionBoTL : public StartPosition
	{
	public:
		/**
		 * From StartPosition, Run.
		 * Sets the new position.
		 * @param b The board to set position to.
		 * @remarks This resets the previous board configuration!
		 */
		void Run(Board& b) override;
	};
}



#endif /* STARTPOSITIONBOTL_H_ */
