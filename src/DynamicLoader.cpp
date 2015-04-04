#include <dlfcn.h>
#include "DynamicLoader.hpp"

DynamicLoader::DynamicLoader()
{
  _handle = NULL;
}

DynamicLoader::~DynamicLoader()
{
  dlclose(_handle);
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

int			DynamicLoader::loadGui(const std::string &path)
{
  if (!(_handle = dlopen(path.data(), RTLD_LAZY)))
    return (-1);
  dlerror();

  dlsym(_handle, "gui");
  return 0;
}

IGui *			DynamicLoader::getGui() const
{
  return _gui;
}
