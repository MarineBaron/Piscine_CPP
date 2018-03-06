/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:13:25 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 20:16:33 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(std::string name) : _name(name)
{
	std::cout << "Human is constructed." << std::endl;
}
Human::~Human(void)
{
	std::cout << "Human is destructed." << std::endl;
}
void	Human::meleeAttack(std::string const & target)
{
	std::cout << "Member function 'meleeAttack' called on '" << this->_name <<  "' with '" << target << "' param." << std::endl;
}
void	Human::rangeAttack(std::string const & target)
{
	std::cout << "Member function 'rangeAttack' called on '" << this->_name <<  "' with '" << target << "' param." << std::endl;
}
void	Human::intimidationShout(std::string const & target)
{
	std::cout << "Member function 'intimidationShout' called on '" << this->_name <<  "' with '" << target << "' param." << std::endl;
}
void	Human::action(std::string const & action_name, std::string const & target)
{
	int		i;
	
	i = -1;
	while (++i < Human::_actions_nb)
	{
		if (Human::_actions[i].name == action_name)
		{
			(this->*_actions[i].fc)(target);
			return ;
		}
	}
	if (i == 3)
		std::cout << action_name << " is not authorized" << std::endl;
}
int			Human::_actions_nb = 3;
struct s_fn	Human::_actions[] = {
				{"meleeAttack", &Human::meleeAttack}, 
				{"rangeAttack", &Human::rangeAttack}, 
				{"intimidationShout", &Human::intimidationShout}};
