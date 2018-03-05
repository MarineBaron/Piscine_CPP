/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:24:10 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/05 20:14:07 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Phonebook::Phonebook(void) {}

Phonebook::~Phonebook(void) {}


int Phonebook::_nb = 0;

void	Phonebook::addEntry(void)
{
	Phonebook::_nb++;
}

void	Phonebook::displayEntries(void) const
{
	int		i;
	int		nb;
	Contact contact;
	
	nb = Phonebook::getNbEntries();
	i = -1;
	while (++i < MAX_ENTRIES)
	{
		contact = this->_entries[i];
		contact.display(0);
	}
}

Contact		Phonebook::getEntry(int	index) const
{
	return (this->_entries[index]);
}

int			Phonebook::getNbEntries(void)
{
	return (Phonebook::_nb);
}

bool		Phonebook::isFull(void)
{
	return (Phonebook::_nb == MAX_ENTRIES);
}
