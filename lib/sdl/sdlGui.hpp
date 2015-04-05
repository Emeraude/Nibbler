#ifndef SDLGUI_HPP
# define SDLGUI_HPP

# include <SDL/SDL.h>
# include "SDLExceptions.hpp"
# include "IGui.hpp"

# define BLOC 20

class sdlGui : public IGui
{
private:
  bool	_paused;
  size_t _width;
  size_t _height;

  SDL_Surface *_win;
  SDL_Surface *_apple;
  SDL_Surface *_body;
  SDL_Surface *_head;
  SDL_Surface *black;

  SDL_Rect _sqr;
public:
  sdlGui(std::pair<std::size_t, std::size_t>);
  ~sdlGui();

  int launchMenu();
  int printGame(const Snake &, const Apple &);
  int eventManager(Snake &);
  int guiQuit();
};

#endif
