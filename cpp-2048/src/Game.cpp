#include <iostream>
#include <fstream>
#include <optional>
#include <conio.h>
#include <vector>
#include <string>
import Game;

Game::Game()
{
	this->_gameEnded = false;
}

std::optional<std::string> ReadSaveAsString()
{
	std::ifstream stream("../save.txt");
	if (stream)
	{
		std::string res;

		stream.close();
		return res;
	}

	return "";
}

void Game::Play()
{
	while (!this->_gameEnded)
	{
		std::cout << "\033[2J\033[H";
		this->_board.InsertNewValue();
		this->_board.PrintCells();
		this->_ReadChar();
		this->_HandleChar();
		this->_board.Move(this->_ch);
	}
	std::cout << std::endl << std::endl << "Game Ended, thanks for playing";
}

void Game::_ReadChar()
{
	char a = _getch();

	while (a != 'a' && a != 's' && a != 'd' && a != 'w' && a != 'o' && a != 'l' && a != 'q')
	{
		a = getch();
		a = std::tolower(a);
		std::cout
			<< "w: up, a: left, s: down, d: right, r: restart, o: save, q: "
			"quit, l: load save\n\n";
	}
	this->_ch = a;
}

void Game::_HandleChar()
{
	if (this->_ch == 'q')
	{
		this->_gameEnded = true;
		return;
	}
	
	if (this->_ch == 'o')
	{
		std::vector<int> map;
		std::string savedMap;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int elem = this->_board.cells[i][j].GetValue();
				savedMap += std::to_string(elem);
				savedMap += " ";
			}
		}
		std::ofstream saveFile("save.txt");

		if (saveFile.is_open()) {
			saveFile << savedMap;
		}
		saveFile.close();
	}

	if (this->_ch == 'l')
	{
		std::optional<std::string> data = ReadSaveAsString();
		if (!data)
		{
			std::cout << "No save file found" << std::endl;
			return;
		}
		std::istringstream map();
		std::string line;


		std::cout << "Save file successfully loaded" << std::endl;
		return;
	}
}

bool Game::IsGameEnded() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (this->_board.cells[i][j].GetValue() == 2048) {
				this->_gameEnded;
				return true;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int value = this->_board.cells[i][j].GetValue();
			if (j != 4 - 1 && _board.cells[i][j + 1].GetValue() == value ||
				j != 0 && _board.cells[i][j - 1].GetValue() == value ||
				i != 4 - 1 && _board.cells[i + 1][j].GetValue() == value ||
				i != 0 && _board.cells[i - 1][j].GetValue() == value ||
				j != 4 - 1 && _board.cells[i][j + 1].GetValue() == 0 ||
				j != 0 && _board.cells[i][j - 1].GetValue() == 0 ||
				i != 4 - 1 && _board.cells[i + 1][j].GetValue() == 0 ||
				i != 0 && _board.cells[i - 1][j].GetValue() == 0) {
				return false;
			}
		}
	}

	this->_gameEnded = true;
	return true;
}