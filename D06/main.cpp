#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const **argv) {
  if (argc != 2)
    return 0;
  std::string str = argv[1];
  std::stringstream ss;
  ss << str;
  double d;
  float f;
  int i;
  char c;

  try
  {
    ss >> c;
    if (!(ss.eof() && std::isprint(c)))
      throw(new std::exception());
    std::cout << "c ok" << i << std::endl;
  }
  catch(std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
  ss.clear();
  /*
  try
  {
    ss >> d;
    std::cout << "d ok" << d << std::endl;
  }
  catch(std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
  ss.clear();
  try
  {
    ss >> f;
    std::cout << "f ok" << f << std::endl;
  }
  catch(std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
  ss.clear();
  try
  {
    ss >> i;
    std::cout << "i ok" << i << std::endl;
  }
  catch(std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
  ss.clear();
  try
  {
    ss >> c;
    std::cout << "c ok" << i << std::endl;
  }
  catch(std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
  ss.clear();
*/
  return 0;
}