/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/07 12:14:31 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int		main(void)
{
	Fixed		a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	
	a = Fixed(1234.4321f);
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as Integer." << std::endl;
	std::cout << "b is " << b.toInt() << " as Integer." << std::endl;
	std::cout << "c is " << c.toInt() << " as Integer." << std::endl;
	std::cout << "d is " << d.toInt() << " as Integer." << std::endl;
	
	std::cout << "a is " << a.toFloat() << " as Float." << std::endl;
	std::cout << "b is " << b.toFloat() << " as Float." << std::endl;
	std::cout << "c is " << c.toFloat() << " as Float." << std::endl;
	std::cout << "d is " << d.toFloat() << " as Float." << std::endl;
	return 0;
}
