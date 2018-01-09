#include "fnc.h"

double fnc::dist(Point& p1, Point& p2)
{
	Point diffPoint = p1 - p2;
	double distance = std::sqrt(diffPoint * diffPoint);
	return distance;
}

double fnc::dist(LineSegment& l, Point& p)
{
	Point ps = p - *l.getStart();
	Point es = *l.getEnd() - *l.getEnd();
	double t = (ps * es) / (es * es);
	es *= t;
	double distance = (ps - es).getLength();
	return distance;
}