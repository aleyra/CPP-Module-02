#include "Fixed.hpp"

Fixed::Fixed( void ){
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src){
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( int const val){
	// std::cout << "Int constructor called" << std::endl;
	this->_val = (val << Fixed::_frac);
}

Fixed::Fixed( float const val){
	// std::cout << "Float constructor called" << std::endl;
	this->_val = roundf(val * (1 << Fixed::_frac));
}

Fixed::~Fixed( void ){
	// std::cout << "Destructor called" << std::endl;
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
	// std::cout << "Assignation operator called" << std::endl;
	if (this != &fx)
		this->_val = fx.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &fx){
	return (this->getRawBits() > fx.getRawBits());
}

bool	Fixed::operator<(Fixed const &fx){
	return (this->_val < fx.getRawBits());
}

bool	Fixed::operator>=(Fixed const &fx){
	return (this->_val >= fx.getRawBits());
}

bool	Fixed::operator<=(Fixed const &fx){
	return (this->_val <= fx.getRawBits());
}

bool	Fixed::operator==(Fixed const &fx){
	return (this->_val == fx.getRawBits());

}

bool	Fixed::operator!=(Fixed const &fx){
	return (this->_val != fx.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &fx){
	Fixed	res;
	
	res.setRawBits(this->_val + fx.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(Fixed const &fx){
	Fixed	res;

	res.setRawBits(this->_val - fx.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(Fixed const &fx){
	Fixed		res;
	long long	t1;
	long long	t2;

	t1 = (long long)this->_val;
	t2 = (long long)fx.getRawBits();
	res.setRawBits((t1 * t2) / (1 << this->_frac));
	return (res);	
}

Fixed	Fixed::operator/(Fixed const &fx){
	Fixed		res;
	long long	t1;
	long long	t2;

	t1 = (long long)this->_val * (long long)(1 << this->_frac);
	t2 = (long long)fx.getRawBits();
	res.setRawBits(t1 / t2);
	return (res);	
}

Fixed	Fixed::operator++( void ){
	this->_val++;
	return (*this);
}

Fixed	Fixed::operator++(int ){
	Fixed	t(*this);

	this->operator++();
	return(t);
}

Fixed	Fixed::operator--( void ){
	this->_val--;
	return(*this);
}

Fixed	Fixed::operator--(int ){
	Fixed	t(*this);

	this->operator--();
	return(t);
}


Fixed	&Fixed::min(Fixed &fx1, Fixed &fx2){
	if (fx1 < fx2)
		return (fx1);
	return (fx2);
}

Fixed const	&Fixed::min(Fixed const &fx1, Fixed const &fx2){
	if (fx1.getRawBits() < fx2.getRawBits())
		return (fx1);
	return (fx2);
}

Fixed	&Fixed::max(Fixed &fx1, Fixed &fx2){
	if (fx1 > fx2)
		return (fx1);
	return (fx2);
}

Fixed const	&Fixed::max(Fixed const &fx1, Fixed const &fx2){
	if (fx1.getRawBits() > fx2.getRawBits())
		return (fx1);
	return (fx2);
}

std::ostream	&operator<<( std::ostream &o, Fixed const &fx){
	o << fx.toFloat();
	return (o);
}
