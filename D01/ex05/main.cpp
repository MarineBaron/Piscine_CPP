/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:18:30 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 14:50:28 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main(void)
{
	Human		bob;
	
	std::cout << std::endl << bob.identify() << std::endl;
	std::cout << std::endl << bob.getBrain().identify() << std::endl;
	return (0);
}
