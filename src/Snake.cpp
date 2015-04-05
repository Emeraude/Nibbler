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
  return std::pair<int, int>(_snake.back().first + 1, _snake.back().second);
}

std::pair<int, int>		Snake::setDirDown()
{
  return std::pair<int, int>(_snake.back().first, _snake.back().second + 1);
}

std::pair<int, int>		Snake::setDirLeft()
{
  return std::pair<int, int>(_snake.back().first - 1, _snake.back().second);
}

std::pair<int, int>		Snake::setDirTop()
{
  return std::pair<int, int>(_snake.back().first, _snake.back().second - 1);
}

bool				Snake::checkBorder() const
{
  if (_snake.back().first < 0
      || _snake.back().first * BLOC_SIZE > WIDTH
      || _snake.back().second < 0
      || _snake.back().second * BLOC_SIZE > HEIGHT)
    return (false);
  return true;
}

int		Snake::move()
{
  _snake.pop_back();
  _snake.push_front(std::pair<int, int>((this->*ptr[_dir])()));
  if (!checkBorder())
    return (1);
  return (0);
}

void		Snake::moveLeft()
{
  _dir += !_dir ? 4 : -1;
}

void		Snake::moveRight()
{
  ++_dir %= 4;
}

std::deque<std::pair<int, int> > Snake::getSnake() const
{
  return (_snake);
}
