
#include "gridgame.h"

GridGame::GridGame(int size):_size(size), _g(size)
{
  if (_size < 0) _size = 0;
}

GridGame::~GridGame()
{
}
