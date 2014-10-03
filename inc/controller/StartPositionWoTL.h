/*
 * StartPositionWoTL.h
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#ifndef STARTPOSITIONWOTL_H_
#define STARTPOSITIONWOTL_H_

#include "StartPosition.h"

namespace reversi
{
	/**
	 * Start position with white on top left.
	 */
	class StartPositionWoTL : public StartPosition
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



#endif /* STARTPOSITIONWOTL_H_ */
