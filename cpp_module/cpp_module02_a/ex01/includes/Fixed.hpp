#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int					RawBits;
	static const int	fixedPoint = 8;

public:
	Fixed();
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed &_fix);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed			&operator=(const Fixed &_fix);
	~Fixed();
};

std::ostream 	&operator<<(std::ostream &os, const Fixed &fix);

#endif
