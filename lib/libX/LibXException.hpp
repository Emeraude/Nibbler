#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>
# include <string>
# include "IGuiException.hpp"

class LibXException : public std::exception, public IGuiException
{
public:
  LibXException(std::string str);
  virtual ~LibXException() throw();
  const char *what() const throw();

protected:
  std::string _str;
};

class ResolutionException : public LibXException
{
public:
  ResolutionException(std::string str);
  virtual ~ResolutionException() throw();
};

#endif
