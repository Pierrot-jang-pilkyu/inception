#include <iostream>

template <typename T>
const char	*Array<T>::BadAccessException::what(void) const throw()
{
	return ("Index is out of bounds.");
}

template <typename T>
Array<T>::Array(void)
{
	len = 0;
	array = NULL;
}

template <typename T>
Array<T>::Array(std::size_t &n)
{
	if (n == 0)
	{
		len = 0;
		array = NULL;
		return ;
	}
	len = n;
	array = new T[n];
	for (std::size_t i = 0; i < n; ++i)
		array[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &obj)
{
	this->len = 0;
	this->array = NULL;

	*this = obj;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &obj)
{
	if (this->len)
		delete[] this->array;

	this->len = obj.size();

	this->array = new T[obj.size()];
	if (obj.size() != 0)
	{
		for (std::size_t i = 0; i < this->len; i++)
			this->array[i] = obj.array[i];
	}
	else
		this->array = NULL;
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	if (array)
	{
		delete[] array;
		array = NULL;
	}
}

template <typename T>
T &Array<T>::operator[](std::size_t n)
{
	if (n < 0)
		throw Array<T>::BadAccessException();
	if (n >= this->len)
		throw Array<T>::BadAccessException();
	return (this->array[n]);
}

template <typename T>
T Array<T>::operator[](std::size_t n) const
{
	if (n < 0)
		throw Array<T>::BadAccessException();
	if (n >= this->len)
		throw Array<T>::BadAccessException();
	return (this->array[n]);
}

template <typename T>
std::size_t Array<T>::size(void) const
{
	return (this->len);
}
