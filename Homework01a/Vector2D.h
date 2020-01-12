#pragma once
#include <string>
#include <ostream>
class Vector2D
{
public:
	Vector2D(int x, int y);
	std::string toString() const;
	bool operator<(const Vector2D& rhs)const;
	bool operator==(const Vector2D& rhs)const;
	bool operator!=(const Vector2D& rhs)const;
	bool operator>(const Vector2D& rhs)const;

private:
	int xA;
	int yA;
};