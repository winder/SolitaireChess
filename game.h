#ifndef GAME_H_
#define GAME_H_

#include <list>
#include <string>

class Game
{
public:
  Game();

  virtual ~Game();

  virtual bool      initializeGame(const std::string gameCode) = 0;
  virtual std::string getState() = 0;
  virtual void      reset() = 0;
  virtual void      print() = 0;
  virtual bool      isWon() = 0;

  void              recordInitialState();
  void              recordState();
  int               numMoves();
  std::string       lastState();
  void              undo();

private:

  // Deserves to be its own entity, this also gets rid of several edge cases.
  std::string       _initialState;

  // List of states.
  std::list<std::string> _stateHistory;
};

#endif
