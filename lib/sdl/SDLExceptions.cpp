#include "SDLExceptions.hpp"

SDLException::~SDLException() throw() {}
SDLException::SDLException(std::string str)
{
  _str = std::string("SDLException : ") + str;
}

const char *SDLException::what() const throw()
{
  return _str.data();
}

ResolutionException::~ResolutionException() throw() {}
ResolutionException::ResolutionException(std::string str) : SDLException(str)
{
  _str = std::string("ResolutionException : ") + str;
}
