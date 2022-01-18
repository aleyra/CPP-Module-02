#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed{

public:
	Fixed( void );
	Fixed( Fixed const &src);
	~Fixed( void );

	void	setRawBits(int const raw);
	int		getRawBits(void) const;

	Fixed	&operator=(Fixed const &fx);

private:

	int					_val;
	static int const	_frac = 8;
};

#endif