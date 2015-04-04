#ifndef LIBX_H_
# define LIBX_H_

# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/Xos.h>
# include <X11/Xatom.h>
# include <X11/keysym.h>

# define PIXELS_BY_CASE	(5)

class		LibX
{

private:

  extern char**	environ;

  Display	_display;
  Window	_window;
  size_t	_sizeX;
  size_t	_sizeY;

public:

  LibX(std::pair<size_t, size_t>);
  virtual ~IGui();

  // virtual int createWindows(std::pair<int, int>);
  virtual int launchMenu();
  virtual int launchGame(const Snake &);
  virtual int guiQuit();
};

#endif // !LIBX_H_
