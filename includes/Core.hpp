#ifndef CORE_HPP
# define CORE_HPP

# include <iostream>
# include "DynamicLoader.hpp"
# include "Snake.hpp"
# include "IGui.hpp"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

class Core
{
private:
  DynamicLoader	*_dynLoader;
  IGui *gui;
  Snake	_snake;

public:
  Core();
  ~Core();
  Core(const Core &);
  Core& operator=(const Core &);

  int	launchGame();

  int	menu();
  int	game();
};

#endif
