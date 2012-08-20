#ifndef PAWN_H_
#define PAWN_H_

#include "piece.h"

class Pawn: public Piece
{
public:
  bool move(int offsetX, int offsetY);
  char getPiece();
};

#endif
