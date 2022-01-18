#include "Fixed.hpp"

Fixed::Fixed( void ){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void ){
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw){
	this->_val = raw;
}
int		Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

Fixed &	Fixed::operator=(Fixed const &fx){
	std::cout << "Assignation operator called" << std::endl;
	this->_val = fx.getRawBits();
	return (*this);
}
