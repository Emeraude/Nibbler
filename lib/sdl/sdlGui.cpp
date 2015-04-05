#include "sdlGui.hpp"

#include <iostream>

sdlGui::sdlGui(std::pair<std::size_t, std::size_t> dim)
{
  std::cout << "first: "<<dim.first * BLOC << std::endl;
  _width = dim.first * BLOC;
  _height = dim.second * BLOC;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw SDLException("Initialisation failed.");
  if (!(_win = SDL_SetVideoMode(_height, _width, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)))
    throw SDLException("Video configuration is unable to be set.");
  if (!(_apple = SDL_CreateRGBSurface(SDL_HWSURFACE, BLOC, BLOC, 32, 0, 0, 0, 0)) ||
      !(_head = SDL_CreateRGBSurface(SDL_HWSURFACE, BLOC, BLOC, 32, 0, 0, 0, 0)) ||
      !(_body = SDL_CreateRGBSurface(SDL_HWSURFACE, BLOC, BLOC, 32, 0, 0, 0, 0)))
    throw SDLException("Texture is unable to be generated.");
  SDL_FillRect(_win, NULL, SDL_MapRGB(_win->format, 255, 255, 255));
  SDL_FillRect(_apple, NULL, SDL_MapRGB(_win->format, 0, 255, 0));
  SDL_FillRect(_head, NULL, SDL_MapRGB(_win->format, 0, 0, 255));
  SDL_FillRect(_body, NULL, SDL_MapRGB(_win->format, 255, 0, 0));
  SDL_WM_SetCaption("Nibbler SDL", NULL);
  black = SDL_CreateRGBSurface(SDL_HWSURFACE, _width, _height, 32, 0, 0, 0, 0);
  SDL_FillRect(black, NULL, SDL_MapRGB(_win->format, 255, 255, 255));
  SDL_Flip(_win);
}

sdlGui::~sdlGui()
{
  SDL_FreeSurface(_win);
  SDL_FreeSurface(_apple);
  SDL_FreeSurface(_body);
  SDL_FreeSurface(_head);
}

int		sdlGui::launchMenu()
{
  return 0;
}

int		sdlGui::printGame(const Snake& snake, const Apple & apple)
{
  std::deque<std::pair<int, int> > s = snake.getSnake();;
  std::deque<std::pair<int, int> >::const_iterator it = s.begin();

  _sqr.x = 00;
  _sqr.y = 00;
  SDL_BlitSurface(black, NULL, _win, &_sqr);
  _sqr.x = it->first * BLOC;
  _sqr.y = it->second * BLOC;
  SDL_BlitSurface(_head, NULL, _win, &_sqr);
  while (++it != s.end()) {
    _sqr.x = it->first * BLOC;
    _sqr.y = it->second * BLOC;
    SDL_BlitSurface(_body, NULL, _win, &_sqr);
  }
  _sqr.x = apple.getApple().first * BLOC;
  _sqr.y = apple.getApple().second * BLOC;
  SDL_BlitSurface(_apple, NULL, _win, &_sqr);
  SDL_Flip(_win);
  return 0;
}

int		sdlGui::eventManager(Snake& snake)
{
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT)
      return (0);
    if (event.type == SDL_KEYDOWN)
      {
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  return (0);
	if (event.key.keysym.sym == SDLK_LEFT)
	  snake.moveLeft();
	if (event.key.keysym.sym == SDLK_RIGHT)
	  snake.moveRight();
      }
  }
  return 1;
}

int		sdlGui::guiQuit()
{
  std::cout << "guiQuit" << std::endl;
  return 0;
}

extern "C"
{
  IGui*	loadGui(std::pair<size_t, size_t> dim)
  {
    return new sdlGui(dim);
  }
}
