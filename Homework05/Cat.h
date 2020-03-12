#pragma once
#include "Animal.h"

class Cat : public Animal {
public: 
	Cat(std::string n);

	void speak();
};

