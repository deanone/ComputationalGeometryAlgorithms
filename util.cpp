#include "util.h"
#include <cmath>
#include <limits>

// Donald Knuth's proposal for a floating point comparison
bool util::approximatelyEqual(double a, double b)
{
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * std::numeric_limits<double>::epsilon());
}