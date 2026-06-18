#include <iostream>
#include <vector>
#include "game.h"

std::string playerOne;
std::string playerTwo;
std::vector<char> board = {
	'1', '2', '3',
	'4', '5', '6',
	'7', '8', '9'
};
int playerSelection;

void gameStart()
{
	std::cout << "Welcome to Tic Tac Toe!\n";
	setPlayerNames();
	displayBoard();

	while (true)
	{
		takeTurn(playerOne, 'X');

		if (checkWin('X'))
		{
			std::cout << playerOne << " wins!\n";
			break;
		}

		takeTurn(playerTwo, 'O');

		if (checkWin('O'))
		{
			std::cout << playerTwo << " wins!\n";
			break;
		}
	}
}

void setPlayerNames() {
	std::cout << "Enter player one's name(X): ";
	std::cin >> playerOne;
	std::cout << "Enter player two's name(O): ";
	std::cin >> playerTwo;
	displayBoard();
}

void displayBoard() {
	system("cls");
	std::cout << "~Tic Tac Toe~" << std::endl;
	std::cout << "  |-----------------|" << std::endl;
	std::cout << "  |  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  | " << std::endl;
	std::cout << "  |-----------------|" << std::endl;
	std::cout << "  |  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  | " << std::endl;
	std::cout << "  |-----------------|" << std::endl;
	std::cout << "  |  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  | " << std::endl;
	std::cout << "  |-----------------|" << std::endl;
}

void playerSelect(int choice, char player) {

	switch (choice) {
	case 1:
		board[0] = player;
		break;
	case 2:
		board[1] = player;
		break;
	case 3:
		board[2] = player;
		break;
	case 4:
		board[3] = player;
		break;
	case 5: 
		board[4] = player;
		break;
	case 6:
		board[5] = player;
		break;
	case 7:
		board[6] = player;
		break;
	case 8:
		board[7] = player;
		break;
	case 9:
		board[8] = player;
		break;
	default:
		std::cout << "Invalid selection. Please choose a number between 1 and 9.\n";
		break;
	}
	
	displayBoard();
}

void takeTurn(const std::string& playerName, char symbol)
{
	int selection;

	while (true)
	{
		std::cout << playerName << " select a square: ";

		if (!(std::cin >> selection))
		{
			std::cin.clear();
			std::cin.ignore(
				std::numeric_limits<std::streamsize>::max(),
				'\n'
			);

			std::cout << "Please enter a number from 1 to 9.\n";
			continue;
		}

		if (selection < 1 || selection > 9)
		{
			std::cout << "Please enter a number from 1 to 9.\n";
			continue;
		}

		int index = selection - 1;

		if (board[index] == 'X' || board[index] == 'O')
		{
			std::cout << "That square is already taken. Try again.\n";
			continue;
		}

		board[index] = symbol;
		displayBoard();
		break;
	}
}
void gameReset() {
	//optional: add a prompt to ask if the players want to play again
}

bool checkWin(char symbol)
{
	return
		// Rows
		(board[0] == symbol && board[1] == symbol && board[2] == symbol) ||
		(board[3] == symbol && board[4] == symbol && board[5] == symbol) ||
		(board[6] == symbol && board[7] == symbol && board[8] == symbol) ||

		// Columns
		(board[0] == symbol && board[3] == symbol && board[6] == symbol) ||
		(board[1] == symbol && board[4] == symbol && board[7] == symbol) ||
		(board[2] == symbol && board[5] == symbol && board[8] == symbol) ||

		// Diagonals
		(board[0] == symbol && board[4] == symbol && board[8] == symbol) ||
		(board[2] == symbol && board[4] == symbol && board[6] == symbol);
}
