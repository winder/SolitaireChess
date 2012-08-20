#include "bishop.h"

bool Bishop::move(int offsetX, int offsetY)
{
  // Must move.
  if ((offsetX == 0) && (offsetY == 0))
    return false;

  if ( !_location )
    return false;

  // can only move diagonally, offsetX == offsetY.
  int x = (int)fabs(offsetX);
  if (x != fabs(offsetY))
    return false;

  bool up = offsetY > 0;
  bool right = offsetX > 0;
  Tile* tmp = _location;

  for (int moves=0; moves < x; moves++)
  {
    // move vertically
    if (up && tmp->up)
      tmp = tmp->up;
    else if (!up && tmp->down)
      tmp = tmp->down;
    else
      return false;
      
    // move horizontally
    if (right && tmp->right)
      tmp = tmp->right;
    else if (!right && tmp->left)
      tmp = tmp->left;
    else
      return false;

    // if occupied, must be the last move.
    if (tmp->occupied())
      if (moves+1 != x)
        return false;
  }

  return true;
}

char Bishop::getPiece()
{
  return 'B';
}
