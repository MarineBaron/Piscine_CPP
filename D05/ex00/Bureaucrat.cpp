/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:34:00 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/12 10:44:57 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*********************************************************************
* Constructor GradeTooHighException Default
*********************************************************************/
Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
/*********************************************************************
* Constructor GradeTooHighException Copy
*********************************************************************/
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
}
/*********************************************************************
* Assignement GradeTooHighException
*********************************************************************/
Bureaucrat::GradeTooHighException	& Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}
/*********************************************************************
* Destructor GradeTooHighException
*********************************************************************/
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}
/*********************************************************************
* What GradeTooHighException
*********************************************************************/
char const				* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}




/*********************************************************************
* Constructor GradeTooLowException Default
*********************************************************************/
Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
/*********************************************************************
* Constructor GradeTooLowException Copy
*********************************************************************/
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
}
/*********************************************************************
* Assignement GradeTooLowException
*********************************************************************/
Bureaucrat::GradeTooLowException	& Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}
/*********************************************************************
* Destructor GradeTooLowException
*********************************************************************/
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}
/*********************************************************************
* What GradeTooLowException
*********************************************************************/
char const				* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}





/*********************************************************************
* Constructor Bureaucrat Default
*********************************************************************/
Bureaucrat::Bureaucrat(std::string const & name, int grade)
	throw(GradeTooHighException, GradeTooLowException) :
	_name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}
/*********************************************************************
* Constructor Bureaucrat Copy
*********************************************************************/
Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}
/*********************************************************************
* Assignement Bureaucrat
*********************************************************************/
Bureaucrat	& Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();
	return (*this);
}
/*********************************************************************
* Destructor Bureaucrat
*********************************************************************/
Bureaucrat::~Bureaucrat(void) {}
/*********************************************************************
* incrementGrade
*********************************************************************/
void Bureaucrat::incrementGrade(void)
	throw(GradeTooLowException)
{
	if (this->_grade > 149)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
	this->_grade++;
}
/*********************************************************************
* decrementGrade
*********************************************************************/
void Bureaucrat::decrementGrade(void)
	throw(GradeTooHighException)
{
	if (this->_grade < 2)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
	this->_grade--;
}
/*********************************************************************
* Getter Grade
*********************************************************************/
int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}
/*********************************************************************
* Getter Name
*********************************************************************/
std::string  const & Bureaucrat::getName(void) const
{
	return (this->_name);
}
/*********************************************************************
* overload operator <<
*********************************************************************/
std::ostream  & operator<<(std::ostream & os, Bureaucrat const & rhs )
{
	os << " Bureaucrate : " << rhs.getName() << " ->Grade : " << rhs.getGrade()
		<< std::endl;
	return (os);
}
