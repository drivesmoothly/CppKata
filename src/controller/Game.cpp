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
	_board.SetValueAt(size / 2 - 1, size / 2 - 1, 'B');
	_board.SetValueAt(size / 2, size / 2, 'B');
	_board.SetValueAt(size / 2 - 1, size / 2, 'W');
	_board.SetValueAt(size / 2, size / 2 - 1, 'W');
}
