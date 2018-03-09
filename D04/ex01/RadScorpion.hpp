/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:55:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 12:56:59 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include <iostream>
# include "Enemy.hpp"

class RadScorpion: public Enemy
{
	public:
		RadScorpion(void);
		RadScorpion(RadScorpion const & src);
		virtual ~RadScorpion(void);
		
		RadScorpion &operator=(RadScorpion const & rhs);
		void		takeDamage(int hp);
};
#endif
