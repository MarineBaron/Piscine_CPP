/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:46:16 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 17:44:21 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
# include <iostream>
# include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
	public:
		TacticalMarine(void);
		~TacticalMarine(void);
		TacticalMarine(TacticalMarine const & src);
		
		TacticalMarine	&operator=(TacticalMarine const & rhs);
		ISpaceMarine	*clone(void) const;
		void			battleCry(void) const;
		void			rangeAttack(void) const;
		void			meleeAttack(void) const;
};
#endif
