#include "Snake.hpp"
#include "option.h"

#include <iostream>

Snake::Snake(size_t limitX, size_t limitY)
  : _limitX(limitX), _limitY(limitY)
{
  _snake.push_back(std::pair<int, int>(10, 10));
  _snake.push_back(std::pair<int, int>(10, 11));
  _snake.push_back(std::pair<int, int>(10, 12));
  _snake.push_back(std::pair<int, int>(10, 13));

  ptr[0] = &Snake::setDirRight;
  ptr[1] = &Snake::setDirDown;
  ptr[2] = &Snake::setDirLeft;
  ptr[3] = &Snake::setDirTop;

  _dir = 0;
  _eated = 0;
  _lastChain = std::make_pair(-1, -1);
}

Snake::~Snake()
{

}

Snake::Snake(const Snake & rhs) :
  _snake(rhs._snake), _dir(rhs._dir), _eated(rhs._eated), _limitX(rhs._limitX), _limitY(rhs._limitY)
{

}

Snake&		Snake::operator=(const Snake& rhs)
{
  if (this != &rhs)
    {
      _snake = rhs._snake;
    }
  return *this;
}

std::pair<int, int>		Snake::setDirRight()
{
  return std::pair<int, int>(_snake.front().first + 1, _snake.front().second);
}

std::pair<int, int>		Snake::setDirDown()
{
  return std::pair<int, int>(_snake.front().first, _snake.front().second + 1);
}

std::pair<int, int>		Snake::setDirLeft()
{
  return std::pair<int, int>(_snake.front().first - 1, _snake.front().second);
}

std::pair<int, int>		Snake::setDirTop()
{
  return std::pair<int, int>(_snake.front().first, _snake.front().second - 1);
}

bool				Snake::checkBorder() const
{
  if (_snake.front().first < 0
      || _snake.front().first >= _limitX
      || _snake.front().second < 0
      || _snake.front().second >= _limitY)
    return (false);
  return true;
}

bool				Snake::checkCannibalism() const
{
  std::deque<std::pair<int, int> >::const_iterator it = _snake.begin();

  for (++it; it != _snake.end(); ++it) {
    if (*it == _snake.front())
      return false;
  }
  return true;
}

int		Snake::move()
{
  _lastChain = _snake.back();
  if (!_eated)
    _snake.pop_back();
  else
    --_eated;
  _dir %= 4;
  _snake.push_front(std::pair<int, int>((this->*ptr[_dir])()));
  if (!checkBorder() || !checkCannibalism())
    return (1);
  return (0);
}

void		Snake::moveLeft()
{
  _dir += !_dir ? 3 : -1;
}

void		Snake::moveRight()
{
  ++_dir %= 4;
}

void		Snake::growth()
{
  _eated += 1;
}

const std::deque<std::pair<int, int> > Snake::getSnake() const
{
  return (_snake);
}

std::pair<int, int>	Snake::getLastChain() const
{
  return (_lastChain);
}

int		Snake::getLimitX() const
{
  return (_limitX);
}

int		Snake::getLimitY() const
{
  return (_limitY);
}
