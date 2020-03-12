#include "Dog.h"

Dog::Dog(std::string n) : Animal(n, "dog", "Guau") {}

void Dog::speak() {
	Animal::speak();
	std::cout << " and I like to walk.\n";
}