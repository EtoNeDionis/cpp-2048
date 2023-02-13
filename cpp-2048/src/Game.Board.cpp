#include <iostream>
import Game.Board;
import Helper;

Board::Board()
{
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      this->cells[i][j] = Cell();
}

void Board::PrintCells()
{
  std::string decorLine(16 * 4, '-');
  for (int i = 0; i < 4; ++i) {
  	std::cout << decorLine << "\n";
  	for (int j = 0; j < 4; ++j) {
  		if (this->cells[i][j].GetValue() == 0) {
  			std::cout << "|       \t";
  		}
  		else {
        std::cout << "|       " << this->cells[i][j].GetValue() << "\t";
  		}
  	}
  	std::cout << "|" << "\n";
  }
  std::cout << decorLine << "\n";
}

void Board::InsertNewValue()
{
  if (this->_numberEmptyCells == 0)
    return;
  
  int x = Helper::GetRandomInt(1, _numberEmptyCells); 
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
    {
      if (!this->cells[i][j].GetValue())
        x--;
      if (x == 0)
      {
        //25% change to get 4 and 75% to get 2
        int value = Helper::GetRandomInt(0, 3);
        value == 3 ? this->cells[i][j].SetValue(4) : this->cells[i][j].SetValue(2);
        break;
      }
    }

  this->_CountEmptyCells();
}

void Board::_CountEmptyCells()
{
  int emptyCells = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if(this->cells[i][j].GetValue()) continue;
      else emptyCells++;
  this->_numberEmptyCells = emptyCells;
}

void Board::Move(char dir)
{
	Board copyBoard;
	switch (dir)
	{
	case 'w':
		while (!this->IsBoardSame(copyBoard)) 
		{
			copyBoard = this->GetCopyBoard();
			this->MoveUp();
		}
		break;

	case 'd':
		while (!this->IsBoardSame(copyBoard))
		{
			copyBoard = this->GetCopyBoard();
			this->MoveRight();
		}
		break;

	case 's':
		while (!this->IsBoardSame(copyBoard))
		{
			copyBoard = this->GetCopyBoard();
			this->MoveDown();
		}
		break;
	case 'a':
		while (!this->IsBoardSame(copyBoard))
		{
			copyBoard = this->GetCopyBoard();
			this->MoveLeft();
		}
		break;
	default:
		break;
	}
}

bool Board::IsBoardSame(Board newBoard) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (newBoard.cells[i][j].GetValue() != this->cells[i][j].GetValue()) return false;
		}
	}
	return true;
}

void Board::MoveUp() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (cells[i][j].GetValue() == 0 ||
				cells[i - 1][j].GetHasCollapsedThisTurn())
				continue;

			if (cells[i - 1][j].GetValue() == 0) 
			{
				cells[i - 1][j].SetValue(cells[i][j].GetValue());
				cells[i][j].SetValue(0);
			}

			if (cells[i - 1][j].GetValue() == cells[i][j].GetValue()) {
				cells[i - 1][j].SetValue(2 * cells[i - 1][j].GetValue());

				cells[i][j].SetValue(0);
				cells[i - 1][j].SetHasCollapsedThisTurn(true);
			}
		}
	}
}
void Board::MoveLeft() {
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (cells[i][j].GetValue() == 0 ||
				cells[i][j - 1].GetHasCollapsedThisTurn())
				continue;

			if (cells[i][j - 1].GetValue() == 0) {
				cells[i][j - 1].SetValue(cells[i][j].GetValue()) ;
				cells[i][j].SetValue(0);
			}

			if (cells[i][j - 1].GetValue() == cells[i][j].GetValue()) {
				cells[i][j - 1].SetValue(2 * cells[i][j - 1].GetValue());

				cells[i][j].SetValue(0);
				cells[i][j - 1].SetHasCollapsedThisTurn(true);
			}
		}
	}
}
void Board::MoveDown() 
{
	for (int i = 4 - 2; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {

			if (cells[i][j].GetValue() == 0 ||
				cells[i + 1][j].GetHasCollapsedThisTurn())
				continue;


			if (cells[i + 1][j].GetValue() == 0) {
				cells[i + 1][j].SetValue(cells[i][j].GetValue());
				cells[i][j].SetValue(0);
			}


			if (cells[i + 1][j].GetValue() == cells[i][j].GetValue()) {
				cells[i + 1][j].SetValue(2 * cells[i + 1][j].GetValue());

				cells[i][j].SetValue(0);
				cells[i + 1][j].SetHasCollapsedThisTurn(true);
			}
		}
	}
}

void Board::MoveRight()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 4 - 2; j >= 0; j--) {
			if (cells[i][j].GetValue() == 0 ||
				cells[i][j + 1].GetHasCollapsedThisTurn())
				continue;

			if (cells[i][j + 1].GetValue() == 0) {
				cells[i][j + 1].SetValue(cells[i][j].GetValue());
				cells[i][j].SetValue(0);
			}

			if (cells[i][j + 1].GetValue() == cells[i][j].GetValue()) {
				cells[i][j + 1].SetValue(2 * cells[i][j + 1].GetValue());

				cells[i][j].SetValue(0);
				cells[i][j + 1].SetHasCollapsedThisTurn(true);
			}
		}
	}
}

Board Board::GetCopyBoard()
{
	Board newBoard;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			newBoard.cells[i][j].SetValue(cells[i][j].GetValue());
		}
	}
	return newBoard;
}