/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:20:12 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 14:49:42 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "Brain.hpp"

class Human {
	private:
		Brain const 	_brain;
	public:
	    Human(void);
	    ~Human(void);
		std::string		identify(void) const;
		Brain			getBrain(void) const;
};
#endif
