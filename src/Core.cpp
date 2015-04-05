#include <dlfcn.h>
#include <unistd.h>
#include <sstream>
#include "Core.hpp"
#include "option.h"

Core::Core(const std::string &casesX, const std::string &casesY, const std::string &libPath) :
  _snake(), _apple(_snake)
{
  std::istringstream(casesX) >> _caseX;
  std::istringstream(casesY) >> _caseY;
  loadGui(libPath);
}

Core::~Core()
{

}

Core::Core(const Core &rhs __attribute__((unused))) :
  _snake(), _apple(_snake)
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
  _gui = (display)(std::pair<std::size_t, std::size_t>(_caseX, _caseY));
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
    if (_snake.move())
      return ;
    if (_snake.getSnake().front() == _apple.getApple())
      _apple.generateApple(_snake);
    usleep(100000);
  }
}
