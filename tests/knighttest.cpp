#include "../knight.h"
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
  //    k . . k
  //    . k k .
  //    . k k .
  //    k . . k
  // 0,0
  SolitairChess b;

  ASSERT_TRUE( b.initializeGame("00k30k11k21k12k22k03k33k") );

  // Take pieces, Outside-in, clockwise
    ASSERT_TRUE( b.movePiece(0,0,1,2) );
    ASSERT_TRUE( b.movePiece(3,0,1,1) );
    ASSERT_TRUE( b.movePiece(3,3,2,1) );
    ASSERT_TRUE( b.movePiece(0,3,2,2) );

  // Move back
    ASSERT_TRUE( b.movePiece(1,2,0,0) );
    ASSERT_TRUE( b.movePiece(1,1,3,0) );
    ASSERT_TRUE( b.movePiece(2,1,3,3) );
    ASSERT_TRUE( b.movePiece(2,2,0,3) );

  ASSERT_TRUE( b.initializeGame("00k30k11k21k12k22k03k33k") );

  // Take pieces, Outside-in, counter-clockwise
    ASSERT_TRUE( b.movePiece(0,0,2,1) );
    ASSERT_TRUE( b.movePiece(3,0,2,2) );
    ASSERT_TRUE( b.movePiece(3,3,1,2) );
    ASSERT_TRUE( b.movePiece(0,3,1,1) );

  // Move back
    ASSERT_TRUE( b.movePiece(2,1,0,0) );
    ASSERT_TRUE( b.movePiece(2,2,3,0) );
    ASSERT_TRUE( b.movePiece(1,2,3,3) );
    ASSERT_TRUE( b.movePiece(1,1,0,3) );

  ASSERT_TRUE( b.initializeGame("00k30k11k21k12k22k03k33k") );

  // Take pieces, Inside-Out, counter-clockwise
    ASSERT_TRUE( b.movePiece(1,2,0,0) );
    ASSERT_TRUE( b.movePiece(1,1,3,0) );
    ASSERT_TRUE( b.movePiece(2,1,3,3) );
    ASSERT_TRUE( b.movePiece(2,2,0,3) );

  // Move back
    ASSERT_TRUE( b.movePiece(0,0,1,2) );
    ASSERT_TRUE( b.movePiece(3,0,1,1) );
    ASSERT_TRUE( b.movePiece(3,3,2,1) );
    ASSERT_TRUE( b.movePiece(0,3,2,2) );

  ASSERT_TRUE( b.initializeGame("00k30k11k21k12k22k03k33k") );

  // Take pieces, Outside-in, clockwise
    ASSERT_TRUE( b.movePiece(2,1,0,0) );
    ASSERT_TRUE( b.movePiece(2,2,3,0) );
    ASSERT_TRUE( b.movePiece(1,2,3,3) );
    ASSERT_TRUE( b.movePiece(1,1,0,3) );

  // Move back
    ASSERT_TRUE( b.movePiece(0,0,2,1) );
    ASSERT_TRUE( b.movePiece(3,0,2,2) );
    ASSERT_TRUE( b.movePiece(3,3,1,2) );
    ASSERT_TRUE( b.movePiece(0,3,1,1) );
}

void badCases()
{
  //           3,3
  //    k k . k
  //    . . . k
  //    k . . .
  //    k . k k
  // 0,0
  SolitairChess b;
  ASSERT_TRUE( b.initializeGame("00k20k30k01k32k03k13k33k") );

  // Corner off board cases
    // bottom left
    ASSERT_FALSE( b.movePiece(0,0,-2,-1) );
    ASSERT_FALSE( b.movePiece(0,0,-2, 1) );
    ASSERT_FALSE( b.movePiece(0,0,-1,-2) );
    ASSERT_FALSE( b.movePiece(0,0, 1,-2) );
    ASSERT_FALSE( b.movePiece(0,0,-1, 2) );
    ASSERT_FALSE( b.movePiece(0,0, 2,-1) );

    // botton right
    ASSERT_FALSE( b.movePiece(3,0,4, 2) );
    ASSERT_FALSE( b.movePiece(3,0,5, 1) );
    ASSERT_FALSE( b.movePiece(3,0,5,-1) );
    ASSERT_FALSE( b.movePiece(3,0,4,-2) );
    ASSERT_FALSE( b.movePiece(3,0,2,-2) );
    ASSERT_FALSE( b.movePiece(3,0,1,-1) );

    // top right
    ASSERT_FALSE( b.movePiece(3,3,4,1) );
    ASSERT_FALSE( b.movePiece(3,3,5,2) );
    ASSERT_FALSE( b.movePiece(3,3,5,4) );
    ASSERT_FALSE( b.movePiece(3,3,4,5) );
    ASSERT_FALSE( b.movePiece(3,3,2,5) );
    ASSERT_FALSE( b.movePiece(3,3,1,5) );

    // top left
    ASSERT_FALSE( b.movePiece(0,3, 4,2) );
    ASSERT_FALSE( b.movePiece(0,3, 1,5) );
    ASSERT_FALSE( b.movePiece(0,3,-1,5) );
    ASSERT_FALSE( b.movePiece(0,3,-2,4) );
    ASSERT_FALSE( b.movePiece(0,3,-2,2) );
    ASSERT_FALSE( b.movePiece(0,3,-1,1) );

  // Edge off board cases
    // bottom edge 
    ASSERT_FALSE( b.movePiece(2,0, 0,-1) );
    ASSERT_FALSE( b.movePiece(2,0, 1,-2) );
    ASSERT_FALSE( b.movePiece(2,0, 3,-2) );
    ASSERT_FALSE( b.movePiece(2,0, 4,-1) );

    // right edge
    ASSERT_FALSE( b.movePiece(3,2,4,4) );
    ASSERT_FALSE( b.movePiece(3,2,5,3) );
    ASSERT_FALSE( b.movePiece(3,2,5,1) );
    ASSERT_FALSE( b.movePiece(3,2,4,0) );

    // top edge
    ASSERT_FALSE( b.movePiece(1,3, 2,5) );
    ASSERT_FALSE( b.movePiece(1,3, 0,5) );
    ASSERT_FALSE( b.movePiece(1,3,-1,5) );

    // left edge
    ASSERT_FALSE( b.movePiece(0,1, 4, 0) );
    ASSERT_FALSE( b.movePiece(0,1,-1, 3) );
    ASSERT_FALSE( b.movePiece(0,1,-2, 2) );
    ASSERT_FALSE( b.movePiece(0,1,-2, 0) );
    ASSERT_FALSE( b.movePiece(0,1,-1,-1) );

    // Not L shaped
    ASSERT_FALSE( b.movePiece(0,0,1,1) );
    ASSERT_FALSE( b.movePiece(3,3,2,2) );
    ASSERT_FALSE( b.movePiece(0,0,2,2) );
    ASSERT_FALSE( b.movePiece(3,3,1,1) );
    ASSERT_FALSE( b.movePiece(0,0,2,0) );
    ASSERT_FALSE( b.movePiece(0,0,0,2) );
    ASSERT_FALSE( b.movePiece(3,3,1,3) );
    ASSERT_FALSE( b.movePiece(3,3,3,1) );
}
