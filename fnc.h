#ifndef FNC_H
#define FNC_H

#include "Point.h"
#include "LineSegment.h"

namespace fnc
{
	double dist(Point& p1, Point& p2);
	double dist(LineSegment& l, Point& p);
}

#endif // !FNC_H