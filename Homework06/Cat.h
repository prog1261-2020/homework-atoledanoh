#pragma once
#include "Animal.h"

class Cat : public Animal {
public: 
	Cat(std::string n);
	int pet();
	void speak() const override;
	void move() override;
private:
	int petted = 0;
};

