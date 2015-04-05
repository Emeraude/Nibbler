#include "Apple.hpp"
#include <time.h>

Apple::Apple(const Snake& snake) :
  _snake(snake)
{
  _age = 0;
  _bonus_age = 2000000;
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

std::pair<int, int> Apple::generateTemporaryApple()
{
  return (std::make_pair(rand() % _snake.getLimitX(), rand() % _snake.getLimitY()));
}

bool		Apple::generateApple(const Snake& snake)
{
  std::deque<std::pair <int, int> >s = snake.getSnake();
  std::deque<std::pair <int, int> >::const_iterator it;
  std::pair<int, int> tmpApple = generateTemporaryApple();
  size_t maxCases = _snake.getLimitX() * _snake.getLimitY();

  if (s.size() > maxCases)
    return false;
  for (it = s.begin(); it != s.end(); ++it)
    {
      if (it->first == tmpApple.first && it->second == tmpApple.second) {
  	tmpApple = generateTemporaryApple();
  	it = s.begin();
      }
    }
  _age = 0;
  _apple = tmpApple;
  return true;
}

const std::pair<int, int> & Apple::getApple() const
{
  return _apple;
}

void Apple::addAge(size_t const age) {
  _age += age;
}

size_t Apple::getAge(void) const {
  return _age;
}

size_t Apple::getBonusAge(void) const {
  return _bonus_age;
}
