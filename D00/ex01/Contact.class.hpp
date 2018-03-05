/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:24:46 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/05 19:39:00 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <iostream>
# include <string>
# include <iomanip>
# define PUT_SEP '|'
# define PUT_MAX 10
# define PUT_LAST '.'

class Contact {
	private:
		int			_index;
		std::string	_firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _login;
		std::string _postal_address;
		std::string _email_address;
		std::string _phone_number;
		std::string _birthday_date;
		std::string _favorite_meal;
		std::string _underwear_color;
		std::string _darkest_secret;
		void		display_field(std::string str, int full) const;
		
	public:
	    Contact(void);
	    ~Contact(void);
		int			getIndex(void) const;
		void		setIndex(int index);
		std::string	getFirstname(void) const;
		void		setFirstname(std::string str);
		std::string	getLastname(void) const;
		void		setLastname(std::string str);
		std::string	getNickname(void) const;
		void		setNickname(std::string str);
		std::string	getLogin(void) const;
		void		setLogin(std::string str);
		std::string	getPostal_address(void) const;
		void		setPostal_address(std::string str);
		std::string	getEmail_address(void) const;
		void		setEmail_address(std::string str);
		std::string	getPhone_number(void) const;
		void		setPhone_number(std::string str);
		std::string	getBirthday_date(void) const;
		void		setBirthday_date(std::string str);
		std::string	getFavorite_meal(void) const;
		void		setFavorite_meal(std::string str);
		std::string	getUnderwear_color(void) const;
		void		setUnderwear_color(std::string str);
		std::string	getDarkest_secret(void) const;
		void		setDarkest_secret(std::string str);
		std::string	truncField(std::string str) const;
		void		display(int full);
};
#endif /* CONTACT_CLASS_HPP */
