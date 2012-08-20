#include "../rook.h"
#include "../solitairchess.h"
#include "assert.h"
#include <string>

// The pieces stress this class very hard, these tests don't do that much.

void interfaces();
void constructorsAndAssignment();
void goodCases();
void badCases();

int main()
{
  interfaces();
  constructorsAndAssignment();
  goodCases();
  badCases();
  return 0;
}

// Testing the interfaces, specifically from Game
void interfaces()
{
  SolitairChess one;
  std::string game1 = "00P11P31Q02P13P03R";
  one.initializeGame(game1);

  // R P . .
  // P . . .
  // . P . Q
  // P . . .

  // Build some history, keep a local copy of it.
  std::string history[6];
  history[0] = one.getState();

  one.movePiece(0,0,1,1);
  history[1] = one.getState();
  ASSERT_TRUE( one.numMoves() == 1 );

  one.movePiece(1,1,0,2);
  history[2] = one.getState();
  ASSERT_TRUE( one.numMoves() == 2 );

  one.movePiece(0,2,1,3);
  history[3] = one.getState();
  ASSERT_TRUE( one.numMoves() == 3 );

  one.movePiece(0,3,1,3);
  history[4] = one.getState();
  ASSERT_TRUE( one.numMoves() == 4 );

  one.movePiece(3,1,1,3);
  history[5] = one.getState();
  ASSERT_TRUE( one.numMoves() == 5 );

  // test that the undo works.
  for (int i=5; i >= 0; i--)
  {
    ASSERT_TRUE( history[i] == one.lastState() );
    one.undo();
  }

  ASSERT_TRUE( one.numMoves() == 0 );

  // This should stop at the initial state.
  one.undo();
  one.undo();
  one.undo();
  one.undo();
  one.undo();

  ASSERT_TRUE( one.lastState() == history[0] );
}

void constructorsAndAssignment()
{
  SolitairChess one;
  std::string game1 = "00R11K22k33K01P";
  one.initializeGame(game1);

  std::string game1ret = one.getState();

  ASSERT_TRUE(game1.length() == game1ret.length());

  SolitairChess two(one);

  ASSERT_TRUE(one.getState() == two.getState());

  SolitairChess *three = new SolitairChess();
  *three = two;
  
  ASSERT_TRUE(one.getState() == three->getState());

  ASSERT_TRUE(three->movePiece(0,0,3,0));

  ASSERT_FALSE(one.getState() == three->getState());

  delete three;

  ASSERT_TRUE(one.getState() == game1ret);

  // Bad initializations.

  SolitairChess four(-1);
}

void goodCases()
{
  SolitairChess test;
  test.initializeGame("00k01k02k03k10k11k12k13k20k21k22k23k30k31k32k33k"); for (int x=0; x < 4; x++) for (int y=0; y < 4; y++)
    {
      ASSERT_TRUE( test.getPiece(x,y) == 'k' );
    } 
}

void badCases()
{
  SolitairChess test;

  // initialize to bad location
  ASSERT_FALSE( test.initializeGame("91k") );
  ASSERT_FALSE( test.initializeGame("19k") );

  // bogus piece
  ASSERT_FALSE( test.initializeGame("11Z") );
  ASSERT_FALSE( test.initializeGame("22x") );

  // bogus location
  ASSERT_FALSE( test.initializeGame("ABk") );

  // bogus move
  ASSERT_FALSE( test.movePiece(-1,-1,0,0) );
}
