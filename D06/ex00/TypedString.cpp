/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypedString.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:05:10 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/14 13:49:00 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypedString.hpp"

/*********************************************************************
* Constructor Default TypedString::NoConversionException
*********************************************************************/
TypedString::NoConversionException::NoConversionException(void) {}
/*********************************************************************
* Constructor Copy TypedString::NoConversionException
*********************************************************************/
TypedString::NoConversionException::NoConversionException(TypedString const & src) {
	*this = src;
}
/*********************************************************************
* Destructor TypedString::NoConversionException
*********************************************************************/
TypedString::NoConversionException::~NoConversionException(void) throw() {}
/*********************************************************************
* Assignator TypedString::NoConversionExceptionTypedString::NoConversionException
*********************************************************************/
TypedString::NoConversionException & TypedString::NoConversionException::operator=(TypedString::NoConversionException const & rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}
/*********************************************************************
* What
*********************************************************************/
const char  * TypedString::NoConversionException::what(void) const throw() 
{
	return ("impossible");
}
/*********************************************************************
* Constructor Default TypedString::NonDisplayableException
*********************************************************************/
TypedString::NonDisplayableException::NonDisplayableException(void) {}
/*********************************************************************
* Constructor Copy TypedString::NonDisplayableException
*********************************************************************/
TypedString::NonDisplayableException::NonDisplayableException(TypedString const & src) {
	*this = src;
}
/*********************************************************************
* Destructor TypedString::NonDisplayableException
*********************************************************************/
TypedString::NonDisplayableException::~NonDisplayableException(void) throw() {}
/*********************************************************************
* Assignator TypedString::NonDisplayableExceptionTypedString::NonDisplayableException
*********************************************************************/
TypedString::NonDisplayableException & TypedString::NonDisplayableException::operator=(TypedString::NonDisplayableException const & rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}
/*********************************************************************
* What
*********************************************************************/
char const * TypedString::NonDisplayableException::what(void) const throw() 
{
	return ("Non displayable");
}


/*********************************************************************
* Constructor Default TypedString
*********************************************************************/
TypedString::TypedString(std::string const & str)
{
	this->_data = str;
	this->_precision = 1;
	this->_impossible = 0;
	
	size_t	l = this->_data.length();
	
	if (l == 3
		&& this->_data[0] == '\'' && this->_data[2] == '\'')
		this->_double = static_cast<double>(this->_data[1]);
	else
	{
		this->_double = std::atof(this->_data.c_str());
		
		size_t	p = this->_data.find(".");
		
		if (p != std::string::npos)
		{
			if (this->_data.find(".", p + 1) != std::string::npos)
				this->_impossible = 1;
			else if (this->_data[p + 1] != '\0')
			{
				if (this->_data.find("f") != std::string::npos)
					++p;
				this->_precision = l - p - 1;
			}
		}
	}
}
/*********************************************************************
* Constructor Copy TypedString
*********************************************************************/
TypedString::TypedString(TypedString const & src)
{
	*this = src;
}
/*********************************************************************
* Destructor TypedString
*********************************************************************/
TypedString::~TypedString(void)
{	
}
/*********************************************************************
* Assignator TypedString
*********************************************************************/
TypedString & TypedString::operator=(TypedString const & rhs)
{
	this->_data = rhs.getData();
	this->_double = rhs.getDouble();
	this->_precision = rhs.getPrecision();
	this->_impossible = rhs.getImpossible();
	return (*this);
}
/*********************************************************************
* Getter Data
*********************************************************************/
std::string const	& TypedString::getData(void) const
{
	return (this->_data);
}
/*********************************************************************
* Getter Double
*********************************************************************/
double				TypedString::getDouble(void) const
{
	return (this->_double);
}
/*********************************************************************
* Getter Precision
*********************************************************************/
int					TypedString::getPrecision(void) const
{
	return (this->_precision);
}
/*********************************************************************
* Getter Precision
*********************************************************************/
bool				TypedString::getImpossible(void) const
{
	return (this->_impossible);
}
/*********************************************************************
* Cast to char
*********************************************************************/
TypedString::operator char(void) const throw(NoConversionException, NonDisplayableException)
{
	
	if (this->_impossible)
		throw (NoConversionException());
	else if (isinf(this->_double) || isnan(this->_double))
		throw NoConversionException();
	else if (this->_double > static_cast<double>(std::numeric_limits<char>::max())
				|| this->_double < static_cast<double>(std::numeric_limits<char>::min()))
		throw NoConversionException();
	else if (std::isprint(static_cast<unsigned char>(this->_double)) == 0)
		throw NonDisplayableException();
	return (static_cast<char>(this->_double));
}
/*********************************************************************
* Cast to int
*********************************************************************/
TypedString::operator int(void) const throw(NoConversionException)
{
	if (this->_impossible)
		throw (NoConversionException());
	else if (isinf(this->_double) || isnan(this->_double))
		throw (NoConversionException());
	else if (this->_double > static_cast<double>(std::numeric_limits<int>::max())
				|| this->_double < static_cast<double>(std::numeric_limits<int>::min()))
		throw (NoConversionException());
	return (static_cast<int>(this->_double));
}
/*********************************************************************
* Cast to float
*********************************************************************/
TypedString::operator float(void) const throw(NoConversionException)
{
	if (this->_impossible)
		throw (NoConversionException());
	return (static_cast<float>(this->_double));
}
/*********************************************************************
* Cast to float
*********************************************************************/
TypedString::operator double(void) const throw(NoConversionException)
{
	if (this->_impossible)
		throw (NoConversionException());
	return (this->_double);
}
/*********************************************************************
* Cast to TypedString
*********************************************************************/
TypedString::operator std::string const &(void) const
{
	return (this->_data);
}
/*********************************************************************
* Display
*********************************************************************/
std::ostream	& operator<<(std::ostream & os, TypedString const & str)
{
	os << "char : ";
	try
	{
		os << static_cast<char>(str);
	}
	catch(TypedString::NoConversionException & e)
	{
		os << e.what();
	}
	catch(TypedString::NonDisplayableException & e)
	{
		os << e.what();
	}
	os << std::endl;
	os << "int : ";
	try
	{
		os << static_cast<int>(str);
	}
	catch(TypedString::NoConversionException & e)
	{
		os << e.what();
	}
	os << std::endl;
	os << "float : ";
	try
	{
		os << static_cast<float>(str) << "f";
	}
	catch(TypedString::NoConversionException & e)
	{
		os << e.what();
	}
	os << std::endl;
	os << "double : ";
	try
	{
		os << static_cast<double>(str);
	}
	catch(TypedString::NoConversionException & e)
	{
		os << e.what();
	}
	os << std::endl;
	return (os);
}
