/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:47:44 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 11:38:05 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int		main(void)
{
	Sorcerer	sorcerer("Gandalf", "Mage");
	Victim		victim("Pippin");
	Peon		peon("William");
	
	std::cout << sorcerer << victim << peon;
	sorcerer.polymorph(victim);
	sorcerer.polymorph(peon);
	return 0;
}
