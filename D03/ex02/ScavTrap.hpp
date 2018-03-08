/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:17:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 16:44:09 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	
	private:
		static unsigned int	const	_hit_max;
		static unsigned int	const	_energie_max;
		static unsigned int	const	_action_energie_cost;
		static unsigned int	const	_armor_reduction;
		static unsigned int	const	_level_default;
		static int					_challenges_nb;
		static unsigned int			(ScavTrap::*_challenges[])(std::string const & target);
		
	public:
		static unsigned int	const	_melee_damage;
		static unsigned int	const	_ranged_damage;
		
	public:
		ScavTrap(void);
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		
		ScavTrap & 	operator=(ScavTrap const & rhs);
		
		unsigned int	challengeNewcomer(std::string const & target);
		
		unsigned int 	jumpingAGap(std::string const & target);
		unsigned int 	runningOutOfAmmo(std::string const & target);
		unsigned int 	spottingABadassEnemy(std::string const & target);
};
#endif
