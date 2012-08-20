#include "king.h"

bool King::move(int offsetX, int offsetY)
{
  // Must move.
  if ((offsetX == 0) && (offsetY == 0))
    return false;

  if ( !_location )
    return false;

  // king can only move 1 space.
  if (!(fabs(offsetX) <= 1 && fabs(offsetY) <= 1))
    return false;

  // Check edges
  if (offsetX == -1 && !_location->left)
    return false;
  if (offsetX == 1 && !_location->right)
    return false;
  if (offsetY == 1 && !_location->up)
    return false;
  if (offsetY == -1 && !_location->down)
    return false;

  return true;
}

char King::getPiece()
{
  return 'K';
}
