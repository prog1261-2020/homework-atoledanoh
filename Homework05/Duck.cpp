#include "Duck.h"

Duck::Duck(std::string n) : Animal(n, "duck", "Cuac"){}

void Duck::speak() {
	Animal::speak();
	std::cout << " and I hate everyone.\n";
}