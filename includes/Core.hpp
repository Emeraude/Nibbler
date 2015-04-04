#ifndef CORE_HPP
# define CORE_HPP

# include <iostream>

class Core
{
private:
  DynamicLoader	*gui;
  Snake	_snake;

public:
  Core();
  ~Core();
  Core(const Core &);
  Core& operator=(const Core &);

  void	launchGame();

  void	menu();
  void	game();
};

#endif
