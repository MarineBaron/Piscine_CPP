/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:06:16 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/04 22:24:59 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include <iostream>
# include <stack>

int   main(void)
{
  MutantStack<int> ms;

  ms.push(2);
  ms.push(10);

  std::cout << "Top :" <<ms.top() << std::endl;
  std::cout << "Size :" << ms.size() << std::endl;

  ms.push(3);
  ms.push(10);
  ms.push(30);
  ms.push(25);
  ms.push(32);
  ms.push(0);

  MutantStack<int>::iterator it = ms.begin();
  MutantStack<int>::iterator ite = ms.end();

  ++it;
  --it;
  std::cout << "--- All list ---"  << std::endl;
  while(it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }

  std::cout << "--- All list after pop ---"  << std::endl;
  ms.pop();
  it = ms.begin();
  while(it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }

  std::cout << "--- Create new from ---"  << std::endl;
  std::stack<int> s(ms);
  return 0;
}