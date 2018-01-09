#include "Rectangle.h"

Rectangle::Rectangle() : downLeft(nullptr), upperRight(nullptr)
{
}

Rectangle::Rectangle(Point* downLeft_, Point* upperRight_) : downLeft(downLeft_), upperRight(upperRight_)
{
}

Rectangle::~Rectangle()
{
	if (downLeft != nullptr) delete downLeft;
	if (upperRight != nullptr) delete upperRight;
}

Point* Rectangle::getDownLeft() const
{
	return downLeft;
}

Point* Rectangle::getUpperRight() const
{
	return upperRight;
}

bool Rectangle::contains(Point* p)
{
	Point v1 = p - downLeft;
	Point v2 = p - upperRight;
	double cosTheta = (v1 * v2) / (v1.getLength() * v2.getLength());
	return cosTheta <= 0.0 ? true : false;
}