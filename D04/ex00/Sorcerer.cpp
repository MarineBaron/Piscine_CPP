/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:26:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 11:37:12 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"


/*********************************************************************
* Constructeur (name, type)
*********************************************************************/
Sorcerer::Sorcerer(std::string const name, std::string const title) : 
	_name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title 
		<< " is born !" << std::endl;
}
/*********************************************************************
* Constructeur (Copy)
*********************************************************************/
Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
	std::cout << this->_name << ", " << this->_title 
		<< " is born !" << std::endl;
}
/*********************************************************************
* Assignation
*********************************************************************/
Sorcerer 		&Sorcerer::operator=(Sorcerer const & rhs)
{
	if(this != &rhs)
	{
		this->_name = rhs.getName();
		this->_title = rhs.getTitle();
	}
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << " is dead !"
			<< " Consequences will never be the same !" << std::endl;
}
/*********************************************************************
* Getter _name
*********************************************************************/
std::string const & Sorcerer::getName(void) const
{
	return (this->_name);
}
/*********************************************************************
* Getter _title
*********************************************************************/
std::string const & Sorcerer::getTitle(void) const
{
	return (this->_title);
}
/*********************************************************************
* polymorph Victim
*********************************************************************/
void				Sorcerer::polymorph(Victim const & victim) const
{
	victim.getPolymorphed();
}
/*********************************************************************
* overload>>
*********************************************************************/
std::ostream	&operator<<(std::ostream &os, Sorcerer const & rhs)
{
	os << "I am " << rhs.getName() << ", " << rhs.getTitle()
		<< ", and I like ponies !" << std::endl;
	return (os);
}
