#ifndef TILE_H_
#define TILE_H_

//typedef class Piece;
class Piece;

struct Tile
{
  Piece* p;
  Tile* up;
  Tile* down;
  Tile* left;
  Tile* right;

  int x, y;

  bool occupied(){ return (p != 0); }
};

#endif
