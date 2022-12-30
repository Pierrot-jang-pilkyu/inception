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
	Fixed(const Fixed &_fix);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed	&operator=(const Fixed &_fix);
	~Fixed();
};

#endif
