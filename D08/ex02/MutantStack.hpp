/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:00:41 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/04 22:35:24 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <list>
# include <stack>

template< typename T >
class MutantStack: public std::stack<T>
{
public:
  MutantStack(void){};
  ~MutantStack(void){};
  MutantStack(MutantStack const & src){(void)src;};
  MutantStack &operator=(MutantStack const & rhs){(void)rhs; return *this;};

  typedef typename std::list<T>::iterator iterator;
  T         top(void)
  {
    return _stack.front();
  };
  T         size(void)
  {
    return _stack.size();
  };
  iterator  begin(void)
  {
    return _stack.begin();
  };
  iterator  end(void)
  {
    return _stack.end();
  };
  void      push(T value)
  {
    _stack.push_front(value);
  };
  void      pop(void)
  {
    _stack.pop_front();
  };
private:
  std::list<T> _stack;
};
#endif