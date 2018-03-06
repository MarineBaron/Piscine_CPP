/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:56:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 19:04:39 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int		error(std::string str)
{
	std::cout << str << std::endl;
	return (1);
}

int		main(int argc, char **argv)
{
	std::string		f;
	std::string		s_from;
	std::string		s_to;
	std::ifstream	f_from;
	std::ofstream	f_to;
	std::string		buff;
	size_t			start;
	size_t			len;
	if (argc < 4)
		return (error("usage: ./replace filename str_to_search str_to replace_with"));
	f = argv[1];
	f_from.open(f, std::ifstream::in);
	f_to.open(f + ".replace", std::ofstream::out | std::ofstream::trunc);
	if (!f_from.is_open() || !f_to.is_open())
		return (error("Error : files can't be opened"));
	s_from = argv[2];
	s_to = argv[3];
	len = s_from.length();
	while (std::getline(f_from, buff))
	{
		start = 0;
		if (len)
		{
			while ((start = buff.find(s_from, start)) != std::string::npos)
				buff.replace(start, len, s_to);
		}
		f_to << buff << std::endl;
	}
	f_from.close();
	f_to.close();
	return (0);
}
