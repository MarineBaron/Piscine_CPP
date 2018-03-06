/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:44:08 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/06 02:01:30 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <iostream>
# include <iomanip>
#include <string>
#include <limits>

class Contact {
  public:
    Contact();
    ~Contact();
    void          init(void);
    void          displayFull(void);
    void          displayShort(void);
    static int    getNb(void);
    static bool   isFull(void);
    static bool   isEmpty(void);
  private:
    int           _index;
    std::string   _firstname;
    std::string   _lastname;
    std::string   _nickname;
		std::string   _login;
    std::string   _postal_address;
    std::string   _email_address;
    std::string   _phone_number;
    std::string   _birthday_date;
    std::string   _favorite_meal;
    std::string   _underwear_color;
    std::string   _darkest_secret;
    void          setIndex(int i);
    int           getIndex(void) const;
    void          setFirstname(std::string str);
    std::string   getFirstname(void) const;
    void          setLastname(std::string str);
    std::string   getLastname(void) const;
    void          setNickname(std::string str);
    std::string   getNickname(void) const;
    std::string	  getLogin(void) const;
    void		      setLogin(std::string str);
    void          setPostal_address(std::string str);
    std::string   getPostal_address(void) const;
    void          setEmail_address(std::string str);
    std::string   getEmail_address(void) const;
    void		      setPhone_number(std::string str);
    std::string	  getPhone_number(void) const;
    void		      setBirthday_date(std::string str);
    std::string	  getBirthday_date(void) const;
    void		      setFavorite_meal(std::string str);
    std::string	  getFavorite_meal(void) const;
    void		      setUnderwear_color(std::string str);
    std::string	  getUnderwear_color(void) const;
    void		      setDarkest_secret(std::string str);
    std::string	  getDarkest_secret(void) const;
    std::string   setFieldValue(std::string str) const;
    std::string   getShortField(std::string str) const;
    std::string   getShortFieldValue(std::string str) const;
    static int    _nb;
    static const int  _nb_max;
    static const unsigned int  _sht_len;
    static const char  _sht_sep;
    static const char  _sht_char;
};
#endif
