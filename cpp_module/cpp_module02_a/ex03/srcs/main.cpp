#include "../includes/Point.hpp"

int main( void )
{
	Point	a;
	Point	b( 2.0f, 0 );
	Point	c( 0, 2.0f );
	Point	p( 1.0f, 1.0f );

	std::cout << "a.x : " << a.getFixedX() << ", a.y : " << a.getFixedY() << std::endl;
	std::cout << "b.x : " << b.getFixedX() << ", b.y : " << b.getFixedY() << std::endl;
	std::cout << "c.x : " << c.getFixedX() << ", c.y : " << c.getFixedY() << std::endl;
	std::cout << "p.x : " << p.getFixedX() << ", p.y : " << p.getFixedY() << std::endl << std::endl;

	if (bsp(a, b, c, p))
		std::cout << "result : IN\n";
	else
		std::cout << "result : OUT\n";

	return 0;
}
