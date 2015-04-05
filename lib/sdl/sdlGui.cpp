#include "sdlGui.hpp"

#include <iostream>

sdlGui::sdlGui(std::pair<std::size_t, std::size_t> dim)
{
  std::cout << "TOOT" << std::endl;
}

sdlGui::~sdlGui()
{
}

int		sdlGui::launchMenu()
{
  std::cout << "TOOT" << std::endl;
  return 0;
}

int		sdlGui::printGame(const Snake&)
{
  return 0;
}

int		sdlGui::eventManager(const Snake&)
{
  return 0;
}

int		sdlGui::guiQuit()
{
  return 0;
}

extern "C"
{
  IGui*	loadGui(std::pair<size_t, size_t> dim)
  {
    return new sdlGui(dim);
  }
}
