/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:08:46 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 16:26:25 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB {
	private:
		Weapon	 			*_weapon;
		std::string 		_name;
		
	public:
	    HumanB(std::string name);
	    ~HumanB(void);
		void				attack(void) const;
		void				setWeapon(Weapon &weapon);
};
#endif
