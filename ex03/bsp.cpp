#include "Point.hpp"

static Fixed   calculate_cross_product(const Point A, const Point B, const Point C)
{
	return (C.getX() - A.getX()) * (B.getY() - A.getY()) - (B.getX() - A.getX()) * (C.getY() - A.getY());
}

static bool    check_point_position(Fixed v1, Fixed v2, Fixed v3)
{
    if ((v1 > 0 && v2 > 0 && v3 > 0)
		|| (v1 < 0 && v2 < 0 && v3 < 0))
        return true;
    return false;
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed   v1;
    Fixed   v2;
    Fixed   v3;
    
    v1 = calculate_cross_product(a, b, point);
    v2 = calculate_cross_product(b, c, point);
    v3 = calculate_cross_product(c, a, point);
    return (check_point_position(v1, v2, v3));
}