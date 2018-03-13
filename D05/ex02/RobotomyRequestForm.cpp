/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:34:00 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/13 12:12:22 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

/*********************************************************************
* Constructor RobotomyRequestForm Default
*********************************************************************/
RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	throw (GradeTooHighException, GradeTooLowException):
	Form("Robotomy Request Form", 72, 45), _target(target)
{
	std::srand(std::time(nullptr));
}
/*********************************************************************
* Constructor RobotomyRequestForm Copy
*********************************************************************/
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):
	Form("Robotomy Request Form", 72, 45)
{
	*this = src;
}
/*********************************************************************
* Assignement RobotomyRequestForm
*********************************************************************/
RobotomyRequestForm	& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	Form::operator=(rhs);
	this->_target = rhs.getTarget();
	return (*this);
}
/*********************************************************************
* Destructor RobotomyRequestForm
*********************************************************************/
RobotomyRequestForm::~RobotomyRequestForm(void) {}
/*********************************************************************
* Getter Target
*********************************************************************/
std::string  const & RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}
/*********************************************************************
* execute (only exceptions)
*********************************************************************/
void		RobotomyRequestForm::action(void) const
{
	int random = std::rand();
	
	std::cout << "*Driiiing Driiiing Driiiing Driiiing*"
		<< std::endl;
	if (random < RAND_MAX / 2)
		std::cout << this->_target << " has been robotomized sucessfully."
	 		<< std::endl;
	else
		std::cout << this->_target << " hasn't been robotomized !!! It's a failure !"
	 		<< std::endl;
}
