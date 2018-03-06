/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:58:47 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 14:48:48 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)  {
	void const *address = static_cast<const void*>(this);
	std::stringstream addr;
	
	std::cout << "Brain is constructed." << std::endl;
	addr << address;
	this->_address = addr.str();
}
Brain::~Brain(void) {
	std::cout << "Brain is destructed." << std::endl;
}
std::string		Brain::identify(void) const
{
	return (this->_address);
}
