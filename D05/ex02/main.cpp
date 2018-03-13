/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/13 13:13:33 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void)
{
	std::cout	<< std::endl << std::endl << std::endl
				<< "*-------------*" << std::endl
				<< "*----ex02-----*" << std::endl
				<< "*-------------*" << std::endl;
	Bureaucrat					jack80("Jack80", 80);
	Bureaucrat					jack20("Jack20", 20);
	Bureaucrat					jim20(jack20);
	Bureaucrat					jack3("Jack3", 3);
	PresidentialPardonForm		formPP("JoTarget");
	RobotomyRequestForm			formRR("JoTarget");
	ShrubberyCreationForm		formSC("home");
	
	std::cout << jack80 << jack20 << jim20 << jack3 << formPP << formRR;
	
	try {
		std::cout	<< std::endl << "-----" << std::endl
					<< "Jack80 try to sign formPP KO (low)" << std::endl
					<< "-----" << std::endl;
		jack80.signForm(formPP);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	try {
		std::cout	<< std::endl << "-----" << std::endl
					<< "Jack80 try to exe formPP KO (sign)" << std::endl
					<< "-----" << std::endl;
		jack80.executeForm(formPP);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	try {
		std::cout	<< std::endl << "-----" << std::endl
			<< "Jack20 try to sign formPP OK" << std::endl
			<< "-----" << std::endl;
		jack20.signForm(formPP);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	try {
		std::cout	<< std::endl << "-----" << std::endl
					<< "Jack80 try to exe formPP KO (sign)" << std::endl
					<< "-----" << std::endl;
		jack80.executeForm(formPP);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	try {
		std::cout	<< std::endl << "-----" << std::endl
					<< "Jack3 try to exe formPP OK" << std::endl
					<< "-----" << std::endl;
		jack3.executeForm(formPP);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	
	
	
	try {
		std::cout	<< std::endl << "-----" << std::endl
			<< "Jack20 try to sign formRR OK" << std::endl
			<< "-----" << std::endl;
		jack20.signForm(formRR);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	int i = -1;
	while (++i < 10)
	{
		try {
			std::cout	<< std::endl << "-----" << std::endl
				<< "Jack20 try to exe formRR OK" << std::endl
				<< "-----" << std::endl;
			jack20.executeForm(formRR);
		}
		catch(std::exception & e)
		{
			std::cout << e.what();
		}
	}
	try {
		std::cout	<< std::endl << "-----" << std::endl
			<< "Jim20 (=Jack20) try to exe formRR OK" << std::endl
			<< "-----" << std::endl;
		jim20.executeForm(formRR);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	
	try {
		std::cout	<< std::endl << "-----" << std::endl
			<< "Jack20 try to sign formSC OK" << std::endl
			<< "-----" << std::endl;
		jack20.signForm(formSC);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	try {
		std::cout	<< std::endl << "-----" << std::endl
			<< "Jack20 try to exe formSC OK" << std::endl
			<< "-----" << std::endl;
		jack20.executeForm(formSC);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout	<< std::endl << "-----" << std::endl
		<< "Tree ASCII File" << std::endl
		<< "-----" << std::endl;
	std::string	line;
	std::ifstream	file("home_shrubbery");
	if (file.is_open())
	{
		while (std::getline(file, line))
			std::cout << line << std::endl;
		file.close();
		remove("home_shrubbery");
	}
	return (0);
}
