/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:33:46 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/12 11:57:36 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	class	GradeTooHighException: public Bureaucrat::GradeTooHighException::GradeTooHighException
	{
		public:
			GradeTooHighException(std::string const & type);
			GradeTooHighException(GradeTooHighException const & src);
			~GradeTooHighException(void) throw();
			
			GradeTooHighException	& operator=(GradeTooHighException const & rhs);
			std::string	const		& geGradeType(void) const;
			char const				* what() const throw();
		private:
			std::string			_grad_type;
	};
	class	GradeTooLowException: public Bureaucrat::GradeTooLowException::GradeTooHighException
	{
		public:
			GradeTooLowException(std::string const & _grade_type);
			GradeTooLowException(GradeTooLowException const & src);
			~GradeTooLowException(void) throw();
			
			GradeTooLowException	& operator=(GradeTooLowException const & rhs);
			std::string	const		& geGradeType(void) const;
			char const				* what() const throw();
		private:
			std::string			_grad_type;
	};
	public:
		Form(std::string const & name, int grad) throw(GradeTooHighException, GradeTooLowException);
		Form(Form const & src);
		~Form(void);
		
		Form			& operator=(Form const & rhs);
		std::string	const	& getName(void) const;
		int	const			& getGradeToSign(void) const;
		int	const			& getGradeToExe(void) const;
		void				beSigned(Bureaucrat const & bureaucrat) throw(GradeTooLowException);
	private:
		std::string			_name;
		int					_grade_to_sign;
		int					_grade_to_exe;
		bool				_is_signed;
};
std::ostream				& operator<<(std::ostream & os, Form const & rhs);
#endif
