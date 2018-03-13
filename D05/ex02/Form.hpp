/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:33:46 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/13 11:48:30 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		class	GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const & src);
				~GradeTooHighException(void) throw();
				
				GradeTooHighException	& operator=(GradeTooHighException const & rhs);
				char const				* what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const & src);
				~GradeTooLowException(void) throw();
				
				GradeTooLowException	& operator=(GradeTooLowException const & rhs);
				char const				* what() const throw();
		};
		class	FormNotSignedException: public std::exception
		{
			public:
				FormNotSignedException(void);
				FormNotSignedException(FormNotSignedException const & src);
				~FormNotSignedException(void) throw();
				
				FormNotSignedException	& operator=(FormNotSignedException const & rhs);
				char const				* what() const throw();
		};
		
		
		Form(std::string const & name, int grade_to_sign, int grade_to_exe)
			throw(GradeTooHighException, GradeTooLowException);
		Form(Form const & src);
		virtual ~Form(void);
		
		Form			& operator=(Form const & rhs);
		std::string	const	& getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExe(void) const;
		bool				isSigned(void) const;
		void				beSigned(Bureaucrat const & bureaucrat) throw(GradeTooLowException);
		virtual void		action(void) const = 0;
		void				execute(Bureaucrat const & bureaucrat) throw(FormNotSignedException, GradeTooLowException);
		
	private:
		std::string			_name;
		int					_grade_to_sign;
		int					_grade_to_exe;
		bool				_is_signed;
};
std::ostream				& operator<<(std::ostream & os, Form const & rhs);
#endif
