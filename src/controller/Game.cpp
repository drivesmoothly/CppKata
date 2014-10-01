#include "Game.h"
#include "Board.h"

using namespace reversi;

///////////////////////////////////////////////////////////////////////////////
//
Game::Game(Board& b)
: _board{b}
{
}

///////////////////////////////////////////////////////////////////////////////
//
void Game::NewGame()
{
	_board.Reset();
	int size{_board.GetSize()};
	_board.SetValueAt(size / 2 - 1, size / 2 - 1, Board::Black);
	_board.SetValueAt(size / 2, size / 2, Board::Black);
	_board.SetValueAt(size / 2 - 1, size / 2, Board::White);
	_board.SetValueAt(size / 2, size / 2 - 1, Board::White);
}
