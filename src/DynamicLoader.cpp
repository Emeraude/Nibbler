#include <iostream>
#include <dlfcn.h>
#include "DynamicLoader.hpp"
#include <stdlib.h>

DynamicLoader::DynamicLoader()
{
  _handle = NULL;
}

DynamicLoader::~DynamicLoader()
{
}

DynamicLoader::DynamicLoader(const DynamicLoader& rhs __attribute__((unused)))
{
}

DynamicLoader&		DynamicLoader::operator=(const DynamicLoader& rhs)
{
  if (this != &rhs)
    {
    }
  return *this;
}

void			*DynamicLoader::loadGui(const std::string &path)
{
  void			*handle;
  if (!(handle = dlopen(path.data(), RTLD_LAZY | RTLD_GLOBAL | RTLD_NOW)))
    throw DynamicLoaderException("loadGui");
  return handle;
}

void			DynamicLoader::setGui(IGui *& gui)
{
  _gui = gui;
}

IGui *		DynamicLoader::getGui() const
{
  return _gui;
}
