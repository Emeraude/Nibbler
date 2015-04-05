#ifndef LIBX_H_
# define LIBX_H_

# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/Xos.h>
# include <X11/Xatom.h>
# include <X11/keysym.h>

# include <utility>
# include <deque>

# include <Snake.hpp>
# include <IGui.hpp>

# include "LibXException.hpp"

# define PIXELS_BY_CASE	(20)
# define CYAN_RGB	("#00FFFF")
# define RED_RGB	("#FF0000")
# define BLUE_RGB	("#0000FF")
# define WHITE_RGB	("#000000")
# define GREEN_RGB	("#01DF01")

class		LibX : public IGui
{

private:

  bool		_paused;
  Display	*_display;
  Window	_window;
  size_t	_sizeX;
  size_t	_sizeY;
  XEvent	_event;
  GC		_cyanContext;
  GC		_redContext;
  GC		_blueContext;
  GC		_whiteContext;
  GC		_greenContext;
  XColor	_cyanParsed;
  XColor	_redParsed;
  XColor	_blueParsed;
  XColor	_whiteParsed;
  XColor	_greenParsed;
  Colormap	_colorMap;

  void		printSquare(int, int, GC);

public:

  LibX(std::pair<size_t, size_t>);
  virtual ~LibX();

  virtual int	launchMenu();
  virtual int	printGame(const Snake &, const Apple &);
  virtual int	eventManager(Snake &);
  virtual int	guiQuit();
};

#endif // !LIBX_H_
