#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

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

	Fixed				&operator=(const Fixed &_fix);
	~Fixed();

	bool				operator>(const Fixed &_fix) const;
	bool				operator<(const Fixed &_fix) const;
	bool				operator>=(const Fixed &_fix) const;
	bool				operator<=(const Fixed &_fix) const;
	bool				operator==(const Fixed &_fix) const;
	bool				operator!=(const Fixed &_fix) const;
	
	Fixed				operator+(const Fixed &_fix) const;
	Fixed				operator-(const Fixed &_fix) const;
	Fixed				operator*(const Fixed &_fix) const;
	Fixed				operator/(const Fixed &_fix) const;

	Fixed				&operator++(void);
	Fixed				&operator--(void);

	const Fixed			operator++(int);
	const Fixed			operator--(int);

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream 	&operator<<(std::ostream &os, const Fixed &fix);

#endif
