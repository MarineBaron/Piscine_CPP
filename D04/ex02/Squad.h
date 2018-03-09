/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:46:16 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 17:26:53 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP
# include <iostream>
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad
{
	public:
		Squad(void);
		~Squad(void);
		Squad(Squad const & src);
		
		Squad			&operator=(Squad const & rhs);
		int				getCount(void) const;
		ISpaceMarine	*getUnit(int index);
		int				push(ISpaceMarine *unit);
		
	private:
		int				_unit_count;
		ISpaceMarine	*_unit_first;
};
#endif
