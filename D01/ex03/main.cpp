/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:18:30 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 13:10:14 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

int		main(void)
{
	ZombieHorde		horde = ZombieHorde(12);
	
	std::cout << std::endl << "Begin ZombieHorde in main" << std::endl << "------"  << std::endl;
	horde.announce();
	std::cout << "------"  << std::endl << "End ZombieHorde in main" << std::endl;
	return (0);
}
