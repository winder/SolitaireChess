#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <string>

class Piece;
#include "grid.h"
#include "gridgame.h"

// Default Solitair Chess board size.
#define BOARD_SIZE 4

class SolitairChess: public GridGame
{
public:
  SolitairChess();
  SolitairChess(int);

  SolitairChess(const SolitairChess& b);
  SolitairChess& operator= (const SolitairChess& b);

  virtual           ~SolitairChess();

  // Accepts an std::string
  // Each piece is represented with 3 characters "<x><y><Piece ID>"
  // Piece IDs:
  //   (R)ook, (K)ing, (k)night, (Q)ueen, (B)ishop, (P)awn
  //bool initializeGame(const char* gameCode);
  bool              initializeGame(const std::string gameCode);

  // Returns the game state to the state argument using the same code as
  // "initializeGame".  The state argument is an array of length bufferSize.
  // Returns false if there was a problem, true if state was written.
  std::string       getState();

  // Check if a piece could be moved from (fromX, fromY) to (toX, toY),
  // moves the piece if it is a valid move.
  // Returns true if moved, false otherwise.
  bool              movePiece(const int fromX, const int fromY,
                              const int toX,   const int toY);

  // Check if a piece could be moved from (fromX, fromY) to (toX, toY)
  // Returns true if can move, false otherwise.
  bool              canMovePiece(const int fromX, const int fromY,
                                 const int toX,   const int toY);

  // Gets the type of piece at given index.
  char              getPiece(const int x, const int y);

  // recursive funtion to solve the "state"
  // returns true if solved, false if not solvable
  // solution is in the form (<fromx><fromy><tox><toy>)+
  static bool       solve(const std::string state, std::string* solution);

  // Returns the number of remaining pieces.
  int               numPieces();

  // Resets game state and free's unused objects.
  void              reset();

  // Prints current state to the console.
  void              print();
  int               size();
  bool              isWon();

private:
  // Initializes a Piece based on a Piece ID
  // Returns NULL if Piece ID is invalid.
  Piece*            _allocatePiece(char);

  // returns false if there was a problem allocating the piece.
  bool              _addPiece(int x, int y, char pID);

private:
  // Member variables
  std::vector<Piece*> _pieces;
};

#endif
