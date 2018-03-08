/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:17:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 16:06:40 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <cmath>

class ScavTrap
{
	private:
		static int					_challenges_nb;
		static unsigned int			(ScavTrap::*_challenges[])(std::string const & target);
		
		static unsigned int	const	_hit_max;
		static unsigned int	const	_energie_max;
		static unsigned int	const	_action_energie_cost;
		static unsigned int	const	_armor_reduction;
		static unsigned int	const	_level_default;

		std::string	_name;
		unsigned int				_hit;
		unsigned int				_energie;
		unsigned int				_level;
		
	public:
		static unsigned int	const	_melee_damage;
		static unsigned int	const	_ranged_damage;
		
	public:
		ScavTrap(void);
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		
		ScavTrap & 	operator=(ScavTrap const & rhs);
		
		void			display(void) const;
		void			setName(std::string const & name);
		std::string		getName(void) const;
		void			meleeAttack(std::string const & target);
		void			rangedAttack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	challengeNewcomer(std::string const & target);
		
		unsigned int 	jumpingAGap(std::string const & target);
		unsigned int 	runningOutOfAmmo(std::string const & target);
		unsigned int 	spottingABadassEnemy(std::string const & target);
		
	private:
		static int		getRandomInt(void);
};
#endif
