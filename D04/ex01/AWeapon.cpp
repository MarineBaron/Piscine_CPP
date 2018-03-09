/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:26:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 14:35:32 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

/*********************************************************************
* Constructeur (name, type)
*********************************************************************/
AWeapon::AWeapon(std::string const & name, int apcost, int damage) : 
	_name(name), _apcost(apcost), _damage(damage)
{
	std::cout << "AWeapon created : "
		<< this->_name << ", " << this->_apcost << ", " << this->_damage
		<< std::endl;
}
/*********************************************************************
* Constructeur (Copy)
*********************************************************************/
AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
	std::cout << "AWeapon created : "
		<< this->_name << ", " << this->_apcost << ", " << this->_damage
		<< std::endl;
}
/*********************************************************************
* Assignation
*********************************************************************/
AWeapon 		&AWeapon::operator=(AWeapon const & rhs)
{
	if(this != &rhs)
	{
		this->_name = rhs.getName();
		this->_apcost = rhs.getAPCost();
		this->_damage = rhs.getDamage();
	}
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
AWeapon::~AWeapon(void)
{
	std::cout << "AWeapon destructed : "
		<< this->_name << ", " << this->_apcost << ", " << this->_damage
		<< std::endl;
}
/*********************************************************************
* Getter _name
*********************************************************************/
std::string const &AWeapon::getName(void) const
{
	return (this->_name);
}
/*********************************************************************
* Getter _apcost
*********************************************************************/
int AWeapon::getAPCost(void) const
{
	return (this->_apcost);
}
/*********************************************************************
* Getter _damage
*********************************************************************/
int AWeapon::getDamage(void) const
{
	return (this->_damage);
}
