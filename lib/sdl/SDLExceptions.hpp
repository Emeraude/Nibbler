#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>
# include <string>

class SDLException : public std::exception
{
public:
  SDLException(std::string str);
  virtual ~SDLException() throw();
  const char *what() const throw();

protected:
  std::string _str;
};

#endif
