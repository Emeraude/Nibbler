#ifndef APPLE_HPP
# define APPLE_HPP

# include <algorithm>
# include "Snake.hpp"

class Apple
{
private:
  std::pair<int, int> _apple;
  Snake const&	_snake;
  size_t _bonus_age;
  size_t _age;

public:
  Apple(const Snake &);
  ~Apple();
  // Apple(const Apple&);
  // Apple& operator=(const Apple&);

  std::pair<int, int> generateTemporaryApple();
  bool generateApple(const Snake& snake);
  const std::pair<int, int> & getApple() const;

  void addAge(size_t age);
  size_t getAge(void) const;
  size_t getBonusAge(void) const;
};

#endif
