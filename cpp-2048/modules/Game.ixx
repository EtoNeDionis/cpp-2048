#include <iostream>
export module Game;
import Game.Board;

export class Game
{
public:
  Game();
  void Play();
private:
  Board _board;
  char _ch;
  bool _gameEnded = false;
  void _ReadChar();
  void _HandleChar();
  bool IsGameEnded();
};