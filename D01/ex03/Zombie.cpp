/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:54:21 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 13:11:26 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Constructor Zombie is called." << std::endl;
	this->_name = "";
	this->_type = "";
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor Zombie is called (name = " << this->_name << ", type = " << this->_type << ")." << std::endl;
}

void		Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiiinnssss....." << std::endl;;
}

void		Zombie::setName(std::string name)
{
	this->_name = name;
}

void		Zombie::setType(std::string type)
{
	this->_type = type;
}
