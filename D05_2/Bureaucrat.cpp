/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:44:42 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/01 23:55:41 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int const Bureaucrat::lowest = 150;
int const Bureaucrat::highest = 1;

/*********************************************************************
* Constructor Bureaucrat Default
*********************************************************************/
Bureaucrat::Bureaucrat(void): _name(""), _grade(Bureaucrat::lowest) {}
/*********************************************************************
* Constructor Bureaucrat Copy
*********************************************************************/
Bureaucrat::Bureaucrat(Bureaucrat const & src) { *this = src; }
/*********************************************************************
* Constructor Bureaucrat By Name & Grade
*********************************************************************/
Bureaucrat::Bureaucrat(std::string const & name, int grade)
  throw(GradeTooHighException, GradeTooLowException):
  _name(name)
{
  if (grade < highest)
    throw(Bureaucrat::GradeTooHighException());
  if (grade > lowest)
    throw(Bureaucrat::GradeTooLowException());
  _grade = grade;
}
/*********************************************************************
* Destrucctor Bureaucrat
*********************************************************************/
Bureaucrat::~Bureaucrat(void) {}
/*********************************************************************
* Assignation Bureaucrat
*********************************************************************/
Bureaucrat            & Bureaucrat::operator=(Bureaucrat const & rhs)
{
  _name = rhs.getName();
  _grade = rhs.getGrade();
	return *this;
}
/*********************************************************************
* Getter Name
*********************************************************************/
std::string const   & Bureaucrat::getName(void) const
{
  return _name;
}
/*********************************************************************
* Getter Grade
*********************************************************************/
int                 Bureaucrat::getGrade(void) const
{
  return _grade;
}
/*********************************************************************
* Increment
*********************************************************************/
void                  Bureaucrat::incrementGrade(void)
                        throw(GradeTooHighException)
{
  if (_grade < highest + 1)
    throw(Bureaucrat::GradeTooHighException());
  _grade--;
}
/*********************************************************************
* Decrement
*********************************************************************/
void                  Bureaucrat::decrementGrade(void)
                        throw(GradeTooLowException)
{
  if (_grade > lowest - 1)
    throw(Bureaucrat::GradeTooLowException());
  _grade++;
}
/*********************************************************************
* Overload <<
*********************************************************************/
std::ostream                   &operator<<(std::ostream & os, Bureaucrat const & rhs)
{
  os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();

  return os;
}



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
* Destrucctor GradeTooHighException
*********************************************************************/
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}
/*********************************************************************
* Assignation GradeTooHighException
*********************************************************************/
Bureaucrat::GradeTooHighException
    & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
  std::exception::operator=(rhs);
	return (*this);
}
/*********************************************************************
* What
*********************************************************************/
char const            * Bureaucrat::GradeTooHighException::what(void) const throw()
{
  return "Grade too high.";
}

/*********************************************************************
* Constructor GradeTooLowException Default
*********************************************************************/
Bureaucrat::GradeTooLowException::GradeTooLowException(void){}
/*********************************************************************
* Constructor GradeTooLowException Copy
*********************************************************************/
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
  *this = src;
}
/*********************************************************************
* Destrucctor GradeTooLowException
*********************************************************************/
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}
/*********************************************************************
* Assignation GradeTooLowException
*********************************************************************/
Bureaucrat::GradeTooLowException
    & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
  std::exception::operator=(rhs);
	return (*this);
}
/*********************************************************************
* What
*********************************************************************/
char const				* Bureaucrat::GradeTooLowException::what(void) const throw()
{
  return "Grade too low.";
}