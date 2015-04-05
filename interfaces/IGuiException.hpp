#ifndef IGUIEXCEPTION_HPP
# define IGUIEXCEPTION_HPP

#include <exception>

class IGuiException
{
public:
  virtual ~IGuiException() { };
  virtual const char *what() const throw() = 0;
};

#endif
