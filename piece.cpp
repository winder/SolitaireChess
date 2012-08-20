#include "piece.h"

Piece::Piece(): alive(true)
{
}

void Piece::kill()
{
  alive = false;
}

bool Piece::isAlive()
{
  return alive;
}

void Piece::setLocation( Tile* l )
{
  _location = l;
}

const Tile* Piece::getLocation()
{
  return _location;
}
