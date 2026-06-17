#include <iostream>
#include <vector>

std::string playerOne;
std::string playerTwo;
std::vector<int> board = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void initGame() {
	displayWelcomeMessage();
	getPlayerNames();
}

void displayWelcomeMessage() {
	std::cout << "Welcome to Tic Tac Toe!" << std::endl;
	std::cout << "=======================" << std::endl;
	displayboard();
}

void getPlayerNames() {
	std::cout << "\nEnter player one's name: ";
	std::cin >> playerOne;
	std::cout << "\nEnter player two's name: ";
	std::cin >> playerTwo;
}

void displayBoard() {
	std::cout << "|  " << board[0] << " | " << board[1] << " | " << board[2] << " |" << std::endl;
	std::cout << "|  " << board[3] << " | " << board[4] << " | " << board[5] << " |" << std::endl;
	std::cout << "|  " << board[6] << " | " << board[7] << " | " << board[8] << " |" << std::endl;
}

void playerSelect(int choice, int board[], char player) {
	if (choice == 1) {
		board[0] = player;
	}
	else if (choice == 2) {
		board[1] = player;
	}
	else if (choice == 3) {
		board[2] = player;
	}
	else if (choice == 4) {
		board[3] = player;
	}
	else if (choice == 5) {
		board[4] = player;
	}
	else if (choice == 6) {
		board[5] = player;
	}
	else if (choice == 7) {
		board[6] = player;
	}
	else if (choice == 8) {
		board[7] = player;
	}
	else if (choice == 9) {
		board[8] = player;
	}
}
