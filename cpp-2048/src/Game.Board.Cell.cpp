import Game.Board.Cell;
#include <iostream>

Cell::Cell()
{
	this->_hasCollapsedThisTurn = false;
	this->_value = 0;
}

int Cell::GetValue()
{
	return this->_value;
};

bool Cell::GetHasCollapsedThisTurn()
{
	return this->_hasCollapsedThisTurn;
}


void Cell::SetValue(const int &value)
{
	this->_value = value;
}

void Cell::SetHasCollapsedThisTurn(const bool &hasMoved)
{
	this->_hasCollapsedThisTurn = hasMoved;
}