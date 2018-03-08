/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:17:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 16:40:04 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <cmath>

class ClapTrap
{
	private:
		static unsigned int	const	_hit_max;
		static unsigned int	const	_energie_max;
		static unsigned int	const	_action_energie_cost;
		static unsigned int	const	_armor_reduction;
		static unsigned int	const	_level_default;

	protected:
		std::string	_name;
		unsigned int				_hit;
		unsigned int				_energie;
		unsigned int				_level;
		
	public:
		static unsigned int	const	_melee_damage;
		static unsigned int	const	_ranged_damage;
		
	public:
		ClapTrap(void);
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		
		ClapTrap & 	operator=(ClapTrap const & rhs);
		
		void			display(void) const;
		void			setName(std::string const & name);
		std::string		getName(void) const;
		void			meleeAttack(std::string const & target);
		void			rangedAttack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	protected:
		static int		getRandomInt(int const nb);
};
#endif
