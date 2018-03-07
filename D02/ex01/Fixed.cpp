#include "Fixed.hpp"

/*********************************************************************
* Constructor : Default
*********************************************************************/
Fixed::Fixed(void)
{
	std::cout << "Fixed Constructor (Default) called." << std::endl;
	
	this->_raw = 0;
}
/*********************************************************************
* Constructor : Copy
*********************************************************************/
Fixed::Fixed(Fixed const & src)
{
	std::cout << "Fixed Constructor (copy) called." << std::endl;
	std::cout << src.getRawBits() << " is copied." << std::endl;
	
	this->_raw = src.getRawBits();
}
/*********************************************************************
* Constructor : From int
*********************************************************************/
Fixed::Fixed(int const raw)
{
	std::cout << "Fixed Constructor (from int) called." << std::endl;
	std::cout << raw << " is copied." << std::endl;
	
	this->_raw = raw << Fixed::_nFixed;
}
/*********************************************************************
* Constructor : From float
*********************************************************************/
Fixed::Fixed(float const raw)
{
	std::cout << "Fixed Constructor (from float) called." << std::endl;
	std::cout << raw << " is copied." << std::endl;
	
	this->_raw = (int)roundf(raw * (1 << Fixed::_nFixed));
}
/*********************************************************************
* Destructor
*********************************************************************/
Fixed::~Fixed(void)
{
	std::cout << "Fixed Destructor called." << std::endl;
}
/*********************************************************************
* Assignation operator
*********************************************************************/
Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Fixed assignation called." << std::endl;
	std::cout << rhs.getRawBits()  << " is assigned to " ;
	std::cout << this->_raw  << "." << std::endl;
	
	this->_raw = rhs.getRawBits();
	return (*this);
}
/*********************************************************************
* Setter
*********************************************************************/
void Fixed::setRawBits(int const raw)
{
	std::cout << "Fixed member setRawBits called." << std::endl;
	this->_raw = raw;
}
/*********************************************************************
* Getter
*********************************************************************/
int Fixed::getRawBits(void) const
{
	std::cout << "Fixed member getRawBits called." << std::endl;
	return (this->_raw);
}
/*********************************************************************
* toInt
*********************************************************************/
int Fixed::toInt(void) const
{
	return (this->_raw >> Fixed::_nFixed);
}
/*********************************************************************
* tofloat
*********************************************************************/
float Fixed::toFloat(void) const
{
	return ((float)this->_raw / (1 << Fixed::_nFixed));
}
/*********************************************************************
* overload <<
*********************************************************************/
std::ostream & operator<<(std::ostream & os, Fixed const & rhs)
{
	os << rhs.toFloat();
	return (os);
}
