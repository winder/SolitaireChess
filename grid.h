#ifndef GRID_H_
#define GRID_H_

// Only used for the "print" method.
#include <stdio.h>

class Piece;
class Tile;

class Grid
{
public:
  // Initialization
  Grid(int size);

  // These constructors do not copy the pieces, just initialize the board to be
  // the same size as the argument.
  Grid(const Grid& g);
  Grid& operator= (const Grid& g);

  // Destructor
  ~Grid();

  // Getter & Setter
  bool              setTile(int x, int y, Piece* p);
  Piece*            getTile(int x, int y);

  // Mutators

  // Removes pieces from each tile.
  void              clearPieces();

  // Deletes all tiles and remakes them with  new size.
  void              resetResize(int size);

  // Prints the grid to stdout.
  void              print();

  int               size();

protected:
  // Helpers
  void              _clearTile(int x, int y);
  Tile*             _getTile(int x, int y);
  void              _initGrid();

  Tile**            _tile;
  int               _size;
};

#endif
