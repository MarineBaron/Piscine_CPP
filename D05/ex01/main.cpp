/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/13 09:11:04 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	int		i;
	
	std::cout	<< std::endl 
				<< "*-------------*" << std::endl
				<< "*----ex00-----*" << std::endl
				<< "*-------------*" << std::endl;
	
	std::cout	<< std::endl << "-----" << std::endl
				<< "Jo200 KO (too high)" << std::endl
				<< "-----" << std::endl;
	try {
		Bureaucrat jo200("jo200", 200);
		std::cout << jo200;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout	<< std::endl << "-----" << std::endl
				<< "Jo0 KO (too low)" << std::endl
				<< "-----" << std::endl;
	try {
		Bureaucrat jo0("Jo0", 0);
		std::cout << jo0;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout	<< std::endl << "-----" << std::endl
				<< "Jo150 OK" << std::endl
				<< "-----" << std::endl;
	try {
		Bureaucrat jo150("Jo150", 150);
		std::cout << jo150;
		try {
			std::cout	<< std::endl << "-----" << std::endl
						<< "Jo150 increment KO (too high)" << std::endl
						<< "-----" << std::endl;
			jo150.incrementGrade();
			std::cout << jo150;
		}
		catch(std::exception & e)
		{
			std::cout << e.what();
		}
		i = jo150.getGrade();
		while (i > 0)
		{
			std::cout	<< std::endl << "-----" << std::endl
						<< "Decrement " << jo150 << std::endl
						<< "-----" << std::endl;
			try
			{
				jo150.decrementGrade();
				std::cout << jo150;
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
	std::cout	<< std::endl << std::endl << std::endl
				<< "*-------------*" << std::endl
				<< "*----ex01-----*" << std::endl
				<< "*-------------*" << std::endl;
	Bureaucrat	jim80("Jim80", 80);
	Form		form79("Form79", 80, 80);
	Form		form130("Form130", 130, 130);
	try {
		std::cout	<< std::endl << "-----" << std::endl
					<< "Jim80 try to sign Form130 OK" << std::endl
					<< "-----" << std::endl;
		jim80.signForm(form130);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	try {
		std::cout	<< std::endl << "-----" << std::endl
					<< "Jim80 try to sign Form79 KO (too low)" << std::endl
					<< "-----" << std::endl;
		jim80.signForm(form79);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	try {
		std::cout	<< std::endl << "-----" << std::endl
					<< "Jim80 decremete and try to sign Form79 OK" << std::endl
					<< "-----" << std::endl;
		std::cout << jim80;
		jim80.decrementGrade();
		std::cout << jim80;
		jim80.signForm(form79);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	return (0);
}
