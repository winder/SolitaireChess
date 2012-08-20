#include "grid.h"

#include "piece.h"
#include "tile.h"

Grid::Grid(int size): _size(size)
{
  if (_size < 0) _size = 0;
  _initGrid();
}

Grid::~Grid()
{
  for (int i=0; i<_size; i++)
    delete [] _tile[i];
  delete [] _tile;
}

Grid::Grid(const Grid& g): _size(g._size)
{
  _initGrid();
}

Grid& Grid::operator= (const Grid& g)
{
  if (this != &g)
  {
    _size = g._size;
    _initGrid();
  }
  return *this;
}

bool Grid::setTile(int x, int y, Piece* p)
{
  // Check bounds, then add piece to grid.
  if (!(x < 0 || y < 0) && x < _size && y < _size)
  {
    _getTile(x, y)->p = p;
    if (p)
    {
      p->setLocation( _getTile(x, y) );
      return true;
    }
  }
  return false;
}

Piece* Grid::getTile(int x, int y)
{
  if (x < _size && y < _size && x >= 0 && y >= 0)
    return _tile[y][x].p;
  return NULL;
}

void Grid::resetResize(int size)
{
  for (int i=0; i<_size; i++)
    delete [] _tile[i];
  delete [] _tile;

  _size = size;
  _initGrid();
}

void Grid::clearPieces()
{
  for (int y=_size-1; y >= 0; y--)
    for (int x=0; x < _size; x++)
      _getTile(x, y)->p = NULL;
}

void Grid::print()
{
  Piece *p;
  printf("          (4,4)\n");
  for (int y=_size-1; y >= 0; y--)
  {
    printf("     ");
    for (int x=0; x < _size; x++)
    {
      p = (Piece*)getTile(x, y);
      if ( p )
        printf("%c", p->getPiece());
      else
        printf("*");
    }
    printf("\n");
  }
  printf("(0,0)\n");
}

int Grid::size()
{
  return _size;
}

//---------- Private -----------//

void Grid::_clearTile(int x, int y)
{
  Tile* t = _getTile(x, y);
  t->p = 0;
  t->up = 0;
  t->down = 0;
  t->left = 0;
  t->right = 0;
}

Tile* Grid::_getTile(int x, int y)
{
  return &(_tile[y][x]);
}

void Grid::_initGrid()
{
  _tile = new Tile*[_size];
  for (int i=0; i<_size; i++)
    _tile[i] = new Tile[_size];

  // Link grid.
  Tile *tmp;
  for (int y=0; y < _size; y++)
    for (int x=0; x < _size; x++)
    {
      _clearTile(x, y);
      tmp = _getTile(x, y);
      tmp->x = x;
      tmp->y = y;

      // horizontal
      if (x < _size-1)
        tmp->right = _getTile(x+1, y);
      if (x > 0)
        tmp->left = _getTile(x-1, y);
      // vertical
      if (y < _size-1)
        tmp->up = _getTile(x, y+1);
      if (y > 0)
        tmp->down = _getTile(x, y-1);
    }
}
