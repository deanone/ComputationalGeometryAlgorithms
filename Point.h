#ifndef POINT_H
#define POINT_H

#include <vector>

class Point
{
	std::vector<double> coords;
public:
	// constructor
	Point(const size_t& numOfCoords);
	// copy assignment operator
	Point& operator=(const Point& rhs);
	// destructor
	~Point();

	// accessors
	void setCoord(const size_t& coordID, const double& coordVal);
	double getCoord(const size_t& coordID) const;
	size_t getNumOfCoords() const;
	double getLength();
	
	// operator overloaders
	Point operator+(const Point& rhs);
	Point operator-(const Point& rhs);
	double operator*(const Point& rhs);
	Point& operator+=(const double& coordVal);
	Point& operator-=(const double& coordVal);
	Point& operator*=(const double& coordVal);
	Point& operator/=(const double& coordVal);

};
#endif // !POINT_H