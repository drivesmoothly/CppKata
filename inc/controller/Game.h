#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include "StartPosition.h"

namespace reversi
{
	// FORWARDS
	class Board;

	/**
	 * Represents the controller part of a game.
	 */
	class Game
	{
	private:
		/**
		 * Stores the board.
		 */
		Board& _board;
		/**
		 * Stores a unique ptr to a startup position provider if none was received.
		 */
		std::unique_ptr<StartPosition> _startPositionOwn;
		/**
		 * The start position provider.
		 */
		StartPosition& _startPosition;

	public:
		/**
		 * Constructor, takes a board. It uses by default the StartPositionBoTL
		 * as the startup position provider.
		 * @param b The board.
		 */
		Game(Board& b);
		/**
		 * Constructor, takes a board and a startup position provider.
		 * @param b The board.
		 * @param sp The startup position provider.
		 */
		Game(Board& b, StartPosition& sp);

		/**
		 * Starts a new game.
		 * Resets the board to the default state.
		 */
		void NewGame();
	};

}

#endif /* GAME_H_ */
