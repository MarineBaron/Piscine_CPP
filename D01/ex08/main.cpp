/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:18:30 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 20:07:48 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main(void)
{
	Human tom("Tom");
	
	tom.action("meleeAttack", "laughing");
	tom.action("rangeAttack", "smiling");
	tom.action("intimidationShout", "sleeping");
	tom.action("sleeping", "sleeping");
	return (0);
}
