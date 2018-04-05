
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include "CastString.hpp"
#include <cerrno>

CastString::ImpossibleException::ImpossibleException(void){}
CastString::ImpossibleException::~ImpossibleException(void) throw(){}
CastString::ImpossibleException::ImpossibleException(ImpossibleException const & src)
{
  (void)src;
}
CastString::ImpossibleException &CastString::ImpossibleException::operator=(CastString::ImpossibleException const & rhs)
{
  (void)rhs;
  return *this;
}
char const          * CastString::ImpossibleException::what(void) const throw()
{
  return "impossible";
}

CastString::CastString(void) {}
CastString::~CastString(void) {}
CastString::CastString(std::string const & str)
{
  _data = str;
}
CastString::CastString(CastString const & src)
{
  *this = src;
}
CastString              & CastString::operator=(CastString const & rhs)
{
  _data = rhs.getData();
  return *this;
}
std::string             CastString::getData(void) const
{
  return _data;
}
                        CastString::operator  std::string const &(void) throw(ImpossibleException)
{
  return _data;
}
                        CastString::operator  char(void) const throw(ImpossibleException)
{
  char	n = static_cast<char>(atoi(_data.c_str()));
	if (errno)
		throw (ImpossibleException());
  return n;
}
                        CastString::operator  int(void) const throw(ImpossibleException)
{
  int	n = std::atoi(_data.c_str());
  if (errno)
    throw (ImpossibleException());
  return n;
}
                        CastString::operator  float(void) const throw(ImpossibleException)
{
  float	n = std::atof(_data.c_str());
  if (errno)
    throw (ImpossibleException());
  return n;
}
                        CastString::operator  float(void) const throw(ImpossibleException)
{
  double	n = std::strod(_data.c_str(), NULL);
  if (errno)
    throw (ImpossibleException());
  return n;
}
std::ostream                & CastString::operator<<(std::ostream & os, CastString const & rhs)
{
  os << rhs.getData();
}


