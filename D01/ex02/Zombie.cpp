/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:54:21 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 12:21:58 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Constructor Zombie is called (name = " << name << ")." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor Zombie is called (name = " << this->_name << ", type = " << this->_type << ")." << std::endl;
}

void		Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiiinnssss....." << std::endl;;
}

void		Zombie::setType(std::string type)
{
	this->_type = type;
}
