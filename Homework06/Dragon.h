#pragma once
#include "Animal.h"

class Dragon : public Animal {
public:
	Dragon(std::string n);
	int pet();
	void speak() const override;
	void move() override;
private:
	int petted = 0;
};

