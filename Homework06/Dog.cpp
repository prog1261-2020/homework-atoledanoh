#include "Dog.h"

Dog::Dog(std::string n) : Animal(n, "dog", "Guau") {}

int Dog::pet() {
	return ++petted;
}

void Dog::speak() const {
	std::cout << " and I like to walk.\n" << getSound() << std::endl;
}

void Dog::move() {
	std::cout << "I track and run.\n";
}