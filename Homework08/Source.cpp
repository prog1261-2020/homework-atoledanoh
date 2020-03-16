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
*  < Object Orientated Programming in C++ homework 08: Read the file and count the occurrences of each word.>
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
#include <fstream>
#include <map>
#include <algorithm>
#include <cctype>


int main() {

	std::fstream myFile;
	std::string buffer;
	std::map<std::string, int> myMap;
	myFile.open("fox.txt");

	//checking if file opened correctly
	if (!myFile) {
		std::cout << "Error accessing the file";
		exit(-1);
	}

	//main part, reading the file, inserting it in the map and counting of occurrences 
	while (!myFile.eof()) {
		myFile >> buffer;
		//transforming text to take care of case and punctuation. ("book", "Book", and "book!" are all the same word)
		std::transform(buffer.begin(), buffer.end(), buffer.begin(),
			//converting the text to lower case 
			[](char n) {
				return std::tolower(n);
			}
		);

		//Checking if the buffer contains alphabetic characters
		for (int i = 0; i < buffer.size(); i++) {
			if (std::isalpha(buffer.at(i)) == false) {
				buffer.erase(buffer.begin() + i);
				i -= 1;
			}
		}

		auto p = myMap.find(buffer);

		//incrementing the count of occurrences of the word
		if (p != myMap.end()) {
			p->second += 1;
		}
		//or staring a new one
		else {
			myMap.insert({ buffer, 1 });
		}
	}

	//iterating through the map to print it
	for (auto i : myMap) {
		std::cout << "Word: " << i.first << "\t\t" << "Count: " << i.second << std::endl;
	}
}