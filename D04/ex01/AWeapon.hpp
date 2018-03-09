/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:55:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 14:35:13 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class AWeapon
{
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & src);
		virtual ~AWeapon(void);
		
		AWeapon 					&operator=(AWeapon const & rhs);
		std::string	const	&getName(void) const;
		int					getAPCost(void) const;
		int					getDamage(void) const;
		virtual void		attacks(void) const = 0;
	
	private:
		std::string		_name;
		int				_apcost;
		int				_damage;
};
#endif
