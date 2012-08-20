#ifndef PIECE_H_
#define PIECE_H_

#include "tile.h"

class Piece
{
public:
  Piece();
  virtual           ~Piece(){}

  void              kill();
  bool              isAlive();

  // Some pieces will need a reference to the board as well,
  // for example the bishop and rook cannot move over other
  // pieces.
  virtual bool      move(int offsetX, int offsetY) = 0;
  virtual char      getPiece() = 0;

  void              setLocation( Tile* l );
  const Tile*       getLocation();
protected:
  Tile*             _location;
  bool              alive;
};

#endif
