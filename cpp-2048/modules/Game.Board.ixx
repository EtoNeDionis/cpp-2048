#include <iostream>
export module Game.Board;
import Game.Board.Cell;

export  class Board
{
public:
  Board();
  void PrintCells();
  void InsertNewValue();
  Cell cells[4][4];
  void Move(char dir);
private:
  void _CountEmptyCells();
  int _numberEmptyCells = 4 * 4;
  bool IsBoardSame(Board newBoard);
  Board GetCopyBoard();
  void MoveUp();
  void MoveRight();
  void MoveDown();
  void MoveLeft();

};

