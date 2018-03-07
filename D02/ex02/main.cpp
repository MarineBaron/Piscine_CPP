/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/07 18:24:57 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int		main(void)
{
	Fixed a(1234.4321f);
	Fixed b(10);
	Fixed c;
	Fixed d = 0;
	Fixed const e(Fixed(5.05f) * Fixed(2));
	
	std::cout << std::endl;
	std::cout << "--- Float value" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "---" << std::endl;
	
	std::cout << std::endl;
	std::cout << "--- Raw values" << std::endl;
	std::cout << "a is " << a.getRawBits() << std::endl;
	std::cout << "b is " << b.getRawBits() << std::endl;
	std::cout << "c is " << c.getRawBits() << std::endl;
	std::cout << "---" << std::endl;
	
	std::cout << "--- Comparisons" << std::endl;
	std::cout << std::endl;
	std::cout << "< : a (" << a << ") is ";
	std::cout << ((a < b) ? "lower" : "greater or egal");
	std::cout << " than b (" << b << ")." << std::endl;
	
	std::cout << "<= : a (" << a << ") is ";
	std::cout << ((a < b) ? "lower or egal " : "greater");
	std::cout << " than b (" << b << ")." << std::endl;
	
	std::cout << "> : a (" << a << ") is ";
	std::cout << ((a > b) ? "greater" : "lower or egal");
	std::cout << " than b (" << b << ")." << std::endl;
	
	std::cout << ">= : a (" << a << ") is ";
	std::cout << ((a > b) ? "greater or egal" : "lower");
	std::cout << " than b (" << b << ")." << std::endl;
	
	std::cout << "== : a (" << a << ") is ";
	std::cout << ((a == b) ? "egal" : "different");
	std::cout << " from b (" << b << ")." << std::endl;
	
	std::cout << "!= : a (" << a << ") is ";
	std::cout << ((a != b) ? "different" : "egal");
	std::cout << " from b (" << b << ")." << std::endl;
	std::cout << "---" << std::endl;
	
	std::cout << std::endl;
	std::cout << "--- Operations" << std::endl;
	std::cout << std::endl;
	std::cout << "-- c = a + b :" << std::endl;
	c = a + b;
	std::cout << std::endl;
	std::cout << "+ : " << a << " + " << b << " = " << c << std::endl;
	std::cout << std::endl;
	std::cout << "-- c = a - b :" << std::endl;
	std::cout << std::endl;
	c = a - b;
	std::cout << std::endl;
	std::cout << "- : " << a << " - " << b << " = " << c << std::endl;
	std::cout << std::endl;
	std::cout << "-- c = a * b :" << std::endl;
	c = a * b;
	std::cout << std::endl;
	std::cout << "* : " << a << " * " << b << " = " << c << std::endl;
	std::cout << std::endl;
	std::cout << "-- c = a / b :" << std::endl;
	c = a / b;
	std::cout << std::endl;
	std::cout << "/ : " << a << " / " << b << " = " << c << std::endl;
	std::cout << std::endl;
	std::cout << "---" << std::endl;
	
	std::cout << std::endl;
	std::cout << "--- Increments" << std::endl;
	std::cout << "--> d ++d d d++ d" << std::endl;
	std::cout << d << std::endl;
	std::cout << (++d) << std::endl;
	std::cout << d << std::endl;
	std::cout << (d++) << std::endl;
	std::cout << d << std::endl;
	std::cout << "--> d --d d d-- d" << std::endl;
	std::cout << d << std::endl;
	std::cout << (--d) << std::endl;
	std::cout << d << std::endl;
	std::cout << (d--) << std::endl;
	std::cout << d << std::endl;
	
	std::cout << std::endl;
	std::cout << "--- Min / Max" << std::endl;
	c = Fixed::min(b, e);
	std::cout << "Minimum of " << b << " and " << e << " is " << c  << std::endl;
	
	c = Fixed::max(b, e);
	std::cout << "Maximum of " << b << " and " << e << " is " << c  << std::endl;

	return 0;
}
