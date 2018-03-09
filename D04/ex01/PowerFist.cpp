/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:26:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 16:18:38 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

/*********************************************************************
* Constructeur (name, type)
*********************************************************************/
PowerFist::PowerFist(void) : 
	AWeapon("power Fist", 8, 50)
{
	std::cout << "PowerFist created : "
		<< this->getName() << ", " << this->getAPCost() << ", " << this->getDamage()
		<< std::endl;
}
/*********************************************************************
* Constructeur (Copy)
*********************************************************************/
PowerFist::PowerFist(PowerFist const & src) :
	AWeapon("", 0, 0)
{
	*this = src;
	std::cout << "PowerFist created : "
		<< this->getName() << ", " << this->getAPCost() << ", " << this->getDamage()
		<< std::endl;
}
/*********************************************************************
* Assignation
*********************************************************************/
PowerFist 		&PowerFist::operator=(PowerFist const & rhs)
{
	if(this != &rhs)
	{
		AWeapon::operator=(rhs);
	}
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
PowerFist::~PowerFist(void)
{
	std::cout << "PowerFist destructed : "
		<< this->getName() << ", " << this->getAPCost() << ", " << this->getDamage()
		<< std::endl;
}
/*********************************************************************
* attacks
*********************************************************************/
void			PowerFist::attacks(void) const
{
	std::cout << "*pshhh... SBAM!*" << std::endl;
}
