#include "../rook.h"
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
  //    . Q . .
  //    Q Q Q .
  //    . Q . .
  // 0,0

  SolitairChess b;
  ASSERT_TRUE( b.initializeGame("11Q10Q01Q12Q21Q00Q02Q22Q20Q") );

  // Horizontals
    ASSERT_TRUE( b.movePiece(1,1,0,1) ); // Left  -    take
    ASSERT_TRUE( b.movePiece(0,1,1,1) ); // Right - no take

    ASSERT_TRUE( b.movePiece(1,1,2,1) ); // Right -    take
    ASSERT_TRUE( b.movePiece(2,1,1,1) ); // Left  - no take

    ASSERT_TRUE( b.movePiece(1,1,1,2) ); // Up    -    take
    ASSERT_TRUE( b.movePiece(1,2,1,1) ); // Down  - no take

    ASSERT_TRUE( b.movePiece(1,1,1,0) ); // Down  -    take
    ASSERT_TRUE( b.movePiece(1,0,1,1) ); // Up    - no take

  //           3,3
  //    . . Q .
  //    Q Q Q Q
  //    . . Q .
  //    . . Q .
  // 0,0
  ASSERT_TRUE( b.initializeGame("02Q12Q22Q32Q20Q21Q23Q") );

  // Vertical
    // One space
    ASSERT_TRUE( b.movePiece(2,1,2,0) ); // Down - no take
    ASSERT_TRUE( b.movePiece(2,2,2,3) ); // Up   - no take

    // Multi space
    ASSERT_TRUE( b.canMovePiece(2,0,2,3) ); // Up   - take (sim)
    ASSERT_TRUE( b.canMovePiece(2,3,2,0) ); // Down - take (sim)

    // setup for horizontal
    ASSERT_TRUE( b.movePiece(2,0,2,1) ); // Up   -    take
    ASSERT_TRUE( b.movePiece(2,3,2,2) ); // Down -    take

  // Horizontal
    // One space
    ASSERT_TRUE( b.movePiece(1,2,0,2) ); // Left  - take
    ASSERT_TRUE( b.movePiece(2,2,3,2) ); // Right - take

    // Multi space
    ASSERT_TRUE( b.canMovePiece(0,2,3,2) ); // Right - take (sim)
    ASSERT_TRUE( b.canMovePiece(3,2,0,2) ); // Left  - take (sim)

    // One space no take
    ASSERT_TRUE( b.movePiece(0,2,1,2) );
    ASSERT_TRUE( b.movePiece(3,2,2,2) );
}

void badCases()
{
  //           3,3
  //    R R . R
  //    R R R R
  //    . R R .
  //    R R . R
  // 0,0
  SolitairChess b;
  ASSERT_TRUE( b.initializeGame("00R10R30R11R21R02R12R22R32R03R13R33R") );

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
  // Horizontal
    // Right
    ASSERT_FALSE( b.movePiece(0,2,2,2) );
    ASSERT_FALSE( b.movePiece(0,2,3,2) );
    // Left
    ASSERT_FALSE( b.movePiece(3,2,1,2) );
    ASSERT_FALSE( b.movePiece(3,2,0,2) );
    // Up
    ASSERT_FALSE( b.movePiece(1,0,1,2) );
    ASSERT_FALSE( b.movePiece(1,0,1,3) );
    // Down
    ASSERT_FALSE( b.movePiece(1,3,1,1) );
    ASSERT_FALSE( b.movePiece(1,3,1,0) );

  // Diagonal
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


  // "Bent"
    ASSERT_FALSE( b.movePiece(0,0,2,1) );
    ASSERT_FALSE( b.movePiece(0,0,3,1) );
    ASSERT_FALSE( b.movePiece(3,3,2,1) );
    ASSERT_FALSE( b.movePiece(3,3,2,0) );
}
