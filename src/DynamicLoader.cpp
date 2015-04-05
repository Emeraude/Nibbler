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
  // dlclose(_handle);
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
  // IGui                  *(*display)(std::pair<std::size_t, std::size_t>);
  //throw

  // std::string tpath = "/home/duques_g/Programming/Nibbler/sdl.so";
  std::cout << "loadGui [1]" << std::endl;
  // if (!(_handle = dlopen(path.data(), RTLD_LAZY | RTLD_GLOBAL)))
  // if (!(handle = dlopen(path.data(), RTLD_LAZY)))
  if (!(handle = dlopen(path.data(), RTLD_LAZY | RTLD_GLOBAL | RTLD_NOW)))
    std::cerr << "DLOPEN FAILED: " << dlerror() << std::endl;
  std::cout << "loadGui [2]" << std::endl;
  // display = reinterpret_cast<IGui *(*)(std::pair<size_t, size_t>)>(dlsym(handle, "loadGui"));
  // std::cout << "loadGui [3]" << std::endl;
  // dlerror();
  // std::cout << "loadGui [4]" << std::endl;
  // _gui = (display)(std::pair<std::size_t, std::size_t>(1000, 500));
  // std::cout << "loadGui [5]" << std::endl;
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
