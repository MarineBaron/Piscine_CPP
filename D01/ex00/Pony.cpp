/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:02:35 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 10:33:52 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony() {
	std::cout << "Constructeur Pony is called." << std::endl;
}

Pony::~Pony(void) {
	std::cout << "Destructeur Pony is call. Pony was (name = '" << this->_name << "' and color = '" << this->_color << "')." << std::endl;
}

void		Pony::init(std::string name, std::string color)
{
	this->_name = name;
	this->_color = color;
}

void		Pony::display(void) const
{
	std::cout << "Hi ! My name is " << this->getName() << " and I'm " << this->getName() << "." << std::endl;
}

std::string	Pony::getName(void) const
{
	return (this->_name);
}

std::string	Pony::getColor(void) const
{
	return (this->_color);
}
