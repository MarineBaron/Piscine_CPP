/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:46:16 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 17:09:31 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP
# include <iostream>

class ISpaceMarine
{
	public:
		virtual ISpaceMarine(void) {};

		virtual ISpaceMarine	*clone(void) const = 0;
		virtual void			battleCry(void) const = 0;
		virtual void			rangeAttack(void) const = 0;
		virtual void			meleeAttack(void) const = 0;
};
#endif
