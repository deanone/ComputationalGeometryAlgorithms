#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include "Point.h"
#include <memory>

class LineSegment
{
	std::shared_ptr<Point> start;
	std::shared_ptr<Point> end;
public:
	// default constructor
	LineSegment();
	// constructor 1
	LineSegment(std::shared_ptr<Point> start_, std::shared_ptr<Point> end_);
	// constructor 2
	LineSegment(Point* start_, Point* end_);
	// copy assignment operator
	LineSegment& operator=(const LineSegment& rhs);
	// destructor
	~LineSegment();

	// accessors
	std::shared_ptr<Point> getStart() const;
	std::shared_ptr<Point> getEnd() const;
	double getLength();
	void setEndPoints(std::shared_ptr<Point> start, std::shared_ptr<Point> end);

	// operator overloaders

	bool contains(Point& p);
};
#endif // !LINE_SEGMENT_H