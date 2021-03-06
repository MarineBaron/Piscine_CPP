/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:17:18 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 15:34:47 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

unsigned int const FragTrap::_hit_max = 100;
unsigned int const FragTrap::_energie_max = 100;
unsigned int const FragTrap::_action_energie_cost = 25;
unsigned int const FragTrap::_armor_reduction = 5;
unsigned int const FragTrap::_melee_damage = 30;
unsigned int const FragTrap::_ranged_damage = 20;
unsigned int const FragTrap::_level_default = 1;
/*********************************************************************
* Static => select
*********************************************************************/
int FragTrap::_attacks_nb = 5;
unsigned int (FragTrap::*FragTrap::_attacks[])(std::string const & target) = {
	&FragTrap::torgueFiesta,
	&FragTrap::pirateShipMode,
	&FragTrap::clapInTheBox,
	&FragTrap::gunWizzard,
	&FragTrap::laserInferno
};
/*********************************************************************
* Constructor Default
*********************************************************************/
FragTrap::FragTrap(void)
{
	std::cout << "<FragTrap> Damage, I'm not alive... I don't know who am I !" << std::endl;
}
/*********************************************************************
* Constructor by String
*********************************************************************/
FragTrap::FragTrap(std::string const name) : _name(name)
{
	std::srand(std::time(nullptr));
	std::cout << "<FragTrap> Hi ! I'm " << _name  << ". Happy to serve you!"<< std::endl;
	this->_hit = FragTrap::_hit_max;
	this->_energie = FragTrap::_energie_max;
	this->_level = FragTrap::_level_default;
}
/*********************************************************************
* Constructor by copy
*********************************************************************/
FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "<FragTrap> Oups, I'm jus a clone..." << std::endl;
	*this = src;
}
/*********************************************************************
* Assignation
*********************************************************************/
FragTrap & 	FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "<FragTrap> Now, I'm just a clone..." << std::endl;
	this->_name = rhs._name;
	this->_hit = rhs._hit;
	this->_energie = rhs._energie;
	this->_level = rhs._level;
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
FragTrap::~FragTrap(void)
{
	std::cout << "<FragTrap> Bye bye... I'm dead... and absolutly destructed !" << std::endl;
}
/*********************************************************************
* Display User
*********************************************************************/
void FragTrap::display(void) const
{
	std::cout 	<< "<FragTrap> Display : " << this->_name << std::endl
				<< "---------------------" << std::endl
				<< "Level :              " << this->_level << std::endl
				<< "Hits points :        " << this->_hit << std::endl
				<< "Energis points :     " << this->_energie << std::endl
				<< "---------------------"<< std::endl;
}
/*********************************************************************
* Setter Name
*********************************************************************/
void FragTrap::setName(std::string const & name)
{
	this->_name = name;
}
/*********************************************************************
* Getter Name
*********************************************************************/
std::string FragTrap::getName(void) const
{
	return (_name);
}
/*********************************************************************
* attacks (with no effects !)
*********************************************************************/
void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "<FragTrap> I'm " << this->_name 
		<< " and attacks (melee) " << target 
		<< " causing " << FragTrap::_melee_damage
		<< " points of damage !"
		<< std::endl;
}
/*********************************************************************
* attacks (with no effects !)
*********************************************************************/
void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "<FragTrap> I'm "<< this->_name 
		<< " and attacks (range) " << target 
		<< " causing " << FragTrap::_ranged_damage
		<< " points of damage !"
		<< std::endl;
}
/*********************************************************************
* after being attacked
*********************************************************************/
void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "<FragTrap> "<< this->_name 
		<< " take " << amount << " points of damage "
		<< " less " << FragTrap::_armor_reduction << "(armor reduction)."
		<< std::endl;
	amount -= FragTrap::_armor_reduction;
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
void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "<FragTrap> "<< this->_name 
		<< " will be repaired with " << amount << " hits points "
		<< std::endl;
	if (this->_hit +  amount >= FragTrap::_hit_max)
		this->_hit = FragTrap::_hit_max;
	else
		this->_hit += amount;
	std::cout << "Now "<< this->_name 
			<< " has " << this->_hit << " hit points."
			<< std::endl;
}
/*********************************************************************
* randed attacks
*********************************************************************/
unsigned int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_energie < FragTrap::_action_energie_cost)
	{
		std::cout << "<FragTrap> " <<this->_name 
			<< " want to attack to can't, because he lacks "
			<< (FragTrap::_action_energie_cost - this->_energie)
			<< " energy points !"
			<< std::endl;
		return (0);
	}
	this->_energie -= FragTrap::_action_energie_cost;
	return ((this->*_attacks[FragTrap::getRandomInt()])(target));
}
/*********************************************************************
* static random int
*********************************************************************/
int FragTrap::getRandomInt(void)
{
	return ((int)std::floor(((float)std::rand() / (float)(RAND_MAX) * FragTrap::_attacks_nb)));
}
/*********************************************************************
* special attack : torgueFiesta
*********************************************************************/
unsigned int 	FragTrap::torgueFiesta(std::string const & target)
{
	std::cout << "<FragTrap> (torgueFiesta) I'm " << this->_name 
		<< " and attacks " << target << std::endl
		<< "One for you, one for you, one for you !"
		<< std::endl;
	return (40);
}
/*********************************************************************
* special attack : pirateShipMode
*********************************************************************/
unsigned int 	FragTrap::pirateShipMode(std::string const & target)
{
	std::cout << "<FragTrap> (pirateShipMode) I'm " << this->_name 
		<< " and attacks " << target << std::endl
		<< "I feel a joke about poop decks coming on !"
		<< std::endl;
	return (45);
}
/*********************************************************************
* special attack : clapInTheBox
*********************************************************************/
unsigned int 	FragTrap::clapInTheBox(std::string const & target)
{
	std::cout << "<FragTrap> (clapInTheBox) I'm " << this->_name 
		<< " and attacks " << target << std::endl
		<< "Oh darn, oh boy, oh crap, oh boy, oh darn."
		<< std::endl;
	return (25);
}
/*********************************************************************
* special attack : gunWizzard
*********************************************************************/
unsigned int 	FragTrap::gunWizzard(std::string const & target)
{
	std::cout << "<FragTrap> (gunWizzard) I'm " << this->_name 
		<< " and attacks " << target << std::endl
		<< "You can call me Gundalf!"
		<< std::endl;
	return (18);
}
/*********************************************************************
* special attack : laserInferno
*********************************************************************/
unsigned int 	FragTrap::laserInferno(std::string const & target)
{
	std::cout << "<FragTrap> (laserInferno) I'm " << this->_name 
		<< " and attacks " << target << std::endl
		<< "Psychedelic, man!"
		<< std::endl;
	return (18);
}
