#include "LibXException.hpp"

LibXException::~LibXException() throw() {}
LibXException::LibXException(std::string str)
{
  _str = std::string("LibXException : ") + str;
}

const char *LibXException::what() const throw()
{
  return _str.data();
}

ResolutionException::~ResolutionException() throw() {}
ResolutionException::ResolutionException(std::string str) : LibXException(str)
{
  _str = std::string("ResolutionException : ") + str;
}
