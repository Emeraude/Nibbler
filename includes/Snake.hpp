#ifndef SNAKE_HPP
# define SNAKE_HPP

# include <unistd.h>
# include <deque>
# include <utility>

class Snake
{
private:
  std::deque<std::pair<int, int> >	_snake;
  int _dir;
  int eated;
  std::pair<int, int> (Snake::*ptr[4])();
  std::pair<int, int>	_lastChain;

  std::pair<int, int> setDirRight();
  std::pair<int, int> setDirDown();
  std::pair<int, int> setDirLeft();
  std::pair<int, int> setDirTop();

  size_t	_limitX, _limitY;

  bool		checkBorder() const;

public:
  Snake(size_t x, size_t y);
  ~Snake();
  Snake(const Snake&);
  Snake& operator=(const Snake&);

  int		move();
  void		moveLeft();
  void		moveRight();
  void		growth();
  const std::deque<std::pair<int, int> > getSnake() const;
  std::pair<int, int>	getLastChain() const;
};

#endif
