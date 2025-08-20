#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const & src);
		~Fixed(void);
		Fixed& 	operator=(Fixed const & rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
	private:
		int					_fix;
		static const int	_fr_bits;
};

std::ostream&	operator<<(std::ostream& o, Fixed const& value);

#endif