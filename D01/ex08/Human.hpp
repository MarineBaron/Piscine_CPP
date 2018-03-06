/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:09:36 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 20:12:23 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <iostream>

struct	s_fn;

class	Human {
	private:
		std::string			_name;
		static struct s_fn	_actions[];
		static int			_actions_nb;
		
		void				meleeAttack(std::string const & target);
		void				rangeAttack(std::string const & target);
		void				intimidationShout(std::string const & target);
	
	public:
							Human(std::string name);
							~Human(void);
	    void				action(std::string const & action_name, std::string const & target);
};

struct	s_fn
{
	std::string	name;
	void		(Human::*fc)(std::string const &);
};
#endif
