/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:18:30 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 10:46:48 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	Pony *pony;
	
	pony = new Pony();
	pony->init("Rick Heap", "red");
	pony->display();
	delete pony;
}

void	ponyOnTheStack(void)
{
	Pony pony;
	
	pony.init("Bob Stack", "blue");
	pony.display();
}

int		main(void)
{
	std::cout << std::endl << "Begin Pony on the heap" << std::endl << "------"  << std::endl;
	ponyOnTheHeap();
	std::cout << "------"  << std::endl << "End Pony on the heap" << std::endl;
	std::cout << std::endl << "Begin Pony on the stack" << std::endl << "------"  << std::endl;
	ponyOnTheStack();
	std::cout << "------"  << std::endl << "End Pony on the stack" << std::endl;
	return (0);
}
