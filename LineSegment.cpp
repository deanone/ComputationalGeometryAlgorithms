#include "LineSegment.h"
#include "fnc.h"
#include "util.h"

// 4 * atan(1) = pi is the most generic solution for computing the value of pi
// and works with the precision of the particular machine
const double pi = 4 * std::atan(1);

LineSegment::LineSegment() : start(nullptr), end(nullptr)
{
}

LineSegment::LineSegment(Point* start_, Point* end_) : start(start_), end(end_)
{
}

LineSegment& LineSegment::operator=(const LineSegment& rhs)
{
	this->start = rhs.start;
	this->end = rhs.end; 
	return *this;
}

LineSegment::~LineSegment()
{
	if (start != nullptr) delete start;
	if (end != nullptr) delete end;
}

Point* LineSegment::getStart() const
{
	return start;
}

Point* LineSegment::getEnd() const
{
	return end;
}

double LineSegment::getLength()
{ 
	return fnc::dist(*start, *end); 
}

void LineSegment::setEndPoints(Point* start, Point* end) 
{ 
	this->start = start; 
	this->end = end; 
}

LineSegment LineSegment::operator+(const LineSegment& rhs)
{
	LineSegment result(this->start, rhs.end);
	return result;
}

bool LineSegment::contains(Point* p)
{
	Point v1 = (*p) - (*start);
	Point v2 = (*p) - (*end);
	double theta = std::acos((v1 * v2) / (v1.getLength() * v2.getLength()));
	return util::approximatelyEqual(theta, pi);
}