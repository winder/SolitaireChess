#include "game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::recordInitialState()
{
  _initialState = getState();
  _stateHistory.clear();
}

void Game::recordState()
{
  // Special case check, this allows users to use recordState only if desired.
  // except if they want the state history cleared.
  if (_initialState == "")
    _initialState = getState();
  else
    _stateHistory.push_back(getState());
}

int Game::numMoves()
{
  return _stateHistory.size();
}

std::string Game::lastState()
{
  if (numMoves() == 0)
    return _initialState;
  return _stateHistory.back();
}

void Game::undo()
{
  if (numMoves() > 0)
    _stateHistory.pop_back();
}

