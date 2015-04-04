#ifndef IGUI_HPP
# define IGUI_HPP

# include <utility>
# include "Snake.hpp"

class IGui
{
public:
  virtual ~IGui() { };

  /* launchMenu return 0 for success and -1 for failure */
  virtual int launchMenu() = 0;

  /* launchGame return 0 for success and -1 for failure */
  virtual int launchGame(const Snake &) = 0;

  /* guiQuit return 0 for success and -1 for failure */
  virtual int guiQuit() = 0;
};

#endif
