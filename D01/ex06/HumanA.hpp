/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:08:46 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 16:23:38 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA {
	private:
		Weapon	 			&_weapon;
		std::string 		_name;
		
	public:
	    HumanA(std::string name, Weapon &weapon);
	    ~HumanA(void);
		void				attack(void) const;
};
#endif
