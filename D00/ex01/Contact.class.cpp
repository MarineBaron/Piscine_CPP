/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:21:01 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/05 21:10:14 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <stdio.h>

Contact::Contact(void)  {
	this->_index = 0;
	this->_lastname = "";
	this->_firstname = "";
	this->_nickname = "";
	this->_login = "";
	this->_postal_address = "";
	this->_email_address = "";
	this->_phone_number = "";
	this->_birthday_date = "";
	this->_favorite_meal = "";
	this->_underwear_color = "";
	this->_darkest_secret = "";
	return ;
}

Contact::~Contact(void) {
	return ;
}

int			Contact::getIndex(void) const
{
	printf("Contact::getIndex:%d\n", this->_index);
	return this->_index;
}
void		Contact::setIndex(int index)
{
	printf("Contact::setIndexindex:%d\n", index);
	this->_index = index;
}
std::string	Contact::getFirstname(void) const
{
	return (this->_firstname);
}
void		Contact::setFirstname(std::string str)
{
	this->_firstname = str;
}
std::string	Contact::getLastname(void) const
{
	return (this->_lastname);
}
void		Contact::setLastname(std::string str)
{
	this->_lastname = str;
}
std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}
void		Contact::setNickname(std::string str)
{
	this->_nickname = str;
}
void		Contact::setLogin(std::string str)
{
	this->_login = str;
}
std::string	Contact::getLogin(void) const
{
	return (this->_login);
}
std::string	Contact::getPostal_address(void) const
{
	return (this->_postal_address);
}
void		Contact::setPostal_address(std::string str)
{
	this->_postal_address = str;
}
std::string	Contact::getEmail_address(void) const
{
	return (this->_email_address);
}
void		Contact::setEmail_address(std::string str)
{
	this->_email_address = str;
}
std::string	Contact::getPhone_number(void) const
{
	return (this->_phone_number);
}
void		Contact::setPhone_number(std::string str)
{
	this->_phone_number = str;
}
std::string	Contact::getBirthday_date(void) const
{
	return (this->_birthday_date);
}
void		Contact::setBirthday_date(std::string str)
{
	this->_birthday_date = str;
}
std::string	Contact::getFavorite_meal(void) const
{
	return (this->_favorite_meal);
}
void		Contact::setFavorite_meal(std::string str)
{
	this->_favorite_meal = str;
}
std::string	Contact::getUnderwear_color(void) const
{
	return (this->_underwear_color);
}
void		Contact::setUnderwear_color(std::string str)
{
	this->_underwear_color = str;
}
std::string	Contact::getDarkest_secret(void) const
{
	return (this->_darkest_secret);
}
void		Contact::setDarkest_secret(std::string str)
{
	this->_darkest_secret = str;
}
std::string	Contact::truncField(std::string str) const
{
	std::string sub;
	
	if (str.length() <= PUT_MAX)
		return (str);
	sub = str.substr(0, PUT_MAX);
	sub[PUT_MAX - 1] = PUT_LAST;
	return (sub);
}
void		Contact::display(int full)
{
	if (!full)
	{
		std::cout << std::setw(10) << this->getIndex() << PUT_SEP;
		std::cout << std::setw(10) << this->truncField(this->getFirstname()) << PUT_SEP;
		std::cout << std::setw(10) << this->truncField(this->getLastname()) << PUT_SEP;
		std::cout << std::setw(10) << this->truncField(this->getNickname()) << std::endl;
	}
	else
	{
		std::cout << "Index : " << this->getIndex() << std::endl;
		std::cout << "Fistname : " << this->getFirstname() << std::endl;
		std::cout << "Lastname : " << this->getLastname() << std::endl;
		std::cout << "Nickname : " << this->getNickname() << std::endl;
		std::cout << "Postal Address : " << this->getPostal_address() << std::endl;
		std::cout << "Email Address : " << this->getEmail_address() << std::endl;
		std::cout << "Phone Number : " << this->getPhone_number() << std::endl;
		std::cout << "Birthday Date : " << this->getBirthday_date() << std::endl;
		std::cout << "Favorite Meal : " << this->getFavorite_meal() << std::endl;
		std::cout << "Underwear Color : " << this->getUnderwear_color() << std::endl;
		std::cout << "Darkest Secret : " << this->getDarkest_secret() << std::endl;
	}
}
