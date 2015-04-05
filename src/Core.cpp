#include <dlfcn.h>
#include <unistd.h>
#include "Core.hpp"

Core::Core(const std::string &libPath)
{
  loadGui(libPath);
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

void		Core::loadGui(const std::string & path)
{
  IGui *(*display)(std::pair<std::size_t, std::size_t>);
  void *symbol = _dynLoader->loadGui(path);

  display = reinterpret_cast<IGui *(*)(std::pair<size_t, size_t>)>(dlsym(symbol, "loadGui"));
  _gui = (display)(std::pair<std::size_t, std::size_t>(50, 50));
}

void		Core::launchGame()
{
  menu();
  game();
}

void		Core::menu()
{
  int ret = 1;

  while (ret != 0)
    ret = _gui->launchMenu();
}

void		Core::game()
{
  int		ret = 1;

  while (ret != 0 && ret != -1) {
    ret = _gui->eventManager(_snake);
    _gui->printGame(_snake);
    _snake.move();
    usleep(100000);
  }
}
