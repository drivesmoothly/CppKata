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
	_board.SetValueAt(_board.GetSize() / 2 - 1, _board.GetSize() / 2 - 1, 'B');
	_board.SetValueAt(_board.GetSize() / 2, _board.GetSize() / 2, 'B');
	_board.SetValueAt(_board.GetSize() / 2 - 1, _board.GetSize() / 2, 'W');
	_board.SetValueAt(_board.GetSize() / 2, _board.GetSize() / 2 - 1, 'W');
}
