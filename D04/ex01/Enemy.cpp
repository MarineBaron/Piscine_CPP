/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:26:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 14:38:02 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

/*********************************************************************
* Constructeur (name, type)
*********************************************************************/
Enemy::Enemy(int hp, std::string const & type) : 
	_hp(hp), _type(type)
{
	std::cout << "Enemy created : "
		<< this->_type << ", " << this->_hp
		<< std::endl;
}
/*********************************************************************
* Constructeur (Copy)
*********************************************************************/
Enemy::Enemy(Enemy const & src)
{
	*this = src;
	std::cout << "Enemy created : "
		<< this->_type << ", " << this->_hp
		<< std::endl;
}
/*********************************************************************
* Assignation
*********************************************************************/
Enemy 		&Enemy::operator=(Enemy const & rhs)
{
	if(this != &rhs)
	{
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return (*this);
}
/*********************************************************************
* Destructor
*********************************************************************/
Enemy::~Enemy(void)
{
	std::cout << "Enemy destructed : "
		<< this->_type << ", " << this->_hp
		<< std::endl;
}
/*********************************************************************
* Getter _type
*********************************************************************/
std::string const &Enemy::getType(void) const
{
	return (this->_type);
}
/*********************************************************************
* Getter _hp
*********************************************************************/
int Enemy::getHP(void) const
{
	return (this->_hp);
}
/*********************************************************************
* takeDamage
*********************************************************************/
void		Enemy::takeDamage(int hp) {
	std::cout << this->_type << " (" <<  this->_hp << ") "
		<< " should take " << hp << " damage points. ";
	if (hp >= 0)
	{
		if (this->_hp - hp > 0)
			this->_hp = this->_hp - hp;
		else
			this->_hp = 0;
	}
	std::cout << this->_type << " has " << this->_hp << " HP."
		<< std::endl;
}
