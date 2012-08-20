#include "knight.h"
#include <stdio.h>
bool Knight::move(int offsetX, int offsetY)
{
  // Must move.
  if ((offsetX == 0) && (offsetY == 0))
    return false;

  if ( !_location )
    return false;

  int fx = (int)fabs(offsetX);
  int fy = (int)fabs(offsetY);

  // Looking for 'L'
  if (fx == 2)
  {
    if (fy != 1)
      return false;
  }
  else if (fy == 2)
  {
    if (fx != 1)
      return false;
  }
  else
    return false;

  Tile* tmp = _location;

  bool right = offsetX > 0;
  for(int x=0; x < fx; x++)
  {
    if (right)
      tmp = tmp->right;
    else
      tmp = tmp->left;

    // hit a wall.
    if (!tmp) return false;
  }

  bool up = offsetY > 0;
  for(int x=0; x < fy; x++)
  {
    if (up)
      tmp = tmp->up;
    else
      tmp = tmp->down;

    // hit a wall.
    if (!tmp) return false;
  }

  return true;
}

char Knight::getPiece()
{
  return 'k';
}
