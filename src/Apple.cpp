#include "Apple.hpp"

Apple::Apple(const Snake& snake) :
  _snake(snake)
{
}

Apple::~Apple()
{
}

Apple::Apple(const Apple& rhs __attribute__((unused)))
{
}

Apple&		Apple::operator=(const Apple & rhs)
{
  if (this != &rhs) {
  }
  return *this;
}

std::pair<int, int> Apple::generateTemporaryApple()
{
  std::pair<int, int> tmpApple;

  tmpApple.first = rand() % (HEIGHT);
  tmpApple.second = rand() % (HEIGHT);
  return tmpApple;
}

bool		Apple::generateApple(const Snake& snake)
{
  std::deque<std::pair <int, int> >::const_iterator it;
  std::pair<int, int> tmpApple = generateTemporaryApple();

  if (_snake.getSnake().size() > HEIGHT * WIDTH / BLOC_SIZE)
    return false;
  for (it = snake.getSnake().begin(); it != snake.getSnake().end(); ++it)
    {
      if (*it == tmpApple) {
  	tmpApple = generateTemporaryApple();
  	it = snake.getSnake().begin();
      }
    }
  return true;
}

const std::pair<int, int> & Apple::getApple() const
{
  return _apple;
}
