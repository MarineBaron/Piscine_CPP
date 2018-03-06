/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:23:29 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 14:33:44 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) 
{
	std::cout << "Human is constructed." << std::endl;
}
Human::~Human(void)
{
	std::cout << "Human is destructed." << std::endl;
}
Brain			Human::getBrain(void) const
{
	return (this->_brain);
}
std::string		Human::identify(void) const
{
	return (this->_brain.identify());
}
