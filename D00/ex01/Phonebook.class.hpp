/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:25:30 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/05 21:13:52 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# define MAX_ENTRIES 8
#include "Contact.class.hpp"

class Phonebook
{
private:
	static int	_nb;
	Contact		*_entries[MAX_ENTRIES];
public:
    Phonebook();
    ~Phonebook();
	void		addEntry(void);
	Contact		getEntry(int	index) const;
	void		displayEntries(void) const;
	static int	getNbEntries(void);
	static bool	isFull();
};
#endif
