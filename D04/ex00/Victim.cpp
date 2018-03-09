/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:26:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 11:37:46 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

/*********************************************************************
* Constructeur (name, type)
*********************************************************************/
Victim::Victim(std::string const name) : 
	_name(name)
{
	std::cout << "Some random victim called " << this->_name
		<< " just poppep !" << std::endl;
}
/*********************************************************************
* Constructeur (Copy)
*********************************************************************/
Victim::Victim(Victim const & src)
{
	*this = src;
	std::cout << "Some random victim called " << this->_name
		<< " just poppep !" << std::endl;
}
/*********************************************************************
* Assignation
*********************************************************************/
Victim 		&Victim::operator=(Victim const & rhs)
{
	if(this != &rhs)
	{
		this->_name = rhs.getName();
	}
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
Victim::~Victim(void)
{
	std::cout << "Victim named " << this->_name
		<< " just died for no apparent reason !" << std::endl;
}
/*********************************************************************
* Getter _name
*********************************************************************/
std::string const & Victim::getName(void) const
{
	return (this->_name);
}
/*********************************************************************
* getPolymorphed
*********************************************************************/
 void				Victim::getPolymorphed(void) const
 {
	 std::cout << this->_name
		 << " has been turned into a cute little sheep !" << std::endl;
 }
/*********************************************************************
* overload>>
*********************************************************************/
std::ostream	&operator<<(std::ostream &os, Victim const & rhs)
{
	os << "I'm " << rhs.getName()
		<< ", and I like otters !" << std::endl;
	return (os);
}
