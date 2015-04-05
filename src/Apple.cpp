#include "Apple.hpp"
#include <time.h>

Apple::Apple(const Snake& snake) :
  _snake(snake)
{
  srand(time(NULL));
}

Apple::~Apple()
{
}

// Apple::Apple(const Apple& rhs __attribute__((unused)))
// {
// }

// Apple&		Apple::operator=(const Apple & rhs)
// {
//   if (this != &rhs) {
//   }
//   return *this;
// }

#include <iostream>

std::pair<int, int> Apple::generateTemporaryApple()
{
  return (std::make_pair(rand() % _snake.getLimitX(), rand() % _snake.getLimitY()));
}

bool		Apple::generateApple(const Snake& snake)
{
  std::deque<std::pair <int, int> >::const_iterator it;
  std::pair<int, int> tmpApple = generateTemporaryApple();
  size_t maxCases = _snake.getLimitX() * _snake.getLimitY();

  if (_snake.getSnake().size() > maxCases)
    return false;
  for (it = snake.getSnake().begin(); it != snake.getSnake().end(); ++it)
    {
      if (*it == tmpApple) {
  	tmpApple = generateTemporaryApple();
  	it = snake.getSnake().begin();
      }
    }
  _apple = tmpApple;
  return true;
}

const std::pair<int, int> & Apple::getApple() const
{
  return _apple;
}
