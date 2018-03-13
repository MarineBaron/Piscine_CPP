/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:33:46 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/13 10:55:12 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	class	GradeTooHighException: public std::exception
	{
		public:
			GradeTooHighException(void);
			GradeTooHighException(GradeTooHighException const & src);
			~GradeTooHighException(void) throw();
			
			GradeTooHighException	& operator=(GradeTooHighException const & rhs);
			char const				* what(void) const throw();
	};
	class	GradeTooLowException: public std::exception
	{
		public:
			GradeTooLowException(void);
			GradeTooLowException(GradeTooLowException const & src);
			~GradeTooLowException(void) throw();
			
			GradeTooLowException	& operator=(GradeTooLowException const & rhs);
			char const				* what(void) const throw();
	};
	public:
		Bureaucrat(std::string const & name, int grad) throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);
		
		Bureaucrat			& operator=(Bureaucrat const & rhs);
		void				incrementGrade(void) throw(GradeTooLowException);
		void				decrementGrade(void) throw(GradeTooHighException);
		std::string	const	& getName(void) const;
		int					getGrade(void) const;
		void				signForm(Form & form) const;
		void				executeForm(Form & form) const;
	private:
		std::string			_name;
		int					_grade;
};
std::ostream				& operator<<(std::ostream & os, Bureaucrat const & rhs);
#endif
