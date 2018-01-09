#include "fnc.h"
/*!
 * Computes the distance between two Points.
 * @param p1 the first Point
 * @param p2 the second Point
 * @return the distance between the two Points
 */
double fnc::dist(Point& p1, Point& p2)
{
	Point diffPoint = p1 - p2;
	double distance = std::sqrt(diffPoint * diffPoint);
	return distance;
}

/*!
 * Computes the distance between a LineSegment and a Point.
 * @param l the LineSegment
 * @param p the Point
 * @return the distance between the LineSegment and the Point.
 */
double fnc::dist(LineSegment& l, Point& p)
{
	Point ps = p - *l.getStart();
	Point es = *l.getEnd() - *l.getStart();
	double t = (ps * es) / (es * es);
	es *= t;
	double distance = (ps - es).getLength();
	return distance;
}