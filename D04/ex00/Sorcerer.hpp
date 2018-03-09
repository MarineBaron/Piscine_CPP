/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:55:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 11:37:26 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
	public:
		Sorcerer(std::string const name, std::string const title);
		Sorcerer(Sorcerer const & src);
		virtual ~Sorcerer(void);
		
		Sorcerer 			&operator=(Sorcerer const & rhs);
		std::string	const	&getName(void) const;
		std::string	const	&getTitle(void) const;
		void				polymorph(Victim const & victim) const;
	
	private:
		std::string		_name;
		std::string		_title;
};

std::ostream	&operator<<(std::ostream &os, Sorcerer const & rhs);
#endif
