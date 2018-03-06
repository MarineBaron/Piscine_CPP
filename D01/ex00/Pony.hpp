/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:03:21 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 10:29:36 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>

class Pony {
	private:
		std::string _name;
		std::string	_color;
		
		std::string	getName(void) const;
		std::string	getColor(void) const;
	public:
	    Pony();
	    ~Pony();
		void		display(void) const;
		void		init(std::string name, std::string color);
};
#endif
