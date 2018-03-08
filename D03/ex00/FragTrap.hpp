/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:17:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 15:30:12 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <cmath>

class FragTrap
{
	private:
		static int					_attacks_nb;
		static unsigned int			(FragTrap::*_attacks[])(std::string const & target);
		
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
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);
		
		FragTrap & 	operator=(FragTrap const & rhs);
		
		void			display(void) const;
		void			setName(std::string const & name);
		std::string		getName(void) const;
		void			meleeAttack(std::string const & target);
		void			rangedAttack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	vaulthunter_dot_exe(std::string const & target);
		
		unsigned int 	torgueFiesta(std::string const & target);
		unsigned int 	pirateShipMode(std::string const & target);
		unsigned int 	clapInTheBox(std::string const & target);
		unsigned int 	gunWizzard(std::string const & target);
		unsigned int 	laserInferno(std::string const & target);
		
	private:
		static int		getRandomInt(void);
};
#endif
