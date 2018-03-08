/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:17:18 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 16:05:45 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

unsigned int const ScavTrap::_hit_max = 100;
unsigned int const ScavTrap::_energie_max = 50;
unsigned int const ScavTrap::_action_energie_cost = 25;
unsigned int const ScavTrap::_armor_reduction = 3;
unsigned int const ScavTrap::_melee_damage = 20;
unsigned int const ScavTrap::_ranged_damage = 15;
unsigned int const ScavTrap::_level_default = 1;
/*********************************************************************
* Static => select
*********************************************************************/
int ScavTrap::_challenges_nb = 3;
unsigned int (ScavTrap::*ScavTrap::_challenges[])(std::string const & target) = {
	&ScavTrap::jumpingAGap,
	&ScavTrap::runningOutOfAmmo,
	&ScavTrap::spottingABadassEnemy
};
/*********************************************************************
* Constructor Default
*********************************************************************/
ScavTrap::ScavTrap(void)
{
	std::cout << "<ScavTrap> Damage, I'm not alive... I don't know who am I !" << std::endl;
}
/*********************************************************************
* Constructor by String
*********************************************************************/
ScavTrap::ScavTrap(std::string const name) : _name(name)
{
	std::srand(std::time(nullptr));
	std::cout << "<ScavTrap> Hi ! I'm " << _name  << ". Happy to serve you!"<< std::endl;
	this->_hit = ScavTrap::_hit_max;
	this->_energie = ScavTrap::_energie_max;
	this->_level = ScavTrap::_level_default;
}
/*********************************************************************
* Constructor by copy
*********************************************************************/
ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "<ScavTrap> Oups, I'm jus a clone..." << std::endl;
	*this = src;
}
/*********************************************************************
* Assignation
*********************************************************************/
ScavTrap & 	ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "<ScavTrap> Now, I'm just a clone..." << std::endl;
	this->_name = rhs._name;
	this->_hit = rhs._hit;
	this->_energie = rhs._energie;
	this->_level = rhs._level;
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
ScavTrap::~ScavTrap(void)
{
	std::cout << "<ScavTrap> Bye bye... I'm dead... and absolutly destructed !" << std::endl;
}
/*********************************************************************
* Display User
*********************************************************************/
void ScavTrap::display(void) const
{
	std::cout 	<< "<ScavTrap> Display : " << this->_name << std::endl
				<< "---------------------" << std::endl
				<< "Level :              " << this->_level << std::endl
				<< "Hits points :        " << this->_hit << std::endl
				<< "Energis points :     " << this->_energie << std::endl
				<< "---------------------"<< std::endl;
}
/*********************************************************************
* Setter Name
*********************************************************************/
void ScavTrap::setName(std::string const & name)
{
	this->_name = name;
}
/*********************************************************************
* Getter Name
*********************************************************************/
std::string ScavTrap::getName(void) const
{
	return (_name);
}
/*********************************************************************
* attacks (with no effects !)
*********************************************************************/
void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "<ScavTrap> I'm " << this->_name 
		<< " and attacks (melee) " << target 
		<< " causing " << ScavTrap::_melee_damage
		<< " points of damage !"
		<< std::endl;
}
/*********************************************************************
* attacks (with no effects !)
*********************************************************************/
void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "<ScavTrap> I'm "<< this->_name 
		<< " and attacks (range) " << target 
		<< " causing " << ScavTrap::_ranged_damage
		<< " points of damage !"
		<< std::endl;
}
/*********************************************************************
* after being attacked
*********************************************************************/
void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "<ScavTrap> "<< this->_name 
		<< " take " << amount << " points of damage "
		<< " less " << ScavTrap::_armor_reduction << "(armor reduction)."
		<< std::endl;
	amount -= ScavTrap::_armor_reduction;
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
void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "<ScavTrap> "<< this->_name 
		<< " will be repaired with " << amount << " hits points "
		<< std::endl;
	if (this->_hit +  amount >= ScavTrap::_hit_max)
		this->_hit = ScavTrap::_hit_max;
	else
		this->_hit += amount;
	std::cout << "Now "<< this->_name 
			<< " has " << this->_hit << " hit points."
			<< std::endl;
}
/*********************************************************************
* randed attacks
*********************************************************************/
unsigned int ScavTrap::challengeNewcomer(std::string const & target)
{
	return ((this->*_challenges[ScavTrap::getRandomInt()])(target));
}
/*********************************************************************
* static random int
*********************************************************************/
int ScavTrap::getRandomInt(void)
{
	return ((int)std::floor(((float)std::rand() / (float)(RAND_MAX) * ScavTrap::_challenges_nb)));
}
/*********************************************************************
* special attack : jumpingAGap
*********************************************************************/
unsigned int 	ScavTrap::jumpingAGap(std::string const & target)
{
	std::cout << "<ScavTrap> (jumpingAGap) I'm " << this->_name 
		<< " and attacks " << target << std::endl
		<< "Watch as we observe the rare and beautiful Clappy Bird!"
		<< std::endl;
	return (40);
}
/*********************************************************************
* special attack : runningOutOfAmmo
*********************************************************************/
unsigned int 	ScavTrap::runningOutOfAmmo(std::string const & target)
{
	std::cout << "<ScavTrap> (runningOutOfAmmo) I'm " << this->_name 
		<< " and attacks " << target << std::endl
		<< "Who needs ammo anyway, am I right?"
		<< std::endl;
	return (45);
}
/*********************************************************************
* special attack : spottingABadassEnemy
*********************************************************************/
unsigned int 	ScavTrap::spottingABadassEnemy(std::string const & target)
{
	std::cout << "<ScavTrap> (clapInTheBox) I'm " << this->_name 
		<< " and attacks " << target << std::endl
		<< "Look out, a Badass!"
		<< std::endl;
	return (25);
}
