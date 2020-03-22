#include "HumanPlayer.h"
#include <iostream>
#include <string>

int HumanPlayer::makeMove() {
	char choice = 'a';
	while (!(choice >= '1' && choice <= '9')) {
		std::cout << "Enter a number between 1 and 9: ";
		std::string s;
		std::cin >> s;
		if (s.size() != 1) {
			continue;
		} else {
			choice = s[0];
		}
	}
	move = choice - '0';
	return (choice - '0');
}

int HumanPlayer::getMove() {
	return move;
}