#ifndef SDLGUI_HPP
# define SDLGUI_HPP

# include "IGui.hpp"

class sdlGui : public IGui
{
public:
  sdlGui(std::pair<std::size_t, std::size_t>);
  ~sdlGui();
  
  int launchMenu();
  int printGame(const Snake &);
  int eventManager(const Snake &);
  int guiQuit();
};

#endif
