#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
	Fixed const	x;
	Fixed const	y;

public:
	Point();
	Point(const float &_x, const float &_y);
	Point(const Point &_p);

	Fixed	getFixedX(void) const;
	Fixed	getFixedY(void) const;

	~Point();
};

bool	equalVector(Point const a, Point const b, Point const c, Point const point);

bool 	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
