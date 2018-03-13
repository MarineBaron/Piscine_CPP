/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:34:00 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/13 13:33:45 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

//std::string const ShrubberyCreationForm::_tree = std::endl + "                                               |" + std::endl;
// 

/*********************************************************************
* Constructor ShrubberyCreationForm Default
*********************************************************************/
ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	throw (GradeTooHighException, GradeTooLowException):
	Form("Shrubbery Creation Form", 145, 137), _target(target)
{
}
/*********************************************************************
* Constructor ShrubberyCreationForm Copy
*********************************************************************/
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):
	Form("Shrubbery Creation Form", 145, 137)
{
	*this = src;
}
/*********************************************************************
* Assignement ShrubberyCreationForm
*********************************************************************/
ShrubberyCreationForm	& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	Form::operator=(rhs);
	this->_target = rhs.getTarget();
	return (*this);
}
/*********************************************************************
* Destructor ShrubberyCreationForm
*********************************************************************/
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
/*********************************************************************
* Getter Target
*********************************************************************/
std::string  const & ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}
/*********************************************************************
* execute (only exceptions)
*********************************************************************/
void		ShrubberyCreationForm::action(void) const
{
	std::ofstream	file;
	
	file.open(this->_target + "_shrubbery");
	if (file.is_open())
	{
	
		file 	<< "      '.," << std::endl
				<< "        'b      *" << std::endl
				<< "         '$    #." << std::endl
				<< "          $:   #:" << std::endl
				<< "          *#  @):" << std::endl
				<< "          :@,@):   ,.**:'" << std::endl
				<< ",         :@@*: ..**'" << std::endl
				<< " '#o.    .:(@'.@*\"'" << std::endl
				<< "    'bq,..:,@@*'" << std::endl
				<< "    ,p$q8,:@)'  .p*'" << std::endl
				<< "   '    '@@Pp@@*'" << std::endl
				<< "         Y7'.'" << std::endl
				<< "       :@):." << std::endl
				<< "      .:@:'." << std::endl
				<< "    .::(@:.      -Sam Blumenstein-" << std::endl;
		file.close();
	}	
}
