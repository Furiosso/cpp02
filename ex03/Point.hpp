#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(float x, float y);
		Point(const Point& src);
		~Point();
		Point& operator=(const Point& rhs);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif