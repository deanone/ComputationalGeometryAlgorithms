#include "LineSegment.h"
#include "fnc.h"

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