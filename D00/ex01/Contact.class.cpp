/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:43:28 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 02:11:38 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(){}
Contact::~Contact(){}
void            Contact::setIndex(int i)
{
  this->_index = i;
}
int             Contact::getIndex(void) const
{
  return (this->_index);
}
void           Contact::setFirstname(std::string str)
{
  this->_firstname = str;
}
std::string    Contact::getFirstname(void) const
{
  return (this->_firstname);
}
void           Contact::setLastname(std::string str)
{
  this->_lastname = str;
}
std::string    Contact::getLastname(void) const
{
  return (this->_lastname);
}
void           Contact::setNickname(std::string str)
{
  this->_nickname = str;
}
std::string    Contact::getNickname(void) const
{
  return (this->_nickname);
}
std::string	Contact::getLogin(void) const
{
	return (this->_login);
}
void		Contact::setLogin(std::string str)
{
	this->_login = str;
}
void           Contact::setPostal_address(std::string str)
{
  this->_postal_address = str;
}
std::string    Contact::getPostal_address(void) const
{
  return (this->_postal_address);
}
void           Contact::setEmail_address(std::string str)
{
  this->_email_address = str;
}
std::string    Contact::getEmail_address(void) const
{
  return (this->_email_address);
}
void		Contact::setPhone_number(std::string str)
{
	this->_phone_number = str;
}
std::string	Contact::getPhone_number(void) const
{
	return (this->_phone_number);
}
void		Contact::setBirthday_date(std::string str)
{
	this->_birthday_date = str;
}
std::string	Contact::getBirthday_date(void) const
{
	return (this->_birthday_date);
}
void		Contact::setFavorite_meal(std::string str)
{
	this->_favorite_meal = str;
}
std::string	Contact::getFavorite_meal(void) const
{
	return (this->_favorite_meal);
}
void		Contact::setUnderwear_color(std::string str)
{
	this->_underwear_color = str;
}
std::string	Contact::getUnderwear_color(void) const
{
	return (this->_underwear_color);
}
void		Contact::setDarkest_secret(std::string str)
{
	this->_darkest_secret = str;
}
std::string	Contact::getDarkest_secret(void) const
{
	return (this->_darkest_secret);
}
int           Contact::getNb(void)
{
  return (Contact::_nb);
}
std::string    Contact::setFieldValue(std::string str) const
{
  std::string		buff;

  while (1)
  {
      std::cout << "Enter " << str << " : ";
      if (std::getline(std::cin, buff) && buff.length() > 0)
        return (buff);
      std::cout << "Retry : field can't be empty !!! ";
  }
}
std::string    Contact::getShortFieldValue(std::string str) const
{
  if (str.length() <= Contact::_sht_len)
    return (str);
  str[Contact::_sht_len - 1] = Contact::_sht_char;
  return (str.substr(0, Contact::_sht_len));
}
void          Contact::init(void)
{
  std::string str;

  std::cout << "--- New Contact ---" << std::endl;
  this->setFirstname(this->setFieldValue("Firstname"));
  this->setLastname(this->setFieldValue("Lastname"));
  this->setNickname(this->setFieldValue("Nickname"));
  this->setLogin(this->setFieldValue("Login"));
  this->setPostal_address(this->setFieldValue("Postal Address"));
  this->setEmail_address(this->setFieldValue("Email Address"));
  this->setPhone_number(this->setFieldValue("Phone Number"));
  this->setBirthday_date(this->setFieldValue("Birthday Date"));
  this->setFavorite_meal(this->setFieldValue("Favorite Meal"));
  this->setUnderwear_color(this->setFieldValue("Underwear Color"));
  this->setDarkest_secret(this->setFieldValue("Darkest Secret"));
  Contact::_nb += 1;
  this->setIndex(Contact::_nb);
  if (this->_nb == 1)
    std::cout << "--- There is " << this->_nb << " contact in phonebook." << std::endl;
  else
    std::cout << "--- There are " << this->_nb << " contacts in phonebook." << std::endl;
}

void          Contact::displayFull(void)
{
  std::cout << "---------- Contact n° " << this->getIndex() << std::endl;
  std::cout << "Firstname : " << this->getFirstname() << std::endl;
  std::cout << "Lastname : " << this->getLastname() << std::endl;
  std::cout << "Nickname : " << this->getNickname() << std::endl;
  std::cout << "Login : " << this->getLogin() << std::endl;
  std::cout << "Postal Address : " << this->getPostal_address() << std::endl;
  std::cout << "Email Address : " << this->getEmail_address() << std::endl;
  std::cout << "Phone Number : " << this->getPhone_number() << std::endl;
  std::cout << "Birthday Date : " << this->getBirthday_date() << std::endl;
  std::cout << "Favorite Meal : " << this->getFavorite_meal() << std::endl;
  std::cout << "Underwear Color : " << this->getUnderwear_color() << std::endl;
  std::cout << "Darkest Secret : " << this->getDarkest_secret() << std::endl;
  std::cout << "---------- " << std::endl;

}
void          Contact::displayShort(void)
{
  std::cout << std::setw(Contact::_sht_len) << this->getIndex() << Contact::_sht_sep;
  std::cout << std::setw(Contact::_sht_len) << this->getShortFieldValue(this->getFirstname()) << Contact::_sht_sep;
  std::cout << std::setw(Contact::_sht_len) << this->getShortFieldValue(this->getLastname()) << Contact::_sht_sep;
  std::cout << std::setw(Contact::_sht_len) << this->getShortFieldValue(this->getNickname()) << std::endl;
}
bool           Contact::isFull(void)
{
  return (Contact::_nb == Contact::_nb_max);
}
bool           Contact::isEmpty(void)
{
  return (!Contact::_nb);
}
int Contact::_nb = 0;
const int Contact::_nb_max = 8;
const unsigned int Contact::_sht_len = 10;
const char Contact::_sht_sep = '|';
const char Contact::_sht_char = '.';