/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/03 07:47:08 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

struct	Data
{
	std::string	s1;
	int			n;
	std::string	s2;
};

char	getRandomChar(void)
{
	int random = static_cast<int>(static_cast<double>(std::rand())
		* 62.0 / static_cast<double>(RAND_MAX));

	if (random < 26)
		return ('a' + random);
	if (random < 52)
		return ('A' + random - 26);
	return ('0' + random - 52);
}

char	getRandomInt(void)
{
	return (std::rand());
}

void 	display(void * raw)
{
	char * cs = reinterpret_cast<char *>(raw);
	int * is = reinterpret_cast<int *>(raw);
	int		i = -1;

	while (++i < 8)
		std::cout << cs[i];
	std::cout << std::endl;
	std::cout << is[2] << std::endl;
	i = 11;
	while (++i < 20)
		std::cout << cs[i];
	std::cout << std::endl;
}

void 	displayData(Data *data)
{
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
}


void	* serialize(void)
{
	char	* datas = new char[20];
	int		i = -1;

	while (++i < 8)
		datas[i] = getRandomChar();
	*(reinterpret_cast<int *>(&datas[8])) =  getRandomInt();
	i = 11;
	while (++i < 20)
		datas[i] = getRandomChar();

	return (static_cast<void *>(datas));
}

Data	* deserialize(void * raw)
{
	Data	* data = new Data();

	data->s1.assign(reinterpret_cast<char *>(raw), 8);
	data->n = *(reinterpret_cast<int *>(&reinterpret_cast<char *>(raw)[8]));
	data->s2.assign(&reinterpret_cast<char *>(raw)[12], 8);
	return (data);
}

int		main(void)
{
	std::srand(std::time(NULL));

	void *p = serialize();
	display(p);
	Data * data = deserialize(p);
	displayData(data);

	delete data;
	return 0;
}
