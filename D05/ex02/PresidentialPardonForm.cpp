/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:34:00 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/13 11:48:11 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

/*********************************************************************
* Constructor PresidentialPardonForm Default
*********************************************************************/
PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	throw (GradeTooHighException, GradeTooLowException):
	Form("Presidential Pardon Form", 25, 5), _target(target)
{
}
/*********************************************************************
* Constructor PresidentialPardonForm Copy
*********************************************************************/
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):
	Form("Presidential Pardon Form", 25, 5)
{
	*this = src;
}
/*********************************************************************
* Assignement PresidentialPardonForm
*********************************************************************/
PresidentialPardonForm	& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	Form::operator=(rhs);
	this->_target = rhs.getTarget();
	return (*this);
}
/*********************************************************************
* Destructor PresidentialPardonForm
*********************************************************************/
PresidentialPardonForm::~PresidentialPardonForm(void) {}
/*********************************************************************
* Getter Target
*********************************************************************/
std::string  const & PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}
/*********************************************************************
* execute (only exceptions)
*********************************************************************/
void		PresidentialPardonForm::action(void) const
{
	std::cout << this->_target << " has been pardonned by Zafod Beeblebrox."
	 	<< std::endl;
}
