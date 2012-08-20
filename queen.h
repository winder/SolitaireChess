#ifndef QUEEN_H_
#define QUEEN_H_

#include <math.h>
#include "piece.h"

class Queen: public Piece
{
public:
  bool move(int offsetX, int offsetY);
  char getPiece();
};

#endif
