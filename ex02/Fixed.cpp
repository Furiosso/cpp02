#include "Fixed.hpp"

const int	Fixed::_fr_bits = 8;

Fixed::Fixed(void) : _fix(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fix(value << _fr_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fix(roundf(value * (1 << _fr_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fix = src.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fix = rhs.getRawBits();
	return	*this;
}

int	Fixed::getRawBits(void) const { return this->_fix; }

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fix = raw;
}

int	Fixed::toInt(void) const
{
	int	num;
	num = this->_fix >> _fr_bits;
	if (num < 0 && (this->_fix & 0xFF) != 0)
		num++;
	return num;
}

float	Fixed::toFloat(void) const
{
	return static_cast <float>(this->_fix) / (1 << _fr_bits);
}

bool	Fixed::operator==(const Fixed& a) const
{
	return this->_fix == a.getRawBits();
}

bool	Fixed::operator!=(const Fixed& a) const
{
	return this->_fix != a.getRawBits();
}

bool	Fixed::operator>(const Fixed& a) const
{
	return this->_fix > a.getRawBits();
}

bool	Fixed::operator<(const Fixed& a) const
{
	return this->_fix < a.getRawBits();
}

bool	Fixed::operator>=(const Fixed& a) const
{
	return this->_fix >= a.getRawBits();
}

bool	Fixed::operator<=(const Fixed& a) const
{
	return this->_fix <= a.getRawBits();
}

Fixed	Fixed::operator+(const Fixed& a) const
{
	long long	res;
	Fixed		sum;

	res = static_cast<long long>(this->_fix) + a.getRawBits();
	if (!_check_limits(res, "Overflow in addition"))
		return sum;
	sum.setRawBits(static_cast<int>(res));
	return sum;
}

Fixed	Fixed::operator-(const Fixed& a) const
{
	long long	res;
	Fixed		subs;

	res = static_cast<long long>(this->_fix) - a.getRawBits();
	if (!_check_limits(res, "Overflow in substraction"))
		return subs;
	subs.setRawBits(static_cast<int>(res));
	return subs;
}

Fixed	Fixed::operator*(const Fixed& a) const
{
	long long	res;
	Fixed		product;

	res = static_cast <long long>(this->_fix) * a.getRawBits();
	res >>= _fr_bits;
	if (!_check_limits(res, "Overflow in multiplication"))
		return product;
	product.setRawBits(static_cast<int>(res));
	return product;
}

Fixed	Fixed::operator/(const Fixed& a) const
{
	long long	res;
	long long	dividend;
	Fixed		quotient;

	dividend = static_cast<long long>(this->_fix) << _fr_bits;
	res = dividend / a.getRawBits();
	if (!_check_limits(res, "Overflow in division"))
		return quotient;
	quotient.setRawBits(static_cast<int>(res));
	return quotient;
}

int	Fixed::_check_limits(const long long& num, const std::string& err_message)
{
	if (num > static_cast<long long>(std::numeric_limits<int>::max())
		|| num < static_cast<long long>(std::numeric_limits<int>::min()))
		{
			std::cerr << "Error" << std::endl << err_message << std::endl;
			return 0;
		}
	return 1;
}

std::ostream&	operator<<(std::ostream& o, Fixed const& value)
{
	o << value.toFloat();
	return o;
}
