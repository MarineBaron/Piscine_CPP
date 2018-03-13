/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:34:00 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/13 11:45:22 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*********************************************************************
* Constructor GradeTooHighException Default
*********************************************************************/
Form::GradeTooHighException::GradeTooHighException(void) {}

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
	std::exception::operator=(rhs);
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
	return ("Grade too high.");
}


/*********************************************************************
* Constructor GradeTooLowException Default
*********************************************************************/
Form::GradeTooLowException::GradeTooLowException(void) {}
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
	std::exception::operator=(rhs);
	return (*this);
}
/*********************************************************************
* Destructor GradeTooLowException
*********************************************************************/
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}
/*********************************************************************
* What GradeTooLowException
*********************************************************************/
char const				* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

/*********************************************************************
* Constructor FormNotSignedException Default
*********************************************************************/
Form::FormNotSignedException::FormNotSignedException(void) {}
/*********************************************************************
* Constructor FormNotSignedException Copy
*********************************************************************/
Form::FormNotSignedException::FormNotSignedException(FormNotSignedException const & src)
{
	*this = src;
}
/*********************************************************************
* Assignement FormNotSignedException
*********************************************************************/
Form::FormNotSignedException	& Form::FormNotSignedException::operator=(FormNotSignedException const & rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}
/*********************************************************************
* Destructor FormNotSignedException
*********************************************************************/
Form::FormNotSignedException::~FormNotSignedException(void) throw() {}
/*********************************************************************
* What FormNotSignedException
*********************************************************************/
char const				* Form::FormNotSignedException::what() const throw()
{
	return ("Form not signed.");
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
* Getter isSigned
*********************************************************************/
bool		Form::isSigned(void) const
{
	return (this->_is_signed);
}
/*********************************************************************
* Sign Form by Bureaucrate
*********************************************************************/
void		Form::beSigned(Bureaucrat const & bureaucrat) throw(GradeTooLowException)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
	{
		throw(GradeTooLowException());
	}
	this->_is_signed = 1;
}
/*********************************************************************
* execute (only exceptions)
*********************************************************************/
void		Form::execute(Bureaucrat const & bureaucrat) throw(FormNotSignedException, GradeTooLowException)
{
	if (!this->_is_signed)
	{
		throw(FormNotSignedException());
	}
	if (bureaucrat.getGrade() > this->_grade_to_exe)
	{
		throw(GradeTooLowException());
	}
	this->action();
}
/*********************************************************************
* overload operator <<
*********************************************************************/
std::ostream  & operator<<(std::ostream & os, Form const & rhs )
{
	os << " Form : " << rhs.getName()
		<< " gradeToSign(" << rhs.getGradeToSign() << (")")
		<< " gradeToExe(" << rhs.getGradeToSign() << (")")
		<< " --> " << (rhs.isSigned() ? "" : "Not") << " Signed"
		<< std::endl;
	return (os);
}
