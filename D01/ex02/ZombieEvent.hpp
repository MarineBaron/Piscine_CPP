/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:17:57 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 12:13:24 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "Zombie.hpp"

class ZombieEvent {
	private:
		std::string	_type;
		
	public:
	    ZombieEvent(void);
	    ~ZombieEvent(void);
		void		setZombieType(std::string type);
		Zombie		*newZombie(std::string name) const;
};
#endif
