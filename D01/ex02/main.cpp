/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:18:30 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 12:20:19 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

void	randomChump(void)
{
	int			random_int;
	ZombieEvent	zombie_event;
	Zombie		*zombie;
	std::string	names[10] = {
		"Marine",
		"Isabelle",
		"Nadia",
		"Tracy",
		"Agnescka",
		"Patrice",
		"Philippe",
		"Pascal",
		"Fred",
		"Richard"
	};
	
	std::srand(std::time(nullptr));
	random_int = std::rand() * 10 / RAND_MAX;
	zombie_event.setZombieType("randomChump");
	zombie = zombie_event.newZombie(names[std::rand() * 10 / RAND_MAX]);
	zombie->announce();
	delete zombie;
}

int		main(void)
{
	ZombieEvent	zombie_event;
	Zombie		*zombie;
	
	std::cout << std::endl << "Begin Zombie in Main Alone" << std::endl << "------"  << std::endl;
	zombie = new Zombie("mainAlone");
	zombie->setType("mainAlone");
	zombie->announce();
	delete zombie;
	std::cout << "------"  << std::endl << "End Zombie in Main Alone" << std::endl;
	
	std::cout << std::endl << "Begin Zombie in Main ZombieEvent" << std::endl << "------"  << std::endl;
	zombie_event.setZombieType("mainZombieEvent");
	zombie = zombie_event.newZombie("mainZombieEvent");
	zombie->announce();
	delete zombie;
	std::cout << "------"  << std::endl << "End Zombie in Main ZombieEvent" << std::endl;
	
	std::cout << std::endl << "Begin Zombie in randomChump" << std::endl << "------"  << std::endl;
	randomChump();
	std::cout << "------"  << std::endl << "End Zombie in randomChump" << std::endl;
	return (0);
}
