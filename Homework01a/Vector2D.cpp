#include "pch.h"
#include "framework.h"
#include "Vector2D.h"
#include <sstream>

void fnVector2D() {
}

Vector2D::Vector2D(int x, int y):xA(x),yA(y) {
}

std::string Vector2D::toString() const {
	std::stringstream ss;
	ss << "("<< xA <<"," << yA << ")";
	return ss.str();
}

bool Vector2D::operator==(const Vector2D& rhs)const {
	return this->xA + this->yA == rhs.xA + rhs.yA;
}

bool Vector2D::operator!=(const Vector2D& rhs) const {
	return this->xA + this->yA != rhs.xA + rhs.yA;
}

bool Vector2D::operator>(const Vector2D& rhs) const {
	return this->xA + this->yA > rhs.xA + rhs.yA;
}

bool Vector2D::operator<(const Vector2D& rhs)const {
	return this->xA +this->yA  < rhs.xA + rhs.yA;
}
