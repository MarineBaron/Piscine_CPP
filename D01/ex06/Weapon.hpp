/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:58:35 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 16:10:51 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon {
	private:
		std::string		_type;
		
	public:
	    Weapon(std::string type);
	    ~Weapon(void);
		std::string const & getType(void) const;
		void				setType(std::string type);
};
#endif
