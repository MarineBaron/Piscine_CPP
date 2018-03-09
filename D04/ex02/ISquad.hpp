/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:46:16 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 16:57:05 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP
# include <iostream>
# include "ISpaceMarine.hpp"

class ISquad
{
	public:
		virtual ISquad(void) {};

		virtual int				getCount(void) const = 0;
		virtual ISpaceMarine	*getUnit(int index) const = 0;
		virtual int				push(ISpaceMarine *unit) = 0;
};
#endif
