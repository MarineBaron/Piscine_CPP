/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:55:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 14:40:19 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	public:
		Character(std::string const & name);
		Character(Character const & src);
		~Character(void);
		
		Character 					&operator=(Character const & rhs);
		std::string const 			&getName(void) const;
		int							getAP(void) const;
		AWeapon						*getEquip(void) const;
		void						recoverAP(void);
		void						equip(AWeapon *weapon);
		void						attack(Enemy *enemy);
		
	private:
		std::string		_name;
		int				_ap;
		AWeapon			*_equip;
};

std::ostream		&operator<<(std::ostream & os, Character const & rhs);
#endif
