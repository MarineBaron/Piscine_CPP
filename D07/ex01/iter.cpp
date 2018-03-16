/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:34:08 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/16 12:12:43 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T>
void	iter(T *array, unsigned int len, void (*f)(T))
{
	for (unsigned int i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

template< typename T>
void	display(T elt)
{
	std::cout << elt << std::endl;
}


int		main(void)
{
	char cs[] = {'a', 'b', 'c'};
	int	is[] = {12, 15, 0};
	std::string	ss[] = {"coucou", "bonjour", "au revoir"};
	
	::iter(cs, 3, ::display);
	::iter(is, 3, ::display);
	::iter(ss, 3, ::display);
	return 0;
}
	
