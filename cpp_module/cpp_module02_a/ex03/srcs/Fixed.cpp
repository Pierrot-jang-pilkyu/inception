#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	this->RawBits = 0;
}

Fixed::Fixed(const int raw)
{
	this->RawBits = raw << this->fixedPoint;
}

Fixed::Fixed(const float raw)
{
	this->RawBits = roundf(raw * (1 << this->fixedPoint));
}

Fixed::Fixed(const Fixed &_fix)
{
	*this = _fix;
}

int	Fixed::getRawBits(void) const
{
	return (this->RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->RawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->RawBits / (1 << this->fixedPoint));
}

int		Fixed::toInt(void) const
{
	return (this->RawBits >> this->fixedPoint);
}

Fixed	&Fixed::operator=(const Fixed &_fix)
{
	if (this != &_fix)
	{
		this->RawBits = _fix.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
}

bool	Fixed::operator>(const Fixed &_fix) const
{
	return (this->toFloat() > _fix.toFloat());
}

bool	Fixed::operator<(const Fixed &_fix) const
{
	return (this->toFloat() < _fix.toFloat());
}

bool	Fixed::operator>=(const Fixed &_fix) const
{
	return (this->toFloat() >= _fix.toFloat());
}

bool	Fixed::operator<=(const Fixed &_fix) const
{
	return (this->toFloat() <= _fix.toFloat());
}

bool	Fixed::operator==(const Fixed &_fix) const
{
	return (this->toFloat() == _fix.toFloat());
}

bool	Fixed::operator!=(const Fixed &_fix) const
{
	return (this->toFloat() != _fix.toFloat());
}

Fixed	Fixed::operator+(const Fixed &_fix) const
{
	Fixed	temp(this->toFloat() + _fix.toFloat());

	return (temp);
}

Fixed	Fixed::operator-(const Fixed &_fix) const
{
	Fixed	temp(this->toFloat() - _fix.toFloat());

	return (temp);
}

Fixed	Fixed::operator*(const Fixed &_fix) const
{
	Fixed	temp(this->toFloat() * _fix.toFloat());

	return (temp);
}

Fixed	Fixed::operator/(const Fixed &_fix) const
{
	Fixed	temp(this->toFloat() / _fix.toFloat());

	return (temp);
}

Fixed	&Fixed::operator++(void)
{
	this->RawBits++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->RawBits--;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->RawBits++;
	return (temp);
}

const Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->RawBits--;
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a <= b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a >= b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a <= b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a >= b ? a : b);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &_fix)
{
	os << _fix.toFloat();
	return (os);
}
