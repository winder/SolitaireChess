#ifndef BISHOP_H_
#define BISHOP_H_

#include <math.h>
#include "piece.h"

class Bishop: public Piece
{
public:
  bool move(int offsetX, int offsetY);
  char getPiece();
};

#endif
