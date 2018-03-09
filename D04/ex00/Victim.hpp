/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:55:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 11:37:53 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>

class Victim
{
	public:
		Victim(std::string const name);
		Victim(Victim const & src);
		virtual ~Victim(void);
		
		Victim 				&operator=(Victim const & rhs);
		std::string	const	&getName(void) const;
		virtual void		getPolymorphed(void) const;
	
	protected:
		std::string		_name;
};

std::ostream	&operator<<(std::ostream &os, Victim const & rhs);
#endif
