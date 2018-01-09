#include <iostream>
#include "fnc.h"

int main()
{
	Point p1(3);
	Point p2(3);

	p1.setCoord(0, -1.0);
	p1.setCoord(1, -1.0);
	p1.setCoord(2, -1.0);

	//p1 *= 2.0;

	std::cout << "Coordinates of point p1\n";
	for (size_t i = 0; i < p1.getNumOfCoords(); ++i)
		std::cout << p1.getCoord(i) << std::endl;
	
	p2.setCoord(0, 2.0);
	p2.setCoord(1, 2.0);
	p2.setCoord(2, 2.0);

	//p2 /= 2.0;

	std::cout << std::endl;

	std::cout << "Coordinates of point p2\n";
	for (size_t i = 0; i < p2.getNumOfCoords(); ++i)
		std::cout << p2.getCoord(i) << std::endl;

	Point sumPoint = p1 + p2;
	Point diffPoint = p1 - p2;

	std::cout << std::endl;

	std::cout << "Coordinates of sum of points p1 and p2\n";
	for (size_t i = 0; i < sumPoint.getNumOfCoords(); ++i)
		std::cout << sumPoint.getCoord(i) << std::endl;

	std::cout << std::endl;

	std::cout << "Coordinates of difference of points p1 and p2\n";
	for (size_t i = 0; i < diffPoint.getNumOfCoords(); ++i)
		std::cout << diffPoint.getCoord(i) << std::endl;

	std::cout << std::endl;

	std::cout << "Dot product of the coordinates of p1 and p2\n";
	std::cout << p1*p2 << std::endl;

	std::cout << std::endl;

	std::cout << "The distance between point p1 and point p2 is " << fnc::dist(p1, p2) << std::endl;
	std::cout << "The length of point p1 is " << p1.getLength() << std::endl;
	std::cout << "The length of point p2 is " << p2.getLength() << std::endl;

	return 0;
}