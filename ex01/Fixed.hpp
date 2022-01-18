#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed{

public:
	Fixed( void );
	Fixed( Fixed const &src );
	Fixed( int const val );
	Fixed( float const val );
	~Fixed( void );

	void	setRawBits(int const raw);
	int		getRawBits(void) const;
	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed	&operator=(Fixed const &fx);

private:

	int					_val;
	static int const	_frac = 8;
};

std::ostream	&operator<<( std::ostream &o, Fixed const &fx);

#endif