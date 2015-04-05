#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>
# include <string>
# include "IGuiException.hpp"

class NCurseException : public std::exception, public IGuiException
{
public:
  NCurseException(std::string str);
  virtual ~NCurseException() throw();
  const char *what() const throw();

protected:
  std::string _str;
};

class ResolutionException : public NCurseException
{
public:
  ResolutionException(std::string str);
  virtual ~ResolutionException() throw();
};

#endif
