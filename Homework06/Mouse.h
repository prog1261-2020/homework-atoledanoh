#pragma once
#include "Animal.h"

class Mouse : public Animal {
public:
	Mouse(std::string n);
	int pet();
	void speak() const override;
	void move() override;
private:
	int petted = 0;
};

