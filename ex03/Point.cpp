#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(float const one, float const two) : x(one), y(two)
{
}

Point::Point(Point const& other) : x(other.x), y(other.y)
{
}

Point& Point::operator=(Point const& other)
{
    if (this != &other)
    {
    }
    return *this;
}

Fixed const &Point::getX(void) const
{
	return x;
}

Fixed const &Point::getY(void) const
{
	return y;
}