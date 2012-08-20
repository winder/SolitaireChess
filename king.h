#ifndef KING_H_
#define KING_H_

#include <math.h>
#include "piece.h"

class King: public Piece
{
public:
  bool move(int offsetX, int offsetY);
  char getPiece();
};

#endif
