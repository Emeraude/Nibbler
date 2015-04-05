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
  IGui *_gui;;
  Snake	_snake;

public:
  Core(const std::string&);
  ~Core();
  Core(const Core &);
  Core& operator=(const Core &);

  void	loadGui(const std::string &);
  void	launchGame();

  int	menu();
  int	game();
};

#endif
