/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:03:08 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 16:12:09 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon is constructed." << std::endl;
}
Weapon::~Weapon(void)
{
	std::cout << "Weapon is destructed." << std::endl;
}
std::string const & Weapon::getType(void) const
{
	std::string const & ref = this->_type;
	
	return (ref);
}
void				Weapon::setType(std::string type)
{
	this->_type = type;
}
