#include "Exceptions.hpp"

NibblerException::~NibblerException() throw() {}
NibblerException::NibblerException(std::string str)
{
  _str = std::string("NibblerException : ") + str;
}

const char *NibblerException::what() const throw()
{
  return _str.data();
}

DynamicLoaderException::~DynamicLoaderException() throw() {}
DynamicLoaderException::DynamicLoaderException(std::string str) : NibblerException(str)
{
  _str = std::string("DynamicLoaderException : ") + str;
}
