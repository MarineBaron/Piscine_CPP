/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:55:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 12:38:46 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include <iostream>
# include "Enemy.hpp"

class SuperMutant: public Enemy
{
	public:
		SuperMutant(void);
		SuperMutant(SuperMutant const & src);
		virtual ~SuperMutant(void);
		
		SuperMutant &operator=(SuperMutant const & rhs);
		void		takeDamage(int hp);
};
#endif
