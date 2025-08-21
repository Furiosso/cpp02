#include "Fixed.hpp"

int main() {
    Fixed a(1.5f);
    Fixed b(-1);

    std::cout << "a > b: " << (a > b) << std::endl;  // Imprime 1 (true)
    std::cout << "a < b: " << (a < b) << std::endl;  // Imprime 0 (false)
    std::cout << "a == b: " << (a == b) << std::endl; // Imprime 0 (false)
    std::cout << "a != b: " << (a != b) << std::endl; // Imprime 1 (true)
    std::cout << "a >= b: " << (a >= b) << std::endl; // Imprime 1 (true)
    std::cout << "a <= b: " << (a <= b) << std::endl; // Imprime 0 (false)
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl; 
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl; 
    std::cout << "a--: " << a-- << std::endl; 
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