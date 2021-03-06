#include <dlfcn.h>
#include <unistd.h>
#include <sstream>
#include "Core.hpp"

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
  delete _gui;
  dlclose(_symbol);
}

Core&		Core::operator=(const Core &rhs __attribute__((unused)))
{
  if (this != &rhs) {
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
  _gui->guiQuit();
}

void		Core::menu()
{
  while (_gui->launchMenu());
}

void		Core::incSpeed()
{
  if (_speed > 30000)
    _speed -= 5000;
}

void		Core::game()
{
  while (1) {
    if (!_gui->eventManager(_snake))
      return;
    _gui->printGame(_snake, _apple);
    if (_snake.move())
      return ;
    if (_snake.getSnake().front() == _apple.getApple()) {
      _snake.growth(_speed, _apple.getScoreCoef());
      _apple.generateApple(_snake);
      incSpeed();
    }
    _apple.addAge(_speed);
    usleep(_speed);
  }
}
