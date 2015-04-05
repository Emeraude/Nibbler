#include "LibX.hh"

LibX::LibX(std::pair<size_t, size_t> dimension)
  : _sizeX(dimension.first), _sizeY(dimension.second)
{
  size_t	dim_x = dimension.first * PIXELS_BY_CASE;
  size_t	dim_y = dimension.second * PIXELS_BY_CASE;
  char		yellow[] = YELLOW_RGB;
  char		cyan[] = CYAN_RGB;
  char		red[] = RED_RGB;
  char		blue[] = BLUE_RGB;
  char		white[] = WHITE_RGB;
  char		green[] = GREEN_RGB;

  if (!(_display = XOpenDisplay((char*)0))) {
    throw LibXException("LibX is unable to be opened.");
  }
  if (dim_x > 1280 || dim_y > 720 ||
      dim_x <= 5 * PIXELS_BY_CASE || dim_x <= 5 * PIXELS_BY_CASE)
    throw ResolutionException("Invalid Resolution.");
  _window = XCreateSimpleWindow(_display, RootWindow(_display, 0),
				1, 1, dim_x, dim_y, 0,
				BlackPixel(_display, 0),
				BlackPixel(_display, 0));
  XMapWindow(_display, _window);

  _colorMap = DefaultColormap(_display, 0);

  _yellowContext = XCreateGC(_display, _window, 0, 0);
  _cyanContext = XCreateGC(_display, _window, 0, 0);
  _redContext = XCreateGC(_display, _window, 0, 0);
  _blueContext = XCreateGC(_display, _window, 0, 0);
  _whiteContext = XCreateGC(_display, _window, 0, 0);
  _greenContext = XCreateGC(_display, _window, 0, 0);
  XParseColor(_display, _colorMap, cyan, &_cyanParsed);
  XParseColor(_display, _colorMap, yellow, &_yellowParsed);
  XParseColor(_display, _colorMap, red, &_redParsed);
  XParseColor(_display, _colorMap, blue, &_blueParsed);
  XParseColor(_display, _colorMap, white, &_whiteParsed);
  XParseColor(_display, _colorMap, green, &_greenParsed);
  XAllocColor(_display, _colorMap, &_yellowParsed);
  XAllocColor(_display, _colorMap, &_cyanParsed);
  XAllocColor(_display, _colorMap, &_greenParsed);
  XAllocColor(_display, _colorMap, &_redParsed);
  XAllocColor(_display, _colorMap, &_blueParsed);
  XAllocColor(_display, _colorMap, &_whiteParsed);
  XSetForeground(_display, _yellowContext, _yellowParsed.pixel);
  XSetForeground(_display, _cyanContext, _cyanParsed.pixel);
  XSetForeground(_display, _greenContext, _greenParsed.pixel);
  XSetForeground(_display, _redContext, _redParsed.pixel);
  XSetForeground(_display, _blueContext, _blueParsed.pixel);
  XSetForeground(_display, _whiteContext, _whiteParsed.pixel);

  XSelectInput(_display, _window, ExposureMask | KeyPressMask);

  _paused = false;
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

void	LibX::printSquare(int x, int y, GC colorContext)
{
  int	x_start = x * PIXELS_BY_CASE;
  int	x_end = x_start + PIXELS_BY_CASE;
  int	y_start = y * PIXELS_BY_CASE;
  int	y_end = y_start + PIXELS_BY_CASE;

  while (y_start < y_end) {
    XDrawLine(_display, _window, colorContext, x_start, y_start, x_end, y_start);
    ++y_start;
  }
}

int	LibX::printGame(const Snake &snake, const Apple & apple)
{
  std::deque<std::pair<int, int> > s = snake.getSnake();
  std::deque<std::pair<int, int> >::iterator it = s.begin();
  GC	apple_color;

  std::pair<int, int> food = apple.getApple();
  if (apple.getAge() <= apple.getBonusAge())
    apple_color = _cyanContext;
  else if (apple.getAge() > apple.getRottenAge())
    apple_color = _yellowContext;
  else
    apple_color = _greenContext;
  printSquare(food.first, food.second, apple_color);

  std::pair<int, int>	last_chain = snake.getLastChain();
  if (last_chain.first >= 0) {
    printSquare(last_chain.first, last_chain.second, _whiteContext);
  }

  if (it != s.end()) {
    printSquare(it->first, it->second, _blueContext);
    ++it;
  }

  while (it != s.end()) {
    printSquare(it->first, it->second, _redContext);
    ++it;
  }

  XFlush(_display);
  return (0);
}

int	LibX::eventManager(Snake &snake)
{
  do {
    if (XCheckMaskEvent(_display, KeyPressMask, &_event)) {
      KeySym key = XLookupKeysym(&_event.xkey, 0);
      switch (key) {
      case (XK_Left):
	snake.moveLeft();
	break;
      case (XK_Right):
	snake.moveRight();
	break;
      case (XK_Escape):
	return (0);
	break;
      case (XK_p | XK_P):
	_paused ^= 1;
	break;
      case (XK_q | XK_Q):
	return (0);
	break;
      }
      usleep(10);
    }
  } while (_paused);
  return (1);
}

int	LibX::guiQuit()
{
  return (0);
}

extern "C" IGui	*loadGui(std::pair<size_t, size_t> dimension)
{
  return (new LibX(dimension));
}
