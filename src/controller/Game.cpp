/*
 * Game.cpp
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#include "Game.h"
#include "Board.h"
#include "StartPositionBoTL.h"

using namespace reversi;

///////////////////////////////////////////////////////////////////////////////
//
Game::Game(Board& b)
: _board{b}, _spOwn(new StartPositionBoTL{}), _sp{*_spOwn}
{

}

///////////////////////////////////////////////////////////////////////////////
//
Game::Game(Board& b, StartPosition& sp)
: _board{b}, _sp{sp}
{

}

///////////////////////////////////////////////////////////////////////////////
//
void Game::NewGame()
{
	_sp.Run(_board);
}
