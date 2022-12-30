#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->RawBits = 0;
}

Fixed::Fixed(const Fixed &_fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = _fix;
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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->RawBits = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
