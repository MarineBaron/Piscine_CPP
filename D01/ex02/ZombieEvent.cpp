/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:10:30 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 12:15:54 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) 
{
	std::cout << "Constructor ZombieEvent is called." << std::endl;
}

ZombieEvent::~ZombieEvent()
{
	std::cout << "Destructor ZombieEvent is called." << std::endl;
}

void		ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie		*ZombieEvent::newZombie(std::string name) const
{
	Zombie *zombie;
	
	zombie = new Zombie(name);
	zombie->setType(this->_type);
	return (zombie);
}
