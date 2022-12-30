#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->RawBits = 0;
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->RawBits = raw << this->fixedPoint;
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->RawBits = roundf(raw * (1 << this->fixedPoint));
}

Fixed::Fixed(const Fixed &_fix)
{
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &_fix)
	{
		this->RawBits = _fix.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &_fix)
{
	os << _fix.toFloat();
	return (os);
}
