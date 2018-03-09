/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:55:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 14:36:13 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>

class Enemy
{
	public:
		Enemy(int hits, std::string const & type);
		Enemy(Enemy const & src);
		virtual ~Enemy(void);
		
		Enemy 					&operator=(Enemy const & rhs);
		std::string	const	&getType(void) const;
		int					getHP(void) const;
		virtual void		takeDamage(int hp);
	
	private:
		int				_hp;
		std::string		_type;
};
#endif
