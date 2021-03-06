#include "Point.h"
#include "util.h"

Point::Point(const size_t& numOfCoords)
{
	for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
		coords.push_back(0.0);	// 0.0 is the initial value for all the coordinates
}

/*!
 * Copy assignment operator.
 * @param right hand side operand
 * @param left hand side operand
 */
Point& Point::operator=(const Point& rhs)
{
	size_t numOfCoords = this->getNumOfCoords();
	size_t numOfCoords_rhs = rhs.getNumOfCoords();
	if (numOfCoords == numOfCoords_rhs)
	{
		for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
			this->setCoord(coordID, rhs.getCoord(coordID));
	}
	return *this;
}

Point::~Point()
{
	if (!coords.empty()) coords.clear();
}

void Point::setCoord(const size_t& coordID, const double& coordVal)
{
	size_t numOfCoords = this->getNumOfCoords();
	if (coordID >= 0 && coordID < numOfCoords)
		coords[coordID] = coordVal;
}

/*!
 * Returns a specific coordinate of the Point.
 * @param coordID the ID of the coordinate to be returned.
 * @return the specific coordinate of the Point.
 */
double Point::getCoord(const size_t& coordID) const
{
	size_t numOfCoords = this->getNumOfCoords();
	if (coordID >= 0 && coordID < numOfCoords)
		return coords[coordID];
	else
		return -1.0;	// -1.0 is defined as the error value. TODO: Define specific value as error value that will be used throughout the application
}
/*!
 * Returns the number of coordinates of the Point.
 * @parnam the number of coordinates of the Point.
 */
size_t Point::getNumOfCoords() const
{
	return coords.size();
}

/*!
 * Returns the length of the vector representation of the Point.
 * @return the length of the vector representation of the Point. 
 */
double Point::getLength()
{
	size_t numOfCoords = this->getNumOfCoords();
	double length = 0.0;
	for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
		length += this->getCoord(coordID) * this->getCoord(coordID);
	return std::sqrt(length);
}

bool Point::operator==(const Point& rhs)
{
	size_t numOfCoords = this->getNumOfCoords();
	size_t numOfCoord_rhs = rhs.getNumOfCoords();

	// first the vectors have to have the same size (or be in the same space)
	if (numOfCoords == numOfCoord_rhs)
	{
		bool same = true;
		// check if the Points differ at at least one coordinate
		for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
		{
			double lhsCoord = this->getCoord(coordID);
			double rhsCoord = rhs.getCoord(coordID);
			bool equal = util::approximatelyEqual(lhsCoord, rhsCoord);
			if (!equal)
			{
				same = false;
				break;
			}
		}
		return same;
	}
	else
		return false;
}

Point Point::operator+(const Point& rhs)
{
	size_t numOfCoords = this->getNumOfCoords();
	size_t numOfCoord_rhs = rhs.getNumOfCoords();

	if (numOfCoords == numOfCoord_rhs)
	{
		Point sumPoint = Point(numOfCoords);
		for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
		{
			double coordVal = this->getCoord(coordID) + rhs.getCoord(coordID);
			sumPoint.setCoord(coordID, coordVal);
		}
		return sumPoint;
	}
	// TODO: Check what should happen the 2 added points have different dimension
	else
	{
		size_t minNumOfCoords = (numOfCoords < numOfCoord_rhs) ? numOfCoords : numOfCoord_rhs;
		Point sumPoint = Point(minNumOfCoords);
		return sumPoint;
	}
}

Point Point::operator-(const Point& rhs)
{
	size_t numOfCoords = this->getNumOfCoords();
	size_t numOfCoord_rhs = rhs.getNumOfCoords();

	if (numOfCoords == numOfCoord_rhs)
	{
		Point diffPoint = Point(numOfCoords);
		for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
		{
			double coordVal = this->getCoord(coordID) - rhs.getCoord(coordID);
			diffPoint.setCoord(coordID, coordVal);
		}
		return diffPoint;
	}
	// TODO: Check what should happen the 2 substracted points have different dimension
	else
	{
		size_t minNumOfCoords = (numOfCoords < numOfCoord_rhs) ? numOfCoords : numOfCoord_rhs;
		Point diffPoint = Point(minNumOfCoords);
		return diffPoint;
	}
}

double Point::operator*(const Point& rhs)
{
	size_t numOfCoords = this->getNumOfCoords();
	size_t numOfCoord_rhs = rhs.getNumOfCoords();

	if (numOfCoords == numOfCoord_rhs)
	{
		double dotProduct = 0.0;
		for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
			dotProduct += (this->getCoord(coordID) * rhs.getCoord(coordID));
		return dotProduct;
	}
	// TODO: Check what should happen the 2 multiplied points have different dimension
	else
		return -1.0;
}

Point& Point::operator+=(const double& coordVal)
{
	size_t numOfCoords = this->getNumOfCoords();
	for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
		this->setCoord(coordID, this->getCoord(coordID) + coordVal);
	return *this;
}

Point& Point::operator-=(const double& coordVal)
{
	size_t numOfCoords = this->getNumOfCoords();
	for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
		this->setCoord(coordID, this->getCoord(coordID) - coordVal);
	return *this;
}

Point& Point::operator*=(const double& coordVal)
{
	size_t numOfCoords = this->getNumOfCoords();
	for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
		this->setCoord(coordID, this->getCoord(coordID) * coordVal);
	return *this;
}

Point& Point::operator/=(const double& coordVal)
{
	if (coordVal != 0.0)	// ATTENTION: Comparing doubles using !=. TODO: Make function for comparing doubles.
	{
		size_t numOfCoords = this->getNumOfCoords();
		for (size_t coordID = 0; coordID < numOfCoords; ++coordID)
			this->setCoord(coordID, this->getCoord(coordID) / coordVal);
	}
	return *this;
}