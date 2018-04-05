#include <iostream>

class CastString
{
  public:

    std::string             _data;

    CastString(void);

    class ImpossibleException: public std::exception
    {
      public:
        ImpossibleException(void);
        ~ImpossibleException(void) throw();
        char const          * what(void) const throw();
      private:
        ImpossibleException(ImpossibleException const & src);
        ImpossibleException &operator=(ImpossibleException const & rhs);
    };

  public:
    CastString(CastString const & src);
    ~CastString(void);
    CastString(std::string const & str);

    CastString              & operator=(CastString const & src);

    std::string             getData(void) const;
                            operator  std::string const &(void) throw(ImpossibleException);
                            operator  char(void) const throw(ImpossibleException);
                            operator  int(void) const throw(ImpossibleException);
                            operator  float(void) const throw(ImpossibleException);
                            operator  double(void) const throw(ImpossibleException);


};
std::ostream                & operator<<(std::ostream & os, CastString const & rhs);