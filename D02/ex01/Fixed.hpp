#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const raw);
		Fixed(float const raw);
		~Fixed(void);
		
		Fixed 				& operator=(Fixed const & rhs);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;
	private:
		int					_raw;
		static int const	_nFixed = 8;
};

std::ostream	& operator<<(std::ostream & os, Fixed const & rhs);
#endif
