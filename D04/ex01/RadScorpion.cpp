/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:26:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 16:06:30 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

/*********************************************************************
* Constructeur (name, type)
*********************************************************************/
RadScorpion::RadScorpion(void) : 
	Enemy(80, "RadScorpion")
{
	std::cout << "*click click click*"
		<< std::endl;
}
/*********************************************************************
* Constructeur (Copy)
*********************************************************************/
RadScorpion::RadScorpion(RadScorpion const & src) :
	Enemy(80, "RadScorpion")
{
	*this = src;
	std::cout << "*click click click*"
		<< std::endl;
}
/*********************************************************************
* Assignation
*********************************************************************/
RadScorpion 		&RadScorpion::operator=(RadScorpion const & rhs)
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
RadScorpion::~RadScorpion(void)
{
	std::cout << "*SPROTCH*"
		<< std::endl;
}
/*********************************************************************
* takeDamage
*********************************************************************/
void		RadScorpion::takeDamage(int hp) {
		Enemy::takeDamage(hp);
}
