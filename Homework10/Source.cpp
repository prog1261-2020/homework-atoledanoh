#include <iostream>
#include <string>
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

const std::string boardPositions = "1 2 3\n4 5 6\n7 8 9\n\n";

int main() {

	bool quit = false;

	while (!quit) {
		system("cls");

		Game game;

		while (game.isPlaying()) {
			system("cls");
			std::cout << "KeyPad Numbers:\n";
			std::cout << boardPositions;
			std::cout << "Current Board:\n";
			std::cout << game.getCurrentBoard();
			Player* player = game.getNextPlayer();

			while (!game.isValid(player->getMove())) {
				player->makeMove();
			}
			game.makeMove(player->getMove());
		}

		system("cls");
		std::cout << boardPositions;
		std::cout << game.getCurrentBoard();

		int hasWon = game.isWon();
		switch (hasWon) {
		case 1:
			std::cout << "PLAYER 1 WINS!\n";
			break;
		case 2:
			std::cout << "PLAYER 2 WINS!\n";
			break;
		default:
			std::cout << "DRAW!\n";
		}
		system("pause");

		std::cout << "Do you want to play again?\nY - YES\nN - NO\n";
		char c;
		std::cin >> c;
		while (!(c == 'y' || c == 'Y' || c == 'n' || c == 'N')) {
			system("cls");
			std::cout << "Invalid option.\nDo you want to play again? :\nY - YES\nN - NO\n";
			std::cin >> c;
		}

		switch (c) {
		case 'y':
		case 'Y':
			break;
		case 'n':
		case 'N':
			quit = true;
			break;
		}
	}
}