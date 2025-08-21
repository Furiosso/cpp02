#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <limits>
# include <cmath>
# include <string>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const & src);
		~Fixed(void);
		Fixed&				operator=(Fixed const & rhs);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;
		bool				operator!=(const Fixed& a) const;
		bool				operator==(const Fixed& a) const;
		bool				operator>(const Fixed& a) const;
		bool				operator<(const Fixed& a) const;
		bool				operator>=(const Fixed& a) const;
		bool				operator<=(const Fixed& a) const;
		Fixed				operator+(const Fixed& a) const;
		Fixed				operator-(const Fixed& a) const;
		Fixed				operator*(const Fixed& a) const;
		Fixed				operator/(const Fixed& a) const;
		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
	private:
		int					_fix;
		static const int	_fr_bits;
		static int			_check_limits(const long long& num, const std::string& err_message);
};

std::ostream&	operator<<(std::ostream& o, Fixed const& value);

#endif