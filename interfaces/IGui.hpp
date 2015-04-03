#ifndef IGUI_HPP
# define IGUI_HPP

# include <utility>

class IGui
{
  virtual ~IGui() { };

  virtual createWindows(std::pair<int, int>) = 0;
  virtual int launchMenu() = 0;
  virtual int launchGame(const Snake &) = 0;
  virtual int guiQuit() = 0;
}

#endif
