#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>
# include <string>
# include "IGuiException.hpp"

class SDLException : public std::exception, public IGuiException
{
public:
  SDLException(std::string str);
  virtual ~SDLException() throw();
  const char *what() const throw();

protected:
  std::string _str;
};

class ResolutionException : public SDLException
{
public:
  ResolutionException(std::string str);
  virtual ~ResolutionException() throw();
};

#endif
