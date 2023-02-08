#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void	iter(T *arr, std::size_t arr_len, void (*f)(T&))
{
	for (std::size_t i = 0; i < arr_len; ++i)
		f(arr[i]);
}

template <typename T>
void	printT(T &str)
{
	std::cout << str << std::endl;
}

#endif
