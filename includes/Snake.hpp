#ifndef SNAKE_HPP
# define SNAKE_HPP

# include <deque>
# include <utility>

class Body
{
  int x;
  int y;
public:
  Body() {};
  ~Body() { };
};

class Snake
{
private:
  std::deque<Body *>	_snake;

public:
  Snake();
  ~Snake();
  Snake(const Snake&);
  Snake& operator=(const Snake&);

};

#endif
