#include "Dragon.h"

Dragon::Dragon(std::string n) : Animal(n, "dragon", "I am fire! I am... death!") {}

int Dragon::pet() {
	return ++petted;
}

void Dragon::speak() const {
	std::cout << " and  I AM KING UNDER THE MOUNTAIN!\n" << getSound() << std::endl;
}

void Dragon::move() {
	std::cout << " My teeth are swords. My claws are spears. My wings are a HURRICANE!\n";
}