#include "../includes/Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float &_x, const float &_y) : x(Fixed(_x)), y(Fixed(_y)) {}

Point::Point(const Point &_p) : x(Fixed(_p.getFixedX())), y(Fixed(_p.getFixedY())) {}

Fixed	Point::getFixedX(void) const
{
	return (this->x);
}

Fixed	Point::getFixedY(void) const
{
	return (this->y);
}

Point::~Point()
{
}

bool	equalVector(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	distA(0);
	Fixed	distB(0);
	int		direction = 1;

	distA = ((b.getFixedX() - a.getFixedX()) * (a.getFixedY() - point.getFixedY()) - (b.getFixedY() - a.getFixedY()) * (a.getFixedX() - point.getFixedX())) \
		/ (((b.getFixedX() - a.getFixedX()) * (b.getFixedX() - a.getFixedX()) + (b.getFixedY() - a.getFixedY()) * (b.getFixedY() - a.getFixedY())) \
			/ ((b.getFixedX() - a.getFixedX()) * (b.getFixedX() - a.getFixedX()) + (b.getFixedY() - a.getFixedY()) * (b.getFixedY() - a.getFixedY())));
	direction = distA.toFloat() > 0 ? direction * 1 : direction * (-1);

	distB = ((b.getFixedX() - a.getFixedX()) * (a.getFixedY() - c.getFixedY()) - (b.getFixedY() - a.getFixedY()) * (a.getFixedX() - c.getFixedX())) \
		/ (((b.getFixedX() - a.getFixedX()) * (b.getFixedX() - a.getFixedX()) + (b.getFixedY() - a.getFixedY()) * (b.getFixedY() - a.getFixedY())) \
			/ ((b.getFixedX() - a.getFixedX()) * (b.getFixedX() - a.getFixedX()) + (b.getFixedY() - a.getFixedY()) * (b.getFixedY() - a.getFixedY())));
	direction = distB.toFloat() > 0 ? direction * 1 : direction * (-1);

	if (distA.toFloat() == 0 || distB.toFloat() == 0)
		return (false);
	return (direction > 0 ? true : false);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	return (equalVector(a, b, c, point) && equalVector(a, c, b, point) && equalVector(b, c, a, point));
}
