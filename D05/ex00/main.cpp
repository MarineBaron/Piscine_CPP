/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/12 09:56:53 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	int		i;
	
	std::cout	<< std::endl << "-----" << std::endl
				<< "Jim KO (too high)" << std::endl
				<< "-----" << std::endl;
	try {
		Bureaucrat jim("Jim", 200);
		std::cout << jim;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout	<< std::endl << "-----" << std::endl
				<< "Lolo KO (too low)" << std::endl
				<< "-----" << std::endl;
	try {
		Bureaucrat lolo("Lolo", 0);
		std::cout << lolo;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout	<< std::endl << "-----" << std::endl
				<< "Jo OK" << std::endl
				<< "-----" << std::endl;
	try {
		Bureaucrat jo("Jo", 150);
		std::cout << jo;
		try {
			std::cout	<< std::endl << "-----" << std::endl
						<< "Jo increment KO (too high)" << std::endl
						<< "-----" << std::endl;
			jo.incrementGrade();
			std::cout << jo;
		}
		catch(std::exception & e)
		{
			std::cout << e.what();
		}
		i = jo.getGrade();
		while (i > 0)
		{
			std::cout	<< std::endl << "-----" << std::endl
						<< "Decrement " << jo << std::endl
						<< "-----" << std::endl;
			try
			{
				jo.decrementGrade();
				std::cout << jo;
			}
			catch(std::exception & e)
			{
				std::cout << e.what();
			}
			i--;
		}
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
