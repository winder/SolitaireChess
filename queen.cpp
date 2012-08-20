#include "queen.h"

bool Queen::move(int offsetX, int offsetY)
{
  // Must move.
  if ((offsetX == 0) && (offsetY == 0))
    return false;

  if ( !_location )
    return false;

  // if moving diagonally they must be equal.
  bool diagonal = (offsetX != 0 && offsetY != 0);
  if (diagonal && fabs(offsetX) != fabs(offsetY))
    return false;

  bool up = offsetY > 0;
  bool right = offsetX > 0;
  Tile* tmp = _location;

  if (diagonal)
  {
    int x = (int)fabs(offsetX);
    // copy/paste from bishop.  oh well.
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
  }

  // not diagonal.
  else
  {
    // copy/pasted from rook.  oh well.
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
  }
  


  return true;
}

char Queen::getPiece()
{
  return 'Q';
}
