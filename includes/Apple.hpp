#ifndef APPLE_HPP
# define APPLE_HPP

# include <algorithm>
# include "Snake.hpp"
# include "option.h"

class Apple
{
private:
  std::pair<int, int> _apple;
  Snake	_snake;

public:
  Apple(const Snake &);
  ~Apple();
  Apple(const Apple&);
  Apple& operator=(const Apple&);

  std::pair<int, int> generateTemporaryApple();
  bool generateApple(const Snake& snake);
  const std::pair<int, int> & getApple() const;
};

#endif