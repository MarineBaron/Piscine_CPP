/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:17:57 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 13:15:22 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include "Zombie.hpp"

class ZombieHorde {
	private:
		int							_n;
		Zombie						*_horde;
		static std::string			getRandomName(void);
		static std::string const	_type;
		
	public:
	    ZombieHorde(int	N);
	    ~ZombieHorde(void);
		void				announce(void) const;
};
#endif
