#include "rook.h"

bool Rook::move(int offsetX, int offsetY)
{
  // Must move.
  if ((offsetX == 0) && (offsetY == 0))
    return false;

  if ( !_location )
    return false;

  // cannot move diagonally
  if (offsetX != 0 && offsetY != 0)
    return false;

  Tile* tmp = _location;
  int offset;

  // horizontal
  if (offsetX != 0)
  {
    bool right = offsetX > 0;
    offset = (int)fabs(offsetX);
    for (int i=0; i<offset; i++)
    {
      if (right && tmp->right)
        tmp = tmp->right;
      else if (!right && tmp->left)
        tmp = tmp->left;
      else
        return false;

      // space can only be occupied if its the last move.
      if (tmp->occupied() && i+1 != offset)
        return false;
    }
  }

  // vertical
  if (offsetY != 0)
  {
    bool up = offsetY > 0;
    offset = (int)fabs(offsetY);
    for (int i=0; i<offset; i++)
    {
      if (up && tmp->up)
        tmp = tmp->up;
      else if (!up && tmp->down)
        tmp = tmp->down;
      else
        return false;

      // space can only be occupied if its the last move.
      if (tmp->occupied() && i+1 != offset)
        return false;
    }
  }

  return true;
}

char Rook::getPiece()
{
  return 'R';
}
