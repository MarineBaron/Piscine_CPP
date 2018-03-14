/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/14 13:08:13 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypedString.hpp"

int		main(int argc, char **argv)
{
	std::string	const prog = argv[0];
	
	if (argc != 2)
	{
		std::cout << "usage: " + prog + " str_to_type" << std::endl;
		return (1);
	}
	
	TypedString	ts = TypedString(static_cast<std::string const &>(argv[1]));
	
	std::cout << "char : ";
	try
	{
		char v = static_cast<char>(ts);
		std::cout << v;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "int : ";
	try
	{
		int v = static_cast<int>(ts);
		std::cout << v;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	
	std::cout << std::fixed;
	std::cout.precision(ts.getPrecision());
	
	std::cout << std::endl;
	std::cout << "float : ";
	try
	{
		float v = static_cast<float>(ts);
		std::cout << v << "f";
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "double : ";
	try
	{
		double v = static_cast<double>(ts);
		std::cout << v;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	return 0;
}
