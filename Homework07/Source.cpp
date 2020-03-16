/*
* @author  <Alejandro Toledano>
* @version <1.0>
*

* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
*
* @section DESCRIPTION
*  < Object Orientated Programming in C++ homework 07 file reading >
*
*
* @section LICENSE
*  <any necessary attributions>
*
*  Copyright 2020
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <ctime>

int main() {
	std::ifstream file1("Quiz.txt");
	std::vector<std::string>vec1{};
	std::vector<std::string>vec2{};
	std::vector<std::string>vec3{};
	int points = 0;
	std::string buffer;

	if (file1.fail()) {
		exit(-1);
	}

	while (!file1.eof()) {
		std::getline(file1, buffer);
		for (int i{ 0 }; i < buffer.size(); i++) {
			if (buffer.at(i) == '?') {
				vec1.push_back(buffer);
			}
			if (buffer.size() > 1 && buffer.at(i) != '?' && buffer.size() - i == 1) {
				vec2.push_back(buffer);
			}
			if (buffer.at(i) >= 48 && buffer.at(i) <= 57) {
				vec3.push_back((buffer));
			}
		}
	}

	std::cout << std::endl;
	std::string playerGuess;

	for (int k = 0; k < vec1.size(); k++) {
		std::cout << vec1.at(k) << std::endl;
		std::cout << vec2.at(k * 4) << "\n" << vec2.at((k * 4) + 1) << "\n" << vec2.at((k * 4) + 2) << "\n" << vec2.at((k * 4) + 3) << std::endl;
		std::cout << "Choose an answewr between 0 and 3\n";
		std::cin >> playerGuess;
		system("cls");
		if (playerGuess == vec3.at(k)) {
			std::cout << "Right answer!\n";
			points++;
		}
		else if (playerGuess != vec3.at(k)) {
			std::cout << "Wrong answer\n";
		}
	}
	system("cls");
	std::cout << "No lives left. You made " << points << " points.\n";

}