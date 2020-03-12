#include "Duck.h"

Duck::Duck(std::string n) : Animal(n, "duck", "Cuac"){}

int Duck::pet() {
	return ++petted;
}

void Duck::speak() const {
	std::cout << " and I hate everyone.\n" << getSound() << std::endl;
}

void Duck::move() {
	std::cout << "I can't run but I can fly.\n";
}