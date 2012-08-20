#include "../king.h"
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
  //    K K K .
  //    K K K .
  //    K K K .
  // 0,0

  SolitairChess b;
  ASSERT_TRUE( b.initializeGame("11K10K01K12K21K00K02K22K20K") );

  // Diagonals
    ASSERT_TRUE( b.movePiece(1,1,2,2) ); // Up  -Right -    take
    ASSERT_TRUE( b.movePiece(2,2,1,1) ); // Down-Left  - no take

    ASSERT_TRUE( b.movePiece(1,1,0,0) ); // Down-Left  -    take
    ASSERT_TRUE( b.movePiece(0,0,1,1) ); // Up  -Right - no take

    ASSERT_TRUE( b.movePiece(1,1,0,2) ); // Up  -Left  -    take
    ASSERT_TRUE( b.movePiece(0,2,1,1) ); // Down-Right - no take

    ASSERT_TRUE( b.movePiece(1,1,2,0) ); // Down-Right -    take
    ASSERT_TRUE( b.movePiece(2,0,1,1) ); // Up  -Left  - no take

  // Horizontals
    ASSERT_TRUE( b.movePiece(1,1,0,1) ); // Left  -    take
    ASSERT_TRUE( b.movePiece(0,1,1,1) ); // Right - no take

    ASSERT_TRUE( b.movePiece(1,1,2,1) ); // Right -    take
    ASSERT_TRUE( b.movePiece(2,1,1,1) ); // Left  - no take

    ASSERT_TRUE( b.movePiece(1,1,1,2) ); // Up    -    take
    ASSERT_TRUE( b.movePiece(1,2,1,1) ); // Down  - no take

    ASSERT_TRUE( b.movePiece(1,1,1,0) ); // Down  -    take
    ASSERT_TRUE( b.movePiece(1,0,1,1) ); // Up    - no take
}

void badCases()
{
  //           3,3
  //    K K . K
  //    K . K K
  //    . K . .
  //    K K . K
  // 0,0
  SolitairChess b;
  ASSERT_TRUE( b.initializeGame("00K10K30K11K02K22K32K03K13K33K") );

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
}
