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

	bool	operator>(Fixed const &fx);
	bool	operator<(Fixed const &fx);
	bool	operator>=(Fixed const &fx);
	bool	operator<=(Fixed const &fx);
	bool	operator==(Fixed const &fx);
	bool	operator!=(Fixed const &fx);

	Fixed	operator+(Fixed const &fx);
	Fixed	operator-(Fixed const &fx);
	Fixed	operator*(Fixed const &fx);
	Fixed	operator/(Fixed const &fx);

	Fixed	operator++( void );
	Fixed	operator++(int );
	Fixed	operator--( void );
	Fixed	operator--(int );

	static Fixed	&min(Fixed &fx1, Fixed &fx2);
	static Fixed	&min(Fixed const fx1, Fixed const &fx2);
	static Fixed	&max(Fixed &fx1, Fixed &fx2);
	static Fixed	&max(Fixed const fx1, Fixed const fx2);

private:

	int					_val;
	static int const	_frac = 8;
};

std::ostream	&operator<<( std::ostream &o, Fixed const &fx);

#endif