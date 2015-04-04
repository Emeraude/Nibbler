#include "Snake.hpp"

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

void		Snake::move()
{
  _snake.pop_front();
  _snake.push_back(std::pair<int, int>((this->*ptr[_dir])()));
}

void		Snake::moveLeft()
{
  ++_dir %= 4;
}

void		Snake::moveRight()
{
  _dir += !_dir ? 4 : -1;
}

std::deque<std::pair<int, int> > Snake::getSnake() const
{
  return (_snake);
}
