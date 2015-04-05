#ifndef SNAKE_HPP
# define SNAKE_HPP

# include <deque>
# include <utility>

class Snake
{
private:
  std::deque<std::pair<int, int> >	_snake;
  int _dir;
  std::pair<int, int> (Snake::*ptr[4])();

  std::pair<int, int> setDirRight();
  std::pair<int, int> setDirDown();
  std::pair<int, int> setDirLeft();
  std::pair<int, int> setDirTop();

  bool		checkBorder() const;

public:
  Snake();
  ~Snake();
  Snake(const Snake&);
  Snake& operator=(const Snake&);

  int		move();
  void		moveLeft();
  void		moveRight();
  std::deque<std::pair<int, int> > getSnake() const;
};

#endif
