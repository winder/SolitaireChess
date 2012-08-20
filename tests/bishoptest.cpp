#include "assert.h"
#include "../bishop.h"
#include "../solitairchess.h"

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
  //    b . . b
  //    . b b .
  //    . b b .
  //    b . . b
  // 0,0
  SolitairChess b;
  ASSERT_TRUE( b.initializeGame("03B33B12B22B11B12B00B30B21B") );

  // One space
  ASSERT_TRUE( b.movePiece(0,0,1,1) ); // Up  -Right -    take
  ASSERT_TRUE( b.movePiece(1,1,0,0) ); // Down-Left  - no take

  ASSERT_TRUE( b.movePiece(3,3,2,2) ); // Down-Left  -    take
  ASSERT_TRUE( b.movePiece(2,2,3,3) ); // Up  -Right - no take

  ASSERT_TRUE( b.movePiece(3,0,2,1) ); // Up  -Left  -    take
  ASSERT_TRUE( b.movePiece(2,1,3,0) ); // Down-Right - no take

  ASSERT_TRUE( b.movePiece(0,3,1,2) ); // Down-Right -    take
  ASSERT_TRUE( b.movePiece(1,2,0,3) ); // Up  -Left  - no take
  
  // Multi space
  ASSERT_TRUE( b.canMovePiece(0,0,3,3) ); // Up  -Right - take (sim)
  ASSERT_TRUE( b.canMovePiece(3,3,0,0) ); // Down-Left  - take (sim)
  ASSERT_TRUE( b.canMovePiece(0,3,3,0) ); // Down-Right - take (sim)
  ASSERT_TRUE( b.canMovePiece(3,0,0,3) ); // Up  -Left  - take (sim)
}

void badCases()
{
  //           3,3
  //    b b . b 
  //    b b b b
  //    . b b .
  //    b b . b
  // 0,0

  SolitairChess b;
  ASSERT_TRUE( b.initializeGame("03B33B12B22B11B12B00B30B13B02B10B32B") );

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

  // Over other pieces
    // Up-Right
    ASSERT_FALSE( b.movePiece(0,0,2,2) );
    ASSERT_FALSE( b.movePiece(0,0,3,3) );
    // Down-Left
    ASSERT_FALSE( b.movePiece(3,3,1,1) );
    ASSERT_FALSE( b.movePiece(3,3,0,0) );
    // Up-Left
    ASSERT_FALSE( b.movePiece(0,3,2,2) );
    ASSERT_FALSE( b.movePiece(0,3,3,3) );
    // Down-Right
    ASSERT_FALSE( b.movePiece(0,3,2,1) );
    ASSERT_FALSE( b.movePiece(0,3,3,0) );

  // Non Diagonal
    ASSERT_FALSE( b.movePiece(1,1,1,2) );
    ASSERT_FALSE( b.movePiece(1,1,1,0) );
    ASSERT_FALSE( b.movePiece(1,1,0,1) );
    ASSERT_FALSE( b.movePiece(1,1,2,1) );
}
