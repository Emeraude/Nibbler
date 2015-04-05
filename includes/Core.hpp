#ifndef CORE_HPP
# define CORE_HPP

# include <iostream>
# include "DynamicLoader.hpp"
# include "Snake.hpp"
# include "IGui.hpp"
# include "Apple.hpp"
# include <sstream>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

class Core
{
private:
  DynamicLoader	*_dynLoader;
  void *_symbol;
  IGui *_gui;;
  Snake	_snake;
  Apple _apple;
  size_t _caseX;
  size_t _caseY;
  size_t _speed;

  void	incSpeed();

  void	menu();
  void	game();
  void	loadGui(const std::string &);

  Core(const Core &);
  Core& operator=(const Core &);

public:
  Core(const size_t, const size_t, const std::string&);
  ~Core();

  void	launchGame();

};

#endif
