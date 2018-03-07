/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/07 20:21:11 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
int	parse_number(char **expr, Fixed & result);
int	parse_factors(char **expr, Fixed & result);
int parse_sum(char **expr, Fixed & result);

int	parse_number(char **expr, Fixed & result)
{
	Fixed	n1;
	std::cout << "in number" << std::endl;
	
	while (**expr == ' ')
		(*expr)++;
	if (**expr == '(')
	{
		(*expr)++;
		parse_sum(expr, n1);
		if (**expr == ')')
			(*expr)++;
		result = n1;
		return (1);
	}
	result = (float)atof(*expr);
	return (1);
}

int	parse_factors(char **expr, Fixed & result)
{
	Fixed	n1;
	Fixed	n2;
	char	op;
	
	if (!parse_number(expr, n1))
		return (0);
	while (**expr)
	{
		std::cout << "in factors" << std::endl;
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '*' && op != '/')
		{
			result = n1;
			return (1);
		}
		(*expr)++;
		if (!parse_number(expr, n2))
			return (0);
		if (op == '*')
			n1 = n1 * n2;
		else if (n2.getRawBits() != 0)
			n1 = n1  / n2;
	}
	result = n1;
	return (1);
}

int 	parse_sum(char **expr, Fixed & result)
{
	Fixed	n1;
	Fixed	n2;
	char	op;
	
	
	if (!parse_factors(expr, n1))
		return (0);
	while (**expr)
	{
		std::cout << "in sum" << std::endl;
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '+' && op != '-')
		{
			result = n1;
			return (1);
		}
		(*expr)++;
		if (!parse_factors(expr, n2))
			return (0);
		if (op == '+')
			n1 = n1 + n2;
		else
			n1 = n1 - n2;
	}
	result = n1;
	return (1);
}

int		main(int argc, char **argv)
{
	Fixed result;
	
	if (argc != 2)
	{
		std::cout << "usage: " << argv[0] << " <expr_to_eval>" << std::endl;
		return (1);
	}
	if (!parse_sum(&argv[1], result))
	{
		std::cout << "Error in expression to eval" << std::endl;
		return (1);
	}
	std::cout << argv[1] << " = " << result << std::endl;
	return (0);
}
