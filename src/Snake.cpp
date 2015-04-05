#include "Snake.hpp"
#include "option.h"

Snake::Snake()
{
  _snake.push_back(std::pair<int, int>(10, 10));
  _snake.push_back(std::pair<int, int>(10, 11));
  _snake.push_back(std::pair<int, int>(10, 12));

  ptr[0] = &Snake::setDirRight;
  ptr[1] = &Snake::setDirDown;
  ptr[2] = &Snake::setDirLeft;
  ptr[3] = &Snake::setDirTop;

  _dir = 0;
  _lastChain = std::make_pair(-1, -1);
}

Snake::~Snake()
{

}

Snake::Snake(const Snake & rhs) :
  _snake(rhs._snake)
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
      || _snake.front().first > WIDTH
      || _snake.front().second < 0
      || _snake.front().second > HEIGHT)
    return (false);
  return true;
}

int		Snake::move()
{
  _lastChain = _snake.back();
  _snake.pop_back();
  _dir %= 4;
  _snake.push_front(std::pair<int, int>((this->*ptr[_dir])()));
  if (!checkBorder())
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

const std::deque<std::pair<int, int> > Snake::getSnake() const
{
  return (_snake);
}

std::pair<int, int>	Snake::getLastChain() const
{
  return (_lastChain);
}
