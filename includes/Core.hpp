#ifndef CORE_HPP
# define CORE_HPP

# include <iostream>
# include "DynamicLoader.hpp"
# include "Snake.hpp"
# include "IGui.hpp"
# include "Apple.hpp"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

class Core
{
private:
  DynamicLoader	*_dynLoader;
  IGui *_gui;;
  Snake	_snake;
  Apple _apple;
  size_t _caseX;
  size_t _caseY;

public:
  Core(const std::string&, const std::string&, const std::string&);
  ~Core();
  Core(const Core &);
  Core& operator=(const Core &);

  void	loadGui(const std::string &);
  void	launchGame();

  void	menu();
  void	game();
};

#endif
