#include <stdio.h>
#include <string.h>
#include "solitairchess.h"
#include <string>


int main()
{
  std::string solution;
  std::string puzzle;

  printf("=======\nPuzzle 1\n=======\n");

  puzzle = "01P12B03k";
  SolitairChess::solve( puzzle, &solution );
  printf("Solution = '%s'\n", solution.c_str());


  printf("=======\nPuzzle 35\n=======\n");

  puzzle = "00P01B11k13R23Q32P";
  SolitairChess::solve(puzzle, &solution);
  printf("Solution = '%s'\n", solution.c_str());

  return 0;
}
