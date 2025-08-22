#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(const Point& src)
{
	*this = src;
}

Point::~Point(void) {}

Point&	Point::operator=(const Point& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

const Fixed	Point::getX(void) const
{
	return this->_x;
}

const Fixed	Point::getY(void) const
{
	return this->_y;
}
