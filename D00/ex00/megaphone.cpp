/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 08:50:20 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/05 09:50:30 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	
	if (argc < 2)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			std::cout<<char(toupper(argv[i][j]));
	}
	std::cout<<std::endl;
	return (0);
}
