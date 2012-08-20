#include "solitairchess.h"

#include "grid.h"
#include "tile.h"
#include "piece.h"
#include "bishop.h"
#include "knight.h"
#include "king.h"
#include "rook.h"
#include "queen.h"
#include "pawn.h"

SolitairChess::SolitairChess(): GridGame(BOARD_SIZE)// _size(BOARD_SIZE), _g(BOARD_SIZE)
{
}

SolitairChess::SolitairChess(int size): GridGame(size)//_size(size), _g(size)
{
  if (_size < 0) _size = 0;
}

SolitairChess::SolitairChess(const SolitairChess& b): GridGame(b._size)
{
  // add pieces.
  for (unsigned int i=0; i < b._pieces.size(); i++)
  {
    _addPiece( b._pieces[i]->getLocation()->x,
               b._pieces[i]->getLocation()->y,
               b._pieces[i]->getPiece()       );
  }
}

SolitairChess& SolitairChess::operator= (const SolitairChess& b)
{
  if (this != &b)
  {
    _g.resetResize(b._size);

    // add pieces.
    for (unsigned int i=0; i < b._pieces.size(); i++)
    {
      _addPiece( b._pieces[i]->getLocation()->x,
                 b._pieces[i]->getLocation()->y,
                 b._pieces[i]->getPiece() );
    }
  }
  return *this;
}

// We allocated pieces, so deallocate them.
SolitairChess::~SolitairChess()
{
  std::vector<Piece*>::iterator iter = _pieces.begin();
  while (iter != _pieces.end())
    delete *iter++;
}

bool SolitairChess::initializeGame(const std::string gameCode)
{
  //const char* ptr;
  int x, y;

  // Reset game state.
  reset();

  // takes 3 characters at a time.
  for (unsigned int ptr = 0; ptr < gameCode.length(); ptr += 3)
  {
    x = gameCode[ptr]     - '0';
    y = gameCode[ptr + 1] - '0';
    if (!_addPiece(x, y, gameCode[ptr + 2]))
      return false;
  }

  // Initial state is recorded.
  recordInitialState();
  return true;
}

std::string SolitairChess::getState()
{
  std::string retString = "";
  Piece* p;

  // Check for a piece at each tile.
  for (int y=0; y < _size; y++)
  {
    for (int x=0; x < _size; x++)
    {
      p = _g.getTile(x, y);
      // if there is a piece, report it.
      if (p)
      {
        retString += ('0' + x);
        retString += ('0' + y);
        retString += p->getPiece();
      }
    }
  }

  return retString;
}

bool SolitairChess::movePiece(const int fromX, const int fromY,
                      const int toX,   const int toY)
{
  bool retval = false;
  Piece* p = _g.getTile(fromX, fromY);
  if (p)
  {
    // if can move.
    if (p->move( toX - fromX, toY - fromY ))
    {
      // If there is already a piece at (toX, toY), kill it.
      Piece* pKill = _g.getTile(toX, toY);
      if (pKill)
        pKill->kill();

      // update (toX, toY) and (fromX, fromY).
      _g.setTile(toX, toY, p);
      _g.setTile(fromX, fromY, 0);

      retval = true;
    }
  }

  // Superclass history tracking.
  if (retval)
  {
      recordState();
  }

  return retval;
}

bool SolitairChess::canMovePiece(const int fromX, const int fromY,
                         const int toX,   const int toY)
{
  Piece* p = _g.getTile(fromX, fromY);
  if (p)
  {
    // if can move.
    if (p->move( toX - fromX, toY - fromY ))
    {
      return true;
    }
  }

  return false;
}

// Gets the type of piece at given index.
char SolitairChess::getPiece(const int x, const int y)
{
  Piece* p = _g.getTile(x, y);
  if (p)
    return p->getPiece();
  return '\0';
}

// recursive funtion to solve the "state"
// returns true if solved, false if not solvable
// solution is in the form (<fromx><fromy><tox><toy>,)+
// TODO: Make this not hideous.
bool SolitairChess::solve(const std::string state, std::string* solution)
{
  *solution = "";
  static std::string move;

  // only one piece left, solved.
  if ( state.length() == 3 )
    return true;

  SolitairChess x;
  x.initializeGame(state);

  // Iterates through each piece looking for which needs to move
  for (unsigned int fromPiece = 0; fromPiece < state.length(); fromPiece+=3)
  {
    // Iterates through each piece looking for where it can move
    for (unsigned int toPiece = 0; toPiece < state.length(); toPiece+=3)
    {
      // Check if the from->to combination is a valid move, if so, recurse.
      if ( x.canMovePiece( state[fromPiece]-'0', state[fromPiece + 1]-'0',
                           state[toPiece]-'0', state[toPiece + 1]-'0') )
      {

        // If it is a valid move, create a game and move the piece.
        SolitairChess b;
        b.initializeGame(state);
        b.movePiece( state[fromPiece] - '0', state[fromPiece + 1] - '0',
                     state[toPiece] - '0', state[toPiece + 1] - '0' );
        std::string afterMove = b.getState();

        // If this happens there is a bug, but trap it so we don't crash.
        if ( afterMove[0] == '\0')
        {
          printf("Some sort of bug has occurred.\n");
          return false;
        }

        // Recurse
        if (solve( afterMove, solution ))
        {
          // TODO: find the better way to do C++ formatted string building.
          //       What I really want is an equivelent to sprintf.
          move  = state[fromPiece    ];
          move += state[fromPiece + 1];
          move += state[toPiece    ];
          move += state[toPiece + 1];
          move += ',';

          *solution = move + *solution;
          return true;
        }
      }
    }
  }

  return false;
}

int SolitairChess::numPieces()
{
  int ret = 0;
  std::vector<Piece*>::iterator iter = _pieces.begin();
  while (iter != _pieces.end())
  {
    if ((*iter)->isAlive()) ret++;
    iter++;
  }
  return ret;
}

void SolitairChess::reset()
{
  // Get rid of old pieces.
  std::vector<Piece*>::iterator iter = _pieces.begin();
  while (iter != _pieces.end())
    delete *iter++;
  _pieces.clear();

  _g.clearPieces();
}

void SolitairChess::print()
{
  _g.print();
}

int SolitairChess::size()
{
  return _size;
}


bool SolitairChess::isWon()
{
  return numPieces() == 1;
}

// My piece 'factory'
Piece* SolitairChess::_allocatePiece(char p)
{
  Piece* ret;
  switch (p)
  {
    case 'K':
      ret = new King();
      break;
    case 'Q':
      ret = new Queen();
      break;
    case 'B':
      ret = new Bishop();
      break;
    case 'P':
      ret = new Pawn();
      break;
    case 'R':
      ret = new Rook();
      break;
    case 'k':
      ret = new Knight();
      break;

    // Unknown?
    default:
      return 0;
  }

  _pieces.push_back(ret);
  return ret;
}

bool SolitairChess::_addPiece(int x, int y, char pID)
{
  Piece* p = _allocatePiece( pID );
  if (!p) return false;
  return _g.setTile(x, y, p);
}
