/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypedString.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:04:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/03 07:14:31 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDSTRING_HPP
# define TYPEDSTRING_HPP
# include <iostream>
# include <string>
# include <cerrno>
# include <cctype>
# include <cstdlib>
# include <limits>
# include <cmath>

class TypedString
{
	public:
		class NoConversionException: public std::exception
		{
			public:
				NoConversionException(void);
				NoConversionException(TypedString const & src);
				~NoConversionException(void) throw();
				char const *what(void) const throw();

				NoConversionException & 	operator=(NoConversionException const & rhs);
		};
		class NonDisplayableException: public std::exception
		{
			public:
				NonDisplayableException(void);
				NonDisplayableException(TypedString const & src);
				~NonDisplayableException(void) throw();
				char const *what(void) const throw();

				NonDisplayableException & 	operator=(NonDisplayableException const & rhs);
		};
		TypedString(std::string const & str);
		TypedString(TypedString const & src);
		~TypedString(void);
		TypedString		& operator=(TypedString const & rhs);

		operator std::string const &(void) const;
		operator char(void) const throw(NoConversionException, NonDisplayableException);
		operator int(void) const throw(NoConversionException);
		operator float(void) const throw(NoConversionException);
		operator double(void) const throw(NoConversionException);

		std::string const	& getData(void) const;
		double			getDouble(void) const;
		int					getPrecision(void) const;
		bool				getImpossible(void) const;

	private:
		std::string		_data;
		double			_double;
		int				_precision;
		bool			_impossible;

		void			setDouble(void);
		void			setPrecision(void);
};
std::ostream	& operator<<(std::ostream & os, TypedString const & str);
#endif
