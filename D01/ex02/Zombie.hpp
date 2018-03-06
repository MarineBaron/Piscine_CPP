/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:56:25 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 11:15:50 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie {
	private:
		std::string	_type;
		std::string	_name;
		
	public:
	    Zombie(std::string name);
	    ~Zombie(void);
		void		announce(void) const;
		void		setType(std::string type);
};
#endif
