#include "../grid.h"
#include "assert.h"
#include "../solitairchess.h"
#include "../piece.h"
#include "../rook.h"
#include <stdio.h>

void goodCases();
void badCases();

int main()
{
  goodCases();
  badCases();
  return 0;
}

void goodCases()
{
  Grid *one;
  Grid *two;
  Piece *p = new Rook();
  one = new Grid(10);
  ASSERT_TRUE( one->setTile(1,1,p) );

  // Accessors
  ASSERT_TRUE(one->size() == 10);
  ASSERT_TRUE(one->getTile(1,1) == p);

  // Copy constructor
  two = new Grid(*one);

  ASSERT_TRUE(one->size() == two->size());
  ASSERT_TRUE(one->getTile(1,1) != two->getTile(1,1));

  // Assignment operator
  Grid three(5);
  three = *one;

  ASSERT_TRUE(one->size() == three.size());
  ASSERT_TRUE(one->getTile(1,1) != three.getTile(1,1));

  three = three;

  ASSERT_TRUE(three.size() == three.size());
  ASSERT_TRUE(three.getTile(1,1) == three.getTile(1,1));
  
  Grid *exhaust;

  // A bunch of sizes.
  for (int i=0; i < 250; i++)
  {
    exhaust = new Grid(i);
    ASSERT_TRUE(exhaust->size() == i);
    delete exhaust;
  }

  // Getting each part of grid.
  exhaust = new Grid(25);
  Piece* pieces[25][25];
  
  // Allocate and place pieces.
  for(int x=0; x < 25; x++)
  {
    for(int y=0; y < 25; y++)
    {
      pieces[x][y] = new Rook();
      exhaust->setTile(x,y,pieces[x][y]);
    }
  }

  // Make sure each piece is accessible;
  for(int x=0; x < 25; x++)
  {
    for(int y=0; y < 25; y++)
    {
      pieces[x][y] = new Rook();
      exhaust->setTile(x,y,pieces[x][y]);
      ASSERT_TRUE(exhaust->getTile(x,y) == pieces[x][y]);
    }
  }

  // Check that the grid is linked correctly by accessing the tile through the
  // pieces. 
  const Tile* t;
  for(int x=0; x < 25; x++)
  {
    for(int y=0; y < 25; y++)
    {
      t = pieces[x][y]->getLocation();

      // verify up link
      if (y < 24)
      {
        ASSERT_TRUE(t->up == pieces[x][y+1]->getLocation());
      }
      else
      {
        ASSERT_TRUE(t->up == NULL);
      }

      // verify down link
      if (y > 0)
      {
        ASSERT_TRUE(t->down == pieces[x][y-1]->getLocation());
      }
      else
      {
        ASSERT_TRUE(t->down == NULL);
      }

      // verify right link
      if (x < 24)
      {
        ASSERT_TRUE(t->right == pieces[x+1][y]->getLocation());
      }
      else
      {
        ASSERT_TRUE(t->right == NULL);
      }

      // verify left link
      if (x > 0)
      {
        ASSERT_TRUE(t->left == pieces[x-1][y]->getLocation());
      }
      else
      {
        ASSERT_TRUE(t->left == NULL);
      }
    }
  }

  // Free memory
  delete exhaust;
  for(int x=0; x < 25; x++)
    for(int y=0; y < 25; y++)
      delete pieces[x][y];
}

void badCases()
{
  Grid g(10);
  Piece *p = new Rook();

  // off board.
  ASSERT_FALSE( g.setTile(-1,-1,p) );

  // invalid constructor.
  Grid g2(-5);
}
