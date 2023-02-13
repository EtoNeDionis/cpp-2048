#include <iostream>
export module Game.Board.Cell;

export class Cell
{
public:
	Cell();

	int GetValue();
	bool GetHasCollapsedThisTurn();
	void SetValue(const int &value);
	void SetHasCollapsedThisTurn(const bool &hasMoved);

private:
	int _value = 0;
	bool _hasCollapsedThisTurn = false;
};

