#include "Fixed.hpp"

int main() {
    Fixed a(1.5f);
    Fixed b(-1);
    Fixed e(7);

    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a * b + e: " << (a * b + e) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl; 
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl; 
    std::cout << "a--: " << a-- << std::endl; 
	Fixed f(std::numeric_limits<float>::max());
	std::cout << "++f: " << ++f << std::endl;
	Fixed g(0x7FFF);
	std::cout << "++g: " << ++g << std::endl;
	std::cout << "a: " << a << std::endl;
	Fixed c;
	Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << d << std::endl;
	std::cout << d << std::endl;
	std::cout << Fixed::max( c, d ) << std::endl;
	return 0;
}
