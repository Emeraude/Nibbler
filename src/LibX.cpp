
#include "LibX.hh"

LibX::LibX(std::pair<size_t, size_t> dimension)
  : _sizeX(dimension.first), _sizeY(dimension.second)
{
  size_t	dim_x = dimension.first * PIXELS_BY_CASE;
  size_t	dim_y = dimension.second * PIXELS_BY_CASE;

  XSetErrorHandler((void*)0);
  if (!(_display = XOpenDisplay((char*)0))) {
    // ERROR
  }
  _window = XCreateSimpleWindow(_display, RootWindow(_display, 0),
				1, 1, dim_x, dim_y, 0,
				WhitePixel(_display, 0),
				WhitePixel(_display, 0));
  XMapWindow(_display, _window);
  XFlush(_display);
}

LibX::~LibX()
{
  XUnmapWindow(_display, _window);
  XCloseDisplay(_display);
}

int	LibX::launchMenu()
{
  return (0);
}

int	LibX::launchGame(const Snake &)
{
  return (0);
}

int	LibX::guiQuit()
{
  return (0);
}
