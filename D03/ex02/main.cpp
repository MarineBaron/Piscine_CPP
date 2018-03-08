/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/08 16:02:08 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	std::string		userNames[5] = {"bob", "jim", "mark", "pablo", "albert"};
	FragTrap 		fusers[5] = {
		userNames[0] + "f",
		userNames[1] + "f",
		userNames[2] + "f",
		userNames[3] + "f",
		userNames[4] + "f"};
	ScavTrap 		susers[5] = {
		userNames[0] + "s",
		userNames[1] + "s",
		userNames[2] + "s",
		userNames[3] + "s",
		userNames[4] + "s"};
	int				i;
	
	
	std::cout  << "DISPLAY BEGIN FrapTrap------------" << std::endl;
	i = -1;
	while (++i < 5)
		fusers[i].display();
	std::cout  << "------------" << std::endl;
		
	std::cout  << "------------" << std::endl;
	std::cout << ">>> bob meleeAttack jim" << std::endl << "------------" << std::endl;
	fusers[0].meleeAttack(userNames[1]);
	fusers[1].takeDamage(FragTrap::_melee_damage);
	std::cout  << "------------" << std::endl;
	std::cout << ">>> bob rangedAttack mark" << std::endl << "------------" << std::endl;
	fusers[0].rangedAttack(userNames[2]);
	fusers[2].takeDamage(FragTrap::_ranged_damage);
	std::cout  << "------------" << std::endl;
	i = -1;
	while (++i < 5)
	{
		std::cout << ">>> mark randedAttack pablo" << std::endl << "------------" << std::endl;
		fusers[4].takeDamage(fusers[3].vaulthunter_dot_exe(userNames[4]));
		std::cout  << "------------" << std::endl;
	}
	i = -1;
	while (++i < 5)
	{
		std::cout << ">>> albert randedAttack bob" << std::endl << "------------" << std::endl;
		fusers[4].takeDamage(fusers[4].vaulthunter_dot_exe(userNames[0]));
		std::cout  << "------------" << std::endl;
	}
	std::cout  << "DISPLAY END ------------" << std::endl;
	
	
	i = -1;
	while (++i < 5)
		susers[i].display();
	std::cout  << "------------" << std::endl;
	std::cout  << "DISPLAY BEGIN ScavTrap------------" << std::endl;
	i = -1;
	while (++i < 5)
		susers[i].display();
	std::cout  << "------------" << std::endl;
		
	std::cout  << "------------" << std::endl;
	std::cout << ">>> bob meleeAttack jim" << std::endl << "------------" << std::endl;
	susers[0].meleeAttack(userNames[1]);
	susers[1].takeDamage(FragTrap::_melee_damage);
	std::cout  << "------------" << std::endl;
	std::cout << ">>> bob rangedAttack mark" << std::endl << "------------" << std::endl;
	susers[0].rangedAttack(userNames[2]);
	susers[2].takeDamage(FragTrap::_ranged_damage);
	std::cout  << "------------" << std::endl;
	i = -1;
	while (++i < 5)
	{
		std::cout << ">>> mark randedChallenge pablo" << std::endl << "------------" << std::endl;
		susers[3].challengeNewcomer(userNames[4]);
		std::cout  << "------------" << std::endl;
	}
	i = -1;
	while (++i < 5)
	{
		std::cout << ">>> albert randedAttack bob" << std::endl << "------------" << std::endl;
		susers[4].challengeNewcomer(userNames[0]);
		std::cout  << "------------" << std::endl;
	}
	std::cout  << "DISPLAY END ------------" << std::endl;
	i = -1;
	while (++i < 5)
		susers[i].display();
	std::cout  << "------------" << std::endl;
	return 0;
}
