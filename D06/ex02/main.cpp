/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/14 17:05:36 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {public: virtual ~Base() throw();};
Base::~Base() throw(){};

class A: public Base {public: ~A() throw();};
A::~A() throw(){};
class B: public Base {public: ~B() throw();};
B::~B() throw(){};
class C: public Base {public: ~C() throw();};
C::~C() throw(){};

Base * generate(void)
{
	int random = std::rand() % 3;
	
	if (random == 0)
		return static_cast<Base *>(new A());
	else if (random == 1)
		return static_cast<Base *>(new B());
	else
		return static_cast<Base *>(new C());
}

void	identify_from_pointer(Base * p)
{
	if (A *n = dynamic_cast<A *>(p))
		std::cout << 'A' << std::endl;
	else if (B *n = dynamic_cast<B *>(p))
		std::cout << 'B' << std::endl;
	else if (C *n = dynamic_cast<C *>(p))
		std::cout << 'C' << std::endl;
}

void	identify_from_reference(Base & p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << 'A' << std::endl;
	}
	catch(std::bad_cast & e)
	{
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << 'B' << std::endl;
		}
		catch(std::bad_cast & e)
		{
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << 'C' << std::endl;	
			}
			catch(std::bad_cast & e) {}
		}
		
	}
}

int		main(void)
{
	std::srand(std::time(nullptr));
	
	Base * base_p = generate();
	identify_from_pointer(base_p);
	identify_from_reference(*base_p);
	return 0;
}
