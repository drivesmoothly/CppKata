#ifndef GAME_H_
#define GAME_H_

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

	public:
		/**
		 * Constructor, takes a board.
		 * @param b The board.
		 */
		Game(Board& b);

		/**
		 * Starts a new game.
		 * Resets the board to the default state.
		 */
		void NewGame();
	};

}



#endif /* GAME_H_ */
