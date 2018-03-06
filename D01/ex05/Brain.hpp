/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:59:23 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 14:47:07 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <sstream>
#include <string>


class Brain {
	private:
		std::string		_address;
	public:
	    Brain(void);
	    ~Brain(void);
		std::string		identify(void) const;
};
#endif
