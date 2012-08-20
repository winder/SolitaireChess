#ifndef ROOK_H_
#define ROOK_H_

#include <math.h>
#include "piece.h"

class Rook: public Piece
{
public:
  bool move(int offsetX, int offsetY);
  char getPiece();
};

#endif
