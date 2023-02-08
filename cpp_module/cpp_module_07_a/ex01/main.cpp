#include "iter.hpp"

int main(void)
{
	std::string arr[5] = { "apple", "bee", "cat", "dog", "energy" };

	std::size_t n = 5;
	iter(arr, n, &printT);

	return (0);
}
