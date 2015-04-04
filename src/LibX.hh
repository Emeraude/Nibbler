#ifndef LIBX_H_
# define LIBX_H_


class		LibX
{
public:

  LibX(size_t length, size_t width);
  virtual ~IGui();

  virtual int createWindows(std::pair<int, int>) = 0;
  virtual int launchMenu() = 0;
  virtual int launchGame(const Snake &) = 0;
  virtual int guiQuit() = 0;
};

#endif // !LIBX_H_
