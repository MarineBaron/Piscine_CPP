/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 22:19:53 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/02 08:05:58 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	std::cout	<< std::endl << std::endl << "-----" << std::endl
				<< "Jim KO (too low)" << std::endl
				<< "-----" << std::endl;
	try {
		Bureaucrat jim("Jim", 200);
		std::cout << jim;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout	<< std::endl << std::endl << "-----" << std::endl
				<< "Lolo KO (too high)" << std::endl
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
			std::cout	<< std::endl << std::endl << "-----" << std::endl
						<< "Jo decrement KO (too low)" << std::endl
						<< "-----" << std::endl;
			jo.decrementGrade();
			std::cout << jo;
		}
		catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

		Bureaucrat jim("Jim", 10);
		int i = jim.getGrade();
		while (i > -1)
		{
			std::cout	 << std::endl << std::endl << "-----" << std::endl
						<< "Increment " << jim << std::endl
						<< "-----" << std::endl;
			try
			{
				jim.incrementGrade();
				std::cout << jim;
			}
			catch(std::exception & e)
			{
				std::cout << e.what() << std::endl;
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
