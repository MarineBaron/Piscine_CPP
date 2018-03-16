/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:20:36 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/16 12:33:52 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
#endif

template< typename T>
class Array
{
	public:
			class OutOfRangeException: public std::exception
			{
				public:
					OutOfRangeException(void) {};
					~OutOfRangeException(void) throw() {};
					char const	* what(void) const throw() {return "Out of range";};
			};
			
			Array<T>(void): _array(nullptr), _size(0) {};
			
			Array<T>(unsigned int size): _size(size)
			{
				if (!size)
					_array = nullptr;
				else
					_array = new T[size];
			};
			
			Array<T>(Array<T> const & src){*this = src;};
			
			Array<T>	& operator=(Array<T> const & rhs) {
				if (this != &rhs)
				{
					delete _array;
					_size = rhs.size();
					_array = new T[_size];
					
					for (unsigned int i = 0; i < _size; i++)
						_array[i] = rhs._array[i];
				}
				return *this;
			};
			
			~Array<T>(void) throw() {delete _array;};
			
		T			& operator[](unsigned int index) throw(OutOfRangeException)
		{
			if (index >= _size)
				throw (OutOfRangeException());
			return (_array[index]);
		};
		
		unsigned int	size(void) const {return _size;};
		
	private:
		T				* _array;
		unsigned int	_size;
};
