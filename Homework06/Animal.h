#pragma once
#include <string>
#include <iostream>

class Animal
{
public:
	Animal();
	virtual void speak() const;
	virtual void move() = 0;
	const std::string& getName() const;
	const std::string& getType() const;
	const std::string& getSound() const;

protected:
	Animal(const std::string& name, const std::string& type, const std::string& sound);
	std::string name;
	std::string type;
	std::string sound;
};

