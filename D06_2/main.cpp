#include "CastString.hpp"
#include <iostream>

int   main(int argc, char **argv)
{
  if (argc != 2)
    return 1;
  CastString str(argv[1]);

  std::cout << "char: ";
  try
  {
    char c = static_cast<char>(str);
    if (isprint(c))
      std::cout << "'" << c << "'";
    else
      std::cout << "Non displayable";
  }
  catch(std::exception)
  {
    std::cout << "impossible";
  }
  std::cout << std::endl;


  std::cout << "int: ";
  try
  {
    std::cout <<static_cast<int>(str);
  }
  catch(std::exception)
  {
    std::cout << "impossible";
  }
  std::cout << std::endl;

  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << "float: ";
  try
  {
    std::cout << static_cast<float>(str) << 'f';
  }
  catch(std::exception)
  {
    std::cout << "impossible";
  }
  std::cout << std::endl;

  std::cout << "double: ";
  try
  {
    std::cout << static_cast<double>(str);
  }
  catch(std::exception)
  {
    std::cout << "impossible";
  }
  std::cout << std::endl;
return 0;
}