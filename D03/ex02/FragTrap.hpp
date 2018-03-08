/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:17:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 16:43:57 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
		static unsigned int	const	_hit_max;
		static unsigned int	const	_energie_max;
		static unsigned int	const	_action_energie_cost;
		static unsigned int	const	_armor_reduction;
		static unsigned int	const	_level_default;
		static int					_attacks_nb;
		static unsigned int			(FragTrap::*_attacks[])(std::string const & target);
		
	public:
		static unsigned int	const	_melee_damage;
		static unsigned int	const	_ranged_damage;
		
	public:
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);
		
		FragTrap & 	operator=(FragTrap const & rhs);
		
		unsigned int	vaulthunter_dot_exe(std::string const & target);
		
		unsigned int 	torgueFiesta(std::string const & target);
		unsigned int 	pirateShipMode(std::string const & target);
		unsigned int 	clapInTheBox(std::string const & target);
		unsigned int 	gunWizzard(std::string const & target);
		unsigned int 	laserInferno(std::string const & target);
};
#endif
