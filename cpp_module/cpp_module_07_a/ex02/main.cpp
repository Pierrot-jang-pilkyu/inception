#include "Array.hpp"

int main(void)
{
	std::size_t n = 3;
	Array<int> a(n);

	std::cout << std::endl;
	for (std::size_t i = 0; i < a.size(); i++)
		std::cout << "a : " << a[i] << std::endl;

	for (std::size_t i = 0; i < a.size(); i++)
		a[i] = i;

	Array<int> b(a);

	std::cout << std::endl;
	for (std::size_t i = 0; i < b.size(); i++)
	{
		std::cout << "b : " << b[i] << std::endl;
	}
	for (std::size_t i = 0; i < b.size(); i++)
	{
		b[i] = 10 -i;
	}
	std::cout << std::endl;
	for (std::size_t i = 0; i < b.size(); i++)
	{
		std::cout << "a : " << a[i] << ", b : " << b[i] << std::endl;
	}
	
	Array<int> c;
	c = b;

	std::cout << std::endl;
	for (std::size_t i = 0; i < c.size(); i++)
		std::cout << "c : " << c[i] << std::endl;

	try
	{
		Array<int> d(n);
		d[-1];
	}
	catch(const Array<int>::BadAccessException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<int> e(n);
		e[1000];
	}
	catch(const Array<int>::BadAccessException& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
