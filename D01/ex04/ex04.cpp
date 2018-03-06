/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:48:05 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 13:56:44 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *p; 
	std::string &r = str;
	
	p = &str;
	std::cout << "With the pointer : " << *p << std::endl;
	std::cout << "With the reference : " << r << std::endl;
	return (0);
}
