#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle
{
	Point* downLeft;
	Point* upperRight;
public:
	// default constructor
	Rectangle();
	// constructor
	Rectangle(Point* downLeft_, Point* upperRight_);
	// destructor
	~Rectangle();

	// accessors
	Point* getDownLeft() const;
	Point* getUpperRight() const;

	bool contains(Point* p);
};

#endif // !RECTANGLE_H