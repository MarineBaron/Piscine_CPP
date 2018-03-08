/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:17:40 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 17:28:41 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap
{
	private:
		static unsigned int	const	_hit_max;
		static unsigned int	const	_energie_max;
		static unsigned int	const	_action_energie_cost;
		static unsigned int	const	_armor_reduction;
		static unsigned int	const	_level_default;
		
	public:
		static unsigned int	const	_melee_damage;
		static unsigned int	const	_ranged_damage;
		
	public:
		NinjaTrap(void);
		NinjaTrap(std::string const name);
		NinjaTrap(NinjaTrap const & src);
		~NinjaTrap(void);
		
		NinjaTrap & 	operator=(NinjaTrap const & rhs);
		
		void			ninjaShoebox(NinjaTrap & src);
		void			ninjaShoebox(FragTrap & src);
		void			ninjaShoebox(ScavTrap & src);
};
#endif
