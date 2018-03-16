/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:34:08 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/16 11:54:45 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T>
void	swap(T & x, T & y)
{
	T  tmp = x;
	x = y;
	y = tmp;
}

template< typename T>
T const &	min(T const & x, T const & y)
{
	return (x < y ? x : y);
}

template< typename T>
T const &	max(T const & x, T const & y)
{
	return (x > y ? x : y);
}

int		main(void)
{
	char c1 = 'c';
	char c2 = 'd';
	
	std::cout << std::endl<< "Init char " << std::endl;
	std::cout << "x: " << c1 << " y: " << c2 << std::endl;
	::swap(c1, c2);
	std::cout << "Swaped x: " << c1 << " y: " << c2 << std::endl;
	std::cout << "min: " << ::min(c1, c2) << " max: " << ::max(c1, c2) << std::endl;
	
	
	int i1 = 0;
	int i2 = 12;
	
	std::cout << std::endl << "Init int " << std::endl;
	std::cout << "x: " << i1 << " y: " << i2 << std::endl;
	::swap(i1, i2);
	std::cout << "Swaped x: " << i1 << " y: " << i2 << std::endl;
	std::cout << "min: " << ::min(i1, i2) << " max: " << ::max(i1, i2) << std::endl;
	
	
	double d1 = 0.12;
	double d2 = 12.31;
	
	std::cout << std::endl << "Init double " << std::endl;
	std::cout << "x: " << d1 << " y: " << d2 << std::endl;
	::swap(d1, d2);
	std::cout << "Swaped x: " << d1 << " y: " << d2 << std::endl;
	std::cout << "min: " << ::min(d1, d2) << " max: " << ::max(d1, d2) << std::endl;
	
	std::string s1 = "aaa";
	std::string s2 = "aba";
	
	std::cout << std::endl << "Init string " << std::endl;
	std::cout << "x: " << s1 << " y: " << s2 << std::endl;
	::swap(s1, s2);
	std::cout << "Swaped x: " << s1 << " y: " << s2 << std::endl;
	std::cout << "min: " << ::min(s1, s2) << " max: " << ::max(s1, s2) << std::endl;
	
	return 0;
}
	
