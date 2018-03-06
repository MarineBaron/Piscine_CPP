/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:10:30 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 13:43:54 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : _n(N)
{
	int		i;
	std::cout << "Constructor ZombieHorde is called." << std::endl;
	this->_horde = new Zombie[N];
	i = -1;
	while (++i < N)
	{
		this->_horde[i].setName(ZombieHorde::getRandomName());
		this->_horde[i].setType(ZombieHorde::_type);
	}
}

ZombieHorde::~ZombieHorde()
{
	std::cout << "Destructor ZombieHorde is called." << std::endl;
	delete [] this->_horde;	
}

void		ZombieHorde::announce(void) const
{
	int		i;
	
	i = -1;
	while (++i < this->_n)
		this->_horde[i].announce();
}


std::string	ZombieHorde::getRandomName(void)
{
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
	
	std::srand(std::time(NULL));
	return (names[(int)((std::rand() / (double)RAND_MAX) * (double)10)]);
}
std::string const ZombieHorde::_type = "Zebu";
