#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include "Point.h"

class LineSegment
{
	Point* start;
	Point* end;
public:
	// default constructor
	LineSegment();
	// constructor
	LineSegment(Point* start_, Point* end_);
	// copy assignment operator
	LineSegment& operator=(const LineSegment& rhs);
	// destructor
	~LineSegment();

	// accessors
	Point* getStart() const;
	Point* getEnd() const;
	double getLength();
	void setEndPoints(Point* start, Point* end);

	// operator overloaders
	LineSegment operator+(const LineSegment& rhs);
};
#endif // !LINE_SEGMENT_H