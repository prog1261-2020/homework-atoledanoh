#include "Cat.h"

Cat::Cat(std::string n) : Animal(n, "cat", "Miau") {}

void Cat::speak() {
	Animal::speak();
	std::cout << " and I like mice.\n";
}