/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:08:09 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 16:30:48 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "HumanB is constructed." << std::endl;
}
HumanB::~HumanB(void)
{
	std::cout << "HumanB is destructed." << std::endl;
}
void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
void	HumanB::attack(void) const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
