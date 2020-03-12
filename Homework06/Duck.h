#pragma once
#include "Animal.h"

class Duck : public Animal {
public:
	Duck(std::string n);
	int pet();
	void speak() const override;
	void move() override;
private:
	int petted = 0;
};