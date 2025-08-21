#include "Fixed.hpp"

int main() {
    Fixed a(1);
    Fixed b(3);

    std::cout << "a > b: " << (a > b) << std::endl;  // Imprime 1 (true)
    std::cout << "a < b: " << (a < b) << std::endl;  // Imprime 0 (false)
    std::cout << "a == b: " << (a == b) << std::endl; // Imprime 0 (false)
    std::cout << "a != b: " << (a != b) << std::endl; // Imprime 1 (true)
    std::cout << "a >= b: " << (a >= b) << std::endl; // Imprime 1 (true)
    std::cout << "a <= b: " << (a <= b) << std::endl; // Imprime 0 (false)
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl; // Imprime 0 (false)
    std::cout << "a - b: " << (a - b) << std::endl; // Imprime 0 (false)
    std::cout << "a * b: " << (a * b) << std::endl; // Imprime 0 (false)
    std::cout << "a / b: " << (a / b) << std::endl; // Imprime 0 (false)

    return 0;
}