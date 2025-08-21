#include "Point.hpp"

int	main(void)
{
	Point	a(2.3f, 4.2f);
	Point	b(30, 50);

	std::cout << a.getX() << std::endl;
	std::cout << a.getY() << std::endl;
	std::cout << b.getX() << std::endl;
	std::cout << b.getY() << std::endl;
	b = a;
	std::cout << b.getX() << std::endl;
	std::cout << b.getY() << std::endl;
}