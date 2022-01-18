#include "Fixed.hpp"

Fixed::Fixed( void ){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( int const val){
	std::cout << "Int constructor called" << std::endl;
	this->_val = (val << Fixed::_frac);
}

Fixed::Fixed( float const val){
	std::cout << "Float constructor called" << std::endl;
	this->_val = roundf(val * (1 << Fixed::_frac));
}

Fixed::~Fixed( void ){
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw){
	this->_val = raw;
}
int	Fixed::getRawBits(void) const{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

float	Fixed::toFloat(void) const{
	float	ret;
	

	ret = (float)this->_val / (float)(1 << Fixed::_frac);
	return (ret);
}

int	Fixed::toInt(void) const{
	return (this->_val >> Fixed::_frac);
}

Fixed &	Fixed::operator=(Fixed const &fx){
	std::cout << "Assignation operator called" << std::endl;
		this->_val = fx.getRawBits();
	return (*this);
}

std::ostream	&operator<<( std::ostream &o, Fixed const &fx){
	o << fx.toFloat();
	return (o);
}
