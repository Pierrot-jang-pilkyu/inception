#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
private:
	std::size_t	len;
	T		*array;

public:
	Array(void);
	Array(std::size_t &n);
	Array(const Array &obj);
	Array	&operator=(const Array &obj);
	~Array(void);

	T	&operator[](std::size_t n);
	T	operator[](std::size_t n) const;

	std::size_t	size(void) const;

	class BadAccessException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

# include "Array.tpp"
#endif
