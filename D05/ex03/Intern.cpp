/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:34:00 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/13 14:35:20 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*********************************************************************
* Constructor Intern Default
*********************************************************************/
Intern::Intern(void) {}
/*********************************************************************
* Constructor Intern Copy
*********************************************************************/
Intern::Intern(Intern const & src)
{
	*this = src;
}
/*********************************************************************
* Assignement Intern
*********************************************************************/
Intern	& Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}
/*********************************************************************
* Destructor Intern
*********************************************************************/
Intern::~Intern(void) {}

/*********************************************************************
* makeForm
*********************************************************************/
Form	* Intern::makeForm(std::string const & name, std::string const & target) const
{
	Form *form = nullptr;
	
	try {
		form = Form::getForm(name, target);
		std::cout << " Interne creates " << form->getName()
			<< std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return form;
}