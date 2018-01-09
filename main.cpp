#include <iostream>
#include "Point.h"
#include "LineSegment.h"
#include "fnc.h"

int main()
{
	//Point p1(3);
	//Point p2(3);

	//p1.setCoord(0, -1.0);
	//p1.setCoord(1, -1.0);
	//p1.setCoord(2, -1.0);

	////p1 *= 2.0;

	//std::cout << "Coordinates of point p1\n";
	//for (size_t i = 0; i < p1.getNumOfCoords(); ++i)
	//	std::cout << p1.getCoord(i) << std::endl;
	//
	//p2.setCoord(0, 2.0);
	//p2.setCoord(1, 2.0);
	//p2.setCoord(2, 2.0);

	////p2 /= 2.0;

	//std::cout << std::endl;

	//std::cout << "Coordinates of point p2\n";
	//for (size_t i = 0; i < p2.getNumOfCoords(); ++i)
	//	std::cout << p2.getCoord(i) << std::endl;

	//Point sumPoint = p1 + p2;
	//Point diffPoint = p1 - p2;

	//std::cout << std::endl;

	//std::cout << "Coordinates of sum of points p1 and p2\n";
	//for (size_t i = 0; i < sumPoint.getNumOfCoords(); ++i)
	//	std::cout << sumPoint.getCoord(i) << std::endl;

	//std::cout << std::endl;

	//std::cout << "Coordinates of difference of points p1 and p2\n";
	//for (size_t i = 0; i < diffPoint.getNumOfCoords(); ++i)
	//	std::cout << diffPoint.getCoord(i) << std::endl;

	//std::cout << std::endl;

	//std::cout << "Dot product of the coordinates of p1 and p2\n";
	//std::cout << p1*p2 << std::endl;

	//std::cout << std::endl;

	//std::cout << "The distance between point p1 and point p2 is " << fnc::dist(p1, p2) << std::endl;
	//std::cout << "The length of point p1 is " << p1.getLength() << std::endl;
	//std::cout << "The length of point p2 is " << p2.getLength() << std::endl;

	Point* start = new Point(2);
	Point* end = new Point(2);
	Point p(2);

	start->setCoord(0, 1.0);
	start->setCoord(1, 1.0);
	end->setCoord(0, 3.0);
	end->setCoord(1, 1.0);
	p.setCoord(0, 2.0);
	p.setCoord(1, 1.0);

	LineSegment l(start, end);

	std::cout << "Does the line segment with start s(" << l.getStart()->getCoord(0) << ", " << l.getStart()->getCoord(1) << ") and end e("
		<< l.getEnd()->getCoord(0) << ", " << l.getEnd()->getCoord(1) << ") contain the point p("
		<< p.getCoord(0) << ", " << p.getCoord(1) << ") ?\n";

	bool contains = l.contains(&p);
	if (contains)
		std::cout << "Yes\n";
	else
		std::cout << "No\n";

	std::cout << "Distance between p and s is " << fnc::dist(p, *l.getStart()) << std::endl;
	std::cout << "Distance between p and e is " << fnc::dist(p, *l.getEnd()) << std::endl;
	std::cout << "Distance between p and line segment is " << fnc::dist(l, p) << std::endl;


	return 0;
}