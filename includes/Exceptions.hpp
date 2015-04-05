#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>
# include <string>

class NibblerException : public std::exception
{
public:
  NibblerException(std::string str);
  virtual ~NibblerException() throw();
  const char *what() const throw();

protected:
  std::string _str;
};

class DynamicLoaderException : public NibblerException
{
public:
  DynamicLoaderException(std::string str);
  virtual ~DynamicLoaderException() throw();
};

class SymbolLoaderException : public NibblerException
{
public:
  SymbolLoaderException(std::string str);
  virtual ~SymbolLoaderException() throw();
};

#endif
