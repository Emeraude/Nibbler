#include <dlfcn.h>
#include "Core.hpp"

Core::Core(const std::string &libPath)
{
  IGui                  *(*display)(std::pair<std::size_t, std::size_t>);

  void *symbol = _dynLoader->loadGui(libPath);


  display = reinterpret_cast<IGui *(*)(std::pair<size_t, size_t>)>(dlsym(symbol, "loadGui"));
  _gui = (display)(std::pair<std::size_t, std::size_t>(1000, 500));
  // _gui = new (sdlGui)(std::pair<size_t, size_t>(1000, 500));

}

Core::~Core()
{

}

Core::Core(const Core &rhs __attribute__((unused)))
{
}

Core&		Core::operator=(const Core &rhs __attribute__((unused)))
{
  if (this != &rhs)
    {
    }
  return *this;
}

void		Core::launchGame()
{
  menu();
  game();
}

int		Core::menu()
{
  int		ret = 1;

  while (ret != 0)
    ret = _gui->launchMenu();
  return ret;
}

int		Core::game()
{
  int		ret = 1;

  while (ret != 0 && ret != -1)
    ret = _gui->printGame(_snake);
  return (ret);
}
