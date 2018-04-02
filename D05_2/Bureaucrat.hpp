/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:27:12 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/01 23:49:44 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
  class GradeTooHighException: public std::exception
  {
    public:
      GradeTooHighException(void);
      GradeTooHighException(GradeTooHighException const & src);
      ~GradeTooHighException(void) throw();

      GradeTooHighException & operator=(GradeTooHighException const & src);
      char const            * what(void) const throw();
  };
  class GradeTooLowException: public std::exception
  {
    public:
      GradeTooLowException(void);
      GradeTooLowException(GradeTooLowException const & src);
      ~GradeTooLowException(void) throw();

      GradeTooLowException & operator=(GradeTooLowException const & src);
      char const            * what(void) const throw();
  };

    public:
      Bureaucrat(std::string const & name, int grade)
          throw(GradeTooHighException, GradeTooLowException);
      Bureaucrat(Bureaucrat const & src);
      ~Bureaucrat( void);

      Bureaucrat            & operator=(Bureaucrat const & src);
      std::string const     & getName(void) const;
      int                   getGrade(void) const;
      void                  incrementGrade(void)
                              throw(GradeTooHighException);
      void                  decrementGrade(void)
                              throw(GradeTooLowException);

    private:
      Bureaucrat(void);

      std::string         _name;
      int                 _grade;
      static int const     lowest;
      static int const     highest;
};
std::ostream                   & operator<<(std::ostream & os, Bureaucrat const & rhs);
#endif