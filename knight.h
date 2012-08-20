#ifndef KNIGHT_H_
#define KNIGHT_H_

#include <math.h>
#include "piece.h"

class Knight: public Piece
{
public:
  bool move(int offsetX, int offsetY);
  char getPiece();
};

#endif
