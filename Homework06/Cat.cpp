#include "Cat.h"

Cat::Cat(std::string n) : Animal(n, "cat", "Miau") {}

int Cat::pet() {
	return ++petted;
}

void Cat::speak() const {
	std::cout << " and I like mice.\n" << getSound() << std::endl;
}

void Cat::move() {
	std::cout << "I prowl my prey.\n";
}