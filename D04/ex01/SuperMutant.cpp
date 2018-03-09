/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:26:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 12:47:54 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

/*********************************************************************
* Constructeur (name, type)
*********************************************************************/
SuperMutant::SuperMutant(void) : 
	Enemy(170, "SuperMutant")
{
	std::cout << "Gaah. Me want smash heads!"
		<< std::endl;
}
/*********************************************************************
* Constructeur (Copy)
*********************************************************************/
SuperMutant::SuperMutant(SuperMutant const & src) :
	Enemy(170, "SuperMutant")
{
	*this = src;
	std::cout << "Gaah. Me want smash heads!"
		<< std::endl;
}
/*********************************************************************
* Assignation
*********************************************************************/
SuperMutant 		&SuperMutant::operator=(SuperMutant const & rhs)
{
	if(this != &rhs)
	{
		Enemy::operator=(rhs);
	}
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh..."
		<< std::endl;
}
/*********************************************************************
* takeDamage
*********************************************************************/
void		SuperMutant::takeDamage(int hp) {
		Enemy::takeDamage(hp - 3);
}
