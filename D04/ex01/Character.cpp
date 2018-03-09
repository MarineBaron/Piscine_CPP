/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:26:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 16:16:59 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*********************************************************************
* Constructeur (name, type)
*********************************************************************/
Character::Character(std::string const & name) : 
	_name(name), _ap(40), _equip(nullptr)
{
	std::cout << "Hello ! I'm "
		<< this->_name << " ! Nice to meet you."
		<< std::endl;
}
/*********************************************************************
* Constructeur (Copy)
*********************************************************************/
Character::Character(Character const & src)
{
	*this = src;
	std::cout << "Hello ! I'm "
		<< this->_name << " ! Nice to meet you."
		<< std::endl;
}
/*********************************************************************
* Assignation
*********************************************************************/
Character 		&Character::operator=(Character const & rhs)
{
	if(this != &rhs)
	{
		this->_name = rhs.getName();
		this->_ap = rhs.getAP();
	}
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
Character::~Character(void)
{
	std::cout << "Ciao from "
		<< this->_name
		<< std::endl;
}
/*********************************************************************
* Getter _type
*********************************************************************/
std::string const &Character::getName(void) const
{
	return (this->_name);
}
/*********************************************************************
* Getter _hp
*********************************************************************/
int Character::getAP(void) const
{
	return (this->_ap);
}
/*********************************************************************
* Getter _equip
*********************************************************************/
AWeapon	*Character::getEquip(void) const
{
	return (this->_equip);
}
/*********************************************************************
* recoverAP
*********************************************************************/
void	Character::recoverAP(void) {
	this->_ap += 10;
	if (this->_ap > 40)
	{
		this->_ap = 40;
	}
}
/*********************************************************************
* equip
*********************************************************************/
void	Character::equip(AWeapon *weapon)
{
	this->_equip = weapon;
}
/*********************************************************************
* attack
*********************************************************************/
void	Character::attack(Enemy *enemy)
{
	if (this->_equip)
	{
		int apcost = this->_equip->getAPCost();
		if (this->_ap >= apcost)
		{
			this->_ap -= apcost;
			this->_equip->attacks();
			enemy->takeDamage(this->_equip->getDamage());
			if (!enemy->getHP())
			{
				delete enemy;
			}
		}
	}
}

std::ostream		&operator<<(std::ostream & os, Character const & rhs)
{
	os << rhs.getName()
		<< " has " << rhs.getAP() << "AP";
	if (rhs.getEquip())
	{
		os << " and wield a " << rhs.getEquip()->getName() << ".";
	}
	else
		 os << " and is unarmed.";
	os << std::endl;
	return (os);
}
