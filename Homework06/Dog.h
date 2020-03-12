#pragma once
#include "Animal.h"

class Dog : public Animal {
public:
	Dog(std::string n);
	int pet();
	void speak() const override;
	void move() override;
private:
	int petted = 0;
};
