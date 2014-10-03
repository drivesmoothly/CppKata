/*
 * Game.h
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include "StartPosition.h"

namespace reversi
{
	// FORWARDS
	class Board;
	class StartPosition;

	/**
	 * The game controller class.
	 */
	class Game
	{
	private:
		/**
		 * Stores the board;
		 */
		Board& _board;

		/**
		 * Keeps the default startup position if none was provided.
		 */
		std::unique_ptr<StartPosition> _spOwn;

		/**
		 * Stores the startup position provider.
		 */
		StartPosition& _sp;

	public:
		/**
		 * Constructor, takes a board.
		 * @param b The board to play on.
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
		 * Resets the board to a starting position.
		 */
		void NewGame();
	};

}



#endif /* GAME_H_ */
