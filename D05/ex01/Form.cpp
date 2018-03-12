/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:34:00 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/12 11:42:26 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*********************************************************************
* Constructor GradeTooHighException Default
*********************************************************************/
Form::GradeTooHighException::GradeTooHighException(void) :
	_grade_type("")
{}
/*********************************************************************
* Constructor GradeTooHighException with Type
*********************************************************************/
Form::GradeTooHighException::GradeTooHighException(std::string const & type) :
	_grade_type(type)
{}
/*********************************************************************
* Constructor GradeTooHighException Copy
*********************************************************************/
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
}
/*********************************************************************
* Assignement GradeTooHighException
*********************************************************************/
Form::GradeTooHighException	& Form::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
	Bureaucrat::GradeTooHighException::operator=(rhs);
	this->_grade_type = rhs.getGradType();
	return (*this);
}
/*********************************************************************
* Destructor GradeTooHighException
*********************************************************************/
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}
/*********************************************************************
* What GradeTooHighException
*********************************************************************/
char const				* Form::GradeTooHighException::what() const throw()
{
	std::string		ret;
	
	ret = this->what();
	if (this->getGradeType().length())
		return (ret);
	return (ret + " to " + type);
}


/*********************************************************************
* Constructor GradeTooLowException Default
*********************************************************************/
Form::GradeTooLowException::GradeTooLowException(void) :
	_grade_type("")
{}
/*********************************************************************
* Constructor GradeTooLowException with Type
*********************************************************************/
Form::GradeTooLowException::GradeTooLowException(std::string const & type) :
	_grade_type(type)
{}
/*********************************************************************
* Constructor GradeTooLowException Copy
*********************************************************************/
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
}
/*********************************************************************
* Assignement GradeTooLowException
*********************************************************************/
Form::GradeTooLowException	& Form::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
	Bureaucrat::GradeTooLowException::operator=(rhs);
	this->_grade_type = rhs.getGradType();
	return (*this);
}
/*********************************************************************
* Destructor GradeTooLowException
*********************************************************************/
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}
/*********************************************************************
* What GradeTooLowException
*********************************************************************/
char const				* Form::GradeToolowException::what() const throw()
{
	std::string		ret;
	
	ret = this->what();
	if (this->getGradeType().length())
		return (ret);
	return (ret + " to " + type);
}

/*********************************************************************
* Constructor Form Default
*********************************************************************/
Form::Form(std::string const & name, int grade_to_sign, int grade_to_exe)
	throw (GradeTooHighException, GradeTooLowException):
	_name(name), _is_signed(0)
{
	if (grade_to_sign < 1 || grade_to_exe < 1)
		throw (GradeTooHighException());
	else if (grade_to_sign > 150 || grade_to_exe > 150)
		throw (GradeTooLowException());
	this->_grade_to_sign = grade_to_sign;
	this->_grade_to_exe = grade_to_sign;
}
/*********************************************************************
* Constructor Form Copy
*********************************************************************/
Form::Form(Form const & src)
{
	*this = src;
}
/*********************************************************************
* Assignement Form
*********************************************************************/
Form	& Form::operator=(Form const & rhs)
{
	this->_name = rhs.getName();
	this->_grade_to_sign = rhs.getGradeToSign();
	this->_grade_to_exe = rhs.getGradeToExe();
	return (*this);
}
/*********************************************************************
* Destructor Form
*********************************************************************/
Form::~Form(void) {}
/*********************************************************************
* Getter GradeToSign
*********************************************************************/
int Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}
/*********************************************************************
* Getter GradeToExe
*********************************************************************/
int Form::getGradeToExe(void) const
{
	return (this->_grade_to_exe);
}
/*********************************************************************
* Getter Name
*********************************************************************/
std::string  const & Form::getName(void) const
{
	return (this->_name);
}
/*********************************************************************
* Sign Form by Bureaucrate
*********************************************************************/
bool				beSigned(Bureaucrat const & bureaucrat) throw(GradeTooLowException)
{
	if(this->_is_signed)
	{
		std::cout << *this << " is already signed." << std::endl;
		return (0);
	}
	if (bureaucrat.getGrade() > this->_grade_to_sign)
	{
		throw(GradeTooLowException("sign"));
		return (0);
	}
	this->_is_signed = 1;
	return (1);
}
/*********************************************************************
* overload operator <<
*********************************************************************/
std::ostream  & operator<<(std::ostream & os, Form const & rhs )
{
	os << " Form : " << rhs.getName()
		<< " gradeToSign(" << rhs.getGradeToSign() << (")")
		<< " gradeToExe(" << rhs.getGradeToSign() << (")")
		<< " --> " << rhs.isSigned() ? "" : "Not" << " Signed"
		<< std::endl;
	return (os);
}
