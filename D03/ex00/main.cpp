/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 15:33:32 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap	*getUserByName(FragTrap users[], int users_nb, std::string name)
{
	int		i;
	
	i = -1;
	while (++i < users_nb)
	{
		if (users[i].getName() == name)
			return (&users[i]);
	}
	return (NULL);
}

int		main(void)
{
	std::string		userNames[5] = {"bob", "jim", "mark", "pablo", "albert"};
	FragTrap 		users[5] = {userNames[0], userNames[1], userNames[2], userNames[3], userNames[4]};
	int				i;
	
	
	std::cout  << "DISPLAY BEGIN ------------" << std::endl;
	i = -1;
	while (++i < 5)
		users[i].display();
	std::cout  << "------------" << std::endl;
		
	std::cout  << "------------" << std::endl;
	std::cout << ">>> bob meleeAttack jim" << std::endl << "------------" << std::endl;
	users[0].meleeAttack(userNames[1]);
	users[1].takeDamage(FragTrap::_melee_damage);
	std::cout  << "------------" << std::endl;
	std::cout << ">>> bob rangedAttack mark" << std::endl << "------------" << std::endl;
	users[0].rangedAttack(userNames[2]);
	users[2].takeDamage(FragTrap::_ranged_damage);
	std::cout  << "------------" << std::endl;
	i = -1;
	while (++i < 5)
	{
		std::cout << ">>> mark randedAttack pablo" << std::endl << "------------" << std::endl;
		users[4].takeDamage(users[3].vaulthunter_dot_exe(userNames[4]));
		std::cout  << "------------" << std::endl;
	}
	i = -1;
	while (++i < 5)
	{
		std::cout << ">>> albert randedAttack bob" << std::endl << "------------" << std::endl;
		users[4].takeDamage(users[4].vaulthunter_dot_exe(userNames[0]));
		std::cout  << "------------" << std::endl;
	}
	std::cout  << "DISPLAY END ------------" << std::endl;
	i = -1;
	while (++i < 5)
		users[i].display();
	std::cout  << "------------" << std::endl;
	return 0;
}
