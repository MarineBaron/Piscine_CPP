/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:26:39 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/05 21:32:11 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdio.h>
#include "Contact.class.hpp"
#include "Phonebook.class.hpp"

std::string	get_input(void)
{
	std::string		buff;
	
	if (std::getline(std::cin, buff))
		return (buff);
	std::cout<<"Error in cin"<<std::endl;
	exit(-1);
}

std::string	get_field_value(std::string field_name) {
	std::string str;
	int			ok;
	
	ok = 1;
	while (ok)
	{
		std::cout << "Enter contact's "<< field_name << " : ";
		str = get_input();
		ok = !(str.length());
		if (ok)
			std::cout << ">>> The field can't be empty !!! <<<" << std::endl;
	}
	printf("%s %s\n", field_name.c_str(), str.c_str());
	return (str);
}

void		contact_add(Phonebook phonebook)
{
	int		index;
	
	index = Phonebook::getNbEntries();
	std::cout << "--> Enter contact's attributes : " << std::endl;
	
	phonebook.getEntry(index).setIndex(index + 1);
	printf("index%d\n", index + 1);
	phonebook.getEntry(index).setFirstname(get_field_value("Firstname"));
	phonebook.getEntry(index).setLastname(get_field_value("Lastname"));
	phonebook.getEntry(index).setNickname(get_field_value("Nickname"));
	phonebook.getEntry(index).setPostal_address(get_field_value("Postal Address"));
	phonebook.getEntry(index).setEmail_address(get_field_value("Email Address"));
	phonebook.getEntry(index).setBirthday_date(get_field_value("Birthday Date"));
	phonebook.getEntry(index).setFavorite_meal(get_field_value("Favorite Meal"));
	phonebook.getEntry(index).setUnderwear_color(get_field_value("Underwear Color"));
	phonebook.getEntry(index).setDarkest_secret(get_field_value("Darkest Secret"));
	
	phonebook.getEntry(index).display(1);
	std::cout << "--> Contact n°" << (index + 1) << " has been added." << std::endl;
	phonebook.addEntry();
}


void		contact_search(Phonebook phonebook)
{
	int		ok;
	int		nb;
	int		index;
	
	nb = Phonebook::getNbEntries();
	phonebook.displayEntries();
	ok = 0;
	while (!ok)
	{
		std::cout << "Enter a contact's index (between 1 and " << nb <<"): ";
		index = std::stoi(get_input());
		if (index < 0 || index > nb - 1)
		{
			phonebook.getEntry(index).display(1);
			ok = 1;
		}
		else
			std::cout << "Bad entry : Try again !!! " << std::endl;
	}
}

int			main(void)
{
	Phonebook		phonebook;
	std::string		command;
	int				ok;
	
	ok = 1;
	while (ok)
	{
		std::cout << "Enter a command(ADD / SEARCH / EXIT) : ";
		command = get_input();
		if (command == "EXIT")
		{
			std::cout<<"Bye bye !"<<std::endl;
			ok = 0;
		}
		else if (command == "ADD")
		{
			if (Phonebook::isFull())
				std::cout << "The phonebook is full ! You can't ADD another contact..." << std::endl;
			else
				contact_add(phonebook);
		}
		else if (command == "SEARCH")
		{
			if (!Phonebook::getNbEntries())
				std::cout<<"The phonebook is empty ! Nothing to show..."<<std::endl;
			else
				contact_search(phonebook);
		}
		else
			std::cout<<"Error ! Try again !"<<std::endl;
	}
	return (0);
}
