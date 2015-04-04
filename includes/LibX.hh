#ifndef LIBX_H_
# define LIBX_H_

# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/Xos.h>
# include <X11/Xatom.h>
# include <X11/keysym.h>

# define PIXELS_BY_CASE	(5)
# define RED_RGB	("#FF0000")
# define BLUE_RGB	("#0000FF")

class		LibX
{

private:

  extern char**	environ;

  Display	_display;
  Window	_window;
  size_t	_sizeX;
  size_t	_sizeY;
  XEvent	_event;
  GC		_redContext;
  GC		_blueContext;
  XColor	_redParsed;
  XColor	_blueParsed;
  ColorMap	_colorMap;

  char		*_red = RED_RGB;
  char		*_blue = BLUE_RGB;

  void		printSquare(int x, int y);

public:

  LibX(std::pair<size_t, size_t>);
  virtual ~IGui();

  virtual int launchMenu();
  virtual int launchGame(const Snake &);
  virtual int guiQuit();
};

#endif // !LIBX_H_
