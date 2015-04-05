#include "sdlGui.hpp"

#include <iostream>

sdlGui::sdlGui(std::pair<std::size_t, std::size_t> dim)
{
  _paused = false;
  _width = dim.first * BLOC;
  _height = dim.second * BLOC;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw SDLException("Initialisation failed.");
  const SDL_VideoInfo* info = SDL_GetVideoInfo();
  int tmpW = _width;
  int tmpH = _height;
  if (tmpW > info->current_w || tmpH > info->current_h
      || tmpW <= 5 * BLOC || tmpH <= 5 * BLOC)
    throw ResolutionException("Invalid resolution.");
  if (!(_win = SDL_SetVideoMode(_height, _width, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)))
    throw SDLException("Video configuration is unable to be set.");
  if (!(_apple = SDL_CreateRGBSurface(SDL_HWSURFACE, BLOC, BLOC, 32, 0, 0, 0, 0)) ||
      !(_new_apple = SDL_CreateRGBSurface(SDL_HWSURFACE, BLOC, BLOC, 32, 0, 0, 0, 0)) ||
      !(_rotten_apple = SDL_CreateRGBSurface(SDL_HWSURFACE, BLOC, BLOC, 32, 0, 0, 0, 0)) ||
      !(_head = SDL_CreateRGBSurface(SDL_HWSURFACE, BLOC, BLOC, 32, 0, 0, 0, 0)) ||
      !(_body = SDL_CreateRGBSurface(SDL_HWSURFACE, BLOC, BLOC, 32, 0, 0, 0, 0)))
    throw SDLException("Texture is unable to be generated.");
  SDL_FillRect(_win, NULL, SDL_MapRGB(_win->format, 255, 255, 255));
  SDL_FillRect(_apple, NULL, SDL_MapRGB(_win->format, 0, 255, 0));
  SDL_FillRect(_new_apple, NULL, SDL_MapRGB(_win->format, 0, 255, 255));
  SDL_FillRect(_rotten_apple, NULL, 0xbb6611);
  SDL_FillRect(_head, NULL, SDL_MapRGB(_win->format, 0, 0, 255));
  SDL_FillRect(_body, NULL, SDL_MapRGB(_win->format, 255, 0, 0));
  SDL_WM_SetCaption("Nibbler SDL", NULL);
  black = SDL_CreateRGBSurface(SDL_HWSURFACE, _width, _height, 32, 0, 0, 0, 0);
  SDL_FillRect(black, NULL, SDL_MapRGB(_win->format, 0, 0, 0));
  SDL_Flip(_win);
}

sdlGui::~sdlGui()
{
  SDL_FreeSurface(_apple);
  SDL_FreeSurface(_new_apple);
  SDL_FreeSurface(_rotten_apple);
  SDL_FreeSurface(_body);
  SDL_FreeSurface(_head);
  SDL_FreeSurface(_win);
}

int		sdlGui::launchMenu()
{
  return 0;
}

int		sdlGui::printGame(const Snake& snake, const Apple & apple)
{
  std::deque<std::pair<int, int> > s = snake.getSnake();;
  std::deque<std::pair<int, int> >::const_iterator it = s.begin();
  SDL_Surface *apple_color;

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
  if (apple.getAge() <= apple.getBonusAge())
    apple_color = _new_apple;
  else if (apple.getAge() > apple.getRottenAge())
    apple_color = _rotten_apple;
  else
    apple_color = _apple;
  SDL_BlitSurface(apple_color, NULL, _win, &_sqr);
  SDL_Flip(_win);
  return 0;
}

int		sdlGui::eventManager(Snake& snake)
{
  SDL_Event event;

  do {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
	return (0);
      if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_ESCAPE
	      || event.key.keysym.sym == SDLK_q)
	    return (0);
	  if (event.key.keysym.sym == SDLK_p)
	    _paused ^= 1;
	  if (event.key.keysym.sym == SDLK_LEFT)
	    snake.moveLeft();
	  if (event.key.keysym.sym == SDLK_RIGHT)
	    snake.moveRight();
	}
    }
    SDL_Delay(1);
  } while (_paused);
  return 1;
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
