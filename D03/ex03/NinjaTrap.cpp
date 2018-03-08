/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:17:18 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 17:29:15 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

unsigned int const NinjaTrap::_hit_max = 60;
unsigned int const NinjaTrap::_energie_max = 120;
unsigned int const NinjaTrap::_action_energie_cost = 25;
unsigned int const NinjaTrap::_armor_reduction = 0;
unsigned int const NinjaTrap::_melee_damage = 60;
unsigned int const NinjaTrap::_ranged_damage = 5;
unsigned int const NinjaTrap::_level_default = 1;

/*********************************************************************
* Constructor Default
*********************************************************************/
NinjaTrap::NinjaTrap(void)
{
	std::cout << "<NinjaTrap> Damage, I'm not alive... I don't know who am I !" << std::endl;
}
/*********************************************************************
* Constructor by String
*********************************************************************/
NinjaTrap::NinjaTrap(std::string const name) : ClapTrap(name)
{
	std::srand(std::time(nullptr));
	std::cout << "<NinjaTrap> Hi ! I'm " << _name  << ". Happy to serve you!"<< std::endl;
	this->_hit = NinjaTrap::_hit_max;
	this->_energie = NinjaTrap::_energie_max;
	this->_level = NinjaTrap::_level_default;
}
/*********************************************************************
* Constructor by copy
*********************************************************************/
NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	std::cout << "<NinjaTrap> Oups, I'm just a clone..." << std::endl;
	*this = src;
}
/*********************************************************************
* Assignation
*********************************************************************/
NinjaTrap & 	NinjaTrap::operator=(NinjaTrap const & rhs)
{
	std::cout << "<NinjaTrap> Now, I'm just a clone..." << std::endl;
	this->_name = rhs._name;
	this->_hit = rhs._hit;
	this->_energie = rhs._energie;
	this->_level = rhs._level;
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
NinjaTrap::~NinjaTrap(void)
{
	std::cout << "<NinjaTrap> Bye bye... I'm dead... and absolutly destructed !" << std::endl;
}
/*********************************************************************
* action on FragTrap : rangedAttack
*********************************************************************/
void NinjaTrap::ninjaShoebox(FragTrap & target)
{
	if (this->_energie < NinjaTrap::_action_energie_cost)
	{
		std::cout << "<NinjaTrap> " <<this->_name 
			<< " want to attack to can't, because he lacks "
			<< (NinjaTrap::_action_energie_cost - this->_energie)
			<< " energy points !"
			<< std::endl;
			return ;
	}
	this->_energie -= NinjaTrap::_action_energie_cost;
	this->rangedAttack(target.getName());
	target.takeDamage(NinjaTrap::_ranged_damage);
}
/*********************************************************************
* action on ScavTrap : meleeAttack
*********************************************************************/
void NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	if (this->_energie < NinjaTrap::_action_energie_cost)
	{
		std::cout << "<NinjaTrap> " <<this->_name 
			<< " want to attack to can't, because he lacks "
			<< (NinjaTrap::_action_energie_cost - this->_energie)
			<< " energy points !"
			<< std::endl;
		return ;
	}
	this->_energie -= NinjaTrap::_action_energie_cost;
	this->meleeAttack(target.getName());
	target.takeDamage(NinjaTrap::_melee_damage);
}
/*********************************************************************
* action on ScavTrap : meleeAttack
*********************************************************************/
void NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
	if (this->_energie < NinjaTrap::_action_energie_cost)
	{
		std::cout << "<NinjaTrap> " <<this->_name 
			<< " want to attack to can't, because he lacks "
			<< (NinjaTrap::_action_energie_cost - this->_energie)
			<< " energy points !"
			<< std::endl;
		return ;
	}
	this->_energie -= NinjaTrap::_action_energie_cost;
	target.beRepaired(50);
}
