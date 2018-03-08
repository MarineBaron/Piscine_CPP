/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:17:18 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 16:42:39 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

unsigned int const ClapTrap::_hit_max = 100;
unsigned int const ClapTrap::_energie_max = 100;
unsigned int const ClapTrap::_action_energie_cost = 25;
unsigned int const ClapTrap::_armor_reduction = 5;
unsigned int const ClapTrap::_melee_damage = 30;
unsigned int const ClapTrap::_ranged_damage = 20;
unsigned int const ClapTrap::_level_default = 1;
/*********************************************************************
* Constructor Default
*********************************************************************/
ClapTrap::ClapTrap(void)
{
	std::cout << "<ClapTrap> Damage, I'm not alive... I don't know who am I !" << std::endl;
}
/*********************************************************************
* Constructor by String
*********************************************************************/
ClapTrap::ClapTrap(std::string const name) : _name(name)
{
	std::srand(std::time(nullptr));
	std::cout << "<ClapTrap> Hi ! I'm " << _name  << ". Happy to serve you!"<< std::endl;
	this->_hit = ClapTrap::_hit_max;
	this->_energie = ClapTrap::_energie_max;
	this->_level = ClapTrap::_level_default;
}
/*********************************************************************
* Constructor by copy
*********************************************************************/
ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "<ClapTrap> Oups, I'm jus a clone..." << std::endl;
	*this = src;
}
/*********************************************************************
* Assignation
*********************************************************************/
ClapTrap & 	ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "<ClapTrap> Now, I'm just a clone..." << std::endl;
	this->_name = rhs._name;
	this->_hit = rhs._hit;
	this->_energie = rhs._energie;
	this->_level = rhs._level;
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
ClapTrap::~ClapTrap(void)
{
	std::cout << "<ClapTrap> Bye bye... I'm dead... and absolutly destructed !" << std::endl;
}
/*********************************************************************
* Display User
*********************************************************************/
void ClapTrap::display(void) const
{
	std::cout 	<< "<ClapTrap> Display : " << this->_name << std::endl
				<< "---------------------" << std::endl
				<< "Level :              " << this->_level << std::endl
				<< "Hits points :        " << this->_hit << std::endl
				<< "Energis points :     " << this->_energie << std::endl
				<< "---------------------"<< std::endl;
}
/*********************************************************************
* Setter Name
*********************************************************************/
void ClapTrap::setName(std::string const & name)
{
	this->_name = name;
}
/*********************************************************************
* Getter Name
*********************************************************************/
std::string ClapTrap::getName(void) const
{
	return (_name);
}
/*********************************************************************
* attacks (with no effects !)
*********************************************************************/
void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "<ClapTrap> I'm " << this->_name 
		<< " and attacks (melee) " << target 
		<< " causing " << ClapTrap::_melee_damage
		<< " points of damage !"
		<< std::endl;
}
/*********************************************************************
* attacks (with no effects !)
*********************************************************************/
void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "<ClapTrap> I'm "<< this->_name 
		<< " and attacks (range) " << target 
		<< " causing " << ClapTrap::_ranged_damage
		<< " points of damage !"
		<< std::endl;
}
/*********************************************************************
* after being attacked
*********************************************************************/
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "<ClapTrap> "<< this->_name 
		<< " take " << amount << " points of damage "
		<< " less " << ClapTrap::_armor_reduction << "(armor reduction)."
		<< std::endl;
	amount -= ClapTrap::_armor_reduction;
	if (amount >= this->_hit)
		this->_hit = 0;
	else
		this->_hit -= amount;
	std::cout << "Now "<< this->_name 
		<< " has " << this->_hit << " hit points."
		<< std::endl;
}
/*********************************************************************
* after being attacked
*********************************************************************/
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "<ClapTrap> "<< this->_name 
		<< " will be repaired with " << amount << " hits points "
		<< std::endl;
	if (this->_hit +  amount >= ClapTrap::_hit_max)
		this->_hit = ClapTrap::_hit_max;
	else
		this->_hit += amount;
	std::cout << "Now "<< this->_name 
			<< " has " << this->_hit << " hit points."
			<< std::endl;
}
/*********************************************************************
* static random int
*********************************************************************/
int ClapTrap::getRandomInt(int const nb)
{
	return ((int)std::floor(((float)std::rand() / (float)(RAND_MAX) * nb)));
}
