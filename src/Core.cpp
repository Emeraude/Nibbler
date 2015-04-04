#include "Core.hpp"

Core::Core(const std::string &libPath)
{
  _dynLoader->loadGui(libPath);
  _gui = _dynLoader->getGui();
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
