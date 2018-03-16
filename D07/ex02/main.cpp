/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:34:08 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/16 13:56:07 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

int		main(void)
{
	unsigned int	len;
	
	Array<int> tab;
	try
	{
		std::cout << tab[0] << std::endl;
		std::cout << "-----> Aff tab[0] (does never appears !)" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "----> Error on tab[0] :" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
	Array<int> tab2(5);
	len = tab2.size();
	std::cout << "----> tab2 size :" << len << std::endl;
	std::cout << "----> Aff tab2 :" << std::endl;
	for (unsigned int i = 0; i < len; i++)
	{
		tab2[i] = static_cast<int>(i);
		try
		{
			std::cout << tab2[i] << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	Array<int> tab3 = tab2;
	std::cout << "----> Aff tab3 (after assignation) :" << std::endl;
	for (unsigned int i = 0; i < len; i++)
	{
		try
		{
			std::cout << tab3[i] << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	tab2[1] = 0;
	tab3[2] = 0;
	std::cout << "----> Aff tab3 & tab2 (after chage tab3[1]) :" << std::endl;
	for (unsigned int i = 0; i < len; i++)
	{
		try
		{
			std::cout << tab2[i] << " " << tab3[i] << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	Array<int> tab4(tab2);
	std::cout << "----> Aff tab4 (after copy) :" << std::endl;
	for (unsigned int i = 0; i < len; i++)
	{
		try
		{
			std::cout << tab4[i] << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	tab2[1] = 1;
	tab4[2] = 0;
	std::cout << "----> Aff tab4 & tab2 (after chage tab5[1]) :" << std::endl;
	for (unsigned int i = 0; i < len; i++)
	{
		try
		{
			std::cout << tab2[i] << " " << tab4[i] << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
