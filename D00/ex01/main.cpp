/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:31:39 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 01:38:35 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

void search(Contact phonebook[])
{
  int   i;
  int   nb;

  nb = Contact::getNb();
  i = -1;
  while (++i < nb)
    phonebook[i].displayShort();
  while (1)
  {
    std::cout << "Enter a contact's index to show details (between 1 and " << nb << ") : ";
    i = std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (i > 48 && i < nb + 49)
    {
      phonebook[i - 49].displayFull();
      return ;
    }
      std::cout << "I didn't understand... ";
  }
}

int main()
{
  Contact phonebook[8];
  std::string       command;

  while (1)
  {
    std::cout << "Enter a command : ADD, SEARCH or EXIT : ";
    std::getline(std::cin, command);
    if (command == "EXIT")
    {
      std::cout << "Bye bye !!! " << std::endl;
      return (0);
    }
    else if (command == "ADD")
    {
      if (Contact::isFull())
        std::cout << "You can't add a contact : the phonebook is full !!! " << std::endl;
      else
        phonebook[Contact::getNb()].init();
    }
    else if (command == "SEARCH")
    {
      if (Contact::isEmpty())
        std::cout << "Nothing to show : the phonebook is empty !!! " << std::endl;
      else
        search(phonebook);
    }
    else
      std::cout << "I didn't understand... ";
  }
  return (1);
}