/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:55:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 09:56:14 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP
# include <iostream>
# include "Victim.hpp"

class Peon: public Victim
{
	public:
		Peon(std::string const name);
		Peon(Peon const & src);
		virtual ~Peon(void);
		
		Peon 				&operator=(Peon const & rhs);
		void				getPolymorphed(void) const;
};
#endif
