/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:26:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 16:18:55 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

/*********************************************************************
* Constructeur (name, type)
*********************************************************************/
PlasmaRifle::PlasmaRifle(void) : 
	AWeapon("Plasma Rifle", 5, 21)
{
	std::cout << "PlasmaRifle created : "
		<< this->getName() << ", " << this->getAPCost() << ", " << this->getDamage()
		<< std::endl;
}
/*********************************************************************
* Constructeur (Copy)
*********************************************************************/
PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) :
	AWeapon("", 0, 0)
{
	*this = src;
	std::cout << "PlasmaRifle created : "
		<< this->getName() << ", " << this->getAPCost() << ", " << this->getDamage()
		<< std::endl;
}
/*********************************************************************
* Assignation
*********************************************************************/
PlasmaRifle 		&PlasmaRifle::operator=(PlasmaRifle const & rhs)
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
PlasmaRifle::~PlasmaRifle(void)
{
	std::cout << "PlasmaRifle destructed : "
		<< this->getName() << ", " << this->getAPCost() << ", " << this->getDamage()
		<< std::endl;
}
/*********************************************************************
* attacks
*********************************************************************/
void			PlasmaRifle::attacks(void) const
{
	std::cout << "*piouuu piouuu piouuu*" << std::endl;
}
