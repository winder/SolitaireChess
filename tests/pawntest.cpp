#include "../pawn.h"
#include "../solitairchess.h"
#include "assert.h"

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
  //           3,3
  //    . . . .
  //    . . P .
  //    . P . .
  //    . . P .
  // 0,0
  SolitairChess b;
  ASSERT_TRUE( b.initializeGame("20P11P22P") );

  // Take forward-left
    ASSERT_TRUE( b.movePiece(2,0,1,1) );
  // Take forward-right
    ASSERT_TRUE( b.movePiece(1,1,2,2) );
  // Move forward
    ASSERT_TRUE( b.movePiece(2,2,2,3) );
}

void badCases()
{
  //           3,3
  //    P P . P
  //    P . P P
  //    . P . .
  //    P P . P
  // 0,0
  SolitairChess b;
  ASSERT_TRUE( b.initializeGame("00P10P30P11P02P22P32P03P13P33P") );

  // Corner off board cases
    // bottom left
    ASSERT_FALSE( b.movePiece(0,0,-1,-1) );
    ASSERT_FALSE( b.movePiece(0,0,-1, 0) );
    ASSERT_FALSE( b.movePiece(0,0,-1, 1) );
    ASSERT_FALSE( b.movePiece(0,0, 0,-1) );
    ASSERT_FALSE( b.movePiece(0,0, 1,-1) );

    // botton right
    ASSERT_FALSE( b.movePiece(3,0,4,-1) );
    ASSERT_FALSE( b.movePiece(3,0,4, 0) );
    ASSERT_FALSE( b.movePiece(3,0,4, 1) );
    ASSERT_FALSE( b.movePiece(3,0,3,-1) );
    ASSERT_FALSE( b.movePiece(3,0,2,-1) );

    // top right
    ASSERT_FALSE( b.movePiece(3,3,4,4) );
    ASSERT_FALSE( b.movePiece(3,3,4,3) );
    ASSERT_FALSE( b.movePiece(3,3,4,2) );
    ASSERT_FALSE( b.movePiece(3,3,3,4) );
    ASSERT_FALSE( b.movePiece(3,3,2,4) );

    // top left
    ASSERT_FALSE( b.movePiece(0,3,-1,4) );
    ASSERT_FALSE( b.movePiece(0,3,-1,3) );
    ASSERT_FALSE( b.movePiece(0,3,-1,2) );
    ASSERT_FALSE( b.movePiece(0,3, 0,4) );
    ASSERT_FALSE( b.movePiece(0,3, 1,4) );

  // Edge off board cases
    // bottom edge
    ASSERT_FALSE( b.movePiece(1,0, 0,-1) );
    ASSERT_FALSE( b.movePiece(1,0, 1,-1) );
    ASSERT_FALSE( b.movePiece(1,0, 2,-1) );
    
    // right edge
    ASSERT_FALSE( b.movePiece(3,2,4,3) );
    ASSERT_FALSE( b.movePiece(3,2,4,2) );
    ASSERT_FALSE( b.movePiece(3,2,4,1) );

    // top edge
    ASSERT_FALSE( b.movePiece(1,3,0,4) );
    ASSERT_FALSE( b.movePiece(1,3,1,4) );
    ASSERT_FALSE( b.movePiece(1,3,2,4) );

    // left edge
    ASSERT_FALSE( b.movePiece(0,2,-1,1) );
    ASSERT_FALSE( b.movePiece(0,2,-1,2) );
    ASSERT_FALSE( b.movePiece(0,2,-1,3) );

  // More than one space
    // horizontal
    ASSERT_FALSE( b.movePiece(1,1,3,1) ); // right
    ASSERT_FALSE( b.movePiece(2,2,0,2) ); // left
    // vertical
    ASSERT_FALSE( b.movePiece(1,1,1,3) ); // up
    ASSERT_FALSE( b.movePiece(2,2,2,0) ); // down

  // Anything but forward
    ASSERT_FALSE( b.movePiece(2,2,2,1) ); // backwards
    ASSERT_FALSE( b.movePiece(2,2,3,2) ); // right
    ASSERT_FALSE( b.movePiece(2,2,1,2) ); // left

  // Forward to occupied space
    ASSERT_FALSE( b.movePiece(1,0,1,1) );
}
