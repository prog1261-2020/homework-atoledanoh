#include "Mouse.h"

Mouse::Mouse(std::string n) : Animal(n, "mouse", "Squeak") {}

int Mouse::pet() {
	return ++petted;
}

void Mouse::speak() const {
	std::cout << " and I hide from the cat.\n" << getSound() << std::endl;
}

void Mouse::move() {
	std::cout << "I run quickly.\n";
}