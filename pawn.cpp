#include "pawn.h"

bool Pawn::move(int offsetX, int offsetY)
{
  // Must move.
  if ((offsetX == 0) && (offsetY == 0))
    return false;

  if ( !_location )
    return false;

  // TODO: real chess would have the first move can be 2 spaces.
  // must move 1 space forward, can move up to 1 space left/right.
  if (offsetY != 1 || offsetX < -1 || offsetX > 1)
    return false;

  Tile* up1 = _location->up;
  if (!up1)
    return false;

  // never going to be a valid move in this game, check it for a good time.
  if ((offsetY == 1) && (offsetX == 0))
    return !up1->occupied();

  // move forward and to the right.  if it exists and is occupied.
  if (offsetX == 1) {
    if (up1->right && up1->right->occupied())
      return true;
    else
      return false;
  }

  // move forward and to the left.  if it exists and is occupied.
  if (offsetX == -1) {
    if (up1->left && up1->left->occupied())
      return true;
    else
      return false;
  }

  // should never get here.
  return false;
}

char Pawn::getPiece()
{
  return 'P';
}
