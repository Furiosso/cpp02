#include "Fixed.hpp"

const int	Fixed::_fr_bits = 8;

Fixed::Fixed(void) : _fix(0) {}

Fixed::Fixed(const int value) : _fix(value << _fr_bits) {}

Fixed::Fixed(const float value) : _fix(roundf(value * (1 << _fr_bits)))	{}

Fixed::Fixed(Fixed const& src)
{
	this->_fix = src.getRawBits();
}

Fixed::~Fixed(void) {}

Fixed&	Fixed::operator=(Fixed const& rhs)
{
	this->_fix = rhs.getRawBits();
	return	*this;
}

int	Fixed::getRawBits(void) const { return this->_fix; }

void	Fixed::setRawBits(int const raw)
{
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
	if (!_check_limits(res, "addition"))
		return *this;
	sum.setRawBits(static_cast<int>(res));
	return sum;
}

Fixed	Fixed::operator-(const Fixed& a) const
{
	long long	res;
	Fixed		subs;

	res = static_cast<long long>(this->_fix) - a.getRawBits();
	if (!_check_limits(res, "substraction"))
		return *this;
	subs.setRawBits(static_cast<int>(res));
	return subs;
}

Fixed	Fixed::operator*(const Fixed& a) const
{
	long long	res;
	Fixed		product;

	res = static_cast <long long>(this->_fix) * a.getRawBits();
	res >>= _fr_bits;
	if (!_check_limits(res, "multiplication"))
		return *this;
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
	if (!_check_limits(res, "division"))
		return *this;
	quotient.setRawBits(static_cast<int>(res));
	return quotient;
}

Fixed&	Fixed::operator++(void)
{
	long long	res;

	res = (static_cast<long long>(this->_fix) + 1) << _fr_bits;
	if (_check_limits(res, "prefix incrementation"))
		++(this->_fix);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed		obj = *this;
	long long	res;

	res = (static_cast<long long>(this->_fix) + 1) << _fr_bits;
	if (_check_limits(res, "postfix incrementation"))
		++(this->_fix);
	return	obj;
}

Fixed&	Fixed::operator--(void)
{
	long long	res;

	res = (static_cast<long long>(this->_fix) - 1) << _fr_bits;
	if (_check_limits(res, "prefix decrementation"))
		--(this->_fix);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed		obj = *this;
	long long	res;

	res = (static_cast<long long>(this->_fix) - 1);
	if (_check_limits(res, "postfix decrementation"))
		--(this->_fix);
	return	obj;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
	{
		if (a == b)
			std::cout << " Both numbers are equal ";
		return a;
	}
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
	{
		if (a == b)
			std::cout << " Both numbers are equal ";
		return a;
	}
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
	{
		if (a == b)
			std::cout << " Both numbers are equal ";
		return a;
	}
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
	{
		if (a == b)
			std::cout << " Both numbers are equal ";
		return a;
	}
	return b;
}

int	Fixed::_check_limits(const long long& num, const std::string& err_message)
{
	if (num > static_cast<long long>(std::numeric_limits<int>::max())
		|| num < static_cast<long long>(std::numeric_limits<int>::min()))
		{
			std::cerr << " Error: overflow in " << err_message << ". Value unchanged ";
			return 0;
		}
	return 1;
}

std::ostream&	operator<<(std::ostream& o, Fixed const& value)
{
	o << value.toFloat();
	return o;
}
