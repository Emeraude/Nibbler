#include "NCurseExceptions.hpp"

NCurseException::~NCurseException() throw() {}
NCurseException::NCurseException(std::string str)
{
  _str = std::string("NCurseException : ") + str;
}

const char *NCurseException::what() const throw()
{
  return _str.data();
}

ResolutionException::~ResolutionException() throw() {}
ResolutionException::ResolutionException(std::string str) : NCurseException(str)
{
  _str = std::string("ResolutionException : ") + str;
}
