#ifndef GRIDGAME_H_
#define GRIDGAME_H_

#include <string>
#include "grid.h"
#include "game.h"

class GridGame: public Game
{
public:
  GridGame(int);

  virtual           ~GridGame();

  virtual bool      initializeGame(const std::string gameCode) = 0;
  virtual std::string getState() = 0;
  virtual void      reset() = 0;
  virtual void      print() = 0;
  virtual bool      isWon() = 0;

protected:

  int               _size;
  Grid              _g;
};

#endif
