#ifndef NCURSEGUI_HPP
# define NCURSEGUI_HPP

# include <ncurses/curses.h>
# include "NCurseExceptions.hpp"
# include "IGui.hpp"

class NCurseGui : public IGui
{
private:
  size_t _width;
  size_t _height;

  WINDOW *_win;

public:
  NCurseGui(std::pair<std::size_t, std::size_t>);
  ~NCurseGui();
  
  int launchMenu();
  int printGame(const Snake &, const Apple &);
  int eventManager(Snake &);
  int guiQuit();
};

#endif
