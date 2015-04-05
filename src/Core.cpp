#include <dlfcn.h>
#include <unistd.h>
#include <sstream>
#include "Core.hpp"
#include "option.h"

Core::Core(const size_t casesX, const size_t casesY, const std::string &libPath) :
  _snake(casesX, casesY), _apple(_snake)
{
  _caseX = casesX;
  _caseY = casesY;
  loadGui(libPath);
  _apple.generateApple(_snake);
  _speed = 100000;
}

Core::~Core()
{
  dlclose(_symbol);
  delete _gui;
}

// Core::Core(const Core &rhs __attribute__((unused))) :
//   _snake(), _apple(_snake)
// {
// }

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
  _symbol = _dynLoader->loadGui(path);

  if (!(display = reinterpret_cast<IGui *(*)(std::pair<size_t, size_t>)>(dlsym(_symbol, "loadGui"))))
    throw SymbolLoaderException("Symbol in dynamic library is invalid.");
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
void		Core::incSpeed()
{
  if (_speed > 30000)
    _speed -= 5000;
}

void		Core::game()
{
  int		ret = 1;

  while (ret != 0) {
    ret = _gui->eventManager(_snake);
    _gui->printGame(_snake, _apple);
    if (_snake.move())
      return ;
    if (_snake.getSnake().front() == _apple.getApple()) {
      _apple.generateApple(_snake);      
      _snake.growth();
      incSpeed();
    }
    usleep(_speed);
  }
}
